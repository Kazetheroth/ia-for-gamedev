#include "pch.h"
#include "GoapSolver.h"
#include <iostream>


std::vector<Actions*> GoapSolver::solveActionSteps(std::vector<Actions*>* disponiblesActions)
{
	std::vector<Precondition*> finalPreconditions = this->finalTarget->getPreconditions();
	size_t finalPreconditionsSize = finalPreconditions.size();

	//int *lastCondition = (int*)malloc(this->finalTarget->getPreconditions().size() * sizeof(int));
	
	for (Actions* actions : disponiblesActions[0])
	{
		switch (actions->getEffect()->getConditionEnum())
		{
		case Condition::Build:
			std::cout << "Builder!" << std::endl;
			break;
		default:
			break;
		}
		
	} 
	
	for (int i = 0; i < finalPreconditionsSize; i++)
	{
		std::cout << "Condition " << i << " : " << finalPreconditions[i]->getVerifyCondition()() << std::endl;
	}

	//free(lastCondition);
	return std::vector<Actions*>();
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
