PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN è il nuovo\n"
	.string "CAPOPALESTRA della città.\p"
	.string "Credo abbia chiamato la famiglia da\n"
	.string "chissà quanto lontano.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Ho sfidato NORMAN una volta, ma, uff,\n"
	.string "era troppo forte.\p"
	.string "Come dire?\p"
	.string "Ho sentito che lui\n"
	.string "vive per i POKéMON.$"

