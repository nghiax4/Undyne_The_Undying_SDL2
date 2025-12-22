#include "Attack_1_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include <AttackRegistry.h>

Attack_1_Manager::Attack_1_Manager() {
    obj_name = "Attack_Manager_1";
    MILLISECONDS_LENGTH = 5000;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT / 2;
    battlebox->width = SCREEN_WIDTH * 0.13;
    battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    Arrow_For_Green_Attack *arrow_1 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_1");
    Arrow_For_Green_Attack *arrow_2 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 1.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_2");

    Arrow_For_Green_Attack *arrow_3 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_3");
    Arrow_For_Green_Attack *arrow_4 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1.75, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_4");

    Arrow_For_Green_Attack *arrow_5 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 2.05, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_5");
    Arrow_For_Green_Attack *arrow_6 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 2.35, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_6");

    Arrow_For_Green_Attack *arrow_7 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 2.75, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_7");

    Arrow_For_Green_Attack *arrow_8 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_8");
    Arrow_For_Green_Attack *arrow_9 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3.15, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_9");

    Arrow_For_Green_Attack *arrow_10 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 3.45, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_10");
    Arrow_For_Green_Attack *arrow_11 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3.7, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_11");

    Arrow_For_Green_Attack *arrow_12 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 4, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_12");
    Arrow_For_Green_Attack *arrow_13 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 4.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_1_Arrow_For_Green_Attack_13");

    Arrow_For_Green_Attack *arrow_14 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 4.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_1_Arrow_For_Green_Attack_14");

    objs.push_back(arrow_1);
    objs.push_back(arrow_2);
    objs.push_back(arrow_3);
    objs.push_back(arrow_4);
    objs.push_back(arrow_5);
    objs.push_back(arrow_6);
    objs.push_back(arrow_7);
    objs.push_back(arrow_8);
    objs.push_back(arrow_9);
    objs.push_back(arrow_10);
    objs.push_back(arrow_11);
    objs.push_back(arrow_12);
    objs.push_back(arrow_13);
    objs.push_back(arrow_14);
}

void Attack_1_Manager::render() {}
void Attack_1_Manager::ready_to_be_removed() {
    _teardown_green_mode("Attack_1");
}

static AutoRegisterAttack<Attack_1_Manager> register_attack_1(1);
