#pragma once
#include "State.h"
#include "GameState.h"

using namespace std;

class StateMachine
{


	private:
		//State de départ
		State *startState_;

		//State dans laquelle la StateMachine est à l'instant t
		State *currentState_;

		//Gamestate lié a la Statemachine
		GameState* gs;

		//Vector contenant toutes les states de la StateMachine
		vector<State*> states_;
	public:
		StateMachine();
		StateMachine(State* startState, GameState* gs);

		const vector<State*>& getStates() const;

		//Ajout de state a la StateMachine
		void AddStates(State* newState);

		//Permet de vérifier toutes les transitions liés a la State dans laquelle est la StateMachine
		//Cette méthode va aussi permettre de changer le "currentState_"
		void checkTransition(const GameState* gameState);

		//C'est dans cette méthode qu'est la boucle principale de la StateMachine
		void mainLoop();
};

