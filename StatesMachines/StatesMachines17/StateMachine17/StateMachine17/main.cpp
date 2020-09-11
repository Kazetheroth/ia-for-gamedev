// StateMachine17.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "StateMachine.h"


int main()
{
	GameState* gs = new GameState(false, true, false, true);
	State* atHomeState = new State("At Home");
	State* makeFoodHomeState = new State("Making food");
	State* goToKebabState = new State("Go to Kebab");

	Transition transHome([gs]() {
		if (gs->isOutside)
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
			return true;
		return false;
	});

	atHomeState->AddTransitions(transKebab);
	atHomeState->AddOutState(goToKebabState);
	atHomeState->AddTransitions(transMakeFood);
	atHomeState->AddOutState(makeFoodHomeState);
	
	goToKebabState->AddTransitions(transHome);
	goToKebabState->AddOutState(atHomeState);

	StateMachine stateMachine(atHomeState, gs);
	stateMachine.AddStates(goToKebabState);
	stateMachine.AddStates(makeFoodHomeState);
	stateMachine.mainLoop();

	delete gs;
	delete atHomeState;
	delete makeFoodHomeState;
	delete goToKebabState;


	return 0;
}






