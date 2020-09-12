#pragma once
#include "State.h"
#include "GameState.h"

using namespace std;

class StateMachine
{


	private:
		//State de d�part
		State *startState_;

		//State dans laquelle la StateMachine est � l'instant t
		State *currentState_;

		//Gamestate li� a la Statemachine
		GameState* gs;

		//Vector contenant toutes les states de la StateMachine
		vector<State*> states_;
	public:
		StateMachine();
		StateMachine(State* startState, GameState* gs);

		const vector<State*>& getStates() const;

		//Ajout de state a la StateMachine
		void AddStates(State* newState);

		//Permet de v�rifier toutes les transitions li�s a la State dans laquelle est la StateMachine
		//Cette m�thode va aussi permettre de changer le "currentState_"
		void checkTransition(const GameState* gameState);

		//C'est dans cette m�thode qu'est la boucle principale de la StateMachine
		void mainLoop();
};

