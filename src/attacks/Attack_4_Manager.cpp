#include "Attack_4_Manager.h"
#include "Attack_Manager_Base_Class.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "AttackRegistry.h"

Attack_4_Manager::Attack_4_Manager() {
    obj_name = "Attack_Manager_4";
    MILLISECONDS_LENGTH = 8500;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT * 0.63;
    battlebox->width = SCREEN_WIDTH * 0.28;
    battlebox->height = battlebox->width;

    Player_EnemyTurn *player = new Player_EnemyTurn(battlebox->x_center, battlebox->y_center);

    objs.push_back(player);
}

void Attack_4_Manager::update() {
    time_elapsed_since_creation += deltaTime;
    time_elapsed_since_last_arrow += deltaTime;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));

    const double MIN_RADIUS = SCREEN_WIDTH * 0.2;
    const double MAX_RADIUS = SCREEN_WIDTH * 0.3;

    if (time_elapsed_since_last_arrow <= 400)
        return;

    double random_radius = get_random(MIN_RADIUS, MAX_RADIUS);
    double angle = get_random(0, 360);

    double x_center = battlebox->x_center + random_radius * cos(angle * M_PI / 180);
    double y_center = battlebox->y_center + random_radius * sin(angle * M_PI / 180);

    White_Arrow_Medium_Box_Attack *arrow = new White_Arrow_Medium_Box_Attack(x_center, y_center, player->x_center, player->y_center, "Attack_4_White_Arrow_" + std::to_string(arrows_created));

    objs.push_back(arrow);
    arrows_created++;

    time_elapsed_since_last_arrow = 0;
}
void Attack_4_Manager::render() {}
void Attack_4_Manager::ready_to_be_removed() {
    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));
    player->to_be_removed = true;
    this->to_be_removed = true;

    for (auto &obj : objs) {
        if (dynamic_cast<White_Arrow_Medium_Box_Attack *>(obj) != nullptr) {
            obj->to_be_removed = true;
        }
    }
}

static AutoRegisterAttack<Attack_4_Manager> register_attack_4(4);
