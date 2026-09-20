PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Dicono che hanno visto un POKéMON\n"
	.string "volare alto sopra HOENN.\p"
	.string "Volerà in giro tutto il tempo?\n"
	.string "Non dovrà riposarsi da qualche parte?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Un POKéMON del cielo!\n"
	.string "Un POKéMON del cielo!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Da dove vieni?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Sì?\n"
	.string "SÌ?\p"
	.string "Non ho mai sentito un posto così.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "No? Non ha alcun senso.\n"
	.string "Devi pur venire da qualche parte.\p"
	.string "Oh! Aspetta! Non dirmi che sei\n"
	.string "nato in fondo al mare?$"

