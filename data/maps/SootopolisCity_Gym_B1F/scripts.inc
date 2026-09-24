SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Ti mostrerò le tecniche sublimi\n"
	.string "che ho imparato dal nostro RODOLFO!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Perdonami, RODOLFO…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Guarda cosa succede se rompi\n"
	.string "tutte le mattonelle.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Sei arrivato fin qui, ma non\n"
	.string "vedrai RODOLFO.\p"
	.string "Non se perdi contro di me!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Sei forte!\n"
	.string "Mi sono fatta ingannare dal tuo aspetto.$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Forse sei abbastanza bravo da non\n"
	.string "essere steso in un colpo da RODOLFO.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Vedere RODOLFO che conduce\n"
	.string "una lotta…\p"
	.string "La sua bellezza mi ha spinta a\n"
	.string "diventare ALLENATRICE.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Hai lottato con più bellezza\n"
	.string "di quanta ne abbia io…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "La grazia che porti in lotta è\n"
	.string "favolosa.\p"
	.string "Oh… sono fortunata ad aver trovato\n"
	.string "i POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Ti insegnerò quanto dure\n"
	.string "possono essere le lotte.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh.\n"
	.string "Sei forte.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Ti dico un segreto.\p"
	.string "Per raggiungere RODOLFO devi\n"
	.string "calpestare ogni mattonella una volta.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "La PALESTRA POKéMON di livello più alto\n"
	.string "della regione di HOENN…\p"
	.string "È la PALESTRA di SOOTOPOLIS.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Che livello alto che hai!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Invece di accontentarti di una\n"
	.string "PALESTRA forte, allenarti altrove\l"
	.string "ti renderà più forte.\l"
	.string "E soprattutto, è più divertente.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "Mi alleno con i POKéMON\n"
	.string "insieme a RODOLFO.\p"
	.string "Non credere che sia una facile.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "Ho perso…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Penso che tu abbia del potenziale.\n"
	.string "Perché non resti ad allenarti con noi?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Scivolare con grazia sul ghiaccio senza\n"
	.string "mai oltrepassare le linee…\p"
	.string "Un ALLENATORE capace di tanto\n"
	.string "sarebbe di una bellezza elegante!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Ma come, scusa?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "È ovvio, ma quanto sei forte\n"
	.string "come ALLENATORE non c'entra nulla\l"
	.string "con la tua età.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Con i miei POKéMON, il tempo\n"
	.string "vola prima che tu dica “Ops!”$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Ops!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "Vorrei dimenticare le cause perse\n"
	.string "prima di dire “Ops!”$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Posso lottare con POKéMON rarissimi\n"
	.string "se vuoi.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, bene! Hai dato una bella occhiata\n"
	.string "ai miei POKéMON?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Sono venuta in questa PALESTRA\n"
	.string "perché RODOLFO ha lodato i miei\p"
	.string "POKéMON. Ah, se avessi conosciuto\n"
	.string "RODOLFO anni fa, da giovane…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Eh eh…\n"
	.string "Il tuo sguardo serio è adorabile.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh, cielo.\n"
	.string "Sono stata troppo clemente.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Non riuscirai a toccare RODOLFO,\n"
	.string "ne son certa. Eh eh…$"

