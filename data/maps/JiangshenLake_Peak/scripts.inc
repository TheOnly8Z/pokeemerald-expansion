JiangshenLake_Peak_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JiangshenLake_Peak_OnFrame
	.byte 0

.set LOCALID_MATT, 2
.set LOCALID_COURTNEY, 1
.set LOCALID_COLRESS, 3

JiangshenLake_Peak_OnFrame::
	map_script_2 VAR_JIANGSHEN_PEAK_STATE, 0, JiangshenLake_Peak_EventScript_Colress_PreCutscene1
	.2byte 0

JiangshenLake_Peak_EventScript_Colress_QuickEnding::
	lock
	faceplayer
	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Peak_Text_QuickEnding_1 MSGBOX_DEFAULT
	msgbox JiangshenLake_Peak_Text_QuickEnding_2 MSGBOX_DEFAULT
	msgbox JiangshenLake_Peak_Text_QuickEnding_3 MSGBOX_DEFAULT
	trainerbattle_single TRAINER_COLRESS_RAYQUAZA, JiangshenLake_Text_BattleIntro_Colress, JiangshenLake_Text_Defeated_Colress, JiangshenLake_Peak_EventScript_Colress_QuickEnding_PostBattle
	release
	end

JiangshenLake_Peak_EventScript_Colress_QuickEnding_PostBattle::
	msgbox JiangshenLake_Peak_Text_QuickEnding_PostDefeat_1 MSGBOX_DEFAULT
	special StartCredits
	end

JiangshenLake_Peak_EventScript_Colress_PreCutscene1::
	lock

	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepDown2
	waitmovement 0

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PreCutscene_1_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PreCutscene_2_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PreCutscene_3_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PreCutscene_4_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PreCutscene_5_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PreCutscene_6_Matt, MSGBOX_DEFAULT
	closemessage

	@ Colress walks in
	applymovement LOCALID_COLRESS, Movement_ColressEnters
	waitmovement 0

	goto JiangshenLake_Peak_EventScript_Colress_PreCutscene2
	end

JiangshenLake_Peak_EventScript_Colress_PreCutscene2::

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PreCutscene_7_Colress, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PreCutscene_8_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PreCutscene_9_Colress, MSGBOX_DEFAULT
	
	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PreCutscene_10_Colress, MSGBOX_DEFAULT
	
	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PreCutscene_11_Courtney, MSGBOX_DEFAULT
	
	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PreCutscene_12_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PreCutscene_13_Courtney, MSGBOX_DEFAULT

	goto JiangshenLake_Peak_EventScript_Colress_PostCutcene1
	end

JiangshenLake_Peak_EventScript_Colress_PostCutcene1::
	@ HERE COMES DAT BOI
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate

	@ Ideally we make rayquaza's sprite show up and stuff right here
	@ But I'm lazy dev

	@ rayquaza yaps and weather disappears
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather

	@ the admins cope and seethe about it
	
	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostCutscene_1_Matt, MSGBOX_DEFAULT
	
	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostCutscene_2_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PostCutscene_3_Colress, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostCutscene_4_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostCutscene_5_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PostCutscene_6_Colress, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostCutscene_7_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostCutscene_8_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PostCutscene_9_Colress, MSGBOX_DEFAULT

	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PostCutscene_10_Colress, MSGBOX_DEFAULT
	

	@ battle time
	trainerbattle_single TRAINER_COLRESS_RAYQUAZA, JiangshenLake_Text_BattleIntro_Colress, JiangshenLake_Text_Defeated_Colress, JiangshenLake_Peak_EventScript_Colress_PostBattle
	end

