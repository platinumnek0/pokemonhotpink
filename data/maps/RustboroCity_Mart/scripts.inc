RustboroCity_Mart_MapScripts::
	.byte 0

RustboroCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartBasic
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartExpanded
	end

RustboroCity_Mart_EventScript_PokemartBasic::
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_PokemartExpanded::
	pokemart RustboroCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_PokefanF::
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy::
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher::
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
	.string "I'm buying some PARLYZ HEALS and\n"
	.string "ANTIDOTES.\p"
	.string "Just in case I run into SHROOMISH\n"
	.string "in PETALBURG WOODS.$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
	.string "My POKéMON evolved.\n"
	.string "It has a lot of HP now.\p"
	.string "I should buy SUPER POTIONS for it\n"
	.string "instead of ordinary POTIONS.$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
	.string "I'm getting an ESCAPE ROPE just in\n"
	.string "case I get lost in a cave.\p"
	.string "I just need to use it to get back to\n"
	.string "the entrance.$"

rustboroMart_baloomGift::
	call_if_unset 0x26A, determineBaloomType
	goto_if_unset 0x269, baloomGift_preGift
	goto_if_set 0x269, baloomGift_postGiftText
	return


determineBaloomType::
	random 4
	switch VAR_RESULT
	case ( 0 ), determineBaloomType_3
	case ( 1 ), determineBaloomType_4
	case ( 2 ), determineBaloomType_5
	case ( 3 ), determineBaloomType_6
determineBaloomType_1:
	setflag 0x26A
	return

determineBaloomType_3:
	setvar VAR_UNUSED_0x404E, 0
	goto determineBaloomType_1

determineBaloomType_4:
	setvar VAR_UNUSED_0x404E, 1
	goto determineBaloomType_1

determineBaloomType_5:
	setvar VAR_UNUSED_0x404E, 2
	goto determineBaloomType_1

determineBaloomType_6:
	setvar VAR_UNUSED_0x404E, 3
	goto determineBaloomType_1


baloomGift_postGiftText::
	lockall
	msgbox baloomGift_postGiftText_Text_0
	releaseall
	return


baloomGift_preGift::
	goto_if_set 0x268, baloomGift_amiiboFlagSet
	goto_if_unset 0x268, baloomGift_amiiboFlagNotSet
	return


baloomGift_amiiboFlagNotSet::
	lockall
	msgbox baloomGift_amiiboFlagNotSet_Text_0
	msgbox baloomGift_amiiboFlagNotSet_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq baloomGift_noText
	msgbox baloomGift_amiiboFlagNotSet_Text_2, MSGBOX_DEFAULT
	releaseall
	return


baloomGift_noText::
	msgbox baloomGift_noText_Text_0
	msgbox amiiboMemory
	releaseall
	return


baloomGift_amiiboFlagSet::
	msgbox baloomGift_amiiboFlagSet_Text_0
	applymovement 5, exclamation
	msgbox baloomGift_amiiboFlagSet_Text_1
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq baloomGift_partyFull
	applymovement 5, shuffle
	msgbox amiiboTransfer
	msgbox baloomGift_amiiboFlagSet_Text_2
	switch VAR_UNUSED_0x404E
	case ( 0 ), baloomGift_amiiboFlagSet_3
	case ( 1 ), baloomGift_amiiboFlagSet_4
	case ( 2 ), baloomGift_amiiboFlagSet_5
	case ( 3 ), baloomGift_amiiboFlagSet_6
baloomGift_amiiboFlagSet_1:
	playfanfare MUS_OBTAIN_ITEM
	msgbox baloomGift_amiiboFlagSet_Text_3
	waitfanfare
	msgbox baloomGift_amiiboFlagSet_Text_4
	setflag 0x269
	releaseall
	return

baloomGift_amiiboFlagSet_3:
	givemon SPECIES_FLABEBE_YELLOW_FLOWER, 7, ITEM_NONE
	goto baloomGift_amiiboFlagSet_1

baloomGift_amiiboFlagSet_4:
	givemon SPECIES_FLABEBE_ORANGE_FLOWER, 7, ITEM_NONE
	goto baloomGift_amiiboFlagSet_1

