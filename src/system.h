#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <random>
#include <math.h>
#include <string>
#include <fstream>
#include <vector> //to use standard C++ vectors
#include "box.h" //yet to be created!
#include "particle.h" //yet to be created!

class System {
  public:
    System(int particleNumber,double sideLength, double timeStep,double noiseStrength, int seed);

    int particleNumber;
    double sideLength;
    double timeStep;
    double noiseStrength;
    Box simulationBox;
    std::vector<Particle> particles;
    std::mt19937 gen;
    std::uniform_real_distribution<double> uniformDist;

    void updateRule();
    void printValues();
    double uniform(double min, double max);
    void randomStart();
    void saveConfig(const std::string &filename);
};

#endif
