#ifndef UNALERTPERSON_H
#define UNALERTPERSON_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "person.h"


// definition of 'UnalertPerson' class as a child of Person
class UnalertPerson : public Person { 
    public:
        UnalertPerson(int loc, int unBite, int alBite, int con); // constructor for unalert people
        UnalertPerson(int loc, int unBite, int alBite, int con, int oldID);
        
        // action of unalert person is nothing since unalert people don't know about the apocalypse
        void action(Person* &ppl, Location& loc); 
};


#endif