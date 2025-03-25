LanternCave_2F_MapScripts::
	.byte 0


LanternCave_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_LANTERN_GRUNT_5, LanternCave_2F_Text_Grunt5Intro, LanternCave_2F_Text_Grunt5Defeat
	msgbox LanternCave_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_LANTERN_GRUNT_6, LanternCave_2F_Text_Grunt6Intro, LanternCave_2F_Text_Grunt6Defeat
	msgbox LanternCave_2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_2F_Text_Grunt5Intro:
	.string "I'm evil!$"

LanternCave_2F_Text_Grunt5Defeat:
	.string "I lost!$"

LanternCave_2F_Text_Grunt5PostBattle:
	.string "Owww...$"

LanternCave_2F_Text_Grunt6Intro:
	.string "I'm evil!$"

LanternCave_2F_Text_Grunt6Defeat:
	.string "I lost!$"

LanternCave_2F_Text_Grunt6PostBattle:
	.string "Owww...$"
