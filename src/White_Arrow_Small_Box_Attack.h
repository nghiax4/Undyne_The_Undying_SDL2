#include "GameObject.h"
#include "Globals.h"

struct White_Arrow_Small_Box_Attack : public GameObject {
    const double SPRITE_WIDTH_TO_HEIGHT = 60.0 / 196;
    const double GETTING_READY_V_Y = SCREEN_HEIGHT * 0.00015;
    const double CHARGE_V_Y = SCREEN_HEIGHT * 0.0008;

    bool played_ready_sound = false;
    bool played_charge_sound = false;

    enum class State { GettingReady, Freeze, Charge };
    State state = State::GettingReady;
    double x_center, y_center;
    int width, height;
    int time_elapsed_since_state_change = 0;
    SDL_Texture *texture;

    White_Arrow_Small_Box_Attack(double x_center, double y_center, std::string obj_name);

    virtual void update() override;
    virtual void render() override;
};