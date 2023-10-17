#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <vector>

using namespace std;

class World;

class Agent {
public:
  explicit Agent() = default;
  ;
  virtual Point2D Move(World*) = 0;

protected:
  vector<Point2D> visited, nextFrontier, frontier;
  Point2D exit = Point2D(INT_MAX, INT_MAX);
  vector<Point2D> GetNeighbors(Point2D point, World* world);
  bool GetPointValidity(Point2D point, World* world);
};

#endif  // AGENT_H
