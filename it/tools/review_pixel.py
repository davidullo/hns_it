#!/usr/bin/env python3
"""Revisore pixel-perfect per il lavoro grafico di hns_it.

Manda le immagini a gpt-6-luna e claude-haiku-5-5 (opencode GO) e raccoglie
un verdetto sulla fedelta' al pixel rispetto all'originale.

Uso:  python3 it/tools/review_pixel.py <file_domande.json> [--solo modello]

Il JSON di domande: {"contesto": "...", "domande": [{"titolo": "...",
"immagini": ["/tmp/a.png", ...], "q": "..."}]}
"""
import base64
import json
import os
import sys
import time
import urllib.error
import urllib.request
import uuid

ENV = os.path.expanduser("~/.hermes/.env")
BASE = "https://opencode.ai/zen/go/v1"
MODELLI = ["gpt-6-luna", "claude-haiku-5-5"]


def chiave():
    with open(ENV) as f:
        for line in f:
            if line.startswith("OPENCODE_GO_API_KEY="):
                return line.split("=", 1)[1].strip().strip('"').strip("'")
    raise SystemExit("OPENCODE_GO_API_KEY non trovata in ~/.hermes/.env")


def b64(p):
    with open(p, "rb") as f:
        return base64.b64encode(f.read()).decode()


def _post(url, payload, headers, timeout=300):
    req = urllib.request.Request(url, data=json.dumps(payload).encode(), headers=headers)
    with urllib.request.urlopen(req, timeout=timeout) as r:
        return json.loads(r.read().decode())


def chiedi(modello, domanda, immagini, chiave_api, maxtok=4000, tentativi=3):
    """Un giro di domanda+immagini a un modello. Ritorna il testo o '[ERROR] ...'."""
    ultimo = None
    for _ in range(tentativi):
        try:
            if modello == "gpt-6-luna":
                # protocollo Responses: auth Bearer, immagini come input_image
                content = [{"type": "input_text", "text": domanda}]
                for img in immagini:
                    content.append({"type": "input_image",
                                    "image_url": "data:image/png;base64," + b64(img)})
                j = _post(BASE + "/responses",
                          {"model": modello, "input": [{"role": "user", "content": content}],
                           "max_output_tokens": maxtok},
                          {"Authorization": "Bearer " + chiave_api,
                           "Content-Type": "application/json", "User-Agent": "Mozilla/5.0",
                           "X-opencode-session": str(uuid.uuid4())})
                pezzi = []
                for it in j.get("output", []):
                    for c in it.get("content", []) or []:
                        if c.get("type") == "output_text":
                            pezzi.append(c.get("text", ""))
                testo = "\n".join(pezzi).strip()
                if testo:
                    return testo
                ultimo = "risposta vuota (status=%s)" % j.get("status")
            else:
                # protocollo Anthropic: auth x-api-key, immagini base64
                content = [{"type": "text", "text": domanda}]
                for img in immagini:
                    content.append({"type": "image", "source": {
                        "type": "base64", "media_type": "image/png", "data": b64(img)}})
                j = _post(BASE + "/messages",
                          {"model": modello, "max_tokens": maxtok,
                           "messages": [{"role": "user", "content": content}]},
                          {"x-api-key": chiave_api, "anthropic-version": "2023-06-01",
                           "Content-Type": "application/json", "User-Agent": "Mozilla/5.0",
                           "X-opencode-session": str(uuid.uuid4())})
                testo = "\n".join(c.get("text", "") for c in j.get("content", [])
                                  if c.get("type") == "text").strip()
                if testo:
                    return testo
                ultimo = "risposta vuota (stop=%s)" % j.get("stop_reason")
        except urllib.error.HTTPError as e:
            ultimo = "HTTP %s: %s" % (e.code, e.read().decode()[:500])
        except Exception as e:  # rete, timeout, JSON rotto
            ultimo = repr(e)[:300]
        time.sleep(4)
    return "[ERROR] " + str(ultimo)


def main():
    cfg = json.load(open(sys.argv[1]))
    solo = None
    if "--solo" in sys.argv:
        solo = sys.argv[sys.argv.index("--solo") + 1]
    k = chiave()
    modelli = [m for m in MODELLI if solo is None or m == solo]
    out = {}
    for blocco in cfg["domande"]:
        print("\n" + "=" * 70)
        print("### %s" % blocco["titolo"])
        domanda = cfg.get("contesto", "") + "\n\n" + blocco["q"]
        out[blocco["titolo"]] = {}
        for m in modelli:
            t0 = time.time()
            r = chiedi(m, domanda, blocco["immagini"], k)
            print("\n--- %s (%.0fs) ---\n%s" % (m, time.time() - t0, r))
            out[blocco["titolo"]][m] = r
    dest = cfg.get("output", "/tmp/review_out.json")
    json.dump(out, open(dest, "w"), ensure_ascii=False, indent=1)
    print("\nsalvato in %s" % dest)


if __name__ == "__main__":
    main()
