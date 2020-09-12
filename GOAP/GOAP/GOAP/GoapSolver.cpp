#include "pch.h"
#include "GoapSolver.h"
#include <iostream>


std::vector<Actions*> GoapSolver::solveActionSteps(std::vector<Actions*>* disponiblesActions, Actions* currentTarget)
{
	std::vector<Precondition*> targetPrecondition = currentTarget->getPreconditions();
	size_t targetPreconditionSize = targetPrecondition.size();

    for (int i = 0; i < targetPreconditionSize; i++)
    {
        std::cout << "Condition " << i << " : " << targetPrecondition[i]->getVerifyCondition()() << std::endl;
        if (!targetPrecondition[i]->getVerifyCondition()()){
            for (Actions* actions : disponiblesActions[0])
            {
                if (actions->getEffect()->getConditionEnum() == targetPrecondition[i]->getResponseCondition()){
                    this->currentPath.push_back(actions);
                    return solveActionSteps(disponiblesActions, actions);
                }
            }
        }
    }


	//free(lastCondition);
	return this->currentPath;
}

GoapSolver::GoapSolver()
{
	
}

GoapSolver::GoapSolver(Actions* finalTarget, World worldState)
{
	this->finalTarget = finalTarget;
	this->copyWorldState = worldState;
}


GoapSolver::~GoapSolver()
{
}

Actions *GoapSolver::getFinalTarget() const {
    return finalTarget;
}

void GoapSolver::setFinalTarget(Actions *finalTarget) {
    GoapSolver::finalTarget = finalTarget;
}
