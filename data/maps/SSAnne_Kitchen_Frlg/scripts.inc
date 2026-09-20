SSAnne_Kitchen_Frlg_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_0x8008, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_0x8008, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
	.string "Ehi, mon petit!\n"
	.string "Siamo occupati qui!\l"
	.string "Fuori dai piedi!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
	.string "Ho visto una strana BACCA nei rifiuti.\n"
	.string "Chissà cosa era?$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
	.string "Sono così occupato che mi gira la testa!\n"
	.string "Dammi un po' di spazio!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
	.string "Hum-de-hum-de-ho…\p"
	.string "Pelo patate ogni giorno!\n"
	.string "Hum-hum…$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
	.string "Hai sentito di SNORLAX?\n"
	.string "È un mangione.\p"
	.string "Nessun POKéMON mangia e dorme\n"
	.string "come fa SNORLAX!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
	.string "Tira… Fiut…\p"
	.string "Io pelo solo cipolle…\n"
	.string "Tira…$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
	.string "Ehm!\n"
	.string "Sì, sono le CHEF!\p"
	.string "Il piatto principale è$"

SSAnne_Kitchen_Text_SalmonDuSalad::
	.string "Insalata di salmone!\p"
	.string "Però gli ospiti potrebbero dire\n"
	.string "che è ancora pesce!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
	.string "Anguille al barbecue!\p"
	.string "Temo che gli ospiti si ribelleranno.$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
	.string "Bistecca di prima scelta!\p"
	.string "Ma ho abbastanza filetti di\n"
	.string "manzo?$"

