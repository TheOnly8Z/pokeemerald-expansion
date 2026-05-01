SkywardTrail_Lab_2F_MapScripts::
	.byte 0

.set LOCALID_MATT, 2
.set LOCALID_BAG, 4

SkywardTrail_Lab_2F_EventScript_TalkScientist::
	@ If parts not delivered yet, remind player where it goes to
	checkitem ITEM_SHIP_PARTS
	goto_if_eq VAR_RESULT, TRUE, SkywardTrail_Lab_2F_EventScript_TalkScientistReminder
	@ Say something generic when delivered
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, SkywardTrail_Lab_2F_EventScript_TalkScientistGiven
	lock
	faceplayer
	@ Dialog depends on whether Kai was visited beforehand
	@ call_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1, SkywardTrail_Lab_2F_EventScript_TalkScientistQuest
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 0, SkywardTrail_Lab_2F_EventScript_TalkScientistNoQuest

	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemQuest, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_SHIP_PARTS
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemPost, MSGBOX_DEFAULT
	release
	end


SkywardTrail_Lab_2F_EventScript_TalkScientistReminder::
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistReminder, MSGBOX_NPC
	end

SkywardTrail_Lab_2F_EventScript_TalkScientistGiven::
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiven, MSGBOX_NPC
	end

SkywardTrail_Lab_2F_EventScript_TalkScientistNoQuest::
	@ Kai was NOT visited first, set a special state so dialog makes sense
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemNoQuest, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 2
	speakername NULL
	giveitem ITEM_SHIP_PARTS
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemPost, MSGBOX_DEFAULT
	release
	end

SkywardTrail_Lab_2F_EventScript_TalkScientistQuest::
	@ Kai was visited first
	msgbox SkywardTrail_Lab_2F_Text_ScientistGiveItemQuest, MSGBOX_DEFAULT
	return

SkywardTrail_Lab_2F_EventScript_TalkScientistTextOnly::
	@ If parts not delivered yet, remind player where it goes to
	checkitem ITEM_SHIP_PARTS
	goto_if_eq VAR_RESULT, TRUE, SkywardTrail_Lab_2F_EventScript_TalkScientistReminder
	@ Say something generic when delivered
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, SkywardTrail_Lab_2F_EventScript_TalkScientistGiven
	lock
	faceplayer
	speakername SkywardTrail_Name_Researcher
	msgbox SkywardTrail_Lab_2F_Text_ScientistAfraid, MSGBOX_DEFAULT
	release
	end

SkywardTrail_Lab_2F_EventScript_TalkMatt::
	lock
	faceplayer
	speakername CommonName_Text_Matt
	msgbox SkywardTrail_Lab_2F_Text_MattIntroduction, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_SKYWARD_MATT, SkywardTrail_Lab_2F_Text_MattIntro2, SkywardTrail_Lab_2F_Text_MattDefeat, SkywardTrail_Lab_2F_EventScript_Matt_PostBattle
	release
	end

SkywardTrail_Lab_2F_EventScript_Matt_PostBattle::
	lock
	faceplayer
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 2
	setflag FLAG_HIDE_SKYWARD_TRAIL_MATT

	speakername CommonName_Text_Matt
	msgbox SkywardTrail_Lab_2F_Text_MattPostBattle1, MSGBOX_DEFAULT

	speakername NULL
	giveitem ITEM_SHIP_PARTS

	speakername CommonName_Text_Matt
	msgbox SkywardTrail_Lab_2F_Text_MattPostBattle2, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox SkywardTrail_Lab_2F_Text_MattPostBattle3, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox SkywardTrail_Lab_2F_Text_MattPostBattle4, MSGBOX_DEFAULT

	closemessage

	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MATT
	removeobject LOCALID_BAG
	fadescreen FADE_FROM_BLACK

	release
	end

SkywardTrail_Lab_2F_Text_ScientistGiveItemNoQuest::
	.string "I'll never give you what you want,\n"
	.string "TEAM AQUA scum!\p"
	.string "……\p"
	.string "Oh, pardon me! You don't look like\n"
	.string "TEAM AQUA at all!\p"
	.string "If you made it this far, you must\n"
	.string "be quite the capable TRAINER.\p"
	.string "Can you bring this to KAI at the\n"
	.string "DOCKYARD in SHUIYUN TOWN?\p"

SkywardTrail_Lab_2F_Text_ScientistGiveItemQuest::
	.string "I'll never give you what you want,\n"
	.string "TEAM AQUA scum!\p"
	.string "……\p"
	.string "Oh, pardon me! You don't look like\n"
	.string "TEAM AQUA at all!\p"
	.string "KAI sent you for the parts, you say?\n"
	.string "Here it is!$"

SkywardTrail_Lab_2F_Text_ScientistGiveItemPost::
	.string "They were supposed to pick it up\n"
	.string "earlier, but the condition of the\l"
	.string "trail speaks for itself.\p"
	.string "Let me heal your POKéMON just in case.$"

SkywardTrail_Lab_2F_Text_ScientistAfraid::
	.string "A-are you here for the SHIP PARTS?\n"
	.string "I'm afraid you're too late…\p"
	.string "These grunts broke in and started\n"
	.string "looting everything…$"

SkywardTrail_Lab_2F_Text_MattIntroduction::
	.string "What's the matter, kid?\n"
	.string "Looking for these parts?\p"
	.string "Hehehe! If you show me a good\n"
	.string "POKéMON BATTLE, I just might!$"

SkywardTrail_Lab_2F_Text_MattIntro2::
	.string "The name's MATT of TEAM AQUA!\n"
	.string "Prepare for a walloping!$"

SkywardTrail_Lab_2F_Text_MattDefeat::
	.string "Sunk twice in the same port?!$"

SkywardTrail_Lab_2F_Text_MattPostBattle1::
	.string "Ohoho! So yer the one that\n"
	.string "GRUNT lass warned me about!\p"
	.string "To be honest with 'cha, I wanted\n"
	.string "you to have those parts!$"

	
SkywardTrail_Lab_2F_Text_MattPostBattle2::
	.string "These SHIP PARTS are for fixin' yer.\n"
	.string "maroon'd ship in the shipyard, yeah?\p"
	.string "Saw that KAI bloke all gloomy in\n"
	.string "there. Hehe!\p"
	.string "Of course TEAM AQUA will support\n"
	.string "our fellow ocean lovers!\p"
	.string "Yer man MATT just wanted to test the\n"
	.string "waters a lil' is all.$"

SkywardTrail_Lab_2F_Text_MattPostBattle3::
	.string "…\p"
	.string "It's been how long since that kid?\n"
	.string "Since ARCHIE left us?$"

SkywardTrail_Lab_2F_Text_MattPostBattle4::
	.string "Heh! It's none of yer business.\n"
	.string "Take yer parts and scram!\p"
	.string "But if ya really wanna get in the\n"
	.string "way of TEAM AQUA for real…\p"
	.string "I won't hold back! Hehehe!$"

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

SkywardTrail_Name_Researcher:
	.string "RESEARCHER$"
