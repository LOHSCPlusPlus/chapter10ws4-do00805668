#include "RabbitDataBase.h"
#include "ReadUtils.h"
#include <iostream>
using namespace std;


const int MAX_MENU_LEN = 70;
void printMenu(char options[][MAX_MENU_LEN], int numEntries) {
    for (int index = 0; index < numEntries; index++) {
        cout << (index + 1) << ") " << options[index] << endl;
    }
}

// Interact with the database functions using a menu to choose what to do
int main() {
    RabbitDB rabbit; 
    int option = 0;
    int ff;
    int num = rabbit.getnum();
    char menuOptions[][MAX_MENU_LEN]={  "Print rabbit list",
                                        "Save list to file",
                                        "Remove rabbit",
                                        "Add rabbit",
                                        "Quit"};
    rabbit.read();
    do {
        printMenu(menuOptions,5);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                rabbit.print(cout);
              cout << endl;
                break;
            case 2:
                rabbit.save();
                break;
            case 3:
              cout << "Which index to break: ";
              cin >> ff;
                rabbit.remove(ff);
                break;
            case 4:
                rabbit.add();
                num++;
                break;
            case 5:
                break;
            default:
                cout << "Invalid option, try again" << endl;
                break;
        }
    }while(option != 5);
    
    return 0;
}
