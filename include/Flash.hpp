#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar {
	class Flash {
	public:
		Flash(GameDataSptr data);

		void Show(float dt);
		void Draw();

	private:
		GameDataSptr _data;

		sf::RectangleShape _shape;

		bool _flashOn;
	};
}