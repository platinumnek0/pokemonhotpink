forestEggRoom_MapScripts::
	.byte 0


forestEggRoom_EventScript_eggMan::
	lockall
	call_if_set 0x267, forestEggRoom_EventScript_noMan
	call_if_unset 0x267, forestEggRoom_EventScript_giveEgg
	releaseall
	return


forestEggRoom_EventScript_giveEgg::
	msgbox forestEggRoom_EventScript_giveEgg_Text_0
	giveitem ITEM_LUCKY_EGG
	setflag 0x267
	return


forestEggRoom_EventScript_noMan::
	msgbox forestEggRoom_EventScript_noMan_Text_0
	return


forestEggRoom_EventScript_giveEgg_Text_0:
	.string "There is a man here.\nHe has an item to give you.$"

forestEggRoom_EventScript_noMan_Text_0:
	.string "There is no longer a man here.$"
