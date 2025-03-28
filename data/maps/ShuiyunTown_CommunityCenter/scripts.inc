ShuiyunTown_CommunityCenter_MapScripts::
	.byte 0

.set LOCALID_MOVE_RELEARNER, 3

ShuiyunTown_CommunityCenter_EventScript_TMShop::
	lock
	faceplayer
	message ShuiyunTown_CommunityCenter_Text_TMShop
	waitmessage
	pokemart ShuiyunTown_CommunityCenter_Pokemart_TMs
	release
	end

ShuiyunTown_CommunityCenter_Pokemart_TMs:
	.2byte ITEM_TM_SUNNY_DAY
	.2byte ITEM_TM_RAIN_DANCE
	.2byte ITEM_TM_SANDSTORM
	.2byte ITEM_TM_HAIL
	.2byte ITEM_TM_THUNDERBOLT
	.2byte ITEM_TM_ICE_BEAM
	.2byte ITEM_TM_FLAMETHROWER
	pokemartlistend

ShuiyunTown_CommunityCenter_EventScript_SpecialShop::
	lock
	faceplayer
	message ShuiyunTown_CommunityCenter_Text_SpecialShop
	waitmessage
	pokemart ShuiyunTown_CommunityCenter_Pokemart_SpecialShop
	release
	end

ShuiyunTown_CommunityCenter_Pokemart_SpecialShop:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_JOLLY_MINT
	pokemartlistend

ShuiyunTown_CommunityCenter_EventScript_TalkRelearn::
	msgbox ShuiyunTown_CommunityCenter_Text_TalkRelearn, MSGBOX_NPC
	end

ShuiyunTown_CommunityCenter_EventScript_TalkHost::
	msgbox ShuiyunTown_CommunityCenter_Text_Host MSGBOX_NPC
	end

ShuiyunTown_CommunityCenter_EventScript_TalkYoungster::
	lock
	faceplayer
	msgbox ShuiyunTown_CommunityCenter_Text_Youngster MSGBOX_DEFAULT
	call_if_unset FLAG_COMMUNITY_CENTER_UTILITY_UMBRELLA, ShuiyunTown_CommunityCenter_EventScript_TalkYoungsterGiveItem
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkYoungsterGiveItem::
	msgbox ShuiyunTown_CommunityCenter_Text_YoungsterGiveUmbrella MSGBOX_DEFAULT
	giveitem ITEM_UTILITY_UMBRELLA
	setflag FLAG_COMMUNITY_CENTER_UTILITY_UMBRELLA
	msgbox ShuiyunTown_CommunityCenter_Text_YoungsterExplainUmbrella MSGBOX_DEFAULT
	return

ShuiyunTown_CommunityCenter_EventScript_TalkScientist::
	lock
	faceplayer
	call_if_unset FLAG_COMMUNITY_CENTER_EXP_SHARE, ShuiyunTown_CommunityCenter_EventScript_TalkScientistGiveItem
	msgbox ShuiyunTown_CommunityCenter_Text_ScientistExplainExpShare MSGBOX_DEFAULT
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkScientistGiveItem::
	msgbox ShuiyunTown_CommunityCenter_Text_ScientistGiveExpShare MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	setflag FLAG_COMMUNITY_CENTER_EXP_SHARE
	return

ShuiyunTown_CommunityCenter_EventScript_TalkGBKid::
	goto_if_set FLAG_COMMUNITY_CENTER_SHOWN_KANGASKHAN, ShuiyunTown_CommunityCenter_EventScript_TalkGBKidDone
	lock
	faceplayer
	msgbox ShuiyunTown_CommunityCenter_Text_GBKidAskToShowKangaskhan, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShuiyunTown_CommunityCenter_EventScript_TalkGBKidShowKangaskhan
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_CommunityCenter_EventScript_TalkGBKidRefuse
	end

ShuiyunTown_CommunityCenter_EventScript_TalkGBKidShowKangaskhan::
	checkspecies SPECIES_KANGASKHAN, OPEN_PARTY_SCREEN
	goto_if_eq VAR_RESULT, YES, ShuiyunTown_CommunityCenter_EventScript_TalkGBKidRightPokemon
	goto_if_eq VAR_RESULT, NO, ShuiyunTown_CommunityCenter_EventScript_TalkGBKidWrongPokemon
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkGBKidRightPokemon::
	msgbox ShuiyunTown_CommunityCenter_Text_GBKidShownKangaskhan, MSGBOX_DEFAULT
	giveitem ITEM_LINKING_CORD
	msgbox ShuiyunTown_CommunityCenter_Text_GBKidLinkingCord, MSGBOX_DEFAULT
	setflag FLAG_COMMUNITY_CENTER_SHOWN_KANGASKHAN
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkGBKidWrongPokemon::
	msgbox ShuiyunTown_CommunityCenter_Text_GBKidWrongPokemon, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkGBKidRefuse::
	msgbox ShuiyunTown_CommunityCenter_Text_GBKidRefuse, MSGBOX_DEFAULT
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkGBKidDone::
	msgbox ShuiyunTown_CommunityCenter_EventScript_TalkGBKidDone, MSGBOX_NPC
	end

