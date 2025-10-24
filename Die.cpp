#include <cstdlib>
#include <ctime>
#include <random>
#include "Die.h"

// Default constructor 6-sided die starting with 0
Die::Die() {
    m_sides = 6;
    m_die_value = 0;
}

//sets number of sides
Die::Die(int S) {
    m_sides = S;
    m_die_value = 0;
}

//roll die using Mersenne Twister
void Die::set_die_value() {
    std::random_device rd; // Random seed from hardware
    std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<int> dis(1,6); //gen inclusive 1 to 6
    m_die_value = dis(gen); //store roll
}

int Die::get_die_value() {
    return m_die_value;
}
