#include "Attack_5_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Attack_5_Manager::Attack_5_Manager() {
    obj_name = "Attack_Manager_5";
    MILLISECONDS_LENGTH = 6000;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT / 2;
    battlebox->width = SCREEN_WIDTH * 0.13;
    battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    Arrow_For_Green_Attack *arrow_1 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 0.2, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0007, 0, Direction::RIGHT, "Attack_5_Arrow_For_Green_Attack_1");
    Arrow_For_Green_Attack *arrow_2 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.2, 0, SCREEN_HEIGHT * 0.0004, Direction::DOWN, "Attack_5_Arrow_For_Green_Attack_2");

    Arrow_For_Green_Attack *arrow_3 = new Arrow_For_Green_Attack(SCREEN_WIDTH * 2, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0007, 0, Direction::LEFT, "Attack_5_Arrow_For_Green_Attack_3");
    Arrow_For_Green_Attack *arrow_4 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 1.5, 0, -SCREEN_HEIGHT * 0.0004, Direction::UP, "Attack_5_Arrow_For_Green_Attack_4");
    Arrow_For_Green_Attack *arrow_5 = new Arrow_For_Green_Attack(SCREEN_WIDTH * 2.5, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0007, 0, Direction::LEFT, "Attack_5_Arrow_For_Green_Attack_5");
    Arrow_For_Green_Attack *arrow_6 = new Arrow_For_Green_Attack(-SCREEN_WIDTH * 1, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0004, 0, Direction::RIGHT, "Attack_5_Arrow_For_Green_Attack_6");

    Arrow_For_Green_Attack *arrow_7 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.25, 0, SCREEN_HEIGHT * 0.0004, Direction::DOWN, "Attack_5_Arrow_For_Green_Attack_7");
    Arrow_For_Green_Attack *arrow_8 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 2.5, 0, -SCREEN_HEIGHT * 0.0004, Direction::UP, "Attack_5_Arrow_For_Green_Attack_8");

    objs.push_back(arrow_1);
    objs.push_back(arrow_2);
    objs.push_back(arrow_3);
    objs.push_back(arrow_4);
    objs.push_back(arrow_5);
    objs.push_back(arrow_6);
    objs.push_back(arrow_7);
    objs.push_back(arrow_8);
}

void Attack_5_Manager::render() {}

void Attack_5_Manager::ready_to_be_removed() {
    _teardown_green_mode("Attack_5");
}

static AutoRegisterAttack<Attack_5_Manager> register_attack_5(5);
