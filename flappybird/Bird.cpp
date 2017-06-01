#include "Bird.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Sonar {
	Bird::Bird(GameDataSptr data) : _data(data) {
		_animationItr = 0;

		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));

		_birdSprite.setTexture(_animationFrames[_animationItr]);
		_birdSprite.setPosition(
			(data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2),
			(data->window.getSize().y / 4) - (_birdSprite.getGlobalBounds().height / 2)
		);

		_birdState = BIRD_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(
			_birdSprite.getGlobalBounds().width / 2,
			_birdSprite.getGlobalBounds().height / 2
		);

		_birdSprite.setOrigin(origin);

		_rotation = 0;
	}

	void Bird::DrawBird() {
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size() ) {
			if (_animationItr < _animationFrames.size() - 1) {
				++_animationItr;
			}
			else {
				_animationItr = 0;
			}

			_birdSprite.setTexture(_animationFrames[_animationItr]);
			_clock.restart();
		}
	}

	void Bird::Update(float dt) {
		if (BIRD_STATE_FALLING == _birdState) {
			_birdSprite.move(0, GRAVITY * dt);
			_rotation += ROTATION_SPEED * dt;
			if (_rotation > 25.0f) {
				_rotation = 25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}
		else if (BIRD_STATE_FLYING == _birdState) {
			_birdSprite.move(0, -FLYING_SPEED * dt);
			_rotation -= ROTATION_SPEED * dt;

			if (_rotation < -25.0f) {
				_rotation = -25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}

		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
			_movementClock.restart();
			_birdState = BIRD_STATE_FALLING;
		}
	}

	void Bird::Tap() {
		_movementClock.restart();
		_birdState = BIRD_STATE_FLYING;
	}

	const sf::Sprite &Bird::GetSprite() const {
		return _birdSprite;
	}
}