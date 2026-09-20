Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Quella GALLERIA RUSTURF…\p"
	.string "All'inizio avevamo una squadra enorme che\n"
	.string "scavava la roccia con macchinari moderni.\l"
	.string "Ma abbiamo dovuto fermarci.\p"
	.string "A quanto pare avremmo danneggiato\n"
	.string "i POKéMON selvatici della\l"
	.string "zona.\p"
	.string "Quindi ora non ci resta che oziare\n"
	.string "qui senza fare nulla.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "C'è un uomo che scava da solo la sua\n"
	.string "strada verso VERDANTURF.\l"
	.string "Vuole passare a tutti i costi.\p"
	.string "Dice che se scava poco per volta\n"
	.string "senza usare macchinari, non\l"
	.string "disturberà i POKéMON e non\l"
	.string "danneggerà l'ambiente naturale.\p"
	.string "Chissà se è già passato.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Per arrivare a VERDANTURF senza usare\n"
	.string "questa GALLERIA, dovresti attraversare\l"
	.string "il mare fino a DEWFORD, salpare per\l"
	.string "PORTOALGHE e passare per MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Hai sentito? La GALLERIA per VERDANTURF\n"
	.string "è stata aperta!\p"
	.string "A volte, se ci speri abbastanza,\n"
	.string "i sogni diventano realtà.$"

