#include "Cat.h"
#include "World.h"
#include <stdexcept>

Point2D Cat::Move(World* world)
{

  FindNearestExit(world->getCat(), world);



}

Point2D Cat::FindNearestExit(Point2D point, World* world)
{
  frontier.push_back(point);

  while(exit == Point2D(INT_MAX, INT_MAX))
  {
    for(Point2D p : frontier)
    {
      for (auto neighbor : GetNeighbors(p, world))
      {
        nextFrontier.push_back(neighbor);
      }
      visited.push_back(p);
    }
    frontier = nextFrontier;
    nextFrontier.clear();
  }

  return exit;
}

