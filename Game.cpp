#include <iostream>
#include "Game.h"

Game::Game(){}
void Game::set_game_score(){}
int Game::get_game_score(){}
void Game::set_game_over(){}
bool Game::reset_game_over(){}
void Game::display_rules(){}

void Game::play_game() {
    while (!m_game_over) {
        m_myTurn.take_turn();
        m_game_over += m_myTurn.get_turn_over();
        std::cout<< "Score this Turn: " << m_myTurn.get_score_this_turn() << std::endl;
        std::cout<< "\nTotal Score: " << m_game_score << std::endl;
        m_myTurn.reset_score_this_turn();
    }
}