#pragma once
#include "GameObject.h"
#include "Globals.h"

struct Arrow_For_Green_Attack;

struct Attack_Manager_Base_Class : public GameObject {
    int MILLISECONDS_LENGTH;
    int time_elapsed_since_creation = 0;
    int attack_id;
    std::string attack_prefix;

    Attack_Manager_Base_Class(int _attack_id);

    virtual void update() override;
    virtual void ready_to_be_removed();
    virtual void render() override {}

    void _teardown_green_mode();

    virtual ~Attack_Manager_Base_Class() = default;

  protected:
    Arrow_For_Green_Attack *create_arrow_for_green_attack(double x, double y, double v_x, double v_y, Direction direction, int arrow_number, ArrowType type);
    Arrow_For_Green_Attack *create_arrow_for_green_attack_with_impact_time(Direction direction, double speed, int time_to_impact_ms, int arrow_number, ArrowType type);
};
