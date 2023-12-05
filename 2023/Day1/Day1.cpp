
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include "Day1.h"
#include <algorithm>

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
      else if()
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
/*
zero
one
two
three
four
six
seven
eigh
nine
*/
