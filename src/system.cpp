#include "system.h"

System::System(int particleNumber,double sideLength, double timeStep,double noiseStrength, int seed){
    this->particleNumber = particleNumber;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    this->noiseStrength = noiseStrength;
    this->simulationBox = Box(sideLength, sideLength, 0, 0);
    this->particles.resize(particleNumber);
    this->gen = std::mt19937(seed);
};

void System::updateRule(){
    std::cout << "Updating the system...";
};

void System::printValues(){
    std::cout << "Particle Number: " << this->particleNumber << "\n"
            << "Side Length: " << this->sideLength << "\n"
            << "Time Step: " << this->timeStep << "\n"
            << "Noise Strength: " << this->noiseStrength << "\n";
};

double System::uniform(double min, double max){
    return(max-min)*this->uniformDist(gen)+min;
};