ShuiyunTownIntroBoat_MapScripts::
	.byte 0

.set LOCALID_BIRCH_BAG, 1

ShuiyunTownIntroBoat_EventScript_BirchsBag::
	lockall
	msgbox ShuiyunTownIntroBoat_Text_BirchsBag, MSGBOX_DEFAULT
	@ closemessage
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BIRCH_BAG
	special ChooseStarter
	waitstate
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
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
	@ msgbox ShuiyunTownIntroBoat_Text_Captain, MSGBOX_DEFAULT
	releaseall
	end

ShuiyunTownIntroBoat_EventScript_PreventExit::
	lockall
	msgbox ShuiyunTownIntroBoat_Text_DontForgetBag, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ShuiyunTownIntroBoat_Movement_PreventExit
	waitmovement 0
	releaseall
	end

ShuiyunTownIntroBoat_Text_BirchsBag:
	.string "There is a note in the bag.\p"
	.string "“{PLAYER}{KUN}, I realized you don't have\n"
	.string "a POKéMON partner yet.\p"
	.string "In this bag are some capable POKéMON.\n"
	.string "Choose one for your journey ahead.\p"
	.string "I also asked the captain to prepare some\n"
	.string "helpful items for you. Don't forget to\l"
	.string "talk to him before you go.\p"
	.string "Good luck, and I hope to see you soon.”\p"
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
	.string "The captain's room is be upstairs.\n"
	.string "Better go look for him!$"