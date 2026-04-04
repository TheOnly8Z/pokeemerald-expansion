LanternCave_2F_MapScripts::
	.byte 0

.set LOCALID_COLRESS, 15

LanternCave_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_LANTERN_GRUNT_5, LanternCave_2F_Text_Grunt5Intro, LanternCave_2F_Text_Grunt5Defeat
	msgbox LanternCave_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_LANTERN_GRUNT_6, LanternCave_2F_Text_Grunt6Intro, LanternCave_2F_Text_Grunt6Defeat
	msgbox LanternCave_2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

LanternCave_2F_Text_Grunt5Intro:
	.string "I'm evil!$"

LanternCave_2F_Text_Grunt5Defeat:
	.string "I lost!$"

LanternCave_2F_Text_Grunt5PostBattle:
	.string "Owww...$"

LanternCave_2F_Text_Grunt6Intro:
	.string "I'm evil!$"

LanternCave_2F_Text_Grunt6Defeat:
	.string "I lost!$"

LanternCave_2F_Text_Grunt6PostBattle:
	.string "Owww...$"

LanternCave_2F_EventScript_ColressTrigger::
	lock
	setvar VAR_COLRESS_1_STATE 1
	setflag FLAG_HIDE_SKYWARD_TRAIL_COLRESS
	setflag FLAG_RECEIVED_HM_SURF

	applymovement LOCALID_COLRESS, Common_Movement_ExclamationMark
	waitmovement 0

	applymovement OBJ_EVENT_ID_PLAYER, LanternCave_2F_Movement_WalkUp3
	waitmovement 0

	release
	goto LanternCave_2F_EventScript_Colress

	end 

LanternCave_2F_EventScript_Colress::
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
	goto_if_eq VAR_COLRESS_1_STATE, 1, LanternCave_2F_EventScript_Colress_1

	@ Otherwise, go straight to battle prompt
	goto LanternCave_2F_EventScript_Colress_Battle
	end

LanternCave_2F_EventScript_Colress_1::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LanternCave_2F_EventScript_Colress_1_NO
	goto LanternCave_2F_EventScript_Colress_1_YES
	end

LanternCave_2F_EventScript_Colress_1_YES::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_1_YES, MSGBOX_DEFAULT
	goto LanternCave_2F_EventScript_Colress_2
	end

LanternCave_2F_EventScript_Colress_1_NO::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_1_NO, MSGBOX_DEFAULT
	goto LanternCave_2F_EventScript_Colress_2
	end

LanternCave_2F_EventScript_Colress_2::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_2, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LanternCave_2F_EventScript_Colress_3_NO
	goto LanternCave_2F_EventScript_Colress_3_YES
	end

LanternCave_2F_EventScript_Colress_3_YES::
	setvar VAR_COLRESS_1_STATE 3
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_3_YES, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_4, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	goto LanternCave_2F_EventScript_Colress_Battle
	end

LanternCave_2F_EventScript_Colress_3_NO::
	setvar VAR_COLRESS_1_STATE 4
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_3_NO, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_4, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	goto LanternCave_2F_EventScript_Colress_Battle
	end

LanternCave_2F_EventScript_Colress_Battle::
	faceplayer
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_AskBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LanternCave_2F_EventScript_Colress_Battle_NO

	goto_if_eq VAR_COLRESS_1_STATE 3 LanternCave_2F_EventScript_Colress_Battle_Sun
	trainerbattle_single TRAINER_COLRESS_1_RAIN, LanternCave_2F_Text_BattleIntro_Colress, LanternCave_2F_Text_Colress_Defeat, LanternCave_2F_EventScript_Colress_PostBattle
	end

LanternCave_2F_EventScript_Colress_Battle_Sun::
	trainerbattle_single TRAINER_COLRESS_1_SUN, LanternCave_2F_Text_BattleIntro_Colress, LanternCave_2F_Text_Colress_Defeat, LanternCave_2F_EventScript_Colress_PostBattle
	end

LanternCave_2F_EventScript_Colress_Battle_NO::
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_RefuseBattle, MSGBOX_DEFAULT
	release
	end

