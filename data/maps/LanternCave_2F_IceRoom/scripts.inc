LanternCave_2F_IceRoom_MapScripts::
	.byte 0

LanternCave_2F_EventScript_Jak::
	trainerbattle_single TRAINER_LANTERN_JAK, LanternCave_2F_Text_Jak_Intro, LanternCave_2F_Text_Jak_Defeat
	msgbox LanternCave_2F_Text_Jak_PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_2F_Text_Jak_Intro:
	.string "Everyone says I'm too hot-headed!\n"
	.string "I'll show you… I'll show them all!$"

LanternCave_2F_Text_Jak_Defeat:
	.string "The cooler head pervailed…$"

LanternCave_2F_Text_Jak_PostBattle:
	.string "This cave is quite hot somehow,\n"
	.string "but it's nice and chill in here.$"
