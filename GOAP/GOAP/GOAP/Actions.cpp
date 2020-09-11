#include "pch.h"
#include "Actions.h"


Actions::Actions()
{
}

Actions::Actions(const std::string& name, const std::function<int()>& effect, int cost)
{
	this->name = name;
	this->effect = effect;
	this->cost = cost;
}


Actions::~Actions()
{
}

std::string Actions::getName() const
{
	return name;
}

void Actions::setName(const std::string& name)
{
	this->name = name;
}

std::function<int()> Actions::getEffect() const
{
	return effect;
}

void Actions::setEffect(const std::function<int()>& effect)
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