#include "system.h"

int main() {
	System system(100,20.0,0.5,0.1, 1234);
	
	std::cout << system.uniform(10, 20) << "\n";
	std::cout << "Hi There";
}
