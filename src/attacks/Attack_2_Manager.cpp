#include "Attack_2_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include <AttackRegistry.h>

Attack_2_Manager::Attack_2_Manager() {
    obj_name = "Attack_Manager_2";
    MILLISECONDS_LENGTH = 11000;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT / 2;
    battlebox->width = SCREEN_WIDTH * 0.13;
    battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    Arrow_For_Green_Attack *arrow_1 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 0.2, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, "Attack_2_Arrow_For_Green_Attack_1");
    Arrow_For_Green_Attack *arrow_2 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.25, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_2");

    Arrow_For_Green_Attack *arrow_3 = new Arrow_For_Green_Attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, "Attack_2_Arrow_For_Green_Attack_3");
    Arrow_For_Green_Attack *arrow_4 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.4, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_4");

    Arrow_For_Green_Attack *arrow_5 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.5, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_5");
    Arrow_For_Green_Attack *arrow_6 = new Arrow_For_Green_Attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.6, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, "Attack_2_Arrow_For_Green_Attack_6");

    Arrow_For_Green_Attack *arrow_7 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 0.65, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, "Attack_2_Arrow_For_Green_Attack_7");
    Arrow_For_Green_Attack *arrow_8 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 0.68, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, "Attack_2_Arrow_For_Green_Attack_8");

    Arrow_For_Green_Attack *arrow_9 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 0.75, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, "Attack_2_Arrow_For_Green_Attack_9");
    Arrow_For_Green_Attack *arrow_10 = new Arrow_For_Green_Attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.8, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, "Attack_2_Arrow_For_Green_Attack_10");

    Arrow_For_Green_Attack *arrow_11 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.9, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_11");
    Arrow_For_Green_Attack *arrow_12 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_12");

    Arrow_For_Green_Attack *arrow_13 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 1.1, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, "Attack_2_Arrow_For_Green_Attack_13");

    Arrow_For_Green_Attack *arrow_14 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.2, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_14");
    Arrow_For_Green_Attack *arrow_15 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.23, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_2_Arrow_For_Green_Attack_15");

    Arrow_For_Green_Attack *arrow_16 = new Arrow_For_Green_Attack(SCREEN_WIDTH + SCREEN_WIDTH * 1.26, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, "Attack_2_Arrow_For_Green_Attack_16");
    Arrow_For_Green_Attack *arrow_17 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 1.29, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, "Attack_2_Arrow_For_Green_Attack_17");

    Arrow_For_Green_Attack *arrow_18 = new Arrow_For_Green_Attack(SCREEN_WIDTH + SCREEN_WIDTH * 1.32, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, "Attack_2_Arrow_For_Green_Attack_18");
    Arrow_For_Green_Attack *arrow_19 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 1.35, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, "Attack_2_Arrow_For_Green_Attack_19");

    objs.push_back(arrow_1);
    objs.push_back(arrow_2);
    objs.push_back(arrow_3);
    objs.push_back(arrow_4);
    objs.push_back(arrow_5);
    objs.push_back(arrow_6);
    objs.push_back(arrow_7);
    objs.push_back(arrow_9);
    objs.push_back(arrow_10);
    objs.push_back(arrow_11);
    objs.push_back(arrow_12);
    objs.push_back(arrow_13);
    objs.push_back(arrow_14);
    objs.push_back(arrow_15);
    objs.push_back(arrow_16);
    objs.push_back(arrow_17);
    objs.push_back(arrow_18);
    objs.push_back(arrow_19);
}

void Attack_2_Manager::render() {}

void Attack_2_Manager::ready_to_be_removed() {
    _teardown_green_mode("Attack_2");
}

static AutoRegisterAttack<Attack_2_Manager> register_attack_2(2);
