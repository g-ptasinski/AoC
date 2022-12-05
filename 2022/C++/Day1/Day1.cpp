
#include <iostream>
#include <fstream>
#include "Day1.h"
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
    if(line!=""){current_elf+=stoi(line);
    }
    else
    {
      if(current_elf>biggest_elf)
      {
        biggest_elf=current_elf;
      }
      current_elf=0;
    }
  }
  cout<<biggest_elf<<endl;
  myfile.close();
}

void part2()
{
  ifstream myfile;
  myfile.open ("input.txt");

  while (std::getline(myfile, line))
  {
    if(line!=""){current_elf+=stoi(line);
    }
    else
    {
      if(current_elf>biggest_elf)
      {
        smallest_elf=middle_elf;
        middle_elf = biggest_elf;
        biggest_elf=current_elf;
      }
      else if(current_elf>middle_elf)
      {
        smallest_elf=middle_elf;
        middle_elf = current_elf;
      }
      else if(current_elf>smallest_elf)
      {
        smallest_elf=current_elf;
      }
      current_elf=0;
    }
  }
  cout<<biggest_elf+middle_elf+smallest_elf<<endl;
  myfile.close();
}
