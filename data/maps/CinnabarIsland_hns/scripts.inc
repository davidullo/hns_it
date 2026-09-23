CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "BLAINE: Non mollerò mai\n"
	.string "finché non ricostruirò\l"
	.string "la PALESTRA!\p"
	.string "Starò al DOJO di LOTTA\n"
	.string "Intanto.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "Chi sei?\p"
	.string "Beh, si vede che sei un\n"
	.string "allenatore…\p"
	.string "Mi chiamo BLU.\p"
	.string "Ero il CAMPIONE, anche se\n"
	.string "solo per poco tempo…\p"
	.string "Quel ROSSO mi ha battuto…\p"
	.string "Comunque, cosa vuoi? Vuoi\n"
	.string "sfidarmi o roba simile?\p"
	.string "…Mi spiace dirlo, ma non\n"
	.string "ho voglia di lottare ora.\p"
	.string "Guardati bene intorno…\p"
	.string "Un vulcano erutta e in un\n"
	.string "attimo una città svanisce.\p"
	.string "Possiamo vincere e perdere coi\n"
	.string "POKéMON. Ma se la natura\l"
	.string "trema, perdiamo in un attimo.\p"
	.string "…\p"
	.string "È così che va…\p"
	.string "Ma io sono ancora un allenatore.\p"
	.string "Se vedo un avversario forte,\n"
	.string "mi prudono le mani.\p"
	.string "Se vuoi sfidarmi, ti servono\n"
	.string "prima 15 medaglie.\p"
	.string "Allora ti sfiderò.$"

CinnabarIsland_Text_Blue:
	.string "Chi sei?\p"
	.string "Beh, si vede che sei un\n"
	.string "allenatore…\p"
	.string "Mi chiamo BLU.\p"
	.string "Ero il CAMPIONE, anche se\n"
	.string "solo per poco tempo…\p"
	.string "Quel ROSSO mi ha battuto…\p"
	.string "Comunque, cosa vuoi? Vuoi\n"
	.string "sfidarmi o roba simile?\p"
	.string "…Mi spiace dirlo, ma non\n"
	.string "ho voglia di lottare ora.\p"
	.string "Guardati bene intorno…\p"
	.string "Un vulcano erutta e in un\n"
	.string "attimo una città svanisce.\p"
	.string "Possiamo vincere e perdere coi\n"
	.string "POKéMON. Ma se la natura\l"
	.string "trema, perdiamo in un attimo.\p"
	.string "…\p"
	.string "È così che va…\p"
	.string "Ma io sono ancora un allenatore.\p"
	.string "Se vedo un avversario forte,\n"
	.string "mi prudono le mani.\p"
	.string "Se vuoi sfidarmi, vieni a\n"
	.string "SMERALDOPOLI!\p"
	.string "Allora ti sfiderò.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "C'è un avviso…\p"
	.string "PALESTRA di ISOLA CANNELLA è alle\n"
	.string "ISOLE SPUMARINE.\p"
	.string "BLAINE$"

CinnabarIsland_Text_Sign:
	.string "ISOLA CANNELLA\p"
	.string "La città ardente di desiderio$"

