#pragma once

class GameState
{
	//Classe permettant de gerer les �tats du monde

	public:
		bool isDay;
		bool isHungry;
		bool isOutside;
		bool hasFood;

	GameState();
	GameState(bool isDay, bool isHungry, bool hasFood, bool isOutside);
};
