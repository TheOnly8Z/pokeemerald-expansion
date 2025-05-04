JiangshenLake_MapScripts::
	.byte 0

.set LOCALID_AQUA_GRUNT, 1
.set LOCALID_MAGMA_GRUNT, 2

.set LOCALID_AQUA_GRUNT_2, 3
.set LOCALID_MAGMA_GRUNT_2, 4

JiangshenLake_EventScript_GruntBattle::
	lock

	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_Grunt_1_Magma MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_GRUNT, Movement_ApproachRight
	waitmovement 0
	delay 20

	speakername CommonName_Text_AquaGrunt
	msgbox JiangshenLake_Text_Grunt_2_Aqua MSGBOX_DEFAULT
	applymovement LOCALID_AQUA_GRUNT, Movement_ApproachLeft
	waitmovement 0

	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_Grunt_3_Magma MSGBOX_DEFAULT

	speakername CommonName_Text_AquaGrunt
	msgbox JiangshenLake_Text_Grunt_4_Aqua MSGBOX_DEFAULT

	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_Grunt_5_Magma MSGBOX_DEFAULT

	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE 1

	trainerbattle_two_trainers TRAINER_NEW_GRUNT_AQUA_2, JiangshenLake_Text_BattleDefeat_Aqua, TRAINER_NEW_GRUNT_MAGMA_2, JiangshenLake_Text_BattleDefeat_Magma
	call JiangshenLake_EventScript_PostGruntBattle
	end

JiangshenLake_EventScript_PostGruntBattle::
	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 2

	speakername CommonName_Text_MagmaGrunt
	@ msgbox JiangshenLake_Text_GruntPostBattle_Temp MSGBOX_DEFAULT
	msgbox JiangshenLake_Text_GruntPostBattle_1_Magma MSGBOX_DEFAULT

	speakername CommonName_Text_MagmaGrunt
	checkplayergender
	call_if_eq VAR_RESULT, MALE, JiangshenLake_EventScript_PostGruntBattle_Text2_Male
	call_if_eq VAR_RESULT, FEMALE, JiangshenLake_EventScript_PostGruntBattle_Text2_Female

	applymovement LOCALID_MAGMA_GRUNT, Movement_MagmaGruntFlee
	waitmovement 0

	speakername CommonName_Text_AquaGrunt
	msgbox JiangshenLake_Text_GruntPostBattle_3_Aqua MSGBOX_DEFAULT

	applymovement LOCALID_AQUA_GRUNT, Movement_AquaGruntFlee
	waitmovement 0

	setflag FLAG_HIDE_JIANGSHEN_BATTLE_GRUNTS
	removeobject LOCALID_MAGMA_GRUNT
	removeobject LOCALID_AQUA_GRUNT
	clearflag FLAG_HIDE_JIANGSHEN_AQUA_GRUNT
	clearflag FLAG_HIDE_JIANGSHEN_MAGMA_GRUNT

	release
	return

JiangshenLake_EventScript_PostGruntBattle_Text2_Male::
	msgbox JiangshenLake_Text_GruntPostBattle_2_Magma_He MSGBOX_DEFAULT
	return

JiangshenLake_EventScript_PostGruntBattle_Text2_Female::
	msgbox JiangshenLake_Text_GruntPostBattle_2_Magma_She MSGBOX_DEFAULT
	return

JiangshenLake_EventScript_Talk_AquaGrunt::
	@ Give keycard
	lock
	faceplayer

	speakername CommonName_Text_AquaGrunt
	msgbox JiangshenLake_Text_KeycardGrunt_1 MSGBOX_DEFAULT

	speakername NULL
	giveitem ITEM_JIANGSHEN_KEY

	speakername CommonName_Text_AquaGrunt
	msgbox JiangshenLake_Text_KeycardGrunt_2 MSGBOX_DEFAULT
	closemessage

	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepDown
	waitmovement 0

	applymovement LOCALID_AQUA_GRUNT_2, Movement_AquaLeaveAfterKeycard
	waitmovement 0
	
	setflag FLAG_HIDE_JIANGSHEN_AQUA_GRUNT
	removeobject LOCALID_AQUA_GRUNT_2
	release
	end

JiangshenLake_EventScript_Talk_MagmaGrunt::
	lock
	faceplayer

	@ If has keycard, say something and leave
	checkitem ITEM_JIANGSHEN_KEY
	goto_if_eq VAR_RESULT, TRUE, JiangshenLake_EventScript_Talk_MagmaGrunt_HasKeycard

	@ Tell them to get the keycard first
	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_GoGetKeycard MSGBOX_DEFAULT
	release
	end

JiangshenLake_EventScript_Talk_MagmaGrunt_HasKeycard::
	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_DoorGrunt_1 MSGBOX_DEFAULT
	closemessage

	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepLeft
	waitmovement 0

	applymovement LOCALID_MAGMA_GRUNT_2, Movement_MagmaLeaveAfterKeycard1
	waitmovement 0

	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown

	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_DoorGrunt_2 MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_MAGMA_GRUNT_2, Movement_MagmaLeaveAfterKeycard2
	waitmovement 0

	setflag FLAG_HIDE_JIANGSHEN_MAGMA_GRUNT
	removeobject LOCALID_MAGMA_GRUNT_2

	release
	end

JiangshenLake_Text_Grunt_1_Magma::
	.string "Target spotted!\n"
	.string "It's time for payback!$"

JiangshenLake_Text_Grunt_2_Aqua::
	.string "Did you miss us? {EMOJI_HEART}$"

JiangshenLake_Text_Grunt_3_Magma::
	.string "Haha! I knew you would try to come to\n"
	.string "JIANGSHEN LAKE and look for our\l"
	.string "SECRET HIDEOUT!\p"
	.string "And the girl found the perfect spot to\n"
	.string "ambush you as well!$"

