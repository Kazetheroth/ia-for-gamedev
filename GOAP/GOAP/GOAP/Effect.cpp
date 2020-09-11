#include "pch.h"
#include "Effect.h"


Effect::Effect()
{
}

Effect::Effect(std::function<int()> effect, Condition newCondition)
{
	this->effect = effect;
	this->responseCondition = newCondition;
}


Effect::~Effect()
{
}

std::function<int()> Effect::getEffectLambda() const
{
	return effect;
}

void Effect::setEffectLambda(const std::function<int()>& effect)
{
	this->effect = effect;
}

Condition Effect::getConditionEnum() const
{
	return responseCondition;
}

void Effect::setConditionEnum(const Condition condition)
{
	this->responseCondition = condition;
}
