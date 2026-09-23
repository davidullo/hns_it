CeladonCity_DepartmentStore_5F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_XItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_XItems::
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Vitamins::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers::
	.string "Gli integratori POKéMON si\n"
	.string "comprano solo qui.\p"
	.string "PS SU aumenta i PS base di un\n"
	.string "POKéMON.\p"
	.string "Il CALCIO alza l'ATT. SPEC.\n"
	.string "base di un POKéMON.\p"
	.string "Lo ZINCO alza la DIF. SPEC. base\n"
	.string "di un POKéMON.\p"
	.string "Il CARBURANTE alza la VELOCITÀ\n"
	.string "base.$"

CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers::
	.string "Cerco integratori per\n"
	.string "POKéMON.\p"
	.string "La PROTEINA alza l'ATTACCO\n"
	.string "base.\p"
	.string "Il FERRO alza la DIFESA\n"
	.string "base.$"

CeladonCity_DepartmentStore_5F_Text_Drugstore::
	.string "5P: FARMACIA$"

