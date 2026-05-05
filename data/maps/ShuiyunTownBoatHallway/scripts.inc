ShuiyunTownBoatHallway_MapScripts::
	.byte 0


ShuiyunTownBoatHallway_EventScript_PreventExit::
	msgbox ShuiyunTownBoatHallway_Text_Captain MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp

ShuiyunTownBoatHallway_EventScript_TalkGrunt1::
	msgbox ShuiyunTownBoatHallway_Text_TalkGrunt1 MSGBOX_NPC
	end


ShuiyunTownBoatHallway_EventScript_TalkGrunt2::
	msgbox ShuiyunTownBoatHallway_Text_TalkGrunt2 MSGBOX_NPC
	end

ShuiyunTownBoatHallway_Text_Captain::
	.string "You remember STEVEN's advice\n"
	.string "to talk to the captain first.$"

ShuiyunTownBoatHallway_Text_TalkGrunt1:
	.string "We're inspecting this boat for\n"
	.string "suspicious cargo!\l"
	.string "Remain in your room!$"

ShuiyunTownBoatHallway_Text_TalkGrunt2:
	.string "Move along, now.\n"
	.string "Nothing out of the ordinary here.$"
