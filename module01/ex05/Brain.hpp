#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>
class Brain {
	public:
		Brain();
		~Brain();
		std::string identify(void);
		float const &getVolume(void);
		int const &getNeuronCount(void);
		void setVolume(float &brain);
		void setNeuronCount(int &neuron_count);
	private:
		float volume;
		int neuron_count;

};
#endif
