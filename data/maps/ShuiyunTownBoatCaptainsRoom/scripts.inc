ShuiyunTownBoatCaptainsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShuiyunTownBoatCaptainsRoom_OnFrame
	.byte 0

ShuiyunTownBoatCaptainsRoom_OnFrame:
	map_script_2 VAR_SHUIYUN_BOAT_INTRO_BATTLE_STATE, 0, ShuiyunTownBoatCaptainsRoom_EventScript_RunCutscene1
	map_script_2 VAR_SHUIYUN_BOAT_INTRO_BATTLE_STATE, 1, ShuiyunTownBoatCaptainsRoom_EventScript_RunCutscene2
	.2byte 0

.set LOCALID_CAPTAIN, 1
.set LOCALID_AQUA_GRUNT, 2
.set LOCALID_MAGMA_GRUNT, 3

CommonName_Text_MagmaGrunt:
	.string "ROWDY GRUNT$"
	
CommonName_Text_AquaGrunt:
	.string "MATURE GRUNT$"

CommonName_Text_Captain:
	.string "CAPTAIN$"

ShuiyunTownBoatCaptainsRoom_EventScript_TalkCaptain::
	msgbox ShuiyunTownBoatCaptainsRoom_Text_TalkCaptain MSGBOX_NPC
	end

ShuiyunTownBoatCaptainsRoom_EventScript_RunCutscene1:
	lock

	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp2
	waitmovement 0
	delay 20

	applymovement LOCALID_AQUA_GRUNT, Movement_WalkSlowUp
	waitmovement 0
	delay 20
	speakername CommonName_Text_AquaGrunt
	msgbox ShuiyunTownBoatCaptainsRoom_Text_1 MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_GRUNT, Movement_WalkSlowUp
	waitmovement 0
	delay 20
	speakername CommonName_Text_MagmaGrunt
	msgbox ShuiyunTownBoatCaptainsRoom_Text_2 MSGBOX_DEFAULT
	applymovement LOCALID_CAPTAIN, Movement_JumpInPlace
	waitmovement 0
	speakername CommonName_Text_Captain
	msgbox ShuiyunTownBoatCaptainsRoom_Text_3 MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_GRUNT, Movement_LookDownExclamation
	waitmovement 0
	delay 20
	applymovement LOCALID_AQUA_GRUNT, Movement_LookDownExclamation
	waitmovement 0
	delay 20

	speakername CommonName_Text_AquaGrunt
	applymovement LOCALID_AQUA_GRUNT, Movement_WalkSlowDown
	waitmovement 0
	delay 20
	msgbox ShuiyunTownBoatCaptainsRoom_Text_4 MSGBOX_DEFAULT

	speakername CommonName_Text_MagmaGrunt
	applymovement LOCALID_MAGMA_GRUNT, Movement_WalkSlowDown
	waitmovement 0
	delay 20
	msgbox ShuiyunTownBoatCaptainsRoom_Text_5 MSGBOX_DEFAULT

	speakername CommonName_Text_Captain
	applymovement LOCALID_CAPTAIN, Movement_JumpInPlace
	waitmovement 0
	msgbox ShuiyunTownBoatCaptainsRoom_Text_6 MSGBOX_DEFAULT
	applymovement LOCALID_CAPTAIN, Movement_CaptainLeave1
	waitmovement 0

	applymovement OBJ_EVENT_ID_PLAYER, Movement_LookRight
	waitmovement 0
	delay 20
	msgbox ShuiyunTownBoatCaptainsRoom_Text_7 MSGBOX_DEFAULT
	givemon SPECIES_EEVEE, 20, move1=MOVE_COVET, move2=MOVE_QUICK_ATTACK, move3=MOVE_BABY_DOLL_EYES, move4=MOVE_HELPING_HAND
	delay 20
	
	applymovement LOCALID_CAPTAIN, Movement_CaptainLeave2
	waitmovement 0
	removeobject LOCALID_CAPTAIN
	delay 20

	applymovement OBJ_EVENT_ID_PLAYER, Movement_LookUp
	waitmovement 0

	speakername CommonName_Text_MagmaGrunt
	msgbox ShuiyunTownBoatCaptainsRoom_Text_8 MSGBOX_DEFAULT

	setvar VAR_SHUIYUN_BOAT_INTRO_BATTLE_STATE, 1
	trainerbattle_two_trainers TRAINER_NEW_GRUNT_AQUA_1, ShuiyunTownBoatCaptainsRoom_Text_Aqua_Grunt_LoseText, TRAINER_NEW_GRUNT_MAGMA_1, ShuiyunTownBoatCaptainsRoom_Text_Magma_Grunt_LoseText
	call ShuiyunTownBoatCaptainsRoom_EventScript_PostBattle
	end

