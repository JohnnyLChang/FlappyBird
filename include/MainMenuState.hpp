#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar {
	class MainMenuState : public State {
	public:
		MainMenuState(GameDataSptr data);

		void Pause();
		void Resume();

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataSptr _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;

	};
}