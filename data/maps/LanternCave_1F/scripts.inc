LanternCave_1F_MapScripts::
	.byte 0

.set LOCALID_ZHONG, 14
.set LOCALID_KID, 22

LanternCave_1F_EventScript_Girl::
	msgbox LanternCave_1F_Text_Girl, MSGBOX_NPC
	end

LanternCave_1F_EventScript_LittleBoy::
	msgbox LanternCave_1F_Text_LittleBoy, MSGBOX_NPC
	end

LanternCave_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_LANTERN_GRUNT_1, LanternCave_1F_Text_Grunt1Intro, LanternCave_1F_Text_Grunt1Defeat
	msgbox LanternCave_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_LANTERN_GRUNT_2, LanternCave_1F_Text_Grunt2Intro, LanternCave_1F_Text_Grunt2Defeat
	msgbox LanternCave_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_LANTERN_GRUNT_3, LanternCave_1F_Text_Grunt3Intro, LanternCave_1F_Text_Grunt3Defeat
	msgbox LanternCave_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_LANTERN_GRUNT_4, LanternCave_1F_Text_Grunt4Intro, LanternCave_1F_Text_Grunt4Defeat
	msgbox LanternCave_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_1F_Text_GruntBringDouble::
	.string "Bring another!$"

LanternCave_1F_Text_Grunt1Intro::
	.string "I'm evil!$"

LanternCave_1F_Text_Grunt1Defeat::
	.string "I lost!$"

LanternCave_1F_Text_Grunt1PostBattle::
	.string "Owww...$"

LanternCave_1F_Text_Grunt2Intro::
	.string "I'm evil!$"

LanternCave_1F_Text_Grunt2Defeat::
	.string "I lost!$"

LanternCave_1F_Text_Grunt2PostBattle::
	.string "Owww...$"

LanternCave_1F_Text_Grunt3Intro::
	.string "I'm evil!$"

LanternCave_1F_Text_Grunt3Defeat::
	.string "I lost!$"

LanternCave_1F_Text_Grunt3PostBattle::
	.string "Owww...$"

LanternCave_1F_Text_Grunt4Intro::
	.string "I'm evil!$"

LanternCave_1F_Text_Grunt4Defeat::
	.string "I lost!$"

LanternCave_1F_Text_Grunt4PostBattle::
	.string "Owww...$"

LanternCave_1F_Text_Girl::
	.string "I thought I would be safe from\n"
	.string "the rain in this cave, but it's\l"
	.string "so uncomfortably hot and damp!\p"
	.string "I feel miserable!$"
	
LanternCave_1F_Text_LittleBoy::
	.string "Wow! You and your POKéMON\n"
	.string "pushed away those boulders so easily!$"

LanternCave_1F_EventScript_TalkZhong::
	@ VAR_SHUIYUN_GYM_QUEST_STATE
	@ 0: Never started
	@ 1: Talked and got HM Rock Smash
	@ 2: Rescued Zhong, need to talk at gym
	@ 3: Complete

	@ If player is facing north, they are talking from outside the puzzle
	@ hence NPC is not rescued
	goto_if_eq VAR_FACING, DIR_NORTH, LanternCave_1F_EventScript_ZhongNeedRescue

	@ Otherwise, NPC is being rescued
	lock
	faceplayer
	msgbox LanternCave_1F_Text_Zhong_Saved, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUIYUN_GYM_QUEST_STATE 2
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_CAVE_ZHONG
	clearflag FLAG_HIDE_GYM_ZHONG
	removeobject LOCALID_ZHONG
	removeobject LOCALID_KID
	fadescreen FADE_FROM_BLACK
	release
	end

LanternCave_1F_EventScript_ZhongNeedRescue::
	@ Repeat message
	goto_if_eq VAR_SHUIYUN_GYM_QUEST_STATE, 1, LanternCave_1F_EventScript_ZhongRescueReminder

	@ First interact, give exposition and Rock Smash
	lock
	faceplayer
	speakername CommonName_Text_Zhong
	msgbox LanternCave_1F_Text_Zhong_InitialMeet1, MSGBOX_DEFAULT
	delay 40
	speakername CommonName_Text_Zhong
	msgbox LanternCave_1F_Text_Zhong_InitialMeet2, MSGBOX_DEFAULT

	speakername NULL
	giveitem ITEM_HM06
	speakername CommonName_Text_Zhong
	msgbox LanternCave_1F_Text_Zhong_InitialMeetGivenRockSmash, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_GYM_QUEST_STATE 1
	speakername NULL
	release
	end

LanternCave_1F_EventScript_ZhongRescueReminder::
	speakername CommonName_Text_Zhong
	msgbox LanternCave_1F_Text_Zhong_RescueReminder, MSGBOX_NPC
	end


LanternCave_1F_Text_Zhong_InitialMeet1::
	.string "You there! It’s dangerous in this\n"
	.string "cave, so you should leave!$"

LanternCave_1F_Text_Zhong_InitialMeet2::
	.string "Wait…… Actually, don't leave!\n"
	.string "Help us! We're trapped!\p"
	.string "I came here to rescue a lost child, but\n"
	.string "some boulders collapsed in our way.\p"
	.string "You're a TRAINER, right?\p"
	.string "The Hidden Machine STRENGTH will let you\n"
	.string "push these boulders out of the way.\p"
	.string "I got it from the old man on SKYWARD TRAIL,\n"
	.string "but I must have lost it on the way! Argh!\p"
	.string "You should take this, though!$"

LanternCave_1F_Text_Zhong_InitialMeetGivenRockSmash::
	.string "This is the HM for ROCK SMASH.\n"
	.string "Teach this to one of your POKéMON.\l"
	.string "Then, you can smash small rock piles\l"
	.string "like the ones to your left.\p"
	.string "If only it worked against these boulders!\p"
	.string "I'd give you the HM for SURF as well,\n"
	.string "but I think I also lost that in the\l"
	.string "darkness of this cave…\p"
	.string "Please hurry!\n"
	.string "I'm getting really hungry!$"

LanternCave_1F_Text_Zhong_RescueReminder::
	.string "Did you get HM STRENGTH?\n"
	.string "I'm sure you can find it on\l"
	.string "SKYWARD TRAIL.\p"
	.string "Teach STRENGTH to one of your\n"
	.string "POKéMON, and you can push these\l"
	.string "boulders out of the way!$"

LanternCave_1F_Text_Zhong_Saved::
	.string "Smashing! We're free as a\n"
	.string "Butterfree!\p"
	.string "I need to take this kid home and\n"
	.string "eat, like, five beef bowls.\p"
	.string "Meet me at my GYM later!$"