#include "GameObject.h"

struct GameManager : public GameObject {
  public:
    virtual void update() override;
    virtual void render() override;
};