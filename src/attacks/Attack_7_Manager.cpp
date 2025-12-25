#include "Attack_7_Manager.h"
#include "AttackRegistry.h"
#include <Player_EnemyTurn_Green.h>
#include <Shield.h>

Attack_7_Manager::Attack_7_Manager() : Attack_Manager_Base_Class(7) {
    // MILLISECONDS_LENGTH = 5000;

    // global_battlebox->x_center = SCREEN_WIDTH / 2;
    // global_battlebox->y_center = SCREEN_HEIGHT / 2;
    // global_battlebox->width = SCREEN_WIDTH * 0.13;
    // global_battlebox->height = SCREEN_WIDTH * 0.13;

    // Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    // Shield *shield = new Shield();
    // objs.push_back(player);
    // objs.push_back(shield);

    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 0.9))
}

static AutoRegisterAttack<Attack_7_Manager> register_attack_7(7);
