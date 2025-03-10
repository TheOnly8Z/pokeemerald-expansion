ShuiyunTown_MapScripts::
	.byte 0

ShuiyunTown_EventScript_Dockyard::
	msgbox ShuiyunTown_Text_Dockyard MSGBOX_SIGN
	end

ShuiyunTown_EventScript_GymSign::
	msgbox ShuiyunTown_Text_GymSign MSGBOX_SIGN
	end

ShuiyunTown_EventScript_Clubhouse::
	msgbox ShuiyunTown_Text_Clubhouse MSGBOX_SIGN
	end

ShuiyunTown_EventScript_Cave::
	msgbox ShuiyunTown_Text_Cave MSGBOX_SIGN
	end

ShuiyunTown_Text_Dockyard:
	.string "SHUIYUN DOCKYARD$"

ShuiyunTown_Text_GymSign:
	.string "SHUIYUN TOWN POKéMON GYM\n"
	.string "LEADER: NAME HERE\l"
	.string "“Quote here!”$"

ShuiyunTown_Text_Cave:
	.string "{UP_ARROW} NAME CAVE\n"
	.string "{RIGHT_ARROW} ROUTE 1$"

ShuiyunTown_Text_Clubhouse:
	.string "CLUBHOUSE\n"
	.string "“Quote here!”$"