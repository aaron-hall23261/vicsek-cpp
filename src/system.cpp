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
    std::vector<double> new_theta;
    new_theta.resize(particles.size());
    const double radius = sideLength/10;

    for(size_t i = 0; i < particles.size(); ++i){
        int count = 1;

        double c = cos(particles[i].theta);
        double s = sin(particles[i].theta);

        for(size_t j = 0; j < particles.size(); ++j){
            if(j==i){
                continue;
            }

            double distance = sqrt(pow((particles[i].x - particles[j].x), 2)+ pow((particles[i].y - particles[j].y), 2));
            if(distance > radius){
                double distance = sqrt(pow((particles[i].x - particles[j].x-sideLength-1), 2)+ pow((particles[i].y - particles[j].y-sideLength-1), 2));
            }

            if(distance < radius){
                c += cos(particles[j].theta);
                s += sin(particles[j].theta);
                count++;
            }
        }

        double avg_theta = atan2(s/count, c/count);
        new_theta[i] = avg_theta + uniform(-noiseStrength/2, noiseStrength/2);
    }

    for(size_t i = 0; i < particles.size(); ++i){
        particles[i].x += cos(new_theta[i]) * particles[i].v * timeStep;
        if(particles[i].x > sideLength){
            particles[i].x -= sideLength;
        } else if (particles[i].x < 0){
            particles[i].x += sideLength;
        }

        particles[i].y += sin(new_theta[i]) * particles[i].v * timeStep;
        if(particles[i].y > sideLength){
            particles[i].y -= sideLength;
        } else if (particles[i].y < 0){
            particles[i].y += sideLength;
        }

        particles[i].theta = new_theta[i];
    }
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

void System::randomStart(){
    for (Particle &p : this->particles){
        p.x = this->uniform(0, this->simulationBox.getSidex());
        p.y = this->uniform(0, this->simulationBox.getSidey());
        p.theta = this->uniform(-M_PI, M_PI);
    }
};

void System::saveConfig(const std::string &filename){

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return; // Exit if file cannot be opened
    }
    outFile << std::to_string(particles.size())+"\nParticles"<<std::endl;
    
    // Write particle properties to the file

    for (size_t i = 0; i < particles.size(); ++i) {
        outFile << i << " " << particles[i].x <<" "<<particles[i].y<<" "<<particles[i].theta << std::endl;
    }
    
    outFile.close(); // Close the file
};