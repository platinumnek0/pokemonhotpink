OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_NPC
	end

OldaleTown_House1_Text_LeftPokemonGoesOutFirst:
	.string "When a POKéMON battle starts, the one\n"
	.string "at the left of the list goes out first.\p"
	.string "So, when you get more POKéMON in your\n"
	.string "party, try switching around the order\l"
	.string "of your POKéMON.\p"
	.string "It could give you an advantage.$"

OldaleTown_House1_eventScript_momDialogue::
	faceplayer
	lockall
	msgbox OldaleTown_House1_eventScript_momDialogue_Text_0
	release
	releaseall
	return


OldaleTown_EventScript_stellaGrandpa::
	faceplayer
	lockall
	msgbox OldaleTown_EventScript_stellaGrandpa_Text_0
	release
	releaseall
	return


OldaleTown_EventScript_stellaHousePainting::
	lockall
	msgbox OldaleTown_EventScript_stellaHousePainting_Text_0
	releaseall
	return


OldaleTown_House1_eventScript_momDialogue_Text_0:
	.string "Oh! {PLAYER}! Didn't expect seeing you so soon!\nStella? She's up poking around Route 2,\lyou should go say hi!$"

OldaleTown_EventScript_stellaGrandpa_Text_0:
	.string "Weh heh heh! If it isn't {PLAYER}! How's the\nmove been on ya?\l...mhm...\l...I see...$"

OldaleTown_EventScript_stellaHousePainting_Text_0:
	.string "A painting of a stormy sea.\nIt looks familiar.$"
