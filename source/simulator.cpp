#include "simulator.h"

using std::cin;
using std::cout;
using std::endl;

Simulator::Simulator() {
    map<int, Location> locMap;
    
    //Creating the four locations of our city and putting them in the map
    Location MedicalHill;
    Location Downtown;
    Location Burbs;
    Location University;
    locMap[0] = MedicalHill;
    locMap[1] = Downtown;
    locMap[2] = Burbs;
    locMap[3] = University;

    //Create a vector of pointers to all people within the simulation
    vector<Person*> people;

    //Initialize all the major parameters to zero (Will be set when simulator is run)
    int convChance = 0;
    int unChance = 0;
    int alChance = 0;
    int numDays = 0;
    float perUniversity = 0;
    float perMedical = 0;
    float perBurbs = 0;
    float perDowntown = 0;
}


void Simulator::getMajorParameters() {
    cout << "How many days will the simulation run: ";
    cin >> numDays; //Grabbing the number of days the simulation will run
    while (numDays < 0) { //Can't have negative days, so go until it is valid
        cout << "Invalid number of days. Enter again: ";
        cin >> numDays;
    }
    
    cout << "What percentage chance for a Alert Person to convince an unalert person (0-100): ";
    cin >> convChance; //Grabbing percentage chance of successful convince
    while(convChance < 0 || convChance > 100) { //Percentage chance must be between 0-100, so go until it is valid
        cout << "Invalid Percantage. Enter again: ";
        cin >> convChance; 
    }
    cout << "What percentage chance for a zombie to bite an unalert person (0-100): ";
    cin >> unChance; //Grabbing percentage chance of successful bite of unalert person
    while(unChance < 0 || unChance > 100) { //Percentage chance must be between 0-100, so go until it is valid
        cout << "Invalid Percantage. Enter again: ";
        cin >> unChance; 
    }
    cout << "What percentage chance for a zombie to bite an alert person (0-100): ";
    cin >> alChance; //Grabbing percentage chance of successful bite of alert person
    while(alChance < 0 || alChance > 100) { //Percentage chance must be between 0-100, so go until it is valid
        cout << "Invalid Percantage. Enter again: ";
        cin >> alChance; 
    }

    int sumPercentage = 0; //Initializing sum of percentage in each district to 0
    while(sumPercentage <= 99.9 || sumPercentage >= 100.1) { //Running until the sum of all district breakup is approximately 100%
        sumPercentage = 0;
        cout << "Percentage of people in University district: ";
        cin >> perUniversity; //Grabbing percentage of people in University District
        while(perUniversity < 0) { //Percentage of people can not be less than 0%, run until number is higher than that
            cout << "Invalid Percentage. Enter again: ";
            cin >> perUniversity;
        }
        cout << "Percentage of people in Medical district: ";
        cin >> perMedical; //Grabbing percentage of people in Medical Hill
        while(perMedical < 0) {//Percentage of people can not be less than 0%, run until number is higher than that
            cout << "Invalid Percentage. Enter again: ";
            cin >> perMedical;
        }
        cout << "Percentage of people in the 'Burbs: ";
        cin >> perBurbs; //Grabbing percentage of people in 'Burbs
        while(perBurbs < 0) {//Percentage of people can not be less than 0%, run until number is higher than that
            cout << "Invalid Percentage. Enter again: ";
            cin >> perBurbs;
        }
        cout << "Percentage of people in Downtown: ";
        cin >> perDowntown; //Grabbing percentage of people in Downtown
        while(perDowntown < 0) {//Percentage of people can not be less than 0%, run until number is higher than that
            cout << "Invalid Percentage. Enter again: ";
            cin >> perDowntown;
        }

        //Check the sum of the percentage of people in each district
        sumPercentage += (perBurbs + perDowntown + perMedical + perUniversity);

    }

    //At this point, we have valid percentages for each district, turn them into an actual percentage value.
    perBurbs /= 100;
    perDowntown /= 100;
    perMedical /= 100;
    perUniversity /= 100;
}

