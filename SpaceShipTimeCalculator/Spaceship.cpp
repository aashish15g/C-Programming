#include <iostream>
#include "Spaceship.h"
using namespace std;

// Default constructor
Spaceship::Spaceship() {
    crewSize = 0;
    name = "NoName";
    color = "NoColor";
    impulseSpeed = 0;
    shieldsUp = false;
}

// Non-default constructor
Spaceship::Spaceship(const int Crew, const string Name, const string Color, const long Impulse, const bool Shields) {
    crewSize = Crew;
    name = Name;
    color = Color;
    impulseSpeed = Impulse;
    shieldsUp = Shields;
}

// Copy constructor
Spaceship::Spaceship(const Spaceship &otherShip) {
    crewSize = otherShip.crewSize;
    name = otherShip.name;
    color = otherShip.color;
    impulseSpeed = otherShip.impulseSpeed;
    shieldsUp = otherShip.shieldsUp;
}

// Destructor
Spaceship::~Spaceship() {
    // No dynamic memory to clean up
}

// Setters
bool Spaceship::SetCrewSize(const int Crew) {
    if (Crew >= 0) {
        crewSize = Crew;
        return true;
    }
    return false;
}

void Spaceship::SetName(string Name) {
    name = Name;
}

void Spaceship::SetColor(string Color) {
    color = Color;
}

bool Spaceship::SetImpulseSpeed(const long Impulse) {
    if (Impulse >= 0) {
        impulseSpeed = Impulse;
        return true;
    }
    return false;
}

void Spaceship::SetShieldsUp(const bool Shields) {
    shieldsUp = Shields;
}

// Getters
int Spaceship::GetCrewSize() const {
    return crewSize;
}

string Spaceship::GetName() const {
    return name;
}

string Spaceship::GetColor() const {
    return color;
}

long Spaceship::GetImpulseSpeed() const {
    return impulseSpeed;
}

bool Spaceship::GetShieldsUp() const {
    return shieldsUp;
}

// Other methods
void Spaceship::Print() const {
    cout << "Name: " << name << std::endl;
    cout << "Color: " << color << std::endl;
    cout << "Crew Size: " << crewSize << " crew members." << std::endl;
    cout << "Impulse Speed: " << impulseSpeed << " km/sec." << std::endl;
    cout << "Shields Up: " << (shieldsUp ? "TRUE" : "FALSE") << std::endl;
}

void Spaceship::OrbitStart() {
    shieldsUp = true;
}

void Spaceship::OrbitEnd() {
    shieldsUp = false;
}

long Spaceship::CurrentSpeed() const {
    return shieldsUp ? impulseSpeed : WARP_SPEED;
}