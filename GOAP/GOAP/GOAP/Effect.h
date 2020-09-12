#pragma once
#include <functional>
#include "Condition.h"

class Effect
{
public:
	Effect();
	Effect(std::function<int()> effect, Condition newCondition);
	~Effect();

	std::function<int()> getEffectLambda() const;
	void setEffectLambda(const std::function<int()>& effect);
	Condition getConditionEnum() const;
	void setConditionEnum(const Condition condition);

private:
	std::function<int()> effect; // Lambda a executer avec l'effet
	Condition responseCondition; // Condition à la quel l'effet répond
};

