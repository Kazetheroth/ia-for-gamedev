#include "pch.h"
#include "GoapSolver.h"
#include <iostream>


std::vector<Actions*> GoapSolver::solveActionSteps(std::vector<Actions*>* disponiblesActions, Actions* currentTarget)
{
	std::vector<Precondition*> targetPrecondition = currentTarget->getPreconditions();
	size_t targetPreconditionSize = targetPrecondition.size();
    std::cout << currentTarget->getName() << std::endl;
    for (int i = 0; i < targetPreconditionSize; i++)
    {
        std::cout << "Condition " << i << " : " << targetPrecondition[i]->getVerifyCondition()() << std::endl;
        while (!targetPrecondition[i]->getVerifyCondition()()){
            for (Actions* actions : disponiblesActions[0])
            {
                if (actions->getEffect()->getConditionEnum() == targetPrecondition[i]->getResponseCondition()){
                    actions->getEffect()->getEffectLambda()();
                    this->currentPath.push_back(actions);
                    if(!targetPrecondition[i]->getVerifyCondition()())
                        return solveActionSteps(disponiblesActions, actions);
                }
            }
        }
    }
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
