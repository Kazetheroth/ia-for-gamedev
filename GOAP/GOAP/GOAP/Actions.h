#pragma once
#include <functional>
#include <string>
#include <vector>
#include "Precondition.h"

class Actions
{
private:
	std::string name;
	std::function<int()> effect;
	std::vector<Precondition*> preconditions;
	int cost;
public:
	int getCost() const;
	void setCost(int cost);
	std::vector<Precondition*> getPreconditions() const;
	void setPreconditions(const std::vector<Precondition*>& preconditions);
	void setEffect(const std::function<int()>& effect);
	std::function<int()> getEffect() const;
	void setName(const std::string& name);
	std::string getName() const;

	Actions();

	Actions(const std::string& name, const std::function<int()>& effect, int cost);

	~Actions();
};

