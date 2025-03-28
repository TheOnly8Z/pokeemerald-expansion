ShuiyunTown_Gym_MapScripts::
	.byte 0

.set LOCALID_ZHONG, 4

ShuiyunTown_Gym_EventScript_TalkZhong::
	goto_if_le VAR_SHUIYUN_GYM_QUEST_STATE, 2, ShuiyunTown_Gym_EventScript_ZhongRescued
	goto_if_lt VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_RemindKai
	end

ShuiyunTown_Gym_EventScript_ZhongRescued::
	goto_if_eq VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_ZhongRescuedGotParts
	goto_if_lt VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_ZhongRescuedNoParts
	end

ShuiyunTown_Gym_EventScript_ZhongRescuedNoParts::
	@ Kai's quest not done, tell player to do that
	lock
	msgbox ShuiyunTown_Gym_Text_Zhong_SavedNoParts, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_GYM_QUEST_STATE, 3
	call ShuiyunTown_Gym_EventScript_ZhongGiveItem
	release
	end

ShuiyunTown_Gym_EventScript_ZhongRescuedGotParts::
	@ Kai's quest already done, go to beach scene
	lock
	msgbox ShuiyunTown_Gym_Text_Zhong_SavedGotParts, MSGBOX_DEFAULT
	call ShuiyunTown_Gym_EventScript_ZhongGiveItem
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZHONG
	setvar VAR_SHUIYUN_GYM_QUEST_STATE, 3
	setflag FLAG_HIDE_GYM_ZHONG
	setflag FLAG_HIDE_DOCKYARD_KAI
	clearflag FLAG_HIDE_BEACH_KAI_ZHONG
	fadescreen FADE_FROM_BLACK
	release
	end

ShuiyunTown_Gym_EventScript_ZhongGiveItem::
	msgbox ShuiyunTown_Gym_Text_Zhong_GiveItem, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
	msgbox ShuiyunTown_Gym_Text_Zhong_ExplainItem, MSGBOX_DEFAULT
	giveitem ITEM_ESCAPE_ROPE
	msgbox ShuiyunTown_Gym_Text_Zhong_ExplainItem2, MSGBOX_DEFAULT
	return

ShuiyunTown_Gym_EventScript_RemindKai::
	msgbox ShuiyunTown_Gym_Text_Zhong_RemindKai, MSGBOX_NPC
	end

	
ShuiyunTown_Gym_EventScript_AdviceGuy::
	goto_if_eq VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_AdviceGuy_Saved
	msgbox ShuiyunTown_Gym_Text_AdviceGuy, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_AdviceGuy_Saved::
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_Saved, MSGBOX_NPC
	end

ShuiyunTown_Gym_Text_Zhong_SavedNoParts:
	.string "It’s my savior!\p"
	.string "Now that I think of it, we never\n"
	.string "introduced ourselves!\p"
	.string "I’m ZHONG, the GYM LEADER of SHUIYUN\n"
	.string "TOWN. What's your name?\p"
	.string "……\p"
	.string "{PLAYER}, sent by the POKéMON LEAGUE!\n"
	.string "They didn't send word at all about you!\p"
	.string "Listen, this rain is threatening to\n"
	.string "flood the whole island.\p"
	.string "My dear KAI at the DOCKYARD has been\n"
	.string "trying to fix a ship so we can evacuate\l"
	.string "everyone, but it's not going well.\p"
	.string "I have to stay here and make sure we\n"
	.string "don't leave anyone behind, so can you\l"
	.string "talk to KAI and offer your help?$"

ShuiyunTown_Gym_Text_Zhong_RemindKai:
	.string "Have you talked to KAI at the DOCKYARD?\n"
	.string "He needs help repairing the ship, so we\l"
	.string "can evacuate everyone with it.$"


ShuiyunTown_Gym_Text_Zhong_GiveItem:
	.string "Ah, but before you go, I meant to give\n"
	.string "you some goodies!$"

ShuiyunTown_Gym_Text_Zhong_ExplainItem:
	.string "I don't know how this doohickey works,\n"
	.string "but it beeps when there are hidden\l"
	.string "items nearby.\p"
	.string "I'm sure you'll find some exotic things\n"
	.string "hidden in plain sight.\p"
	.string "There's also this!$"

ShuiyunTown_Gym_Text_Zhong_ExplainItem2:
	.string "It was silly of me not to bring one\n"
	.string "of these when going into a cave.\p"
	.string "One pull of the rope, and you'll be\n"
	.string "whisked outside of the cave safely!$"

ShuiyunTown_Gym_Text_Zhong_SavedGotParts:
	.string "It’s my savior!\p"
	.string "Now that I think of it, we never\n"
	.string "introduced ourselves!\p"
	.string "I’m ZHONG, the GYM LEADER of SHUIYUN\n"
	.string "TOWN, and you must be {PLAYER}!\p"
	.string "KAI told me you helped him repair the\n"
	.string "ship. You're a sight for sore eyes!\p"
	.string "KAI also said we should discuss the\n"
	.string "situation together, come up with a plan.\p"
	.string "We will be right outside the GYM.\n"
	.string "Take a breakand come talk to us\l"
	.string "when you're ready for the next step.$"

