#include "Rabbit.h"
#include <iostream>
#include <fstream>
using namespace std;

void Rabbit::printRabbit(ostream &out, int index) {
    if (isValid) {
      out << index +1 << ". "
        << name << ";" << maxWeight << ";" << yearRecognized << ";" << isRare << endl;
      }
}
 void Rabbit::readFromUser(){
   char select;
       if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cout << "Enter rabboit name: ";
    cin.get(name, Rabbit::MAX_CHAR_LEN);
    cin.ignore(100,'\n');
    cout << "Enter max rabbit weight: ";
    cin >> maxWeight;
    cin.ignore(100,'\n');
    cout << "Enter year recognized: ";
    cin >> yearRecognized;
   cin.ignore(100,'\n');
    cout << "Is this rabbit rare(y/n)? ";
    cin >> select;
   if (select == 'y') isRare = true;
   if (select == 'n') isRare = false;
    isValid = true;
 }
void Rabbit::readFromFile(ifstream &inFile){
    inFile.get(name, Rabbit::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> maxWeight;
    inFile.ignore(100,';');
    inFile >> yearRecognized;
    inFile.ignore(100,';');
    inFile >> isRare;
    inFile.ignore(100,'\n');
    isValid = !inFile.eof();
}
void Rabbit::changeValid(){
  if(isValid) isValid = false;
  else if(!isValid) isValid = true;
}
Rabbit::Rabbit(){
      for (int index = 0; index < MAX_CHAR_LEN; index++) {
        name[index] = '\0';
    }
    maxWeight = 0;
    yearRecognized = 0;
    isRare = false;
    isValid = false;
}
