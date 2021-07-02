#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(MateriaSource const &);
		MateriaSource & operator=(MateriaSource &);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria *_materias[4];
		int _materiasCount;

};
#endif