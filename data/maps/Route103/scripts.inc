.set LOCALID_RIVAL, 2
.set LOCALID_BLOCKER, 21

Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	call_if_unset FLAG_ADVENTURE_STARTED, Route103_EventScript_BlockEntrance
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalMay
	end

Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	call Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_stepDown:
	walk_down
	step_end

Route103_EventScript_playerStepDown::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_stepDown
	releaseall
	end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_BlockEntrance::
	setobjectxyperm 21, 9, 46
	setobjectmovementtype 21, MOVEMENT_TYPE_FACE_RIGHT
	return

Route103_Text_MayRoute103Pokemon:
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon:
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "Route 2\n"
	.string "{DOWN_ARROW} Asterra\l"
	.string "{LEFT_ARROW} Route 3$"

Route103_EventScript_playerStepBack::
	lockall
	applymovement 21, Common_Movement_ExclamationMark
	waitmovement 21
	msgbox Route103_EventScript_playerStepBack_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, playerStepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 21, patrolArea
	waitmovement 21
	msgbox Route103_EventScript_playerStepBack_Text_1
	waitmovement 21
	applymovement OBJ_EVENT_ID_PLAYER, playerStepDown
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	return


Route103_EventScript_RockText::
	lockall
	msgbox Route103_EventScript_RockText_Text_0
	releaseall
	return


playerStepDown:
	walk_down
	face_up
	step_end

patrolArea:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route103_EventScript_ladyText::
	lockall
	faceplayer
	msgbox Route103_EventScript_ladyText_Text_0
	release
	releaseall
	return


Route2_EventScript_lassBattle::
	trainerbattle_single TRAINER_TIANA, lassr2_intro, lassr2_defeat
	lockall
	msgbox lassr2_postbattle
	releaseall
	end


route2_walkUp_left::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepRight
	waitmovement OBJ_EVENT_ID_PLAYER
	goto route2_EventScript_stellaIntro
	return


route2_walkUp_right::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	goto route2_EventScript_stellaIntro
	return


route2_walkUp_rightMost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepLeft2
	waitmovement OBJ_EVENT_ID_PLAYER
	goto route2_EventScript_stellaIntro
	return


route2_walkUp::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, route2_playerStepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	goto route2_EventScript_stellaIntro
	return


route2_EventScript_stellaIntro::
	applymovement 2, route2_stellaShuffle
	msgbox route2_stellaIntroText
	waitmessage
	msgbox route2_EventScript_stellaIntro_Text_0
	applymovement 2, lookDown
	waitmovement 2
	applymovement 2, exclamation
	waitmovement 2
	msgbox route2_EventScript_stellaIntro_Text_1
	waitmessage
	applymovement 2, route2_stellaRunDown
	waitmovement 2
	msgbox route2_stella2
	waitmessage
	applymovement 2, exclamation
	msgbox route2_stellaPreBattle, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq route2_EventScript_stellaBattleNo
	msgbox route2_EventScript_stellaIntro_Text_2
	goto route2_stellaRivalBattle
	return


route2_EventScript_stellaBattleNo::
	msgbox route2_stellaBattleNo
	special HealPlayerParty
	goto route2_stellaRivalBattle
	return


route2_stellaRivalBattle::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, route2_stellaDefeat
	goto route2_EventScript_stellaAfterBattle
	return


route2_EventScript_stellaAfterBattle::
	setvar VAR_OLDALE_RIVAL_STATE, 1
	msgbox route2_stellaAfterBattle, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 2, route2_stellaLeave
	waitmovement 2
	call Route103_EventScript_RivalEnd
	releaseall
	return


route2_playerStepUp:
	walk_up
	walk_up
	walk_up
	step_end

route2_playerStepLeft:
	walk_left
	face_up
	step_end

route2_playerStepLeft2:
	walk_left
	walk_left
	face_up
	step_end

route2_playerStepRight:
	walk_right
	face_up
	step_end

route2_stellaWalkDown:
	walk_down
	walk_down
	step_end

route2_stellaShuffle:
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	step_end

route2_stellaRunDown:
	walk_fast_down
	walk_fast_down
	step_end

route2_stellaLeave:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

route2_stellaLookDown:
	face_down
	step_end

Route103_EventScript_playerStepBack_Text_0:
	.string "HEY! Step off!$"

Route103_EventScript_playerStepBack_Text_1:
	.string "I'm TRYING to look for Pokémon\nfootprints here! Now go! Get!$"

Route103_EventScript_RockText_Text_0:
	.string "Made you look ::-3$"

Route103_EventScript_ladyText_Text_0:
	.string "So uh. Turns out, that uh.\nThose footprints. They, uh...\lThey were kinda mine.$"

route2_EventScript_stellaIntro_Text_0:
	.string "Let's see what else th-$"

route2_EventScript_stellaIntro_Text_1:
	.string "{PLAYER}!!$"

route2_EventScript_stellaIntro_Text_2:
	.string "Alright! Me 'n Sprinkles are giving\nit all we got!$"

lassr2_intro::
	.string "Hey! Stop walking and look at my\nPokémon!$"

lassr2_defeat::
	.string "UGHHHH. Great.$"

lassr2_postbattle::
	.string "I don't understand how I could've\nlost... my Pokémon are so cute!$"

route2_stellaIntroText::
	.string "Alright, uhhh…\p"
	.string "Eggrole feathers, check…\nCaonine fur, check…\lSqweekling hair…$"

route2_stella2::
	.string "I had no IDEA you would be here so\nSOON!!!\p"
	.string "… … … … … …\n"
	.string "…Uncle James needs me for something?\p"
	.string "Alright, alright, I'll come with…$"

route2_stellaPreBattle::
	.string "WOAH! He gave you A Pokémon!?\nNo WAY!\p"
	.string "We GOTTA battle before we head back!$"

route2_stellaBattleNo::
	.string "C'mooooon… you know you wanna!\nHere, I'll even heal your team! Just\lto be safe!$"

route2_stellaAfterBattle::
	.string "…alright, maybe you're a little stronger\nthan I thought.\pLet's get going, if it's really THAT\nimportant.$"

route2_stellaDefeat::
	.string "WOW! Uh…$"
