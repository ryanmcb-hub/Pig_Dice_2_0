#include <cstdlib>
#include <ctime>
#include <random>
#include "Die.h"

Die::Die() {
    m_sides = 6;
    m_die_value = 0;
}
Die::Die(int S) {
    m_sides = S;
    m_die_value = 0;
}


void Die::set_die_value() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,6); //gen inclusive 1 to 6
    m_die_value = dis(gen);
}

int Die::get_die_value() {
    return m_die_value;
}
