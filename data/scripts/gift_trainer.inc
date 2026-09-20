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
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Con questa CARTA MAGICA puoi\n"
	.string "partecipare a un sondaggio in un\l"
	.string "SUPERMERCATO POKéMON.\p"
	.string "Usa i sondaggi per invitare\n"
	.string "ALLENATORI a CENGIA CIELO.\p"
	.string "…Ti do una password\n"
	.string "segreta per un sondaggio:\p"
	.string "“DAMMI UN\n"
	.string "ALLENATORE FANTASTICO”\p"
	.string "Scrivila in un sondaggio e inviala\n"
	.string "al sistema di COMUNICAZIONE\l"
	.string "SENZA FILI.$"

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
