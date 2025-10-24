#ifndef DIE_H
#define DIE_H

class Die {
private:
    int m_sides;
    int m_die_value;
public:
    Die(); //Default constructor
    Die(int S); // Constructor that accepts sides
    void set_die_value(); // Roll die
    int get_die_value(); // Accessor roll result
};

#endif //DIE_H
