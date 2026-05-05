ShuiyunTown_MapScripts::
	.byte 0

.set LOCALID_DEBUGNPC, 1
.set LOCALID_KAI, 6
.set LOCALID_ZHONG, 5

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
	goto_if_unset FLAG_RECEIVED_OLD_ROD, ShuiyunTown_EventScript_Fisher_OldRod
	goto_if_unset FLAG_RECEIVED_GOOD_ROD, ShuiyunTown_EventScript_Fisher_GoodRod
	goto_if_unset FLAG_RECEIVED_SUPER_ROD, ShuiyunTown_EventScript_Fisher_SuperRod
	msgbox ShuiyunTown_Text_TalkFisher MSGBOX_NPC
	end

ShuiyunTown_EventScript_Fisher_OldRod::
	lock
	faceplayer
	msgbox ShuiyunTown_Text_TalkFisher_GiveOldRod MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	giveitem ITEM_POKE_BALL, 5
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox ShuiyunTown_Text_TalkFisher_FishGoldeen MSGBOX_DEFAULT
	release
	end

ShuiyunTown_EventScript_Fisher_GoodRod::
	lock
	faceplayer
	checkspecies SPECIES_GOLDEEN
	goto_if_eq VAR_RESULT, YES, ShuiyunTown_EventScript_Fisher_GoodRod_HasGoldeen
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_EventScript_Fisher_GoodRod_NoGoldeen

ShuiyunTown_EventScript_Fisher_GoodRod_HasGoldeen::
	msgbox ShuiyunTown_Text_TalkFisher_CheckGoldeenSuccess, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	giveitem ITEM_GREAT_BALL, 5
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox ShuiyunTown_Text_TalkFisher_GiveGoodRod, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_EventScript_Fisher_GoodRod_NoGoldeen::
	msgbox ShuiyunTown_Text_TalkFisher_CheckGoldeen, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_EventScript_Fisher_SuperRod::
	lock
	faceplayer
	checkspecies SPECIES_CARVANHA
	goto_if_eq VAR_RESULT, YES, ShuiyunTown_EventScript_Fisher_SuperRod_HasCarvanha
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_EventScript_Fisher_SuperRod_NoCarvanha

ShuiyunTown_EventScript_Fisher_SuperRod_HasCarvanha::
	msgbox ShuiyunTown_Text_TalkFisher_CheckCarvanhaSuccess, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox ShuiyunTown_Text_TalkFisher_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_NET_BALL, 20
	msgbox ShuiyunTown_Text_TalkFisher_GiveNetBall, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_EventScript_Fisher_SuperRod_NoCarvanha::
	msgbox ShuiyunTown_Text_TalkFisher_CheckCarvanha, MSGBOX_DEFAULT
	release
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
	.string "Perhaps that's why you came?\p"
	.string "If so, you should head for the\n"
	.string "DOCKYARD north of the POKé MART.\p"
	.string "I heard they're in need of a\n"
	.string "capable TRAINER like you.$"

ShuiyunTown_Text_TalkFisher_GiveOldRod:
	.string "This island is great for fishing!\n"
	.string "Here, give it a try!$"

ShuiyunTown_Text_TalkFisher_FishGoldeen:
	.string "This basic rod will get you started.\p"
	.string "To use a fishing rod, stand in front of\n"
	.string "a body of water and use the item.\p"
	.string "When you get a bite, press A at the\n"
	.string "right moment, and you'll fish it up!\p"
	.string "If you can fish up a GOLDEEN, I'll\n"
	.string "consider giving you a better rod!$"

ShuiyunTown_Text_TalkFisher_CheckGoldeen:
	.string "To use a fishing rod, stand in front of\n"
	.string "a body of water and use the item.\p"
	.string "When you get a bite, press A at the\n"
	.string "right moment, and you'll fish it up!\p"
	.string "If you show me a GOLDEEN you caught,\n"
	.string "I'll give you a better rod!$"

ShuiyunTown_Text_TalkFisher_CheckGoldeenSuccess:
	.string "Ah, most impressive!\n"
	.string "I simply can't not give you this!$"

