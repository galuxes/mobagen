#include "Agent.h"
#include "World.h"


vector<Point2D> Agent::GetNeighbors(Point2D point, World* world)//returns list of neighbors stops early if finds exit
{
  vector<Point2D> neighbors = world->neighbors(point);
  vector<Point2D> validNeighbors;

  for (auto tile : neighbors)
  {

    bool tileValid = true;

    for (auto nTile : nextFrontier)  // checks not in list already
    {
      if (nTile == tile)
      {
        tileValid = false;
      }
    }

    for (auto fTile : frontier)  // checks not in list already
    {
      if (fTile == tile)
      {
        tileValid = false;
      }
    }

    for (auto vTile : visited)  // checks not in list already
    {
      if (vTile == tile)
      {
        tileValid = false;
      }
    }

    if(tileValid)//adds tile if valid is true
    {
      validNeighbors.push_back(tile);
    }

    if (world->catWinsOnSpace(tile) && tileValid)
    {
      exit = tile;
      return neighbors;
    }
  }
  return validNeighbors;
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