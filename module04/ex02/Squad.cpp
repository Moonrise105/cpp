#include "Squad.hpp"

Squad::Squad() : unitCount_(0), units_(NULL) {

}

Squad::~Squad() {
	t_units * tmp = this->units_;
	t_units * prev;

	for (int i = 0; i < this->unitCount_; i++) {
		prev = tmp; 
		tmp = tmp->next;
		delete prev->unit;
		delete prev;
	}
}

Squad::Squad(Squad const & copy) {
	
	this->unitCount_ = 0;
	for (int i = 0; i < copy.unitCount_; i++) {
		this->push(copy.getUnit(i)->clone());
	}
}

Squad & Squad::operator=(Squad & op) {
	if (this != &op) {
		t_units * tmp = this->units_;
		t_units * prev;

		for (int i = 0; i < this->unitCount_; i++) {
			prev = tmp; 
			tmp = tmp->next;
			delete prev->unit;
			delete prev;
		}
		this->unitCount_ = 0;
		for (int i = 0; i < op.unitCount_; i++) {
			this->push(op.getUnit(i)->clone());
		}
	}
	return *this;
}

int Squad::getCount() const {
	return this->unitCount_;
}

ISpaceMarine* Squad::getUnit(int index) const {
	t_units * tmp = this->units_;

	if (index < 0 || index >= this->unitCount_)
		return NULL;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->unit;
}

bool Squad::isInList(ISpaceMarine * iSpaceMarine) {
	t_units * tmp = this->units_;
	
	for (int i = 0; i < this->unitCount_; i++) {
		if (iSpaceMarine == tmp->unit)
			return true;
		tmp = tmp->next;	
	}
	return false;
}

void Squad::addList(ISpaceMarine * iSpaceMarine) {
	t_units * new_elem = new t_units;
	t_units * tmp = this->units_;

	for (int i = 0; i < this->unitCount_ - 1; i++) {
		tmp = tmp->next;
	}
	new_elem->unit = iSpaceMarine;
	new_elem->next = NULL;
	if (this->unitCount_ > 0)
		tmp->next = new_elem;
	else
		this->units_ = new_elem;
}

int Squad::push(ISpaceMarine * iSpaceMarine) {
	if (!iSpaceMarine || this->isInList(iSpaceMarine))
		return this->unitCount_;
	addList(iSpaceMarine);
	++this->unitCount_;
	return this->unitCount_;
}