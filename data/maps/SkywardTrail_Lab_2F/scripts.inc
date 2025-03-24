SkywardTrail_Lab_2F_MapScripts::
	.byte 0

SkywardTrail_Lab_2F_EventScript_TalkScientist::
	@ If parts not delivered yet, remind player where it goes to
	checkitem ITEM_SHIP_PARTS
	goto_if_eq VAR_RESULT, TRUE, SkywardTrail_Lab_2F_EventScript_TalkScientistReminder
	@ Say something generic when delivered
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, SkywardTrail_Lab_2F_EventScript_TalkScientistGiven
	lock
	faceplayer
	@ Dialog depends on whether Kai was visited beforehand
	call_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1, SkywardTrail_Lab_2F_EventScript_TalkScientistQuest
	call_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 0, SkywardTrail_Lab_2F_EventScript_TalkScientistNoQuest
	giveitem ITEM_SHIP_PARTS
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemPost, MSGBOX_DEFAULT
	release
	end


SkywardTrail_Lab_2F_EventScript_TalkScientistReminder::
	msgbox SkywardTrail_Lab_2F_Text_ScientistReminder, MSGBOX_NPC
	end

SkywardTrail_Lab_2F_EventScript_TalkScientistGiven::
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiven, MSGBOX_NPC
	end

SkywardTrail_Lab_2F_EventScript_TalkScientistNoQuest::
	@ Kai was NOT visited first, set a special state so dialog makes sense
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemNoQuest, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 2
	return

SkywardTrail_Lab_2F_EventScript_TalkScientistQuest::
	@ Kai was visited first
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemQuest, MSGBOX_DEFAULT
	return

SkywardTrail_Lab_2F_Text_ScientistGiveItemNoQuest:
	.string "I'll never give you what you want,\n"
	.string "TEAM AQUA scum!\p"
	.string "……\p"
	.string "Oh, pardon me! You don't look like\n"
	.string "TEAM AQUA at all!\p"
	.string "If you made it this far, you must\n"
	.string "be quite the capable TRAINER.\p"
	.string "Can you bring this to the DOCKYARD\n"
	.string "in SHUIYUN TOWN?\p"

SkywardTrail_Lab_2F_Text_ScientistGiveItemQuest:
	.string "I'll never give you what you want,\n"
	.string "TEAM AQUA scum!\p"
	.string "……\p"
	.string "Oh, pardon me! You don't look like\n"
	.string "TEAM AQUA at all!\p"
	.string "KAI sent you for the parts, you say?\n"
	.string "Here it is!$"

SkywardTrail_Lab_2F_Text_ScientistGiveItemPost:
	.string "They were supposed to pick it up,\n"
	.string "but the condition of the trail\l"
	.string "speaks for itself.\p"
	.string "Now hurry, before the water\n"
	.string "swallows us all!$"

SkywardTrail_Lab_2F_Text_ScientistReminder:
	.string "Those parts need to go to the DOCKYARD\n"
	.string "in SHUIYUN TOWN. Talk to KAI there.$"

SkywardTrail_Lab_2F_Text_ScientistGiven:
	.string "We repaired those parts for the\n"
	.string "folks down at the DOCKYARD.\p"
	.string "They're capable people, but lack\n"
	.string "the specialized machines we have\l"
	.string "up here.\p"
	.string "On the contrary, we lack their\n"
	.string "sheer manpower and resources.\p"
	.string "We rely on each other for success!$"