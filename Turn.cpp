#include <iostream>
#include "Turn.h"

//constructor initialize data member
Turn::Turn() {
    m_choice = '\0';
    m_turn_count = 0;
    m_score_this_turn = 0;
    m_turn_over = false;
}

void Turn::reset_turn_over() {
    m_turn_over = false;
}

//current turn over status
bool Turn::get_turn_over() {
    return m_turn_over;
}

//reset accumulated score
void Turn::reset_score_this_turn() {
    m_score_this_turn = 0;
}

int Turn::get_score_this_turn() {
    return m_score_this_turn;
}

//increment turn count
void Turn::set_turn_count() {
    m_turn_count++;
}

int Turn::get_turn_count() {
    return m_turn_count;
}


//player input untill turn end
void Turn::take_turn() {
    m_turn_count++;
    std::cout << "\nTURN " << m_turn_count << std::endl;

    // Loop until turn is over
    while (!m_turn_over) {
        std::cout << "Enter (r)oll or (h)old: ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            m_turn_over = true; // End turn when player holds
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }
}

//Rolls the die and applies rules.
void Turn::roll() {
    m_myDie.set_die_value();
    std::cout << "Die: " << m_myDie.get_die_value() << std::endl;
    // Rolling a 1 ends the turn with 0 points
    if (m_myDie.get_die_value() == 1) {
        m_score_this_turn = 0;
        m_turn_over = true;
        std::cout << "Turn Over. No Score.\n";
    }
    else {
        // Add rolled value to this turn score
        m_score_this_turn += m_myDie.get_die_value();
    }
}
