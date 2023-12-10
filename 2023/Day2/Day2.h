#include <map>

void part1();
void part2();

std::string line;
std::string ch;

int Sum = 0;

int RedAmount 	= 12;
int BlueAmount  = 14;   
int GreenAmount = 13;
int iPower 	 	= 0;


class Game 
{

  public:

  Game(char identifier)
  {
  	ID = identifier;
  };

  ~Game(){};

  int 	GetGameID();
  int 	GetPower();
  bool 	is_Possible();
  void 	CalculateMaxes(std::string);

  private:

  int ID 		= 0;
  int MaxGreen 	= 0;
  int MaxBlue  	= 0;
  int MaxRed   	= 0;

  int Power = 0;

};