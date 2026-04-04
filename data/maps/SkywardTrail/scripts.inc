SkywardTrail_MapScripts::
	.byte 0

.set LOCALID_COLRESS, 21

SkywardTrail_EventScript_Grunt1::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_1, SkywardTrail_Text_Grunt1Intro, SkywardTrail_Text_Grunt1Defeat
	msgbox SkywardTrail_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt2::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_2, SkywardTrail_Text_Grunt2Intro, SkywardTrail_Text_Grunt2Defeat
	msgbox SkywardTrail_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt3::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_3, SkywardTrail_Text_Grunt3Intro, SkywardTrail_Text_Grunt3Defeat
	msgbox SkywardTrail_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_Grunt4::
	trainerbattle_single TRAINER_SKYWARD_GRUNT_4, SkywardTrail_Text_Grunt4Intro, SkywardTrail_Text_Grunt4Defeat
	msgbox SkywardTrail_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SkywardTrail_EventScript_ColressTrigger::
	lock
	setvar VAR_COLRESS_1_STATE 2
	setflag FLAG_HIDE_LANTERN_CAVE_COLRESS
	setflag FLAG_RECEIVED_HM_STRENGTH

	applymovement LOCALID_COLRESS, Common_Movement_ExclamationMark
	waitmovement 0

	applymovement VAR_0x8008, SkywardTrail_Movement_WalkUp3
	waitmovement 0
	release
	goto SkywardTrail_EventScript_Colress

	end 

SkywardTrail_EventScript_ColressTriggerLeft::
	lock
	setvar VAR_COLRESS_1_STATE 2
	setflag FLAG_HIDE_LANTERN_CAVE_COLRESS
	setflag FLAG_RECEIVED_HM_STRENGTH

	applymovement LOCALID_COLRESS, Common_Movement_ExclamationMark
	waitmovement 0

	applymovement OBJ_EVENT_ID_PLAYER, SkywardTrail_Movement_WalkUp3Right1
	waitmovement 0

	release
	goto SkywardTrail_EventScript_Colress

	end 

SkywardTrail_EventScript_Colress::
	@ VAR_COLRESS_1_STATE
	@ 0: Never encountered Colress
	@ 1: Met in Lantern Cave
	@ 2: Met in Skyward Trail
	@ 3: Met in Lantern Cave, answered yes (sun)
	@ 4: Met in Lantern Cave, answered no (rain)
	@ 5: Met in Skyward Trail, answered yes (rain)
	@ 6: Met in Skyward Trail, answered no (sun)

	lock
	faceplayer

	@ First encounter variables and event
	goto_if_eq VAR_COLRESS_1_STATE, 2, SkywardTrail_EventScript_Colress_1

	@ Otherwise, go straight to battle prompt
	goto SkywardTrail_EventScript_Colress_Battle
	end

SkywardTrail_EventScript_Colress_1::
	setvar VAR_COLRESS_1_STATE, 2

	speakername CommonName_Text_Colress
	msgbox SkywardTrail_Text_Colress_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SkywardTrail_EventScript_Colress_1_NO
	goto SkywardTrail_EventScript_Colress_1_YES
	end

SkywardTrail_EventScript_Colress_1_YES::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_1_YES, MSGBOX_DEFAULT
	goto SkywardTrail_EventScript_Colress_2
	end

SkywardTrail_EventScript_Colress_1_NO::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_1_NO, MSGBOX_DEFAULT
	goto SkywardTrail_EventScript_Colress_2
	end

SkywardTrail_EventScript_Colress_2::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_2, MSGBOX_DEFAULT
	msgbox SkywardTrail_Text_Colress_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SkywardTrail_EventScript_Colress_3_NO
	goto SkywardTrail_EventScript_Colress_3_YES
	end

SkywardTrail_EventScript_Colress_3_YES::
	setvar VAR_COLRESS_1_STATE 5
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_3_YES, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_4, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	goto SkywardTrail_EventScript_Colress_Battle
	end

SkywardTrail_EventScript_Colress_3_NO::
	setvar VAR_COLRESS_1_STATE 6
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_3_NO, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_4, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	goto SkywardTrail_EventScript_Colress_Battle
	end


