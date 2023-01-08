#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "zombie.h"
#include "alertPerson.h"
#include "unalertPerson.h"

using std::cout;
using std::endl;

Zombie::Zombie(int loc, int unBite, int alBite, int con) : Person(loc, 0, unBite, alBite, con){}
Zombie::Zombie(int loc, int unBite, int alBite, int con, int oldID) : Person(loc, 0, unBite, alBite, con, oldID){}

void Zombie::action(Person*& ppl, Location& loc){
    int randNum = rand() % 100;
    if((*ppl).getStatus() == 1) { // They attempt to bite a alert person: if successful a new zombie is created, otherwise nothing happens (they escape)
        if(randNum < alertBite) {
            loc.removePerson((ppl)); // remove person from the current location
            Person* newPerson = new Zombie((*ppl).getLoc(), unalertBite, alertBite, convince, (*ppl).getID()); // create new zombie
            delete ppl;
            ppl = newPerson;
        }
    } else { // They attempt to bite an unalert person: either the UnalertPerson becomes a zombie, or they escape and are now aware of the apocalypse (an AwarePerson)
        if(randNum < unalertBite) {
            loc.removePerson((ppl)); // remove person from the current location
            Person* newPerson = new Zombie((*ppl).getLoc(), unalertBite, alertBite, convince, (*ppl).getID()); // create new zombie
            delete ppl;
            ppl = newPerson;
        } else {
            loc.removePerson((ppl)); // remove person from the current location
            Person* newPerson = new AlertPerson((*ppl).getLoc(), unalertBite, alertBite, convince, (*ppl).getID()); // create new AlertPerson 
            delete ppl;
            ppl = newPerson;
            loc.addPerson(ppl); // add newly created turned person back to the current location

        }
    }
}

