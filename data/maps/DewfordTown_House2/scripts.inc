DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Goditi lo spettacolo!\p"
	.string "È una SCIARPA DI SETA. È il top\n"
	.string "della moda, davvero!\p"
	.string "Oh, vedo i tuoi occhi brillare!\n"
	.string "Ami il mio stile Corposgargiante!\p"
	.string "Oh, sei un incanto!\n"
	.string "Ecco, voglio che sia tua!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, non hai spazio?\p"
	.string "Ascolta bene: la SCIARPA è\n"
	.string "un must! Venderei tutto\l"
	.string "per averla!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "La SCIARPA SETA potenzia le mosse\n"
	.string "di tipo Normale.\p"
	.string "È una SCIARPA stupenda, va\n"
	.string "con quasi ogni POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, hai attraversato il mare per\n"
	.string "visitare DEWFORD?\p"
	.string "Sei venuto qui perché hai\n"
	.string "sentito di RUDI?\p"
	.string "È così forte…\n"
	.string "Tutti lo idolatrano.$"

