# GOAP
***Développés par Abdallah El-Hajjam & Medhi FOULGOC***

Le GOAPSolver n'est pas fonctionnel et nous travaillons toujours dessus. Quelques explications sur ce qui nous manque en dessous du code.

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
			if(!targetPrecondition[i]->getVerifyCondition()())  
                            return solveActionSteps(disponiblesActions, actions);  
      }  
                }  
            }  
        }  
       return this->currentPath;  
    }

Nous devons encore prendre en compte le coût de chaque actions pour permettre au Solver de prendre le chemin optimal.
Il nous manque aussi la récursivité qui permettrait de faire des chemins d'actions.
Les autres classes sont sensée être bonnes et sont commenté pour plus d'information pour chaque attribut.
