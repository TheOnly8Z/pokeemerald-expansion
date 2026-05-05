SkywardTrail_Lab_B1_MapScripts::
	.byte 0

SkywardTrail_Lab_B1_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call SkywardTrail_Lab_B1_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

SkywardTrail_Lab_B1_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call SkywardTrail_Lab_B1_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

SkywardTrail_Lab_B1_EventScript_SetBarrierStateBlueButton::
	@ button blue
	setmetatile 17, 14, METATILE_BikeShop_Button_Pressed, FALSE

	@ button green
	setmetatile 47, 4, METATILE_BikeShop_Button_Green, FALSE

	@ top left (green)
	setmetatile 21, 1, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_Bottom, TRUE

	@ left (green)
	setmetatile 9, 8, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 9, 9, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 9, 10, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 9, 11, METATILE_BikeShop_Barrier_Green_Bottom, TRUE

	@ center right (green)
	setmetatile 35, 15, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 35, 16, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 35, 17, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 35, 18, METATILE_BikeShop_Barrier_Green_Bottom, TRUE

	@ top right (blue)
	setmetatile 35, 1, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 35, 2, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 35, 3, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 35, 4, METATILE_BikeShop_Wall_Edge_Top, FALSE

	@ center left (blue)
	setmetatile 21, 14, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 21, 15, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 21, 16, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 21, 17, METATILE_BikeShop_Wall_Edge_Top, FALSE

	@ right (blue)
	setmetatile 50, 14, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 50, 15, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 50, 16, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 50, 17, METATILE_BikeShop_Wall_Edge_Top, FALSE

	return

SkywardTrail_Lab_B1_EventScript_SetBarrierStateGreenButton::
	@ button blue
	setmetatile 17, 14, METATILE_BikeShop_Button_Blue, FALSE

	@ button green
	setmetatile 47, 4, METATILE_BikeShop_Button_Pressed, FALSE

	@ top left (green)
	setmetatile 21, 1, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 21, 4, METATILE_BikeShop_Wall_Edge_Top, FALSE

	@ left (green)
	setmetatile 9, 8, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 9, 9, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 9, 10, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 9, 11, METATILE_BikeShop_Wall_Edge_Top, FALSE

	@ center right (green)
	setmetatile 35, 15, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 35, 16, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 35, 17, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 35, 18, METATILE_BikeShop_Wall_Edge_Top, FALSE

	@ top right (blue)
	setmetatile 35, 1, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 35, 2, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 35, 3, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 35, 4, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE

	@ center left (blue)
	setmetatile 21, 14, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 21, 15, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 21, 16, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 21, 17, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE

	@ right (blue)
	setmetatile 50, 14, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 50, 15, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 50, 16, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 50, 17, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	return


SkywardTrail_Lab_B1_Text_ScientistAskGetResearch:
	.string "Oh, fiddlesticks…\p"
	.string "TEAM AQUA messed with the control\n"
	.string "panel, and now it's all dark!\p"
	.string "If we don't fix the settings, the\n"
	.string "power generator is going to overload\l"
	.string "and explode in…… about 4 years!\p"
	.string "What's more, all my research is stored\n"
	.string "on the computers that I can't use!\p"
	.string "You're a trainer, right?\n"
	.string "Can you go kick some TEAM AQUA a-\n"
	.string "I mean, kindly repair what they have\l"
	.string "tampered with?\p"
	.string "All you have to do is step on the big\n"
	.string "RED RESET BUTTON to the north of here.\p"
	.string "The hooligans have activated our\n"
	.string "security gates, so you need to find the\l"
	.string "buttons to open those as well.\p"
	
SkywardTrail_Lab_B1_Text_ScientistRepeat:
	.string "Were you able to find the RED RESET BUTTON?\n"
	.string "It is to the north of here.\p"
	.string "You may have to open some of those security\n"
	.string "gates first with the colored buttons.$"
	
SkywardTrail_Lab_B1_Text_ScientistComplete:
	.string "Yes! You showed them what for!\p"
	.string "Let me check the status of the generator.\p"
	.string "Hmm, it looks like it will now overload\n"
	.string "in one year! An amazing improvement-\l"
	.string "Wait, that's bad.\p"
	.string "I must hurry back and resolve that, but\n"
	.string "do accept this reward for your efforts!$"
	
SkywardTrail_Lab_B1_Text_ScientistExplain:
	.string "This is a battle item for your "