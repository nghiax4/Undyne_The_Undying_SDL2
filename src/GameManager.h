#include "GameObject.h"

struct GameManager : public GameObject {
  public:
    GameManager();
    virtual void update() override;
    virtual void render() override;

  private:
    virtual int get_milliseconds_of_attack(int attack_idx);
};