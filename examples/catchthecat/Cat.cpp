#include "Cat.h"
#include "World.h"
#include <stdexcept>

Point2D Cat::Move(World* world)
{

  FindNearestExit(world->getCat(), world);



}

int Cat::FindNearestExit(Point2D point, World* world)
{
  frontier.push_back(point);
  int heuristic = 0;

  while(exit == Point2D(INT_MAX, INT_MAX))
  {
    for(auto fPoint : frontier)
    {
      for (auto neighbor : GetNeighbors(fPoint, world))
      {
        nextFrontier.push_back(neighbor);
      }
      visited.push_back(fPoint);
      distances.push_back(heuristic);
    }
    heuristic++;
    frontier = nextFrontier;
    nextFrontier.clear();
  }

  return heuristic;
}

void Cat::Cleanup()
{
  visited.clear();
  nextFrontier.clear();
  frontier.clear();
  exit = Point2D(INT_MAX, INT_MAX);
}