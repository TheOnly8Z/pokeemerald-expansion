SkywardTrail_Lab_MapScripts::
	.byte 0

SkywardTrail_Lab_EventScript_Grunt5::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_5, SkywardTrail_Lab_Text_Grunt5Intro, SkywardTrail_Lab_Text_Grunt5Defeat
	msgbox SkywardTrail_Lab_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_Lab_EventScript_Grunt6::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_6, SkywardTrail_Lab_Text_Grunt6Intro, SkywardTrail_Lab_Text_Grunt6Defeat
	msgbox SkywardTrail_Lab_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_Lab_Text_Grunt5Intro:
	.string "I'm evil!$"

SkywardTrail_Lab_Text_Grunt5Defeat:
	.string "I lost!$"

SkywardTrail_Lab_Text_Grunt5PostBattle:
	.string "Owww...$"

SkywardTrail_Lab_Text_Grunt6Intro:
	.string "I'm evil!$"

SkywardTrail_Lab_Text_Grunt6Defeat:
	.string "I lost!$"

SkywardTrail_Lab_Text_Grunt6PostBattle:
	.string "Owww...$"
