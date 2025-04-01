ShuiyunTown_Gym_MapScripts::
	.byte 0

.set LOCALID_ZHONG, 4
.set LOCALID_KAI, 6

ShuiyunTown_Gym_EventScript_TalkKai::
	@ Kai should only be here if the Kai/Zhong battle is pending
	setflag FLAG_TEMP_1
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 1, ShuiyunTown_Gym_EventScript_BattleKaiZhong
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 2, ShuiyunTown_Gym_EventScript_BattleKaiZhongRematch
	@ If state is 0 or 3, Kai should be in dockyard
	msgbox ShuiyunTown_Gym_Text_KaiNotSupposedToBeHere, MSGBOX_NPC
	setflag FLAG_HIDE_GYM_KAI
	removeobject LOCALID_KAI
	end

ShuiyunTown_Gym_EventScript_TalkZhong::
	clearflag FLAG_TEMP_1
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 1, ShuiyunTown_Gym_EventScript_BattleKaiZhong
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 2, ShuiyunTown_Gym_EventScript_BattleKaiZhongRematch
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 3, ShuiyunTown_Gym_EventScript_ZhongRemindLake

	goto_if_le VAR_SHUIYUN_GYM_QUEST_STATE, 2, ShuiyunTown_Gym_EventScript_ZhongRescued
	goto_if_lt VAR_SHUIYUN_DOCKYARD_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_ZhongRemindKai
	end

ShuiyunTown_Gym_EventScript_ZhongRescued::
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 1, ShuiyunTown_Gym_EventScript_ZhongRescuedGotParts
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 2, ShuiyunTown_Gym_EventScript_ZhongRescuedGotParts
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

ShuiyunTown_Gym_EventScript_ZhongRemindKai::
	msgbox ShuiyunTown_Gym_Text_ZhongRemindKai, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_ZhongRemindLake::
	msgbox ShuiyunTown_Gym_Text_ZhongRemindLake, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_AdviceGuy::
	goto_if_eq VAR_KAI_ZHONG_BATTLE_STATE, 3, ShuiyunTown_Gym_EventScript_AdviceGuy_PostBattle
	goto_if_ge VAR_KAI_ZHONG_BATTLE_STATE, 1, ShuiyunTown_Gym_EventScript_AdviceGuy_PreBattle
	goto_if_eq VAR_SHUIYUN_GYM_QUEST_STATE, 3, ShuiyunTown_Gym_EventScript_AdviceGuy_Saved
	msgbox ShuiyunTown_Gym_Text_AdviceGuy, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_AdviceGuy_PostBattle::
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PostBattle, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_AdviceGuy_PreBattle::
	lock
	faceplayer
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_Gym_EventScript_AdviceGuy_PreBattleDeclineAdvice
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam1, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam2, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam3, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam4, MSGBOX_DEFAULT
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam5, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_Gym_EventScript_AdviceGuy_PreBattleDeclineAdvice::
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_PreBattleDeclineAdvice, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_Gym_EventScript_AdviceGuy_Saved::
	msgbox ShuiyunTown_Gym_Text_AdviceGuy_Saved, MSGBOX_NPC
	end

ShuiyunTown_Gym_EventScript_BattleKaiZhong::
	@ First time player attempts battle
	lock
	msgbox ShuiyunTown_Gym_Text_KaiZhongBattlePreamble, MSGBOX_DEFAULT
	setvar VAR_KAI_ZHONG_BATTLE_STATE, 2
	setflag FLAG_SYS_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_VS_GYM_LEADER
	@ trainerbattle_two_trainers TRAINER_KAI_1, ShuiyunTown_Gym_Text_BattleDefeatKai, TRAINER_ZHONG_1, ShuiyunTown_Gym_Text_BattleDefeatZhong
	trainerbattle_double TRAINER_KAI_AND_ZHONG, ShuiyunTown_Gym_Text_BattleIntroKaiZhong, ShuiyunTown_Gym_Text_BattleDefeatKaiZhong, ShuiyunTown_Gym_Text_BattleNotEnoughMons, ShuiyunTown_Gym_EventScript_KaiZhongPostBattle
	release
	end

ShuiyunTown_Gym_EventScript_BattleKaiZhongRematch::
	lock
	msgbox ShuiyunTown_Gym_Text_KaiZhongBattleRematch, MSGBOX_DEFAULT
	setflag FLAG_SYS_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_VS_GYM_LEADER
	@ trainerbattle_two_trainers TRAINER_KAI_1, ShuiyunTown_Gym_Text_BattleDefeatKai, TRAINER_ZHONG_1, ShuiyunTown_Gym_Text_BattleDefeatZhong
	trainerbattle_double TRAINER_KAI_AND_ZHONG, ShuiyunTown_Gym_Text_BattleIntroKaiZhong, ShuiyunTown_Gym_Text_BattleDefeatKaiZhong, ShuiyunTown_Gym_Text_BattleNotEnoughMons, ShuiyunTown_Gym_EventScript_KaiZhongPostBattle
	release
	end

