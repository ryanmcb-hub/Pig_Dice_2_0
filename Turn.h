#ifndef TURN_H
#define TURN_H
#include "Die.h"
class Turn {
private:
    Die m_myDie; // Die object
    char m_choice; // r or h choice
    int m_score_this_turn;
    int m_turn_count; //turn number it is
    bool m_turn_over;

public:
    Turn();
    void reset_turn_over();
    bool get_turn_over(); //check turn over
    void reset_score_this_turn(); //reset turn score zero
    int get_score_this_turn();
    void set_turn_count(); //increment turn count
    int get_turn_count();
    void take_turn(); //choices roll or hold

private:
    void roll(); //roll and turn logic
};

#endif //TURN_H
