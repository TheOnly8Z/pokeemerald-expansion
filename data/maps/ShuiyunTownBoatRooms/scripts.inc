ShuiyunTownBoatRooms_MapScripts::
	.byte 0

.set LOCALID_WOMAN, 1
.set LOCALID_BOY, 2


ShuiyunTownBoatRooms_EventScript_TalkWoman::
	msgbox ShuiyunTownBoatRooms_Text_TalkWoman MSGBOX_NPC
	end


ShuiyunTownBoatRooms_EventScript_TalkBoy::
	msgbox ShuiyunTownBoatRooms_Text_TalkBoy MSGBOX_NPC
	end

ShuiyunTownBoatRooms_Text_TalkWoman:
	.string "When POKéMON battle in pairs, it's\n"
	.string "called a DOUBLE BATTLE.\p"
	.string "There is a lot more strategy involved\n"
	.string "when you can use two POKéMON at once.\p"
	.string "My Gramps over there used to be\n"
	.string "quite good at it!$"

ShuiyunTownBoatRooms_Text_TalkBoy:
	.string "My POKéMON have so many moves, it's\n"
	.string "confusing me!\p"
	.string "But I can open their SUMMARY page\n"
	.string "to read all about them.$"

ShuiyunTownBoatRooms_EventScript_TalkExpert::
	faceplayer
	lock
	goto_if_set FLAG_EXPERT_ADVICE_ITEM, ShuiyunTownBoatRooms_EventScript_TalkExpertRepeat
	msgbox ShuiyunTownBoatRooms_Text_TalkExpert MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShuiyunTownBoatRooms_EventScript_TalkExpertSelectAdvice
	goto_if_eq VAR_RESULT, NO, ShuiyunTownBoatRooms_EventScript_TalkExpertTooBad
	end

ShuiyunTownBoatRooms_EventScript_TalkExpertRepeat::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertRepeat MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShuiyunTownBoatRooms_EventScript_TalkExpertSelectAdvice
	release
	end

ShuiyunTownBoatRooms_EventScript_TalkExpertSelectAdvice::
	call_if_eq VAR_STARTER_MON, 0, ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceCarnivine
	call_if_eq VAR_STARTER_MON, 1, ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceHeatmor
	call_if_eq VAR_STARTER_MON, 2, ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceLuvdisc
	call_if_unset FLAG_EXPERT_ADVICE_ITEM, ShuiyunTownBoatRooms_EventScript_TalkExpertGiveItem
	release
	end

ShuiyunTownBoatRooms_EventScript_TalkExpertGiveItem::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceGiveItem MSGBOX_DEFAULT
	giveitem ITEM_EXPERT_BELT
	setflag FLAG_EXPERT_ADVICE_ITEM
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceExplainItem MSGBOX_DEFAULT
	return

ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceLuvdisc::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceLuvdisc MSGBOX_DEFAULT
	return

ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceCarnivine::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceCarnivine MSGBOX_DEFAULT
	return

ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceHeatmor::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceHeatmor MSGBOX_DEFAULT
	return

ShuiyunTownBoatRooms_EventScript_TalkExpertAdviceSpinda::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertAdviceSpinda MSGBOX_DEFAULT
	return

ShuiyunTownBoatRooms_EventScript_TalkExpertTooBad::
	msgbox ShuiyunTownBoatRooms_Text_TalkExpertTooBad MSGBOX_DEFAULT
	release
	end

ShuiyunTownBoatRooms_Text_TalkExpert:
	.string "Hoh, so you were the lucky recipient\n"
	.string "of STEVEN's POKéMON!\p"
	.string "Believe it or not, I used to be quite\n"
	.string "good at POKéMON battles!\p"
	.string "Want some advice on your choice?$"

ShuiyunTownBoatRooms_Text_TalkExpertRepeat:
	.string "Eager to hear my advice?$"

ShuiyunTownBoatRooms_Text_TalkExpertTooBad:
	.string "A shame. I love giving items to\n"
	.string "eager TRAINERS who take my advice!$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceLuvdisc:
	.string "I see you chose LUVDISC…\p"
	.string "It might not have powerful attacks,\n"
	.string "but it's fast and durable, with many\l"
	.string "ways to support and enable its partner.\p"
	.string "Its ability, FRIEND GUARD, is especially\n"
	.string "impactful. Just by being next to its\l"
	.string "partner, they will take less damage!\p"
	.string "Let your partner boost their attack\n"
	.string "while LUVDISC keeps them safe.\l"
	.string "Then, you'll be unstoppable!$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceCarnivine:
	.string "I see you chose CARNIVINE…\p"
	.string "It's incredibly slow, but that just\n"
	.string "means it's very durable and powerful.\p"
	.string "Its ability, STRONG JAW, boosts the\n"
	.string "power of biting moves.\l"
	.string "With this ability, BITE becomes much\l"
	.string "stronger than VINE WHIP!\p"
	.string "Use GROWTH and SYNTHESIS to gain power\n"
	.string "while staying healthy.\p"
	.string "Here's an extra tip. There's a special\n"
	.string "move that will let slow POKéMON move\l"
	.string "before fast POKéMON called TRICK ROOM.\p"
	.string "CARNIVINE cannot learn it, so you need\n"
	.string "a partner to set it up. If you do that,\l"
	.string "the payoff will be incredible!$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceHeatmor:
	.string "I see you chose HEATMOR…\p"
	.string "It is a well-rounded offensive\n"
	.string "POKéMON, but not very durable.\p"
	.string "Its ability, EARTH EATER, makes\n"
	.string "GROUND-type moves heal it instead.\l"
	.string "Use this immunity to switch into\l"
	.string "battle or use a boosting move!\p"
	.string "Use FOCUS ENERGY with SLASH\n"
	.string "to get a guaranteed critical hit!\p"
	.string "A jack of all trades is a master of\n"
	.string "none. Take advantage of stat changes\l"
	.string "to unleash HEATMOR's full potential!$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceSpinda:
	.string "I see you chose SPINDA…\p"
	.string "It is quite unorthodox, and its\n"
	.string "strengths are not obvious.\p"
	.string "Its ability, CONTRARY, reverses\n"
	.string "its stat drops and stat gains.\p"
	.string "A move that will lower your Attack\l"
	.string "will raise it instead!\p"
	.string "The opposite is also true, so boosting\n"
	.string "moves are not useful for SPINDA.\p"
	.string "Take advantage of moves that typically\n"
	.string "reduce your stats, as they will now\l"
	.string "boost your stats instead!\p"
	.string "SPINDA also has great moves to support\n"
	.string "its partner if needed.$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceGiveItem:
	.string "I love young 'uns who are receptive to\n"
	.string "advice from their elders.\p"
	.string "You deserve this item!$"

ShuiyunTownBoatRooms_Text_TalkExpertAdviceExplainItem:
	.string "Let a POKéMON hold the EXPERT BELT.\n"
	.string "When it uses a super-effective move,\l"
	.string "the move's power will be boosted by 20%.\p"
	.string "Study your type matchups to use this\n"
	.string "item to its full potential.$"
