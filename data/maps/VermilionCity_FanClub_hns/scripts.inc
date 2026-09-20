VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Sono il PRESIDENTE del POKéMON\n"
	.string "FAN CLUB.\p"
	.string "Ho allevato oltre 150 POKéMON.\p"
	.string "Sono molto esigente quando si parla\n"
	.string "di POKéMON.\p"
	.string "Sei venuto solo per sentire parlare\n"
	.string "dei miei POKéMON?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "Bene! Allora ascolta!\p"
	.string "Dunque… il mio RAPIDASH preferito…\p"
	.string "È… carino… adorabile… intelligente…\n"
	.string "insopportabilmente…\l"
	.string "e… stupendo… oh… dici\l"
	.string "così?…\l"
	.string "Troppo… selvaggio… bellissimo…\l"
	.string "dolcemente…\l"
	.string "lo adoro!\p"
	.string "Lo abbraccio… mentre… dorme… caldo\n"
	.string "e coccoloso…\l"
	.string "Oh, e… spettacolare…\l"
	.string "splendido… semplicemente divino…\p"
	.string "Ops! Guarda l'ora!\n"
	.string "Ti ho trattenuto troppo!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Grazie per avermi ascoltato.\n"
	.string "Voglio che tu abbia questo!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "È una RARA CARAMELLA che rende\n"
	.string "i POKéMON più forti.\p"
	.string "Preferisco rendere forti i miei\n"
	.string "POKéMON lottando, quindi\l"
	.string "puoi prenderla.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "Ciao, {PLAYER}!\p"
	.string "Sei venuto a sentirmi parlare\n"
	.string "ancora dei miei POKéMON?\p"
	.string "No? Oh… avevo altre storie\n"
	.string "da raccontare…$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "Che delusione…\p"
	.string "Torna se vuoi ascoltarmi.$"

PokemonFanClub_Text_Receptionist:
	.string "Il nostro PRESIDENTE parla molto\n"
	.string "quando si tratta di POKéMON…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "Adoro come CLEFAIRY agita\n"
	.string "il dito quando prova a\l"
	.string "usare PLESSIMETRO.\p"
	.string "Che tenerezza!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "Adoro CLEFAIRY, ma non ne\n"
	.string "ho mai preso uno.\p"
	.string "Quindi mi accontento di un\n"
	.string "POKé DOLL che ho trovato.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Oh, I see now. The girl who lost\n"
	.string "this POKé DOLL is sad…\p"
	.string "OK. Could you take this POKé DOLL\n"
	.string "back to that poor little girl?\p"
	.string "I'll befriend a real CLEFAIRY on\n"
	.string "my own one day. No worries!$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "Vedrai. Diventerò amico di\n"
	.string "un vero CLEFAIRY.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "Guarda il mio BAYLEEF!\p"
	.string "La foglia sul capo è carinissima!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "È un CLEFAIRY! Eh?\p"
	.string "Ah, giusto. È un POKé\n"
	.string "DOLL.$"

PokemonFanClub_Text_Bayleef:
	.string "BAYLEEF: Lii liif!$"

PokemonFanClub_Text_Listen:
	.string "Ascoltiamo con educazione\n"
	.string "gli altri allenatori.$"

PokemonFanClub_Text_Bragging:
	.string "Se qualcuno si vanta, vantati\n"
	.string "anche tu!$"
