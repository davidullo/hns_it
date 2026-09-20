BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "Sono CLAIR.\p"
    .string "La miglior maestra di Draghi.\p"
    .string "Reggo bene persino contro l'ALTO\n"
    .string "COMANDO della LEGGA POKéMON.\p"
    .string "Vuoi ancora affrontarmi?\p"
    .string "…Va bene. Si fa!\p"
    .string "Da CAPOPALESTRA userò tutte le\n"
    .string "mie forze contro chiunque!$"

BlackthornGym_Text_ClairWinText:
    .string "Ho perso?\p"
    .string "Non ci credo. Deve esserci\n"
    .string "uno sbaglio…$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "Non me lo merito.\p"
    .string "Forse ho perso, ma non sei\n"
    .string "ancora pronto per la LEGGA POKéMON.\p"
    .string "So cosa fare: affronta la sfida\n"
    .string "degli amanti dei Draghi.\p"
    .string "Dietro questa PALESTRA c'è un\n"
    .string "posto, la GROTTA DRAGO.\p"
    .string "Al centro c'è un piccolo\n"
    .string "santuario. Vai lì.\p"
    .string "Se dimostrerai di aver perso\n"
    .string "i tuoi ideali pigri, ti dirò che\l"
    .string "sei un ALLENATORE degno di\l"
    .string "una MEDAGLIA!$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "Che c'è?\p"
    .string "Ti chiedo troppo?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "Mi hai fatto aspettare!\p"
    .string "Prendi! Tieni!$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "Contiene LEVA DRAGO.\p"
    .string "Cosa fa, lo capirai da solo.$"

BlackthornGym_Text_ClairText_League:
    .string "Che succede?\p"
    .string "Non vai alla LEGA\n"
    .string "POKéMON?\p"
    .string "Non sai dove sia?\p"
    .string "Da qui vai a NEW BARK TOWN.\p"
    .string "Poi SURF a est. La strada è\n"
    .string "durissima.\p"
    .string "Non osare perdere alla LEGA\n"
    .string "POKéMON!\p"
    .string "Se perdi, starò ancora peggio\n"
    .string "per averti perso contro!\p"
    .string "Dai tutto te stesso.$"

BlackthornGym_Text_ClairAfterLeague:
    .string "Ce l'hai fatta, eh?\p"
    .string "Ora sei CAMPIONE DI JOHTO.$"

BlackthornGym_Text_ClairRematchText:
    .string "Ce l'hai fatta, eh?\p"
    .string "Ora sei CAMPIONE DI JOHTO.\p"
    .string "Hai dato prova di forza, ma\n"
    .string "reggerai ancora contro di me?\p"
    .string "Da maestra di Draghi non\n"
    .string "trattengo i colpi.\p"
    .string "Non stavolta.\p"
    .string "Vuoi fare la rivincita con me?$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "Ho perso?\p"
    .string "Di nuovo?\p"
    .string "Non ci credo. Deve esserci\n"
    .string "uno sbaglio…$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "Ora posso usare POKéMON\n"
    .string "di tipo Drago!$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Accidenti! Un DRAGONITE…$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
    .string "Il nostro clan usa i Draghi\n"
    .string "ma solo dopo il permesso\l"
    .string "del nostro MAESTRO.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "Non posso lasciar passare\n"
    .string "un allenatore anonimo!\p"
    .string "CLAIR si arrabbierebbe!$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "Oh no… Ho perso…$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "Uh oh… CLAIR sarà furiosa…$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "Prima volta contro i Draghi?\p"
    .string "Ti mostro quanto sono forti!$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "I miei Draghi hanno perso?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "LANCE ha detto che vuole\n"
    .string "rivederti?\p"
    .string "Impossibile!$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "Perdere? Nemmeno l'1%\n"
    .string "di possibilità!$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "Che strano.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "Ho visto i miei limiti.\p"
    .string "Grazie mille!$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "I Draghi sono POKéMON sacri.\p"
    .string "Pieni di energia vitale.\p"
    .string "Se non sei Seria, non\n"
    .string "riuscirai a batterli.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "Bel colpo!$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "I Draghi temono le mosse\n"
    .string "di tipo Drago.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "Ehi! Futuro CAMPIONE\p"
    .string "È stato un lungo viaggio, ma\n"
    .string "quasi finito! Conta su di me!\p"
    .string "Mentre CLAIR ammira il Maestro\n"
    .string "dei Draghi, LANCE, è riuscita a\l"
    .string "crearsi una sua identità con\l"
    .string "una squadra di draghi del\l"
    .string "mare.\p"
    .string "I Draghi in teoria sono\n"
    .string "deboli al tipo GHIACCIO,\l"
    .string "ma ti servono mosse di tipo\l"
	.string "DRAGO o MAGICO, se vuoi\l"
    .string "vincere.$"
    .string "Ce la fai!$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "Grande, hai battuto CLAIR!\p"
    .string "Però quando perde è un po'\n"
	.string "permale\p"
    .string "Per la TARGA devi andare\n"
    .string "all'ANTRO DEL DRAGO!$"

BlackthornGym_Text_GuideWinText:
    .string "Complimenti, hai battuto CLAIR!\p"
    .string "Manca solo la LEGA\n"
    .string "POKéMON.\p"
    .string "Stai per diventare il\n"
    .string "CAMPIONE POKéMON!$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "PALESTRA DI FIOCCONIGLIA$"

BlackthornGym_Text_GymStatueCertified:
	.string "PALESTRA DI FIOCCONIGLIA\p"
	.string "ALLENATORI DI CLAIR:\n"
	.string "{PLAYER}$"
