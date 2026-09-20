const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Nessuna abilità speciale."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("TANFO"),
        .description = COMPOUND_STRING("Può far tentennare il nemico."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("PIOVISCHIO"),
        .description = COMPOUND_STRING("Evoca la pioggia in lotta."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("ACCELERATORE"),
        .description = COMPOUND_STRING("Aumenta la Velocità gradualmente."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("LOTTASCUDO"),
        .description = COMPOUND_STRING("Blocca i brutti colpi."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("VIGORE"),
        .description = COMPOUND_STRING("Annienta le mosse KO in un colpo."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("UMIDITÀ"),
        .description = COMPOUND_STRING("Impedisce l'autodistruzione."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("SCIOLTEZZA"),
        .description = COMPOUND_STRING("Impedisce la paralisi."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("SABBIAVELO"),
        .description = COMPOUND_STRING("Alza l'elusione nel Terrempesta."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("STATICO"),
        .description = COMPOUND_STRING("Paralizza al contatto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("ASSORBIVOLT"),
        .description = COMPOUND_STRING("Trasforma l'elettricità in PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("ASSORBACQUA"),
        .description = COMPOUND_STRING("Trasforma l'acqua in PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("INDIFFERENZA"),
        .description = COMPOUND_STRING("Evita l'attrazione."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("ANTIMETEO"),
        .description = COMPOUND_STRING("Annienta gli effetti del Meteo."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("INSETTOCCHI"),
        .description = COMPOUND_STRING("Aumenta la precisione."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("INSONNIA"),
        .description = COMPOUND_STRING("Impedisce il sonno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("CAMBIACOLORE"),
        .description = COMPOUND_STRING("Cambia tipo con la mossa nemica."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("IMMUNITÀ"),
        .description = COMPOUND_STRING("Impedisce l'avvelenamento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("FUOCARDORE"),
        .description = COMPOUND_STRING("Si potenzia se colpito dal fuoco."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("POLVOSCUDO"),
        .description = COMPOUND_STRING("Blocca gli effetti aggiunti."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("MENTE LOCALE"),
        .description = COMPOUND_STRING("Blocca la Confusione."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("VENTOSE"),
        .description = COMPOUND_STRING("Ancora saldamente il corpo."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("PREPOTENZA"),
        .description = COMPOUND_STRING("Riduce l'Attacco del nemico."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("PEDINOMBRA"),
        .description = COMPOUND_STRING("Impedisce la fuga del nemico."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("CARTAVETRO"),
        .description = COMPOUND_STRING("Fa male al contatto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("MAGIDIFESA"),
        .description = COMPOUND_STRING("Solo colpi “superefficaci”."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("LEVITAZIONE"),
        .description = COMPOUND_STRING("Non viene colpito da attacchi Terra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("SPARGISPORA"),
        .description = COMPOUND_STRING("Rilascia spore al contatto."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("SINCRONISMO"),
        .description = COMPOUND_STRING("Trasmette i problemi di stato."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("CORPOCHIARO"),
        .description = COMPOUND_STRING("Impedisce cali di abilità."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("ALTERNACURA"),
        .description = COMPOUND_STRING("Cura quando viene ritirato."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("PARAFULMINE"),
        .description = COMPOUND_STRING("Attira mosse elettriche."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("LEGGIADRO"),
        .description = COMPOUND_STRING("Favorisce effetti aggiunti."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("NUOTOVELOX"),
        .description = COMPOUND_STRING("Aumenta la Velocità sotto la pioggia."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("CLOROFILLA"),
        .description = COMPOUND_STRING("Aumenta la Velocità col sole."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("RISPLENDI"),
        .description = COMPOUND_STRING("Aumenta gli incontri."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("TRACCIA"),
        .description = COMPOUND_STRING("Copia l'abilità speciale."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("MACROFORZA"),
        .description = COMPOUND_STRING("Aumenta l'Attacco."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("VELENOPUNTO"),
        .description = COMPOUND_STRING("Avvelena il nemico al contatto."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("FORZA INTERIORE"),
        .description = COMPOUND_STRING("Evita di tentennare."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("MAGMASCUDO"),
        .description = COMPOUND_STRING("Evita il congelamento."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("IDROVELO"),
        .description = COMPOUND_STRING("Evita le scottature."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("MAGNETISMO"),
        .description = COMPOUND_STRING("Intrappola i POKéMON di tipo Acciaio."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("ANTISUONO"),
        .description = COMPOUND_STRING("Evita le mosse sonore."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("COPRIPIOGGIA"),
        .description = COMPOUND_STRING("Recupera un po' di PS sotto la pioggia."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("SABBIAFIUME"),
        .description = COMPOUND_STRING("Evoca una Terrempesta."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("PRESSIONE"),
        .description = COMPOUND_STRING("Aumenta il consumo di PP del nemico."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("GRASSOSPESSO"),
        .description = COMPOUND_STRING("Protezione da caldo e freddo."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("SVEGLIALAMPO"),
        .description = COMPOUND_STRING("Si sveglia in fretta."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("CORPODIFUOCO"),
        .description = COMPOUND_STRING("Scotta il nemico al contatto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("FUGAFACILE"),
        .description = COMPOUND_STRING("Facilita la fuga."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("SGUARDOFERMO"),
        .description = COMPOUND_STRING("Impedisce di perdere precisione."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("IPERTAGLIO"),
        .description = COMPOUND_STRING("Impedisce cali di Attacco."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("RACCOLTA"),
        .description = COMPOUND_STRING("Può raccogliere oggetti."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("PIGRONE"),
        .description = COMPOUND_STRING("Si muove un turno sì e uno no."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("TUTTAFRETTA"),
        .description = COMPOUND_STRING("Baratta precisione per potenza."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("INCANTEVOLE"),
        .description = COMPOUND_STRING("Fa innamorare al contatto."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("PIÙ"),
        .description = COMPOUND_STRING("Si potenzia con Meno."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("MENO"),
        .description = COMPOUND_STRING("Si potenzia con Più."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("PREVISIONI"),
        .description = COMPOUND_STRING("Cambia col Meteo."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("ANTIFURTO"),
        .description = COMPOUND_STRING("Impedisce il furto di oggetti."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("MUTA"),
        .description = COMPOUND_STRING("Si cura cambiando pelle."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("DENTISTRETTI"),
        .description = COMPOUND_STRING("Alza l'Attacco se soffre."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("PELLEDURA"),
        .description = COMPOUND_STRING("Alza la Difesa se soffre."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("MELMA"),
        .description = COMPOUND_STRING("I drenaggi lo feriscono."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("ERBAIUTO"),
        .description = COMPOUND_STRING("Alza le mosse Erba in difficoltà."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("AIUTOFUOCO"),
        .description = COMPOUND_STRING("Alza le mosse Fuoco in difficoltà."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("ACQUAIUTO"),
        .description = COMPOUND_STRING("Alza le mosse Acqua in difficoltà."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("AIUTINSETTO"),
        .description = COMPOUND_STRING("Alza le mosse Coleottero in difficoltà."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("TESTADURA"),
        .description = COMPOUND_STRING("Impedisce i danni da contraccolpo."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("SICCITÀ"),
        .description = COMPOUND_STRING("Evoca il sole in lotta."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("TRAPPOARENA"),
        .description = COMPOUND_STRING("Impedisce la fuga."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("SPIRITOVIVO"),
        .description = COMPOUND_STRING("Impedisce il sonno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("FUMOCHIARO"),
        .description = COMPOUND_STRING("Impedisce cali di abilità."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("FORZAPURA"),
        .description = COMPOUND_STRING("Aumenta l'Attacco."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("GUSCIOSCUDO"),
        .description = COMPOUND_STRING("Blocca i brutti colpi."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("RIPARO"),
        .description = COMPOUND_STRING("Annienta gli effetti del Meteo."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("INTRICOPIEDI"),
        .description = COMPOUND_STRING("Alza l'elusione se confuso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("ELETTRORAPID"),
        .description = COMPOUND_STRING("L'elettricità alza la Velocità."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("ANTAGONISMO"),
        .description = COMPOUND_STRING("Più forte contro i rivali."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("CUORDECISO"),
        .description = COMPOUND_STRING("Terrorizzato alza la Velocità."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("MANTELNEVE"),
        .description = COMPOUND_STRING("Alza elusione in Grandine o Neve."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("VORACITÀ"),
        .description = COMPOUND_STRING("Mangia le Bacche in anticipo."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("GRANCOLLERA"),
        .description = COMPOUND_STRING("I brutti colpi alzano l'Attacco."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("AGILTECNICA"),
        .description = COMPOUND_STRING("Usando uno strumento alza la Velocità."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("ANTIFUOCO"),
        .description = COMPOUND_STRING("Protegge da calore e scottature."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("DISINVOLTURA"),
        .description = COMPOUND_STRING("Soggetto a cambi stat strani."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("PELLEARSA"),
        .description = COMPOUND_STRING("Preferisce l'umidità al calore."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("DOWNLOAD"),
        .description = COMPOUND_STRING("Regola la potenza a favore."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("FERROPUGNO"),
        .description = COMPOUND_STRING("Potenzia le mosse Tirapugni."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("VELENCURA"),
        .description = COMPOUND_STRING("Ripristina PS se avvelenato."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("ADATTABILITÀ"),
        .description = COMPOUND_STRING("Potenzia mosse dello stesso tipo."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("ABILLEGAME"),
        .description = COMPOUND_STRING("Mosse multiple colpiscono 5 volte."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("IDRATAZIONE"),
        .description = COMPOUND_STRING("Cura lo stato sotto la pioggia."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("SOLARPOTERE"),
        .description = COMPOUND_STRING("Più forte sotto il sole."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("PIEDISVELTI"),
        .description = COMPOUND_STRING("Alza la Velocità se soffre."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("NORMALITÀ"),
        .description = COMPOUND_STRING("Le mosse diventano di tipo Normale."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("CECCHINO"),
        .description = COMPOUND_STRING("Potenzia i brutti colpi."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("MAGICSCUDO"),
        .description = COMPOUND_STRING("Danneggiato solo dagli attacchi."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("NULLODIFESA"),
        .description = COMPOUND_STRING("Fa sì che tutte le mosse colpiscano."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("RALLENTATORE"),
        .description = COMPOUND_STRING("Si muove sempre per ultimo."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("TECNICO"),
        .description = COMPOUND_STRING("Potenzia le mosse più deboli."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("FOGLIAMANTO"),
        .description = COMPOUND_STRING("Blocca gli stati sotto il sole."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("IMPACCIO"),
        .description = COMPOUND_STRING("Non può usare strumenti."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("ROMPIFORMA"),
        .description = COMPOUND_STRING("Le mosse passano le abilità."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("SUPERSORTE"),
        .description = COMPOUND_STRING("Brutti colpi spesso a segno."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("SCOPPIO"),
        .description = COMPOUND_STRING("Se sviene danneggia il nemico."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("PRESAGIO"),
        .description = COMPOUND_STRING("Percepisce mosse pericolose."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("PREMONIZIONE"),
        .description = COMPOUND_STRING("Determina la mossa del nemico."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("IMPRUDENZA"),
        .description = COMPOUND_STRING("Ignora i cambi di statistiche."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("LENTIFUMÉ"),
        .description = COMPOUND_STRING("Alza il “poco efficace”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("FILTRO"),
        .description = COMPOUND_STRING("Indebolisce il “superefficace”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("LENTOINIZIO"),
        .description = COMPOUND_STRING("Ci mette un po' a ingranare."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("NERVISALDI"),
        .description = COMPOUND_STRING("Colpisce i POKéMON Spettro."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("ACQUASCOLO"),
        .description = COMPOUND_STRING("Attira le mosse d'Acqua."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("CORPOGELO"),
        .description = COMPOUND_STRING("Recupera PS con Grandine o neve."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("SOLIDROCCIA"),
        .description = COMPOUND_STRING("Indebolisce il “superefficace”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("SCENDINEVE"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Evoca la neve in lotta."),
    #else
        .description = COMPOUND_STRING("Evoca la grandine in lotta."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("MIELINCETTA"),
        .description = COMPOUND_STRING("Può raccogliere Miele."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("INDAGINE"),
        .description = COMPOUND_STRING("Controlla l'oggetto del nemico."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("TEMERARIETÀ"),
        .description = COMPOUND_STRING("Potenzia le mosse con contraccolpo."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("MULTITIPO"),
        .description = COMPOUND_STRING("Cambia tipo in base alla Piastra."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("REGALFIORE"),
        .description = COMPOUND_STRING("Gli alleati si potenziano al sole."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("SOGNIAMARI"),
        .description = COMPOUND_STRING("Danneggia i POKéMON addormentati."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("ARRAFFALESTO"),
        .description = COMPOUND_STRING("Ruba l'oggetto del nemico."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("FORZABRUTA"),
        .description = COMPOUND_STRING("Scambia effetti con la potenza."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("INVERSIONE"),
        .description = COMPOUND_STRING("Inverte le variazioni di statistiche."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("AGITAZIONE"),
        .description = COMPOUND_STRING("I nemici non mangiano bacche."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("AGONISMO"),
        .description = COMPOUND_STRING("Le stat calate alzano l'Attacco."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("SCONFORTO"),
        .description = COMPOUND_STRING("Si arrende a metà PS."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("CORPOFUNESTO"),
        .description = COMPOUND_STRING("Blocca mosse al contatto."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("CURACUORE"),
        .description = COMPOUND_STRING("Cura il POKéMON compagno."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("AMICOSCUDO"),
        .description = COMPOUND_STRING("Riduce i danni al compagno."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("SOTTILGUSCIO"),
        .description = COMPOUND_STRING("Le stat cambiano se colpito."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("METALPESANTE"),
        .description = COMPOUND_STRING("Raddoppia il peso."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("METALLEGGERO"),
        .description = COMPOUND_STRING("Dimezza il peso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("MULTISQUAME"),
        .description = COMPOUND_STRING("Dimezza i danni a PS pieni."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("VELENIMPETO"),
        .description = COMPOUND_STRING("Alza l'Attacco se avvelenato."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("BRUCIAIMPETO"),
        .description = COMPOUND_STRING("Alza l'Att. Speciale se scottato."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("COGLIBACCHE"),
        .description = COMPOUND_STRING("Può riciclare una bacca usata."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("TELEPATIA"),
        .description = COMPOUND_STRING("Non subisce danni da alleati."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("ALTALENA"),
        .description = COMPOUND_STRING("Le stat cambiano gradualmente."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("COPRICAPO"),
        .description = COMPOUND_STRING("Blocca meteo e polveri."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("VELENTOCCO"),
        .description = COMPOUND_STRING("Avvelena il nemico al contatto."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("RIGENERGIA"),
        .description = COMPOUND_STRING("Cura quando viene ritirato."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("PETTINFUORI"),
        .description = COMPOUND_STRING("Impedisce la perdita di Difesa."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("REMASABBIA"),
        .description = COMPOUND_STRING("Alza la Velocità nella Terrempesta."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("SPLENDICUTE"),
        .description = COMPOUND_STRING("Può evitare problemi di stato."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("PONDERAZIONE"),
        .description = COMPOUND_STRING("Muoversi per ultimo potenzia."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("ILLUSIONE"),
        .description = COMPOUND_STRING("Appare come compagno."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("SOSIA"),
        .description = COMPOUND_STRING("Si trasforma nel nemico."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("INTRAPASSO"),
        .description = COMPOUND_STRING("Passa attraverso le barriere."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("MUMMIA"),
        .description = COMPOUND_STRING("Si diffonde al contatto."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("ARROGANZA"),
        .description = COMPOUND_STRING("I KO alzano l'Attacco."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("GIUSTIZIA"),
        .description = COMPOUND_STRING("Colpi Buio alzano Attacco."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("PAURA"),
        .description = COMPOUND_STRING("Alza la Velocità se spaventato."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("MAGISPECCHIO"),
        .description = COMPOUND_STRING("Riflette le mosse di stato."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("MANGIAERBA"),
        .description = COMPOUND_STRING("L'Erba aumenta l'Attacco."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("BURLA"),
        .description = COMPOUND_STRING("Mosse di stato per prime."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("SILICOFORZA"),
        .description = COMPOUND_STRING("Si potenzia nella terrempesta."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("SPINEFERRATE"),
        .description = COMPOUND_STRING("Fa male al contatto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("STATO ZEN"),
        .description = COMPOUND_STRING("Si trasforma a metà PS."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("VITTORSTELLA"),
        .description = COMPOUND_STRING("Alza la precisione del team."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("PIROTURBINA"),
        .description = COMPOUND_STRING("Le mosse passano le abilità."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("TERAVOLT"),
        .description = COMPOUND_STRING("Le mosse passano le abilità."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("AROMAVELO"),
        .description = COMPOUND_STRING("Impedisce di limitare le mosse."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("FIORVELO"),
        .description = COMPOUND_STRING("Protegge i tipi Erba."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("GUANCEGONFIE"),
        .description = COMPOUND_STRING("Mangiare bacche cura i PS."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("MUTATIPO"),
        .description = COMPOUND_STRING("Cambia tipo con la mossa usata."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("FOLTOPELO"),
        .description = COMPOUND_STRING("Alza la Difesa."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("PRESTIGIATORE"),
        .description = COMPOUND_STRING("Ruba l'oggetto del nemico."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("ANTIPROIETTILE"),
        .description = COMPOUND_STRING("Evita alcuni proiettili."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("TENACIA"),
        .description = COMPOUND_STRING("Statistiche calate alzano Att. Sp."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("FERROMASCELLA"),
        .description = COMPOUND_STRING("Potenzia le mosse morso."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("PELLEGELO"),
        .description = COMPOUND_STRING("Mosse Normale diventano Ghiaccio."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("DOLCEVELO"),
        .description = COMPOUND_STRING("Impedisce il sonno al team."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("ACCENDILOTTA"),
        .description = COMPOUND_STRING("Si trasforma lottando."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("ALIRAFFICA"),
        .description = COMPOUND_STRING("Mosse Volante per prime."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("MEGALANCIO"),
        .description = COMPOUND_STRING("Potenzia le mosse impulso."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("PELODERBA"),
        .description = COMPOUND_STRING("Alza la Difesa nell'erba."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("SIMBIOSI"),
        .description = COMPOUND_STRING("Passa lo strumento a un alleato."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("UNGHIEDURE"),
        .description = COMPOUND_STRING("Potenzia le mosse da contatto."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("PELLEFOLLETTO"),
        .description = COMPOUND_STRING("Mosse Normale diventano Magico."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("VISCOSITÀ"),
        .description = COMPOUND_STRING("Riduce la Velocità al contatto."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("PELLECIELO"),
        .description = COMPOUND_STRING("Mosse Normale diventano Volante."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("AMOREFILIALE"),
        .description = COMPOUND_STRING("Le mosse colpiscono due volte."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("AURATETRA"),
        .description = COMPOUND_STRING("Potenzia le mosse Buio."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("AURAFOLLETTO"),
        .description = COMPOUND_STRING("Potenzia le mosse Magico."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("FRANGIAURA"),
        .description = COMPOUND_STRING("Inverte le abilità Aura."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("MARE PRIMORDIALE"),
        .description = COMPOUND_STRING("Evoca pioggia battente."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("TERRA ESTREMA"),
        .description = COMPOUND_STRING("Evoca luce solare intensa."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("FLUSSO DELTA"),
        .description = COMPOUND_STRING("Evoca venti forti."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("SOPPORTAZIONE"),
        .description = COMPOUND_STRING("Aumenta la Difesa se colpito."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("FUGGIFUGGI"),
        .description = COMPOUND_STRING("Fugge a metà PS."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("PASSOINDIETRO"),
        .description = COMPOUND_STRING("Fugge a metà PS."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("IDRORINFORZO"),
        .description = COMPOUND_STRING("L'Acqua aumenta la Difesa."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("SPIETATEZZA"),
        .description = COMPOUND_STRING("Critici sui nemici avvelenati."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("SCUDOSOGLIA"),
        .description = COMPOUND_STRING("Il guscio si rompe a metà PS."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("SORVEGLIANZA"),
        .description = COMPOUND_STRING("Più forte quando il nemico entra."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("BOLLADACQUA"),
        .description = COMPOUND_STRING("Protegge da fuoco e scottature."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("TEMPRACCIAIO"),
        .description = COMPOUND_STRING("Potenzia le mosse Acciaio."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("FURORE"),
        .description = COMPOUND_STRING("Aumenta l'Att. Sp. con pochi PS."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("SPALANEVE"),
        .description = COMPOUND_STRING("Aumenta la Velocità in Grandine."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("DISTACCO"),
        .description = COMPOUND_STRING("Non entra mai a contatto."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("IDROVOCE"),
        .description = COMPOUND_STRING("Mosse sonore diventano Acqua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("PRIMACURA"),
        .description = COMPOUND_STRING("Le mosse curative vanno prima."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("PELLELETTRO"),
        .description = COMPOUND_STRING("Mosse Normale diventano Elettrico."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("CODASURF"),
        .description = COMPOUND_STRING("Più veloce sull'elettricità."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("BANCO"),
        .description = COMPOUND_STRING("Forma un banco se forte."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("FANTASMANTO"),
        .description = COMPOUND_STRING("Un diversivo lo protegge una volta."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("MORFOSINTONIA"),
        .description = COMPOUND_STRING("Cambia forma dopo un KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("SCIAMEFUSIONE"),
        .description = COMPOUND_STRING("Le cellule lo aiutano se indebolito."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("CORROSIONE"),
        .description = COMPOUND_STRING("Avvelena qualsiasi tipo."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("SONNO ASSOLUTO"),
        .description = COMPOUND_STRING("Sempre in Dormiveglia."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("REGALITÀ"),
        .description = COMPOUND_STRING("Protegge dalla priorità."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("ESPELLINTERNO"),
        .description = COMPOUND_STRING("Danneggia il nemico se va KO."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("SINCRODANZA"),
        .description = COMPOUND_STRING("Balla insieme agli altri."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("BATTERIA"),
        .description = COMPOUND_STRING("Aumenta l'Att. Sp. degli alleati."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("MORBIDONE"),
        .description = COMPOUND_STRING("Più robusto ma infiammabile."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("CORPOSGARGIANTE"),
        .description = COMPOUND_STRING("Protegge dalla priorità."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("CUOREANIMA"),
        .description = COMPOUND_STRING("Gli KO aumentano l'Att. Sp."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("BOCCOLIDORO"),
        .description = COMPOUND_STRING("Riduce la Velocità al contatto."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("RICEZIONE"),
        .description = COMPOUND_STRING("Copia l'abilità dell'alleato."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("FORZA CHIMICA"),
        .description = COMPOUND_STRING("Copia l'abilità dell'alleato."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("ULTRABOOST"),
        .description = COMPOUND_STRING("Gli KO alzano la statistica migliore."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("SISTEMA PRIMEVO"),
        .description = COMPOUND_STRING("Le memorie cambiano il suo tipo."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("ELETTROGENESI"),
        .description = COMPOUND_STRING("Il campo diventa Elettrico."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("PSICOGENESI"),
        .description = COMPOUND_STRING("Il campo diventa strano."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("NEBBIOGENESI"),
        .description = COMPOUND_STRING("Il campo diventa nebbioso."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("ERBOGENESI"),
        .description = COMPOUND_STRING("Il campo diventa erboso."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("METALPROTEZIONE"),
        .description = COMPOUND_STRING("Impedisce la riduzione delle statistiche."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("SPETTROGUARDIA"),
        .description = COMPOUND_STRING("Dimezza i danni a PS pieni."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("SCUDOPRISMA"),
        .description = COMPOUND_STRING("Indebolisce il “superefficace”."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("CEREBROFORZA"),
        .description = COMPOUND_STRING("Aumenta il “superefficace”."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("SPADA INDOMITA"),
        .description = COMPOUND_STRING("Alza l'Attacco all'entrata."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("SCUDO SALDO"),
        .description = COMPOUND_STRING("Alza la Difesa all'entrata."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LIBERO"),
        .description = COMPOUND_STRING("Cambia tipo in quello della mossa."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("RACCATTAPALLE"),
        .description = COMPOUND_STRING("Recupera la Poké Ball fallita."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("LANUGINE"),
        .description = COMPOUND_STRING("Riduce la Velocità di tutti se colpito."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("ELICOPINNA"),
        .description = COMPOUND_STRING("Ignora la deviazione del nemico."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("BLINDOSPECCHIO"),
        .description = COMPOUND_STRING("Riflette i cali di statistiche."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("INGHIOTTIMISSILE"),
        .description = COMPOUND_STRING("Se colpito, sputa la preda dal mare."),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("VOLONTÀ DI FERRO"),
        .description = COMPOUND_STRING("Ignora la deviazione del nemico."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("VAPORMACCHINA"),
        .description = COMPOUND_STRING("Colpi di Fuoco o Acqua alzano la Velocità."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("PUNK ROCK"),
        .description = COMPOUND_STRING("Alza e resiste ai suoni."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("SPUTASABBIA"),
        .description = COMPOUND_STRING("Se colpito, crea una Terrempesta."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("GELOSCAGLIE"),
        .description = COMPOUND_STRING("Dimezza i danni speciali."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("MATURAZIONE"),
        .description = COMPOUND_STRING("Raddoppia l'effetto delle Bacche."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("GELOFACCIA"),
        .description = COMPOUND_STRING("Grandine o Neve rinnovano il colpo gratis."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("FONTE ENERGETICA"),
        .description = COMPOUND_STRING("Potenzia le mosse degli alleati."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("MIMETISMO"),
        .description = COMPOUND_STRING("Cambia tipo sul terreno."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("ANNULLABARRIERE"),
        .description = COMPOUND_STRING("Rimuove le barriere di luce."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("SPIRITOFERREO"),
        .description = COMPOUND_STRING("Potenzia le mosse Acciaio degli alleati."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("ULTIMOTOCCO"),
        .description = COMPOUND_STRING("Il nemico sviene in 3 turni se colpito."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("ANIMA ERRANTE"),
        .description = COMPOUND_STRING("Scambia abilità al contatto."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("VIGORILLA"),
        .description = COMPOUND_STRING("Alza l'Attacco e blocca la mossa."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("GAS REAGENTE"),
        .description = COMPOUND_STRING("Tutte le abilità sono annullate."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("PASTELVELO"),
        .description = COMPOUND_STRING("Protegge la squadra dal veleno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("PANCIALTERNA"),
        .description = COMPOUND_STRING("Cambia forma ogni turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("COLPOLESTO"),
        .description = COMPOUND_STRING("A volte agisce per primo."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("PUGNI INVISIBILI"),
        .description = COMPOUND_STRING("Il contatto evade le protezioni."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("STRANOFARMACO"),
        .description = COMPOUND_STRING("Rimuove i potenziamenti dell'alleato."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("TRANSISTOR"),
        .description = COMPOUND_STRING("Potenzia le mosse Elettro."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("DRAGOMASCELLE"),
        .description = COMPOUND_STRING("Potenzia le mosse Drago."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("NITRITO BIANCO"),
        .description = COMPOUND_STRING("I KO aumentano l'Attacco."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("NITRITO NERO"),
        .description = COMPOUND_STRING("I KO aumentano l'Att. Spec."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("SINTONIA EQUINA"),
        .description = COMPOUND_STRING("Agitazione e Nitrito Sferzante."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("SINTONIA EQUINA"),
        .description = COMPOUND_STRING("Agitazione e Nitrito Truce."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("ODORE TENACE"),
        .description = COMPOUND_STRING("Si diffonde al contatto."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("SPARGISEMI"),
        .description = COMPOUND_STRING("Cambia il terreno se colpito."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("TERMOSCAMBIO"),
        .description = COMPOUND_STRING("Il Fuoco ne aumenta l'Attacco."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("IRAGUSCIO"),
        .description = COMPOUND_STRING("Si arrabbia a metà PS."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("SALE PURIFICANTE"),
        .description = COMPOUND_STRING("Protetto dai sali puri."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("BENTOSTATO"),
        .description = COMPOUND_STRING("Rinforzato dal Fuoco."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("VENTO PROPIZIO"),
        .description = COMPOUND_STRING("Aumenta l'Attacco se colpito dal vento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("CANE DA GUARDIA"),
        .description = COMPOUND_STRING("Non può essere intimidito."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("PORTAMASSI"),
        .description = COMPOUND_STRING("Potenzia le mosse Roccia."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("ENERGIA EOLICA"),
        .description = COMPOUND_STRING("Si carica con il vento."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("SUPERCAMBIO"),
        .description = COMPOUND_STRING("Cambia forma quando viene sostituito."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("TORRE DI COMANDO"),
        .description = COMPOUND_STRING("Riceve ordini da Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("CONVERTIVOLT"),
        .description = COMPOUND_STRING("Si carica quando viene colpito."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("PALEOATTIVAZIONE"),
        .description = COMPOUND_STRING("Il Sole potenzia la statistica migliore."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("CARICA QUARK"),
        .description = COMPOUND_STRING("Il campo Elettro sale la stat migliore."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("CORPO AUREO"),
        .description = COMPOUND_STRING("Evita le mosse di stato."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("VASO NEFASTO"),
        .description = COMPOUND_STRING("Riduce i danni speciali dei nemici."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("SPADA NEFASTA"),
        .description = COMPOUND_STRING("Riduce la Difesa dei nemici."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("AMULETO NEFASTO"),
        .description = COMPOUND_STRING("Riduce i danni dei nemici."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("MONILE NEFASTO"),
        .description = COMPOUND_STRING("Riduce la Dif. Spec. dei nemici."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("RITMO D’ORICALCO"),
        .description = COMPOUND_STRING("Evoca il sole in lotta."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("MOTORE ADRONICO"),
        .description = COMPOUND_STRING("Il campo diventa Elettrico."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("SCROCCO"),
        .description = COMPOUND_STRING("Copia il potenziamento del nemico."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("RUMINANTE"),
        .description = COMPOUND_STRING("Mangia di nuovo una bacca usata."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("AFFILAMA"),
        .description = COMPOUND_STRING("Potenzia le mosse taglienti."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("GENERALE SUPREMO"),
        .description = COMPOUND_STRING("Eredita la forza di un alleato caduto."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("COPROTAGONISMO"),
        .description = COMPOUND_STRING("Copia i potenziamenti dell'alleato."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("MANTOSSINA"),
        .description = COMPOUND_STRING("Lancia Punzoni velenosi se colpito."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("CODARMATURA"),
        .description = COMPOUND_STRING("Protegge dalla priorità."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("MANGIATERRA"),
        .description = COMPOUND_STRING("Mangia terra per recuperare PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("MICOFORZA"),
        .description = COMPOUND_STRING("Le mosse di stato non falliscono mai."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("OSPITALITÀ"),
        .description = COMPOUND_STRING("Recupera i PS dell'alleato."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("OCCHIO INTERIORE"),
        .description = COMPOUND_STRING("Occhioindifeso e Nervisaldi."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("ALBERGAMEMORIE"),
        .description = COMPOUND_STRING("Aumenta la Velocità."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("ALBERGAMEMORIE"),
        .description = COMPOUND_STRING("Aumenta l'Attacco."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("ALBERGAMEMORIE"),
        .description = COMPOUND_STRING("Aumenta la Dif. Sp."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("ALBERGAMEMORIE"),
        .description = COMPOUND_STRING("Alza la Difesa."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("CATENA TOSSICA"),
        .description = COMPOUND_STRING("Le mosse possono avvelenare."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("SCIROPPO SUBLIME"),
        .description = COMPOUND_STRING("Riduce l'Elusione del nemico."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("TERAMORFOSI"),
        .description = COMPOUND_STRING("Si teracristallizza entrando."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("TERAGUSCIO"),
        .description = COMPOUND_STRING("Resiste a tutto a PS pieni."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("ZEROFORMAZIONE"),
        .description = COMPOUND_STRING("Annulla meteo e terreno."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("MALIA TOSSICA"),
        .description = COMPOUND_STRING("Confonde i nemici avvelenati."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