LanternCave_2F_EventScript_Colress_PostBattle::
	lock
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_Defeat_1, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	speakername CommonName_Text_Colress
	msgbox LanternCave_2F_Text_Colress_Defeat_2, MSGBOX_DEFAULT
	msgbox LanternCave_2F_Text_Colress_Defeat_3, MSGBOX_DEFAULT

	call_if_eq VAR_FACING, DIR_EAST, LanternCave_2F_EventScript_Colress_MovePlayer

	applymovement LOCALID_COLRESS, LanternCave_Movement_WalkRight8
	waitmovement 0

	@ fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_LANTERN_CAVE_COLRESS
	removeobject LOCALID_COLRESS
	@ fadescreen FADE_FROM_BLACK

	release
	end

LanternCave_2F_EventScript_Colress_MovePlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	return

LanternCave_2F_Text_Colress_1::
	.string "...Oh! A POKéMON TRAINER!\p"
	.string "You must have battled many TEAM\n"
	.string "MAGMA GRUNTS under this scorching\l"
	.string "heat to get here!\p"
	.string "May I have your name?$"

LanternCave_2F_Text_Colress_1_YES:
	.string "Pleased to meet you, {PLAYER}.\n"
	.string "I am COLRESS, a POKéMON researcher.$"

LanternCave_2F_Text_Colress_1_NO:
	.string "Oh, but where are my manners!\n"
	.string "I am COLRESS, a POKéMON researcher.$"

LanternCave_2F_Text_Colress_2:
	.string "I'm passionate about research into the\n"
	.string "potential of POKéMON!\p"
	.string "We live together with POKéMON, so it's a\n"
	.string "disservice if we don't help them become\l"
	.string "stronger!\p"
	.string "That's why when I heard rumors of\n"
	.string "legendary POKéMON on this island,\l"
	.string "I traveled here all the way from UNOVA!$"

LanternCave_2F_Text_Colress_3::
	.string "...I have a question for you.\p"
	.string "Are your POKéMON strong because\n"
	.string "they take advantage of the heat?$"

LanternCave_2F_Text_Colress_3_YES:
	.string "Fascinating...\n"
	.string "You embrace the harsh weather\l"
	.string "to maximize their potential!$"

LanternCave_2F_Text_Colress_3_NO:
	.string "Fascinating...\n"
	.string "You defy the harsh weather\l"
	.string "to bring out their true power!$"

LanternCave_2F_Text_Colress_4:
	.string "Your words gave me an idea.\n"
	.string "I would like to perform an\l"
	.string "expriment through a battle.\p"
	.string "Let me heal your POKéMON so they\n"
	.string "can be at their peak condition.$"

LanternCave_2F_Text_Colress_AskBattle:
	.string "Will you battle me and help prove\n"
	.string "my hypothesis?$"

LanternCave_2F_Text_BattleIntro_Colress:
	.string "Excellent!\n"
	.string "Let our experiment begin!$"

LanternCave_2F_Text_Colress_RefuseBattle:
	.string "Ah, are you busy, perhaps?\p"
	.string "You will not go unrewarded, so\n"
	.string "do come back when you're ready!$"

LanternCave_2F_Text_Colress_Defeat::
	.string "Our results are logged.\n"
	.string "There is much to learn!$"

LanternCave_2F_Text_Colress_Defeat_1:
	.string "... I see!\p"
	.string "Your approach has shown merit...\n"
	.string "Yet I spot another unexplained\l"
	.string "parameter in play.\p"
	.string "Regardless, I must thank you\n"
	.string "for your efforts!$"

LanternCave_2F_Text_Colress_Defeat_2::
	.string "This is a HIDDEN MACHINE for the\n"
	.string "move SURF I found for you.\p"
	.string "Not only is it a powerful attack\n"
	.string "that hits both opponents, it also\l"
	.string "lets you ride across water!\p"
	.string "I expect this to be useful on\n"
	.string "the turbulent SKYWARD TRAIL.$"

LanternCave_2F_Text_Colress_Defeat_3:
	.string "My research leads me elsewhere.\n"
	.string "I'm sure we will cross paths again!$"

LanternCave_2F_Movement_WalkUp3::
	walk_up
	walk_up
	walk_up
	step_end

LanternCave_Movement_WalkRight8::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end