ShuiyunTown_CommunityCenter_EventScript_TalkLass::
	msgbox ShuiyunTown_CommunityCenter_Text_Lass, MSGBOX_NPC
	end

ShuiyunTown_CommunityCenter_EventScript_TalkSchoolKid::
	msgbox ShuiyunTown_CommunityCenter_Text_SchoolKid, MSGBOX_NPC
	end

ShuiyunTown_CommunityCenter_EventScript_TalkRichBoy::
	lock
	faceplayer
	call_if_unset FLAG_COMMUNITY_CENTER_PROTECT, ShuiyunTown_CommunityCenter_EventScript_TalkRichBoyGiveItem
	msgbox ShuiyunTown_CommunityCenter_Text_RichBoyExplain MSGBOX_DEFAULT
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkRichBoyGiveItem::
	msgbox ShuiyunTown_CommunityCenter_Text_RichBoy MSGBOX_DEFAULT
	giveitem ITEM_TM_PROTECT
	setflag FLAG_COMMUNITY_CENTER_PROTECT
	return


ShuiyunTown_CommunityCenter_EventScript_TalkLittleGirl::
	lock
	faceplayer
	call_if_unset FLAG_COMMUNITY_CENTER_TWISTED_SPOON, ShuiyunTown_CommunityCenter_EventScript_TalkLittleGirlGiveItem
	msgbox ShuiyunTown_CommunityCenter_Text_LittleGirlExplain MSGBOX_DEFAULT
	release
	end

ShuiyunTown_CommunityCenter_EventScript_TalkLittleGirlGiveItem::
	msgbox ShuiyunTown_CommunityCenter_Text_LittleGirl MSGBOX_DEFAULT
	giveitem ITEM_TWISTED_SPOON
	setflag FLAG_COMMUNITY_CENTER_TWISTED_SPOON
	return

ShuiyunTown_CommunityCenter_Text_TalkRelearn:
	.string "If you want your POKéMON to remember\n"
	.string "a move it used to know, all you have\l"
	.string "to do is go to its BATTLE SUMMARY\l"
	.string "page, and press START.\p"
	.string "Similarly, in the POKéMON INFO page,\n"
	.string "press A to rename your POKéMON!\p"
	.string "It's so convenient!$"

ShuiyunTown_CommunityCenter_Text_TMShop:
	.string "I have a lot of Technical Machines!\n"
	.string "Come on, buy a few!$"

ShuiyunTown_CommunityCenter_Text_SpecialShop:
	.string "My wares are for the discerning\n"
	.string "TRAINER only. Care for a gander?$"

ShuiyunTown_CommunityCenter_Text_Host:
	.string "Welcome to the COMMUNITY CENTER.\p"
	.string "Many are sheltering here from the\n"
	.string "endless rain, and you are free to\l"
	.string "stay as you like.\p"
	.string "Don't be afraid to be chatty!$"

ShuiyunTown_CommunityCenter_Text_Youngster:
	.string "The constant rain also affects\n"
	.string "POKéMON battles!\p"
	.string "Water-type moves do more damage, and\n"
	.string "Fire-type moves do less damage.\p"
	.string "Many moves have unique interactions\n"
	.string "with the weather, too.$"
	.string "For example, SYNTHESIS recovers more\n"
	.string "in harsh sunlight and less in rain.\p"
	.string "It's a lot to worry about!$"

ShuiyunTown_CommunityCenter_Text_YoungsterGiveUmbrella:
	.string "That's why I think you should have\n"
	.string "this item!$"

ShuiyunTown_CommunityCenter_Text_YoungsterExplainUmbrella:
	.string "The UTILITY UMBRELLA negates the\n"
	.string "effects of rain and harsh sunlight.\p"
	.string "That means Water-type moves no longer\n"
	.string "get a damage bonus against your POKéMON\l"
	.string "while it is holding the item.\p"
	.string "Come rain or shine, a POKéMON TRAINER\n"
	.string "needs to keep their head up!$"