ShuiyunTown_Text_TalkFisher_GiveGoodRod:
	.string "This rod will catch more POKéMON!\n"
	.string "They're tougher, so you may need to.\l"
	.string "pull on the rod several times.\p"
	.string "You can find different POKéMON by\n"
	.string "fishing in different areas.\p"
	.string "If you can fish up a CARVANHA, I'll give\n"
	.string "you my best rod.\p"
	.string "CARVANHA can only be fished up on\n"
	.string "SKYWARD TRAIL with your GOOD ROD!$"

ShuiyunTown_Text_TalkFisher_CheckCarvanha:
	.string "If you can fish up a CARVANHA, I'll give\n"
	.string "you my best rod.\p"
	.string "CARVANHA can only be fished up on\n"
	.string "SKYWARD TRAIL with your GOOD ROD!$"

ShuiyunTown_Text_TalkFisher_CheckCarvanhaSuccess:
	.string "Oh man! You're getting good at this!\n"
	.string "You deserve the best rod there is!$"

ShuiyunTown_Text_TalkFisher_GiveSuperRod:
	.string "You'll find rare POKéMON with this rod.\n"
	.string "Try it out in different areas!\p"
	.string "And since you're such an inspiration,\n"
	.string "I want you to have these as well!$"

ShuiyunTown_Text_TalkFisher_GiveNetBall:
	.string "NET BALLS are great for catching\n"
	.string "Water-type and Bug-type POKéMON.\l"
	.string "It's useful for fishing!\p"
	.string "I have given you all I have.\n"
	.string "Now, go and enjoy fishing!$"

ShuiyunTown_Text_TalkFisher:
	.string "Do you know what this weather means?\n"
	.string "That's right, more fish!$"

ShuiyunTown_Text_DebugGiveHM:
	.string "I'm a debug NPC who will give you\n"
	.string "a POKéMON with all the needed HMs.\p"
	.string "Enjoy!$"

ShuiyunTown_EventScript_TalkKaiZhong::
	lock
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition1Kai, MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition1Zhong, MSGBOX_DEFAULT
	closemessage

	delay 40

	@ Zhong notices player
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_Surprise
	waitmovement 0
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FacePlayer
	waitmovement 0

	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition1NoticePlayer, MSGBOX_DEFAULT

	@ Zhong and Kai move into dialog position
	@ If player talks from the east or west, one NPC has to move north
	call_if_eq VAR_FACING, DIR_EAST, ShuiyunTown_EventScript_MoveKaiZhongLeft
	call_if_eq VAR_FACING, DIR_WEST, ShuiyunTown_EventScript_MoveKaiZhongRight
	call_if_eq VAR_FACING, DIR_SOUTH, ShuiyunTown_EventScript_MoveKaiZhongUp

	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition2Kai, MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition2Zhong, MSGBOX_DEFAULT

	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition3Kai, MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition3Zhong, MSGBOX_DEFAULT


	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition4Kai, MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition4Zhong, MSGBOX_DEFAULT


	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition5Kai, MSGBOX_DEFAULT
	closemessage

	delay 40
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition5Turn, MSGBOX_DEFAULT

	@ Kai and Zhong turn to each other for a few sentences
	call_if_eq VAR_FACING, DIR_EAST, ShuiyunTown_EventScript_ZhongKaiFaceEachOtherEast
	call_if_eq VAR_FACING, DIR_WEST, ShuiyunTown_EventScript_ZhongKaiFaceEachOtherWest
	call_if_eq VAR_FACING, DIR_SOUTH, ShuiyunTown_EventScript_ZhongKaiFaceEachOtherSouth

	checkplayergender
	call_if_eq VAR_RESULT, MALE, ShuiyunTown_EventScript_TalkKaiZhongExposition5He
	call_if_eq VAR_RESULT, FEMALE, ShuiyunTown_EventScript_TalkKaiZhongExposition5She

	@ Zhong forgor
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition8Pause, MSGBOX_DEFAULT

	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_Surprise
	waitmovement 0

	@ He remembers
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition8Zhong, MSGBOX_DEFAULT

	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition8Kai, MSGBOX_DEFAULT

	

	@ Turn back to face player
	call_if_eq VAR_FACING, DIR_EAST, ShuiyunTown_EventScript_ZhongKaiFacePlayerEast
	call_if_eq VAR_FACING, DIR_WEST, ShuiyunTown_EventScript_ZhongKaiFacePlayerWest
	call_if_eq VAR_FACING, DIR_SOUTH, ShuiyunTown_EventScript_ZhongKaiFacePlayerSouth

	@ blah blah blah

	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition9Zhong, MSGBOX_DEFAULT
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition9Kai, MSGBOX_DEFAULT

	@ Zhong goes into the gym
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition10Zhong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, ShuiyunTown_EventScript_MoveZhongGymRight
	call_if_eq VAR_FACING, DIR_WEST, ShuiyunTown_EventScript_MoveZhongGymUpRight
	call_if_eq VAR_FACING, DIR_SOUTH, ShuiyunTown_EventScript_MoveZhongGymRightUp
	opendoor 13, 20
	waitdooranim
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_StepUp
	waitmovement 0
	removeobject LOCALID_ZHONG
	closedoor 13, 20
	
	@ Kai goes into the gym
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition10Kai MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, ShuiyunTown_EventScript_MoveKaiGymRightUp
	call_if_eq VAR_FACING, DIR_WEST, ShuiyunTown_EventScript_MoveKaiGymRight
	call_if_eq VAR_FACING, DIR_SOUTH, ShuiyunTown_EventScript_MoveKaiGymRightUp
	opendoor 13, 20
	waitdooranim
	applymovement LOCALID_KAI, ShuiyunTown_Movement_StepUp
	waitmovement 0
	removeobject LOCALID_KAI
	closedoor 13, 20
	waitdooranim

	@ Donezos
	setflag FLAG_HIDE_BEACH_KAI_ZHONG
	clearflag FLAG_HIDE_GYM_KAI
	clearflag FLAG_HIDE_GYM_ZHONG
	setvar VAR_KAI_ZHONG_BATTLE_STATE 1
	release
	end

	@ fadescreen FADE_TO_BLACK
	@ message ShuiyunTown_Text_KaiZhong_ToBeContinued
	@ waitmessage
	@ delay 20
	@ special StartCredits


