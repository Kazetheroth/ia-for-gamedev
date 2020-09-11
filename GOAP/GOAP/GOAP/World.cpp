#include "pch.h"
#include "World.h"


World::World()
{
}


World::World(int golds, int rocks, int wood, int freeWorkers, int goldWorkers, int rockWorkers, int woodWorkers)
{
	this->golds = golds;
	this->rocks = rocks;
	this->wood = wood;
	this->freeWorkers = freeWorkers;
	this->goldWorkers = goldWorkers;
	this->rockWorkers = rockWorkers;
	this->woodWorkers = woodWorkers;
}

World::~World()
{
}

int World::getGolds() const
{
	return golds;
}

void World::setGolds(int golds)
{
	this->golds = golds;
}

int World::getRocks() const
{
	return rocks;
}

void World::setRocks(int rocks)
{
	this->rocks = rocks;
}

int World::getWooden() const
{
	return wooden;
}

void World::setWooden(int wooden)
{
	this->wooden = wooden;
}

int World::getWorkers() const
{
	return workers;
}

void World::setWorkers(int workers)
{
	this->workers = workers;
}
