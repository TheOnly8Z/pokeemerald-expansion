ShuiyunTown_Dockyard_MapScripts::
	.byte 0

.set LOCALID_KAI, 5

ShuiyunTown_Dockyard_EventScript_TalkMan1::
	msgbox ShuiyunTown_Dockyard_Text_Man1, MSGBOX_NPC
	end

ShuiyunTown_Dockyard_EventScript_TalkMan2::
	msgbox ShuiyunTown_Dockyard_Text_Man2, MSGBOX_NPC
	end

ShuiyunTown_Dockyard_EventScript_TalkMan3::
	msgbox ShuiyunTown_Dockyard_Text_Man3, MSGBOX_NPC
	end

ShuiyunTown_Dockyard_EventScript_TalkMan4::
	msgbox ShuiyunTown_Dockyard_Text_Man4, MSGBOX_NPC
	end

ShuiyunTown_Dockyard_EventScript_TalkMan5::
	msgbox ShuiyunTown_Dockyard_Text_Man5, MSGBOX_NPC
	end

ShuiyunTown_Dockyard_Text_Man1:
	.string "Hey, are you able to lend a hand?\n"
	.string "Talk to our boss over there.\p"
	.string "He's been looking troubled for the past\n"
	.string "few days.\p"
	.string "Everyone's on edge, but he's got it the\n"
	.string "hardest as the dockmaster.$"

ShuiyunTown_Dockyard_Text_Man2:
	.string "My back hurts, but there's no time to\n"
	.string "rest or complain.\p"
	.string "People's lives depend on us!$"

ShuiyunTown_Dockyard_Text_Man3:
	.string "Heave-ho! Heave-ho!\n"
	.string "Patch these holes or underwater we go!$"
	
ShuiyunTown_Dockyard_Text_Man4:
	.string "I must ask you to stay out of the\n"
	.string "construction area.\p"
	.string "It's hectic down there, and you might\n"
	.string "get hurt from the machinery.$"
	
ShuiyunTown_Dockyard_Text_Man5:
	.string "I've never seen a ship with more holes\n"
	.string "than the one we're patching up.\p"
	.string "Apparently, it only stayed afloat\n"
	.string "because POKéMON helped out.$"

	
ShuiyunTown_Dockyard_EventScript_TalkKai::
	@ VAR_SHUIYUN_DOCKYARD_QUEST_STATE
	@ 0: Never started
	@ 1: Talked to Kai
	@ 2: Got ship parts before talking to Kai
	@ 3: Complete

	@ If player has ship parts, hand in the quest
	checkitem ITEM_SHIP_PARTS
	goto_if_eq VAR_RESULT, TRUE, ShuiyunTown_Dockyard_EventScript_TalkKaiGotParts

	@ In the middle of some quest
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1, ShuiyunTown_Dockyard_EventScript_TalkKaiRepeat
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_TalkKaiRescueZhong

	@ First meeting
	lock
	msgbox ShuiyunTown_Dockyard_Text_Kai_Muttering, MSGBOX_DEFAULT
	applymovement LOCALID_KAI, Movement_KaiSurprised
	waitmovement 0
	delay 20
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_FirstMeet, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Dockyard_Text_Kai_Exposition, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Dockyard_Text_Kai_AskFetch, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1
	release
	end

ShuiyunTown_Dockyard_EventScript_TalkKaiRepeat::
	lock
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_Repeat, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_Dockyard_EventScript_TalkKaiRescueZhong::
	lock
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_RescueZhong, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_Dockyard_EventScript_TalkKaiGotParts::
	lock
	removeitem ITEM_SHIP_PARTS
	call_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1, ShuiyunTown_Dockyard_EventScript_TalkKaiHandin
	call_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 2, ShuiyunTown_Dockyard_EventScript_TalkKaiSkip
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3
	@ TODO Set state based on state of gym leader rescue
	release
	end

ShuiyunTown_Dockyard_EventScript_TalkKaiHandin::
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_FetchHandin1, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	msgbox ShuiyunTown_Dockyard_Text_Kai_FetchHandin2, MSGBOX_DEFAULT
	return

