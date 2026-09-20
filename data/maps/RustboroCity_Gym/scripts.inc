RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va?\p"
	.string "Ascolta, amico!\n"
	.string "Vuoi diventare CAMPIONE?\p"
	.string "Io non sono un ALLENATORE, ma\n"
	.string "posso darti consigli vincenti.\p"
	.string "Deciso, allora! Puntiamo insieme al\n"
	.string "CAMPIONATO POKéMON!\p"
	.string "È tuo compito come ALLENATORE\n"
	.string "collezionare le MEDAGLIE, giusto?\p"
	.string "Ma i CAPOPALESTRA non sono deboli!\p"
	.string "Ed è qui che entro in gioco io!\n"
	.string "Sono qui per darti consigli esperti!\p"
	.string "ROXANNE, la CAPOPALESTRA, usa\n"
	.string "POKéMON di tipo ROCCIA.\p"
	.string "Il tipo ROCCIA è molto resistente, ma\n"
	.string "non regge le mosse di tipo ACQUA e\l"
	.string "di tipo ERBA.\p"
	.string "Vieni da me dopo, se batti\n"
	.string "la CAPOPALESTRA.\p"
	.string "Beh, andiamo!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wow! Che vittoria mozzafiato!\n"
	.string "Il mio incitamento ha funzionato!\p"
	.string "Ottimo!\n"
	.string "Controlla il tuo SCHEDA ALLENATORE.\p"
	.string "La MEDAGLIA PIETRA che hai ottenuto\n"
	.string "dovrebbe essere registrata lì.\p"
	.string "In altre parole…\p"
	.string "Hai salito il primo gradino\n"
	.string "verso il CAMPIONATO!\p"
	.string "Dev'essere una sensazione fantastica!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Non sottovalutarci, noi ALLENATORI!\n"
	.string "Ti mostrerò perché siamo migliori!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Sei stato troppo forte per me…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Non hai ancora visto il terribile\n"
	.string "potere del tipo ROCCIA!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Se non batti me, non hai\n"
	.string "speranze contro ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Hai del potenziale!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE è più forte di me\n"
	.string "di parecchie volte.\p"
	.string "Meglio stare in guardia!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Saremo in centro città,\n"
	.string "ma che importa?\p"
	.string "I miei POKéMON ROCCIA hanno bisogno di\n"
	.string "spazio per scatenarsi!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, mamma mia!\n"
	.string "Il nostro sfidante è un bel tipo tosto!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Devo riconoscerlo alla nostra CAPO.\p"
	.string "Ci è voluta intelligenza per scegliere\n"
	.string "il tipo ROCCIA alla sua giovane età.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Ciao, sono ROXANNE, CAPOPALESTRA\n"
	.string "di FERRUGIPOLI.\p"
	.string "Sono diventata CAPOPALESTRA per\n"
	.string "mettere in pratica ciò che ho imparato\l"
	.string "alla SCUOLA PER ALLENATORI.\p"
	.string "Mi mostri gentilmente come lotti\n"
	.string "e con quali POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Quindi…\n"
	.string "ho perso…\p"
	.string "Sembra che abbia ancora molto\n"
	.string "da imparare…\p"
	.string "Capisco.\p"
	.string "Le regole della LEGA POKéMON dicono\n"
	.string "che agli ALLENATORI va dato questo\l"
	.string "se battono un CAPOPALESTRA.\p"
	.string "Accetta la MEDAGLIA PIETRA ufficiale\n"
	.string "della LEGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIETRA\n"
	.string "da ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "La MEDAGLIA SASSO aumenta l'ATTACCO\n"
	.string "dei tuoi POKéMON.\p"
	.string "Permette anche di usare la mossa MN\n"
	.string "TAGLIO fuori dalla lotta.\p"
	.string "Prendi anche questo.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Quella MACCHINA TECNICA, MT39,\n"
	.string "contiene ROCCIOMBRA.\p"
	.string "Non solo infligge danni facendo cadere\n"
	.string "rocce, ma abbassa anche la VELOCITÀ.\p"
	.string "Se usi una MT, insegna subito\n"
	.string "la mossa a un POKéMON.\p"
	.string "Ricorda, una MT si usa una volta sola,\n"
	.string "quindi pensaci prima di usarla.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Visto che sei così forte, dovresti\n"
	.string "sfidare altri CAPOPALESTRA.\p"
	.string "Combattendo con molti ALLENATORI,\n"
	.string "impari molte cose.$"

RustboroCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI PETALIPOLI$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI PETALIPOLI\p"
	.string "ALLENATORI CERTIFICATI DA ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, ciao, {PLAYER}?\n"
	.string "Sono ROXANNE di RUSTBORO.\p"
	.string "BRAWLY mi ha detto che stai\n"
	.string "salendo tra gli ALLENATORI a un\l"
	.string "ritmo incredibile.\p"
	.string "Beh, non voglio pensare che\n"
	.string "non possa batterti.\p"
	.string "Prometto che migliorerò la mia\n"
	.string "PALESTRA per poterti risfidare.\p"
	.string "Spero che non vedrai l'ora\n"
	.string "quanto me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "CAPOPALESTRA ROXANNE registrata\n"
	.string "nel POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Che piacere rivederti.\n"
	.string "Sono ROXANNE, la CAPOPALESTRA.\p"
	.string "Di certo entrambi abbiamo fatto\n"
	.string "molte lotte da allora.\p"
	.string "Voglio vedere quanto siamo\n"
	.string "migliorati. Combattiamo!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Di nuovo ho perso…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Devo ancora imparare molto\n"
	.string "sulle lotte tra POKéMON.\p"
	.string "Proprio per questo amo combattere\n"
	.string "ancora di più!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Che piacere rivederti.\n"
	.string "Sono ROXANNE, la CAPOPALESTRA.\p"
	.string "Di certo entrambi abbiamo fatto\n"
	.string "molte lotte da allora.\p"
	.string "Voglio vedere quanto siamo\n"
	.string "migliorati…\p"
	.string "Oh, no…\n"
	.string "Hai un solo POKéMON con te?\p"
	.string "Torna almeno con un altro\n"
	.string "POKéMON.$"
