#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"

typedef struct s_units {
	ISpaceMarine * unit;
	struct s_units * next;
} t_units;

class Squad : public ISquad {
	public:
		virtual ~Squad();
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
		Squad();
		Squad(Squad const & copy);
		Squad & operator=(Squad & op);
	private:
		bool isInList(ISpaceMarine *);
		void addList(ISpaceMarine *);
		int unitCount_;
		t_units * units_;
};
#endif