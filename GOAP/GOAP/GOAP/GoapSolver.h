#pragma once
#include "Actions.h"

class GoapSolver
{
private:
	World copyWorldState;
	std::vector<Actions*>* actions;
	std::vector<Actions*> currentPath;
	Actions* currentTarget;
	Actions* finalTarget;
public:
	std::vector<Actions*> solveActionSteps(std::vector<Actions*>* possiblesActions);
	GoapSolver();
	GoapSolver(Actions* finalTarget, World worldState);
	~GoapSolver();
};

