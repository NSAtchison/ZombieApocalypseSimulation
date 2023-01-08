#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "AlertPerson.h"

using std::cout;
using std::endl;

AlertPerson::AlertPerson(int loc, int unBite, int alBite, int con) : Person(loc, 1, unBite, alBite, con){}
AlertPerson::AlertPerson(int loc, int unBite, int alBite, int con, int oldID) : Person(loc, 1, unBite, alBite, con, oldID){}

void AlertPerson::action(Person*& ppl, Location& loc){
    int randNum = rand() % 100;
    if(randNum < convince) { // Alert Person successfully convinces Unalert Person
        loc.removePerson(ppl); // removes the unalert person from the area
        Person* newPerson = new AlertPerson((*ppl).getLoc(), unalertBite, alertBite, convince, (*ppl).getID()); // creates a new alert person
        delete ppl;
        ppl = newPerson;
        loc.addPerson(ppl); // adds the new alert person to the area/location
    }
}