ShuiyunTownBoatCaptainsRoom_EventScript_RunCutscene2:
	lock
	removeobject LOCALID_CAPTAIN

	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp2
	waitmovement 0

	applymovement LOCALID_AQUA_GRUNT, Movement_LookDown
	waitmovement 0
	delay 20
	applymovement LOCALID_MAGMA_GRUNT, Movement_LookDownExclamation
	waitmovement 0
	delay 20
	speakername CommonName_Text_MagmaGrunt
	msgbox ShuiyunTownBoatCaptainsRoom_Text_Rematch MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_NEW_GRUNT_AQUA_1, ShuiyunTownBoatCaptainsRoom_Text_Aqua_Grunt_LoseText, TRAINER_NEW_GRUNT_MAGMA_1, ShuiyunTownBoatCaptainsRoom_Text_Magma_Grunt_LoseText
	call ShuiyunTownBoatCaptainsRoom_EventScript_PostBattle
	end

ShuiyunTownBoatCaptainsRoom_EventScript_PostBattle::

	special HealPlayerParty

	speakername CommonName_Text_MagmaGrunt
	applymovement LOCALID_MAGMA_GRUNT, Movement_JumpInPlaceRight
	waitmovement 0
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle1 MSGBOX_DEFAULT

	speakername CommonName_Text_AquaGrunt
	applymovement LOCALID_AQUA_GRUNT, Movement_LookLeft
	waitmovement 0
	delay 20
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle2 MSGBOX_DEFAULT

	speakername CommonName_Text_MagmaGrunt
	applymovement LOCALID_MAGMA_GRUNT, Movement_MagmaGruntThink
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle3 MSGBOX_DEFAULT

	waitmovement 0
	
	speakername CommonName_Text_AquaGrunt
	applymovement LOCALID_AQUA_GRUNT, Movement_LookDown
	waitmovement 0
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle4 MSGBOX_DEFAULT

	speakername CommonName_Text_MagmaGrunt
	applymovement LOCALID_MAGMA_GRUNT, Movement_LookDownExclamation
	waitmovement 0
	delay 20
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle5 MSGBOX_DEFAULT

	applymovement LOCALID_MAGMA_GRUNT, Movement_MagmaGruntLeave
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT
	delay 20

	speakername CommonName_Text_AquaGrunt
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle6 MSGBOX_DEFAULT
	applymovement LOCALID_AQUA_GRUNT, Movement_AquaGruntLeave
	waitmovement 0
	removeobject LOCALID_AQUA_GRUNT
	delay 20

	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	addobject LOCALID_CAPTAIN

	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp2
	waitmovement 0

	speakername CommonName_Text_Captain
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle7 MSGBOX_DEFAULT

	giveitem ITEM_POKE_BALL, 30
	giveitem ITEM_SUPER_POTION, 10

	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle8 MSGBOX_DEFAULT

	playfanfare MUS_OBTAIN_ITEM
	message ShuiyunTownBoatCaptainsRoom_Text_GetEevee
	waitfanfare
	waitmessage

	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShuiyunTownBoatCaptainsRoom_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, ShuiyunTownBoatCaptainsRoom_EventScript_CutsceneEnd
	end

ShuiyunTownBoatCaptainsRoom_EventScript_NicknameStarter::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto ShuiyunTownBoatCaptainsRoom_EventScript_CutsceneEnd
	end

ShuiyunTownBoatCaptainsRoom_EventScript_CutsceneEnd::
	speakername CommonName_Text_Captain
	msgbox ShuiyunTownBoatCaptainsRoom_Text_PostBattle9, MSGBOX_DEFAULT
	setvar VAR_SHUIYUN_BOAT_INTRO_BATTLE_STATE, 2
	setflag FLAG_DEFEATED_INTRO_GRUNTS
	release
	end

ShuiyunTownBoatCaptainsRoom_Text_1:
	.string "Oh captain, my captain…{EMOJI_HEART}\n"
	.string "You're not supposed to sail here…$"

ShuiyunTownBoatCaptainsRoom_Text_2:
	.string "I bet you're illegally fishing!\n"
	.string "We'll have to impound your ship!$"

ShuiyunTownBoatCaptainsRoom_Text_3:
	.string "Uhhhh… Behind you!$"

ShuiyunTownBoatCaptainsRoom_Text_4:
	.string "Oh look, a hero…{EMOJI_HEART}\p"
	.string "Are you really going to stand up\n"
	.string "against the two of us alone? {EMOJI_HEART}$"

