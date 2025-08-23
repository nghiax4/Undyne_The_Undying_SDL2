#include "Arrow_For_Green_Attack.h"
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_0_Manager : public Attack_Manager_Base_Class {
    static const int MILLISECONDS_LENGTH = 9000;

    Attack_0_Manager();

    virtual void update() override;
    virtual void render() override;
    virtual void ready_to_be_removed() override;
};