SkywardTrail_EventScript_Colress_Battle::
	faceplayer
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_AskBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SkywardTrail_EventScript_Colress_Battle_NO

	goto_if_eq VAR_COLRESS_1_STATE 6 SkywardTrail_EventScript_Colress_Battle_Sun
	trainerbattle_single TRAINER_COLRESS_1_RAIN, LanternCave_2F_Text_BattleIntro_Colress, LanternCave_2F_Text_Colress_Defeat, SkywardTrail_EventScript_Colress_PostBattle
	end

SkywardTrail_EventScript_Colress_Battle_Sun::
	trainerbattle_single TRAINER_COLRESS_1_SUN, LanternCave_2F_Text_BattleIntro_Colress, LanternCave_2F_Text_Colress_Defeat, SkywardTrail_EventScript_Colress_PostBattle
	end

SkywardTrail_EventScript_Colress_Battle_NO::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_RefuseBattle, MSGBOX_DEFAULT
	release
	end

SkywardTrail_EventScript_Colress_PostBattle::
	lock
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_Defeat_1, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	speakername CommonName_Text_Colress
	msgbox SkywardTrail_Text_Colress_Defeat_2, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_Defeat_3, MSGBOX_DEFAULT

	call_if_eq VAR_FACING, DIR_SOUTH, SkywardTrail_EventScript_Colress_MovePlayer

	applymovement LOCALID_COLRESS, Common_Movement_WalkUp6
	waitmovement 0

	@fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SKYWARD_TRAIL_COLRESS
	removeobject LOCALID_COLRESS
	@fadescreen FADE_FROM_BLACK
	release
	end

SkywardTrail_EventScript_Colress_MovePlayer::
	applymovement OBJ_EVENT_ID_PLAYER, SkywardTrail_Movement_WalkLeft
	waitmovement 0
	return

SkywardTrail_Text_GruntBringDouble::
	.string "Bring another!$"

SkywardTrail_Text_Grunt1Intro::
	.string "I'm evil!$"

SkywardTrail_Text_Grunt1Defeat::
	.string "I lost!$"

SkywardTrail_Text_Grunt1PostBattle::
	.string "Owww...$"

SkywardTrail_Text_Grunt2Intro::
	.string "I'm evil!$"

SkywardTrail_Text_Grunt2Defeat::
	.string "I lost!$"

SkywardTrail_Text_Grunt2PostBattle::
	.string "Owww...$"

SkywardTrail_Text_Grunt3Intro::
	.string "I'm evil!$"

SkywardTrail_Text_Grunt3Defeat::
	.string "I lost!$"

SkywardTrail_Text_Grunt3PostBattle::
	.string "Owww...$"

SkywardTrail_Text_Grunt4Intro::
	.string "I'm evil!$"

SkywardTrail_Text_Grunt4Defeat::
	.string "I lost!$"

SkywardTrail_Text_Grunt4PostBattle::
	.string "Owww...$"

SkywardTrail_EventScript_SignBridge::
	msgbox SkywardTrail_Text_Bridge, MSGBOX_SIGN
	end

SkywardTrail_EventScript_SignLab::
	msgbox SkywardTrail_Text_Lab, MSGBOX_SIGN
	end

SkywardTrail_Text_Bridge::
	.string "{LEFT_ARROW} REST STOP\n"
	.string "{RIGHT_ARROW} YONGTAI LABORATORY$"

SkywardTrail_Text_Lab::
	.string "YONGTAI LABORATORY\p"
	.string "“Always The First Wave”$"

SkywardTrail_Text_Colress_1::
.string "...Oh! A POKéMON TRAINER!\p"
.string "You must have battled many TEAM\n"
.string "AQUA GRUNTS in this heavy rain\l"
.string "to get here!\p"
.string "May I have your name?$"


SkywardTrail_Text_Colress_3::
	.string "...I have a question for you.\p"
	.string "Are your POKéMON strong because\n"
	.string "they take advantage of the rain?$"

SkywardTrail_Text_Colress_Defeat_2::
	.string "This is a HIDDEN MACHINE for the\n"
	.string "move STRENGTH I found for you.\p"
	.string "Not only is it a powerful attack\n"
	.string "that may raise the user's Defense,\l"
	.string "it also lets you push boulders!\p"
	.string "I expect this to be useful in\n"
	.string "the rock-filled LANTERN CAVES.$"


SkywardTrail_Movement_WalkLeft::
	walk_left
	step_end

SkywardTrail_Movement_WalkUp3::
	walk_up
	walk_up
	walk_up
	step_end

SkywardTrail_Movement_WalkUp3Right1::
	walk_up
	walk_right
	walk_up
	walk_up
	step_end