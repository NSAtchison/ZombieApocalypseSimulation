#include <iostream>
#include <string>
#include <vector>
#include "location.h"
#include "person.h"

using std::cout;
using std::endl;

Location::Location() {
    map<int, Person*> alerts;
    vector<int> alertsID;
    map<int, Person*> unalerts;
    vector<int> unalertsID;
}

void Location::addPerson(Person* ppl) {
    if((*ppl).getStatus() == 1) {//adding someone who's alert to this location
        alertsID.push_back((*ppl).getID());//add their ID to the vector
        alerts[(*ppl).getID()] = ppl;//add them to the map with their ID as the key
    } else if((*ppl).getStatus() == 2) {//adding someone who's unalert to this location
        unalertsID.push_back((*ppl).getID());//add their ID to the vector
        unalerts[(*ppl).getID()] = ppl; //add them to the map with their ID as the key
    }
}

void Location::removePerson(Person* ppl) {
    if ((*ppl).getStatus() == 1) {//removing an alert person from this location
        for(int i = 0; i < alertsID.size(); i++) {//run through vector until we find their id, then remove id
            if(alertsID[i] == (*ppl).getID()) {
                alertsID.erase(alertsID.begin() + i);
                break;
            }
        }
        alerts.erase((*ppl).getID());//remove from the map
    } else if ((*ppl).getStatus() == 2) {//removing an unalert person from this location
        for(int i = 0; i < unalertsID.size(); i++) {//run through vector until we find their id, then remove id
            if(unalertsID[i] == (*ppl).getID()) {
                unalertsID.erase(unalertsID.begin() + i);
                break;
            }
        }
        unalerts.erase((*ppl).getID());//remove from map
    }
}


Person* Location::randPerson(int actorStat) {
    if(actorStat == 0) { //Actor is a zombie;
        int randPerson = rand() % (alertsID.size() + unalertsID.size()); //Grab random alert/unalert person (what a zombie does)
        if(randPerson < alertsID.size()) {//if the random number is less than the size of alert id, we'll take a random person from the alert vector
            int randID = alertsID[randPerson];//get the id of the person at [random number] spot
            return (alerts[randID]);//return the person with that id using the map
        } else {
            randPerson -= alertsID.size();//subtract the size of the alert vector to get the random position in the unalert vector
            int randID = unalertsID[randPerson];//get the id of the person at [random number] spot
            return (unalerts[randID]);//return the person with that id using the map
        }
    } else { //Actor is an alert Person-so, randomly select an unalert person
        int randPerson = rand() % unalertsID.size();//select a new random number
        int randID = unalertsID[randPerson];//select the id at that random spot using the vector
        return (unalerts[randID]);//return the person with that id using the map
    }
}

int Location::getNumAlert() {
    return alertsID.size();
}

int Location::getNumUnalert() {
    return unalertsID.size();
}