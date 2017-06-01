#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar {
	Land::Land(GameDataSptr data) : _data(data) {
		sf::Sprite sprite(_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(_data->assets.GetTexture("Land"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt) {
		for (auto & l : _landSprites) {
			sf::Vector2f pos = l.getPosition();
			float movement = PIPE_MOVEMENT_SPEED * dt;;

			l.move(-movement, 0.0f);

			if (l.getPosition().x < 0 - l.getGlobalBounds().width) {
				sf::Vector2f pos(_data->window.getSize().x, l.getPosition().y);

				l.setPosition(pos);
			}
		}
	}

	void Land::DrawLand() {
		for (auto l : _landSprites) {
			_data->window.draw(l);
		}
	}

	const std::vector<sf::Sprite> &Land::GetSprites() const {
		return _landSprites;
	}
}