#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Flash.hpp"
#include "Collision.hpp"

namespace Sonar {
	class GameState : public State {
	public:
		GameState(GameDataSptr data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		void Pause();
		void Resume();

	private:
		GameDataSptr _data;

		sf::Clock _clock;

		//sf::Texture _backgroundTexture;
		sf::Sprite _background;

		//draw pipes
		Pipe *pipe;

		Land *land;
		Bird *bird;
		Flash *flash;
		Collision collision;
		
		int _gameState;

		sf::RectangleShape _gameOverFlash;
		bool _flahsOn;

		int _score;
	};
}