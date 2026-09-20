CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "Non ricordo l'ultima volta\n"
	.string "che qualcuno mi visita.\p"
	.string "Da giovane ero anche io\n"
	.string "ALLENATORE POKéMON.\l"
	.string "Volevo raggiungere la torre e\l"
	.string "tuffarmi nell'oceano.\p"
	.string "Mi sono impegnato in molte\n"
	.string "cose.\p"
	.string "Ora me la prendo comoda,\n"
	.string "ascoltando onde e venti\l"
	.string "sulla riva.$"

CianwoodCity_Text_BellTowerStory:
	.string "Hai sentito della TORRE CAMPANA\n"
	.string "di ECRUTEAK?\p"
	.string "In cima alla torre ci sono le\n"
	.string "CAMPANE CHIARE.\p"
	.string "Non fanno alcun rumore\n"
	.string "nel vento forte.\p"
	.string "C'è un solo modo per farle\n"
	.string "suonare.\p"
	.string "È procurarsi un'altra CAMPANA\n"
	.string "CHIARA come quelle in cima alla\l"
	.string "torre.\p"
	.string "Ci ho provato da giovane.\n"
	.string "Ma non l'ho mai avuta…$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "Hai sentito delle ISOLE VORTICOSE?\p"
	.string "Ci sono le cosiddette CAMPANE\n"
	.string "ONDA, alla cascata.\p"
	.string "Non fanno alcun rumore\n"
	.string "tra le onde forti.\p"
	.string "C'è un solo modo per farle\n"
	.string "suonare.\p"
	.string "È procurarsi un'altra CAMPANA\n"
	.string "ONDA, come quelle della\l"
	.string "cascata.\p"
	.string "Ci ho provato da giovane.\n"
	.string "Ma non l'ho mai avuta…$"

CianwoodCity_Text_ClearBellReaction:
	.string "Oh! Hai ottenuto la CAMPANA\n"
	.string "CHIARA?\p"
	.string "Il mio vecchio sogno…\n"
	.string "Vedo…\p"
	.string "Ce l'hai fatta…\n"
	.string "…\l"
	.string "…Le sento!\p"
	.string "Il suono delle campane nel vento\n"
	.string "arriva dalla direzione della\l"
	.string "TORRE CAMPANA…$"

CianwoodCity_Text_TidalBellReaction:
	.string "Oh! Hai ottenuto la CAMPANA\n"
	.string "ONDA?\p"
	.string "Il mio vecchio sogno…\n"
	.string "Vedo…\p"
	.string "Ce l'hai fatta…\n"
	.string "…\l"
	.string "…Le sento!\p"
	.string "Il suono delle campane sulla\n"
	.string "brezza che arriva dalle\l"
	.string "ISOLE VORTICOSE…$"
