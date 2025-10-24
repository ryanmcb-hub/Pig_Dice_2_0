#ifndef GAME_H
#define GAME_H
#include "Turn.h"
class Game {
private:
    Turn m_myTurn;
    int m_game_score;
    bool m_game_over;
public:
    Game();
    void set_game_score();
    int get_game_score();
    void set_game_over();
    bool reset_game_over();
    void display_rules();
    void play_game();
};


#endif //GAME_H
