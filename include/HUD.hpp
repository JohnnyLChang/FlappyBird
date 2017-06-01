#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Sonar {
	class HUD {
	public:
		HUD(GameDataSptr data);

		void Draw();
		void UpdateScore(int score);

	private:
		GameDataSptr _data;
		sf::Text _scoreText;
	};
}