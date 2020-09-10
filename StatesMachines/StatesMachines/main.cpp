#include "StateMachine.h"

int main()
{

	GameState* gs = new GameState();
	State* atHomeState = new State("At Home");
	State* makeFoodHomeState = new State("Making food");
	State* goToKebabState = new State("Go to Kebab");



	Transition transHome(atHomeState, [gs]() {
		if (gs->isOutside)
			return true;
		return false;
	});

	Transition transMakeFood(makeFoodHomeState, [gs]() {
		if (gs->isDay && gs->isHungry && gs->hasFood && !gs->isOutside)
			return true;
		return false;
	});

	Transition transKebab(goToKebabState, [gs]() {
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

}






