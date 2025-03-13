ShuiyunTownPokemonCenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShuiyunTownPokemonCenter1F_MapScripts
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

.set LOCALID_NURSE, 1

ShuiyunTownPokemonCenter1F_OnTransition:
	setrespawn HEAL_LOCATION_SHUIYUN_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

ShuiyunTownPokemonCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end