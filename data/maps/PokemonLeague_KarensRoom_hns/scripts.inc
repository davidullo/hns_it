PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC

PokemonLeague_KarensRoom_EventScript_KarenRematchStandard::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_POSTOBC_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "KAREN: Ah, sei di nuovo tu.\p"
    .string "Spero tu non abbia dimenticato\n"
    .string "la mia convinzione:\p"
    .string "La vera forza nasce dalla fiducia\n"
    .string "nei propri POKéMON.\p"
    .string "Dall'ultimo incontro, il mio\n"
    .string "legame con i POKéMON si è\l"
    .string "rafforzato ancora.\p"
    .string "Sei pronto ad affrontare una squadra\n"
    .string "unita da un legame indistruttibile?\p"
    .string "Mostrami la potenza del legame\n"
    .string "con i tuoi POKéMON.$"

PokemonLeague_KarensRoom_Text_Before:
    .string "Sono KAREN dei SUPERQUATTRO.\p"
    .string "Sei {PLAYER}? Che divertente.\p"
    .string "Adoro i POKéMON di tipo BUIO.\p"
    .string "Trovo la loro immagine selvaggia\n"
    .string "così attraente. E sono\l"
    .string "così forti.\p"
    .string "Credi di poterli battere?\n"
    .string "Cerca solo di divertirmi.\p"
    .string "Andiamo.$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "Bene, sei bravo. Mi piace\n"
    .string "in un allenatore.$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "POKéMON forti.\p"
    .string "POKéMON deboli.\p"
    .string "Questa è solo la percezione\n"
    .string "egoista delle persone.\p"
    .string "I veri allenatori abili dovrebbero\n"
    .string "provare a vincere con i loro preferiti.\p"
    .string "Mi piace il tuo stile. Capisci\n"
    .string "cosa conta davvero.\p"
    .string "Vai, il CAMPIONE ti aspetta.$"

