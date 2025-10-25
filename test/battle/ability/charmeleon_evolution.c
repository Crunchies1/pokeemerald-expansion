#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Charmeleon Evolution prevents KOs and triggers form change")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(100); MaxHP(100); HP(1); };
        OPPONENT(SPECIES_CHARMELEON) { Ability(ABILITY_CHARMELEON_EVOLUTION); MaxHP(100); HP(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent, hp: 1);
        ABILITY_POPUP(opponent, ABILITY_CHARMELEON_EVOLUTION);
        HP_BAR(opponent);
        HP_BAR(player, hp: 0);
    }
}