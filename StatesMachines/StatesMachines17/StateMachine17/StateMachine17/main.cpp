// StateMachine17.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "StateMachine.h"


int main()
{
	//	Création du gameState avec les variables suivante : isDay, isHungry, isOutside, hasFood
	GameState* gs = new GameState(false, true, false, true);

	//Creation des différentes state de la StateMachine
	State* atHomeState = new State("At Home");
	State* makeFoodHomeState = new State("Making food");
	State* goToKebabState = new State("Go to Kebab");
	State* goToSleep = new State("Going to sleep");


	//Création des transitions qui seront plus tard associés aux state
	Transition transHome([gs]() {
		if (gs->isOutside && !gs->isDay)
			return true;
		return false;
	});

	Transition transHomeFromSleep([gs]() {
		if (gs->isDay && !gs->isOutside)
			return true;
		return false;
	});

	Transition transMakeFood([gs]() {
		if (!gs->isDay && gs->isHungry && gs->hasFood && !gs->isOutside)
		{
			gs->isHungry = false;
			gs->hasFood = false;
			return true;
		}
			
		return false;
	});

	Transition transKebab([gs]() {
		if (gs->isDay && gs->isHungry && !gs->hasFood && !gs->isOutside)
		{
			gs->isOutside = true;
			gs->isHungry = false;
			gs->isDay = false;
			return true;
		}
		return false;
	});

	Transition transSleep([gs]() {
		if (!gs->isDay && !gs->isHungry && !gs->isOutside)
		{
			gs->isDay = true;
			gs->isHungry = true;
			return true;
		}
		return false;
	});


	//Association des transitions et des State entre elles
	atHomeState->AddTransitions(transKebab);
	atHomeState->AddOutState(goToKebabState);
	atHomeState->AddTransitions(transSleep);
	atHomeState->AddOutState(goToSleep);
	atHomeState->AddTransitions(transMakeFood);
	atHomeState->AddOutState(makeFoodHomeState);

	makeFoodHomeState->AddTransitions(transSleep);
	makeFoodHomeState->AddOutState(goToSleep);
	
	goToKebabState->AddTransitions(transHome);
	goToKebabState->AddOutState(atHomeState);

	goToSleep->AddTransitions(transHomeFromSleep);
	goToSleep->AddOutState(atHomeState);

	//Creation de la stateMachine
	StateMachine stateMachine(atHomeState, gs);

	//Ajout des states à la StateMachine
	stateMachine.AddStates(goToKebabState);
	stateMachine.AddStates(makeFoodHomeState);
	stateMachine.mainLoop();

	//Destruction des pointeurs
	delete gs;
	delete atHomeState;
	delete makeFoodHomeState;
	delete goToKebabState;


	return 0;
}






