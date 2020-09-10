// StateMachine17.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "StateMachine.h"


int main()
{

	GameState* gs = new GameState(true, true, false, false);
	State* atHomeState = new State("At Home");
	State* makeFoodHomeState = new State("Making food");
	State* goToKebabState = new State("Go to Kebab");



	Transition transHome([gs]() {
		if (gs->isOutside)
			return true;
		return false;
	});

	Transition transMakeFood([gs]() {
		if (gs->isDay && gs->isHungry && gs->hasFood && !gs->isOutside)
			return true;
		return false;
	});

	Transition transKebab([gs]() {
		if (gs->isDay && gs->isHungry && !gs->hasFood)
			return true;
		return false;
	});

	atHomeState->AddTransitions(transKebab);
	atHomeState->AddTransitions(transMakeFood);

	goToKebabState->AddTransitions(transHome);

	StateMachine stateMachine(atHomeState, gs);
	stateMachine.AddStates(goToKebabState);
	stateMachine.AddStates(makeFoodHomeState);
	stateMachine.mainLoop();
}






