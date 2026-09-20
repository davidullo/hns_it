BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Questa è la TORRE LOTTA!\n"
	.string "Mantieni la serie di vittorie\l"
	.string "come miglior ALLENATORE!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Questo è il PALAGOTTA!\n"
	.string "Occhi alle lotte di POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Quest'è l'ARENA LOTTA!\n"
	.string "Venite, squadre durissime!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Questa è la PIRAMIDE LOTTA!\n"
	.string "Avanza nella missione!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "SALA CLASSIFICHE FRONTIERA\n"
	.string "Punta a nuovi record!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "PUNTI LOTTA, ANGOLO DI CAMBIO\n"
	.string "Cambia i tuoi Punti Lotta!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "È enorme!\p"
	.string "La TORRE LOTTA è speciale.\n"
	.string "Diversa dalle altre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Il mio sogno è vincere sia la\n"
	.string "FRONTIERA LOTTA che la LEGA\l"
	.string "POKéMON.\p"
	.string "E se il sogno si avvera…\p"
	.string "Io… io chiedo a MIMI qui accanto\n"
	.string "se vuole essere mia amica!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PIRAMIDE DI LOTTA è troppo dura!\n"
	.string "Non riesco ad arrivare in cima!\p"
	.string "Visto che non ho più alternative,\n"
	.string "forse la scalo da fuori…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Vivo nell'oscurità…\n"
	.string "Sì… Cosa è degno di me?\l"
	.string "Nient'altro che la PIRAMIDE LOTTA…\p"
	.string "Che ne dici di vagare nell'oscurità\n"
	.string "e in totale, assoluta disperazione?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Non dormo da una settimana, ma\n"
	.string "ho creato la squadra definitiva!\p"
	.string "Non vedo come potrei perdere.\n"
	.string "Invaderemo l'ARENA DI LOTTA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Anche SCOTT ti ha portato qui?\n"
	.string "Ma com'è fatto quell'uomo?\p"
	.string "Sembra che sappia davvero\n"
	.string "scovare ALLENATORI in gamba, ma…\p"
	.string "L'ho sempre visto in giro, mai\n"
	.string "in lotta.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Io credo in te, amichetto!\p"
	.string "Se vinci, ti preparo tutti i\n"
	.string "dolcetti che preferisci, mio ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON sembra distratto…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Dicono che sono ficcanaso,\n"
	.string "ma non posso farci niente.\p"
	.string "Cappello storto!\n"
	.string "Oh no, spazzatura a terra!\l"
	.string "Ops, è quasi ora di cena!\p"
	.string "Al PALAGOTTA non so se riesco\n"
	.string "a stare a guardare…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Ora non sembrerò granché, ma una\n"
	.string "volta ho battuto un CAPOPALESTRA.\p"
	.string "Chissà, magari vale la pena\n"
	.string "riprovare per la gloria.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sono rapido in Bicicletta, e vale\n"
	.string "anche in battaglia.\p"
	.string "Vinco gli incontri in un\n"
	.string "baleno!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Con i POKéMON sono più forte\n"
	.string "del papà.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Avanti, tesoro mio!\n"
	.string "Vinci anche per il babbo!\p"
	.string "Sei proprio come la mamma,\n"
	.string "quindi dominerai!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Arrivare qui non è stato facile.\n"
	.string "Dicevano di una bella\l"
	.string "ragazza all'ARENA LOTTA.\p"
	.string "E invece di lei, sapete che\n"
	.string "ho trovato?\p"
	.string "Un branco di praticanti di arti\n"
	.string "marziali sudati e puzzolenti!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "A volte vedo entrare lì un vecchio\n"
	.string "dall'aria davvero importante.\p"
	.string "Ha dei POKéMON eccezionali.\n"
	.string "Però sembra proprio gentile.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Lo conosci?\n"
	.string "Il mito della PIRAMIDE LOTTA?\p"
	.string "Quando un ALLENATORE sicuro\n"
	.string "mira alla vetta dorata,\l"
	.string "apparirà un uomo tra gli uomini.\p"
	.string "Non conosci quel mito?\n"
	.string "Ma certo che no!\l"
	.string "Me lo sto inventando!\p"
	.string "E che dovrebbe voler dire?\n"
	.string "Questo, amico, non lo so!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Caspita! Oh caspita!\n"
	.string "Prima non perdevo mai!\p"
	.string "Ma sono stato travolto senza\n"
	.string "alcuna speranza!\p"
	.string "E poi mi dicono che non ho\n"
	.string "talento?! Mah!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Costui ha incontrato un ALLENATORE\n"
	.string "terribilmente tosto nella sfida alla\l"
	.string "TORRE DI LOTTA.\p"
	.string "Ora guardatelo…\p"
	.string "Se mai vai alla TORRE DI LOTTA,\n"
	.string "muoviti con cautela.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Sì!\n"
	.string "Finalmente ho abbastanza Punti Lotta!\p"
	.string "Adesso cambio per un'altra\n"
	.string "bamboleia gigante!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Già, va bene!\n"
	.string "Quindi questa è la SALA RANKING!\p"
	.string "Voglio passare alla storia come\n"
	.string "grande campione e lasciare\l"
	.string "qui il mio nome per sempre.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Con te accanto, posso fare tutto.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Oh, tesoro, sei meraviglioso!\p"
	.string "Oh, non resisto più!\p"
	.string "Andiamo subito in una SALA\n"
	.string "MULTILOTTA, adesso!\p"
	.string "Se ci uniamo al SALA LOTTA,\n"
	.string "il potere del nostro amore batte\l"
	.string "chiunque incontriamo.\p"
	.string "Davanti a noi, tesoro, tutti\n"
	.string "cadranno come domini!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "La ZONA LOTTA non è solo per\n"
	.string "ALLENATORI duri.\p"
	.string "Pare che abbiano invitato gente\n"
	.string "dotata di abilità speciali.\p"
	.string "Quell'uomo, SCOTT…\p"
	.string "Forse ha costruito tutto questo per\n"
	.string "uno scopo più grande…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Permesso, giovanotto.\n"
	.string "Hai una buona vista?\p"
	.string "Più avanti c'è un albero strano, e\n"
	.string "ai miei occhi stanchi pare ondeggiare.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Permesso, giovanotto.\n"
	.string "Hai una buona memoria?\p"
	.string "Ho la Sensazione che qui accanto\n"
	.string "ci fosse un albero strano.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Io…\n"
	.string "L'ho visto!\p"
	.string "Davanti c'era un POKéMON\n"
	.string "appiccicoso dalla coda lunga!\p"
	.string "Si nascondeva sotto un masso\n"
	.string "e mi fissava di continuo!$"
