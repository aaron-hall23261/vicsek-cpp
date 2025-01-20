#include "system.h"

System::System(int particleNumber,double sideLength, double timeStep,double noiseStrength){
    this->particleNumber = particleNumber;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    this->noiseStrength = noiseStrength;
}

void System::updateRule(){
    std::cout << "Updating the system...";
}

void System::printValues(){
    std::cout << "Particle Number: " << this->particleNumber << "\n"
            << "Side Length: " << this->sideLength << "\n"
            << "Time Step: " << this->timeStep << "\n"
            << "Noise Strength: " << this->noiseStrength << "\n";
}