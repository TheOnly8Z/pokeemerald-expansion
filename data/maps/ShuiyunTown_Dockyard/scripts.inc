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

	@ Remind player to go to lake
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 3, ShuiyunTown_Dockyard_EventScript_TalkKaiPostBattle

	@ If player has ship parts, hand in the quest
	checkitem ITEM_SHIP_PARTS
	goto_if_eq VAR_RESULT, TRUE, ShuiyunTown_Dockyard_EventScript_TalkKaiGotParts

	@ In the middle of some quest
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1, ShuiyunTown_Dockyard_EventScript_TalkKaiRepeat
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_TalkKaiRescueZhong

	@ First meeting
	lock
	call_if_eq VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_KaiFirstMeetZhongRescued
	call_if_ne VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_KaiFirstMeetZhongNotRescued
	msgbox ShuiyunTown_Dockyard_Text_Kai_Exposition, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Dockyard_Text_Kai_AskFetch, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 1
	release
	end

ShuiyunTown_Dockyard_EventScript_TalkKaiPostBattle::
	msgbox ShuiyunTown_Dockyard_Text_Kai_PostBattle, MSGBOX_NPC

ShuiyunTown_Dockyard_EventScript_KaiFirstMeetZhongNotRescued::
	msgbox ShuiyunTown_Dockyard_Text_Kai_Muttering, MSGBOX_DEFAULT
	applymovement LOCALID_KAI, Movement_KaiSurprised
	waitmovement 0
	delay 20
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_FirstMeet, MSGBOX_DEFAULT
	return

ShuiyunTown_Dockyard_EventScript_KaiFirstMeetZhongRescued::
	faceplayer
	msgbox ShuiyunTown_Dockyard_Text_Kai_FirstMeetZhongRescued, MSGBOX_DEFAULT
	return

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
	call_if_eq VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_KaiMeetAtBeach
	call_if_ne VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Dockyard_EventScript_KaiAskToRescueZhong
	release
	end

ShuiyunTown_Dockyard_EventScript_KaiAskToRescueZhong::
	msgbox ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong1, MSGBOX_DEFAULT
	delay 20
	msgbox ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong2, MSGBOX_DEFAULT
	return

ShuiyunTown_Dockyard_EventScript_KaiMeetAtBeach::
	msgbox ShuiyunTown_Dockyard_Text_Kai_FetchHandinRescued, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KAI
	setflag FLAG_HIDE_GYM_ZHONG
	setflag FLAG_HIDE_DOCKYARD_KAI
	clearflag FLAG_HIDE_BEACH_KAI_ZHONG
	fadescreen FADE_FROM_BLACK
	return

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

ShuiyunTown_Dockyard_Text_Kai_FirstMeetZhongRescued:
	.string "???: {PLAYER}, right?\n"
	.string "I'm DOCKMASTER KAI.\p"
	.string "Thank you for rescuing ZHONG.\n"
	.string "He is very important to me -\l"
	.string "and everyone else, of course.\p"
	.string "With that said, there's another matter\n"
	.string "that requires your assistance.$"

ShuiyunTown_Dockyard_Text_Kai_Exposition:
	.string "KAI: This rain is flooding JIANGSHEN LAKE.\n"
	.string "The water is threatening to overflow\l"
	.string "and claim the entire island.\n"
	.string "We are trying to evacuate everyone using\n"
	.string "a damaged cruise ship in the docks.$"

ShuiyunTown_Dockyard_Text_Kai_AskFetch:
	.string "KAI: Some critical parts for the repair\n"
	.string "are in the LABORATORY on SKYWARD TRAIL.\p"
	.string "Both the weather and interference from\n"
	.string "TEAM AQUA make the journey difficult\l"
	.string "for anyone who isn't a TRAINER.\p"
	.string "All hands are full here, so I must ask\n"
	.string "you to retrieve those parts for me.\p"
	.string "If you need help, visit the house near\n"
	.string "the top of the trail.\p"
	.string "Exercise caution.$"

ShuiyunTown_Dockyard_Text_Kai_Repeat:
	.string "KAI: Ah, did you get the ship parts?\p"
	.string "The parts are in the LABORATORY on top\n"
	.string "of SKYWARD TRAIL."
	.string "There's a house on the way there.\n"
	.string "Visit there if you need help.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin1:
	.string "???: Ah-{PAUSE 15}Ahem. You must be new.\n"
	.string "What's that? You have a package for me?\p"
	.string "{PLAYER} handed over the SHIP PARTS.\p"
	.string "???: Thank you. This is very important.\p"
	.string "KAI: I'm DOCKMASTER KAI.\n"
	.string "What's your name?\p"
	.string "…{PAUSE 15}…\p"
	.string "{PLAYER}, and you're here on behalf\n"
	.string "of the POKéMON LEAGUE?\p"
	.string "I am glad the LEAGUE sent such a\n"
	.string "capable TRAINER. Let me explain what\l"
	.string "is going on here.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin2:
	.string "KAI: The parts you just delievered\n"
	.string "were crucial to the repair effort.\p"
	.string "I'd like you to have this as thanks.$"

ShuiyunTown_Dockyard_Text_Kai_SkipHandin3:
	.string "KAI: This will allow you to travel\n"
	.string "quickly, even up slippery cliff slopes.$"

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
	.string "KAI: We need to evaluate the situation with\n"
	.string "ZHONG and consider our options.\p"
	.string "Let’s rendezvous outside the GYM.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong1:
	.string "KAI: No doubt this will be helpful for the\n"
	.string "second favor I must ask for.\p"
	.string "If you have not heard the news yet,\n"
	.string "the GYM LEADER of this town, ZHONG,\l"
	.string "has been missing for a few days.\p"
	.string "He was last seen heading towards\n"
	.string "LANTERN CAVE to rescue a lost child.\p"
	.string "He is important to this town{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

ShuiyunTown_Dockyard_Text_Kai_FetchHandinZhong2:
	.string "KAI: I miss him so much…\n"
	.string "You'll find him, right?$"

ShuiyunTown_Dockyard_Text_Kai_RescueZhong:
	.string "KAI: Have you found ZHONG yet?\n"
	.string "He is likely still in LANTERN CAVE.$"

ShuiyunTown_Dockyard_Text_Kai_PostBattle:
	.string "KAI: How goes your investigation?\p"
	.string "In case you forgot, you can reach\l"
	.string "JIANGSHEN LAKE using WATERFALL.\p"
	.string "Ascend the waterfall north of the\n"
	.string "house on SKYWARD TRAIL, and you'll\l"
	.string "reach the lake.\p"
	.string "You should stop by our house there\n"
	.string "to rest and stock up on items.$"

Movement_KaiSurprised:
	face_down
	emote_exclamation_mark
	step_end