# 1 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 2 "data//maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 3 "data//maps/EverGrandeCity/scripts.pory"
	.byte 0
# 4 "data//maps/EverGrandeCity/scripts.pory"

# 5 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 6 "data//maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 7 "data//maps/EverGrandeCity/scripts.pory"
    call_if_unset FLAG_TEST_RIVAL_EVER_GRANDE_CITY_DEFEATED, EverGrandeCity_EventScript_SetupBattleOne
# 8 "data//maps/EverGrandeCity/scripts.pory"
	end
# 9 "data//maps/EverGrandeCity/scripts.pory"

# 10 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 11 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 12 "data//maps/EverGrandeCity/scripts.pory"
	end
# 13 "data//maps/EverGrandeCity/scripts.pory"

# 14 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 15 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 16 "data//maps/EverGrandeCity/scripts.pory"
	end
# 17 "data//maps/EverGrandeCity/scripts.pory"

# 18 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 19 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 20 "data//maps/EverGrandeCity/scripts.pory"
	end
# 21 "data//maps/EverGrandeCity/scripts.pory"

# 22 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 23 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 24 "data//maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 25 "data//maps/EverGrandeCity/scripts.pory"
	end
# 26 "data//maps/EverGrandeCity/scripts.pory"

# 27 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 28 "data//maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"
# 29 "data//maps/EverGrandeCity/scripts.pory"

# 30 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 31 "data//maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE\n"
# 32 "data//maps/EverGrandeCity/scripts.pory"
	.string "CENTER GATE$"
# 33 "data//maps/EverGrandeCity/scripts.pory"

# 34 "data//maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 35 "data//maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
# 36 "data//maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 37 "data//maps/EverGrandeCity/scripts.pory"
	.string "and POKéMON.”$"

EverGrandeCity_EventScript_PickPokemon::
# 41 "data//maps/EverGrandeCity/scripts.pory"
	lockall
# 42 "data//maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_AMPHAROS, 10, 3
# 43 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_0, MSGBOX_YESNO
# 44 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EverGrandeCity_EventScript_PickPokemon_2
# 60 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_3
# 61 "data//maps/EverGrandeCity/scripts.pory"
	waitmessage
EverGrandeCity_EventScript_PickPokemon_1:
# 63 "data//maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 64 "data//maps/EverGrandeCity/scripts.pory"
	releaseall
	end

EverGrandeCity_EventScript_PickPokemon_2:
# 45 "data//maps/EverGrandeCity/scripts.pory"
	givemon SPECIES_AMPHAROS, 36, ITEM_LEFTOVERS, ITEM_LUXURY_BALL, NATURE_MODEST, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_NUZZLE, MOVE_THUNDERBOLT, MOVE_POWER_GEM, MOVE_DRAGON_TAIL, TRUE, FALSE, TYPE_ELECTRIC
# 46 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_ne EverGrandeCity_EventScript_PickPokemon_7
EverGrandeCity_EventScript_PickPokemon_5:
# 54 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 55 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_2
# 56 "data//maps/EverGrandeCity/scripts.pory"
	removeobject 2
# 57 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_TEST_PICK_POKEMON_EVER_GRANDE_CITY
	goto EverGrandeCity_EventScript_PickPokemon_1

EverGrandeCity_EventScript_PickPokemon_6:
# 47 "data//maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 48 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_1
# 49 "data//maps/EverGrandeCity/scripts.pory"
	waitmessage
# 50 "data//maps/EverGrandeCity/scripts.pory"
	releaseall
	end

EverGrandeCity_EventScript_PickPokemon_7:
# 46 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_ne EverGrandeCity_EventScript_PickPokemon_6
	goto EverGrandeCity_EventScript_PickPokemon_5


EverGrandeCity_EventScript_PickSecondPokemon::
# 69 "data//maps/EverGrandeCity/scripts.pory"
	lockall
# 70 "data//maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_GOLEM_ALOLA, 10, 3
# 71 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_0, MSGBOX_YESNO
# 72 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EverGrandeCity_EventScript_PickSecondPokemon_2
# 88 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_3
# 89 "data//maps/EverGrandeCity/scripts.pory"
	waitmessage
EverGrandeCity_EventScript_PickSecondPokemon_1:
# 91 "data//maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 92 "data//maps/EverGrandeCity/scripts.pory"
	releaseall
	end

EverGrandeCity_EventScript_PickSecondPokemon_2:
# 73 "data//maps/EverGrandeCity/scripts.pory"
	givemon SPECIES_GOLEM_ALOLA, 36, ITEM_LEFTOVERS, ITEM_LUXURY_BALL, NATURE_ADAMANT
# 74 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_ne EverGrandeCity_EventScript_PickSecondPokemon_7
EverGrandeCity_EventScript_PickSecondPokemon_5:
# 82 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 83 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_2
# 84 "data//maps/EverGrandeCity/scripts.pory"
	removeobject 4
# 85 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_TEST_PICK_SECOND_POKEMON_EVER_GRANDE_CITY
	goto EverGrandeCity_EventScript_PickSecondPokemon_1

EverGrandeCity_EventScript_PickSecondPokemon_6:
# 75 "data//maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 76 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_PickPokemon_Text_1
# 77 "data//maps/EverGrandeCity/scripts.pory"
	waitmessage
