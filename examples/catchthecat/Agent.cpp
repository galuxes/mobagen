#include "Agent.h"
#include "World.h"


vector<Point2D> Agent::GetNeighbors(Point2D point, World* world)//returns list of neighbors stops early if finds exit
{
  vector<Point2D> neighbors = world->neighbors(point);
  Point2D tile;


  for (int i = 0; i < neighbors.size() - 1; i++)
  {
    bool tileValid = true;

    tile = neighbors[i];

    if (!GetPointValidity(point, world))//checks in bounds
    {
      tileValid = false;
    }

    if(!nextFrontier.empty()) {
      for (int j = 0; j < nextFrontier.size() - 1; j++)  // checks not in list already
      {
        if (nextFrontier[j] == tile)
        {
          tileValid = false;
        }
      }
    }

    if(!visited.empty()) {
      for (int j = 0; j < visited.size() - 1; j++)  // checks not in list already
      {
        if (visited[j] == tile)
        {
          tileValid = false;
        }
      }
    }

    if(!tileValid)//adds tile if valid is true
    {
      neighbors.erase(neighbors.begin()+i);
    }

    if (world->catWinsOnSpace(tile) && tileValid)
    {
      exit = tile;
      return neighbors;
    }
  }
  return neighbors;
}

bool Agent::GetPointValidity(Point2D tile, World* world)
{
  bool tileValid = true;

  if (!world->isValidPosition(tile))//checks in bounds
  {
    tileValid = false;
  }

  if(world->getContent(tile))//checks if blocked
  {
    tileValid = false;
  }

  if(world->getCat() == tile)//checks if cat
  {
    tileValid = false;
  }

  return tileValid;
}