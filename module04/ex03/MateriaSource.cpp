#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiasCount(0) {
	
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < this->_materiasCount; ++i) {
		delete this->_materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	this->_materiasCount = 0;
	for (int i = 0; i < copy._materiasCount; ++i) {
		learnMateria(copy._materias[i]);
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource & op) {
	if (this != &op) {
		for (int i = 0; i < this->_materiasCount; ++i) {
			delete this->_materias[i];
		}
		this->_materiasCount = 0;
		for (int i = 0; i < op._materiasCount; ++i) {
			learnMateria(op._materias[i]);
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (this->_materiasCount >= 4 || !materia)
		return ;
	this->_materias[this->_materiasCount] = materia->clone();
	++this->_materiasCount;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_materiasCount; ++i) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}