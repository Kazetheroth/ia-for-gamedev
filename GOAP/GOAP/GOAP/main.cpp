// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>

#include "GoapSolver.h"
#include "Actions.h"

int main()
{
	World* ws = new World(50, 50, 50, 50);
	Actions* letMakeSomeBabies = new Actions("Lets Make Some Babies", []()
	{
			return true;
	}, 1);
	Actions* cropSomeWood = new Actions("Lets Crop Some Wood", []()
		{
			return true;
		}, 1);
	Actions* mineSomeGold = new Actions("Lets Mine Some Gold", []()
		{
			return true;
		}, 1);
	Actions* breakSomeRock = new Actions("Lets Break Some Rock", []()
		{
			return true;
		}, 1);
	return 0;
}

