#ifndef CAT_H
#define CAT_H

#include "Agent.h"
using namespace std;

class Cat : public Agent {
public:
  explicit Cat() : Agent(){};
  Point2D Move(World*) override;
  Point2D FindNearestExit(Point2D point, World* world);
};

#endif  // CAT_H
