MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "Ho sentito che un GYARADOS rosso\n"
    .string "è apparso al LAGO.\p"
    .string "Strano, perché anche i GYARADOS\n"
    .string "normali sono rari in quel lago…$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "Il mio programma radio preferito? Direi\n"
    .string "MUSICA POKéMON.$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "Sento delle risate alla\n"
    .string "radio…\p"
    .string "Che brividi.$"
