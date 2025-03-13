ShuiyunTownBoatHallway_MapScripts::
	.byte 0


ShuiyunTownBoatHallway_EventScript_TalkGrunt1::
	msgbox ShuiyunTownBoatHallway_Text_TalkGrunt1 MSGBOX_NPC
	end


ShuiyunTownBoatHallway_EventScript_TalkGrunt2::
	msgbox ShuiyunTownBoatHallway_Text_TalkGrunt2 MSGBOX_NPC
	end

ShuiyunTownBoatHallway_Text_TalkGrunt1:
	.string "We're inspecting this boat for\n"
	.string "suspicious cargo!\l"
	.string "Remain in your room!$"

ShuiyunTownBoatHallway_Text_TalkGrunt2:
	.string "Move along, now.\n"
	.string "Nothing out of the ordinary here.$"
