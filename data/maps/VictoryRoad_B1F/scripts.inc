VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Al pensiero di avvicinarmi alla\n"
	.string "LEGA POKÉMON…\p"
	.string "mi viene l'ansia…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Non ho potuto fare nulla…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LEGA POKÉMON si è allontanata\n"
	.string "di nuovo… Che delusione…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Per arrivare alla POKéMON\n"
	.string "LEAGUE serve la fiducia dei\l"
	.string "tuoi POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Il vostro legame si basa\n"
	.string "su una solida fiducia.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Stando sempre insieme, la fiducia\n"
	.string "cresce tra POKéMON e ALLENATORI.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Non è il traguardo, solo un luogo\n"
	.string "sulla via per la LEGA POKÉMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Così si fa!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Te la caverai di sicuro!\n"
	.string "I tuoi POKéMON son pronti a partire!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "I miei POKéMON sono di una\n"
	.string "bellezza cosmica!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Mai visto nessuno come te.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Anche fuori dalla lotta sento\n"
	.string "un potere incredibile venire da te\l"
	.string "e dai tuoi POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Ok, non arrabbiarti!\n"
	.string "Rilassati, andiamo piano!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Uau!\n"
	.string "Fantastico!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Certo, questa è la VIA VITTORIA.\p"
	.string "Ma non è poi così diversa\n"
	.string "dal cammino che hai fatto.\p"
	.string "Goditi il resto\n"
	.string "della strada!$"

