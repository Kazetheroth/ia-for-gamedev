#include "pch.h"
#include "Actions.h"


Actions::Actions()
{
}

Actions::Actions(const std::string& name, Effect* effect, int cost)
{
	this->name = name;
	this->effect = effect;
	this->cost = cost;
}


Actions::~Actions()
{
    delete effect;
    for (int i = 0; i < getPreconditions().size(); i++) {
        delete preconditions[i];
    }
}

std::string Actions::getName() const
{
	return name;
}

void Actions::setName(const std::string& name)
{
	this->name = name;
}

Effect* Actions::getEffect() const
{
	return effect;
}

void Actions::setEffect(Effect* effect)
{
	this->effect = effect;
}

std::vector<Precondition*> Actions::getPreconditions() const
{
	return preconditions;
}

void Actions::setPreconditions(const std::vector<Precondition*>& preconditions)
{
	this->preconditions = preconditions;
}

int Actions::getCost() const
{
	return cost;
}

void Actions::setCost(int cost)
{
	this->cost = cost;
}

void Actions::addPreconditions(Precondition* addedPreconditions)
{
	this->preconditions.push_back(addedPreconditions);
}