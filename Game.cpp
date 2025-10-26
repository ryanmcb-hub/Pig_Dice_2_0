#include <iostream>
#include "Game.h"
#include <iostream>
#include <random>     // For Mersenne Twister RNG
#include "Game.h"

// Constructor
Game::Game() {
    m_game_score = 0;
    m_game_over = false;
}

// Add points from this turn to total
void Game::set_game_score() {
    m_game_score += m_myTurn.get_score_this_turn();
}

// Return total score
int Game::get_game_score() {
    return m_game_score;
}

// Ends the game when condition met
void Game::set_game_over() {
    m_game_over = true;
}

// Resets game over flag
bool Game::reset_game_over() {
    m_game_over = false;
    return m_game_over;
}

// Display the rules
void Game::display_rules() {
    std::cout << "Let's Play PIG Dice!\n";
    std::cout << "* See how many turns it takes you to get to 20.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you save all points for the turn.\n";
}

// Main game loop
void Game::play_game() {
    // Random
    std::random_device rd;
    std::mt19937 rng(rd());

    // Ask for number of sides on die
    int userSides;
    std::cout << "Enter number of sides for the die (2, 4, 6, 8, 12): ";
    std::cin >> userSides;

    // Validate sides and make it the die
    // Die in Turn has 6 by default = 2 OR =4, ect
    if (userSides == 2 || userSides == 4 || userSides == 6 || userSides == 8 || userSides == 12) {
        std::cout << "Using a " << userSides << "-sided die.\n";
    } else {
        std::cout << "Invalid number of sides. Defaulting to 6.\n";
        userSides = 6;
    }

    // Game loop until total score >= 20
    while (!m_game_over) {
        // Start turn
        m_myTurn.reset_turn_over();
        m_myTurn.reset_score_this_turn();
        m_myTurn.take_turn();

        // Add score from this turn to total
        set_game_score();

        // Display scores
        std::cout << "Score this Turn: " << m_myTurn.get_score_this_turn() << std::endl;
        std::cout << "Total Score: " << m_game_score << std::endl;

        // Win check
        if (m_game_score >= 20) {
            set_game_over();
            std::cout << "\nYou finished with a final score of 20 or more in "
                      << m_myTurn.get_turn_count() << " turns!\n";
        }
    }
}
