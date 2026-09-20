NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU è un POKéMON evoluto.\p"
	.string "Sono rimasta stupita dalle\n"
	.string "scoperte del PROF.ELM.\p"
	.string "È famoso per le sue ricerche\n"
	.string "sull'evoluzione dei POKéMON.\p"
	.string "…sigh…\p"
	.string "Vorrei fare la ricercatrice\n"
	.string "come lui…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Mia figlia vuole a tutti i costi\n"
	.string "fare l'assistente del PROF.ELM.\p"
	.string "Adora i POKéMON!\p"
	.string "Ma anche io!$"

