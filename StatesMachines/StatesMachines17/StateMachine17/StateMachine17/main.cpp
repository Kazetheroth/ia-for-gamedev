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


	//Création des transitions qui seront plus tard associés aux state
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


	//Association des transitions et des State entre elles
	atHomeState->AddTransitions(transKebab);
	atHomeState->AddOutState(goToKebabState);
	atHomeState->AddTransitions(transMakeFood);
	atHomeState->AddOutState(makeFoodHomeState);
	
	goToKebabState->AddTransitions(transHome);
	goToKebabState->AddOutState(atHomeState);

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