ShuiyunTown_Gym_EventScript_KaiZhongPostBattle::
	setvar VAR_KAI_ZHONG_BATTLE_STATE, 3
	msgbox ShuiyunTown_Gym_Text_KaiZhongPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_HM07
	giveitem ITEM_HM08
	msgbox ShuiyunTown_Gym_Text_KaiZhongGiveWaterfall, MSGBOX_DEFAULT
	closemessage
	call_if_set FLAG_TEMP_1, ShuiyunTown_Gym_EventScript_PlayerStepRight
	applymovement LOCALID_KAI, ShuiyunTown_Movement_KaiLeave
	waitmovement 0
	removeobject LOCALID_KAI
	setflag FLAG_HIDE_GYM_KAI
	clearflag FLAG_HIDE_DOCKYARD_KAI
	msgbox ShuiyunTown_Gym_Text_KaiZhongGoodbye, MSGBOX_DEFAULT
	closemessage
	delay 60

	@ Temporary
	fadescreen FADE_TO_BLACK
	message ShuiyunTown_Gym_Text_KaiZhongPostBattleToBeContinued
	waitmessage
	delay 40
	special StartCredits

	release
	end

ShuiyunTown_Gym_EventScript_PlayerStepRight::
	applymovement OBJ_EVENT_ID_PLAYER, ShuiyunTown_Movement_PlayerStepRight
	waitmovement 0
	return

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

ShuiyunTown_Gym_Text_ZhongRemindKai:
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
	.string "I'm glad ZHONG is back again, but with\n"
	.string "this rain business, nobody is in the\l"
	.string "mood for a GYM BATTLE…$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattle:
	.string "Yo, how's it going,\n"
	.string "CHAMPION-bound {PLAYER}?\p"
	.string "I don't know how you fired up ZHONG,\n"
	.string "but he's more excited than ever!\p"
	.string "And KAI's here to battle too, it seems!\p"
	.string "Finally, I can give some advice!\p"
	.string "ZHONG uses Flying-type POKéMON, while\n"
	.string "KAI uses Electric-type POKéMON.\p"
	.string "Their team is around Level 40, and\n"
	.string "everyone has a held item equipped.\p"
	.string "If you want, I can tell you all the\n"
	.string "juicy team details! Be warned, it'll\l"
	.string "take me a while to go through the list.$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleDeclineAdvice:
	.string "Ah shucks. If you change your mind,\n"
	.string "I'll be right here.$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam1:
	.string "Okay, let me peek at my notes…\p"
	.string "ZHONG will lead with MURKROW, who has the\n"
	.string "PRANKSTER ability and holds EVIOLITE.\p"
	.string "MURKROW is a support POKéMON who can\n"
	.string "move first with its status moves to\l"
	.string "set up TAILWIND and hinder you.\p"
	.string "Next is SCIZOR with the TECHNICIAN\n"
	.string "ability and FOCUS SASH item.\p"
	.string "It may try to set up with SWORDS DANCE,\n"
	.string "and sweep through your team with its\l"
	.string "TECHNICIAN-boosted attacks.$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam2:
	.string "Finally, there is GLISCOR with the HYPER\n"
	.string "CUTTER ability and ASSAULT VEST item.\p"
	.string "This is a durable attacker who has move\n"
	.string "coverage for every type. Worse, you\l"
	.string "can't weaken it by dropping its Attack!$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam3:
	.string "On KAI's side, he will lead with LUXRAY,\n"
	.string "who has the INTIMIDATE ability and\l"
	.string "the ASSAULT VEST item.\p"
	.string "INTIMIDATE will reduce your team's\n"
	.string "Attack on entry, so expect it to switch\l"
	.string "in and out frequently.\p"
	.string "In the back, first up is RAICHU with the\n"
	.string "LIGHTNING ROD ability, and holding the\l"
	.string "FOCUS SASH item.\p"
	.string "It's frail, fast, and more importantly,\n"
	.string "uses its LIGHTNING ROD to protect its\l"
	.string "partner from Electric-type attacks.\p"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam4:
	.string "KAI's final POKéMON is ROTOM-WASH.\p"
	.string "If you didn't know, ROTOM can take up\l"
	.string "different forms, and its Washing Machine\l"
	.string "form is Water and Electric type.\p"
	.string "It has the LEVITATE ability, making it\n"
	.string "immune to Ground-type moves, and the\l"
	.string "SITRUS BERRY item for healing.\p"
	.string "It can burn your team with WILL-O-WISP,\n"
	.string "but it can also use NASTY PLOT to boost\l"
	.string "its Special Attack to sweep your team.$"

