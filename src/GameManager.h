#pragma once
#include "Attack_Manager_Base_Class.h"
#include "GameObject.h"

struct GameManager : public GameObject {
  public:
    GameManager();
    virtual void update() override;
    virtual void render() override;

  private:
    virtual void play_attack(int attack_idx);
    Attack_Manager_Base_Class *find_attack_manager();
};