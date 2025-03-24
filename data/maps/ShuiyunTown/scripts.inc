ShuiyunTown_MapScripts::
	.byte 0

.set LOCALID_DEBUGNPC, 5

ShuiyunTown_EventScript_DebugGiveHM::
	lock
	msgbox ShuiyunTown_Text_DebugGiveHM MSGBOX_DEFAULT
	givemon SPECIES_BIDOOF, 50, move1=MOVE_SURF, move2=MOVE_STRENGTH, move3=MOVE_ROCK_SMASH, move4=MOVE_WATERFALL
	setflag FLAG_DEBUG_GIVE_HM
	removeobject LOCALID_DEBUGNPC
	release
	end

ShuiyunTown_EventScript_TalkFatMan::
	msgbox ShuiyunTown_Text_TalkFatMan MSGBOX_NPC
	end

ShuiyunTown_EventScript_TalkOldMan::
	msgbox ShuiyunTown_Text_TalkOldMan MSGBOX_NPC
	end

ShuiyunTown_EventScript_TalkFisher::
	msgbox ShuiyunTown_Text_TalkFisher MSGBOX_NPC
	end

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
	.string "LEADER: ZHONG\l"
	.string "“Strong Arms, Strong Heart”$"

ShuiyunTown_Text_Cave:
	.string "{UP_ARROW} LANTERN CAVE\n"
	.string "{RIGHT_ARROW} SKYWARD TRAIL$"

ShuiyunTown_Text_Clubhouse:
	.string "COMMUNITY CENTER\n"
	.string "“Sharing Ocean's Bounty”$"

ShuiyunTown_Text_TalkFatMan:
	.string "Everyone is hiding from the rain inside\n"
	.string "the COMMUNITY CENTER to the northeast.\p"
	.string "If you don't want to get drenched like\n"
	.string "me, you should head there too.$"

ShuiyunTown_Text_TalkOldMan:
	.string "Oh, young one, you arrived at a\n"
	.string "troublesome time…\p"
	.string "So many people are looking for a\n"
	.string "POKéMON TRAINER to help them.\p"
	.string "Perhaps that's why you came?$"

ShuiyunTown_Text_TalkFisher:
	.string "Do you know what this weather means?\n"
	.string "That's right, more fish!$"

	
ShuiyunTown_Text_DebugGiveHM:
	.string "I'm a debug NPC who will give you\n"
	.string "a POKéMON with all the needed HMs.\p"
	.string "Enjoy!$"