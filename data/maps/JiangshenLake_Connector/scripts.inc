JiangshenLake_Connector_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, JiangshenLake_Connector_OnLoad
	.byte 0

.set LOCALID_MATT, 1
.set LOCALID_COURTNEY, 2

JiangshenLake_Connector_OnLoad:
	setvar VAR_TEMP_0, 0
	call_if_lt VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 3, JiangshenLake_Connector_EventScript_CloseDoor
	call_if_lt VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 4, JiangshenLake_Connector_EventScript_RemoveMatt
	call_if_lt VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 5, JiangshenLake_Connector_EventScript_RemoveCourtney
	end

JiangshenLake_Connector_EventScript_CloseDoor::
	setmetatile 9, 9, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 10, 9, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 11, 9, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 9, 10, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 10, 10, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 11, 10, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

JiangshenLake_Connector_EventScript_RemoveMatt::
	removeobject LOCALID_MATT
	return

JiangshenLake_Connector_EventScript_RemoveCourtney::
	removeobject LOCALID_COURTNEY
	return 

JiangshenLake_Connector_EventScript_Door::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox JiangshenLake_Connector_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_JIANGSHEN_KEY
	goto_if_eq VAR_RESULT, FALSE, JiangshenLake_Connector_EventScript_DontOpenDoor
	msgbox JiangshenLake_Connector_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JiangshenLake_Connector_EventScript_DontOpenDoor
	msgbox JiangshenLake_Connector_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 9, 9, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 10, 9, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 11, 9, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 9, 10, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 10, 10, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 11, 10, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 3
	releaseall
	end

JiangshenLake_Connector_EventScript_DontOpenDoor::
	releaseall
	end

JiangshenLake_Connector_Text_DoorIsLocked:
	.string "The door is locked.$"

JiangshenLake_Connector_Text_UseBasementKey:
	.string "Use the KEYCARD?$"

JiangshenLake_Connector_Text_UsedBasementKey:
	.string "{PLAYER} used the KEYCARD.\p"
	.string "The door opened!$"

JiangshenLake_Connector_Trainer_Matt::
	trainerbattle_single TRAINER_JIANGSHEN_MATT, JiangshenLake_Connector_Text_MattIntro, JiangshenLake_Connector_Text_MattDefeat, JiangshenLake_Connector_Trainer_Matt_PostBattle
	end

JiangshenLake_Connector_Trainer_Matt_PostBattle::
	lock
	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 4
	setflag FLAG_HIDE_JIANGSHEN_MATT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Connector_Text_MattPostBattle, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MATT
	fadescreen FADE_FROM_BLACK
	release
	end

JiangshenLake_Connector_Trainer_Courtney::
	trainerbattle_single TRAINER_JIANGSHEN_COURTNEY, JiangshenLake_Connector_Text_CourtneyIntro, JiangshenLake_Connector_Text_CourtneyDefeat, JiangshenLake_Connector_Trainer_Courtney_PostBattle
	end

JiangshenLake_Connector_Trainer_Courtney_PostBattle::
	lock
	setvar VAR_JIANGSHEN_GRUNT_BATTLE_STATE, 5
	setflag FLAG_HIDE_JIANGSHEN_COURTNEY

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Connector_Text_CourtneyPostBattle, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	removeobject LOCALID_COURTNEY
	fadescreen FADE_FROM_BLACK
	release
	end

JiangshenLake_Connector_Text_MattIntro::
	.string "Hoohahaha! An intruder!\p"
	.string "You must be the TRAINER my grunts keep\n"
	.string "warning me about!\p"
	.string "But they didn't tell me it was just\n"
	.string "a kid! Bwahahahaha!\p"
	.string "Of course you wouldn't understand\n"
	.string "TEAM AQUA's noble ambitions-\p"
	.string "…What? Why are you giving me that\n"
	.string "'sick and tired of this' look?!$"

JiangshenLake_Connector_Text_MattDefeat::
	.string "Wh-wait!$"

JiangshenLake_Connector_Text_MattPostBattle::
	.string "Oh, you're serious…\n"
	.string "No matter! I'll do my part to serve\l"
	.string "my captain ARCHIE, wherever he is!\p"
	.string "Even though you found us, you're too\n"
	.string "late to stop us! Hoohahahaha!$"

JiangshenLake_Connector_Text_CourtneyIntro::
	.string "Analyzing… {EMOJI_NOTE}\n"
	.string "Target is… impatient. {EMOJI_NOTE}\p"
	.string "Deleting…$"

JiangshenLake_Connector_Text_CourtneyDefeat::
	.string "Hah. {EMOJI_NOTE}$"

JiangshenLake_Connector_Text_CourtneyPostBattle::
	.string "Just enough time…\n"
	.string "… MAXIE's dream. {EMOJI_NOTE}\p"
	.string "Follow if you dare! Ahahaha. {EMOJI_NOTE}$"

CommonName_Text_Matt:
	.string "MATT$"
	
CommonName_Text_Courtney:
	.string "COURTNEY$"


JiangshenLake_Connector_EventScript_SaveGameReminder::
	lock
	msgbox JiangshenLake_Connector_Text_SaveGameReminder, MSGBOX_DEFAULT
	msgbox JiangshenLake_Connector_Text_SaveGamePrompt, MSGBOX_DEFAULT
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 1
	release
	end

JiangshenLake_Connector_Text_SaveGameReminder::
	.string "Upon proceeding to the sultana's-\n"
	.string "I mean, reaching the peak, several\l"
	.string "cutscenes will play in sequence.\p"
	.string "It is recommended that you set aside\n"
	.string "sufficient time to view these scenes\l"
	.string "in their entirety.$"

JiangshenLake_Connector_Text_SaveGamePrompt::
	.string "There is no post-game content, so\n"
	.string "unsaved progress will be lost after\l"
	.string "the upcoming battle.\p"
	.string "Saving the game is recommended.$"