JiangshenLake_Peak_EventScript_Colress_PostBattle::
	setvar VAR_JIANGSHEN_PEAK_STATE, 1
	lock
	speakername CommonName_Text_Colress
	msgbox JiangshenLake_Text_PostBattle_1_Colress, MSGBOX_DEFAULT
	closemessage

	@ and he waddles away (waddle waddle)
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_COLRESS, Movement_ColressLeave
	waitmovement 0
	removeobject LOCALID_COLRESS
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceDown
	waitmovement 0

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostBattle_2_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostBattle_3_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostBattle_4_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostBattle_5_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostBattle_6_Matt, MSGBOX_DEFAULT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostBattle_7_Courtney, MSGBOX_DEFAULT

	speakername CommonName_Text_Matt
	msgbox JiangshenLake_Text_PostBattle_8_Matt, MSGBOX_DEFAULT
	msgbox JiangshenLake_Text_PostBattle_9_Matt, MSGBOX_DEFAULT
	closemessage

	@ matt leaves
	applymovement LOCALID_MATT, Movement_MattLeave
	waitmovement 0
	removeobject LOCALID_MATT

	speakername CommonName_Text_Courtney
	msgbox JiangshenLake_Text_PostBattle_10_Courtney, MSGBOX_DEFAULT
	closemessage

	@ courtney leaves
	applymovement LOCALID_COURTNEY, Movement_CourtneyLeave
	waitmovement 0
	removeobject LOCALID_COURTNEY

	@ credits for now
	@ TODO epilouge and postgame state

	speakername NULL
	fadescreen FADE_TO_BLACK
	msgbox JiangshenLake_Text_PostBattle_10_Narrator, MSGBOX_DEFAULT
	msgbox JiangshenLake_Peak_Text_TheEnd, MSGBOX_DEFAULT
	special StartCredits

	release
	end

JiangshenLake_Peak_Text_QuickEnding_1::
	.string "Pleasure to make your acquaintance.\n"
	.string "I am COLRESS, a POKéMON researcher.\p"
	.string "You must be {PLAYER}, right?\p"
	.string "My 'colleagues', MATT and COURTNEY,\n"
	.string "informed me of your arrival.\p"
	.string "They were quite excited to meet you!\n"
	.string "It's a shame they couldn't make it.$"

JiangshenLake_Peak_Text_QuickEnding_2::
	.string "I'm passionate about research into the\n"
	.string "potential of POKéMON!\p"
	.string "We live together with POKéMON, so it's a\n"
	.string "disservice if we don't help them become\l"
	.string "stronger!\p"
	.string "That's why when I heard rumors of\n"
	.string "legendary POKéMON on this island,\l"
	.string "I traveled here all the way from UNOVA!$"

JiangshenLake_Peak_Text_QuickEnding_3::
	.string "Studying the powers of KYOGRE and\n"
	.string "GROUDON, I was perplexed by their\l"
	.string "fear of RAYQUAZA. Or perhaps respect?\p"
	.string "Why can RAYQUAZA suppress the strength\n"
	.string "of those POKéMON?\p"
	.string "There was only one way to find out.\p"
	.string "I built a special device to control\n"
	.string "both RAYQUAZA's behavior and powers!\p"
	.string "But with RAYQUAZA alone, I cannot\n"
	.string "conduct any tests and satiate my\l"
	.string "curiosity.\p"
	.string "That's why I was waiting for you!\p"
	.string "Battle me, {PLAYER}, and let me see\n"
	.string "what RAYQUAZA can truly achieve!$"

JiangshenLake_Peak_Text_QuickEnding_PostDefeat_1::
	.string "You and your POKéMON went beyond\n"
	.string "all of my wildest predictions!\p"
	.string "To be honest, I was so excited to\n"
	.string "show off RAYQUAZA's powers, I didn't\l"
	.string "think about what to do afterwards!\p"
	.string "Wait, I know!\n"
	.string "How about an abrupt cut to credits?$"


JiangshenLake_Text_PreCutscene_1_Courtney::
	.string "… Right on time. {EMOJI_NOTE}$"

JiangshenLake_Text_PreCutscene_2_Matt::
	.string "Hahahaha! That nerd can act mysterious\n"
	.string "all he wants if he's planned it all out!$"

JiangshenLake_Text_PreCutscene_3_Courtney::
	.string "… {PLAYER}. {EMOJI_NOTE}\p"
	.string "…Witness greatness… {EMOJI_NOTE}$"

JiangshenLake_Text_PreCutscene_4_Matt::
	.string "ARCHIE has left us, but I haven't\n"
	.string "forgot his dreams of expanding the\l"
	.string "seas we love!\p"
	.string "Our rivals, TEAM MAGMA…\p"
	.string "We didn't see eye to eye, and all that\n"
	.string "did was foil both teams' plans!$"

JiangshenLake_Text_PreCutscene_5_Courtney::
	.string "… Common foe. {EMOJI_NOTE}$"

JiangshenLake_Text_PreCutscene_6_Matt::
	.string "Who's say we can't expand BOTH\n"
	.string "land and sea?\p"
	.string "There's just a little green serpent\n"
	.string "in the way. Well, not anymore!\p"
	.string "Make your grand entrance, nerd!$"

