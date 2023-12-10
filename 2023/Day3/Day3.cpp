
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

  int ID = 1;
  int Sum = 0;

  ////////////////////////////////////////////////////////////////////////////////
  //EDGE CASE - TOP LINE
  ////////////////////////////////////////////////////////////////////////////////
  std::getline(myfile, line);
  std::getline(myfile, line_bottom);

  for(int i = 0; i<line.length(); i++)
  { 
    if(isdigit(line[i]))
    {
      int iPartNumber = IdentifyPartNumber(line[i], line, i);
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

    for(int i = 0; i<line.length(); i++)
    { 
      for(int i = 0; i<line.length(); i++)
      { 
        if(isdigit(line[i]))
        {
          int iPartNumber = IdentifyPartNumber(line[i], line, i);
          
          if(IsAdjacent(line, line_bottom, line_top))
          {
            Sum+=iPartNumber;
          }

        }
      }

      if(ID = 140)
      {
        if(IsAdjacent(line, line_top))
        {
        Sum+=iPartNumber;
        }  
      }
      else if(IsAdjacent(line, line_bottom) || IsAdjacent(line, line_top)
      {
        Sum+=iPartNumber;
      }
    }

    
    line_top = line;
    line = line_bottom;
  }

}

void part2()
{

}

double IdentifyPartNumber(int firstdigit, std::string line, int index)
{

}
