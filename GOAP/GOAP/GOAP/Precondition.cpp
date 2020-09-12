#include "pch.h"
#include "Precondition.h"


Precondition::Precondition(std::function<bool()> verifyCondition, Condition responseCondition)
{
	this->verifyCondition = verifyCondition;
	this->responseCondition = responseCondition;
}


Precondition::~Precondition()
{
}

std::function<bool()> Precondition::getVerifyCondition() const
{
	return verifyCondition;
}

void Precondition::setVerifyCondition(const std::function<bool()>& verify_condition)
{
	verifyCondition = verify_condition;
}

Condition Precondition::getResponseCondition() const
{
	return this->responseCondition;
}

void Precondition::setResponseCondition(const Condition response_condition)
{
	this->responseCondition = response_condition;
}

