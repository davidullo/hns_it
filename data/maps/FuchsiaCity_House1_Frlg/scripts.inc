FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "Il GUARDIANO della ZONA SAFARI è\n"
	.string "ma è ancora molto attivo.\p"
	.string "Però ha tutti i denti finti.$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "Hmm?\n"
	.string "Conosci BILL?\p"
	.string "È mio nipote!\p"
	.string "Ha sempre amato collezionare,\n"
	.string "anche da bimbo!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "BILL archivia i suoi POKéMON sul\n"
	.string "suo PC.\p"
	.string "Li hai visti?$"

