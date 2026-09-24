// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("POKéMON Talk di OAK");
static const u8 sRadioStationName_PokedexShow[]     = _("POKéDEX Show");
static const u8 sRadioStationName_PokemonMusic[]    = _("Musica POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("Canale Fortuna");
static const u8 sRadioStationName_BuenasPassword[]  = _("PASSWORD DI BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("Genti e luoghi");
static const u8 sRadioStationName_LetsAllSing[]     = _("Cantiamo tutti!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLAUTO");

static const u8 sRadioStationName_HoennSound[]  = _("Suono di Hoenn");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("Una melodia POKéMON da");
static const u8 sRadioText_Hoenn2[] = _("una regione lontana, HOENN!");
static const u8 sRadioText_Hoenn3[] = _("POKéMON selvatici di quella");
static const u8 sRadioText_Hoenn4[] = _("potrebbero apparire qui!");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("Il POKéDEX SHOW di OAK!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: Oggi il POKéMON è ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY: POKéMON TALK del PROF. OAK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("Con me, MARY!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("si vedono in giro");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ");
static const u8 sRadioText_OPT_MaryIs[] = _("'s ");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("Canale POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("dolce e adorabile");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("sinuoso e liscio");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("nome azzeccato e");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("indiscutibilmente un po'");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("così, così insopportabile");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("wow, in modo impressionante");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("quasi velenosamente");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("ooh, che sensualità");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("che birichino");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("molto d'attualità");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("davvero avvincente");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("guarda nell'acqua ed è");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("l'Evoluzione dev'essere");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocante");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("così scioccante e");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("da sciogliere il cuore");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("carino.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("strano.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("piacevole.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("Sicura, più o meno.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("spaventoso.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("affascinante e raffinato!");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("potente.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("emozionante.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("groovy!");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("ispirante.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("amichevole.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("caldo, caldo, caldo!");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("stimolante.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("guardingo.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("adorabile.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("veloce.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN: MUSICA POKéMON!");
static const u8 sRadioText_BenIntro2[] = _("Sono io, DJ BEN!");
static const u8 sRadioText_FernIntro[] = _("FERN: POKéMUSIC!");
static const u8 sRadioText_FernIntro2[] = _("Con DJ FERN!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Oggi è ");
static const u8 sRadioText_BenFern_JamTo[] = _("quindi suoniamo");
static const u8 sRadioText_BenFern_ChillTo[] = _("quindi rilassati");
static const u8 sRadioText_BenFern_March[] = _("Marcia POKéMON!");
static const u8 sRadioText_BenFern_Lullaby[] = _("Ninna nanna!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("ORLANDO: Yahoo! Come butta");
static const u8 sRadioText_LC2[] = _("oggi? Che siate su o giù");
static const u8 sRadioText_LC3[] = _("di morale, non perdete");
static const u8 sRadioText_LC4[] = _("IL NUMERO FORTUNATO!");
static const u8 sRadioText_LC5[] = _("Il Numero Fortunato è");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("Lo ripeto!");
static const u8 sRadioText_LC_Match[] = _("Indovinalo e vai");
static const u8 sRadioText_LC_Tower[] = _("alla TORRE RADIO!");
static const u8 sRadioText_LC_Drag1[] = _("…Ripetermi");
static const u8 sRadioText_LC_Drag2[] = _("è una noia…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("GENTI E LUOGHI! Offerto");
static const u8 sRadioText_PnP_Intro2[] = _("a voi da me, DJ LILY!");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("è carino.");
static const u8 sRadioText_PnP_Lazy[]       = _("è un po' pigro.");
static const u8 sRadioText_PnP_Happy[]      = _("è sempre felice.");
static const u8 sRadioText_PnP_Noisy[]      = _("è assai rumoroso.");
static const u8 sRadioText_PnP_Precocious[] = _("è precoce.");
static const u8 sRadioText_PnP_Bold[]       = _("è un po' audace.");
static const u8 sRadioText_PnP_Picky[]      = _("è troppo esigente!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("è passabile.");
static const u8 sRadioText_PnP_SoSo[]       = _("è così così.");
static const u8 sRadioText_PnP_Great[]       = _("è davvero forte.");
static const u8 sRadioText_PnP_MyType[]      = _("è proprio il mio tipo.");
static const u8 sRadioText_PnP_Cool[]        = _("è troppo forte, no?");
static const u8 sRadioText_PnP_Inspiring[]   = _("è ispirante!");
static const u8 sRadioText_PnP_Weird[]       = _("è un po' strano.");
static const u8 sRadioText_PnP_RightForMe[]  = _("fa per me?");
static const u8 sRadioText_PnP_Odd[]         = _("è proprio strano!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("… …Ehm, siamo");
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("Dopo tre anni");
static const u8 sRadioText_Rocket4[]  = _("di preparativi, ci");
static const u8 sRadioText_Rocket5[]  = _("siamo rialzati");
static const u8 sRadioText_Rocket6[]  = _("dalle ceneri!");
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI!");
static const u8 sRadioText_Rocket8[]  = _("Mi sentite?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: Sono BUENA!");
static const u8 sRadioText_Buena2[] = _("La password di oggi!");
static const u8 sRadioText_Buena3[] = _("Vediamo… È");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("Non scordarla! Sono alla");
static const u8 sRadioText_Buena6[] = _("TORRE RADIO di FIORDOROPOLI!");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("FIORNETO");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CILIANWOOD");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("AZALINA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOLANTE");
static const u8 sRadioBuenaPassword_Bug[]             = _("COLEOTTERO");
static const u8 sRadioBuenaPassword_Grass[]           = _("ERBA");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("POKéMON Talk");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("Musica POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Canale Fortuna");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("MARY: Stanotte, un raro");
static const u8 sOPT_Report_Clefairy_1[]  = _("chiaro di luna a POKéMON");
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: Oggi parliamo dei");
static const u8 sOPT_Report_Clefairy_3[]  = _("mistici CLEFAIRY!");
static const u8 sOPT_Report_Clefairy_4[]  = _("Si radunano al MONTE LUNA");
static const u8 sOPT_Report_Clefairy_5[]  = _("con la luna piena.");
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY: Danzano in cerchio!");
static const u8 sOPT_Report_Clefairy_7[]  = _("Che strano adorabili!");
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: Un mistero eterno");
static const u8 sOPT_Report_Clefairy_9[]  = _("e uno spettacolo!");

static const u8 sOPT_Report_Lapras_0[]  = _("MARY: Un gigante gentile");
static const u8 sOPT_Report_Lapras_1[]  = _("oggi è con noi!");
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: È il traghetto del");
static const u8 sOPT_Report_Lapras_3[]  = _("mare, il nostro LAPRAS!");
static const u8 sOPT_Report_Lapras_4[]  = _("Visto alla GROTTA DI MEZZO,");
static const u8 sOPT_Report_Lapras_5[]  = _("da nessun'altra parte.");
static const u8 sOPT_Report_Lapras_6[]  = _("MARY: Che pace rara!");
static const u8 sOPT_Report_Lapras_7[]  = _("E anche canta!");
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Si dice che i suoi");
static const u8 sOPT_Report_Lapras_9[]  = _("canti calmino il mare.");

static const u8 sOPT_Report_Ampharos_0[]  = _("MARY: Bentornati a tutti!");
static const u8 sOPT_Report_Ampharos_1[]  = _("È l'ora di POKéMON TALK!");
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: Facciamo luce su");
static const u8 sOPT_Report_Ampharos_3[]  = _("AMPHAROS, nostro amico!");
static const u8 sOPT_Report_Ampharos_4[]  = _("La coda brillante guida");
static const u8 sOPT_Report_Ampharos_5[]  = _("i dispersi nella nebbia.");
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY: Forte, elegante");
static const u8 sOPT_Report_Ampharos_7[]  = _("e molto amichevole!");
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: Protagonista di");
static const u8 sOPT_Report_Ampharos_9[]  = _("molte storie di fari!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY: Ora un tipo strano");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("sulla PERCORSO 36...");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: SUDOWOODO! Sembra un");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("albero, ma non lo è!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Blocca la strada e non si");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("muove senza acqua.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY: Reagisce solo a una");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("ANNAFFIATOIO!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: Non è un cespuglio,");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("è un tipo ROCClA mascherato!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY: La storia di oggi è");
static const u8 sOPT_Report_RedGyarados_1[]  = _("scioccante da JOHTO!");
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: Avvistato un GYARADOS");
static const u8 sOPT_Report_RedGyarados_3[]  = _("avvistato un GYARADOS al LAGO");
static const u8 sOPT_Report_RedGyarados_4[]  = _("A differenza dei soliti blu,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("questo è cremisi brillante!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY: Si dice sia legato a");
static const u8 sOPT_Report_RedGyarados_7[]  = _("strane onde radio!");
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: Una misteriosa evoluzione…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Forse innaturale.");

static const u8 sOPT_Report_Unown_0[]  = _("MARY: Mai visitato le ROVINE");
static const u8 sOPT_Report_Unown_1[]  = _("DI ALPH? Che brividi!");
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Strani simboli coprono le");
static const u8 sOPT_Report_Unown_3[]  = _("pareti, come rune antiche.");
static const u8 sOPT_Report_Unown_4[]  = _("Dentro troverai UNOWN…");
static const u8 sOPT_Report_Unown_5[]  = _("ognuno a forma di lettera!");
static const u8 sOPT_Report_Unown_6[]  = _("MARY: Compongono parole,");
static const u8 sOPT_Report_Unown_7[]  = _("forse? O ci spaventano e basta!");
static const u8 sOPT_Report_Unown_8[]  = _("OAK: Un vero enigma naturale,");
static const u8 sOPT_Report_Unown_9[]  = _("ancora irrisolto oggi.");

static const u8 sOPT_Report_Snubbull_0[]  = _("MARY: A FIORLISOPOLO i");
static const u8 sOPT_Report_Snubbull_1[]  = _("residenti li cercano!");
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: Uno SNUBBULL è fuggito");
static const u8 sOPT_Report_Snubbull_3[]  = _("ed è in libertà!");
static const u8 sOPT_Report_Snubbull_4[]  = _("Di solito timido e schizzinoso,");
static const u8 sOPT_Report_Snubbull_5[]  = _("è stato visto in stazione.");
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY: Forse inseguiva");
static const u8 sOPT_Report_Snubbull_7[]  = _("l'amore… o l'avventura!");
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: Tenete gli occhi aperti");
static const u8 sOPT_Report_Snubbull_9[]  = _("e il guinzaglio pronto.");

static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY: Notizia da FIORALBA");
static const u8 sOPT_Report_Slowpoke_1[]  = _("in città questa settimana!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: Gli SLOWPOKE sono tornati");
static const u8 sOPT_Report_Slowpoke_3[]  = _("al loro pozzo dopo una crisi!");
static const u8 sOPT_Report_Slowpoke_4[]  = _("Il TEAM ROCKET tagliava");
static const u8 sOPT_Report_Slowpoke_5[]  = _("le loro code! Orribile!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY: Ma un giovane");
static const u8 sOPT_Report_Slowpoke_7[]  = _("audace li ha fermati!");
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: Gli SLOWPOKE sono salvi");
static const u8 sOPT_Report_Slowpoke_9[]  = _("e tornano a sonnecchiare.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY: La torre di LAVANDONIA");
static const u8 sOPT_Report_LavenderTower_1[]  = _("ha cambiato musica!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: La vecchia torre spettro");
static const u8 sOPT_Report_LavenderTower_3[]  = _("ora è una RADIO!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Alcuni dicono che dia");
static const u8 sOPT_Report_LavenderTower_5[]  = _("ancora i brividi.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY: Giuro di aver visto un GASTLY");
static const u8 sOPT_Report_LavenderTower_7[]  = _("vicino alla cabina!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Sarà statico…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("o spettri!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY: Notizia curiosa dalle");
static const u8 sOPT_Report_Tentacruel_1[]  = _("ISOLE VORTICE oggi!");
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: I TENTACRUEL stanno");
static const u8 sOPT_Report_Tentacruel_3[]  = _("circondando le grotte!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Sono enormi e aggressivi.");
static const u8 sOPT_Report_Tentacruel_5[]  = _("Quasi territoriali.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY: Bloccano la via");
static const u8 sOPT_Report_Tentacruel_7[]  = _("senza attaccare…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: Come a guardia di qualcosa");
static const u8 sOPT_Report_Tentacruel_9[]  = _("in fondo al mare.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