JiangshenLake_Text_PreCutscene_7_Colress::
	.string "Pleasure to make your acquaintance,\n"
	.string "and I apologize on behalf of my less…\l"
	.string "well spoken, 'colleagues'.$"

JiangshenLake_Text_PreCutscene_8_Matt:
	.string "Hoh! You're quite the comedian!$"

JiangshenLake_Text_PreCutscene_9_Colress::
	.string "My name is COLRESS. I'm a researcher\n"
	.string "interested in the hidden potential in\l"
	.string "POKéMON.\p"
	.string "When I heard of POKéMON with the power\n"
	.string "to conjure world-changing weather,\l"
	.string "I simply couldn't control my excitement!$"

JiangshenLake_Text_PreCutscene_10_Colress::
	.string "My 'colleagues' have kindly demonstrated\n"
	.string "demonstrated for me the power of the\l"
	.string "legendary POKéMON, KYOGRE and GROUDON.\p"
	.string "Imagine my shock when I was told that\n"
	.string "these terrifying forces of nature\l"
	.string "answer to a higher power!\p"
	.string "I've poured my passion into a device\n"
	.string "that will let me control and test\l"
	.string "the power of that POKéMON, RAYQUAZA.$"

JiangshenLake_Text_PreCutscene_11_Courtney::
	.string "…When they fight…RAYQUAZA arrives…\n"
	.string "…Annoying!$"

JiangshenLake_Text_PreCutscene_12_Matt::
	.string "Nerd gets his snake, weird girl gets her\n"
	.string "land, and I get my ocean!\p"
	.string "And you dare stand in our way?\p"
	.string "Courtney! Send out GROUDON!\n"
	.string "Let's get this ship sailing already!$"

JiangshenLake_Text_PreCutscene_13_Courtney::
	.string "…Delightful. {EMOJI_NOTE}$"

JiangshenLake_Text_PostCutscene_1_Matt::
	.string "You got your snake, nerd! Why is it still\n"
	.string "controlling KYOGRE and GROUDON!$"

JiangshenLake_Text_PostCutscene_2_Courtney::
	.string "…You…\n"
	.string "…Unless…$"

JiangshenLake_Text_PostCutscene_3_Colress::
	.string "Oh, please don't misunderstand me!\p"
	.string "I am simply observing how RAYQUAZA\n"
	.string "influences the other POKéMON!\p"
	.string "It's a shame GROUDON and KYOGRE are so\n"
	.string "so powerless by comparison.$"

JiangshenLake_Text_PostCutscene_4_Courtney::
	.string "MAXIE's hope… GROUDON…\n"
	.string "…powerless?…$"

JiangshenLake_Text_PostCutscene_5_Matt::
	.string "Four-eyes! If you dare insult TEAM\n"
	.string "AQUA's grand plans, then I'll have\l"
	.string "you sleep with the fishes!$"

JiangshenLake_Text_PostCutscene_6_Colress::
	.string "Ah, so you would like to volunteer\n"
	.string "to test the power of RAYQUAZA?\p"
	.string "Thank you for your enthuasism!\n"
	.string "RAYQUAZA, use DRACO METEOR-$"

JiangshenLake_Text_PostCutscene_7_Matt::
	.string "Uhhh… heh… Don't take that seriously!\n"
	.string "It was just… some good ol' sailor humor!$"

JiangshenLake_Text_PostCutscene_8_Courtney::
	.string "Grr…!!$"

JiangshenLake_Text_PostCutscene_9_Colress::
	.string "Oh, my bad.\p"
	.string "The two of you can sit here and\n"
	.string "help me take notes, if you'd like.$"

JiangshenLake_Text_PostCutscene_10_Colress::
	.string "{PLAYER}, it looks like you are the\n"
	.string "only trainer here who is strong\l"
	.string "enough to help me out.\p"
	.string "My goal is quite simple!\n"
	.string "I want to bring out the full power\l"
	.string "hidden inside every POKéMON!"
	.string "Now, battle me and show me just how\n"
	.string "much potential is within RAYQUAZA!$"

JiangshenLake_Text_BattleIntro_Colress:
	.string "All parameters optimal.\n"
	.string "The experiment begins!$"

JiangshenLake_Text_Defeated_Colress:
	.string "An unexpected result…\n"
	.string "I must study this further!$"

