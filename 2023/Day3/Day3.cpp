
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include "Day3.h"


int main ()
{
  part1();
  //part2();
  return 0;
}

void part1()
{
  std::ifstream myfile;
  myfile.open ("input.txt");

  int ID  = 1;
  int Sum = 0;

  ////////////////////////////////////////////////////////////////////////////////
  //EDGE CASE - TOP LINE
  ////////////////////////////////////////////////////////////////////////////////
  std::getline(myfile, line);
  std::getline(myfile, line_bottom);

  int iPartNumber        = 0;
  int increment          = 1;

  for(int i = 0; i<line.length(); i+=std::to_string(iPartNumber).length())
  { 
    if(isdigit(line[i]))
    {
      iPartNumber = IdentifyPartNumber(line[i], line, i);
      increment = std::to_string(iPartNumber).length();
      
      if(IsAdjacent(line, line_bottom))
      {
        Sum+=iPartNumber;
      }
    }

  }

  line_top = line;
  line = line_bottom;
  
  ////////////////////////////////////////////////////////////////////////////////
  //END OF EDGE CASE
  ////////////////////////////////////////////////////////////////////////////////
  
  while (std::getline(myfile, line_bottom))
  {
      int iPartNumber = 0;
      int increment   = 1;

        for(int i = 0; i<line.length(); i+=increment)
        { 
          if(isdigit(line[i]))
          {
            iPartNumber = IdentifyPartNumber(line[i], line, i);
            increment = std::to_string(iPartNumber).length();
            
          }
          else
          increment = 1;
        }
  
        if(ID = 140)
        {
          if(IsAdjacent(line, line_top))
          {
            Sum+=iPartNumber;
          }  
        }
        else if(IsAdjacent(line, line_bottom) || IsAdjacent(line, line_top))
        {
          Sum+=iPartNumber;
        }
      
      
      line_top = line;
      line = line_bottom;
  }
}




int IdentifyPartNumber(char firstdigit, std::string line, std::size_t index)
{
  return std::__cxx11::stoi(line, index);
}

bool IsAdjacent(std::string line, std::string bottomline )
{
  return true;
}
