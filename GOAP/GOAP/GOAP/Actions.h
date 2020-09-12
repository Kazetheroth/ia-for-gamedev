#pragma once
#include <functional>
#include <string>
#include <vector>
#include "Precondition.h"
#include "Effect.h"

class Actions
{
private:
	std::string name; // Sert à l'affichage des actions
	Effect* effect; // Pointeur vers un new Effect déclaré à la création de l'action
	std::vector<Precondition*> preconditions; // Liste de Préconditions nécessaire à l'activation de l'action
	int cost; // cout de l'action
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

