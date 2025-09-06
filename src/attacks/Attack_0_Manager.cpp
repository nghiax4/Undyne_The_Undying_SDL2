#include "Attack_0_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Attack_0_Manager::Attack_0_Manager() {
    obj_name = "Attack_Manager_0";
    MILLISECONDS_LENGTH = 10000;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT / 2;
    battlebox->width = SCREEN_WIDTH * 0.13;
    battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    Arrow_For_Green_Attack *arrow_1 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.7, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_1");
    Arrow_For_Green_Attack *arrow_2 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.85, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_2");
    Arrow_For_Green_Attack *arrow_3 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 1, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_3");

    Arrow_For_Green_Attack *arrow_4 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 5, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_0_Arrow_For_Green_Attack_4");
    Arrow_For_Green_Attack *arrow_5 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 5.4, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, "Attack_0_Arrow_For_Green_Attack_5");
    Arrow_For_Green_Attack *arrow_6 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 5.8, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_0_Arrow_For_Green_Attack_6");

    Arrow_For_Green_Attack *arrow_7 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 6.2, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_7");
    Arrow_For_Green_Attack *arrow_8 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 6.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_0_Arrow_For_Green_Attack_8");
    Arrow_For_Green_Attack *arrow_9 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 7, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, "Attack_0_Arrow_For_Green_Attack_9");

    Arrow_For_Green_Attack *arrow_10 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 7.4, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_0_Arrow_For_Green_Attack_10");
    Arrow_For_Green_Attack *arrow_11 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 7.8, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, "Attack_0_Arrow_For_Green_Attack_11");
    Arrow_For_Green_Attack *arrow_12 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 8.2, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_0_Arrow_For_Green_Attack_12");

    Arrow_For_Green_Attack *arrow_13 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 8.6, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_13");

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
}

void Attack_0_Manager::update() { time_elapsed_since_creation += deltaTime; }

void Attack_0_Manager::render() {}

void Attack_0_Manager::ready_to_be_removed() {
    this->to_be_removed = true;
    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));
    Shield *shield = static_cast<Shield *>(find_object_by_name("Shield"));
    player->to_be_removed = true;
    shield->to_be_removed = true;

    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_0") == 0) {
            obj->to_be_removed = true;
        }
    }
}