void Simulator::setupSimulation() {
    Person* patientZero = new Zombie(0, unChance, alChance, convChance); //Create patient zero
    Person* firstAlarmed = new AlertPerson(3, unChance, alChance, convChance); //Create first alert person
    
    //Add our initial people to the vector of all people in our city
    people.push_back(patientZero);
    people.push_back(firstAlarmed);

    locMap[3].addPerson(firstAlarmed); //Add our alarmed person to the location he is supposed to be at
    
    //Determin the number of people that are going to be in each district based off of user input parameters
    int numBurbs = perBurbs * 1998;
    int numDowntown = perDowntown * 1998;
    int numMedical = perMedical * 1998;
    int numUniversity = perUniversity * 1998;

    //Add all unalert people who are supposed to be in the 'Burbs
    for(int i = 0; i < numBurbs; i++) {
        Person* currPerson = new UnalertPerson(2, unChance, alChance, convChance); //Create an unalert person
        people.push_back(currPerson); //Add them to the vector of people
        locMap[2].addPerson(currPerson); //Add them to the location they are starting at
    }

    //Add all unalert people who are supposed to be in Downtown
    for(int i = 0; i < numDowntown; i++) {
        Person* currPerson = new UnalertPerson(1, unChance, alChance, convChance);
        people.push_back(currPerson);
        locMap[1].addPerson(currPerson);
    }
    
    //Add all unalert people who are supposed to be in Medical Hill
    for(int i = 0; i < numMedical; i++) {
        Person* currPerson = new UnalertPerson(0, unChance, alChance, convChance);
        people.push_back(currPerson);
        locMap[0].addPerson(currPerson);
    }

    //Add all unalert people who are supposed to be in the University District
    for(int i = 0; i < numUniversity; i++) {
        Person* currPerson = new UnalertPerson(3, unChance, alChance, convChance);
        people.push_back(currPerson);
        locMap[3].addPerson(currPerson);
    }

    //If our percentage values gave us less than 2000 people, insert the difference into Downtown
    while(people.size() < 2000) {
        Person* currPerson = new UnalertPerson(1, unChance, alChance, convChance);
        people.push_back(currPerson);
        locMap[1].addPerson(currPerson);
    }
}



void Simulator::runSimulator() {
    getMajorParameters(); //Getting all the major parameters from user
    setupSimulation(); //Putting all the people in the correct district
    int numHours = numDays * 24; //Getting how many hours are simulation can run at maximum


    std::fstream outputFile("output.csv", std::ios::out); //Creating our .csv output file for our data
    outputFile << "Hour,Zombies,Alerts,Unalerts" << endl; //Creating headers in our .csv file


    for(int i = 0; i < numHours; i++) { //Run until we reach the number of hours that match the user input for number of days the simulation will run
        
        cout << "You are on hour " << i+1 << std::endl; //Tells the user which hour they are on in the simulation
        
        //Next 3 lines of code are essentially a "button push" to progress. We don't want to simulation to go all at once, but progress upon button push
        cout << "Enter Key to Progress: ";
        char hold;
        cin >> hold;

        //Following for loop does the simulation for 1 hours worth of action
        for(int j = 0; j < people.size(); j++) { //Runs for every person in the city
            
            //Grabs the pointer to the current person and grabs important information about them
            Person* currPerson = people[j];
            int currPersonStatus = (*people[j]).getStatus();
            int currPersonLoc = (*(people[j])).getLoc();


            (*people[j]).moveLoc(locMap); //Current person attempts to move

            if(currPersonStatus != 2) { //Check if the current person is an unalert person (since their action does nothing)
                if(currPersonStatus == 1 && locMap[currPersonLoc].getNumUnalert() > 0) { //Enter if statement the current person is an alert person and there are unalert people to interact with
                    Person* randPerson = locMap[currPersonLoc].randPerson(currPersonStatus); //Grab a random unalert person in the alert person's location
                    int randPersonID = (*randPerson).getID(); //Get the ID of the random person
                    (*people[j]).action(randPerson, locMap[currPersonLoc]); //Unalert person tries to convince the unalert person the apocalypse is happening
                    people[randPersonID] = randPerson; //Have the pointer in the person vector point to pointer of random person
                } else if (currPersonStatus == 0 && (locMap[currPersonLoc].getNumUnalert() > 0 || locMap[currPersonLoc].getNumAlert() > 0)) { //Enter if statement the current person is a zombie and there are people they can interact with
                    Person* randPerson = locMap[currPersonLoc].randPerson(currPersonStatus); //Grab a random unalert or alert person in the zombie's location
                    int randPersonID = (*randPerson).getID(); //Get ID of the random person
                    (*people[j]).action(randPerson, locMap[currPersonLoc]); //Zombie attempts to bite the random person
                    people[randPersonID] = randPerson; //Have the pointer in the person vector point to pointer of random person
                }
            }
        }

        //Create a vector for holding the number of people of each type after the last hour of action
        vector<int> numTypes;
        numTypes.push_back(0);
        numTypes.push_back(0);
        numTypes.push_back(0);

        for(int j = 0; j < 4; j++) { //Run for every location in our city
            numTypes[1] += locMap[j].getNumAlert(); //Add the number of alert people at current location to vector
            numTypes[2] += locMap[j].getNumUnalert(); //Add the number of unalert people at current location to vector
        }
        numTypes[0] = 2000 - numTypes[1] - numTypes[2]; //Fimd total number of zombies
        outputFile << i << "," << numTypes[0] << "," << numTypes[1] << "," << numTypes[2] << "," << endl; //Output data for number of each type to output file
        if(numTypes[0] == 2000) { //Check if all the people in our city have been turned into zombies
            break; //Exit simulation early if all people are zombies
        }
    }
}