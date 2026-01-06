#pragma once
#include "GameObject.h"

struct BattleBox : public GameObject {
  public:
    double m_x_center, m_y_center, m_width, m_height;

    BattleBox(int x_center, int y_center, int width, int height);

    virtual void update() override;

    virtual void render() override;
};
