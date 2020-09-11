#pragma once
#include <functional>

#include "Condition.h"
#include "World.h"

class Precondition
{
	private:
		std::function<bool()> verifyCondition;
		Condition responseCondition;
	public:
		Condition getResponseCondition() const;
		void setResponseCondition(const Condition response_condition);

		std::function<bool()> getVerifyCondition() const;
		void setVerifyCondition(const std::function<bool()>& verify_condition);

		Precondition(std::function<bool()> verifyCondition, Condition responseCondition);
		~Precondition();
};

