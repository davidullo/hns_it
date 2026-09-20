SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Che schifo!\n"
    .string "Non dovevo guardare!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Ehi, ragazzo. Puoi cercare\n"
	.string "il mio amico?\p"
	.string "Sta bighellonando da qualche parte,\n"
	.string "quel pigrone!\p"
	.string "Vorrei andare io, ma\n"
	.string "sono di servizio ora.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh, caspita…\p"
	.string "Il CAPITANO sarà furioso…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Grazie, ragazzo! L'ho sgridato\n"
	.string "come si deve, ora la smetterà!$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "Una bambina?\p"
	.string "Forse l'ho vista passare di qui.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "La sala da pranzo è più avanti.\p"
	.string "Le scale in fondo portano\n"
	.string "alla cabina del CAPITANO.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Niente batte una lotta\n"
	.string "durante la pausa.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Vinca o perda, la pausa è finita!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Direi che non posso vincere\n"
	.string "se non faccio sul serio.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Che noia. Ti va di lottare?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Ahia! Sei troppo forte!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFFRON, CELADON… dicono che\n"
	.string "a KANTO ci siano grandi città.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Uff… che mal di mare!$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "Non riesco più a muovermi…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "Mai più navi per me.\n"
	.string "La prossima volta\p"
	.string "prendo il TRENO MAGNETICO.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "Qui lavoriamo noi marinai!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "Ho perso in casa mia…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Portiamo passeggeri diversi\n"
	.string "da VERMILION CITY a\p"
	.string "OLIVINE CITY.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "Siamo in mare, eppure\n"
	.string "non posso pescare!\p"
	.string "Che noia! Lottiamo!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Io… non mi annoio più…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Penso di pescare dal\n"
	.string "molo di VERMILION.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "Metto su le gambe\n"
	.string "tenendomi\p"
	.string "al rollio della nave!$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "Mi hai travolto!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "Non ho trovato il RE DEL KARATE\n"
	.string "a JOHTO.\p"
	.string "Dovrebbe allenarsi in\n"
	.string "una grotta da qualche parte.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "Sono un marinaio!\p"
	.string "Ma alleno POKéMON per\n"
	.string "diventare CAMPIONE!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "La mia poca esperienza si vede…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Otto MEDAGLIE! Devono provare\n"
	.string "che hai battuto\p"
	.string "i CAPOPALESTRA.\p"
	.string "Ecco perché sei così forte!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "Non osare toccare\n"
	.string "i miei alunni!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaah!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "Siamo in gita verso le\n"
	.string "ROVINE fuori da VIOLET.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Conosci le ROVINE DI ALPH?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Argh!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Le radio captano strani segnali\n"
	.string "dentro le ROVINE.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "Ci sono strane lastre di pietra\n"
	.string "nelle ROVINE DI ALPH.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "Mi hai battuto!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "Ho letto che ce ne sono quattro,\n"
	.string "di quelle lastre di pietra.$"

