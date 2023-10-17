#include "Cat.h"
#include "World.h"
#include <stdexcept>

Point2D Cat::Move(World* world)
{
  int numSteps = 0;
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

  return exit;

}

vector<Point2D> Cat::GetNeighbors(Point2D point, World* world)//returns true if found exit
{
  vector<Point2D> neighbors;
  Point2D tile;
  for (int i = 0; i < 6; i++)
  {
    bool tileValid = true;
    switch (i)
    {
      case 0:
        tile = world->E(point);
        break;
      case 1:
        tile = world->NE(point);
        break;
      case 2:
        tile = world->NW(point);
        break;
      case 3:
        tile = world->W(point);
        break;
      case 4:
        tile = world->SW(point);
        break;
      case 5:
        tile = world->SE(point);
        break;
      default:
        break;
    }

    if (!world->isValidPosition(tile))//checks in bounds
    {
      tileValid = false;
    }

    if(world->getContent(tile))//checks if blocked
    {
      tileValid = false;
    }

    for (int j = 0; j < neighbors.size(); j++)//checks not in list already
    {
      if(neighbors[i] == tile)
      {
        tileValid = false;
      }
    }

    for (int j = 0; j < nextFrontier.size(); j++)//checks not in list already
    {
      if(nextFrontier[i] == tile)
      {
        tileValid = false;
      }
    }

    if(tileValid)//adds tile if valid is true
    {
      neighbors.push_back(tile);
    }

    if (world->catWinsOnSpace(tile))
    {
      exit = tile;
      return neighbors;
    }
  }
  return neighbors;
}

