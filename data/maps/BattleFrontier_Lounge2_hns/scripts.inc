BattleFrontier_Lounge2_hns_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice_hns::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews_hns
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews_hns::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle_hns::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble_hns::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns::
	.string "Salve! Per le notizie sulla\n"
	.string "FRONTIERA LOTTA sono il n. 1.\p"
	.string "Puoi considerarmi il\n"
	.string "MANIACO DELLA FRONTIERA.\p"
	.string "Solo un controllo: sei un ALLENATORE,\n"
	.string "vero?\p"
	.string "Condividerò volentieri le novità\n"
	.string "che ho raccolto sulla FRONTIERA.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns::
	.string "Ehi! Sei qui per estorcermi\n"
	.string "le ultime voci? Vabbè, va bene!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight_hns::
	.string "Beh? Beh? Beh?\p"
	.string "Sono sicuro che le mie info\n"
	.string "ti sono servite un sacco, vero?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest_hns::
	.string "Vediamo un po'…\p"
	.string "Sembra che {STR_VAR_1}\n"
	.string "sia il posto più in voga.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns::
	.string "Vediamo un po'…\p"
	.string "Sembra che la TORRE LOTTA\n"
	.string "{STR_VAR_1} sia la più in voga.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere_hns::
	.string "Non lo sapevi, eh?\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama FRONTIER BRAINS è lì.\p"
	.string "È un ALLENATORE misterioso,\n"
	.string "la SALON MAIDEN gestisce il posto.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons_hns::
	.string "Hai affrontato la SALON MAIDEN?\p"
	.string "Quando valuta l'avversario,\n"
	.string "pare che usi questi POKéMON:\p"
	.string "un PSI di tipo PSICHICO,\n"
	.string "un VULCANO di tipo FUOCO,\l"
	.string "e un SONNO di tipo NORMALE.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons_hns::
	.string "Hai affrontato la SALON MAIDEN\n"
	.string "quando è seria?\p"
	.string "Quando lotta al massimo,\n"
	.string "pare che usi questi POKéMON:\p"
	.string "un EONE di DRAGO E PSICHICO,\n"
	.string "un TUONO di tipo ELETTRICO,\l"
	.string "e un SONNO di tipo NORMALE.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere_hns::
	.string "Scommetto che non lo sai!\p"
	.string "Uno dei forti ALLENATORI che SAVERIO\n"
	.string "chiama MENTI DELLA FRONTIERA è lì.\p"
	.string "È lo stravagante ALLENATORE\n"
	.string "chiamato AS DELLA CUPOLA.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons_hns::
	.string "Hai mai sfidato il MAESTRO\p"
	.string "DEL DOMO? Quando sottovaluta un\n"
	.string "avversario, usa questi tre POKéMON:\p"
	.string "Un POKéMON DRAGO & VOLANTE,\n"
	.string "un POKéMON ACQUA & TERRA,\l"
	.string "e un POKéMON FUOCO & VOLANTE.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons_hns::
	.string "Hai già sfidato l'AS DELLA\n"
	.string "CUPOLA sul serio?\p"
	.string "Quando mostra la sua strategia,\n"
	.string "usa questi tre POKéMON:\p"
	.string "Un POKéMON DRAGO E VOLANTE, l'EONE,\n"
	.string "un PESCE FANGOSO ACQUA E TERRA,\l"
	.string "e una GAMBA DI FERRO ACCIAIO E\l"
	.string "PSICHICO.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere_hns::
	.string "Scommetto che non lo sai!\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama MENTI DELLA FRONTIERA\p"
	.string "c'è proprio qui: è quel bizzarro\n"
	.string "ALLENATORE detto CAPO FABBRICA.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons_hns::
	.string "Hai già sfidato il CAPO\n"
	.string "FABBRICA?\p"
	.string "Vediamo… Quando lotta, prende\n"
	.string "solo tre POKéMON a noleggio.\p"
	.string "Lotta praticamente nelle stesse\n"
	.string "condizioni di te.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons_hns::
	.string "Hai già sfidato il CAPO FABBRICA\n"
	.string "sul serio?\p"
	.string "Quando scende in campo, prende\n"
	.string "comunque tre POKéMON a noleggio.\p"
	.string "Lotta praticamente nelle stesse\n"
	.string "condizioni di te.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere_hns::
	.string "Non lo sapevi, eh?\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama FRONTIER BRAINS è lì.\p"
	.string "È un ALLENATORE spaventoso,\n"
	.string "la PIKE QUEEN, a gestire il posto.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons_hns::
	.string "Hai affrontato la PIKE QUEEN\n"
	.string "prima?\p"
	.string "Se è di buon umore, si dice\n"
	.string "che usa tre POKéMON:\p"
	.string "un SERPENTE ZANNA di VELENO,\n"
	.string "MUFFA COLEOTTERO, ROCCIA,\l"
	.string "e un TENEREZZA di ACQUA.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons_hns::
	.string "Hai affrontato la PIKE QUEEN\n"
	.string "quando è seria?\p"
	.string "Quando si infuria davvero,\n"
	.string "usa questi tre POKéMON:\p"
	.string "un SERPENTE ZANNA di VELENO,\n"
	.string "un SERPENTE FERRO ACCIAIO E TERRA,\l"
	.string "e un ATROCE di ACQUA E\l"
	.string "VOLANTE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere_hns::
	.string "Scommetto che non lo sai!\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama MENTI DELLA FRONTIERA\p"
	.string "c'è proprio qui: è la simpatica\n"
	.string "ALLENATRICE DIVA DELL'ARENA.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons_hns::
	.string "Hai già sfidato la DIVA\n"
	.string "DELL'ARENA?\p"
	.string "Quando studia l'avversario,\n"
	.string "si dice che usi questi POKéMON:\p"
	.string "Un POKéMON COLEOTTERO E LOTTA\n"
	.string "con CORNO, uno BUIO LUCELUNARE,\l"
	.string "e un COLEOTTERO SPETTRO CAMBIAPIELLE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons_hns::
	.string "Hai già sfidato la DIVA\n"
	.string "DELL'ARENA sul serio?\p"
	.string "Quando dà il massimo, si\n"
	.string "dice che usi questi POKéMON:\p"
	.string "Un POKéMON BUIO con LUCELUNARE,\n"
	.string "un POKéMON OMBRA SPETTRO E VELENO\l"
	.string "e un POKéMON ERBA E LOTTA,\l"
	.string "di tipo FUNGO.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere_hns::
	.string "Non lo sapevi, eh?\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama FRONTIER BRAINS è lì.\p"
	.string "Il posto lo gestisce un ALLENATORE\n"
	.string "sinistro, detto PALACE MAVEN.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons_hns::
	.string "Hai affrontato PALACE MAVEN\n"
	.string "prima?\p"
	.string "Quando prova lo spirito\n"
	.string "dell'avversario, usa questi POKéMON:\p"
	.string "un PIPISTRELLO VELENO E VOLANTE,\n"
	.string "un PIGRIZIA NORMALE, e un\l"
	.string "POKéMON TRASPORTO di ACQUA E GELO.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons_hns::
	.string "Hai affrontato PALACE MAVEN\n"
	.string "quando è serio?\p"
	.string "Quando dà il massimo,\n"
	.string "si dice che usi questi POKéMON:\p"
	.string "Un POKéMON LEGGENDA di FUOCO,\n"
	.string "un PIGRIZIA NORMALE,\l"
	.string "e un POKéMON AURORA di ACQUA.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere_hns::
	.string "Non lo sapevi, eh?\p"
	.string "Uno dei migliori ALLENATORI che\n"
	.string "SAVERIO chiama FRONTIER BRAINS è lì.\p"
	.string "È un ALLENATORE ardente,\n"
	.string "il PYRAMID KING gestisce il posto.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons_hns::
	.string "Hai affrontato il PYRAMID KING\n"
	.string "prima?\p"
	.string "Quando valuta la forza\n"
	.string "del nemico, usa questi POKéMON:\p"
	.string "un PICCO DI ROCCIA di ROCCIA,\n"
	.string "un ICEBERG di tipo GHIACCIO,\l"
	.string "e un FERRO di tipo ACCIAIO.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons_hns::
	.string "Hai affrontato il PYRAMID KING\n"
	.string "quando è serio?\p"
	.string "Quando è al top della forma,\n"
	.string "pare che usi questi POKéMON:\p"
	.string "un POKéMON GELO di GHIACCIO E\n"
	.string "VOLANTE, un TUONO ELETTRICO E\l"
	.string "ELETTRICO, e un FIAMMA FUOCO\l"
	.string "VOLANTE.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1_hns::
	.string "Certo, ci sono molti posti dove\n"
	.string "si fanno LOTTE IN DOPPIA.\p"
	.string "Ma le STANZE DOPPIA della\n"
	.string "TORRE LOTTA sono basiche!\p"
	.string "Sono il posto giusto per capire\n"
	.string "come funzionano le LOTTE IN DOPPIA\l"
	.string "nella FRONTIERA LOTTA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2_hns::
	.string "Attento alle lotte di qui.\p"
	.string "Mi dicono che ci sono ALLENATORI\n"
	.string "con strategie studiate apposta per\l"
	.string "le LOTTE IN DOPPIA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3_hns::
	.string "Quando ti senti pronto con le\n"
	.string "LOTTE IN DOPPIA di qui, pensa a\l"
	.string "sfidare anche gli altri posti che\l"
	.string "offrono LOTTE IN DOPPIA.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice_hns::
	.string "Nella SALA LOTTA si radunano\n"
	.string "ALLENATORI di ogni tipo.\p"
	.string "Pensa che potresti incontrare\n"
	.string "i tuoi amici o ammiratori!\l"
	.string "Tieni gli occhi ben aperti!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice_hns::
	.string "Se sei con un amico, vai nella\n"
	.string "SALA LOTTA IN COLLEGAMENTO.\p"
	.string "Con un amico forte,\n"
	.string "troverai avversari tosti!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower_hns::
	.string "Che fiuto per le notizie!\n"
	.string "Il mio maestro è unico!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns::
	.string "Che capacità di osservazione!\n"
	.string "Il mio maestro è unico!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns::
	.string "Che potere di persuasione!\n"
	.string "Il mio maestro è unico!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns::
	.string "…Che posto è?\n"
	.string "Mi fa paura…$"

