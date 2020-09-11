// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>

#include "GoapSolver.h"
#include "Actions.h"

int main()
{
	World* ws = new World(0, 0, 0, 5, 0, 0, 0);

	//======================

	Precondition* haveFreeWorkersBuilding = new Precondition([ws](){return ws->getFreeWorkers() >= 5 ? true : false;});
	Precondition* haveGolds = new Precondition([ws]() {return ws->getGolds() >= 10 ? true : false; });
	Precondition* haveRocks = new Precondition([ws]() {return ws->getRocks() >= 10 ? true : false; });
	Precondition* haveWoods = new Precondition([ws]() {return ws->getWood() >= 10 ? true : false; });

	Precondition* haveFreeWorkers = new Precondition([ws]() {return ws->getFreeWorkers() >= 1 ? true : false; });

	Actions* buildHouse = new Actions("Lets Make a house", [ws]()
		{
			return true;
		}, 1);
	
	buildHouse->addPreconditions(haveFreeWorkersBuilding);
	buildHouse->addPreconditions(haveGolds);
	buildHouse->addPreconditions(haveRocks);
	buildHouse->addPreconditions(haveWoods);

	//======================
	
	Precondition* haveFreeWorkersBabies = new Precondition([ws]() {return ws->getFreeWorkers() >= 2 ? true : false; });
	
	Actions* letsMakeSomeBabies = new Actions("Lets Make Some Babies", [ws]()
		{
			return true;
		}, 1);

	letsMakeSomeBabies->addPreconditions(haveFreeWorkersBabies);

	//======================

	Actions* assignWoodWorkers = new Actions("Assign worker to Wood", [ws]()
		{
			return true;
		}, 1);

	assignWoodWorkers->addPreconditions(haveFreeWorkers);


	
	
	Precondition* haveWoodWorkers = new Precondition([ws]() {return ws->getWoodWorkers() >= 2 ? true : false; });
	
	Actions* cropSomeWood = new Actions("Lets Crop Some Wood", [ws]()
		{
			return true;
		}, 1);

	cropSomeWood->addPreconditions(haveWoodWorkers);


	Actions* unassignWoodWorkers = new Actions("Unassign worker from Wood", [ws]()
		{
			return true;
		}, 1);

	unassignWoodWorkers->addPreconditions(haveWoodWorkers);

	//======================
	
	Actions* assignGoldWorkers = new Actions("Assign worker to Gold", [ws]()
		{
			return true;
		}, 1);

	assignGoldWorkers->addPreconditions(haveFreeWorkers);

	
	
	Precondition* haveGoldWorkers = new Precondition([ws]() {return ws->getGoldWorkers() >= 2 ? true : false; });

	Actions* mineSomeGold = new Actions("Lets Mine Some Gold", [ws]()
		{
			return true;
		}, 1);

	mineSomeGold->addPreconditions(haveGoldWorkers);


	Actions* unassignGoldWorkers = new Actions("Unassign worker from Gold", [ws]()
		{
			return true;
		}, 1);


	unassignGoldWorkers->addPreconditions(haveGoldWorkers);

	//======================

	Actions* assignRockWorkers = new Actions("Assign worker to Rock", [ws]()
		{
			return true;
		}, 1);
	
	assignRockWorkers->addPreconditions(haveFreeWorkers);

	

	Precondition* haveRockWorkers = new Precondition([ws]() {return ws->getRockWorkers() >= 2 ? true : false; });
	
	Actions* breakSomeRock = new Actions("Lets Break Some Rock", [ws]()
		{
			return true;
		}, 1);

	breakSomeRock->addPreconditions(haveRockWorkers);


	Actions* unassignRockWorkers = new Actions("Unassign worker from Rock", [ws]()
		{
			return true;
		}, 1);

	unassignRockWorkers->addPreconditions(haveRockWorkers);
	
	
	//======================

	
	
	return 0;
}

