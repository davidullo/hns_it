MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Ricordi del mio adorato SKITTY…\n"
	.string "Mi si riempiono gli occhi al pensiero.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ahia, ahia… Ci sono buchi nel\n"
	.string "terreno qua e là.\p"
	.string "Non li ho visti e sono caduto dal\n"
	.string "piano di sopra.$"

MtPyre_2F_Text_MarkIntro:
	.string "Ehi! Cerchi dei POKéMON?\n"
	.string "Sei arrivato dopo di me! Che maleducato!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ahiieeeh!\n"
	.string "Scusa, perdonami, ti prego!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Non viene quasi nessuno qui, quindi\n"
	.string "credevo ci fossero POKéMON rari.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUCA: Siamo qui per una scommessa.\p"
	.string "Se le mostro quanto sono forte,\n"
	.string "si innamorerà di me. Lo so!\p"
	.string "Lo so! Ti straccio e le mostro\n"
	.string "quanto sono forte!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUCA: Ops!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUCA: Beh, abbiamo perso ma va bene!\n"
	.string "Ti sono accanto.\l"
	.string "Supereremo questa scommessa!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUCA: Se vuoi sfidarmi,\n"
	.string "porta altri POKéMON.\p"
	.string "Altrimenti non posso mostrare\n"
	.string "alla mia ragazza quanto sono forte!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Sono venuta qui per una sfida\n"
	.string "col mio ragazzo.\p"
	.string "Fa davvero paura, ma sono col mio\n"
	.string "ragazzo. Va tutto bene.\p"
	.string "Idea! Farò fare bella figura al mio\n"
	.string "ragazzo battendoti!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaah! Che paura!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Siamo innamorati, quindi\n"
	.string "non ci importa se perdiamo!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Se vuoi sfidarci, dovresti\n"
	.string "portare almeno due POKéMON.\p"
	.string "Il mio ragazzo è forte.\n"
	.string "Con un solo POKéMON non basta.$"

MtPyre_2F_Text_LeahIntro:
	.string "Sei un volto sconosciuto…\n"
	.string "Vattene prima che ti accada qualcosa!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Sei resistente.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "La mia famiglia fa la TRAINER qui\n"
	.string "da quando c'era la mia bisnonna…\p"
	.string "È mio dovere proteggere questa\n"
	.string "montagna…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Che terrore!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooooooo!\n"
	.string "Ho perso la testa!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Prendo un colpo ogni volta che vedo\n"
	.string "qualcosa muoversi…\p"
	.string "Non dovevo venire qui ad allenarmi…$"

