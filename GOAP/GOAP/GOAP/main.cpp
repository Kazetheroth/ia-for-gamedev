// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>

#include "GoapSolver.h"
#include "Actions.h"

void InitGOAP(World* ws)
{
	std::vector<Actions*> *fullActionList = new std::vector<Actions*>;
	
	//====================== INIT FINAL ACTION

	Precondition* haveFreeWorkersBuilding = new Precondition([ws]() {return ws->getFreeWorkers() >= 5 ? true : false; }, Condition::Build);
	Precondition* haveGolds = new Precondition([ws]() {return ws->getGolds() >= 10 ? true : false; }, Condition::Build);
	Precondition* haveRocks = new Precondition([ws]() {return ws->getRocks() >= 10 ? true : false; }, Condition::Build);
	Precondition* haveWoods = new Precondition([ws]() {return ws->getWood() >= 10 ? true : false; }, Condition::Build);

	Precondition* haveFreeWorkers = new Precondition([ws]() {return ws->getFreeWorkers() >= 1 ? true : false; }, Condition::Any);

	Actions* buildHouse = new Actions("Lets Make a house", new Effect([ws]()
		{
			return true;
		}, Condition::Build),
		1);

	buildHouse->addPreconditions(haveFreeWorkersBuilding);
	buildHouse->addPreconditions(haveGolds);
	buildHouse->addPreconditions(haveRocks);
	buildHouse->addPreconditions(haveWoods);
	fullActionList->push_back(buildHouse);

	//====================== INIT NEW FREEWORKER ACTION

	Precondition* haveFreeWorkersBabies = new Precondition([ws]() {return ws->getFreeWorkers() >= 2 ? true : false; }, Condition::FreeWorkers);

	Actions* letsMakeSomeBabies = new Actions("Lets Make Some Babies", new Effect([ws]()
		{
			return true;
		}, Condition::FreeWorkers),
		1);

	letsMakeSomeBabies->addPreconditions(haveFreeWorkersBabies);
	fullActionList->push_back(letsMakeSomeBabies);

	//====================== INIT WOOD WORKER ACTION

	Actions* assignWoodWorkers = new Actions("Assign worker to Wood", new Effect([ws]()
		{
			return true;
		}, Condition::WoodWorkers),
		1);

	assignWoodWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignWoodWorkers);


	Precondition* haveWoodWorkers = new Precondition([ws]() {return ws->getWoodWorkers() >= 2 ? true : false; }, Condition::Wood);

	Actions* cropSomeWood = new Actions("Lets Crop Some Wood", new Effect([ws]()
		{
			return true;
		}, Condition::Wood),
		1);

	cropSomeWood->addPreconditions(haveWoodWorkers);
	fullActionList->push_back(cropSomeWood);


	Actions* unassignWoodWorkers = new Actions("Unassign worker from Wood", new Effect([ws]()
		{
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignWoodWorkers->addPreconditions(haveWoodWorkers);
	fullActionList->push_back(unassignWoodWorkers);

<<<<<<< HEAD
	//======================
	
	Actions* assignGoldWorkers = new Actions("Assign worker to Gold", [ws]()
=======

	//====================== INIT GOLDWORKER ACTION

	Actions* assignGoldWorkers = new Actions("Assign worker to Gold", new Effect([ws]()
>>>>>>> 940e410286f7eb0d6af0f03f76410ae74d0b0269
		{
			return true;
		}, Condition::GoldWorkers),
		1);

	assignGoldWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignGoldWorkers);

	Precondition* haveGoldWorkers = new Precondition([ws]() {return ws->getGoldWorkers() >= 2 ? true : false; }, Condition::Gold);

	Actions* mineSomeGold = new Actions("Lets Mine Some Gold", new Effect([ws]()
		{
			return true;
		}, Condition::Gold),
		1);

	mineSomeGold->addPreconditions(haveGoldWorkers);
	fullActionList->push_back(mineSomeGold);


	Actions* unassignGoldWorkers = new Actions("Unassign worker from Gold", new Effect([ws]()
		{
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignGoldWorkers->addPreconditions(haveGoldWorkers);
	fullActionList->push_back(unassignGoldWorkers);
	 
	//====================== INIT ROCKWOKERS

	Actions* assignRockWorkers = new Actions("Assign worker to Rock", new Effect([ws]()
		{
			return true;
		}, Condition::RockWorkers),
		1);

	assignRockWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignRockWorkers);

	Precondition* haveRockWorkers = new Precondition([ws]() {return ws->getRockWorkers() >= 2 ? true : false; }, Condition::FreeWorkers);

	Actions* breakSomeRock = new Actions("Lets Break Some Rock", new Effect([ws]()
		{
			return true;
		}, Condition::Rock),
		1);

	breakSomeRock->addPreconditions(haveRockWorkers);
	fullActionList->push_back(breakSomeRock);


	Actions* unassignRockWorkers = new Actions("Unassign worker from Rock", new Effect([ws]()
		{
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignRockWorkers->addPreconditions(haveRockWorkers);
	fullActionList->push_back(unassignRockWorkers);


	//====================== STARTING GOAP

	GoapSolver* gs = new GoapSolver(buildHouse, *ws);
	gs->solveActionSteps(fullActionList);
}

int main()
{
	World* ws = new World(0, 0, 0, 5, 0, 0, 0);
	InitGOAP(ws);

	return 0;
}

