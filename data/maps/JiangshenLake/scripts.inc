JiangshenLake_MapScripts::
	.byte 0

.set LOCALID_AQUA_GRUNT, 1
.set LOCALID_MAGMA_GRUNT, 2

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

	trainerbattle_two_trainers TRAINER_NEW_GRUNT_AQUA_2, JiangshenLake_Text_BattleDefeat_Aqua, TRAINER_NEW_GRUNT_MAGMA_2, JiangshenLake_Text_BattleDefeat_Magma
	call JiangshenLake_EventScript_PostGruntBattle
	end

JiangshenLake_EventScript_PostGruntBattle::
	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 1

	speakername CommonName_Text_MagmaGrunt
	msgbox JiangshenLake_Text_GruntPostBattle_Temp MSGBOX_DEFAULT
	@ msgbox JiangshenLake_Text_GruntPostBattle_1_Magma MSGBOX_DEFAULT

	@ speakername CommonName_Text_MagmaGrunt
	@ checkplayergender
	@ call_if_eq VAR_RESULT, MALE, JiangshenLake_EventScript_PostGruntBattle_Text2_Male
	@ call_if_eq VAR_RESULT, FEMALE, JiangshenLake_EventScript_PostGruntBattle_Text2_Female

	applymovement LOCALID_MAGMA_GRUNT, Movement_MagmaGruntFlee
	waitmovement 0

	@ speakername CommonName_Text_AquaGrunt
	@ msgbox JiangshenLake_Text_GruntPostBattle_3_Aqua MSGBOX_DEFAULT

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
	end

JiangshenLake_EventScript_Talk_MagmaGrunt::
	@ Tell them to give keycard; if given the grunt will disappear
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
	.string "Au revoir! {EMOJI_HEART}$"

JiangshenLake_Text_GoGetKeycard::
	.string "Hey! You went the wrong way!\p"
	.string "You're supposed to look for the\n"
	.string "TEAM AQUA girl for the KEYCARD first!\p"
	.string "Even if I let you in, which I won't,\n"
	.string "you can't get pass the door inside!$"

JiangshenLake_Text_KeycardGrunt_1::
	.string "Oh, I've nowhere to run…\p"
	.string "Don't you dare lay a finger on me,\n"
	.string "you pervert!\p"
	.string "… Just kidding. {EMOJI_HEART}\p"
	.string "Take the KEYCARD, won't you? {EMOJI_HEART}$"

JiangshenLake_Text_KeycardGrunt_2::
	.string "It's been a fun song and dance,\n"
	.string "but I'm all worn out… {EMOJI_HEART}\p"
	.string "After all, I only signed up to TEAM AQUA\n"
	.string "to enjoy a free trip here. {EMOJI_HEART}\p"
	.string "Go and do your… hero business. Ta-ta. {EMOJI_HEART}$"

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
