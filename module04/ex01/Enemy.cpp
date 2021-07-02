#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) {
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy() {

}

std::string const & Enemy::getType() const {
	return this->type;
}

int Enemy::getHP() const {
	return this->hp;
}

void Enemy::takeDamage(int damage) {
	if (damage > 0) {
		this->hp -= damage;
		if (this->hp < 0)
			this->hp = 0;
	}
}

Enemy::Enemy(Enemy const &copy) {
	this->hp = copy.hp;
	this->type = copy.type;
}

Enemy & Enemy::operator=(Enemy const & op) {
	if (this != &op) {
		this->type = op.type;
		this->hp = op.hp;
	}
	return *this;
}

void Enemy::setHP(int hp) {
	this->hp = hp;
}

void Enemy::setType(std::string const & type) {
	this->type = type;
}