ShuiyunTown_Gym_Text_AdviceGuy:
	.string "Yo, how's it going,\n"
	.string "CHAMPION-bound {PLAYER}?\p"
	.string "Normally I'd tell you all about this GYM\n"
	.string "and its GYM LEADER, ZHONG…\p"
	.string "But the thing is, he left to rescue a\n"
	.string "child trapped in LANTERN CAVE.\p"
	.string "Ugh, it's been days and I'm so worried…$"

ShuiyunTown_Gym_Text_AdviceGuy_Saved:
	.string "Yo, how's it going,\n"
	.string "CHAMPION-bound {PLAYER}?\p"
	.string "GYM LEADER ZHONG is known for using\n"
	.string "ROCK-type and STEEL-type POKéMON.\p"
	.string "Of course, with this rain business,\n"
	.string "nobody is in the mood for a\l"
	.string "GYM BATTLE…$"

ShuiyunTown_Gym_Text_ManiacAskBattle:
	.string "Kukuku… I have a cool strategy.\n"
	.string "Why don't I show it to you in battle?\p"
	.string "If you win, I'll give you something\n"
	.string "real special…$"

ShuiyunTown_Gym_Text_ManiacAskBattleReject:
	.string "What a shame…$"

ShuiyunTown_Gym_Text_ManiacAskBattleAccept:
	.string "Kukuku… Let us begin!$"

ShuiyunTown_Gym_Text_ManiacDefeat:
	.string "My strategy! Aww!$"

ShuiyunTown_Gym_Text_ManiacGiveItem:
	.string "You beat me fair and square.\n"
	.string "Here's what I promised you.$"

ShuiyunTown_Gym_Text_ManiacPostBattle:
	.string "I really thought I had you…$"

ShuiyunTown_Gym_EventScript_BattleEthan::
	lock
	faceplayer
	buffertrainerclassname STR_VAR_1, TRAINER_CAMEO_ETHAN
	buffertrainername STR_VAR_2, TRAINER_CAMEO_ETHAN
	msgbox ShuiyunTown_Gym_Text_EthanTalk, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AskBattleTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_Gym_EventScript_DeclineBattle
	trainerbattle_single TRAINER_CAMEO_ETHAN, ShuiyunTown_Gym_Text_EthanIntro, ShuiyunTown_Gym_Text_EthanDefeated
	cleartrainerflag TRAINER_CAMEO_ETHAN
	release
	end

ShuiyunTown_Gym_EventScript_BattleCollin::
	lock
	faceplayer
	buffertrainerclassname STR_VAR_1, TRAINER_CAMEO_COLLIN
	buffertrainername STR_VAR_2, TRAINER_CAMEO_COLLIN
	msgbox ShuiyunTown_Gym_Text_CollinTalk, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AskBattleTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_Gym_EventScript_DeclineBattle
	trainerbattle_single TRAINER_CAMEO_COLLIN, ShuiyunTown_Gym_Text_CollinIntro, ShuiyunTown_Gym_Text_CollinDefeated
	cleartrainerflag TRAINER_CAMEO_COLLIN
	release
	end

ShuiyunTown_Gym_EventScript_BattleNellie::
	lock
	faceplayer
	buffertrainerclassname STR_VAR_1, TRAINER_CAMEO_NELLIE
	buffertrainername STR_VAR_2, TRAINER_CAMEO_NELLIE
	msgbox ShuiyunTown_Gym_Text_NellieTalk, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AskBattleTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_Gym_EventScript_DeclineBattle
	trainerbattle_single TRAINER_CAMEO_NELLIE, ShuiyunTown_Gym_Text_NellieIntro, ShuiyunTown_Gym_Text_NellieDefeated
	cleartrainerflag TRAINER_CAMEO_NELLIE
	release
	end

ShuiyunTown_Gym_EventScript_DeclineBattle::
	release
	end

ShuiyunTown_Gym_Text_AskBattleTrainer:
	.string "Battle {STR_VAR_1} {STR_VAR_2}?\n"
	.string "(4 Lv.50 POKéMON w/ Held Items)$"

ShuiyunTown_Gym_Text_EthanTalk:
	.string "ETHAN: Want to challenge me?\p"
	.string "My EXCADRILL and TYRANITAR have\n"
	.string "an unbreakable bond forged in battle.\p"
	.string "You'll be swept away in the sand!$"

ShuiyunTown_Gym_Text_EthanIntro:
	.string "Alright, you asked for it!$"

ShuiyunTown_Gym_Text_EthanDefeated:
	.string "Woah! What a match!$"
	
ShuiyunTown_Gym_Text_CollinTalk:
	.string "COLLIN: ...$"
	
ShuiyunTown_Gym_Text_CollinIntro:
	.string "Let's battle!$"

ShuiyunTown_Gym_Text_CollinDefeated:
	.string "I lost!!$"

ShuiyunTown_Gym_Text_NellieTalk:
	.string "NELLIE: ...$"
	
ShuiyunTown_Gym_Text_NellieIntro:
	.string "Let's battle!$"

ShuiyunTown_Gym_Text_NellieDefeated:
	.string "I lost!$"