#include <iostream>
#include "Turn.h"

Turn::Turn() {
    m_choice = '\0';
    m_turn_count = 0;
    m_score_this_turn = 0;
    m_turn_over = false;
}

void Turn::reset_turn_over() {
    m_turn_over = false;
}

bool Turn::get_turn_over() {
    return m_turn_over;
}

void Turn::reset_score_this_turn() {
    m_score_this_turn = 0;
}

int Turn::get_score_this_turn() {
    return m_score_this_turn;

}
void Turn::set_turn_count() {
    m_turn_count++;
}

int Turn::get_turn_count() {
    return m_turn_count;
}

void Turn::take_turn() {
    m_turn_count++;
    std::cout << "\n\n TURN" << m_turn_count << std::endl;
    while (!m_turn_over) {
        std::cout << "Enter (r)oll or (h)old: ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            m_turn_over = true;
        }
    }
}

void Turn::roll() {
    m_myDie.set_die_value();//I want to roll the die
    std::cout << "Die: " << m_myDie.get_die_value();
    if (m_myDie.get_die_value() == 1) {
        m_score_this_turn = 0;
        m_turn_over = true;
        std::cout << "\nTurn Over. No Score. \n" << std::endl;
    }
    else {
        m_score_this_turn += m_myDie.get_die_value();
    }

}