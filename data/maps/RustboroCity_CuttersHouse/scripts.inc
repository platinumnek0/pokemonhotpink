RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"

porkbelly_cutter::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, porkbelly_cutter_hasCut
	applymovement 1, exclamation
	msgbox porkbelly_cutter_Text_0
	waitmessage
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox porkbelly_cutter_Text_1
	msgbox porkbelly_cutter_Text_2
	release
	releaseall
	return


porkbelly_cutter_hasCut::
	msgbox porkbelly_cutter_hasCut_Text_0
	release
	releaseall
	return


porkbelly_cutterHouse_caution::
	lockall
	faceplayer
	msgbox porkbelly_cutterHouse_caution_Text_0
	release
	releaseall
	return


porkbelly_cutter_Text_0:
	.string "You!\pTake this!$"

porkbelly_cutter_Text_1:
	.string "Ya see those thin scraggly trees\naround?\pUse this to cut 'em down.\pThey grow back quick, though- they won't\nstay down forever.$"

porkbelly_cutter_Text_2:
	.string "Oh!\pAlso, if ya don't got it already, you'll\nneed the Test Badge from the gym here\lin Porkbelly to use it.$"

porkbelly_cutter_hasCut_Text_0:
	.string "To use Cut outside battle, you need the\nTest Badge from the gym here.$"

porkbelly_cutterHouse_caution_Text_0:
	.string "Be careful using Cut.\pSometimes, Pokémon disguise themselves\nas trees.$"
