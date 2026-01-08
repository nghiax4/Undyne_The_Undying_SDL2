#pragma once
#include "GameObject.h"
#include "core/Components.h"

struct BattleBox : public GameObject {
  public:
    BattleBox(int x_center, int y_center, int width, int height);
    virtual void update() override;
    virtual void render() override;
};
