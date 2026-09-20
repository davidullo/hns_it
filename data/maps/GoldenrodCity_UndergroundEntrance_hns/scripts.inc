GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "Mi hanno sfidato a una lotta\n"
	.string "di sotto.\p"
	.string "È duro laggiù. Meglio\n"
	.string "che tu stia attento.$"


GoldenrodUnderground1_Text_Teacher:
	.string "Ci sono dei negozi di sotto…\n"
	.string "Ma anche degli allenatori.\p"
	.string "Ho paura a scendere.$"