ShuiyunTown_EventScript_TalkKaiZhongExposition5He::
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition5He MSGBOX_DEFAULT
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition6He MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition7He MSGBOX_DEFAULT
	return

ShuiyunTown_EventScript_TalkKaiZhongExposition5She::
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition5She MSGBOX_DEFAULT
	speakername CommonName_Text_Kai
	msgbox ShuiyunTown_Text_KaiZhong_Exposition6She MSGBOX_DEFAULT
	speakername CommonName_Text_Zhong
	msgbox ShuiyunTown_Text_KaiZhong_Exposition7She MSGBOX_DEFAULT
	return


ShuiyunTown_EventScript_MoveKaiZhongRight::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_StepUpRight
	waitmovement 0
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceRight
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveKaiZhongLeft::
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_StepUpLeft
	waitmovement 0
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceLeft
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveKaiZhongUp::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceUp
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveZhongGymUpRight::
	@ Player is to the right and Kai is above, so Kai takes a step back
	applymovement LOCALID_KAI, ShuiyunTown_Movement_StepLeftFaceRight
	waitmovement 0
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_StepUp1Right2
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveZhongGymRightUp::
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_StepRight2Up1
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveZhongGymRight::
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_StepRight3
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveKaiGymRight::
	@ In Kai's original position it would only take 2 steps,
	@ But he steps left to make space for Zhong
	applymovement LOCALID_KAI, ShuiyunTown_Movement_StepRight3
	waitmovement 0
	return

ShuiyunTown_EventScript_MoveKaiGymRightUp::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_StepRight3Up1
	waitmovement 0
	return

ShuiyunTown_EventScript_ZhongKaiFaceEachOtherEast::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceUp
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceDown
	waitmovement 0
	return

ShuiyunTown_EventScript_ZhongKaiFaceEachOtherWest::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceDown
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceUp
	waitmovement 0
	return

