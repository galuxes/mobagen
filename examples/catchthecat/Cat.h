#ifndef CAT_H
#define CAT_H

#include "Agent.h"
using namespace std;

class Cat : public Agent {
public:
  explicit Cat() : Agent(){};
  Point2D Move(World*) override;
private:
  vector<int> distances;
  int FindNearestExit(Point2D point, World* world);
  void Cleanup();
};

#endif  // CAT_H
