RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "DEVON's PRESIDENT likes to collect\n"
	.string "rare stones.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "I think the PRESIDENT's son also\n"
	.string "collects rare stones.$"

rustboro_flat2_3f_suitGuy::
	msgbox rustboro_flat2_suitGuy, MSGBOX_NPC
	return


rustboro_flat2_3f_couchLady::
	msgbox rustboro_flat2_couchLady, MSGBOX_NPC
	return


rustboro_flat2_3f_girl::
	lockall
	msgbox rustboro_flat2_girl
	releaseall
	return


rustboro_flat2_suitGuy::
	.string "I'm feelin' good!\pBoss said he'd give me a promotion if\nI kept my output high.\pCouple weeks'a hard work, and... bam!\pHello pay raise!$"

rustboro_flat2_couchLady::
	.string "Sometimes I worry about my husband...\pI respect his dedication, but...\pHe tends to overwork himself.$"

rustboro_flat2_girl::
	.string "(She seems too concentrated on drawing\nsomething to talk.)$"
