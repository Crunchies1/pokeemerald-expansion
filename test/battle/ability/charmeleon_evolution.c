#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Charmeleon Evolution prevents KOs and triggers form change")
{
    GIVEN {
        PLAYER(SPECIES_CHARMELEON) { Ability(ABILITY_CHARMELEON_EVOLUTION); MaxHP(100); HP(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        HP_BAR(player, hp: 1);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_CHARMELEON_EVOLUTION);
        MESSAGE("Charmeleon evolved due to it's will to survive!");
        HP_BAR(player);
    }
}