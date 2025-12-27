#include "Attack_4_Manager.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"

// Attack 4 uses a square box based on 28% of Width.
// To satisfy Red_Mode_Manager (which wants height ratio), we calculate:
// target_height = SCREEN_WIDTH * 0.28
// ratio = target_height / SCREEN_HEIGHT
Attack_4_Manager::Attack_4_Manager() : Red_Mode_Manager(4, 8500, 0.63, 0.28, (SCREEN_WIDTH * 0.28) / SCREEN_HEIGHT) {}

void Attack_4_Manager::update() {
    Red_Mode_Manager::update();
    time_elapsed_since_last_arrow += deltaTime;

    if (time_elapsed_since_last_arrow <= 400)
        return;

    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));

    const double MIN_RADIUS = SCREEN_WIDTH * 0.2;
    const double MAX_RADIUS = SCREEN_WIDTH * 0.3;

    double random_radius = get_random(MIN_RADIUS, MAX_RADIUS);
    double angle = get_random(0, 360);

    double x_center = global_battlebox->x_center + random_radius * cos(angle * M_PI / 180);
    double y_center = global_battlebox->y_center + random_radius * sin(angle * M_PI / 180);

    White_Arrow_Medium_Box_Attack *arrow = new White_Arrow_Medium_Box_Attack(x_center, y_center, player->x_center, player->y_center, attack_prefix + "_White_Arrow_" + std::to_string(arrows_created));

    objs.push_back(arrow);
    arrows_created++;

    time_elapsed_since_last_arrow = 0;
}

void Attack_4_Manager::render() {}

static AutoRegisterAttack<Attack_4_Manager> register_attack_4(4);
