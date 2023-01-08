# ZombieApocalypseSimulation

This final project was a accumulation of the knowledge learned through the data structures course of the Whitworth CS Program.

# How to run the program:
1. Build the project to create the main.exe folder (this code was created and run in the latest version of Visual Studio Code)
2. Run the project (i.e. terminal -> run task -> run)
3. Enter in the following parameters as instructed:
  a.	Number of days (integer)
  b.	Percentage chance of Unalert person being bitten (integer between 0-100)
  c.	Percentage chance of Alert person being bitten (integer between 0-100)
  d.	Percentage chance of Unalert person being convinced about the zombie apocalypse by an Alert person (integer between 0-100)
  e.	Percentage of people in each district (floating point number, 4 districts adding up to approximately 100)
4.	Simulation will run for (number of days * 24) hours.
  a.	For each hour, user must input a key to progress to next hour
  b.	Simulation will stop when either everyone becomes a zombie or simulation reaches end of time limit
5.	After simulation ends, the data for each hour is output to a .csv file


# Things that could be used to improve the design given the knowledge I have now
1. I would look into breaking the 3 different types of people further. For example, I could possibly break down the alert person further into people who possibly become panicked and become more likely to get bit or people who are actively hunting zombies. Breaking down the 3 different types of people further could add some more interesting behavior in the simulation.
2. Possibly look into adding more districts in the city. With only 4 districts, the people can only be spread out so much and with that comes a much quicker simulation than would be anticipated. Adding more districts would allow the people to be spread out more and lead to a more realistic simulation.
3. I would also look into adding more user input before the acutal simulation runs. Adding things such as changing the number of starting people, how many alerts/zombies there are at the beginning, where the alerts/zombies start would allow for some more intersting simulations.
4. Adding in some sort of daily schedules for people who are unalert would be an interesting idea. People who don't know what's going on would go about their day normally, staying in certain areas for long periods of time (i.e. one place for work, one for home, etc.). Adding in a sort of daily schedule would make for a nire realistic simulation.

NOTE: This project was done with classmates at Whitworth. I did not do this project on my own and in order to protect their privacy, I will withold from exposing their names unless they desire.
