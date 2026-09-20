CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} usa il PC.\p"
	.string "…\p"
	.string "Qualcuno stava scrivendo\n"
	.string "una e-mail.\p"
	.string "…Spero che verrai in KANTO.\p"
	.string "Ti stupirà vedere quanto è\n"
	.string "cambiato tutto qui.\p"
	.string "Vedrai anche molti POKéMON che\n"
	.string "non sono di JOHTO.\p"
	.string "Al PRODUTTORE\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "UFFICIO SVILUPPO HEART & SOUL$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Ciao, la Patch 15...\p"
	.string "Scusa, cioè...\p"
	.string "Ciao, sono il GAME DIRECTOR!\p"
	.string "Ho creato le mappe, i tileset,\n"
	.string "gli script e molto altro.\p"
	.string "Ma non ce l'avrei fatta senza\n"
	.string "gli altri dev e i playtester.\p"
	.string "Grazie per giocare! Spero che\n"
	.string "vi sia piaciuto HEART & SOUL.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "Stiamo rifacendo il gioco\n"
	.string "con pokeemerald expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "Hai sentito parlare di THE EGGENING?\n"
	.string "Era un bug del playtest\l"
	.string "che trasformava a caso i POKéMON\l"
	.string "in UOVA!\p"
	.string "La correzione l'ho fatta io!$"

CeladonMansion2F_Text_Phant:
	.string "Adoro i DEMAKE!\p"
	.string "Hai giocato a SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH?\l"
	.string "L'ho tradotto io!\p"
	.string "Per il prossimo DEMAKE penso\n"
	.string "di fare ALOLA!$"

CeladonMansion2F_Text_Exclsior:
	.string "Ho realizzato le sprite uniche\n"
	.string "di NUOTA per ogni POKéMON!\p"
	.string "Il progetto è OPEN SOURCE,\n"
	.string "aggiungi anche tu novità!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Oh!\p"
	.string "Sono bravo a trovare i difetti,\n"
	.string "e a sistemare i piccoli.\p"
    .string "Una barzelletta?\p"
    .string "LANCE ha provato a insegnare\n"
    .string "ALITO DRAGO a DRAGONITE.\p"
    .string "Ma DRAGONITE andava troppo\n"
    .string "veloce con IPERVELOCITÀ e non\l"
    .string "beccarla!$"
