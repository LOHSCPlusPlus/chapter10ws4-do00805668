#include <fstream>

using namespace std;
class Rabbit{
  private:
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
  public:
    Rabbit();
    void printRabbit(ostream &out, int index);
    void readFromUser();
    void readFromFile(ifstream &inFile);
    void changeValid();
    
};