MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "By holding this WONDER CARD, you\n"
	.string "may take part in a survey at a\l"
	.string "POKéMON MART.\p"
	.string "Use these surveys to invite\n"
	.string "TRAINERS to SOOTOPOLIS CITY.\p"
	.string "…Let me give you a secret\n"
	.string "password for a survey:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Write that in on a survey and send\n"
	.string "it to the WIRELESS\l"
	.string "COMMUNICATION SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Un ALLENATORE è arrivato a\n"
	.string "CENGIA CIELO in cerca di te.\p"
	.string "Speriamo che ti piaccia\n"
	.string "sfidare l'ALLENATORE in visita.\p"
	.string "Puoi invitare altri ALLENATORI\n"
	.string "inserendo altre password.\p"
	.string "Prova a cercare altre password\n"
	.string "che potrebbero funzionare.$"
