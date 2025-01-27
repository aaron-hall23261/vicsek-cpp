#include "system.h"

int main() {
	System system(100,20.0,0.5,0.1, 1234);
	
	system.randomStart();
	system.saveConfig("init.conf");

}
