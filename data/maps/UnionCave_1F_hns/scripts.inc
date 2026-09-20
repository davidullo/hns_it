UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "Vai ad AZALEA, eh?\p"
	.string "Fai vedere ai miei POKéMON se sei\n"
	.string "all'altezza di lottare.$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "Oh, oh, oh!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "Va bene, allora! Ho deciso.\p"
	.string "Non me ne vado finché i miei POKéMON\n"
	.string "non saranno più forti!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Vago in lungo e in largo in cerca di\n"
	.string "POKéMON.\p"
	.string "Anche tu cerchi POKéMON?\p"
	.string "Allora sei il mio rivale!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "Uff. I miei poveri POKéMON…$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "A volte senti i versi dei POKéMON\n"
	.string "dal profondo della grotta.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "Caspita! Che sorpresa!\p"
	.string "Non pensavo di trovare qualcuno qui!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "Caspita! Mi hai battuto alla grande!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "Mi hanno truffato facendomi comprare\n"
	.string "una CODA DI SLOWPOKE.\p"
	.string "Mi dispiace per quel povero POKéMON.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "SUPERSONO dei ZUBAT confonde\n"
	.string "i miei POKéMON.\p"
	.string "Sono davvero arrabbiato!$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "Mi sono spento!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Nei weekend si sentono strani\n"
	.string "ruggiti dal fondo della grotta.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "Con la luce, una grotta non fa paura.\p"
	.string "Se sei forte, i POKéMON non\n"
	.string "fanno paura.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "FLASH$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "È il fuoco dei miei POKéMON che\n"
	.string "illumina questa grotta.$"
