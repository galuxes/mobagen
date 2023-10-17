#ifndef CAT_H
#define CAT_H

#include <vector>
#include "Agent.h"
using namespace std;

class Cat : public Agent {
public:
  explicit Cat() : Agent(){};
  Point2D Move(World*) override;
private:
  vector<Point2D> GetNeighbors(Point2D point,World* world);

  vector<Point2D> tilesInRadius, nextFrontier, frontier;
  Point2D exit;
};

#endif  // CAT_H
