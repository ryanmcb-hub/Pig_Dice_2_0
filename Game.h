#ifndef GAME_H
#define GAME_H
#include "Turn.h"
class Game {
private:
    Turn m_myTurn; // Turn object
    int m_game_score; // Player Socre
    bool m_game_over;
public:
    Game(); // Constructor
    void set_game_score(); //add turn score to total score
    int get_game_score();
    void set_game_over(); // Game over
    bool reset_game_over();
    void display_rules();  // Show game instructions
    void play_game(); //main game loop
};


#endif //GAME_H
