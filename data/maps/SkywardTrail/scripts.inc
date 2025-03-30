SkywardTrail_MapScripts::
	.byte 0

SkywardTrail_EventScript_Grunt1::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_1, SkywardTrail_Text_Grunt1Intro, SkywardTrail_Text_Grunt1Defeat
	msgbox SkywardTrail_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt2::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_2, SkywardTrail_Text_Grunt2Intro, SkywardTrail_Text_Grunt2Defeat
	msgbox SkywardTrail_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt3::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_3, SkywardTrail_Text_Grunt3Intro, SkywardTrail_Text_Grunt3Defeat
	msgbox SkywardTrail_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt4::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_4, SkywardTrail_Text_Grunt4Intro, SkywardTrail_Text_Grunt4Defeat
	msgbox SkywardTrail_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_Text_GruntBringDouble:
	.string "Bring another!$"

SkywardTrail_Text_Grunt1Intro:
	.string "I'm evil!$"

SkywardTrail_Text_Grunt1Defeat:
	.string "I lost!$"

SkywardTrail_Text_Grunt1PostBattle:
	.string "Owww...$"

SkywardTrail_Text_Grunt2Intro:
	.string "I'm evil!$"

SkywardTrail_Text_Grunt2Defeat:
	.string "I lost!$"

SkywardTrail_Text_Grunt2PostBattle:
	.string "Owww...$"

SkywardTrail_Text_Grunt3Intro:
	.string "I'm evil!$"

SkywardTrail_Text_Grunt3Defeat:
	.string "I lost!$"

SkywardTrail_Text_Grunt3PostBattle:
	.string "Owww...$"

SkywardTrail_Text_Grunt4Intro:
	.string "I'm evil!$"

SkywardTrail_Text_Grunt4Defeat:
	.string "I lost!$"

SkywardTrail_Text_Grunt4PostBattle:
	.string "Owww...$"

SkywardTrail_EventScript_SignBridge::
	msgbox SkywardTrail_Text_Bridge, MSGBOX_SIGN
	end

SkywardTrail_EventScript_SignLab::
	msgbox SkywardTrail_Text_Lab, MSGBOX_SIGN
	end

SkywardTrail_Text_Bridge:
	.string "{LEFT_ARROW} REST STOP\n"
	.string "{RIGHT_ARROW} YONGTAI LABORATORY$"

SkywardTrail_Text_Lab:
	.string "YONGTAI LABORATORY\p"
	.string "“Always The First Wave”$"