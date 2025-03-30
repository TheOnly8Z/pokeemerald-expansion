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
	
SkywardTrail_Lab_EventScript_TalkBlockerGrunt::
	msgbox SkywardTrail_Lab_Text_BlockerGrunt, MSGBOX_NPC
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

SkywardTrail_Lab_Text_BlockerGrunt:
	.string "Hehehe……\p"
	.string "Our boys are having the time of their\n"
	.string "lives down in the basement, pressing\l"
	.string "all the flashing buttons they see!\p"
	.string "What do the buttons do? Who cares!\p"
	.string "You're silly if you think I'll let\n"
	.string "you join in on the fun.$"