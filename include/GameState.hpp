#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Flash.hpp"
#include "HUD.hpp"
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
		HUD *hud;
		Collision collision;
		
		int _gameState;

		sf::RectangleShape _gameOverFlash;
		bool _flahsOn;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;

		static bool _bgameSoundLoaded;
		static sf::SoundBuffer _gameSoundBuffer;
		static sf::Sound _gameSound;

		sf::Sound _hitSound;
		sf::Sound _wingSound;
		sf::Sound _pointSound;
	};
}