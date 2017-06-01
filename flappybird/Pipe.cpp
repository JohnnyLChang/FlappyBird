#include "Pipe.hpp"
#include <cmath>
#include <iostream>

namespace Sonar {
	Pipe::Pipe(GameDataSptr data) : _data(data) {
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}

	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);

		_pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);

		_pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, 0);
		//sprite.setColor(sf::Color(0, 0, 0, 0));

		//_pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(_data->window.getSize().x, 0);

		_pipeScoringSprites.push_back(sprite);
	}

	void Pipe::MovePipes(float dt) {
		//for accurately move the pipes after out of screen 
		for (auto p = _pipeSprites.begin(); p != _pipeSprites.end(); ++p) {
			//sf::Vector2f position = p.getPosition();
			if (p->getPosition().x < 0 - p->getGlobalBounds().width) {
				_pipeSprites.erase(p);
			}
			else {
				float movement = PIPE_MOVEMENT_SPEED * dt;
				p->move(-movement, 0);
			}
		}

		for (auto p = _pipeScoringSprites.begin(); p != _pipeScoringSprites.end(); ++p) {
			//sf::Vector2f position = p.getPosition();
			if (p->getPosition().x < 0 - p->getGlobalBounds().width) {
				_pipeScoringSprites.erase(p);
			}
			else {
				float movement = PIPE_MOVEMENT_SPEED * dt;
				p->move(-movement, 0);
			}
		}
	}

	void Pipe::DrawPipes() {
		for (auto & p : _pipeSprites){
			this->_data->window.draw(p);
		}
	}

	void Pipe::RandomizePipeOffSet() {
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite> &Pipe::GetSprites() const {
		return _pipeSprites;
	}

	std::vector<sf::Sprite> &Pipe::GetScoringSprites() {
		return _pipeScoringSprites;
	}
}