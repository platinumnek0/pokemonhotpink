firstGymTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, porkbellyOnTransition
	.byte 0


porkbelly_eventScript_gymSign::
	msgbox johnnyGymSign MSGBOX_SIGN
	return


porkbelly_eventScript_townSign::
	msgbox porkbellySign, MSGBOX_SIGN
	return


porkbelly_eventScript_preventExit_west::
	lockall
	applymovement 3, exclamation
	applymovement 3, porkbellyGuyLookDown
	msgbox porkbelly_eventScript_preventExit_west_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, porkbellyStepBack
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox porkbelly_eventScript_preventExit_west_Text_1
	applymovement 3, porkbellyGuyLookLeft
	releaseall
	return


porkbellyGuyLookDown:
	face_down
	step_end

porkbellyStepBack:
	walk_right
	face_left
	step_end

porkbellyGuyLookLeft:
	face_left
	step_end

porkbelly_eventScript_preventExit_north::
	lockall
	applymovement 4, porkbellyHiker_turnAndSpeak
	msgbox porkbelly_eventScript_preventExit_north_Text_0
	waitmessage
	applymovement 6, porkbellyGentleman_turnAndSpeak
	msgbox porkbelly_eventScript_preventExit_north_Text_1
	waitmessage
	applymovement 4, porkbellyHiker_turnAndSpeak
	msgbox porkbelly_eventScript_preventExit_north_Text_2
	waitmessage
	msgbox porkbelly_eventScript_preventExit_north_Text_3
	releaseall
	return


porkbellyHiker_turnAndSpeak:
	face_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	step_end

porkbellyGentleman_turnAndSpeak:
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

porkbelly_eventScript_politicsBear::
	lockall
	msgbox politicsBearText, MSGBOX_NPC
	release
	releaseall
	return


porkbellyRoute4Block::
	lockall
	applymovement 9, exclamation
	applymovement 9, route4blockadeFaceRight
	waitmovement 9
	msgbox porkbellyRoute4Block_Text_0
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, playerStepUp1
	msgbox porkbellyRoute4Block_Text_1
	releaseall
	return


route4blockadeFaceRight:
	walk_in_place_right
	walk_in_place_right
	step_end

playerStepUp1:
	walk_up
	face_down
	step_end

porkbellyRoute4IsBlocked::
	lockall
	faceplayer
	msgbox porkbellyRoute4IsBlocked_Text_0
	release
	releaseall
	return


porkbellyRoute4IsNotBlocked::
	lockall
	faceplayer
	msgbox porkbellyRoute4IsNotBlocked_Text_0
	release
	releaseall
	return


porkbellyRoute4Guy::
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 0, porkbellyRoute4IsBlocked
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 1, porkbellyRoute4IsNotBlocked
	return


porkbellyGymClearToggle::
	lockall
	switch VAR_RUSTBORO_CITY_STATE
	case ( 0 ), porkbellyGymClearToggle_3
	case ( 1 ), porkbellyGymClearToggle_4
porkbellyGymClearToggle_1:
	releaseall
	return

porkbellyGymClearToggle_3:
	setvar VAR_RUSTBORO_CITY_STATE, 1
	msgbox porkbellyGymClearToggle_Text_0
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	goto porkbellyGymClearToggle_1

porkbellyGymClearToggle_4:
	setvar VAR_RUSTBORO_CITY_STATE, 0
	msgbox porkbellyGymClearToggle_Text_1
	clearflag FLAG_DEFEATED_RUSTBORO_GYM
	goto porkbellyGymClearToggle_1


setGymToClear::
	setvar VAR_RUSTBORO_CITY_STATE, 1
	return


setGymToUnclear::
	setvar VAR_RUSTBORO_CITY_STATE, 0
	return


porkbellyMoveRoadblock::
	setobjectxyperm 9, 25, 49
	return


porkbellyOnTransition::
	call_if_unset FLAG_DEFEATED_RUSTBORO_GYM, porkbellyMoveRoadblock
	call_if_unset FLAG_DEFEATED_RUSTBORO_GYM, porkbellyHideKanny
	call_if_set FLAG_DEFEATED_RUSTBORO_GYM, porkbellyShowKanny
	return


porkbellyHideKanny::
	setflag FLAG_UNUSED_0x493
	return


porkbellyShowKanny::
	clearflag FLAG_UNUSED_0x493
	return


porkbellyKannyAppearance::
	lockall
	setvar VAR_RUSTBORO_CITY_STATE, 2
	applymovement 10, kannyEntrance
	waitmovement 10
	applymovement OBJ_EVENT_ID_PLAYER, playerLookDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox kannyEncounter1
	msgbox kannyEncounterYesNo, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq porkbellyKannyAppearanceNo
	msgbox kannyEncounterYes, MSGBOX_AUTOCLOSE
	applymovement 10, kannyLeave
	waitmovement 10
	removeobject 10
	releaseall
	return


