#pragma once
#include "Actions.h"

class GoapSolver
{
private:
	World copyWorldState;
	std::vector<Actions*>* actions;
	std::vector<Actions*> currentPath;
	Actions* finalTarget;
public:
	std::vector<Actions*> solveActionSteps(std::vector<Actions*>* possiblesActions, Actions* currentTarget);
    Actions *getFinalTarget() const;
    void setFinalTarget(Actions *finalTarget);
    GoapSolver();
	GoapSolver(Actions* finalTarget, World worldState);
	~GoapSolver();
};

