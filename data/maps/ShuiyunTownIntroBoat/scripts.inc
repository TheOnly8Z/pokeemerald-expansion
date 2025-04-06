ShuiyunTownIntroBoat_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShuiyunTownIntroBoat_OnFrame
	.byte 0

ShuiyunTownIntroBoat_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, ShuiyunTownIntroBoat_EventScript_Intro
	.2byte 0

.set LOCALID_BIRCH_BAG, 1

ShuiyunTownIntroBoat_EventScript_Intro::
	lock
	setrespawn HEAL_LOCATION_SHUIYUN_TOWN_INTRO_BOAT

	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate

	msgbox ShuiyunTownIntroBoat_Text_Intro, MSGBOX_DEFAULT
	setvar VAR_ROUTE101_STATE, 1
	setflag FLAG_HIDE_GYM_ZHONG
	setflag FLAG_HIDE_BEACH_KAI_ZHONG
	setflag FLAG_HIDE_GYM_KAI
	release
	end

ShuiyunTownIntroBoat_EventScript_BirchsBag::
	lock

	msgbox ShuiyunTownIntroBoat_Text_BirchsBag1, MSGBOX_DEFAULT

	playfanfare MUS_OBTAIN_ITEM
	message ShuiyunTownIntroBoat_Text_BirchsBag2
	waitfanfare
	waitmessage

	playfanfare MUS_OBTAIN_ITEM
	message ShuiyunTownIntroBoat_Text_BirchsBagPokedex
	waitfanfare
	waitmessage

	msgbox ShuiyunTownIntroBoat_Text_BirchsBag3, MSGBOX_DEFAULT

	msgbox ShuiyunTownIntroBoat_Text_PickStarter, MSGBOX_DEFAULT

	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BIRCH_BAG
	special ChooseStarter
	waitstate
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	bufferleadmonspeciesname STR_VAR_1
	playfanfare MUS_OBTAIN_ITEM
	message ShuiyunTownIntroBoat_Text_Received
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShuiyunTownIntroBoat_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, ShuiyunTownIntroBoat_EventScript_LookForCaptain
	end

ShuiyunTownIntroBoat_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto ShuiyunTownIntroBoat_EventScript_LookForCaptain
	end

ShuiyunTownIntroBoat_EventScript_LookForCaptain::
	msgbox ShuiyunTownIntroBoat_Text_Captain, MSGBOX_DEFAULT
	release
	end

ShuiyunTownIntroBoat_EventScript_PreventExit::
	lockall
	msgbox ShuiyunTownIntroBoat_Text_DontForgetBag, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ShuiyunTownIntroBoat_Movement_PreventExit
	waitmovement 0
	release
	end

ShuiyunTownIntroBoat_Text_Intro:
	.string "After a long trip on the boat, it seems\n"
	.string "like you're finally at your destination.$"

ShuiyunTownIntroBoat_Text_BirchsBag1:
	.string "You open the bag from STEVEN.$"

ShuiyunTownIntroBoat_Text_BirchsBag2:
	.string "{PLAYER} received the RUNNING SHOES!\n"
	.string "Hold the B Button to run faster.$"

ShuiyunTownIntroBoat_Text_BirchsBagPokedex:
	.string "{PLAYER} received the POKéDEX!$"

ShuiyunTownIntroBoat_Text_BirchsBag3:
	.string "There is a letter addressed to you.\p"
	.string "“{PLAYER}{KUN}, here are two things\n"
	.string "essential for a new TRAINER like you.\p"
	.string "The first is a POKéDEX. Use it to\n"
	.string "record and learn about the POKéMON you\l"
	.string "encounter in your travels.\p"
	.string "The second is a POKéMON partner.\p"
	.string "In this bag are three capable POKéMON\n"
	.string "with unique abilities.\p"
	.string "You'll find them quite different to\n"
	.string "what you might expect.\p"
	.string "Pick one of these POKéMON for your\n"
	.string "journey ahead.\p"
	.string "I also asked the captain to prepare some\n"
	.string "helpful items for you. Don't forget to\l"
	.string "talk to him before you go.\p"
	.string "I hope to hear from you soon.”\n"
	.string "- STEVEN STONE$"

ShuiyunTownIntroBoat_Text_PickStarter:
	.string "There are some POKé BALLS in the bag.\n"
	.string "Time to pick a partner!$"

ShuiyunTownIntroBoat_Text_Received:
	.string "{PLAYER} received the {STR_VAR_1}!$"

ShuiyunTownIntroBoat_Text_DontForgetBag:
	.string "It might be a good idea to check out\n"
	.string "what's in the bag first.$"

ShuiyunTownIntroBoat_Movement_PreventExit:
	walk_down
	step_end

ShuiyunTownIntroBoat_Text_Captain:
	.string "The captain's room is upstairs.\n"
	.string "Better go look for him!$"
