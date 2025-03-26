ShuiyunTown_House1_MapScripts::
	.byte 0

ShuiyunTown_House1_EventScript_OldWoman::
	msgbox ShuiyunTown_House1_Text_OldWoman, MSGBOX_NPC
	end

ShuiyunTown_House1_EventScript_Boy::
	msgbox ShuiyunTown_House1_Text_Boy, MSGBOX_NPC
	end

ShuiyunTown_House1_Text_OldWoman:
	.string "Sweetie, is your POKéMON holding\n"
	.string "an item?\p"
	.string "Held items give powerful effects,\n"
	.string "you know.\p"
	.string "The best items come with conditions\n"
	.string "or drawbacks, but they're worth the\l"
	.string "hassle.$"

ShuiyunTown_House1_Text_Boy:
	.string "I don't like it when my POKéMON\n"
	.string "move after my opponent!\p"
	.string "I use moves like ICY WIND and\n"
	.string "BULLDOZE to slow my opponent down,\l"
	.string "but Granny insists I use setup moves\n"
	.string "like TAILWIND and TRICK ROOM!\p"
	.string "Hmph!$"