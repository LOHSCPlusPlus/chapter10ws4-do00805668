#include "Rabbit.h"

class RabbitDB{
private:
      enum {MAX_RABBITS = 50};
      Rabbit rabbitArray[MAX_RABBITS];
      int numRabbits;
public:
      RabbitDB();
      int getnum();
      void read();
      void print(ostream &mout);
      void save();
      void remove(int index);
      void add();
};