ShuiyunTown_EventScript_ZhongKaiFaceEachOtherSouth::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceRight
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceLeft
	waitmovement 0
	return

ShuiyunTown_EventScript_ZhongKaiFacePlayerEast::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceLeft
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceLeft
	waitmovement 0
	return
	
ShuiyunTown_EventScript_ZhongKaiFacePlayerWest::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceRight
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceRight
	waitmovement 0
	return
	
ShuiyunTown_EventScript_ZhongKaiFacePlayerSouth::
	applymovement LOCALID_KAI, ShuiyunTown_Movement_FaceUp
	applymovement LOCALID_ZHONG, ShuiyunTown_Movement_FaceUp
	waitmovement 0
	return

ShuiyunTown_Text_KaiZhong_Exposition1Kai::
	.string "The rain isn’t letting up.$"

ShuiyunTown_Text_KaiZhong_Exposition1Zhong::
	.string "Even in the sweltering LANTERN CAVE,\n"
	.string "I could see the water level rise with\l"
	.string "my bare eyes…$"

ShuiyunTown_Text_KaiZhong_Exposition1NoticePlayer::
	.string "Ah, it's {PLAYER}! Tremendous!\n"
	.string "Let's get this conversation started!$"

ShuiyunTown_Text_KaiZhong_Exposition2Kai::
	.string "Pfft, you dork.\p"
	.string "Alright, let me summarize our\n"
	.string "current situation.\p"
	.string "The folks at the DOCKYARD has\n"
	.string "installed the parts you delivered.\p"
	.string "The ship is sea-worthy now,\n"
	.string "although the weather is still very\l"
	.string "dangerous to sail in.$"

ShuiyunTown_Text_KaiZhong_Exposition2Zhong::
	.string "Doesn't take a PhD to realize\n"
	.string "the weather is abnormal.\p"
	.string "{PLAYER}, you travelled around\n"
	.string "the most. Did you notice anything?$"

ShuiyunTown_Text_KaiZhong_Exposition3Kai::
	.string "TEAM AQUA and TEAM MAGMA,\n"
	.string "working together?$"

ShuiyunTown_Text_KaiZhong_Exposition3Zhong::
	.string "Huh? Those guys hate each other!\n"
	.string "Also, they disbanded! It was all over\l"
	.string "the news months ago!$"

ShuiyunTown_Text_KaiZhong_Exposition4Kai::
	.string "Must be stubborn holdouts without their\n"
	.string "original leaders in charge.\p"
	.string "Judging by the weather, they likely\n"
	.string "still have control of KYOGRE and GROUDON,\l"
	.string "who are duking it out as we speak.$"

ShuiyunTown_Text_KaiZhong_Exposition4Zhong::
	.string "The way I see it, KYOGRE is surrounded.\n"
	.string "But so is GROUDON!\p"
	.string "They are evenly matched, and the only\n"
	.string "thing that can stop them is RAYQUAZA!$"

ShuiyunTown_Text_KaiZhong_Exposition5Kai::
	.string "We know too little about their\n"
	.string "plans, and there's too little time.\l"
	.string "We must proceed with the evacuation.$"

ShuiyunTown_Text_KaiZhong_Exposition5Turn::
	.string "{PLAYER}, you seem unhappy about\n"
	.string "this decision somehow.$"

ShuiyunTown_Text_KaiZhong_Exposition5He::
	.string "Of course he would! He saved my sorry\n"
	.string "arse, picked up your slack,\l"
	.string "and we're just gonna shrug and run away\n"
	.string "instead of repaying the favor?$"

ShuiyunTown_Text_KaiZhong_Exposition5She::
	.string "Of course she would! She saved my sorry\n"
	.string "arse, picked up your slack,\l"
	.string "and we're just gonna shrug and run away\n"
	.string "instead of repaying the favor?$"

ShuiyunTown_Text_KaiZhong_Exposition6He::
	.string "{PLAYER} is capable, but asking\n"
	.string "him to face off against TEAM\l"
	.string "AQUA and MAGMA, who both control\l"
	.string "legendary POKéMON?\p"
	.string "I cannot ask him to risk his life\n"
	.string "like this.$"

