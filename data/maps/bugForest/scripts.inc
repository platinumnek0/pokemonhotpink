bugForest_MapScripts::
	.byte 0


bugForest_EventScript_IntroSign::
	lockall
	msgbox bugForest_EventScript_IntroSign_Text_0
	releaseall
	return


bugForest_EventScript_trainerTip::
	lockall
	msgbox bugForest_EventScript_trainerTip_Text_0
	releaseall
	return


bugForest_EventScript_fatGuy::
	lockall
	faceplayer
	msgbox bugForest_EventScript_fatGuy_Text_0
	release
	releaseall
	return


bugForest_EventScript_rockGuy::
	lockall
	faceplayer
	msgbox bugForest_EventScript_rockGuy_Text_0
	release
	releaseall
	return


bugForest_EventScript_lassBattle::
	trainerbattle_single TRAINER_HALEY_1, bugf_lass_intro, bugf_lass_defeat
	lockall
	msgbox bugf_lass_postbattle
	releaseall
	end


bugForest_EventScript_youngsterBattle::
	trainerbattle_single TRAINER_BILLY, bugf_youngster_intro, bugf_youngster_defeat
	lockall
	msgbox bugf_youngster_postbattle
	releaseall
	end


bugForest_EventScript_camperBattle::
	trainerbattle_single TRAINER_DREW, bugf_camper_intro, bugf_camper_defeat
	lockall
	msgbox bugf_camper_postbattle
	releaseall
	end


bugForest_EventScript_picnickerBattle::
	trainerbattle_single TRAINER_AUTUMN, bugf_picnicker_intro, bugf_picnicker_defeat
	lockall
	msgbox bugf_picnicker_postbattle
	releaseall
	end


bugForest_eventScript_gentlemanBattle::
	trainerbattle_single TRAINER_WALTER_1, bugf_gentleman_intro, bugf_gentleman_defeat
	lockall
	msgbox bugf_gentleman_postbattle
	releaseall
	end


martEventIntro::
	lockall
	applymovement 8, martTurnAround
	waitmovement 8
	msgbox martEventIntro_Text_0
	waitmessage
	applymovement 8, exclamation
	waitmovement 8
	return


martTurnAround:
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	step_end

exclamation:
	emote_exclamation_mark
	delay_16
	face_player
	step_end

martApproach_bottom_left:
	walk_down
	walk_down
	step_end

martApproach_bottom_right:
	walk_right
	walk_down
	walk_down
	step_end

martApproach_east_top:
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

martApproach_east_bottom:
	walk_right
	walk_right
	walk_right
	step_end

martEventGift::
	msgbox martEventGift_Text_0
	applymovement 8, exclamation
	msgbox martEventGift_Text_1
	giveitem ITEM_OLD_ROD
	setvar VAR_UNUSED_0x408B, 1
	msgbox martEventGift_Text_2
	applymovement 8, martTurnAround
	waitmovement 8
	faceplayer
	msgbox martEventGift_Text_3
	return


martLeave_bottom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

martLeave_east:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

bugForest_EventScript_martEvent_bottomLeft::
	call martEventIntro
	applymovement 8, martApproach_bottom_left
	waitmovement 8
	call martEventGift
	applymovement 8, martLeave_bottom
	waitmovement 8
	releaseall
	removeobject 8
	setflag 0x264
	return


bugForest_EventScript_martEvent_bottomRight::
	call martEventIntro
	applymovement 8, martApproach_bottom_right
	waitmovement 8
	call martEventGift
	applymovement 8, martLeave_bottom
	waitmovement 8
	releaseall
	removeobject 8
	setflag 0x264
	return


bugForest_EventScript_martEvent_eastTop::
	call martEventIntro
	applymovement 8, martApproach_east_top
	waitmovement 8
	call martEventGift
	applymovement 8, martLeave_east
	waitmovement 8
	releaseall
	removeobject 8
	setflag 0x264
	return


bugForest_EventScript_martEvent_eastBottom::
	call martEventIntro
	applymovement 8, martApproach_east_bottom
	waitmovement 8
	call martEventGift
	applymovement 8, martLeave_east
	waitmovement 8
	releaseall
	removeobject 8
	setflag 0x264
	return


bugForest_EventScript_IntroSign_Text_0:
	.string "SUBFLORA WOODS\nWhere bugs skitter underfoot$"

bugForest_EventScript_trainerTip_Text_0:
	.string "Trainer Tips!\nIf you have a Fishing rod, don't forget\lto use it anytime you find a new body\lof water! You never know what you'll\lcatch!$"

bugForest_EventScript_fatGuy_Text_0:
	.string "Hey, kid! Word'a advice. You might wanna\ncarry some healing items like Potions\l'round here. The bugs 'n trainers can be\la little nasty...$"

bugForest_EventScript_rockGuy_Text_0:
	.string "Look at this rock. Wonderful, isn't it?\nI've done some testing. Most of its\lcomposition is minerals not seen in this\larea at ALL! Cool, right!?$"

martEventIntro_Text_0:
	.string "Man... nothing's biting today...$"

martEventGift_Text_0:
	.string "Oh! Didn't see you there!\nApologies, having some trouble catching\lanything today. Name's Martin, I'm part\lof the Pokémon League.\pHaven't had much in way of battles\nlately, so figured I'd pop by the pond\lhere for some fishing.$"

martEventGift_Text_1:
	.string "Hey! You have a Pokédex? Sweet! Here,\nyou'll probably have better luck with\lthis than I've had.$"

martEventGift_Text_2:
	.string "That's an Old Rod. It might not be the\nbest, but it's sure as hell reliable.\lGive it a try when you come across some\lwater.$"

martEventGift_Text_3:
	.string "I should get going. Sorry this was so...\nout of the blue. Enjoy the rod!$"

bugf_lass_intro::
	.string "Lucky number 7, comin' in hot!$"

bugf_lass_defeat::
	.string "Six in a row, and I lose number 7...\ntypical.$"

bugf_lass_postbattle::
	.string "I got this, just you see, I'll win TEN in\na row!$"

bugf_youngster_intro::
	.string "Look at my incredible team!$"

bugf_youngster_defeat::
	.string "That loss was uncanny!$"

bugf_youngster_postbattle::
	.string "Your team is incredible!$"

bugf_camper_intro::
	.string "Ooey gooey gloopy- that's how I like it!$"

bugf_camper_defeat::
	.string "Am I not strong enough?$"

bugf_camper_postbattle::
	.string "Gloopy and gross mons are cool! You just\ndon't get it...$"

bugf_picnicker_intro::
	.string "Alright! Let's go!$"

bugf_picnicker_defeat::
	.string "...that didn't go to plan.$"

bugf_picnicker_postbattle::
	.string "So what if I lost?$"

bugf_gentleman_intro::
	.string "You look like you can't carry\nwood or you'll stumble!$"

bugf_gentleman_defeat::
	.string "Maybe I am full of fleast after\nall...$"

bugf_gentleman_postbattle::
	.string "I've gotta admit, kid, you're\npretty humble!$"
