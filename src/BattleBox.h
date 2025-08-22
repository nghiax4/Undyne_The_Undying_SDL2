#pragma once
#include "GameObject.h"

struct BattleBox : public GameObject {
  public:
    int x_center, y_center, width, height;

    BattleBox(int x_center, int y_center, int width, int height);

    virtual void update() override;

    virtual void render() override;
};