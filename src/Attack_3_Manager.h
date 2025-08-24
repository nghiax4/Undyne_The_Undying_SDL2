#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_3_Manager : public Attack_Manager_Base_Class {
    Attack_3_Manager();

    virtual void update() override;
    virtual void render() override;
    virtual void ready_to_be_removed() override;
};
