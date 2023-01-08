#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


using std::map;
using std::vector;
using std::set;

//Circular Dependency Problem fixed with solution from here.
//src: https://stackoverflow.com/questions/30223453/c-circular-dependency-in-header-files
class Person;

//Location class keeps track of who is in which location so zombies and alert people know who to take action against
//No zombies because no one does actions against zombies
//Four instances of this class are created in the simulation class-one for each location

class Location {
    private:
        //maps are used to identify people based on their ID's so people can act against them and we can move people
        //vectors are used to find random people in this location
        map<int, Person*> alerts;
        vector<int> alertsID;
        map<int, Person*> unalerts;
        vector<int> unalertsID;


    public:
        Location();

        //adds a person to the correct map and vector
        void addPerson(Person* ppl);

        //removes a person from their map/vector
        void removePerson(Person* ppl);

        //selects a random actee based on the actor's type (zombies act against unalerts and alerts, alerts act against unalerts)
        //unalerts act against no one, so don't include them in here
        Person* randPerson(int actorStat);

        //used in output file
        int getNumAlert();
        int getNumUnalert();
};

#endif 