baloomGift_amiiboFlagSet_5:
	givemon SPECIES_FLABEBE_WHITE_FLOWER, 7, ITEM_NONE
	goto baloomGift_amiiboFlagSet_1

baloomGift_amiiboFlagSet_6:
	givemon SPECIES_FLABEBE_BLUE_FLOWER, 7, ITEM_NONE
	goto baloomGift_amiiboFlagSet_1


baloomGift_partyFull::
	msgbox baloomGift_partyFull_Text_0
	releaseall
	return


shuffle:
	walk_in_place_right
	walk_in_place_right
	step_end

rustbotoMart_gamerGuy::
	lockall
	goto_if_set 0x26A, gameText
	call_if_unset 0x26A, determineBaloomType
	applymovement 4, exclamation
	waitmovement 4
	faceplayer
	msgbox rustbotoMart_gamerGuy_Text_0
	goto gameText
	return


gameText::
	msgbox gameText_Text_0
	switch VAR_UNUSED_0x404E
	case ( 0 ), gameText_3
	case ( 1 ), gameText_4
	case ( 2 ), gameText_5
	case ( 3 ), gameText_6
gameText_1:
	release
	releaseall
	return

gameText_3:
	msgbox gameText_Text_1
	goto gameText_1

gameText_4:
	msgbox gameText_Text_2
	goto gameText_1

gameText_5:
	msgbox gameText_Text_3
	goto gameText_1

gameText_6:
	msgbox gameText_Text_4
	goto gameText_1


baloomGift_postGiftText_Text_0:
	.string "Hope you enjoy the gift!\p"
	.string "Be sure to tell all your friends\nabout it!$"

baloomGift_amiiboFlagNotSet_Text_0:
	.string "Welcome to the PokéMart, how can I\nhelp you today?$"

baloomGift_amiiboFlagNotSet_Text_1:
	.string "Have you heard about our special\noffer?$"

baloomGift_amiiboFlagNotSet_Text_2:
	.string "Great! If you have any Amiibos we can\nscan, be sure to bring them by!$"

baloomGift_noText_Text_0:
	.string "Well!\p"
	.string "We're holding a special offer for\nthis weekend only!\p"
	.string "If you come in with an Amiibo, we'll\n"
	.string "scan it and gift you a free Pokémon!$"

baloomGift_amiiboFlagSet_Text_0:
	.string "Welcome to the PokéMart, how c-$"

baloomGift_amiiboFlagSet_Text_1:
	.string "Wowie Zowie!\pYou have an Amiibo?!\pLucky for you, we have a special deal\ngoing on!\pJust let me scan it, aaaand...$"

baloomGift_amiiboFlagSet_Text_2:
	.string "Theeere we go! And here you are!$"

baloomGift_amiiboFlagSet_Text_3:
	.string "You got a Baloom!$"

baloomGift_amiiboFlagSet_Text_4:
	.string "Enjoy the gift!$"

baloomGift_partyFull_Text_0:
	.string "Hmmm... looks like your party's full.\pSorry, if you want the gift, you need\nan empty slot.\pWe can't access trainers' PCs to make\ndeposits.$"

rustbotoMart_gamerGuy_Text_0:
	.string "HEY! Go away!\pCan't you see I'm busy here!?$"

gameText_Text_0:
	.string "(He seems to be busy playing a game.)$"

gameText_Text_1:
	.string "(Whoever that character is, it seems\ntheir rocket just crashed...)$"

gameText_Text_2:
	.string "(Two characters are in a cave.)\p(That rock doesn't look safe...)$"

gameText_Text_3:
	.string "(Look at all those fruits!)\p(Must be a gardening game...)$"

gameText_Text_4:
	.string "(Some kind of timed challenge is\ngoing on.)\p(Better not interrupt...)$"

amiiboMemory::
	.string "(You remember your mom saying to check\nthat everything is on your desk...)$"

amiiboTransfer::
	.string "(You hand the clerk your Amiibo.)\p"
	.string "(He takes a scanner to the bottom of\nit.)$"
