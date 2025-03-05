ShuiyunTownIntroBoat_MapScripts::
	.byte 0

.set LOCALID_BIRCH_BAG, 1

ShuiyunTownIntroBoat_EventScript_BirchsBag::
	lock
	msgbox ShuiyunTownIntroBoat_Text_BirchsBag1, MSGBOX_DEFAULT

	msgbox ShuiyunTownIntroBoat_Text_BirchsBag2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare

	msgbox ShuiyunTownIntroBoat_Text_BirchsBag3, MSGBOX_DEFAULT

	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RESCUED_BIRCH
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

ShuiyunTownIntroBoat_Text_BirchsBag1:
	.string "This looks like the bag STEVEN mentioned.$"

ShuiyunTownIntroBoat_Text_BirchsBag2:
	.string "You got the POKéDEX and RUNNING SHOES!$"

ShuiyunTownIntroBoat_Text_BirchsBag3:
	.string "You also found a note addressed to you.\p"
	.string "“{PLAYER}{KUN}, I realized you don't have\n"
	.string "a POKéMON partner yet.\p"
	.string "In this bag are some capable POKéMON.\n"
	.string "Choose one for your journey ahead.\p"
	.string "I also asked the captain to prepare some\n"
	.string "helpful items for you. Don't forget to\l"
	.string "talk to him before you go.\p"
	.string "I hope to hear from you soon.”\n"
	.string "- STEVEN STONE$"

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