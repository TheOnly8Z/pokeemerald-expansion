JiangshenLake_House_MapScripts::
	.byte 0

JiangshenLake_House_EventScript_Shelf::
	lock

	goto_if_set FLAG_ITEM_JIANGSHEN_HOUSE, JiangshenLake_House_EventScript_ShelfEmpty

	msgbox JiangshenLake_House_Text_TakeItems, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, JiangshenLake_House_EventScript_ShelfTake
	end

JiangshenLake_House_EventScript_ShelfEmpty::
	msgbox JiangshenLake_House_Text_ShelfEmpty, MSGBOX_DEFAULT
	release
	end

JiangshenLake_House_EventScript_ShelfTake::
	giveitem ITEM_MOOMOO_MILK, 20
	giveitem ITEM_ULTRA_BALL, 30
	giveitem ITEM_REVIVE, 5
	setflag FLAG_ITEM_JIANGSHEN_HOUSE
	release
	end

JiangshenLake_House_EventScript_Bed::
	lock
	faceplayer
	msgbox JiangshenLake_House_Text_Rest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, JiangshenLake_House_EventScript_Rest
	end

JiangshenLake_House_EventScript_Rest::
	msgbox SkywardTrail_House_Text_WomanRestAccept, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

JiangshenLake_House_Text_Rest::
	.string "This bed looks cozy.\n"
	.string "Rest here?$"

JiangshenLake_House_Text_TakeItems::
	.string "There's a lot of items\n"
	.string "on the shelf! Take them?$"

JiangshenLake_House_Text_ShelfEmpty::
	.string "The shelf is empty.$"