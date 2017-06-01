#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar {
	class SplashState : public State {
	public:
		SplashState(GameDataSptr data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		void Pause();
		void Resume();

	private :
		GameDataSptr _data;

		sf::Clock _clock;

		//sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}