ShuiyunTownBoatCaptainsRoom_Text_5:
	.string "That's right! This cowardly CAPTAIN\n"
	.string "isn't even a TRAINER! He's helpless!\p"
	.string "Go on, run for your life!$"

ShuiyunTownBoatCaptainsRoom_Text_6:
	.string "Wahhhhh!! Leave me alone!!$"

ShuiyunTownBoatCaptainsRoom_Text_7:
	.string "The CAPTAIN secretly hands you\n"
	.string "a POKé BALL.$"

ShuiyunTownBoatCaptainsRoom_Text_8:
	.string "Okay, buddy.\n"
	.string "You're in for a world of pain!$"

ShuiyunTownBoatCaptainsRoom_Text_Rematch:
	.string "Why, you persistent little…\p"
	.string "We'll simply have to beat you\n"
	.string "again!$"

ShuiyunTownBoatCaptainsRoom_Text_Magma_Grunt_LoseText:
	.string "Hey! This is supposed to be easy!$"
	
ShuiyunTownBoatCaptainsRoom_Text_Aqua_Grunt_LoseText:
	.string "What a feisty Trainer…{EMOJI_HEART}$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle1:
	.string "Tsk… I knew working with TEAM AQUA was\n"
	.string "a mistake. You're dead weight!$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle2:
	.string "Now, now…{EMOJI_HEART}\p"
	.string "COURTNEY did mention a certain someone\n"
	.string "sent by the POKéMON LEAGUE…{EMOJI_HEART}$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle3:
	.string "Right, right! We were supposed to find\n"
	.string "this repar-{PAUSE 15} rap-{PAUSE 15} reprare-{PAUSE 15} repair-{PAUSE 15}$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle4:
	.string "Representative {PLAYER}. {EMOJI_HEART}$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle5:
	.string "Yes! Exactly! That's you, isn't it?!\p"
	.string "We need to tell COURTNEY and MATT!\n"
	.string "Grab the others! Let's go!$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle6:
	.string "Time to bid adieu… {EMOJI_HEART}$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle7:
	.string "Ah, sorry for the trouble.\p"
	.string "They rushed inside as soon as I docked.\p"
	.string "Here are the supplies STEVEN asked me\n"
	.string "to give you.$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle8:
	.string "Oh, and about the EEVEE…\p"
	.string "I saw you battle with the grunts.\n"
	.string "You're quite capable!\p"
	.string "The EEVEE seems to have taken a liking\n"
	.string "with you as well.\p"
	.string "Why don't you raise it instead?$"

ShuiyunTownBoatCaptainsRoom_Text_GetEevee:
	.string "{PLAYER} received EEVEE!$"

ShuiyunTownBoatCaptainsRoom_Text_PostBattle9:
	.string "Well, here's our stop - TIANLAN ISLAND.\p"
	.string "It's a tourist hotspot known for its\n"
	.string "hospitality.\p"
	.string "If I were you,\n"
	.string "I'd talk to everyone I see.\p"
	.string "They have a habit of giving helpful\n"
	.string "advice and items to aspiring TRAINERS.\p"
	.string "That said, it never rains this much on\n"
	.string "this island. I wonder what's going on.$"

ShuiyunTownBoatCaptainsRoom_Text_TalkCaptain:
	.string "Maybe I should have paid attention\n"
	.string "during TRAINER school…$"

Movement_WalkUp2:
	walk_up
	walk_up
	step_end

Movement_WalkSlowUp:
	walk_slow_up
	step_end

Movement_WalkSlowDown:
	walk_slow_down
	step_end

Movement_LookRight:
	face_right
	emote_question_mark
	step_end

Movement_LookUp:
	face_up
	step_end

Movement_LookDown:
	face_down
	step_end

Movement_LookDownExclamation:
	face_down
	emote_exclamation_mark
	step_end

Movement_LookLeft:
	face_left
	step_end

Movement_JumpInPlaceRight:
	jump_in_place_right
	jump_in_place_right
	step_end

Movement_JumpInPlace:
	jump_in_place_down
	jump_in_place_down
	step_end

	
Movement_MagmaGruntThink:
	walk_slow_left
	walk_slow_up
	walk_slow_right
	walk_slow_down
	emote_question_mark
	step_end
	
Movement_CaptainLeave1:
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	step_end

Movement_CaptainLeave2:
	walk_faster_down
	walk_faster_down
	step_end

Movement_MagmaGruntLeave:
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	step_end

Movement_AquaGruntLeave:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end
	
Movement_CaptainReturn:
	walk_up
	face_left
	step_end

	
Movement_CaptainReturn2:
	walk_up
	face_left
	walk_up
	walk_up
	walk_up
	step_end

Movement_PlayerUp:
	walk_up
	walk_up
	walk_up
	step_end
