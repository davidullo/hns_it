NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
    .string "Ciao, piccolino..\p"
	.string "Benvenuto nella...\n"
	.string "beh, chiamala biblioteca di Nuova Sinjoh.\p"
	.string "In realtà qui conserviamo tutti\n"
	.string "i documenti della storia del paese,\l"
	.string "e anche i libri che\l"
	.string "importiamo dalle altre regioni..$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "Tooor?$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
    .string "È stipato di antichi\n"
	.string "libri rilegati in pelle.\p"
	.string "La lingua è irriconoscibile.$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
    .string "È stipato di libri\n"
	.string "sui POKéMON.\p"
	.string "Questi sembrano più nuovi e noti.$"
