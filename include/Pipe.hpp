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
		void SpawnScoringPipe();
		void MovePipes(float dt);
		void RandomizePipeOffSet();
		void DrawPipes( );

		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();

	private:
		GameDataSptr _data;
		std::vector<sf::Sprite> _pipeSprites;
		std::vector<sf::Sprite> _pipeScoringSprites;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}