JiangshenLake_Text_PostBattle_1_Colress::
	.string "Marvelous!\p"
	.string "You defeated such a powerful POKéMON\n"
	.string "as well as RAYQUAZA with just your\l"
	.string "ordinary POKéMON!\p"
	.string "I can't say I'm disapointed. In fact,\n"
	.string "I'm glad you showed me just how much\l"
	.string "potential a TRAINER can bring out of\l"
	.string "their POKéMON, regardless of species!\p"
	.string "You remind me of a TRAINER I knew from\n"
	.string "the UNOVA region, where I came from.\p"
	.string "If we meet again, perhaps I should\n"
	.string "share you a story or two.\p"
	.string "That said, I must take my leave to\n"
	.string "review my findings.\p"
	.string "I wish you and your POKéMON\n"
	.string "safe travels wherever you go!$"

JiangshenLake_Text_PostBattle_2_Matt::
	.string "He's just gonna walk away like that?\n"
	.string "Never should have trusted a nerd……$"

JiangshenLake_Text_PostBattle_3_Courtney::
	.string "…GROUDON left…\n"
	.string "…What of Maxie's dream…$"

JiangshenLake_Text_PostBattle_4_Matt::
	.string "I don't bloody care how many times\n"
	.string "it takes! I'll find that whale again\l"
	.string "and bring forth the great oceans!$"

JiangshenLake_Text_PostBattle_5_Courtney::
	.string "…Analyze… retry… persistance…$"

JiangshenLake_Text_PostBattle_6_Matt::
	.string "In fact, we'll try again right here!\p"
	.string "…\p"
	.string "Wh-what did you say?\p"
	.string "Your POKéMON is gonna do WHAT to\n"
	.string "my WHAT?! Is that even possible?$"

JiangshenLake_Text_PostBattle_7_Courtney::
	.string "…Scary. {EMOJI_NOTE}$"

JiangshenLake_Text_PostBattle_8_Matt::
	.string "Hoohahaha! You have guts, kid!\p"
	.string "I'll have to admit defeat, both\n"
	.string "in strength and in spirit!\p"
	.string "{PLAYER}, is it?\p"
	.string "You showed me a good time with\n"
	.string "your POKéMON!\p"
	.string "Ever since ARCHIE walked away,\n"
	.string "I've been stuck in a rut until\l"
	.string "you came along!$"

JiangshenLake_Text_PostBattle_9_Matt::
	.string "You know, being in TEAM AQUA were\n"
	.string "the best days of my life.\p"
	.string "Me, the boss, and the boys,\n"
	.string "working together to change the world…\p"
	.string "Oh-hoh. I'm getting sentimental.\p"
	.string "Where did ARCHIE go? Why has he given\n"
	.string "up on what we were fighting for?\p"
	.string "…\p"
	.string "Hehehe! This is too deep for me!\p"
	.string "I'm just gonna keep battling and\n"
	.string "training until my boss returns!\p"
	.string "AQUA or no AQUA, you better prepare\n"
	.string "for the day I wipe that smirk off\l"
	.string "your face, punk!$"

JiangshenLake_Text_PostBattle_10_Courtney::
	.string "Hah…… {EMOJI_NOTE}\p"
	.string "Ahahahahaha!\p"
	.string "Why does this keep happening to me!\n"
	.string "Without MAXIE, is it really not\l"
	.string "possible anymore?\p"
	.string "…I want answers…\p"
	.string "MAXIE… I must find you… Find what you\n"
	.string "found out. {EMOJI_NOTE}$"
 
JiangshenLake_Text_PostBattle_10_Narrator::
	.string "With the ADMINs defeated,\n"
	.string "TIANLAN ISLAND is saved from certain\l"
	.string "destruction.\p"
	.string "The three legendary POKéMON, freed from\n"
	.string "the influence of COLRESS and company,\l"
	.string "roam HOENN once more.\p"
	.string "There are many more tales to be told\n"
	.string "about {PLAYER}'s adventures on\l"
	.string "TIANLAN ISLAND after the crisis.\p"
	.string "Alas, the developer did not add\n"
	.string "any post-game content, so you'll\l"
	.string "have to leave it to your imagination.$"

CommonName_Text_Colress:
	.string "COLRESS$"

JiangshenLake_Peak_Text_TheEnd::
	.string "THE END… (for now)$"

Movement_StepDown2::
	walk_down
	walk_down
	step_end

Movement_ColressEnters::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_FaceLeft::
	face_left
	step_end

Movement_FaceRight::
	face_right
	step_end

Movement_FaceDown::
	face_down
	step_end

Movement_FaceUp::
	face_up
	step_end

Movement_ColressLeave::
	walk_up
	walk_up
	step_end

Movement_MattLeave::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_CourtneyLeave::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