ShuiyunTown_Dockyard_EventScript_TalkKaiSkip::
	@ Handle edge case where player went to get parts before talking to Kai
	@ This effectively merges first meet dialog with handin dialog
	msgbox ShuiyunTown_Dockyard_Text_Kai_Muttering, MSGBOX_DEFAULT
	applymovement LOCALID_KAI, Movement_KaiSurprised
	waitmovement 0
	delay 20
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_SkipHandin1, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Dockyard_Text_Kai_Exposition, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Dockyard_Text_Kai_SkipHandin2, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	msgbox ShuiyunTown_Dockyard_Text_Kai_SkipHandin3, MSGBOX_DEFAULT
	return

ShuiyunTown_Dockyard_Text_Kai_Muttering:
	.string "???: What am I supposed to do…\n"
	.string "First the rain, now you're missing too…$"

ShuiyunTown_Dockyard_Text_Kai_FirstMeet:
	.string "Ah-Ahem. You must be new.\n"
	.string "I'm DOCKMASTER KAI. What's your name?\p"
	.string "……\p"
	.string "{PLAYER}, and you're here on behalf\n"
	.string "of the POKéMON LEAGUE?\p"
	.string "I can explain what's going on, but\n"
	.string "we need your assistance desperately.$"

ShuiyunTown_Dockyard_Text_Kai_Exposition:
	.string "This rain is flooding JIANGSHEN LAKE.\n"
	.string "It is about to flood the entire island.\p"
	.string "We are trying to evacuate everyone using\n"
	.string "a damaged cruise ship in the docks.$"

ShuiyunTown_Dockyard_Text_Kai_AskFetch:
	.string "Some critical parts for the repair are\n"
	.string "in the LABORATORY on SKYWARD TRAIL.\p"
	.string "Both the weather and interference from\n"
	.string "TEAM AQUA make the journey difficult\l"
	.string "for anyone who isn't a TRAINER.\p"
	.string "All hands are full here, so I must ask\n"
	.string "you to retrieve those parts for me.\p"
	.string "If you need help, visit the house near\n"
	.string "the top of the trail.\p"
	.string "Exercise caution.$"

ShuiyunTown_Dockyard_Text_Kai_Repeat:
	.string "Ah, did you get the ship parts?\p"
	.string "The parts are in the LABORATORY on top\n"
	.string "of SKYWARD TRAIL."
	.string "There's a house on the way there.\n"
	.string "Visit there if you need help.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin1:
	.string "Ah-{PAUSE 15}Ahem. You must be new.\n"
	.string "What's that? You have a package for me?\p"
	.string "{PLAYER} handed over the SHIP PARTS.\p"
	.string "Thank you. This is very important.\p"
	.string "I'm DOCKMASTER KAI. What's your name?\p"
	.string "…{PAUSE 15}…\p"
	.string "{PLAYER}, and you're here on behalf\n"
	.string "of the POKéMON LEAGUE?\p"
	.string "I am glad the LEAGUE sent such a\n"
	.string "capable TRAINER. Let me explain what\l"
	.string "is going on here.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin2:
	.string "The parts you just delievered are\n"
	.string "crucial to the repair.\p"
	.string "I'd like you to have this as thanks.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin3:
	.string "This will allow you to travel quickly.\n"
	.string "You can also ascend steep slopes with it.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandin1:
	.string "{PLAYER} handed over the SHIP PARTS.\p"
	.string "KAI: That's it! I'm so glad I could…\p"
	.string "No, it is not yet time for celebration.\p"
	.string "First, you should take this.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandin2:
	.string "KAI: I found this in our warehouses\n"
	.string "while you were away.\p"
	.string "It allows you to travel quickly, and\n"
	.string "also ascend steep slopes on the trail.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandinRescued:
	.string "We need to evaluate the situation with\n"
	.string "ZHONG and consider our options.\p"
	.string "Let’s rendezvous on the beach outside\n"
	.string "the GYM. It's to the south of here.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong1:
	.string "No doubt this will be helpful for the\n"
	.string "second favor I must ask for.\p"
	.string "If you have not heard the news yet,\n"
	.string "the GYM LEADER of this town, ZHONG,\l"
	.string "has been missing for a few days.\p"
	.string "He was last seen heading towards\n"
	.string "LANTERN CAVE to rescue a lost child.\p"
	.string "He is important to this town{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong2:
	.string "I miss him so much…\n"
	.string "You'll find him, right?$"

ShuiyunTown_Dockyard_Text_Kai_RescueZhong:
	.string "Have you found ZHONG yet?\n"
	.string "He is likely still in LANTERN CAVE.$"

Movement_KaiSurprised:
	face_down
	emote_exclamation_mark
	step_end