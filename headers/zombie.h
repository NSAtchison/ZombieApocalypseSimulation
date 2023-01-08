#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "person.h"
#include "alertPerson.h"
#include "location.h"

// create the 'Zombie' class as a child of Person class
class Zombie : public Person {
    public:
        Zombie(int loc, int unBite, int alBite, int con); // constructor for the first zombie
        Zombie(int loc, int unBite, int alBite, int con, int oldID); // constructor for a new zombie that has been turned from an alert or unalert person
        
        // zombie's action attempts to bite people in the same area as them
        // takes in arguments of the current location as well as a person within their current location
        void action(Person*& ppl, Location& loc);
};


#endif