#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "person.h"
#include "location.h"
#include "alertPerson.h"
#include "unalertPerson.h"
#include "zombie.h"


//Simulator class is used to set up everything for our simulation of the zombie apocalypse
//By calling the function to run the simulation in main, the simulation class will create it's parameters
//using the private functions defined within the class
//Usually, one simulation is created in main, however, the user can create as many simulations as they desire

class Simulator {
    private:
    map<int, Location> locMap; //Map containing all of the locations in our simulation
    vector<Person*> people; //Vector of all the people in our simulation
    int convChance; //Percentage chance of an unalert person being convinced the apocalypse is happening
    int unChance; //Percentage chance of an unalert person being bitten by a zombie
    int alChance; //Percentage chance of an alert person being bitten by a zombie
    int numDays; //Number of the days that the simulation will run
    float perUniversity; //Percentage of people in the University district
    float perMedical; //Percentage of people in Medical Hill
    float perBurbs; //Percentage of people in the 'Burbs
    float perDowntown; //Percentage of people in Downtown


    //Function for the user to input all the major parameters of the simulation
    //Input: N/A
    //Output/Return: All the major parameters are updated within the simulator object to match user input
    void getMajorParameters();

    //Function for setting up the simulation. This mainly creates a zombie in Medical Hill, and alert person
    //in the University district, and spreads out all the unalert people based on the user input for the major parameters
    //Input: N/A
    //Output/Return: The maps/vectors within each location are filled with all the unalert and alert people.
    //               The people vector within the simulation object is filled with all the people of the simulation.
    void setupSimulation();


    public:
        //Default constructor
        Simulator();

        //Function for running the simulation
        //Input: N/A
        //Output/Return: A .csv file named "output.csv" is created containing how many of each type of person there is
        //               during each hour of the simulation
        void runSimulator();

};

#endif