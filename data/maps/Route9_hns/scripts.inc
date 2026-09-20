Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "Sono venuto a esplorare la TUNNEL ROCCIOSO.$"

Route9_Text_CamperDeanBeaten:
	.string "Whoa! Pericolo, amico.$"

Route9_Text_CamperDeanAfter:
	.string "I miei POKéMON erano feriti prima\n"
	.string "di entrare nel TUNNEL ROCCIOSO.\p"
	.string "Meglio portarli subito al CENTRO\n"
	.string "POKéMON.$"

Route9_Text_PicnickerHeidiSeen:
	.string "Sei mai stato a un picnic?\p"
	.string "Sono divertentissimi!$"

Route9_Text_PicnickerHeidiBeaten:
	.string "Oooh!$"

Route9_Text_PicnickerHeidiAfter:
	.string "Prepariamo tante leccornie e le\n"
	.string "dividiamo con tutti.\p"
	.string "Sono deliziose!$"

Route9_Text_CamperSidSeen:
	.string "Ehi, tu! Non sporcare!$"

Route9_Text_CamperSidBeaten:
	.string "Volevo solo farti notare…$"

Route9_Text_CamperSidAfter:
	.string "Scusa. Non stavi sporcando.\n"
	.string "È stato un mio errore.$"

Route9_Text_PicnickerEdnaSeen:
	.string "Non si dovrebbe lasciare in giro\n"
	.string "immondizia.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "Ohh… ho perso…$"

Route9_Text_PicnickerEdnaAfter:
	.string "Risparmiare energia è importante,\n"
	.string "ma l'ambiente lo è\l"
	.string "ancora di più.$"

Route9_Text_HikerTimSeen:
	.string "Tornerà girando per MT.SILVER\n"
	.string "quando verrà…\p"
	.string "MT.SILVER è a JOHTO, vero?$"

Route9_Text_HikerTimBeaten:
	.string "Ero troppo impegnato a cantare…$"

Route9_Text_HikerTimAfter:
	.string "Nelle lotte conta la concentrazione.$"

Route9_Text_HikerSidneySeen:
	.string "Ti svelo un segreto.\p"
	.string "Ma prima, lottiamo!$"

Route9_Text_HikerSidneyBeaten:
	.string "Oh, no! Ho perso…$"

Route9_Text_HikerSidneyAfter:
	.string "La CENTRALE è oltre un piccolo\n"
	.string "fiume.$"

Route9_Text_Sign:
	.string "PERCORSO 9\p"
	.string "CELESTOPOLI - TUNNEL ROCCIOSO$"
