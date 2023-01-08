#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include "person.h"

using std::map;
using std::vector;
using std::cout;
using std::endl;

Person::Person() {
    currLoc = 0;
    status = 0;
    ID = 0;
    unalertBite = 0;
    alertBite = 0;
    convince = 0;
}

static unsigned int idPool = 0;
Person::Person(int loc, int stat, int unBite, int alBite, int con) {
    currLoc = loc;
    status = stat;
    ID = idPool++;


    unalertBite = unBite;
    alertBite = alBite;
    convince = con;

};

Person::Person(int loc, int stat, int unBite, int alBite, int con, int oldID) {
    currLoc = loc;
    status = stat;
    ID = oldID;


    unalertBite = unBite;
    alertBite = alBite;
    convince = con;
}

void Person::moveLoc(map<int, Location>& locMap) {
    int randNum = rand() % 100;
    if (currLoc != 1) { // They are starting somewhere that isn't downtown
        if (randNum > 50) { //They go downtown
            locMap[currLoc].removePerson(this);
            currLoc = 1;
            locMap[currLoc].addPerson(this);
        }
    } else { //They are starting downtown
        if (randNum < 25) { //They go to Medical Hill
            locMap[currLoc].removePerson(this);
            currLoc = 0;
            locMap[currLoc].addPerson(this);
        } else if (randNum < 50) { //They go to the Burbs
            locMap[currLoc].removePerson(this);
            currLoc = 2;
            locMap[currLoc].addPerson(this);
        } else if (randNum < 75) { //They go to the University
            locMap[currLoc].removePerson(this);
            currLoc = 3;
            locMap[currLoc].addPerson(this);
        }
    }
}

Person::~Person() {}

int Person::getID() { return ID; }
int Person::getStatus() { return status; }
int Person::getLoc() { return currLoc; }