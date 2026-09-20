GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "BILL: Ciao, {PLAYER}! Fammi un\n"
    .string "piacere, prendi questo EEVEE.\p"
    .string "Era affidato a noi mentre\n"
    .string "ero via per il mio sistema.\p"
    .string "Qualcuno deve occuparsene,\n"
    .string "ma io non amo stare fuori.\p"
    .string "Posso contare su di te per\n"
    .string "giocare con lui, {PLAYER}?$"

BillHouse_Text_CountingOnYou:
    .string "BILL: Sapevo che ce l'avresti fatta!\p"
    .string "Grande! Sei un vero fenomeno!\p"
    .string "OK, conto su di te.\p"
    .string "Prenditene cura!$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} riceve EEVEE!$"

BillHouse_Text_EeveeMayEvolve:
    .string "BILL: Il PROF.ELM dice che EEVEE può\n"
    .string "evolversi in modi nuovi e ignoti.$"

BillHouse_Text_PartyFull:
    .string "Ehi, aspetta. Non puoi portare altri\n"
    .string "POKéMON.$"

BillHouse_Text_NoEevee:
    .string "Oh… E ora che faccio?$"

BillHouse_Text_PopWontWork:
    .string "BILL: Mio padre non lavora. Non fa\n"
    .string "altro che bighellonare tutto il giorno.\p"
    .string "Sta diventando un bel problema…$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Oh, collezioni POKéMON? Mio figlio\n"
    .string "BILL è un esperto.\p"
    .string "L'hanno appena chiamato al CENTRO\n"
    .string "POKéMON di AMARANTOPOLI.\p"
    .string "Mio marito è andato al CASINÒ\n"
    .string "senza che lo chiamassero…$"

BillHouse_Text_MomAfterEcruteak:
    .string "Mio marito era noto come\n"
    .string "POKéMANIAC.\p"
    .string "BILL deve aver preso da suo\n"
    .string "padre.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Sei un ALLENATORE?\p"
    .string "Ho un numero utile\n"
    .string "per te.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} ha registrato il numero di BILL.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mio fratello ha creato il sistema\n"
    .string "di archiviazione POKéMON del PC.\p"
    .string "Stavo per darti il numero\n"
    .string "di BILL…$"

BillHouse_Text_SisterPhoneFull:
    .string "Non puoi registrare altri numeri.$"

BillHouse_Text_SisterStorageSystem:
    .string "Mio fratello BILL ha creato il\n"
    .string "sistema di archiviazione POKéMON.$"