ShuiyunTown_CommunityCenter_Text_ScientistGiveExpShare:
	.string "A TRAINER! Finally! I've been wanting\n"
	.string "to hand this off for a long time!$"

ShuiyunTown_CommunityCenter_Text_ScientistExplainExpShare:
	.string "Give EXP Share to a POKéMON, and they\n"
	.string "will gain experience even when they\l"
	.string "didn't participate in a battle.$"

ShuiyunTown_CommunityCenter_Text_GBKid:
	.string "I love KANGASKHAN!\n"
	.string "It's protective of its baby!$"

ShuiyunTown_CommunityCenter_Text_GBKidAskToShowKangaskhan:
	.string "Hey, you're a TRAINER, right?\p"
	.string "There's this really awesome POKéMON…\l"
	.string "It had a pocket with a baby inside!\p"
	.string "I know I saw it in LANTERN CAVE!\n"
	.string "Can you show me that POKéMON?$"

ShuiyunTown_CommunityCenter_Text_GBKidShownKangaskhan:
	.string "Wow, that's it! It's so cool!\n"
	.string "It's called KANGASKHAN, you say?\p"
	.string "Thank you so much! Please take this!$"

ShuiyunTown_CommunityCenter_Text_GBKidLinkingCord:
	.string "This item can evolve POKéMON that\n"
	.string "needs trading to evolve normally.\p"
	.string "Hard to find someone to trade with on\n"
	.string "this island, so this might be useful!$"

ShuiyunTown_CommunityCenter_Text_GBKidWrongPokemon:
	.string "That's not the right POKéMON…$"

ShuiyunTown_CommunityCenter_Text_GBKidRefuse:
	.string "Aww, it's alright.$"

ShuiyunTown_CommunityCenter_Text_Lass:
	.string "The DOCKYARD and GYM are pillars\n"
	.string "of SHUIYUN TOWN.\p"
	.string "But it seems like trouble is\n"
	.string "brewing in both places…\p"
	.string "If only there was a handsome or\n"
	.string "beautiful TRAINER who would\l"
	.string "intervene and save the day!$"

ShuiyunTown_CommunityCenter_Text_LassGiveItem:
	.string "Oh, {PLAYER}, you're the talk of the\n"
	.string "town!\p"
	.string "You have brought a sliver of hope to\n"
	.string "everyone here!\p"
	.string "Please accept this gift!$"

ShuiyunTown_CommunityCenter_Text_LassExplainItem:
	.string "Give this toyour POKéMON, and they can\n"
	.string "gain experience even faster!$"

ShuiyunTown_CommunityCenter_Text_RichBoy:
	.string "Can you believe it? There are nefarious\n"
	.string "goons prowling about the island!\p"
	.string "It's essential for me and my POKéMON to\n"
	.string "PROTECT themselves!\p"
	.string "As a TRAINER, you have a responsibility\n"
	.string "to keep your POKéMON safe, so take this!$"

ShuiyunTown_CommunityCenter_Text_RichBoyExplain:
	.string "PROTECT makes you invulnerable during\n"
	.string "the turn. However, when used\l"
	.string "consecutively, it is likely to fail.\p"
	.string "During a double battle, you can PROTECT\n"
	.string "a vulnerable POKéMON while its partner\l"
	.string "acts freely.\p"
	.string "It's also useful if you have an attack\n"
	.string "that hits your partner, such as SURF.$"

ShuiyunTown_CommunityCenter_Text_SchoolKid:
	.string "Want to find out what a POKéMON's move\n"
	.string "does during battle?\l"
	.string "Just press L to read all about it!\p"
	.string "This will also tell you whether the move\n"
	.string "is a PHYSICAL, SPECIAL, or STATUS move.\p"
	.string "Back in the day, a move's type\n"
	.string "determined its physicality, but the\l"
	.string "times have changed.$"


ShuiyunTown_CommunityCenter_Text_LittleGirl:
	.string "Ummm, I bent this, and I don't want my\n"
	.string "mom to find out. Can you take it?$"

ShuiyunTown_CommunityCenter_Text_LittleGirlExplain:
	.string "Teacher said POKéMON can hold items\n"
	.string "like this for an effect in battle.\p"
	.string "Umm… This TWISTED SPOON gives Psychic-\n"
	.string "type moves a 20% boost in power.\p"
	.string "It's not the strongest boosting item,\n"
	.string "but, umm, there's no drawback to it.\p"
	.string "Umm, teacher said there's one of these\n"
	.string "for each type! Look around for them!$"