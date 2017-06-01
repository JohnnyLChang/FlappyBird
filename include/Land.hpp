#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar {
	class Land {
	public:
		Land(GameDataSptr data);

		void MoveLand(float dt);
		void DrawLand();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataSptr _data;
		std::vector<sf::Sprite> _landSprites;
	};
}