JiangshenLake_Peak_MapScripts::
	.byte 0

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
	.string "… It is as the nerd said.{EMOJI_NOTE}$"

JiangshenLake_Text_PreCutscene_2_Matt::
	.string "Hahahaha! He can act mysterious all he\n"
	.string "wants if he's that good!$"

JiangshenLake_Text_PreCutscene_3_Courtney::
	.string "… {PLAYER}. {EMOJI_NOTE}\p"
	.string "…You are just in time…\p"
	.string "…Witness greatness… {EMOJI_NOTE}$"

JiangshenLake_Text_PreCutscene_4_Matt::
	.string "That scallywag Archie has abandoned\n"
	.string "ship, but I haven't forgot TEAM AQUA's\l"
	.string "dreams!\p"
	.string "TEAM AQUA and TEAM MAGMA…\p"
	.string "We didn't see eye to eye, and all that\n"
	.string "did was to let some brat stop our plans!$"

JiangshenLake_Text_PreCutscene_5_Courtney::
	.string "…Common goal… Common foe…$"

JiangshenLake_Text_PreCutscene_6_Matt::
	.string "Who's say we can't expand BOTH\n"
	.string "land and sea?\p"
	.string "There's just a little green snake\n"
	.string "in the way. Well, not anymore!\p"
	.string "Make your grand entrance, nerd!$"

JiangshenLake_Text_PreCutscene_7_Colress::
	.string "Pleasure to make your acquaintance,\n"
	.string "and I apologize on behalf of my less…\l"
	.string "well spoken, 'colleagues'.$"

JiangshenLake_Text_PreCutscene_8_Matt:
	.string "Tsk.$"

JiangshenLake_Text_PreCutscene_9_Colress::
	.string "My name is COLRESS. I'm a researcher\n"
	.string "interested in the hidden potential in\l"
	.string "POKéMON.\p"
	.string "When I heard of POKéMON with the power\n"
	.string "to conjure world-changing weather in HOENN,\l"
	.string "I simply couldn't control my excitement!$"

JiangshenLake_Text_PreCutscene_10_Colress::
	.string "My 'colleagues' have kindly demonstrated\n"
	.string "demonstrated for me the power of the\l"
	.string "legendary POKéMON, KYOGRE and GROUDON.\p"
	.string "Imagine my shock when I was told that\n"
	.string "these terrifying forces of nature\l"
	.string "answer to a higher power!\p"
	.string "I've poured my passion into a device that\n"
	.string "will let me control and test the power of\l"
	.string "that POKéMON, RAYQUAZA.$"

JiangshenLake_Text_PreCutscene_11_Courtney::
	.string "…When they fight…RAYQUAZA arrives…\n"
	.string "…Annoying!$"

JiangshenLake_Text_PreCutscene_12_Matt::
	.string "Nerd gets his snake, quiet girl gets her\n"
	.string "land, and I get my ocean!\p"
	.string "And you dare stand in our way?\p"
	.string "Courtney! Send out GROUDON! Let's get this\n"
	.string "ship sailing already!$"

JiangshenLake_Text_PreCutscene_13_Courtney::
	.string "…Delightful. {EMOJI_NOTE}$"

JiangshenLake_Text_PostCutscene_1_Matt::
	.string "You got your snake, nerd! Why is it still\n"
	.string "controlling KYOGRE?!$"

JiangshenLake_Text_PostCutscene_2_Courtney::
	.string "…You…\n"
	.string "…Unless…$"

JiangshenLake_Text_PostCutscene_3_Colress::
	.string "Oh, please don't misunderstand me!\p"
	.string "I am simply experimenting with how\n"
	.string "RAYQUAZA influences the other POKéMON!\p"
	.string "It's a shame GROUDON and KYOGRE are so\n"
	.string "limited in potential in comparison.$"

JiangshenLake_Text_PostCutscene_4_Courtney::
	.string "…Maxie's dream…\n"
	.string "…Limited?…$"

JiangshenLake_Text_PostCutscene_5_Matt::
	.string "You talk smack about TEAM AQUA, and I'll\n"
	.string "have you sleep with the fishes!$"

JiangshenLake_Text_PostCutscene_6_Colress::
	.string "Ah, so you would like to volunteer\n"
	.string "testing the power of RAYQUAZA?\p"
	.string "Thank you for your enthuasism!\n"
	.string "RAYQUAZA, use DRACO METEOR-$"

JiangshenLake_Text_PostCutscene_7_Matt::
	.string "Uhhh… Hahaha… Don't take that seriously!\n"
	.string "It was just a sailor's funny little joke!$"

JiangshenLake_Text_PostCutscene_8_Courtney::
	.string "…Grrrrr…$"

JiangshenLake_Text_PostCutscene_8_Colress::
	.string "It looks like you are the only one here\n"
	.string "able to participate in the experiment.\p"
	.string "My dream is quite simple!\n"
	.string "I want to bring out the full power of POKéMON!\p"
	.string "{PLAYER}, show me just how far RAYQUAZA can go!$"

JiangshenLake_Text_BattleIntro_Colress:
	.string "All parameters are optimal.\n"
	.string "Device on. The experiment begins!$"

JiangshenLake_Text_Defeated_Colress:
	.string "An unexpected result…\n"
	.string "I must study this further!$"

JiangshenLake_Text_PostBattle_1_Colress::
	.string "It's quite interesting how you were able to\n"
	.string "defeat a legendary POKéMON with only common\l"
	.string "POKéMON!\p"
	.string "Not to disparage them, but I did not expect\n"
	.string "you could bring out this much potential!\p"
	.string "You remind me of a TRAINER I knew in the\n"
	.string "UNOVA region, where I came from.\p"
	.string "…Perhaps that is a story for another time!\p"
	.string "I have learned so much, and I must take my\n"
	.string "leave to review my findings.\p"
	.string "I wish you and your POKéMON safe travels!$"

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
	.string "Wh-what did you say?\p"
	.string "Your POKéMON is gonna do WHAT to\l"
	.string "my WHAT?! Is that even possible?$"

JiangshenLake_Text_PostBattle_7_Courtney::
	.string "…Scary. {EMOJI_NOTE}$"

JiangshenLake_Text_PostBattle_8_Matt::
	.string "Hahahahahaha! You have guts, kid!\p"
	.string "I'll have to admit defeat, both\l"
	.string "in strength and in spirit!\p"
	.string "{PLAYER}, is it?\p"
	.string "A sailor never gives up! That means\n"
	.string "you better prepare for the day I\l"
	.string "wipe that smirk off your face!$"

JiangshenLake_Text_PostBattle_9_Courtney::
	.string "Ha. {EMOJI_NOTE}\p"
	.string "…The dream never dies…\n"
	.string "…The world… …change is inevitable…\p"
	.string "One day. {EMOJI_NOTE}$"

CommonName_Text_Colress:
	.string "COLRESS$"
