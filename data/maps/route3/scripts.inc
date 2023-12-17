route3_MapScripts::
	.byte 0


randomTest::
	lockall
	random 4
	switch VAR_RESULT
	case ( 0 ), randomTest_3
	case ( 1 ), randomTest_4
	case ( 2 ), randomTest_5
	case ( 3 ), randomTest_6
randomTest_1:
	releaseall
	return

randomTest_3:
	msgbox randomTest_Text_0
	goto randomTest_1

randomTest_4:
	msgbox randomTest_Text_1
	goto randomTest_1

randomTest_5:
	msgbox randomTest_Text_2
	goto randomTest_1

randomTest_6:
	msgbox randomTest_Text_3
	goto randomTest_1


randomTest_Text_0:
	.string "Yellow$"

randomTest_Text_1:
	.string "Purple$"

randomTest_Text_2:
	.string "Pink$"

randomTest_Text_3:
	.string "Cyan$"
