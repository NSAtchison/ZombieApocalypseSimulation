#ifndef ALERTPERSON_H
#define ALERTPERSON_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "person.h"

// create the 'AlertPerson' class as a child of Person class
class AlertPerson : public Person {
    public:
        AlertPerson(int loc, int unBite, int alBite, int con); // constructor for first alert person
        AlertPerson(int loc, int unBite, int alBite, int con, int oldID); // constructor for people turned from an UnalertPerson to an AlertPerson

        // AlertPerson's action attempts to turn UnalertPeople into AlertPeople so they are aware of the apocalyse
        // action takes in arguments of a person located within the current location of the actee
        void action(Person*& ppl, Location& loc);
};


#endif