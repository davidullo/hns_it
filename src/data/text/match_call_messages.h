#if IS_HNS
// HnS rematch trainer check page text — currently unused (check page disabled).
// Rematch slot → HnS trainer mapping kept here for reference if re-enabled.
// REMATCH_ROSE         = Joey (Youngster, Route 30)
// REMATCH_ANDRES       = Wade (Bug Catcher, Route 31)
// REMATCH_DUSTY        = Ralph (Fisherman, Route 32)
// REMATCH_LOLA         = Liz (Picnicker, Route 32)
// REMATCH_RICKY        = Anthony (Hiker, Route 33)
// REMATCH_LILA_AND_ROY = Todd (Camper, Route 34)
// REMATCH_CRISTIN      = Gina (Picnicker, Route 34)
// REMATCH_BROOKE       = Irwin (Juggler, Route 35)
// REMATCH_WILTON       = Arnie (Bug Catcher, Route 35)
// REMATCH_VALERIE      = Alan (School Kid, Route 36)
// REMATCH_CINDY        = Dana (Lass, Route 38)
// REMATCH_THALIA       = Chad (School Kid, Route 38)
// REMATCH_JESSICA      = Derek (Pokefan, Route 39)
// REMATCH_WINSTON      = Tully (Fisherman, Route 42)
// REMATCH_STEVE        = Brent (Pokemaniac, Route 43)
// REMATCH_TONY         = Tiffany (Picnicker, Route 43)
// REMATCH_NOB          = Vance (Bird Keeper, Route 44)
// REMATCH_KOJI         = Wilton (Fisherman, Route 44)
// REMATCH_FERNANDO     = Kenji (Black Belt, Route 45)
// REMATCH_DALTON       = Parry (Hiker, Route 45)
// REMATCH_BERNIE       = Erin (Picnicker, Route 46)
// REMATCH_ETHAN        = Jack (School Kid, National Park)
// REMATCH_JOHN_AND_JAY = Beverly (Parasol Lady, National Park)
// REMATCH_JEFFREY      = Huey (Sailor, Lighthouse)
// REMATCH_CAMERON      = Gaven (Cooltrainer, Route 26)
// REMATCH_JACKI        = Beth (Cooltrainer, Route 26)
// REMATCH_WALTER       = Jose (Bird Keeper, Route 27)
// REMATCH_KAREN        = Reena (Cooltrainer, Route 27)
// Crystal phone text reference: pokecrystal/data/phone/text/<name>_caller.asm
#else
const u8 gText_MatchCallAromaLady_Rose_Strategy[] = _("Calma le emozioni in lotta.");
const u8 gText_MatchCallAromaLady_Rose_Pokemon[] = _("POKéMON Erba profumati.");
const u8 gText_MatchCallAromaLady_Rose_Intro1[] = _("Profumi rilassanti rendono");
const u8 gText_MatchCallAromaLady_Rose_Intro2[] = _("corpo e mente in salute.");

const u8 gText_MatchCallRuinManiac_Andres_Strategy[] = _("Non sono molto bravo.");
const u8 gText_MatchCallRuinManiac_Andres_Pokemon[] = _("Compagni di esplorazione.");
const u8 gText_MatchCallRuinManiac_Andres_Intro1[] = _("Cerco rovine sottomarine");
const u8 gText_MatchCallRuinManiac_Andres_Intro2[] = _("e reliquie sottomarine.");

const u8 gText_MatchCallRuinManiac_Dusty_Strategy[] = _("Travolgi con la forza!");
const u8 gText_MatchCallRuinManiac_Dusty_Pokemon[] = _("ROCK POKéMON rocciosi.");
const u8 gText_MatchCallRuinManiac_Dusty_Intro1[] = _("In cerca di antiche storie,");
const u8 gText_MatchCallRuinManiac_Dusty_Intro2[] = _("Giro il mondo.");

const u8 gText_MatchCallTuber_Lola_Strategy[] = _("Ci darò dentro!");
const u8 gText_MatchCallTuber_Lola_Pokemon[] = _("POKéMON forti nel nuoto.");
const u8 gText_MatchCallTuber_Lola_Intro1[] = _("Vorrei nuotare senza");
const u8 gText_MatchCallTuber_Lola_Intro2[] = _("con un canotto.");

const u8 gText_MatchCallTuber_Ricky_Strategy[] = _("Non so. Ci proverò.");
const u8 gText_MatchCallTuber_Ricky_Pokemon[] = _("I POKéMON d'ACQUA sono amici.");
const u8 gText_MatchCallTuber_Ricky_Intro1[] = _("Non è che non sappia nuotare.");
const u8 gText_MatchCallTuber_Ricky_Intro2[] = _("Mi piace il mio ciambellone.");

