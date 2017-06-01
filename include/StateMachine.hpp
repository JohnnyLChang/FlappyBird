#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Sonar{
	typedef std::unique_ptr<State> StateUptr;

	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}

		void AddState(StateUptr newState, bool isReplacing = true);
		void RemoveState();
		void ProcessingStateChanges();

		//Run at start of each loop in Game.cpp
		StateUptr &GetActivityState();

	private:
		std::stack<StateUptr> _states;
		StateUptr _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}