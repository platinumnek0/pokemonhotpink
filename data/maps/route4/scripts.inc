route4_MapScripts::
	.byte 0


route4_walkDown_left::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_left
	goto route4_stellaLookAround
	return


route4_walkDown_middle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_middle
	goto route4_stellaLookAround
	return


route4_walkDown_right::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_right
	goto route4_stellaLookAround
	return


route4_stellaLookAround::
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 2, route4_stellaLooking
	waitmovement 2
	msgbox route4_stellaLookAround_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 2, route4_stellaLooking
	waitmovement 2
	applymovement 2, route4_stellaSurprise
	waitmovement 2
	applymovement 2, route4_stellaWalkUp
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerLookRight
	msgbox route4_stellaLookAround_Text_1, MSGBOX_AUTOCLOSE
	goto route4_starterBattleIntro
	return


route4_starterBattleIntro::
	waitmessage
	special HealPlayerParty
	msgbox route4_starterBattleIntro_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_RUSTBORO_CITY_STATE, 3
	setflag FLAG_DISABLE_RUNNING_AWAY
	applymovement 1, route4_starterWalkUp
	fadeoutbgm 1
	waitmovement 1
	applymovement 2, route4_stellaLookDownShocked
	applymovement OBJ_EVENT_ID_PLAYER, route4_stellaLookDownShocked
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox route4_starterBattleIntro_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 1, route4_starterWalkUp
	waitmovement 1
	applymovement 1, route4_starterWalkLeft
	waitmovement 1
	applymovement 1, route_4_starterWalkRight
	waitmovement 1
	applymovement 1, route4_starterWalkLeft
	waitmovement 1
	msgbox route4_starterBattleIntro_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 1, route4_starterAttack
	waitmovement 1
	goto route4_starterBattleCommence
	return


route4_starterBattleCommence::
	switch VAR_STARTER_MON
	case ( 0 ), route4_starterBattleCommence_3
	case ( 1 ), route4_starterBattleCommence_4
	case ( 2 ), route4_starterBattleCommence_5
route4_starterBattleCommence_1:
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq route4_starterBattleCommence_6
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq route4_starterBattleCommence_7
	return

route4_starterBattleCommence_3:
	call route4_evoStarterBattle_croconut
	goto route4_starterBattleCommence_1

route4_starterBattleCommence_4:
	call route4_evoStarterBattle_skrappup
	goto route4_starterBattleCommence_1

route4_starterBattleCommence_5:
	call route4_evoStarterBattle_kitfisk
	goto route4_starterBattleCommence_1

route4_starterBattleCommence_6:
	goto route4_endCutscene
	return

route4_starterBattleCommence_7:
	goto route4_koFailsafe
	return


route4_endCutscene::
	setvar VAR_RUSTBORO_CITY_STATE, 4
	clearflag FLAG_DISABLE_RUNNING_AWAY
	setobjectxy 1, 16, 7
	setobjectxy 3, 17, 11
	setobjectxy 2, 17, 6
	applymovement 3, route4_scientist_walkUp
	waitmovement 3
	msgbox route4_endCutscene_Text_0, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 2, route4_stellaShuffle
	msgbox route4_endCutscene_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 3, route4_scientistShuffle
	msgbox route4_endCutscene_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 3, route4_scientistShuffle
	playfanfare MUS_OBTAIN_ITEM
	removeobject 1
	waitmovement 3
	applymovement 3, route4_scientistExit
	waitmovement 3
	removeobject 3
	applymovement 2, route4_stellaFaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerLookRight
	msgbox route4_endCutscene_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 2, route4_scientistExit
	waitmovement 2
	removeobject 2
	setflag FLAG_UNUSED_0x021
	releaseall
	return


route4_koFailsafe::
	setvar VAR_RUSTBORO_CITY_STATE, 3
	clearflag FLAG_DISABLE_RUNNING_AWAY
	releaseall
	return


route4_postKo_right::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_right
	goto route4_postKoRematch
	return


route4_postKo_left::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_left
	goto route4_postKoRematch
	return


route4_postKo_middle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route4_playerWalkDown_middle
	goto route4_postKoRematch
	return


route4_postKoRematch::
	setobjectxy 1, 16, 7
	setobjectxy 2, 17, 6
	setflag FLAG_DISABLE_RUNNING_AWAY
	applymovement 1, route4_starterAttack
	waitmovement 1
	goto route4_starterBattleCommence
	return


route4_evoStarterBattle_croconut::
	setwildbattle SPECIES_SANDILE, 10
	dowildbattle
	return


route4_evoStarterBattle_skrappup::
	setwildbattle SPECIES_FENNEKIN, 10
	dowildbattle
	return


route4_evoStarterBattle_kitfisk::
	setwildbattle SPECIES_LITTEN, 10
	dowildbattle
	return


route4_stellaLooking:
	walk_in_place_left
	walk_in_place_left
	walk_in_place_right
	walk_in_place_right
	step_end

route4_stellaSurprise:
	walk_in_place_up
	walk_in_place_up
	emote_exclamation_mark
	step_end

route4_playerLookRight:
	face_right
	step_end

route4_stellaWalkUp:
	walk_up
	walk_up
	face_left
	step_end

route4_stellaLookDownShocked:
	emote_exclamation_mark
	face_down
	step_end

route4_starterWalkUp:
	walk_up
	step_end

route4_starterWalkLeft:
	walk_left
	face_up
	delay_16
	step_end

route_4_starterWalkRight:
	walk_right
	face_up
	delay_16
	step_end

route4_starterAttack:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	delay_4
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_up
	step_end

route4_playerWalkDown_left:
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

route4_playerWalkDown_middle:
	walk_down
	walk_down
	walk_down
	step_end

route4_playerWalkDown_right:
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

route4_scientist_walkUp:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

route4_stellaShuffle:
	walk_in_place_down
	walk_in_place_down
	step_end

route4_scientistShuffle:
	walk_in_place_up
	walk_in_place_up
	step_end

route4_scientistExit:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

route4_stellaFaceLeft:
	face_left
	step_end

route4_stellaLookAround_Text_0:
	.string "I wonder where {PLAYER} is…$"

route4_stellaLookAround_Text_1:
	.string "THERE you are!\nI was starting to get worried!\pSoooo, I heard about your battle with\nJohnny!\lI bet you CRUSHED him, haha!\pOh!\nHey!\pWhy don't we have a battle?!$"

route4_starterBattleIntro_Text_0:
	.string "Here, I'll even heal your party so th-$"

route4_starterBattleIntro_Text_1:
	.string "U-u-umm…\n{PLAYER}…?$"

route4_starterBattleIntro_Text_2:
	.string "Wh… wh-what i-i-is THAT!?!$"

route4_endCutscene_Text_0:
	.string "Ah, apologies.\pThis one must've gotten out.$"

route4_endCutscene_Text_1:
	.string "U-uh-\pH-huh?! What!?$"

route4_endCutscene_Text_2:
	.string "I'll be taking this one back to the\nlab.\pAgain, my sincerest apologies.\nThings like this don't usually happen.$"

route4_endCutscene_Text_3:
	.string "I… u-um…\p… … …\p…I'm… g-going to… go t-tell Dad.\nA-about this.\lI-I guess…\pI, u-uh…\p… … …\pS-see you b-back at th-the Lab, then…$"