ShuiyunTown_Text_KaiZhong_Exposition6She::
	.string "{PLAYER} is capable, but asking\n"
	.string "her to face off against TEAM\l"
	.string "AQUA and MAGMA, who both control\l"
	.string "legendary POKéMON?\p"
	.string "I cannot ask her to risk his life\n"
	.string "like this.$"

ShuiyunTown_Text_KaiZhong_Exposition7He::
	.string "Maybe he's stronger than you think.\p"
	.string "If only there was a way to prove\n"
	.string "someone's skills at POKéMON battles!$"

ShuiyunTown_Text_KaiZhong_Exposition7She::
	.string "Maybe she's stronger than you think.\p"
	.string "If only there was a way to prove\n"
	.string "someone's skills at POKéMON battles!$"

ShuiyunTown_Text_KaiZhong_Exposition8Pause::
	.string "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

ShuiyunTown_Text_KaiZhong_Exposition8Zhong::
	.string "Oh wait, I'm a GYM LEADER!\n"
	.string "We can just battle it out at my GYM!$"

ShuiyunTown_Text_KaiZhong_Exposition8Kai::
	.string "You are… as quick-witted as a\n"
	.string "SLOWPOKE…$"

ShuiyunTown_Text_KaiZhong_Exposition9Zhong:
	.string "I had this whole thing where you had\n"
	.string "to answer a quiz while balancing\l"
	.string "on a unicycle, but we can skip the\l"
	.string "formalities.\p"
	.string "KAI, you should come as well.\n"
	.string "It's been a while, right?$"

ShuiyunTown_Text_KaiZhong_Exposition9Kai:
	.string "Can't argue with that. Besides, I\n"
	.string "want to see {PLAYER}'s skills myself.$"

ShuiyunTown_Text_KaiZhong_Exposition10Zhong:
	.string "Perfectamundo!\n"
	.string "See you at the GYM, {PLAYER}!$"

ShuiyunTown_Text_KaiZhong_Exposition10Kai:
	.string "At least he's in good spirits…$"

ShuiyunTown_Text_KaiZhong_ToBeContinued:
	.string "TO BE CONTINUED{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

ShuiyunTown_Movement_FaceUp:
	face_up
	step_end

ShuiyunTown_Movement_FaceRight:
	face_right
	step_end

ShuiyunTown_Movement_FaceLeft:
	face_left
	step_end

ShuiyunTown_Movement_FaceDown:
	face_down
	step_end

ShuiyunTown_Movement_FacePlayer:
	face_player
	step_end

ShuiyunTown_Movement_StepRight:
	walk_right
	step_end

ShuiyunTown_Movement_StepUpRight:
	walk_up
	walk_right
	step_end

ShuiyunTown_Movement_StepUpLeft:
	walk_up
	walk_left
	step_end

ShuiyunTown_Movement_StepLeftFaceRight:
	walk_left
	face_right
	step_end

ShuiyunTown_Movement_StepUp:
	walk_up
	step_end

ShuiyunTown_Movement_StepUp1Right2:
	walk_up
	walk_right
	walk_right
	face_up
	step_end

ShuiyunTown_Movement_StepRight2Up1:
	walk_right
	walk_right
	walk_up
	face_up
	step_end
	
ShuiyunTown_Movement_StepRight3Up1:
	walk_right
	walk_right
	walk_right
	walk_up
	face_up
	step_end

ShuiyunTown_Movement_StepRight2:
	walk_right
	walk_right
	face_up
	step_end

ShuiyunTown_Movement_StepRight3:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

ShuiyunTown_Movement_Surprise:
	emote_exclamation_mark
	step_end

ShuiyunTown_EventScript_TestBattleColress::
	lock
	faceplayer
	trainerbattle_single TRAINER_COLRESS_RAYQUAZA, ShuiyunTown_Text_ColressIntro, ShuiyunTown_Text_ColressDefeated
	cleartrainerflag TRAINER_COLRESS_RAYQUAZA
	release
	end

ShuiyunTown_Text_ColressIntro:
	.string "go go gadget mega rayquaza$"

ShuiyunTown_Text_ColressDefeated:
	.string "wtf are those zu shitmons$"
	
