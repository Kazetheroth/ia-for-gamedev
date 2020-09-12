#pragma once
#include <functional>

#include "GameState.h"


class Transition
{
	private:
		//Attribut contenant la lambda permettant de vérifier les conditions de la transition
		std::function<bool()> condition;
	public:
		Transition(const std::function<bool()> newCondition);
		const std::function<bool()>& getCondition();	
};