porkbellyKannyAppearanceNo::
	applymovement 10, exclamation
	msgbox kannyEncounterNo, MSGBOX_AUTOCLOSE
	applymovement 10, kannyLeave
	waitmovement 10
	removeobject 10
	releaseall
	return


kannyEntrance:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

kannyLeave:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

playerLookDown:
	face_down
	step_end

porkbelly_eventScript_preventExit_west_Text_0:
	.string "Woah woah woah!\pI can't let ya through here, kid.$"

porkbelly_eventScript_preventExit_west_Text_1:
	.string "Somethin' happened up on Mt. Bighair,\n'n there was a big rockslide all over\lRoute 6.\pMe 'n my buddies are try'n'a clear it all\nout.\pBut til then, no one can pass.$"

porkbelly_eventScript_preventExit_north_Text_0:
	.string "So then I says, I says…$"

porkbelly_eventScript_preventExit_north_Text_1:
	.string "Well?$"

porkbelly_eventScript_preventExit_north_Text_2:
	.string "Well, then I turns to her, and I says,\nI says…\p“'ey! You!”$"

porkbelly_eventScript_preventExit_north_Text_3:
	.string "(You have a feeling this is going to go\non for a while.)$"

porkbellyRoute4Block_Text_0:
	.string "Hey! I can't let you past!$"

porkbellyRoute4Block_Text_1:
	.string "There's been reports of strange\nPokémon attacking people!\pI don't know how true it is…\nBut I'm not letting you through!\lI don't wanna get a kid hurt!\l…potentially!$"

porkbellyRoute4IsBlocked_Text_0:
	.string "I've heard there have been some Pokémon\nattacks on Route 4.\pThe descriptions don't match anything\nI've heard…\lBut, best to be safe.$"

porkbellyRoute4IsNotBlocked_Text_0:
	.string "Did you see it!?\nDid you really see it!?\lThat strange Pokémon!?\pThat must've been CRAZY!$"

porkbellyGymClearToggle_Text_0:
	.string "Set gym to CLEARED.$"

porkbellyGymClearToggle_Text_1:
	.string "Set gym to NOT CLEARED.$"

johnnyGymSign::
	.string "Porkbelly Gym\nLeader: Johnny\l“The New Trainer's First Test”$"

porkbellySign::
	.string "PORKBELLY\n“A town that's never boar-ing”$"

politicsBearText::
	.string "The old League Champion had to step down\nrecently.\p"
	.string "Since then Chairman Kanny's been trying\nto recruit a new one.\p"
	.string "So technically, we don't even have a\nChampion right now.\p"
	.string "Thaaaaat's politics!$"

kannyEncounter1::
	.string "Well! That was some, er, mighty\nimpressive fightin' back there, eh?\p"
	.string "The Gagil League streams Gym battles,\ner, uh, online, that's how I saw.\p"
	.string "You must be wonderin' who I am.\p"
	.string "I'm the, er, Chairman of the Gagil\nPokémon League.\lMy name's Gregory, but you can just\lcall me, er, uh, Chairman Kanny.\p"
	.string "Say, kid.\p"
	.string "We've been having some, er, legal\nissues, with the League lately.\lThe last Champ resigned, and we uh,\lhaven't been able to find a suitable,\ler, replacement.\p"
	.string "Howzabout YOU step up ta bat?$"

kannyEncounterYesNo::
	.string "Whaddaya say, kid?$"

kannyEncounterYes::
	.string "Now that's what I like ta hear!\p"
	.string "You've already got, er, one down,\ndon't ya?\p"
	.string "That means ya got seven ta go.\nThe next gym should be, er, just west\lof Beaston.\lIt's in Hamborough.\p"
	.string "I'll, er, uh, catch up ta you there\nafter that battle, alright?\p"
	.string "…by the way, I just realized.\lI never, er, got your name, did I?\p"
	.string "{PLAYER}?\p"
	.string "Well then, {PLAYER}, I'll see ya in,\ner, a while, yeah?\p"
	.string "Good luck!$"

kannyEncounterNo::
	.string "What!?\p"
	.string "Come on, you can't be tellin' me now\nthat you, um, don't like battlin'\llike that.\p"
	.string "Tell ya what, kid.\p"
	.string "You give the, er, Gym over in\nHamborough a roughin' up.\p"
	.string "I'll stop by after the battle to\ncheck up on ya.\p"
	.string "Sound good?\nGreat!\p"
	.string "Well, be, er, seein' ya, kid!$"
