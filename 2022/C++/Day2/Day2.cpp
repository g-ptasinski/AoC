
#include <iostream>
#include <fstream>
#include <string>
#include "Day2.h"
using namespace std;

int main ()
{
  //part1();
  part2();
  return 0;
}

void part1()
{
  ifstream myfile;
  myfile.open ("input.txt");

  while (std::getline(myfile, line))
  {
    i++;
    parse();

    if     ( hands_outcome ==  0)                       {value_of_outcome=3;}
    else if( hands_outcome == -2 || hands_outcome ==  1){value_of_outcome=6;}
    else if( hands_outcome ==  2 || hands_outcome == -1){value_of_outcome=0;}
    else {std::cerr<<"Wrong input at line "<< i <<endl;}

    total_score+=value_of_hand2+value_of_outcome;
  }

  cout<<total_score;

  myfile.close();
}

void part2()
{
  ifstream myfile;
  myfile.open ("input.txt");

  while (std::getline(myfile, line))
  {
    i++;
    parse();

    value_of_outcome = (value_of_hand2-1)*3;
    switch(value_of_outcome)
    {
    case 0: //LOSE
    if     (value_of_hand1 == 1){value_of_hand2_changed = 3;}
    else if(value_of_hand1 == 2){value_of_hand2_changed = 1;}
    else if(value_of_hand1 == 3){value_of_hand2_changed = 2;}
    break;
    case 3: //DRAW
    value_of_hand2_changed = value_of_hand1;
    break;
    case 6: //WIN
    if     (value_of_hand1 == 1){value_of_hand2_changed = 2;}
    else if(value_of_hand1 == 2){value_of_hand2_changed = 3;}
    else if(value_of_hand1 == 3){value_of_hand2_changed = 1;}
    break;
    default:
    break;
    }
    total_score+=value_of_hand2_changed+value_of_outcome;
  }
  myfile.close();

  cout<<total_score;
}

void parse()
{
  hand1 = line.substr(0, line.find(delimiter));
  hand2 = line.substr(line.find(delimiter)+1, line.size());

  value_of_hand2 = static_cast<int>(hand2[0]) - 87;
  value_of_hand1 = static_cast<int>(hand1[0]) - 64;

  hands_outcome = value_of_hand2-value_of_hand1;
}
