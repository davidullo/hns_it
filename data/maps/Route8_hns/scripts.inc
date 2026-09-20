Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "Siamo il gruppo allenatori della\n"
	.string "FEDERAZIONE POKéMON di KANTO.\p"
	.string "Ti passiamo sotto le ruote!$"

Route8_Text_BikerDwayneBeaten:
	.string "S-scusa!$"

Route8_Text_BikerDwayneAfter:
	.string "La FEDERAZIONE POKéMON di KANTO\n"
	.string "non cadrà mai!$"

Route8_Text_BikerHarrisSeen:
	.string "La polizia ci ha chiuso\n"
	.string "il PASSAGGIO SOTTERRANEO!\p"
	.string "Mi fa infuriare!$"

Route8_Text_BikerHarrisBeaten:
	.string "P-perdonami!$"

Route8_Text_BikerHarrisAfter:
	.string "Steso da un Punk\n"
	.string "di JOHTO…$"

Route8_Text_BikerZekeSeen:
	.string "Siamo la FEDERAZIONE POKéMON\n"
	.string "di KANTO!\n"
	.string "Evvai!$"

Route8_Text_BikerZekeBeaten:
	.string "Accidenti! Scusa!$"

Route8_Text_BikerZekeAfter:
	.string "Cercheremo di non disturbare\n"
	.string "nessuno, d'ora in poi…$"

Route8_Text_SupernerdSamSeen:
	.string "Come funziona il TRENO CALAMITA?$"

Route8_Text_SupernerdSamBeaten:
	.string "Voglio solo vedere il TRENO\n"
	.string "CALAMITA…$"

Route8_Text_SupernerdSamAfter:
	.string "La forza delle Calamita è incredibile!$"

Route8_Text_SupernerdTomSeen:
	.string "Hm… Hai un sacco di MEDAGLIE.$"

Route8_Text_SupernerdTomBeaten:
	.string "Come pensavo… Sei forte!$"

Route8_Text_SupernerdTomAfter:
	.string "Le MEDAGLIE danno vantaggi\n"
	.string "in battaglia.$"

Route8_Text_LockedDoor:
	.string "È chiuso…$"

Route8_Text_UndergroundPathSign:
	.string "Il volantino è strappato.\p"
	.string "Impossibile leggerlo…$"
