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
    /* Précondition have 5 Workers */
	Precondition* haveFreeWorkersBuilding = new Precondition([ws]() {return ws->getFreeWorkers() >= 5 ? true : false; }, Condition::Build);
	Precondition* haveGolds = new Precondition([ws]() {return ws->getGolds() >= 10 ? true : false; }, Condition::Build);
	Precondition* haveRocks = new Precondition([ws]() {return ws->getRocks() >= 10 ? true : false; }, Condition::Build);
	Precondition* haveWoods = new Precondition([ws]() {return ws->getWood() >= 10 ? true : false; }, Condition::Build);

	Precondition* haveFreeWorkers = new Precondition([ws]() {return ws->getFreeWorkers() >= 1 ? true : false; }, Condition::FreeWorkers);

	Actions* buildHouse = new Actions("Lets Make a house", new Effect([ws]()
		{
            ws->setFreeWorkers(ws->getFreeWorkers() - 5);
            ws->setGolds(ws->getGolds() - 10);
            ws->setRocks(ws->getRocks() - 10);
            ws->setWood(ws->getWood() - 10);
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
			ws->setFreeWorkers(ws->getFreeWorkers() + 1);
            return true;
		}, Condition::FreeWorkers),
		1);

	letsMakeSomeBabies->addPreconditions(haveFreeWorkersBabies);
	fullActionList->push_back(letsMakeSomeBabies);

	//====================== INIT WOOD WORKER ACTION

	Actions* assignWoodWorkers = new Actions("Assign worker to Wood", new Effect([ws]()
		{
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
            ws->setWoodWorkers(ws->getWoodWorkers() + 1);
			return true;
		}, Condition::WoodWorkers),
		1);

	assignWoodWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignWoodWorkers);


	Precondition* haveWoodWorkers = new Precondition([ws]() {return ws->getWoodWorkers() >= 1 ? true : false; }, Condition::WoodWorkers);

	Actions* cropSomeWood = new Actions("Lets Crop Some Wood", new Effect([ws]()
		{
            ws->setWood(ws->getWood() + 1);
			return true;
		}, Condition::Wood),
		1);

	cropSomeWood->addPreconditions(haveWoodWorkers);
	fullActionList->push_back(cropSomeWood);


	Actions* unassignWoodWorkers = new Actions("Unassign worker from Wood", new Effect([ws]()
		{
            ws->setWoodWorkers(ws->getWoodWorkers() - 1);
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignWoodWorkers->addPreconditions(haveWoodWorkers);
	fullActionList->push_back(unassignWoodWorkers);


	//====================== INIT GOLDWORKER ACTION

	Actions* assignGoldWorkers = new Actions("Assign worker to Gold", new Effect([ws]()
		{
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
            ws->setGoldWorkers(ws->getGoldWorkers() + 1);
			return true;
		}, Condition::GoldWorkers),
		1);

	assignGoldWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignGoldWorkers);

	Precondition* haveGoldWorkers = new Precondition([ws]() {return ws->getGoldWorkers() >= 1 ? true : false; }, Condition::GoldWorkers);

	Actions* mineSomeGold = new Actions("Lets Mine Some Gold", new Effect([ws]()
		{
            ws->setGolds(ws->getGolds() + 1);
			return true;
		}, Condition::Gold),
		1);

	mineSomeGold->addPreconditions(haveGoldWorkers);
	fullActionList->push_back(mineSomeGold);


	Actions* unassignGoldWorkers = new Actions("Unassign worker from Gold", new Effect([ws]()
		{
            ws->setGoldWorkers(ws->getGoldWorkers() - 1);
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignGoldWorkers->addPreconditions(haveGoldWorkers);
	fullActionList->push_back(unassignGoldWorkers);
	 
	//====================== INIT ROCKWOKERS

	Actions* assignRockWorkers = new Actions("Assign worker to Rock", new Effect([ws]()
		{
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
            ws->setRockWorkers(ws->getRockWorkers() + 1);
			return true;
		}, Condition::RockWorkers),
		1);

	assignRockWorkers->addPreconditions(haveFreeWorkers);
	fullActionList->push_back(assignRockWorkers);

	Precondition* haveRockWorkers = new Precondition([ws]() {return ws->getRockWorkers() >= 1 ? true : false; }, Condition::RockWorkers);

	Actions* breakSomeRock = new Actions("Lets Break Some Rock", new Effect([ws]()
		{
            ws->setRocks(ws->getRocks() + 1);
			return true;
		}, Condition::Rock),
		1);

	breakSomeRock->addPreconditions(haveRockWorkers);
	fullActionList->push_back(breakSomeRock);


	Actions* unassignRockWorkers = new Actions("Unassign worker from Rock", new Effect([ws]()
		{
            ws->setRockWorkers(ws->getRockWorkers() - 1);
            ws->setFreeWorkers(ws->getFreeWorkers() - 1);
			return true;
		}, Condition::FreeWorkers),
		1);

	unassignRockWorkers->addPreconditions(haveRockWorkers);
	fullActionList->push_back(unassignRockWorkers);


	//====================== STARTING GOAP

	GoapSolver* gs = new GoapSolver(buildHouse, *ws);
	gs->solveActionSteps(fullActionList, gs->getFinalTarget());

    //====================== Free/delete actions
    for (int i = 0; i < fullActionList[0].size(); ++i) {
        delete fullActionList[0][i];
    }
    delete fullActionList;
}

int main()
{
	World* ws = new World(0, 0, 0, 10, 0, 0, 0);
	InitGOAP(ws);

	return 0;
}

