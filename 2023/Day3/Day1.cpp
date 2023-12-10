
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include "Day1.h"
#include <map>

int main ()
{
  //part1();
  part2();
  return 0;
}

void part1()
{
  std::ifstream myfile;

  myfile.open ("input.txt");

  while (std::getline(myfile, line))
  {
    for (std::string::size_type i = 0; i < line.size(); i++)
    {
      if(isdigit(line[i]))
        {
          tens = line[i]-48;
          break;
        }
    }
    for (std::string::size_type i = line.size(); i >= 0 ; i--)
    {
      if(isdigit(line[i]))
      {
          ones = line[i]-48;
          break;
        }
    }

    sum+=10*tens+ones;
  }
  std::cout<<sum<<std::endl;
  myfile.close();
}

void part2()
{
    std::string Numbers[9] =
   {"one","two","three",
   "four","five","six",
   "seven","eight","nine"};

  std::map<std::string, int> NumValues = 
  { 
     {"one",1},{"two",2},{"three",3},
     {"four",4},{"five",5},{"six",6},
     {"seven",7},{"eight",8},{"nine",9} 
  };

  std::ifstream myfile;

  myfile.open ("input.txt");

  std::pair<std::string ,int> MinNum = {"test", 80000 };
  std::pair<std::string ,int> MaxNum = {"test", -1 };  
  
  while (std::getline(myfile, line))
  {
    MinNum = {"test", 80000 };
    MaxNum = {"test", 0 };  

    ones = 0;
    tens = 0;

    int iOnesIndex = 0;
    int iTensIndex = 0;

    for(auto &element : Numbers)
    {
      auto found = line.find(element);
      auto found2= line.rfind(element);

      if (found!=std::string::npos && found < MinNum.second )
        {
           MinNum = ( std::pair<std::string ,int>(element,found) );
        }

      if (found2!=std::string::npos && found2 >= MaxNum.second )
        {
           MaxNum = ( std::pair<std::string ,int>(element,found2)  );
        }
    }

    for (std::string::size_type i = 0; i < line.size(); i++)
    {
      if(isdigit(line[i]))
        {
          tens = line[i]-48;
          iTensIndex = i;
          break;
        }
    }
    for (std::string::size_type i = line.size(); i >= 0 ; i--)
    {
      if(isdigit(line[i]))
      {
          ones = line[i]-48;
          iOnesIndex = i;
          break;
      }
    }
  
    if(MinNum.first!="test")
    {  
        (iTensIndex < MinNum.second) ? (tens=tens) : (tens=NumValues.at(MinNum.first));
    }

    if(MaxNum.first!="test")
    {  
        (iOnesIndex > MaxNum.second) ? (ones=ones) : (ones=NumValues.at(MaxNum.first));
    }
    sum+=10*tens+ones;
  }
  std::cout<<sum<<std::endl;
  myfile.close();
}
