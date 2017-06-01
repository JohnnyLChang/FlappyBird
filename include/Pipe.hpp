#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <vector>

namespace Sonar {
	class Pipe {
	public:
		Pipe(GameDataSptr data);

		void SpawnBottomPipe( );
		void SpawnTopPipe( );
		void SpawnInvisiblePipe( );
		void MovePipes(float dt);
		void RandomizePipeOffSet();
		void DrawPipes( );

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataSptr _data;
		std::vector<sf::Sprite> _pipeSprites;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}