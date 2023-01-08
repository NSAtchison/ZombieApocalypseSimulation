#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "person.h"
#include "unalertPerson.h"

UnalertPerson::UnalertPerson(int loc, int unBite, int alBite, int con) : Person(loc, 2, unBite, alBite, con){}
UnalertPerson::UnalertPerson(int loc, int unBite, int alBite, int con, int oldID) : Person(loc, 1, unBite, alBite, con, oldID){}

void UnalertPerson::action(Person*& ppl, Location& loc) {}