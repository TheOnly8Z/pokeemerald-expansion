SkywardTrail_House_MapScripts::
	.byte 0

SkywardTrail_House_EventScript_TalkWoman::
	lock
	faceplayer
	msgbox SkywardTrail_House_Text_WomanRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SkywardTrail_House_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, SkywardTrail_House_EventScript_DeclineRest
	end

SkywardTrail_House_EventScript_Rest::
	msgbox SkywardTrail_House_Text_WomanRestAccept, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SkywardTrail_House_Text_WomanRestDone, MSGBOX_DEFAULT
	release
	end

SkywardTrail_House_EventScript_DeclineRest::
	msgbox SkywardTrail_House_Text_WomanRestRefuse, MSGBOX_DEFAULT
	release
	end

SkywardTrail_House_EventScript_TalkOldMan::
	goto_if_set FLAG_RECEIVED_HM_FLASH, SkywardTrail_House_EventScript_TalkRepeat
	lock
	faceplayer
	msgbox SkywardTrail_House_Text_OldManGiveItem1, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SkywardTrail_House_Text_OldManGiveItem2, MSGBOX_DEFAULT
	release
	end

SkywardTrail_House_EventScript_TalkRepeat::
	msgbox SkywardTrail_House_Text_OldManReminder, MSGBOX_NPC
	end

SkywardTrail_House_Text_OldManGiveItem1:
	.string "A traveller! How jolly.\n"
	.string "You braved the terrible rain and the\l"
	.string "nefarious TEAM AQUA's interference!\p"
	.string "Are you travelling to the LABORATORY,\n"
	.string "perchance?\p"
	.string "Alas, the blasted rain took out the\n"
	.string "only bridge there!\p"
	.string "You would need the Hidden Machine SURF\n"
	.string "to swim across on your POKéMON.\p"
	.string "Regretfully, I do not have HM SURF.\n"
	.string "A good friend, ZHONG, took it for\l"
	.string "his daring rescue in LANTERN CAVE.\p"
	.string "But that goof forgot this!$"

SkywardTrail_House_Text_OldManGiveItem2:
	.string "This is the Hidden Machine FLASH.\p"
	.string "Teach FLASH to one of your POKéMON.\n"
	.string "It will light up dark areas, and\l"
	.string "lower accuracy harshly in battle.\p"
	.string "Go west of here for a shortcut\n"
	.string "into LANTERN CAVE.\p"
	.string "ZHONG has a habit of leaving things\n"
	.string "behind in a hurry, so search every\l"
	.string "corner of the cave for the HM.\p"
	.string "Ah! Before you go, talk to my lovely\n"
	.string "daughter if you need a pick me up.\p"
	.string "The last thing we need is two lads\n"
	.string "stuck in LANTERN CAVE instead of one!$"

SkywardTrail_House_Text_OldManReminder:
	.string "To cross the river to get to the\n"
	.string "LABORATORY, you need HM SURF.\p"
	.string "ZHONG took it, but most likely\n"
	.string "dropped it in LANTERN CAVE.\p"
	.string "Use HM STRENGTH on your POKéMON,\n"
	.string "and you should be able to pass\l"
	.string "through the shortcut west of here.$"

SkywardTrail_House_Text_WomanRest:
	.string "Oh, you look wet and miserable!\n"
	.string "Why don't you take a nap here?$"

SkywardTrail_House_Text_WomanRestRefuse:
	.string "Perhaps you like it that way!\p"
	.string "Still, stop by if you need a break!$"

SkywardTrail_House_Text_WomanRestAccept:
	.string "Jolly good! And have some tea while\n"
	.string "you're here, won't you?$"

SkywardTrail_House_Text_WomanRestDone:
	.string "You and your POKéMON look dashing!\n"
	.string "Stop by some other time!$"