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
	.string "Perhaps that's why you came?$"

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