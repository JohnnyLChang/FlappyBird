#pragma once

#include <sstream>
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>

namespace Sonar {
	GameOverState::GameOverState(GameDataSptr data, int score) : _data(data), _score(score){

	}

	void GameOverState::Pause() {
		return;
	}

	void GameOverState::Resume() {
		return;
	}

	void GameOverState::Init() {
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_gameOverContainer.setPosition(sf::Vector2f(
			(_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), 
			(_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));

		_gameOverTitle.setPosition(sf::Vector2f(
			(_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), 
			_gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));

		_retryButton.setPosition(sf::Vector2f(
			(_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), 
			_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + 
			(_retryButton.getGlobalBounds().height * 0.2)));

		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(
			_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(
			_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y / 2.15);

		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(
			_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(
			_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y / 1.78);
	}

	void GameOverState::HandleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(StateUptr(new GameState(_data)));
			}
		}
	}

	void GameOverState::Update(float dt) {

	}

	void GameOverState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);

		_data->window.display();
	}
}