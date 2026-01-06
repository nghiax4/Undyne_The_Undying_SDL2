#pragma once
#include "Attack_Manager_Base_Class.h"
#include "GameObject.h"
#include "Turn.h"

struct GameManager : public GameObject {
  public:
    GameManager();

    Turn m_current_turn = Turn::PlayerTurn;
    int m_current_attack_idx = 0;

    void update() override;
    void render() override;

  private:
    void play_attack(int attack_idx);
    Attack_Manager_Base_Class *find_attack_manager();
};
