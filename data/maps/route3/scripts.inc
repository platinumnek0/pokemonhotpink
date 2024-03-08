route3_MapScripts::
	.byte 0


randomTest::
	lockall
	msgbox randomTest_Text_0
	releaseall
	return


route3_eventScript_camperBattle::
	trainerbattle_single TRAINER_BEAU, route3_camperIntro, route3_camperDefeat
	lockall
	msgbox route3_camperPostbattle
	releaseall
	return


route3_eventScript_beautyBattle::
	trainerbattle_single TRAINER_MELISSA, route3_beautyIntro, route3_beautyDefeat
	lockall
	msgbox route3_beautyPostBattle
	releaseall
	return


route3_eventScript_lassBattle::
	trainerbattle_single TRAINER_JANICE, route3_lassIntro, route3_lassDefeat
	lockall
	msgbox route3_lassPostBattle
	releaseall
	return


route3_eventScript_bugCatcherBattle::
	trainerbattle_single TRAINER_RICK, route3_catcherIntro, route3_catcherDefeat
	lockall
	msgbox route3_catcherPostBattle
	releaseall
	return


route3_eventScript_guy::
	msgbox route3_text_guy, MSGBOX_NPC
	return


randomTest_Text_0:
	.string "Trainer Tip!\pExplore every path you can in\na new location. You never know\lwhat you'll find!$"

route3_camperIntro::
	.string "First rule of the Berry Scout code:\nnever admit defeat!$"

route3_camperDefeat::
	.string "…crap…$"

route3_camperPostbattle::
	.string "Uh… second rule of the Berry Scout\ncode… um… okay, I never paid\lattention.$"

route3_beautyIntro::
	.string "I'll wipe the floor with you!$"

route3_beautyDefeat::
	.string "You CANNOT be serious right now.$"

route3_beautyPostBattle::
	.string "Whatever you did to win, don't even tell\nme.$"

route3_lassIntro::
	.string "Hey! You! Look at this!$"

route3_lassDefeat::
	.string "Maybe next time…$"

route3_lassPostBattle::
	.string "Okay so maybe I messed up.\pBut I'll get it right, I swear!$"

route3_catcherIntro::
	.string "Well, well, well, what do we have here?$"

route3_catcherDefeat::
	.string "Stomped!$"

route3_catcherPostBattle::
	.string "If I could call up my buddy, your team\nwould be splattered in a second!$"

route3_text_guy::
	.string "Hey, don't tell that Bug Catcher over\nhere, but uh…\pI think I'm a little lost.$"