JiangshenLake_Text_Grunt_4_Aqua::
	.string "We were watching your little journey…\n"
	.string "and we have been preparing. {EMOJI_HEART}$"

JiangshenLake_Text_Grunt_5_Magma::
	.string "Tell'em, girl! We got new POKéMON from\n"
	.string "our bosses, and trained hard!\p"
	.string "Time for payback!$"

JiangshenLake_Text_BattleIntro_Magma::
	.string "Time for payback!$"

JiangshenLake_Text_BattleIntro_Aqua::
	.string "You'll be washed ashore… {EMOJI_HEART}$"

JiangshenLake_Text_BattleDefeat_Magma::
	.string "Hu-huh?! I let the girl down!$"

JiangshenLake_Text_BattleDefeat_Aqua::
	.string "Ehehehe… {EMOJI_HEART}$"

JiangshenLake_Text_GruntPostBattle_Temp::
	.string "Gah! I'm supposed to make {PLAYER}\n"
	.string "explore the area a little more,\l"
	.string "but there's no time!\p"
	.string "Don't follow me into our secret\n"
	.string "hideout!$"

JiangshenLake_Text_GruntPostBattle_1_Magma::
	.string "Gah! Time for plan B!\p"
	.string "Take the KEYCARD with you and run EAST!\n"
	.string "I'll run WEST for the HIDEOUT!$"

JiangshenLake_Text_GruntPostBattle_2_Magma_He::
	.string "Without the KEYCARD, he won't be able\n"
	.string "to get into the HIDEOUT, and I'll have\l"
	.string "time to warn our bosses!\p"
	.string "Get outsmarted!$"

JiangshenLake_Text_GruntPostBattle_2_Magma_She::
	.string "Without the KEYCARD, she won't be able\n"
	.string "to get into the HIDEOUT, and I'll have\l"
	.string "time to warn our bosses!\p"
	.string "Get outsmarted!$"

JiangshenLake_Text_GruntPostBattle_3_Aqua::
	.string "Clever boy… I like it.\p"
	.string "Au revoir! {EMOJI_HEART}$"

JiangshenLake_Text_GoGetKeycard::
	.string "Hey! You went the wrong way!\p"
	.string "You're supposed to look for the\n"
	.string "TEAM AQUA girl for the KEYCARD first!\p"
	.string "Even if I let you in, which I won't,\n"
	.string "you can't get past the door inside!$"

JiangshenLake_Text_KeycardGrunt_1::
	.string "Oh, I've nowhere to run…\p"
	.string "Don't you dare lay a finger on me!\p"
	.string "… Just kidding. {EMOJI_HEART}\p"
	.string "Take the KEYCARD, won't you? {EMOJI_HEART}$"

JiangshenLake_Text_KeycardGrunt_2::
	.string "It's been a fun song and dance,\n"
	.string "but I'm all worn out… {EMOJI_HEART}\p"
	.string "TEAM AQUA hasn't been the same since\n"
	.string "ARCHIE left, you know. {EMOJI_HEART}\p"
	.string "There's no sense of purpose, no passion…\n"
	.string "What a heartbreaking ending. {EMOJI_HEART}\p"
	.string "But I have to say, that TEAM MAGMA boy…\n"
	.string "You really lit that fire in him, hehe. {EMOJI_HEART}\p"
	.string "Seeing him stomp around made this trip\n"
	.string "quite fun. Such a shame you won't be\l"
	.string "around to rile him up after this… {EMOJI_HEART}\p"
	.string "Oh my. I've said too much. {EMOJI_HEART}\p"
	.string "I shall go take my overdue vacation.\n"
	.string "You go and finish your… hero business.\p"
	.string "Ta-ta. {EMOJI_HEART}$"

JiangshenLake_Text_DoorGrunt_1::
	.string "Agh! You got the KEYCARD so quickly!\n"
	.string "And I totally forgot I needed it to\l"
	.string "get inside in the first place…\p"
	.string "This is all a massive failure…\p"
	.string "…\p"
	.string "When I followed COURTNEY to this island,\n"
	.string "I didn't know what I wanted to do.\p"
	.string "MAXIE's dream is over, so why am I still\n"
	.string "wearing this ridiculous, sweaty suit?\p"
	.string "I had no purpose, and I hated it!\p"
	.string "But working with the girl changed my mind.\n"
	.string "She gave me the passion to battle again!\p"
	.string "I wanted to work hard and impress her, so\n"
	.string "she'll think I'm hot stuff!\p"
	.string "… So much for that.\p"
	.string "If you see the TEAM AQUA girl again,\n"
	.string "can you tell her I almost beat you?\p"
	.string "Heh. She'll never believe that…$"

JiangshenLake_Text_DoorGrunt_2::
	.string "Kid!\p"
	.string "…Hmm, doesn't have the same ring now.\p"
	.string "{PLAYER}!\n"
	.string "Thanks for battling me. It's been fun!$"

JiangshenLake_Text_Sign::
	.string "{UP_ARROW} JIANGSHEN PEAK\n"
	.string "AUTHORIZED ACCESS ONLY$"


Movement_ApproachRight::
	walk_right
	walk_right
	walk_right
	step_end

Movement_ApproachLeft::
	walk_left
	walk_left
	walk_left
	step_end

Movement_AquaGruntFlee::
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

Movement_MagmaGruntFlee::
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Movement_PlayerStepDown:
	walk_down
	face_up
	step_end

Movement_PlayerStepLeft:
	walk_left
	face_right
	step_end

Movement_MagmaLeaveAfterKeycard1::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	delay_16
	face_up
	step_end

Movement_MagmaLeaveAfterKeycard2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Movement_AquaLeaveAfterKeycard::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end