#include <iostream>
#include <ctime>
#include "simulator.h"

using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main () {
    srand(time(NULL));
    Simulator zombieApoc;
    zombieApoc.runSimulator();
}