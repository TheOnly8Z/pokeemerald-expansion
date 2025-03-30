ShuiyunShores_MapScripts::
	.byte 0

ShuiyunShores_EventScript_Shire::
	trainerbattle_single TRAINER_SHORE_SHIRE, ShuiyunShores_Text_Shire_Intro, ShuiyunShores_Text_Shire_Defeat
	msgbox ShuiyunShores_Text_Shire_PostBattle, MSGBOX_AUTOCLOSE
	end

ShuiyunShores_Text_Shire_Intro:
	.string "We're just living in a database!\n"
	.string "You know that, right?$"

ShuiyunShores_Text_Shire_Defeat:
	.string "The madness of the system grows…$"

ShuiyunShores_Text_Shire_PostBattle:
	.string "I'm hiding on this island because\n"
	.string "I did tax evasion.$"

	
ShuiyunShores_EventScript_Lancelot::
	trainerbattle_single TRAINER_SHORE_LANCELOT, ShuiyunShores_Text_Lancelot_Intro, ShuiyunShores_Text_Lancelot_Defeat
	msgbox ShuiyunShores_Text_Lancelot_PostBattle, MSGBOX_AUTOCLOSE
	end

ShuiyunShores_Text_Lancelot_Intro:
	.string "Water you doing, interrupting my\n"
	.string "fishing?$"

ShuiyunShores_Text_Lancelot_Defeat:
	.string "Glubglubglub……$"

ShuiyunShores_Text_Lancelot_PostBattle:
	.string "Fishing's pretty swell. If you've\n"
	.string "a mind for it, talk to the fellow\l"
	.string "who is fishing on the beach.$"