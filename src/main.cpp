#include "system.h"

int main() {
	// particleNumber,sideLength, timeStep, noiseStrength, seed
	System system(200,50,0.5,0.2,666);
	
	system.randomStart();
	system.saveConfig("frames/init.conf");

	for(int i=0; i<1000; i++){
		system.updateRule();
		std::string root = "frame";
		system.saveConfig("frames/"+root+std::to_string(i));
	}

}
