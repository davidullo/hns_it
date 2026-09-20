// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("Informazioni: Finestre Aiuto"),
        .desc = COMPOUND_STRING("Questa è una finestra di aiuto. Puoi\n"
                                "mettere un sacco di testo sullo\n"
                                "schermo che i giocatori non leggeranno!\n\nNon è fantastico!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("Informazioni: Altre Opzioni"),
        .desc = COMPOUND_STRING("L'orologio si può cambiare da qualsiasi\n"
                                "CENTRO POKéMON senza penalità.\n"
                                "Controlla gli STRUMENTI nella BORSA\n"
                                "e il MENU OPZIONI per altre\n"
                                "modi di personalizzare l'esperienza.\n"
                                "Buon divertimento!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("ATTENZIONE: COMPATIBILITÀ"),
        .desc = COMPOUND_STRING("Un collegamento errato può danneggiare\n"
                                "permanentemente il file di salvataggio.\n"
                                "Collega un altro giocatore solo se:\n"
                                "Entrambi giocate a Heart & Soul.\n"
                                "Avete la stessa versione.\n"
                                "Avete le stesse impostazioni di sfida.\n"
                                "NON usate impostazioni randomizzate."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENUTO EXTRA OPZIONALE: TELEPORTO"),
        .desc = COMPOUND_STRING("Il TELEPORTO può trasformare PER SEMPRE\n"
                                "i POKéMON nelle loro forme di GALAR.\n"
                                "Le forme di GALAR NON servono\n"
                                "per la storia né per\n"
                                "completare il POKéDEX NAZIONALE.\n"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENUTI BONUS OPZIONALI: SINJOH"),
        .desc = COMPOUND_STRING("Questo PNG dà accesso a contenuti\n"
                                "bonus opzionali: SINJOH.\n"
                                "NON serve per la storia\n"
                                "né per il POKéDEX NAZIONALE.\n"
                                "\n"
                                "È solo un bonus. Se lo vuoi."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENUTI EXTRA OPZIONALI: ISOLE"),
        .desc = COMPOUND_STRING("Questo NPC dà accesso a contenuti\n"
                                "extra opzionali: le ISOLE.\n"
                                "NON serve per la storia\n"
                                "né per completare il POKéDEX NAZIONALE.\n"
                                "\n"
                                "È solo un extra. Se lo vuoi."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("ABILITÀ DEI POKéMON BEBÈ"),
        .desc = COMPOUND_STRING("L'abilità di PICHU è STATICO.\n"
                                "L'abilità di CLEFFA è GRAZIOSO.\n"
                                "L'abilità di IGGLYBUFF è GRAZIOSO.\n"
                                "L'abilità di TYROGUE è DENTISTRETTI.\n"
                                "L'abilità di SMOOCHUM è INDIFFERENZA.\n"
                                "L'abilità di ELEKID è STATICO.\n"
                                "L'abilità di MAGBY è CORPOFIAMMA."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("TIPI DEI POKéMON BEBÈ"),
        .desc = COMPOUND_STRING("PICHU è di tipo ELETTRICO.\n"
                                "CLEFFA è di tipo NORMALE.\n"
                                "IGGLYBUFF è di tipo NORMALE.\n"
                                "TYROGUE è di tipo LOTTA.\n"
                                "SMOOCHUM è di tipo GHIACCIO.\n"
                                "ELEKID è di tipo ELETTRICO.\n"
                                "MAGBY è di tipo FUOCO."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("VERSI DEI POKéMON BEBÈ"),
        .desc = COMPOUND_STRING("PICHU fa WAAAH.\n"
                                "CLEFFA fa IHH.\n"
                                "IGGLYBUFF fa LALALA.\n"
                                "TYROGUE fa HIYAH.\n"
                                "SMOOCHUM fa EHEHE.\n"
                                "ELEKID fa OI, OI, OI.\n"
                                "MAGBY fa TCH."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("AZIONI DEI POKéMON BEBÈ"),
        .desc = COMPOUND_STRING("PICHU adora GIOCARE tutto il giorno.\n"
                                "CLEFFA GUARDA la luna.\n"
                                "IGGLYBUFF li fa ADDORMENTARE.\n"
                                "TYROGUE si ALLENA sempre.\n"
                                "SMOOCHUM adora METTERSI in mostra.\n"
                                "ELEKID ACCUMULA carica.\n"
                                "MAGBY spesso si ARRABBIA."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("NUTRIENTI: POKéBLOCCHI NORMALI"),
        .desc = COMPOUND_STRING("I POKéBLOCK attirano IV perfetti:\n"
                                "ROS: PS,ATT,VEL   BLU: PS,ATTSP,VEL\n"
                                "ROS: ATT,ATTSP,VEL VER: PS,DIF,VEL\n"
                                "GIA: PS,ATT,DIF   PUR: ATT,DIF,VEL\n"
                                "IND: PS,ATTSP,VEL  MAR: DIF,VEL,VEL\n"
                                "LBL: ATTSP,VEL,VEL OLI: ATT,DIF,VEL\n"
                                "GRG: PS,ATT,ATTSP\n"
                                "Ogni POKéBLOCK attira ABILITÀ NASCOSTA."

                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("NUTRIENTI: POKéBLOCCHI ORO"),
        .desc = COMPOUND_STRING("I POKéBLOCK D'ORO attirano POKéMON con\n"
                                "5 IV perfetti. Il sapore determina quale\n"
                                "IV non è perfetto.\n"
                                "PICC: no ATTSP    SECCO: no ATTACCO\n"
                                "DOLCE: no DIFSP   AMARO: no VELOCITÀ\n"
                                "ASPRO: no PS\n"
                                "Ogni POKéBLOCK attira ABILITÀ NASCOSTA."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
