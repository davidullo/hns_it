MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Sembra che ci sia una voce su\n"
	.string "avvistamenti di POKéMON rari.\p"
	.string "Pare che provengano dalla\n"
	.string "GROTTA CAMBIANTE del PERCORSO 103.\p"
	.string "Forse varrebbe la pena per te\n"
	.string "indagare su questa voce.$"
