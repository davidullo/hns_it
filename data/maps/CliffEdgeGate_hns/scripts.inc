CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Lo sapevi? La ZONA SAFARI è\n"
	.string "proprio qui vicino.\p"
	.string "È divertente!\n"
	.string "Vedrai POKéMON di ogni tipo,\l"
	.string "puoi catturarne quanti vuoi!\p"
	.string "Non hai motivo di non andarci, no?\n"
	.string "Proprio qui vicino.$"

CliffEdgeGate_Text_Expectations:
	.string "So che tutti lo aspettano\n"
	.string "con ansia.\p"
	.string "Ma la signora alla reception\n"
	.string "è troppo teatrale…\p"
	.string "Non farti troppe illusioni!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Che emozione!\n"
	.string "Esplora e trova POKéMON!\l"
	.string "La ZONA SAFARI di BAOBA\l"
	.string "è aperta!$"

