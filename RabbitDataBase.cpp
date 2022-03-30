#include "RabbitDataBase.h"
#include <iostream>
#include <fstream>

using namespace std;
RabbitDB::RabbitDB(){
  numRabbits = 0;
}

int RabbitDB::getnum(){
  return numRabbits;
}
void RabbitDB::read() {
    ifstream rabbitFile("rabbits.txt");
    numRabbits = 0;
    while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
  rabbitArray[numRabbits].readFromFile(rabbitFile);
        numRabbits++;
    }
}

void RabbitDB::print(ostream &mout){
  //if (rabbitArray[index].isValid){
    for (int i = 0; i < numRabbits; i++){
      rabbitArray[i].printRabbit(mout, i);
    }
  //}
}

void RabbitDB::save(){
  ofstream outFile("saveRabbit.txt");
  for(int i = 0; i < numRabbits; i++){
    rabbitArray[i].printRabbit(outFile, i);
  }
}

void RabbitDB::remove(int index){
  index--;
  rabbitArray[index].changeValid();
}

void RabbitDB::add(){
  rabbitArray[numRabbits].readFromUser();
  numRabbits++;
}