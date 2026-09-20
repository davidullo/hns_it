![HnS Logo](HnS_Logo.png)

# About `pokemonHnS-expansion`

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->
<!-- TODO: Actually change these gifs, and generally update contents to convey HnS-specific information -->
![HnS Collage](HnS_Collage_YourAdventure.png)

**`pokemonHnS-expansion`**, aka Pokémon Heart and Soul 2.0, is a GBA ROM hack that is both a remake of GSC and demake of HGSS, with added quality-of-life, customization, and more.  
Originally built on top of [resetes12's **`Modern Emerald`**](https://github.com/resetes12/pokeemerald).  
Now additionally built on top of [RHH's **`pokeemerald-expansion`**](https://github.com/rh-hideout/pokeemerald-expansion) GBA ROM hack base.  
Finally, all of these projects are built on top of [pret's **`pokeemerald`**](https://github.com/pret/pokeemerald) decompilation project.

> Pokémon Heart & Soul brings the classic Johto Region and its iconic story to the world of modern GBA decomp hacking. Built on Modern Emerald and pokeemerald-expansion, this project offers a fresh take on the GSC/HGSS experience, blending key aspects of the Gen 2 and Gen 4 games, while incorporating many modern QoL features, as well as some familiar mechanics from Gen 3 to Gen 9. Not only is Heart & Soul (HnS) a first-of-its-kind, fully completed, playtested, and largely faithful GSC remake / HGSS demake, it's also completely open source, and is intended to be a base for a new generation of Johto rom hacks.

Unfortunately, saves from before 2.0 will not be compatible moving forward.

2.0.1 will be the last "official" release of Pokémon Heart and Soul, after which any bug fixes, content updates, or any propogated updates from **`pokeemerald`** or **`pokeemerald-expansion`** will only be available via community forks of the project.

# 🇮🇹 Versione italiana (traduzione non ufficiale)

Questo fork contiene la **traduzione italiana** dei testi di Pokémon Heart and Soul 2.0.
Lo stato e le cose ancora da fare stanno in [`it/MANCANTI.md`](it/MANCANTI.md).

## Come si ottiene la ROM italiana

La traduzione è **dentro il gioco**: si compila una ROM completa. Non serve applicare nessuna patch a una ROM di Smeraldo.

### Compilare da sorgente (consigliato)

1. Installa devkitARM di devkitPro seguendo le [istruzioni per il tuo sistema](INSTALL.md).
2. Poi:

```bash
git clone https://github.com/davidullo/hns_it
cd hns_it
make hns -j8
```

Alla fine trovi **`pokehns.gba`** nella cartella del progetto: è la ROM italiana, pronta da aprire in un emulatore.

### Se hai già la ROM compilata

Se qualcuno ti ha passato `pokehns.gba` compilato da questo repository, è già la versione italiana: aprila e gioca. Non serve altro.

## Come si gioca

- Desktop: **mGBA** (consigliato) o VBA-M
- Android: Pizza Boy, MyBoy
- iOS: Provenance o simili
- Serve il file **BIOS di GBA** per alcuni emulatori; mGBA non lo richiede

## Cosa è tradotto

- **dialoghi, menu, descrizioni, nomi di oggetti, mosse, abilità e luoghi**: i nomi di oggetti e luoghi usano quelli ufficiali italiani dei giochi (da PokeAPI e dal wiki italiano), non traduzioni inventate
- le unità di misura sono quelle metriche
- **non tradotta**: la grafica. Font, title screen, schermate di battaglia e menu grafici sono ancora in inglese (167 file immagine). È il prossimo lavoro, vedi [`it/MANCANTI.md`](it/MANCANTI.md)

## Segnalare un errore

Apri una issue su GitHub e scrivi:

1. la frase sbagliata, copiata dal gioco
2. dove si vede (città, schermata, menu, momento della storia)
3. cosa dovrebbe dire secondo te

Se è una parola sola (per esempio un nome di oggetto), basta anche solo quella.

## Come funziona la traduzione

I testi tradotti non si modificano a mano nel codice: vivono in file dati e vengono scritti nei sorgenti da una pipeline, descritta in [`it/README.md`](it/README.md).

## Crediti

- **Pokémon Heart and Soul 2.0** e **pokeemerald-expansion**: autori originali, vedi [`CREDITS.md`](CREDITS.md)
- **traduzione italiana**: fork [`davidullo/hns_it`](https://github.com/davidullo/hns_it)
- **nomi ufficiali italiani**: [PokeAPI](https://pokeapi.co) (localizzazioni dei giochi) e [Pokémon Central Wiki](https://wiki.pokemoncentral.it)

# [Features](FEATURES.md)

**`pokemonHnS-expansion`** includes a mix of vanilla Emerald/FRLG features, re/de-made implementations of GSC/HGSS features, custom **`Modern Emerald`** features, and both features from [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series) and popular QOL enhancements made available by **`pokeemerald-expansion`**.  
A full list of the features present in Pokémon Heart & Soul 2.0 can be found in [`FEATURES.md`](FEATURES.md)
A full list of the features made available by **`pokeemerald-expansion`** can be found in [`AVAILABLE_FEATURES.md`](AVAILABLE_FEATURES.md).

# [Credits](CREDITS.md)

<!-- TODO: update .all-contributorsrc and CREDITS.md to match https://pokemonhns-development.github.io/pokehns-expansion-documentation/credits.html -->
<!-- [![](https://img.shields.io/github/all-contributors/pokemonHnS-Development/pokemonHnS-expansion/upcoming)](CREDITS.md) -->

<!-- TODO: confirm our actual crediting policy and how best to respect our upstreams -->
If you use **`pokemonHnS-expansion`**, please credit **Pokemon Heart and Soul**, and retain the full chain of credits as best possible.  
If you additionally use a more updated version of **`pokeemerald-expansion`**, please *specifically* credit **RHH (Rom Hacking Hideout)** and include the version number for clarity.
For example:

<!-- TODO: confirm the closest applicable expansion version number -->
```
pokemonHnS-expansion 2.0 is Based off RHH's pokeemerald-expansion version 1.15.1 https://github.com/rh-hideout/pokemonHnS-expansion/
```

Finally, please consider [crediting all contributors](CREDITS.md) involved in the project!

# **`pokemonHnS-expansion`** multiplayer compatibility

- **`pokemonHnS-expansion`** supports trade and link battle multiplayer functionality, which *should* extend to forks built on **`pokemonHnS-expansion`** but cannot be guaranteed.
- **`pokemonHnS-expansion`** is not compatible with official Pokémon games, **`pokemonHnS 1.X`**, **`Modern Emerald`**, or other **`pokeemerald-expansion`** projects.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches from **`pokeemerald-expansion`**.

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide to forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

<!-- TODO: update INSTALL.md to refer to HnS-specific things -->
## 📥 [Installing **`pokemonHnS-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokemonHnS-expansion`**](INSTALL.md#Building-pokemonHnS-expansion)

# [Documentation](https://pokemonhns-development.github.io/pokehns-expansion-documentation/)

For our player-facing documentation, visit the [**`pokemonHnS-expansion`** documentation page](https://pokemonhns-development.github.io/pokehns-expansion-documentation/).

# [Contributions and Community](https://discord.gg/ksNTFNSBj)

[![](https://dcbadge.limes.pink/api/server/ksNTFNSBj)](https://discord.gg/ksNTFNSBj)

If - in the window between 2.0 release and 2.0.1 release - you are looking to report a bug, make a suggestion, or give feedback, please join the [Pokémon Heart and Soul Discord server](https://discord.gg/ksNTFNSBj). You are also welcome to join just to participate in the community, including pinging our @guides (and only our guides) for help answering questions not sufficiently covered by our documentation or in-game resources.

# AI Disclosure
Since this is a controversial topic at the moment, we'd like to be transparent about use of AI for this project.

Every line of code written for the game is either hand-written or manually reviewed by a member of the team. However, it is still important to point out that LLMs like Claude Code and GitHub Copilot have been used for some tasks.

Here is what AI has been used for:
- Code Reviews of hand-written code
- Debugging more complex scenarios
- Auto Completion (stuff like repeating lists, DebugPrints, etc.)
- Creating Python Scripts for I/O procedures (like downloading/writing list data, I/O data with Excel, etc. namely for documentation)

AI has not been used for:
- Generating assets of any kind; Art or Music
