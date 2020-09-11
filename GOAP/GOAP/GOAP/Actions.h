#pragma once
#include <functional>
#include <string>
#include <vector>
#include "Precondition.h"
#include "Effect.h"

class Actions
{
private:
	std::string name;
	Effect* effect;
	std::vector<Precondition*> preconditions;
	int cost;
public:
	int getCost() const;
	void setCost(int cost);
	std::vector<Precondition*> getPreconditions() const;
	void setPreconditions(const std::vector<Precondition*>& preconditions);
	void setEffect(Effect* effect);
	Effect* getEffect() const;
	void setName(const std::string& name);
	std::string getName() const;
	void addPreconditions(Precondition* addedPreconditions);

	

	Actions();

	Actions(const std::string& name, Effect* effect, int cost);

	~Actions();
};

