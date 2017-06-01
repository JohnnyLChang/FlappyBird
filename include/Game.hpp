#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Sonar {
	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataSptr;

	class Game {
	public:
		Game(int width, int height, std::string title);

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataSptr _data = std::make_shared<GameData>();

		void Run();
	};
}