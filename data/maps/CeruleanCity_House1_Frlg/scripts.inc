CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
	lock
	faceplayer
	msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
	message CeruleanCity_House1_Text_DescribeWhichBadge
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BADGES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
	case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
	case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
	case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
	case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
	case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
	case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
	case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
	case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
	case 127, CeruleanCity_House1_EventScript_StopDescribingBadges
	end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
	msgbox CeruleanCity_House1_Text_AttackStatFlash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv30Cut
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
	msgbox CeruleanCity_House1_Text_SpeedStatFly
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv50Strength
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
	msgbox CeruleanCity_House1_Text_DefenseStatSurf
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv70RockSmash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
	msgbox CeruleanCity_House1_Text_SpStatsWaterfall
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
	msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_StopDescribingBadges::
	msgbox CeruleanCity_House1_Text_ComeVisitAnytime
	release
	end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
	.string "Solo gli ALLENATORI esperti\n"
	.string "le ottengono.\p"
	.string "Ne vedo almeno una.\p"
	.string "Quelle MEDAGLIE nascondono\n"
	.string "segreti, sai?$"

CeruleanCity_House1_Text_DescribeWhichBadge::
	.string "Allora…\p"
	.string "Quale delle otto MEDAGLIE\n"
	.string "descrivo?$"

CeruleanCity_House1_Text_ComeVisitAnytime::
	.string "Vieni a trovarmi quando vuoi.$"

CeruleanCity_House1_Text_AttackStatFlash::
	.string "L'ATTACCO di tutti i tuoi\n"
	.string "POKéMON aumenta un po'.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare BALENO.$"

CeruleanCity_House1_Text_ObeyLv30Cut::
	.string "I POKéMON fino al liv. 30\n"
	.string "ti ubbidiranno.\p"
	.string "Anche quelli ottenuti\n"
	.string "negli scambi.\p"
	.string "Quelli di livello più alto\n"
	.string "in lotta saranno ribelli.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare TAGLIO.$"

CeruleanCity_House1_Text_SpeedStatFly::
	.string "La VELOCITÀ di tutti i\n"
	.string "tuoi POKéMON aumenta un po'.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare VOLO.$"

CeruleanCity_House1_Text_ObeyLv50Strength::
	.string "I POKéMON fino al liv. 50\n"
	.string "ti ubbidiranno.\p"
	.string "Anche quelli ottenuti\n"
	.string "negli scambi.\p"
	.string "Quelli di livello più alto\n"
	.string "in lotta saranno ribelli.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare FORZA.$"

CeruleanCity_House1_Text_DefenseStatSurf::
	.string "La DIFESA di tutti i tuoi\n"
	.string "POKéMON aumenta un po'.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare SURF.$"

CeruleanCity_House1_Text_ObeyLv70RockSmash::
	.string "I POKéMON fino al liv. 70\n"
	.string "ti ubbidiranno.\p"
	.string "Anche quelli ottenuti\n"
	.string "negli scambi.\p"
	.string "Quelli di livello più alto\n"
	.string "in lotta saranno ribelli.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare SPACCAROCCIA.$"

CeruleanCity_House1_Text_SpStatsWaterfall::
	.string "ATT. SPEC. e DIF. SPEC. dei\n"
	.string "tuoi POKéMON salgono un po'.\p"
	.string "Inoltre, fuori dalla lotta\n"
	.string "puoi usare CASCATA.$"

CeruleanCity_House1_Text_AllMonsWillObeyYou::
	.string "Ogni POKéMON ti ubbidirà!$"

