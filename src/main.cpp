#include "system.h"

int main() {
	System system(100,20.0,0.5,0.1);
	
	std::cout<<"The system has a simulation box of side "<<system.simulationBox.getSidex()<<std::endl;
}
