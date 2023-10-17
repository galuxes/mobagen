#include "Cat.h"
#include "World.h"
#include <stdexcept>

Point2D Cat::Move(World* world)
{

  /*auto neighbors = GetNeighbors(world->getCat(), world);

  if(neighbors.back() == exit)
  {
    return exit;
  }else{
    auto ranNum = Random::Range(0,neighbors.size()-1);
    return neighbors[ranNum];
  }*/

  return FindNearestExit(world->getCat(), world);

  /*int numSteps = 0;
  bool exitFound = false;

  frontier.push_back(world->getCat());

  while (!exitFound)
  {
    for (int i = 0; i < frontier.size(); i++)
    {
      vector<Point2D> neighbors = GetNeighbors(frontier[i], world);

      for (int j = 0; j < neighbors.size(); j++)
      {
        nextFrontier.push_back(neighbors[j]);
      }

      tilesInRadius.push_back(frontier[i]);

      if(world->catWinsOnSpace(neighbors.back()))
      {
        exitFound = true;
        break;
      }
    }
    numSteps++;
    frontier = nextFrontier;
    nextFrontier.clear();
  }

  vector<Point2D> open, closed;

  return exit;*/

}

Point2D Cat::FindNearestExit(Point2D point, World* world)
{
  frontier.push_back(point);

  while(exit == Point2D(INT_MAX, INT_MAX))
  {

    for(Point2D p : frontier)
    {

      auto neighbors = GetNeighbors(p, world);

      for (Point2D n : neighbors)
      {
        nextFrontier.push_back(n);
      }

      visited.push_back(p);
    }
    frontier = nextFrontier;
    nextFrontier.clear();

  }

  return exit;
}

