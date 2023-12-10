
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include "Day2.h"

int main ()
{
  part1();

  return 0;
}

void part1()
{
  std::ifstream myfile;

  myfile.open ("input.txt");
  int ID = 0;

  while (std::getline(myfile, line))
  {
    ID++;

    Game game(ID);
    game.CalculateMaxes(line);

    if(game.is_Possible())
    {
      Sum+=ID;
    }

    iPower+=game.GetPower();
  }

  std::cout<<iPower<<std::endl;
  std::cout<<Sum<<std::endl;


  myfile.close();
}

int   Game::GetGameID()
{
  return ID;
}

int   Game::GetPower()
{
  return Power;
}


bool  Game::is_Possible()
{
  return( (MaxGreen <= GreenAmount) && (MaxRed <= RedAmount) && (MaxBlue <= BlueAmount) );
}

void  Game::CalculateMaxes(std::string line)
{

  MaxGreen  = 0;
  MaxBlue   = 0;
  MaxRed    = 0;

  for(int i = 0; i < line.length() ; i++)
  {
    if(line[i] == 'r' && line[i-1]!='g')
    {
      int TempRed = line[i-2]-'0';

      if(isdigit(line[i-3]))
      {
        TempRed+= 10*(line[i-3]-'0');
      }

      if( TempRed > MaxRed )
      {
        MaxRed = TempRed;
      }
    }

    if(line[i] == 'g')
    {
      int TempGreen = line[i-2]-'0';

      if(isdigit(line[i-3]))
      {
        TempGreen+= 10*(line[i-3]-'0');
      }

      if(TempGreen>MaxGreen)
      {
        MaxGreen = TempGreen;
      }
    }

    if(line[i] == 'b')
    {
      int TempBlue = line[i-2]-'0';

      if(isdigit(line[i-3]))
      {
        TempBlue+= 10*(line[i-3]-'0');
      }

      if(TempBlue>MaxBlue)
      {
        MaxBlue = TempBlue;
      }
    }
  }

  Power = MaxGreen*MaxBlue*MaxRed;

}