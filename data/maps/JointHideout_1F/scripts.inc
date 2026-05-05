JointHideout_1F_MapScripts::
	.byte 0

.set LOCALID_COURTNEY, 30


JointHideout_EventScript_Courtney_Battle::
	lock
	faceplayer
	speakername CommonName_Text_Courtney
	msgbox JointHideout_Text_Courtney_1, MSGBOX_DEFAULT

	trainerbattle_single TRAINER_LANTERN_COURTNEY, JointHideout_Text_Courtney_BattleIntro, JointHideout_Text_Courtney_BattleDefeat, SkywardTrail_EventScript_Colress_PostBattle
	end

JointHideout_EventScript_Courtney_PostBattle::

	speakername CommonName_Text_Courtney
	msgbox JointHideout_Text_Courtney_PostBattle_1, MSGBOX_DEFAULT

	applymovement LOCALID_COURTNEY, JointHideout_Movement_Courtney_Leave
	waitmovement 0

	removeobject LOCALID_COURTNEY
	setflag FLAG_HIDE_LANTERN_CAVE_COURTNEY

	release
	end

JointHideout_Text_Courtney_1::
	.string "A shared vision… {EMOJI_NOTE}\n"
	.string "AQUA and MAGMA's cooperation…\l"
	.string "Let's say… failure. {EMOJI_NOTE}\p"
	.string "MATT… was too romantic.\n"
	.string "Too soft… despite the muscles. {EMOJI_NOTE}\p"
	.string "How about you… {PLAYER}? {EMOJI_NOTE}$"

JointHideout_Text_Courtney_BattleIntro::
	.string "Eradication. {EMOJI_NOTE}$"

JointHideout_Text_Courtney_BattleDefeat::
	.string "… Hah!$"

JointHideout_Text_Courtney_PostBattle_1::
	.string "Funny. {EMOJI_NOTE}\p"
	.string "Even with MEGA EVOLUTION from\n"
	.string "that COLRESS…\p"
	.string "Well. No big deal.\p"
	.string "You are…\n"
	.string "A non-factor. {EMOJI_NOTE}$"

	
JointHideout_Movement_Courtney_Leave::
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
