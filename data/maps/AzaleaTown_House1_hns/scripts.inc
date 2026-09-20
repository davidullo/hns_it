AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Tutti gli SLOWPOKE sono spariti\n"
	.string "dalla città.\p"
	.string "Il guardiano del bosco forse\n"
	.string "è arrabbiato con noi…\p"
	.string "Sarà un presagio. Meglio stare\n"
	.string "dentro.$"

CharcoalKiln_Text_Boss2:
	.string "Gli SLOWPOKE sono tornati…$"

CharcoalKiln_Text_Boss3:
	.string "Gli SLOWPOKE sono tornati…\p"
	.string "Ma il mio APPRENTICE non è\n"
	.string "tornato dal BOSCO ILEX.\p"
	.string "Dove sarà finito quel pigro?$"

CharcoalKiln_Text_Boss4:
	.string "Hai scacciato il TEAM ROCKET e\n"
	.string "sei entrato solo nel BOSCO?\p"
	.string "Serve fegato! Mi piace.\n"
	.string "Vieni ad allenarti con noi.$"

CharcoalKiln_Text_Apprentice1:
	.string "Dove sono finiti gli SLOWPOKE?\p"
	.string "Staranno giocando da qualche parte?$"

CharcoalKiln_Text_Apprentice2:
	.string "Gli SLOWPOKE sono tornati!$"

CharcoalKiln_Text_Apprentice3:
	.string "Scusa, non ti ho ringraziato.\p"
	.string "Questa è la CARBONELLA che ho fatto.\p"
	.string "I POKéMON FUOCO saranno felici\n"
	.string "di portarla.$"

CharcoalKiln_Text_Apprentice4:
	.string "Gli SLOWPOKE sono tornati e hai\n"
	.string "trovato anche FARFETCH'D.\p"
	.string "Sei il migliore, ragazzo!$"

CharcoalKiln_Text_Farfetchd:
	.string "FARFETCH'D: Kuaa!$"