# 78 "data//maps/EverGrandeCity/scripts.pory"
	releaseall
	end

EverGrandeCity_EventScript_PickSecondPokemon_7:
# 74 "data//maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_ne EverGrandeCity_EventScript_PickSecondPokemon_6
	goto EverGrandeCity_EventScript_PickSecondPokemon_5


EverGrandeCity_EventScript_DebugNPC::
# 97 "data//maps/EverGrandeCity/scripts.pory"
	lockall
# 98 "data//maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_TEST_PICK_POKEMON_EVER_GRANDE_CITY, EverGrandeCity_EventScript_DebugNPC_2
# 98 "data//maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_TEST_PICK_SECOND_POKEMON_EVER_GRANDE_CITY, EverGrandeCity_EventScript_DebugNPC_2
# 102 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_DebugNPC_Text_1
EverGrandeCity_EventScript_DebugNPC_1:
# 105 "data//maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_TEST_RIVAL_NOT_APPEARS_EVER_GRANDE_CITY, EverGrandeCity_EventScript_DebugNPC_8
# 109 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_DebugNPC_Text_3
EverGrandeCity_EventScript_DebugNPC_7:
# 111 "data//maps/EverGrandeCity/scripts.pory"
	releaseall
	end

EverGrandeCity_EventScript_DebugNPC_2:
# 99 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_DebugNPC_Text_0
	goto EverGrandeCity_EventScript_DebugNPC_1

EverGrandeCity_EventScript_DebugNPC_8:
# 106 "data//maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_DebugNPC_Text_2
	goto EverGrandeCity_EventScript_DebugNPC_7


EverGrandeCity_EventScript_SetupBattleOne::
# 116 "data//maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_TEST_PICK_POKEMON_EVER_GRANDE_CITY, EverGrandeCity_EventScript_SetupBattleOne_4
EverGrandeCity_EventScript_SetupBattleOne_3:
# 120 "data//maps/EverGrandeCity/scripts.pory"
	clearflag FLAG_TEST_RIVAL_NOT_APPEARS_EVER_GRANDE_CITY
EverGrandeCity_EventScript_SetupBattleOne_1:
	end

EverGrandeCity_EventScript_SetupBattleOne_2:
# 117 "data//maps/EverGrandeCity/scripts.pory"
	setflag FLAG_TEST_RIVAL_NOT_APPEARS_EVER_GRANDE_CITY
	goto EverGrandeCity_EventScript_SetupBattleOne_1

EverGrandeCity_EventScript_SetupBattleOne_4:
# 116 "data//maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_TEST_PICK_SECOND_POKEMON_EVER_GRANDE_CITY, EverGrandeCity_EventScript_SetupBattleOne_2
	goto EverGrandeCity_EventScript_SetupBattleOne_3


EverGrandeCity_EventScript_PokemonBattleOne::
# 126 "data//maps/EverGrandeCity/scripts.pory"
	trainerbattle_single TRAINER_MAY_RUSTBORO_TREECKO, Rival_IntroText, Rival_DefeatText
# 127 "data//maps/EverGrandeCity/scripts.pory"
	msgbox Rival_PostBattleText, MSGBOX_AUTOCLOSE
# 128 "data//maps/EverGrandeCity/scripts.pory"
	waitmessage
	end


EverGrandeCity_EventScript_PickPokemon_Text_0:
# 43 "data//maps/EverGrandeCity/scripts.pory"
	.string "Do you want to pick up this Pokemon?$"

EverGrandeCity_EventScript_PickPokemon_Text_1:
# 48 "data//maps/EverGrandeCity/scripts.pory"
	.string "You don't have enough space in your party.$"

EverGrandeCity_EventScript_PickPokemon_Text_2:
# 55 "data//maps/EverGrandeCity/scripts.pory"
	.string "You picked up the Pokemon.$"

EverGrandeCity_EventScript_PickPokemon_Text_3:
# 60 "data//maps/EverGrandeCity/scripts.pory"
	.string "You leave the Pokemon alone.$"

EverGrandeCity_EventScript_DebugNPC_Text_0:
# 99 "data//maps/EverGrandeCity/scripts.pory"
	.string "Pokemon was picked up$"

EverGrandeCity_EventScript_DebugNPC_Text_1:
# 102 "data//maps/EverGrandeCity/scripts.pory"
	.string "Pokemon was NOT picked up$"

EverGrandeCity_EventScript_DebugNPC_Text_2:
# 106 "data//maps/EverGrandeCity/scripts.pory"
	.string "Rival will NOT appear$"

EverGrandeCity_EventScript_DebugNPC_Text_3:
# 109 "data//maps/EverGrandeCity/scripts.pory"
	.string "Rival WILL appear$"

Rival_IntroText::
# 132 "data//maps/EverGrandeCity/scripts.pory"
	.string "Hello, I'm Rival!$"

Rival_DefeatText::
# 135 "data//maps/EverGrandeCity/scripts.pory"
	.string "I lost!$"

Rival_PostBattleText::
# 138 "data//maps/EverGrandeCity/scripts.pory"
	.string "Good game!$"