ShuiyunTown_Gym_Text_AdviceGuy_PreBattleFullTeam5:
	.string "Whew, that's all their 6 POKéMON!\n"
	.string "I hope you paid attention to everything,\l"
	.string "otherwise you'll learn it the hard way.\p"
	.string "Good luck!$"


ShuiyunTown_Gym_Text_AdviceGuy_PostBattle:
	.string "Well I'll be damned! You really pummelled\n"
	.string "KAI and ZHONG!\p"
	.string "If you want to test yourself even further,\n"
	.string "pick a fight with some of the Trainers here.\p"
	.string "I've been told they come from some sort of……\n"
	.string "technology center? Anyways, I'm sure a battle\l"
	.string "with them will be fruitful.$"

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

ShuiyunTown_Gym_Text_KaiZhongBattlePreamble:
	.string "ZHONG: {PLAYER}, you look determined.\n"
	.string "Hope you're ready for the both of us!\p"
	.string "KAI: I figured that if TEAM AQUA and\n"
	.string "TEAM MAGMA are working together, you\l"
	.string "will have to fight double battles.\p"
	.string "KAI: Prove to us that you have what\n"
	.string "it takes to take on them together!$"

ShuiyunTown_Gym_Text_KaiZhongBattleRematch:
	.string "KAI: I don't mind a rematch, but don't\n"
	.string "expect us to go easy on you now.\p"
	.string "ZHONG: TEAM AQUA and TEAM MAGMA\n"
	.string "certainly won't!\p"
	.string "ZHONG: Now come on!$"

ShuiyunTown_Gym_Text_BattleDefeatKai:
	.string "I… what just happened?$"

ShuiyunTown_Gym_Text_BattleDefeatZhong:
	.string "Yowzers!$"

ShuiyunTown_Gym_Text_BattleIntroKaiZhong:
	.string "ZHONG: It's time to d-d-d-d-d-d-d-\n"
	.string "battle!\p"
	.string "KAI: Sigh…$"

ShuiyunTown_Gym_Text_BattleNotEnoughMons:
	.string "Bring two!$" @ Should never trigger

ShuiyunTown_Gym_Text_BattleDefeatKaiZhong:
	.string "KAI: I… what just happened?\p"
	.string "ZHONG: Yowzers! Woah! Electric!$"

ShuiyunTown_Gym_Text_KaiZhongPostBattleToBeContinued:
	.string "TO BE CONTINUED{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

ShuiyunTown_Gym_Text_KaiZhongPostBattle:
	.string "ZHONG: A full beatdown was delivered!\n"
	.string "to us! KAI, what do you think?\p"
	.string "KAI: You have proved you and your\n"
	.string "POKéMON's capabilities in battle.\p"
	.string "At this rate, TEAM AQUA and TEAM MAGMA\n"
	.string "won't stand a chance against you.\p"
	.string "ZHONG: Uhh… But where would they be?\n"
	.string "We've seen the grunts out and about,\l"
	.string "but not where their base is.\p"
	.string "KAI: I'm certain they will be at\n"
	.string "JIANGSHEN LAKE, north of SKYWARD TRAIL.\p"
	.string "If I needed a quiet spot to scheme,\n"
	.string "that's where I'd go.\p"
	.string "ZHONG: Scheme is a funny way to say\n"
	.string "“planning our honeymoon to Paldea”.\p"
	.string "KAI: ZHONG!\p"
	.string "KAI: Ahem. To go there, you'll need this.$"

ShuiyunTown_Gym_Text_KaiZhongGiveWaterfall:
	.string "KAI: You may have seen the large waterfall\n"
	.string "north of the house on SKYWARD TRAIL.\p"
	.string "Ascend the waterfall with WATERFALL, and\n"
	.string "you will reach JIANGSHEN LAKE.\p"
	.string "KAI: I also gave you DIVE, just in case\n"
	.string "there is a hidden entrance underwater.\p"
	.string "ZHONG: And definitely stop by our little\n"
	.string "hideaway house by the lake!\p"
	.string "ZHONG: Rest on the bed there, and feel\n"
	.string "free to take anything you need.\p"
	.string "KAI: ZHONG and I will stay here and\n"
	.string "continue preparing for the evacuation,\l"
	.string "just in case.\p"
	.string "KAI: Not that I'm implying you might fail…\n"
	.string "Sniffle… But please stay safe!$"

