FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
	.string "Hai provato la GARA SAFARI?\p"
	.string "Ci sono POKéMON rari che\n"
	.string "si catturano solo lì.$"

FuchsiaCity_Text_SafariZoneZooInFront::
	.string "La ZONA SAFARI ha uno zoo davanti\n"
	.string "all'ingresso.\p"
	.string "Dietro c'è la GARA SAFARI per\n"
	.string "prendere POKéMON.$"

FuchsiaCity_Text_WheresSara::
	.string "ERIK: Dov'è SARA?\n"
	.string "Dovevo incontrarla qui.$"

FuchsiaCity_Text_ItemBallInThere::
	.string "That item ball in there…\n"
	.string "Were you wanting that?\p"
	.string "Me, too!\n"
	.string "…Huh? That's a POKéMON?$"

FuchsiaCity_Text_CitySign::
	.string "FUCSIAPOLI\n"
	.string "Ecco la Passione Rosa!$"

FuchsiaCity_Text_SafariZoneSign::
	.string "PARADISO POKéMON\n"
	.string "ZONA SAFARI$"

FuchsiaCity_Text_SafariGameSign::
	.string "GARA SAFARI\n"
	.string "PIGLIA-POKéMON!$"

FuchsiaCity_Text_WardensHomeSign::
	.string "ZONA SAFARI\n"
	.string "CASA GUARDIANO$"

FuchsiaCity_Text_SafariZoneOfficeSign::
	.string "PARADISO POKéMON!\n"
	.string "Benvenuto nella ZONA SAFARI!\l"
	.string "UFFICIO SAFARI$"

FuchsiaCity_Text_GymSign::
	.string "PALESTRA DI FUCSIAPOLI\n"
	.string "CAPO: KOGA\l"
	.string "Il Maestro Ninja del Veleno$"

FuchsiaCity_Text_ChanseySign::
	.string "Nome: CHANSEY\n"
	.string "Catturarlo è solo fortuna.$"

FuchsiaCity_Text_VoltorbSign::
	.string "Nome: VOLTORB\n"
	.string "È identico a una POKé BALL.$"

FuchsiaCity_Text_KangaskhanSign::
	.string "Nome: KANGASKHAN\p"
	.string "Un POKéMON materno che alleva\n"
	.string "i piccoli nella sua sacca.$"

FuchsiaCity_Text_SlowpokeSign::
	.string "Nome: SLOWPOKE\n"
	.string "Amichevole e molto lento.$"

FuchsiaCity_Text_LaprasSign::
	.string "Nome: LAPRAS\n"
	.string "Noto come il Re dei mari.$"

FuchsiaCity_Text_OmanyteSign::
	.string "Nome: OMANYTE\n"
	.string "Un POKéMON rarissimo che\l"
	.string "rinato da un fossile.$"

FuchsiaCity_Text_KabutoSign::
	.string "Nome: KABUTO\n"
	.string "Un POKéMON rarissimo che\l"
	.string "rinato da un fossile.$"

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
	.string "……$"

Text_SubstituteTeach::
	.string "Se fossi un KANGASKHAN\n"
	.string "bebè.\p"
	.string "E fare da sostituto per il\n"
	.string "bebè…\p"
	.string "E coccolarmi nella\n"
	.string "tasca della mamma.\p"
	.string "Ma solo i POKéMON possono\n"
	.string "usare SOSTITUTO…\p"
	.string "Vuoi che insegni SOSTITUTO\n"
	.string "a un tuo POKéMON?$"

Text_SubstituteDeclined::
	.string "Davvero?\n"
	.string "SOSTITUTO sembra bello…$"

Text_SubstituteWhichMon::
	.string "Quale POKéMON vuole imparare\n"
	.string "SOSTITUTO?$"

Text_SubstituteTaught::
	.string "Cosa darei per infilarmi nella\n"
	.string "tasca di un KANGASKHAN…$"

FuchsiaCity_Text_MyFatherIsGymLeader::
	.string "Mio padre è il CAPOPALESTRA\n"
	.string "di qui.\p"
	.string "Mi alleno a usare i POKéMON\n"
	.string "Veleno come lui.$"

