//Circular Dependency Problem fixed with solution from here.
//src: https://stackoverflow.com/questions/30223453/c-circular-dependency-in-header-files
#include "location.h"

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::vector;


class Person {
    private:
        int currLoc;
        int status;
        int ID;

    protected:
        int unalertBite;
        int alertBite;
        int convince;

    public:
        Person();
        Person(int loc, int stat, int unBite, int alBite, int con);
        Person(int loc, int stat, int unBite, int alBite, int con, int oldID);

        void moveLoc(map<int, Location>& locMap);

        virtual void action(Person*& ppl, Location& loc) = 0;

        virtual ~Person();

        int getID();
        int getStatus();
        int getLoc();
};






#endif