const u8 gText_MatchCallSisAndBro_LilaAndRoy_Strategy[] = _("Ci dividiamo i compiti.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Pokemon[] = _("Ci piacciono i POKéMON amichevoli.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro1[] = _("Ci godiamo i POKéMON insieme");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro2[] = _("come fratello e sorella.");

const u8 gText_MatchCallCooltrainer_Cristin_Strategy[] = _("Finisco con mosse potenti!");
const u8 gText_MatchCallCooltrainer_Cristin_Pokemon[] = _("Un mix di tipi diversi.");
const u8 gText_MatchCallCooltrainer_Cristin_Intro1[] = _("Voglio diventare un'ultima");
const u8 gText_MatchCallCooltrainer_Cristin_Intro2[] = _("ALLENATORE!");

const u8 gText_MatchCallCooltrainer_Brooke_Strategy[] = _("Sfrutta le debolezze.");
const u8 gText_MatchCallCooltrainer_Brooke_Pokemon[] = _("L'equilibrio è tutto.");
const u8 gText_MatchCallCooltrainer_Brooke_Intro1[] = _("Il mio sogno è diventare");
const u8 gText_MatchCallCooltrainer_Brooke_Intro2[] = _("CAMPIONE POKéMON.");

const u8 gText_MatchCallCooltrainer_Wilton_Strategy[] = _("Spiazza l'avversario.");
const u8 gText_MatchCallCooltrainer_Wilton_Pokemon[] = _("Il tipo non conta.");
const u8 gText_MatchCallCooltrainer_Wilton_Intro1[] = _("Sono il primo della");
const u8 gText_MatchCallCooltrainer_Wilton_Intro2[] = _("SCUOLA ALLENATORI.");

const u8 gText_MatchCallHexManiac_Valerie_Strategy[] = _("Lenta, costante sofferenza.");
const u8 gText_MatchCallHexManiac_Valerie_Pokemon[] = _("Spaventosi di notte.");
const u8 gText_MatchCallHexManiac_Valerie_Intro1[] = _("Vedo cose che gli altri");
const u8 gText_MatchCallHexManiac_Valerie_Intro2[] = _("non vedono…");

const u8 gText_MatchCallLady_Cindy_Strategy[] = _("Tutto pur di vincere.");
const u8 gText_MatchCallLady_Cindy_Pokemon[] = _("Tipo stupendo!");
const u8 gText_MatchCallLady_Cindy_Intro1[] = _("Ho una piscina solo per");
const u8 gText_MatchCallLady_Cindy_Intro2[] = _("i POKéMON, a casa.");

const u8 gText_MatchCallBeauty_Thalia_Strategy[] = _("Cadrai sotto il mio incantesimo!");
const u8 gText_MatchCallBeauty_Thalia_Pokemon[] = _("Tipo ACQUA maturo.");
const u8 gText_MatchCallBeauty_Thalia_Intro1[] = _("Sogno di navigare");
const u8 gText_MatchCallBeauty_Thalia_Intro2[] = _("il mondo su un transatlantico.");

const u8 gText_MatchCallBeauty_Jessica_Strategy[] = _("Ti porterò fuori strada.");
const u8 gText_MatchCallBeauty_Jessica_Pokemon[] = _("Carini, ovviamente.");
const u8 gText_MatchCallBeauty_Jessica_Intro1[] = _("Adoro la ZONE SAFARI.");
const u8 gText_MatchCallBeauty_Jessica_Intro2[] = _("Finisco sempre lì.");

const u8 gText_MatchCallRichBoy_Winston_Strategy[] = _("Strategia? Chi la vuole?");
const u8 gText_MatchCallRichBoy_Winston_Pokemon[] = _("L'ho pagato un sacco!");
const u8 gText_MatchCallRichBoy_Winston_Intro1[] = _("Io, da ricco, dormo in un");
const u8 gText_MatchCallRichBoy_Winston_Intro2[] = _("letto su misura.");

const u8 gText_MatchCallPokeManiac_Steve_Strategy[] = _("Lotta con la forza.");
const u8 gText_MatchCallPokeManiac_Steve_Pokemon[] = _("Catturato in una notte.");
const u8 gText_MatchCallPokeManiac_Steve_Intro1[] = _("Grandi, grossi e forti");
const u8 gText_MatchCallPokeManiac_Steve_Intro2[] = _("i POKéMON sono il top…");

const u8 gText_MatchCallSwimmer_Tony_Strategy[] = _("Sperona a tutta velocità!");
const u8 gText_MatchCallSwimmer_Tony_Pokemon[] = _("Tipo ACQUA strambo!");
const u8 gText_MatchCallSwimmer_Tony_Intro1[] = _("Se non posso nuotare,");
const u8 gText_MatchCallSwimmer_Tony_Intro2[] = _("Sollevo pesi.");

const u8 gText_MatchCallBlackBelt_Nob_Strategy[] = _("Mazzate da gran finale!");
const u8 gText_MatchCallBlackBelt_Nob_Pokemon[] = _("Tipo LOTTA.");
const u8 gText_MatchCallBlackBelt_Nob_Intro1[] = _("Non per vantarmi, ma spacco");
const u8 gText_MatchCallBlackBelt_Nob_Intro2[] = _("dieci tegole!");

const u8 gText_MatchCallBlackBelt_Koji_Strategy[] = _("Ammira la potenza del karate!");
const u8 gText_MatchCallBlackBelt_Koji_Pokemon[] = _("I miei compagni di allenamento!");
const u8 gText_MatchCallBlackBelt_Koji_Intro1[] = _("Parliamo delle questioni");
const u8 gText_MatchCallBlackBelt_Koji_Intro2[] = _("del mondo a pugni nudi!");

const u8 gText_MatchCallGuitarist_Fernando_Strategy[] = _("Rock a suoni strepitosi!");
const u8 gText_MatchCallGuitarist_Fernando_Pokemon[] = _("Combo elettro-sonora!");
const u8 gText_MatchCallGuitarist_Fernando_Intro1[] = _("Le mie canzoni ti");
const u8 gText_MatchCallGuitarist_Fernando_Intro2[] = _("fulmineranno!");

const u8 gText_MatchCallGuitarist_Dalton_Strategy[] = _("Ti elettrizzerò!");
const u8 gText_MatchCallGuitarist_Dalton_Pokemon[] = _("Sono ELETTRICI!");
const u8 gText_MatchCallGuitarist_Dalton_Intro1[] = _("Voglio far piangere");
const u8 gText_MatchCallGuitarist_Dalton_Intro2[] = _("col cuore in musica.");

const u8 gText_MatchCallKindler_Bernie_Strategy[] = _("Bruciate tutto!");
const u8 gText_MatchCallKindler_Bernie_Pokemon[] = _("POKéMON che bruciano.");
const u8 gText_MatchCallKindler_Bernie_Intro1[] = _("Se accendi un falò,");
const u8 gText_MatchCallKindler_Bernie_Intro2[] = _("tieni pronta dell'acqua.");

const u8 gText_MatchCallCamper_Ethan_Strategy[] = _("Resisti e non mollare!");
const u8 gText_MatchCallCamper_Ethan_Pokemon[] = _("Alleno qualsiasi POKéMON.");
const u8 gText_MatchCallCamper_Ethan_Intro1[] = _("I POKéMON cresciuti");
const u8 gText_MatchCallCamper_Ethan_Intro2[] = _("sono forti!");

const u8 gText_MatchCallOldCouple_JohnAndJay_Strategy[] = _("Vince chi si vuol bene.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Pokemon[] = _("Li abbiamo da anni.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro1[] = _("Sposati da 50 anni, li");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro2[] = _("alleviamo con amore.");

const u8 gText_MatchCallBugManiac_Jeffrey_Strategy[] = _("Attacco a ondate!");
const u8 gText_MatchCallBugManiac_Jeffrey_Pokemon[] = _("I POKéMON Coleottero");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro1[] = _("Vado nel bosco ogni");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro2[] = _("giorno a prender Coleotteri.");

const u8 gText_MatchCallPsychic_Cameron_Strategy[] = _("Stordisci e confondi!");
const u8 gText_MatchCallPsychic_Cameron_Pokemon[] = _("Quelli coi poteri strani.");
const u8 gText_MatchCallPsychic_Cameron_Intro1[] = _("Leggo esattamente");
const u8 gText_MatchCallPsychic_Cameron_Intro2[] = _("cosa stai pensando!");

const u8 gText_MatchCallPsychic_Jacki_Strategy[] = _("Lotto a piena forza.");
const u8 gText_MatchCallPsychic_Jacki_Pokemon[] = _("POKéMON pieni di misteri.");
const u8 gText_MatchCallPsychic_Jacki_Intro1[] = _("Quando parlavamo, usavo");
const u8 gText_MatchCallPsychic_Jacki_Intro2[] = _("davvero la telepatia.");

const u8 gText_MatchCallGentleman_Walter_Strategy[] = _("Calmo e posato.");
const u8 gText_MatchCallGentleman_Walter_Pokemon[] = _("POKéMON raffinati.");
const u8 gText_MatchCallGentleman_Walter_Intro1[] = _("Ci gusta un tè");
const u8 gText_MatchCallGentleman_Walter_Intro2[] = _("ogni giorno. È importato.");

const u8 gText_MatchCallSchoolKid_Karen_Strategy[] = _("Uso la testa in lotta.");
const u8 gText_MatchCallSchoolKid_Karen_Pokemon[] = _("Amo ogni tipo di POKéMON!");
const u8 gText_MatchCallSchoolKid_Karen_Intro1[] = _("Papà mi dà i soldi");
const u8 gText_MatchCallSchoolKid_Karen_Intro2[] = _("se prendo bei voti.");

const u8 gText_MatchCallSchoolKid_Jerry_Strategy[] = _("La Sapienza vince!");
const u8 gText_MatchCallSchoolKid_Jerry_Pokemon[] = _("Ogni POKéMON intelligente!");
const u8 gText_MatchCallSchoolKid_Jerry_Intro1[] = _("Da grande voglio essere");
const u8 gText_MatchCallSchoolKid_Jerry_Intro2[] = _("un ricercatore POKéMON.");

const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Strategy[] = _("Prima ne parliamo.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Pokemon[] = _("POKéMON che piacciono a entrambe.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro1[] = _("Siamo maestra e allieva");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro2[] = _("studenti nei POKéMON!");

const u8 gText_MatchCallPokefan_Isabel_Strategy[] = _("Forza, tesori!");
const u8 gText_MatchCallPokefan_Isabel_Pokemon[] = _("Non ho preferenze.");
const u8 gText_MatchCallPokefan_Isabel_Intro1[] = _("Mentre faccio la spesa");
const u8 gText_MatchCallPokefan_Isabel_Intro2[] = _("per cena, lotto anche.");

const u8 gText_MatchCallPokefan_Miguel_Strategy[] = _("Lotto con amore!");
const u8 gText_MatchCallPokefan_Miguel_Pokemon[] = _("Un POKéMON cresciuto con amore!");
const u8 gText_MatchCallPokefan_Miguel_Intro1[] = _("È importante creare");
const u8 gText_MatchCallPokefan_Miguel_Intro2[] = _("fiducia col tuo POKéMON.");

const u8 gText_MatchCallExpert_Timothy_Strategy[] = _("Leggo le tue mosse!");
const u8 gText_MatchCallExpert_Timothy_Pokemon[] = _("L'essenza della LOTTA.");
const u8 gText_MatchCallExpert_Timothy_Intro1[] = _("Non cedo il posto");
const u8 gText_MatchCallExpert_Timothy_Intro2[] = _("ai giovani, non ancora!");

const u8 gText_MatchCallExpert_Shelby_Strategy[] = _("Attacco difendendomi.");
const u8 gText_MatchCallExpert_Shelby_Pokemon[] = _("Il tipo LOTTA.");
const u8 gText_MatchCallExpert_Shelby_Intro1[] = _("Da vecchia, ho il mio");
const u8 gText_MatchCallExpert_Shelby_Intro2[] = _("stile di lotta.");

const u8 gText_MatchCallYoungster_Calvin_Strategy[] = _("Faccio quel che posso.");
const u8 gText_MatchCallYoungster_Calvin_Pokemon[] = _("Uso tipi diversi.");
const u8 gText_MatchCallYoungster_Calvin_Intro1[] = _("Continuerò ad allenarmi");
const u8 gText_MatchCallYoungster_Calvin_Intro2[] = _("finché non batto un CAPOPALESTRA.");

const u8 gText_MatchCallFisherman_Elliot_Strategy[] = _("Lotto con pazienza.");
const u8 gText_MatchCallFisherman_Elliot_Pokemon[] = _("POKéMON ACQUA per lottare!");
const u8 gText_MatchCallFisherman_Elliot_Intro1[] = _("Sono l'unico al mondo a");
const u8 gText_MatchCallFisherman_Elliot_Intro2[] = _("catturare POKéMON enormi!");

const u8 gText_MatchCallTriathlete_Isaiah_Strategy[] = _("Sfrutta l'ambiente!");
const u8 gText_MatchCallTriathlete_Isaiah_Pokemon[] = _("Viva il tipo ACQUA!");
const u8 gText_MatchCallTriathlete_Isaiah_Intro1[] = _("Non mi batte certo un");
const u8 gText_MatchCallTriathlete_Isaiah_Intro2[] = _("NUOTATORE sfaticato!");

const u8 gText_MatchCallTriathlete_Maria_Strategy[] = _("La Velocità prima di tutto!");
const u8 gText_MatchCallTriathlete_Maria_Pokemon[] = _("Uso un POKéMON veloce.");
const u8 gText_MatchCallTriathlete_Maria_Intro1[] = _("La maratona è una sfida");
const u8 gText_MatchCallTriathlete_Maria_Intro2[] = _("contro te stesso.");

const u8 gText_MatchCallTriathlete_Abigail_Strategy[] = _("La Difesa è cruciale.");
const u8 gText_MatchCallTriathlete_Abigail_Pokemon[] = _("Il mio POKéMON è solido.");
const u8 gText_MatchCallTriathlete_Abigail_Intro1[] = _("Ho iniziato per la dieta,");
const u8 gText_MatchCallTriathlete_Abigail_Intro2[] = _("ma poi mi è piaciuto.");

const u8 gText_MatchCallTriathlete_Dylan_Strategy[] = _("Colpisci per primo!");
const u8 gText_MatchCallTriathlete_Dylan_Pokemon[] = _("Un POKéMON velocissimo!");
const u8 gText_MatchCallTriathlete_Dylan_Intro1[] = _("Correndo e correndo,");
const u8 gText_MatchCallTriathlete_Dylan_Intro2[] = _("diventi tutt'uno col vento.");

const u8 gText_MatchCallTriathlete_Katelyn_Strategy[] = _("Attacco totale!");
const u8 gText_MatchCallTriathlete_Katelyn_Pokemon[] = _("I POKéMON d'ACQUA dominano!");
const u8 gText_MatchCallTriathlete_Katelyn_Intro1[] = _("Devo nuotare 10 km");
const u8 gText_MatchCallTriathlete_Katelyn_Intro2[] = _("ogni giorno.");

const u8 gText_MatchCallTriathlete_Benjamin_Strategy[] = _("Spingi e rispingi!");
const u8 gText_MatchCallTriathlete_Benjamin_Pokemon[] = _("La forza dell'ACCIAIO.");
const u8 gText_MatchCallTriathlete_Benjamin_Intro1[] = _("Se stai sudando,");
const u8 gText_MatchCallTriathlete_Benjamin_Intro2[] = _("bevi liquidi regolarmente.");

const u8 gText_MatchCallTriathlete_Pablo_Strategy[] = _("Attingi la forza dell'ACQUA.");
const u8 gText_MatchCallTriathlete_Pablo_Pokemon[] = _("POKéMON d'ACQUA temprati.");
const u8 gText_MatchCallTriathlete_Pablo_Intro1[] = _("Allenare POKéMON va bene,");
const u8 gText_MatchCallTriathlete_Pablo_Intro2[] = _("ma non trascurarti.");

const u8 gText_MatchCallDragonTamer_Nicolas_Strategy[] = _("Conta la forza dei POKéMON!");
const u8 gText_MatchCallDragonTamer_Nicolas_Pokemon[] = _("Guarda la forza dei DRAGHI!");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro1[] = _("Diventerò una Leggenda come il");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro2[] = _("più forte, un giorno!");

const u8 gText_MatchCallBirdKeeper_Robert_Strategy[] = _("Ti mostro la mia tecnica!");
const u8 gText_MatchCallBirdKeeper_Robert_Pokemon[] = _("Uccelli che volano eleganti.");
const u8 gText_MatchCallBirdKeeper_Robert_Intro1[] = _("Miei POKéMON Uccello, portate");
const u8 gText_MatchCallBirdKeeper_Robert_Intro2[] = _("il mio amore a quella ragazza!");

const u8 gText_MatchCallNinjaBoy_Lao_Strategy[] = _("Soffrirai per il veleno!");
const u8 gText_MatchCallNinjaBoy_Lao_Pokemon[] = _("POKéMON velenosi.");
const u8 gText_MatchCallNinjaBoy_Lao_Intro1[] = _("Mi alleno ogni giorno");
const u8 gText_MatchCallNinjaBoy_Lao_Intro2[] = _("per diventare un ninja.");

const u8 gText_MatchCallBattleGirl_Cyndy_Strategy[] = _("Chi colpisce per primo vince!");
const u8 gText_MatchCallBattleGirl_Cyndy_Pokemon[] = _("Tipo LOTTA veloce.");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro1[] = _("Se i miei POKéMON perdono,");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro2[] = _("io continuo a lottare!");

const u8 gText_MatchCallParasolLady_Madeline_Strategy[] = _("Forza, miei POKéMON!");
const u8 gText_MatchCallParasolLady_Madeline_Pokemon[] = _("Allevo di tutto.");
const u8 gText_MatchCallParasolLady_Madeline_Intro1[] = _("I raggi UV rovinano la pelle.");
const u8 gText_MatchCallParasolLady_Madeline_Intro2[] = _("della pelle. Proteggiti.");

const u8 gText_MatchCallSwimmer_Jenny_Strategy[] = _("Nessuna pietà!");
const u8 gText_MatchCallSwimmer_Jenny_Pokemon[] = _("POKéMON ACQUA carini.");
const u8 gText_MatchCallSwimmer_Jenny_Intro1[] = _("Ho troppi fan.");
const u8 gText_MatchCallSwimmer_Jenny_Intro2[] = _("Mi hanno intervistata in TV.");

const u8 gText_MatchCallPicnicker_Diana_Strategy[] = _("Penso a questo e a quello.");
const u8 gText_MatchCallPicnicker_Diana_Pokemon[] = _("Mi piacciono tutti i POKéMON.");
const u8 gText_MatchCallPicnicker_Diana_Intro1[] = _("Cosa c'è oltre quella");
const u8 gText_MatchCallPicnicker_Diana_Intro2[] = _("collina laggiù?");

const u8 gText_MatchCallTwins_AmyAndLiv_Strategy[] = _("Lottiamo insieme!");
const u8 gText_MatchCallTwins_AmyAndLiv_Pokemon[] = _("Ci alleniamo insieme!");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro1[] = _("Ci piacciono gli stessi POKéMON,");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro2[] = _("ma dolci diversi.");

const u8 gText_MatchCallSailor_Ernest_Strategy[] = _("Uso la forza bruta!");
const u8 gText_MatchCallSailor_Ernest_Pokemon[] = _("Tipi ACQUA e LOTTA.");
const u8 gText_MatchCallSailor_Ernest_Intro1[] = _("I marinai son rudi!");
const u8 gText_MatchCallSailor_Ernest_Intro2[] = _("Qualche lamentela?");

const u8 gText_MatchCallSailor_Cory_Strategy[] = _("Sempre pronto a lottare!");
const u8 gText_MatchCallSailor_Cory_Pokemon[] = _("I POKéMON ACQUA sono i miei preferiti!");
const u8 gText_MatchCallSailor_Cory_Intro1[] = _("Se vuoi gridare forte,");
const u8 gText_MatchCallSailor_Cory_Intro2[] = _("gonfia la pancia d'aria!");

const u8 gText_MatchCallCollector_Edwin_Strategy[] = _("Proteggo i POKéMON dai pericoli.");
const u8 gText_MatchCallCollector_Edwin_Pokemon[] = _("Adoro i POKéMON rari.");
const u8 gText_MatchCallCollector_Edwin_Intro1[] = _("Voglio collezionare tutti i");
const u8 gText_MatchCallCollector_Edwin_Intro2[] = _("POKéMON rari del mondo.");

const u8 gText_MatchCallPkmnBreeder_Lydia_Strategy[] = _("Conto sulla potenza.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Pokemon[] = _("I POKéMON sono i miei figli.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro1[] = _("Servono Sapienza e");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro2[] = _("amore per allevare POKéMON.");

const u8 gText_MatchCallPkmnBreeder_Isaac_Strategy[] = _("Attacco a tutto campo!");
const u8 gText_MatchCallPkmnBreeder_Isaac_Pokemon[] = _("Qualsiasi. Lo alleno io.");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro1[] = _("Do {POKEBLOCK}S ai miei per");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro2[] = _("vincere le GARE.");

const u8 gText_MatchCallPkmnBreeder_Gabrielle_Strategy[] = _("Allevo POKéMON con cura.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Pokemon[] = _("POKéMON da allevare.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro1[] = _("Tratta ogni POKéMON che");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro2[] = _("incontri con rispetto.");

const u8 gText_MatchCallPkmnRanger_Catherine_Strategy[] = _("Credo nei miei POKéMON.");
const u8 gText_MatchCallPkmnRanger_Catherine_Pokemon[] = _("Mi piacciono i POKéMON forti.");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro1[] = _("Mi alleno per il soccorso");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro2[] = _("insieme ai POKéMON.");

const u8 gText_MatchCallPkmnRanger_Jackson_Strategy[] = _("Attacco a ondate!");
const u8 gText_MatchCallPkmnRanger_Jackson_Pokemon[] = _("Uso tipi diversi.");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro1[] = _("Chi distrugge la natura");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro2[] = _("non va mai perdonato!");

const u8 gText_MatchCallLass_Haley_Strategy[] = _("Ti mostro che fegato ho!");
const u8 gText_MatchCallLass_Haley_Pokemon[] = _("Adoro i POKéMON carini!");
const u8 gText_MatchCallLass_Haley_Intro1[] = _("Dopo la lotta, mi lavo");
const u8 gText_MatchCallLass_Haley_Intro2[] = _("sempre con i POKéMON.");

const u8 gText_MatchCallBugCatcher_James_Strategy[] = _("Attacco fulmineo!");
const u8 gText_MatchCallBugCatcher_James_Pokemon[] = _("I POKéMON COLEOTTERO son i migliori!");
const u8 gText_MatchCallBugCatcher_James_Intro1[] = _("Per catturare POKéMON");
const u8 gText_MatchCallBugCatcher_James_Intro2[] = _("COLEOTTERO, alzati presto.");

const u8 gText_MatchCallHiker_Trent_Strategy[] = _("Lotto con la forza.");
const u8 gText_MatchCallHiker_Trent_Pokemon[] = _("POKéMON duri.");
const u8 gText_MatchCallHiker_Trent_Intro1[] = _("Programmo da un mese");
const u8 gText_MatchCallHiker_Trent_Intro2[] = _("l'escursione di oggi.");

const u8 gText_MatchCallHiker_Sawyer_Strategy[] = _("Mi piace il caldo!");
const u8 gText_MatchCallHiker_Sawyer_Pokemon[] = _("POKéMON caldi!");
const u8 gText_MatchCallHiker_Sawyer_Intro1[] = _("Amo i POKéMON, ma");
const u8 gText_MatchCallHiker_Sawyer_Intro2[] = _("adoro fare escursioni!");

const u8 gText_MatchCallYoungCouple_LoisAndHal_Strategy[] = _("Strategia da innamorati!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Pokemon[] = _("POKéMON da innamorati!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro1[] = _("Siamo innamorati!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro2[] = _("Innamorati per sempre!");

const u8 gText_MatchCallPkmnTrainer_Wally_Strategy[] = _("Diamo il massimo.");
const u8 gText_MatchCallPkmnTrainer_Wally_Pokemon[] = _("Il 1º POKéMON che presi.");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro1[] = _("Io e i POKéMON siamo");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro2[] = _("cresciuti insieme.");

const u8 gText_MatchCallRockinWhiz_Roxanne_Strategy[] = _("Attacco di tipo ROCIA.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Pokemon[] = _("Preferisco POKéMON duri.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro1[] = _("Un CAPO di una grande");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro2[] = _("PALESTRA ha responsabilità.");

const u8 gText_MatchCallTheBigHit_Brawly_Strategy[] = _("Azione fisica diretta!");
const u8 gText_MatchCallTheBigHit_Brawly_Pokemon[] = _("I POKéMON LOTTA spaccano!");
const u8 gText_MatchCallTheBigHit_Brawly_Intro1[] = _("Il mondo mi attende come");
const u8 gText_MatchCallTheBigHit_Brawly_Intro2[] = _("la prossima grande onda!");

const u8 gText_MatchCallSwellShock_Wattson_Strategy[] = _("Scelgo l'elettrocontagio.");
const u8 gText_MatchCallSwellShock_Wattson_Pokemon[] = _("Prendi la scossa elettrica!");
const u8 gText_MatchCallSwellShock_Wattson_Intro1[] = _("Non si deve mai perdere");
const u8 gText_MatchCallSwellShock_Wattson_Intro2[] = _("un incontro. Nemmeno io.");

const u8 gText_MatchCallPassionBurn_Flannery_Strategy[] = _("Lotta con aggressività.");
const u8 gText_MatchCallPassionBurn_Flannery_Pokemon[] = _("Brucia di passione!");
const u8 gText_MatchCallPassionBurn_Flannery_Intro1[] = _("Lava via la stanchezza");
const u8 gText_MatchCallPassionBurn_Flannery_Intro2[] = _("quotidiana alle terme!");

const u8 gText_MatchCallReliableOne_Dad_Strategy[] = _("Adatto lo stile ai nemici.");
const u8 gText_MatchCallReliableOne_Dad_Pokemon[] = _("Cresciuto in modo equilibrato.");
const u8 gText_MatchCallReliableOne_Dad_Intro1[] = _("Cammino 30 minuti da casa");
const u8 gText_MatchCallReliableOne_Dad_Intro2[] = _("fino a qui ogni giorno.");

const u8 gText_MatchCallSkyTamer_Winona_Strategy[] = _("Sfrutto la Velocità.");
const u8 gText_MatchCallSkyTamer_Winona_Pokemon[] = _("Danzatori del cielo.");
const u8 gText_MatchCallSkyTamer_Winona_Intro1[] = _("Il massimo sarebbe vivere");
const u8 gText_MatchCallSkyTamer_Winona_Intro2[] = _("in armonia con la natura.");

const u8 gText_MatchCallMysticDuo_TateAndLiza_Strategy[] = _("Lottiamo in cooperazione.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Pokemon[] = _("POKéMON sempre amici.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro1[] = _("Papà fa fatica a dire");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro2[] = _("noi due divisi!");

const u8 gText_MatchCallDandyCharm_Juan_Strategy[] = _("Uso lo splendido potere dell'acqua.");
const u8 gText_MatchCallDandyCharm_Juan_Pokemon[] = _("POKéMON di eleganza!");
const u8 gText_MatchCallDandyCharm_Juan_Intro1[] = _("L'omaggio di splendide");
const u8 gText_MatchCallDandyCharm_Juan_Intro2[] = _("dame mi riempie di energia!");

const u8 gText_MatchCallEliteFour_Sidney_Strategy[] = _("Offesa prima di difesa!");
const u8 gText_MatchCallEliteFour_Sidney_Pokemon[] = _("Le bellezze del lato BUIO.");
const u8 gText_MatchCallEliteFour_Sidney_Intro1[] = _("Mi dicevano punk, ma");
const u8 gText_MatchCallEliteFour_Sidney_Intro2[] = _("sono dei SUPERQUATTRO!");

const u8 gText_MatchCallEliteFour_Phoebe_Strategy[] = _("Confondi e sconcerta.");
const u8 gText_MatchCallEliteFour_Phoebe_Pokemon[] = _("Non c'è nulla di certo.");
const u8 gText_MatchCallEliteFour_Phoebe_Intro1[] = _("Chissà come se la cava");
const u8 gText_MatchCallEliteFour_Phoebe_Intro2[] = _("la nonna al MT. PIRO?");

const u8 gText_MatchCallEliteFour_Glacia_Strategy[] = _("Uso strumenti d'aiuto.");
const u8 gText_MatchCallEliteFour_Glacia_Pokemon[] = _("Passione ardente nel gelo!");
const u8 gText_MatchCallEliteFour_Glacia_Intro1[] = _("Il tipo GHIACCIO si allena");
const u8 gText_MatchCallEliteFour_Glacia_Intro2[] = _("meglio in questa terra calda.");

const u8 gText_MatchCallEliteFour_Drake_Strategy[] = _("Sfrutta abilità potenti.");
const u8 gText_MatchCallEliteFour_Drake_Pokemon[] = _("La forza pura dei DRAGHI!");
const u8 gText_MatchCallEliteFour_Drake_Intro1[] = _("Mi dedico ai draghi");
const u8 gText_MatchCallEliteFour_Drake_Intro2[] = _("POKéMON che mi salvarono.");

const u8 gText_MatchCallChampion_Wallace_Strategy[] = _("Dignità e rispetto.");
const u8 gText_MatchCallChampion_Wallace_Pokemon[] = _("Preferisco POKéMON aggraziati.");
const u8 gText_MatchCallChampion_Wallace_Intro1[] = _("Rappresento la bellezza e");
const u8 gText_MatchCallChampion_Wallace_Intro2[] = _("anche l'intelligenza.");
#endif

#if IS_HNS
// Check page disabled for HnS trainers — table left empty.
// To re-enable: add MCFLAVOR entries here and set HasCheckPage_Trainer to TRUE.
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] = {0};
#else
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] =
{
    [REMATCH_ROSE] = MCFLAVOR(AromaLady_Rose),
    [REMATCH_ANDRES] = MCFLAVOR(RuinManiac_Andres),
    [REMATCH_DUSTY] = MCFLAVOR(RuinManiac_Dusty),
    [REMATCH_LOLA] = MCFLAVOR(Tuber_Lola),
    [REMATCH_RICKY] = MCFLAVOR(Tuber_Ricky),
    [REMATCH_LILA_AND_ROY] = MCFLAVOR(SisAndBro_LilaAndRoy),
    [REMATCH_CRISTIN] = MCFLAVOR(Cooltrainer_Cristin),
    [REMATCH_BROOKE] = MCFLAVOR(Cooltrainer_Brooke),
    [REMATCH_WILTON] = MCFLAVOR(Cooltrainer_Wilton),
    [REMATCH_VALERIE] = MCFLAVOR(HexManiac_Valerie),
    [REMATCH_CINDY] = MCFLAVOR(Lady_Cindy),
    [REMATCH_THALIA] = MCFLAVOR(Beauty_Thalia),
    [REMATCH_JESSICA] = MCFLAVOR(Beauty_Jessica),
    [REMATCH_WINSTON] = MCFLAVOR(RichBoy_Winston),
    [REMATCH_STEVE] = MCFLAVOR(PokeManiac_Steve),
    [REMATCH_TONY] = MCFLAVOR(Swimmer_Tony),
    [REMATCH_NOB] = MCFLAVOR(BlackBelt_Nob),
    [REMATCH_KOJI] = MCFLAVOR(BlackBelt_Koji),
    [REMATCH_FERNANDO] = MCFLAVOR(Guitarist_Fernando),
    [REMATCH_DALTON] = MCFLAVOR(Guitarist_Dalton),
    [REMATCH_BERNIE] = MCFLAVOR(Kindler_Bernie),
    [REMATCH_ETHAN] = MCFLAVOR(Camper_Ethan),
    [REMATCH_JOHN_AND_JAY] = MCFLAVOR(OldCouple_JohnAndJay),
    [REMATCH_JEFFREY] = MCFLAVOR(BugManiac_Jeffrey),
    [REMATCH_CAMERON] = MCFLAVOR(Psychic_Cameron),
    [REMATCH_JACKI] = MCFLAVOR(Psychic_Jacki),
    [REMATCH_WALTER] = MCFLAVOR(Gentleman_Walter),
    [REMATCH_KAREN] = MCFLAVOR(SchoolKid_Karen),
    [REMATCH_JERRY] = MCFLAVOR(SchoolKid_Jerry),
    [REMATCH_ANNA_AND_MEG] = MCFLAVOR(SrAndJr_AnnaAndMeg),
    [REMATCH_ISABEL] = MCFLAVOR(Pokefan_Isabel),
    [REMATCH_MIGUEL] = MCFLAVOR(Pokefan_Miguel),
    [REMATCH_TIMOTHY] = MCFLAVOR(Expert_Timothy),
    [REMATCH_SHELBY] = MCFLAVOR(Expert_Shelby),
    [REMATCH_CALVIN] = MCFLAVOR(Youngster_Calvin),
    [REMATCH_ELLIOT] = MCFLAVOR(Fisherman_Elliot),
    [REMATCH_ISAIAH] = MCFLAVOR(Triathlete_Isaiah),
    [REMATCH_MARIA] = MCFLAVOR(Triathlete_Maria),
    [REMATCH_ABIGAIL] = MCFLAVOR(Triathlete_Abigail),
    [REMATCH_DYLAN] = MCFLAVOR(Triathlete_Dylan),
    [REMATCH_KATELYN] = MCFLAVOR(Triathlete_Katelyn),
    [REMATCH_BENJAMIN] = MCFLAVOR(Triathlete_Benjamin),
    [REMATCH_PABLO] = MCFLAVOR(Triathlete_Pablo),
    [REMATCH_NICOLAS] = MCFLAVOR(DragonTamer_Nicolas),
    [REMATCH_ROBERT] = MCFLAVOR(BirdKeeper_Robert),
    [REMATCH_LAO] = MCFLAVOR(NinjaBoy_Lao),
    [REMATCH_CYNDY] = MCFLAVOR(BattleGirl_Cyndy),
    [REMATCH_MADELINE] = MCFLAVOR(ParasolLady_Madeline),
    [REMATCH_JENNY] = MCFLAVOR(Swimmer_Jenny),
    [REMATCH_DIANA] = MCFLAVOR(Picnicker_Diana),
    [REMATCH_AMY_AND_LIV] = MCFLAVOR(Twins_AmyAndLiv),
    [REMATCH_ERNEST] = MCFLAVOR(Sailor_Ernest),
    [REMATCH_CORY] = MCFLAVOR(Sailor_Cory),
    [REMATCH_EDWIN] = MCFLAVOR(Collector_Edwin),
    [REMATCH_LYDIA] = MCFLAVOR(PkmnBreeder_Lydia),
    [REMATCH_ISAAC] = MCFLAVOR(PkmnBreeder_Isaac),
    [REMATCH_GABRIELLE] = MCFLAVOR(PkmnBreeder_Gabrielle),
    [REMATCH_CATHERINE] = MCFLAVOR(PkmnRanger_Catherine),
    [REMATCH_JACKSON] = MCFLAVOR(PkmnRanger_Jackson),
    [REMATCH_HALEY] = MCFLAVOR(Lass_Haley),
    [REMATCH_JAMES] = MCFLAVOR(BugCatcher_James),
    [REMATCH_TRENT] = MCFLAVOR(Hiker_Trent),
    [REMATCH_SAWYER] = MCFLAVOR(Hiker_Sawyer),
    [REMATCH_KIRA_AND_DAN] = MCFLAVOR(YoungCouple_LoisAndHal),
    [REMATCH_WALLY_VR] = MCFLAVOR(PkmnTrainer_Wally),
    [REMATCH_ROXANNE] = MCFLAVOR(RockinWhiz_Roxanne),
    [REMATCH_BRAWLY] = MCFLAVOR(TheBigHit_Brawly),
    [REMATCH_WATTSON] = MCFLAVOR(SwellShock_Wattson),
    [REMATCH_FLANNERY] = MCFLAVOR(PassionBurn_Flannery),
    [REMATCH_NORMAN] = MCFLAVOR(ReliableOne_Dad),
    [REMATCH_WINONA] = MCFLAVOR(SkyTamer_Winona),
    [REMATCH_TATE_AND_LIZA] = MCFLAVOR(MysticDuo_TateAndLiza),
    [REMATCH_JUAN] = MCFLAVOR(DandyCharm_Juan),
    [REMATCH_SIDNEY] = MCFLAVOR(EliteFour_Sidney),
    [REMATCH_PHOEBE] = MCFLAVOR(EliteFour_Phoebe),
    [REMATCH_GLACIA] = MCFLAVOR(EliteFour_Glacia),
    [REMATCH_DRAKE] = MCFLAVOR(EliteFour_Drake),
    [REMATCH_WALLACE] = MCFLAVOR(Champion_Wallace),
};
#endif
