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

int World::getWood() const
{
	return wood;
}

void World::setWood(int wooden)
{
	this->wood = wooden;
}

int World::getFreeWorkers() const
{
	return freeWorkers;
}

void World::setFreeWorkers(int workers)
{
	this->freeWorkers = workers;
}

int World::getGoldWorkers() const
{
	return goldWorkers;
}

void World::setGoldWorkers(const int gold_workers)
{
	goldWorkers = gold_workers;
}

int World::getRockWorkers() const
{
	return rockWorkers;
}

void World::setRockWorkers(const int rock_workers)
{
	rockWorkers = rock_workers;
}

int World::getWoodWorkers() const
{
	return woodWorkers;
}

void World::setWoodWorkers(const int wood_workers)
{
	woodWorkers = wood_workers;
}