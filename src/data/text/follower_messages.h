extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} ti ha colpito lo\nstomaco.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} è felice ma timido.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} ti segue felice.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} è composto.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} sembra felice\ndi camminare con te!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} è raggiante di salute.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} sembra felicissimo.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} si è impegnato di più.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} annusa gli odori\ndell'aria intorno.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} salta di gioia!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} sta ancora benissimo!");
static const u8 sHappyMsg11[] = _("Il tuo POKéMON ha sentito odore\ndi fumo.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} ti tocca la pancia.");
static const u8 sHappyMsg13[] = _("Il tuo POKéMON si è stiracchiato\ne si rilassa.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} vuole\nguidare lui!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} fa del suo meglio\nper starti dietro.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} si struscia felice\ncontro di te!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} è pieno di vita!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} sembra molto felice!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} è così felice che\nnon sta fermo!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} ha annuito piano.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} è pieno di entusiasmo!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} gironzola in giro\nascoltando i vari suoni.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} sembra molto interessato.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} si sta sforzando\ndi continuare.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} ti ha dato uno sguardo solare!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} ti guarda felice\ne sorride.");
static const u8 sHappyMsg27[] = _("Il tuo POKéMON annusa il profumo\ndei fiori.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} sembra felice di\nvederti!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} si è girato\ne ha sorriso.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} ti si è coccolato\naddosso!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Il tuo POKéMON sembra felice\ndel bel tempo.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} è molto composto\ne sicuro di sé!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} punzecchia il\nterreno.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} fa la guardia.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} fissa paziente\nil nulla.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} gironzola in giro.");
static const u8 sNeutralMsg04[] = _("Il tuo POKéMON ha sbadigliato forte!");
static const u8 sNeutralMsg05[] = _("Il tuo POKéMON si guarda intorno\nirrequieto.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} ti guarda\ne sorride.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} si guarda intorno\nirrequieto.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} ha lanciato un grido di battaglia.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} ha ballato una\ndanza meravigliosa!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} è molto impaziente.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} fissa intensamente\nla distanza.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} è in allerta!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} ha guardato lontano\ne ha abbaiato!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} ha le vertigini.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} ti sta pestando\ni piedi!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} sembra un po' stanco.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} non è felice.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} sta per cadere!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} sta per\ncrollare!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} si sforza molto\ndi starti dietro…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} è nervoso.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} sembra inquieto…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} ha una\nfaccia infelice.");
static const u8 sUpsetMsg02[] = _("…Il tuo POKéMON sembra un po'\nfreddo.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} si ripara nell'\nerba dalla pioggia.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} ha emesso un Boato!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} fa una faccia\narrabbiata!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} sembra arrabbiato\nper qualche motivo.");
static const u8 sAngryMsg03[] = _("Il tuo POKéMON si è girato\ndall'altra parte, con aria di sfida.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} ha gridato.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} guarda in basso\nfisso.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} osserva i dintorni.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} sbircia in basso.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} lotta contro il\nsonno…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} sembra vagare\nqua e là.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} si guarda intorno\ndistratto.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} ha sbadigliato forte!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} si riposa comodo.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} ti fissa\nil volto.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} ti fissa\nil volto.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} concentra la sua\nattenzione su di te.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} fissa\nnel vuoto.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} annusa\nil terreno.");
static const u8 sPensiveMsg13[] = _("Il tuo POKéMON fissa intensamente\nil nulla.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} si è concentrato\ncon sguardo acuto!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} si concentra.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} si è voltato\ne ha annuito.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} sembra un po' nervoso…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} guarda le tue\nimpronte.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} ti fissa dritto\nnegli occhi.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} si è avvicinato\ndi colpo!");
static const u8 sLoveMsg01[] = _("Le guance di {STR_VAR_1}\nsi fanno rosse!");
static const u8 sLoveMsg02[] = _("Uau! {STR_VAR_1} ti ha\nabbracciato di colpo!");
static const u8 sLoveMsg03[] = _("Uau! {STR_VAR_1} è diventato\ncosì briccone!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} ti struscia contro\nle zampe!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} arrossisce.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} ti coccola!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} ti guarda con\nadorazione!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} ti si avvicina.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} ti resta vicino\nai piedi.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} sta per cadere\na terra!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} ti ha urtato!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} non sembra ancora\nabituato al suo nome.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} sbircia in basso.");
static const u8 sSurpriseMsg04[] = _("Il tuo POKéMON è inciampato e\nstava per cadere!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} sente qualcosa e\nulula!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} sembra ripreso!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} si è girato\ne ha iniziato ad abbaiare!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} si è girato di colpo!");
static const u8 sSurpriseMsg09[] = _("Il tuo POKéMON si è sorpreso\nche gli hai parlato!");
static const u8 sSurpriseMsg10[] = _("Sniff sniff, c'è qualcosa che\nprofuma davvero bene!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} si sente ripreso.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} barcolla e sta\nper cadere.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} rischia di\ncadere.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} cammina\ncon cautela.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} è teso e pieno\ndi nervosismo.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} ha sentito qualcosa\ndi strano ed è sussultato!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} spaventato si è\nstrusciato contro di te!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} sente una presenza\ninsolita…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} è teso e pieno\ndi nervosismo.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} sembra molto\nsorpreso che piova!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Il tuo POKéMON si guarda intorno\nin cerca di qualcosa.");
static const u8 sCuriousMsg01[] = _("Il tuo POKéMON non guardava dove\nandava e ti è venuto addosso!");
static const u8 sCuriousMsg02[] = _("Sniff, sniff! C'è qualcosa\nqui vicino?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} fa rotolare un\nsassolino giocando.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} va in giro e\ncerca qualcosa.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} ti annusa.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} sembra un po'\nesitante…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} sfoggia la sua\nagilità!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} si muove\nfelice!");
static const u8 sMusicMsg02[] = _("Uau! {STR_VAR_1} ha iniziato\na ballare per la felicità!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} ti sta dietro\nsenza problemi!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} vuole giocare\ncon te.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} saltella felice.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} canta e canticchia.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} ti mordicchia i piedi!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} si gira e ti\nguarda.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} si impegna per\nmostrare la sua forza!");
static const u8 sMusicMsg10[] = _("Uau! {STR_VAR_1} ha ballato\nper la felicità!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} è allegro!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} salta in giro\nspensierato!");
static const u8 sMusicMsg13[] = _("Il tuo POKéMON sente un odore\nfamiliare e nostalgico…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} è molto felice\nper la pioggia.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} trema per\nl'effetto del veleno.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
