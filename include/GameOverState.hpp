#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"

namespace Sonar {
	class GameOverState : public State {
	public:
		GameOverState(GameDataSptr data, int score);

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

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;
	};
}