ShuiyunTown_Gym_Text_KaiZhongGoodbye:
	.string "ZHONG: KAI's just a worrywart. Go show\n"
	.string "those punks who's boss, {PLAYER}.$"

ShuiyunTown_Gym_Text_ZhongRemindLake:
	.string "ZHONG: Ah, you're still here.\n"
	.string "In case you forgot, you can reach\l"
	.string "JIANGSHEN LAKE using WATERFALL.\p"
	.string "Ascend the waterfall north of the\n"
	.string "house on SKYWARD TRAIL, and you'll\l"
	.string "reach the lake.\p"
	.string "You should stop by our house there\n"
	.string "to rest and stock up on items.$"

	
ShuiyunTown_Gym_Text_KaiNotSupposedToBeHere:
	.string "KAI: Wait, I'm not supposed to be here.$"

ShuiyunTown_Gym_EventScript_CameoGiveItem::
	msgbox ShuiyunTown_Gym_Text_DefeatedGiveItem, MSGBOX_DEFAULT
	random 10
	switch VAR_RESULT
	case 0, Script_Give_BigNugget
	case 1, Script_Give_BigNugget
	case 2, Script_Give_ExpCandy
	case 3, Script_Give_ExpCandy
	case 4, Script_Give_EjectButton
	case 5, Script_Give_RedCard
	case 6, Script_Give_FocusSash
	case 7, Script_Give_AirBalloon
	case 8, Script_Give_WhiteHerb
	case 9, Script_Give_PowerHerb
	end

Script_Give_ExpCandy::
	giveitem ITEM_EXP_CANDY_M, 3
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_BigNugget::
	giveitem ITEM_BIG_NUGGET
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end
	
Script_Give_EjectButton::
	giveitem ITEM_EJECT_BUTTON
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_RedCard::
	giveitem ITEM_RED_CARD
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_FocusSash::
	giveitem ITEM_FOCUS_SASH
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_AirBalloon::
	giveitem ITEM_AIR_BALLOON
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_WhiteHerb::
	giveitem ITEM_WHITE_HERB
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

Script_Give_PowerHerb::
	giveitem ITEM_POWER_HERB
	msgbox ShuiyunTown_Gym_Text_DefeatedBattleAgain, MSGBOX_DEFAULT
	release
	end

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
	goto ShuiyunTown_Gym_EventScript_CameoGiveItem
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
	goto ShuiyunTown_Gym_EventScript_CameoGiveItem
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
	goto ShuiyunTown_Gym_EventScript_CameoGiveItem
	release
	end

ShuiyunTown_Gym_EventScript_DeclineBattle::
	release
	end

ShuiyunTown_Gym_Text_AskBattleTrainer:
	.string "Battle {STR_VAR_1} {STR_VAR_2}?\n"
	.string "(4 Lv.50 POKéMON w/ Held Items)$"

ShuiyunTown_Gym_Text_EthanTalk:
	.string "ETHAN: My EXCADRILL is the coolest.\n"
	.string "Want to battle and see him in action?$"

ShuiyunTown_Gym_Text_EthanIntro:
	.string "Alright, you asked for it!$"

ShuiyunTown_Gym_Text_EthanDefeated:
	.string "Ah… Good game…$"
	
ShuiyunTown_Gym_Text_CollinTalk:
	.string "COLLIN: I'm down for a battle.\n"
	.string "Don't be surprised if you lose, though.$"
	
ShuiyunTown_Gym_Text_CollinIntro:
	.string "Sure.$"

ShuiyunTown_Gym_Text_CollinDefeated:
	.string "Damn…$"

ShuiyunTown_Gym_Text_NellieTalk:
	.string "NELLIE: Check out my team!\n"
	.string "It's all made up of pink POKéMON!$"
	
ShuiyunTown_Gym_Text_NellieIntro:
	.string "Get ready to get dazzled!$"

ShuiyunTown_Gym_Text_NellieDefeated:
	.string "Maybe I should take off my rose-tinted\n"
	.string "glasses and look at other colors…$"

ShuiyunTown_Gym_Text_DefeatedGiveItem:
	.string "{STR_VAR_2}: Thanks for the battle!\n"
	.string "Take this item for your victory!$"

ShuiyunTown_Gym_Text_DefeatedBattleAgain:
	.string "{STR_VAR_2}: Let's battle again\n"
	.string "sometime!$"

ShuiyunTown_Movement_PlayerStepRight:
	walk_right
	face_up
	step_end

ShuiyunTown_Movement_KaiLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end