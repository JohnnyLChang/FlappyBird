#pragma once

#include <sstream>
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Sonar {
	GameState::GameState(GameDataSptr data) : _data(data) {

	}

	void GameState::Pause() {
		return;
	}

	void GameState::Resume() {
		return;
	}

	void GameState::Init() {

		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);

		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		hud = new HUD(_data);
		flash = new Flash(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_score = 0;
		hud->UpdateScore(_score);

		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
				if (GameStates::eGameOver != _gameState) {
					_gameState = GameStates::ePlaying;
					bird->Tap();
				}
			}
		}
	}

	void GameState::Update(float dt) {
		if (GameStates::eGameOver != _gameState) {
			bird->Animate(dt);
			land->MoveLand(dt);
		}

		if (GameStates::ePlaying == _gameState) {
			pipe->MovePipes(dt);

			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
				pipe->RandomizePipeOffSet();

				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();
				_clock.restart();
			}
			bird->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();
			for (auto l : landSprites) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, l, 1.0f )) {
					_gameState = GameStates::eGameOver;
					_clock.restart();
				}
			}

			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
			for (auto p : pipeSprites) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.8f, p, 0.8f)) {
					_gameState = GameStates::eGameOver;
					_clock.restart();
				}
			}

			if (GameStates::ePlaying == _gameState) {
				std::vector<sf::Sprite> & scoringSprites = pipe->GetScoringSprites();
				for (auto p = scoringSprites.begin(); p != scoringSprites.end(); ++p) {
					if (collision.CheckSpriteCollision(bird->GetSprite(), 0.8f, *p, 0.8f)) {
						_score++;
						scoringSprites.erase(p);
						hud->UpdateScore(_score);
					}
				}
			}
		}

		if (GameStates::eGameOver == _gameState) {
			flash->Show(dt);
			if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
				_data->machine.AddState(StateUptr(new GameOverState(_data)));
			}
		}
	}

	void GameState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->DrawBird();
		flash->Draw();
		hud->Draw();
		_data->window.display();
	}
}