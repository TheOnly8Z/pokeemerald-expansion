LanternCave_2F_Connector_MapScripts::
	.byte 0

LanternCave_2F_Connector_EventScript_FlashGiver::
	goto_if_set FLAG_RECEIVED_HM_FLASH, LanternCave_2F_Connector_EventScript_FlashGiver_PostBattle
	lock
	faceplayer
	call_if_unset FLAG_TEMP_1, LanternCave_2F_Connector_EventScript_FlashGiverAskLong
	call_if_set FLAG_TEMP_1, LanternCave_2F_Connector_EventScript_FlashGiverAskShort
	setflag FLAG_TEMP_1
	goto_if_eq VAR_RESULT, YES, LanternCave_2F_Connector_EventScript_FlashGiver_Accept
	goto_if_eq VAR_RESULT, NO, LanternCave_2F_Connector_EventScript_FlashGiver_Refuse
	end

LanternCave_2F_Connector_EventScript_FlashGiverAskLong::
	msgbox LanternCave_2F_Connector_Text_FlashGiver MSGBOX_YESNO
	return

LanternCave_2F_Connector_EventScript_FlashGiverAskShort::
	msgbox LanternCave_2F_Connector_Text_FlashGiverShort MSGBOX_YESNO
	return

LanternCave_2F_Connector_EventScript_FlashGiver_Accept::
	trainerbattle_single TRAINER_FLASH_HIKER, LanternCave_2F_Connector_Text_FlashGiverBattle, LanternCave_2F_Connector_Text_FlashGiverDefeated, LanternCave_2F_Connector_EventScript_FlashGiver_GiveItem
	release
	end

LanternCave_2F_Connector_EventScript_FlashGiver_GiveItem::
	lock
	giveitem ITEM_HM05
	msgbox LanternCave_2F_Connector_Text_FlashGiverItem, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_HM_FLASH
	release
	end

LanternCave_2F_Connector_EventScript_FlashGiver_Refuse::
	msgbox LanternCave_2F_Connector_Text_FlashGiverRefuse, MSGBOX_DEFAULT
	release
	end

LanternCave_2F_Connector_EventScript_FlashGiver_PostBattle::
	msgbox LanternCave_2F_Connector_Text_FlashGiverPostBattle, MSGBOX_NPC
	end

LanternCave_2F_Connector_Text_FlashGiver:
	.string "You know, the cave up ahead is all\n"
	.string "dark and stuff.\p"
	.string "I do have the HM FLASH to light it up…\p"
	.string "Well, this is a bit of a selfish\n"
	.string "request, but I would really like to\l"
	.string "fight you in a POKéMON battle.\p"
	.string "If you win, I'll give you FLASH. Deal?$"

LanternCave_2F_Connector_Text_FlashGiverShort:
	.string "Up for a POKéMON battle?\n"
	.string "If you win, I'll give you HM FLASH.$"

LanternCave_2F_Connector_Text_FlashGiverRefuse:
	.string "Fair. But let me know if you change\n"
	.string "your mind.$"

LanternCave_2F_Connector_Text_FlashGiverGiven:
	.string "I feel a lot better now.\p"
	.string "Good luck in the caves!$"

LanternCave_2F_Connector_Text_FlashGiverBattle:
	.string "Finally, a worthy opponent!\n"
	.string "Our battle will be somewhat remarkable!$"

LanternCave_2F_Connector_Text_FlashGiverPostBattle:
	.string "Ah, I feel better after a heated\n"
	.string "battle like that.$"

LanternCave_2F_Connector_Text_FlashGiverDefeated:
	.string "I tip my Safari hat to you,\n"
	.string "from one TRAINER to another!$"

LanternCave_2F_Connector_Text_FlashGiverItem:
	.string "As promised, here it is!\p"
	.string "Teach it to one of your POKéMON.\n"
	.string "Then, use it from your summary screen.\p"
	.string "In battle, FLASH harshly lowers the\n"
	.string "accuracy of everyone else, even your ally.\p"
	.string "It's not just a… flash in a pan!\n"
	.string "Ahahahahahahaha!$"
