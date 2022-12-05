
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Day4.h"

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
    parse();

    if(range1_size>=range2_size)
    {
      if(range1_lowerbound<=range2_lowerbound && range1_upperbound>=range2_upperbound)
      {i++;}
    }
    else if (range1_size <= range2_size)
    {
      if(range1_lowerbound>=range2_lowerbound && range1_upperbound<=range2_upperbound)
      {i++;}
    }

  }

  std::cout<<i<<std::endl;
  myfile.close();
}

void part2()
{
  std::ifstream myfile;
  myfile.open ("input.txt");

  while (std::getline(myfile, line))
  {
    parse();

    if(range1_upperbound<range2_lowerbound || range2_upperbound<range1_lowerbound)
    {i++;}
  }
  std::cout<<i<<std::endl;
  myfile.close();
}

void parse()
{
  range1 = line.substr(0, line.find(","));
  range2 = line.substr(line.find(",")+1, line.size());

  range1_lowerbound = range1.substr(0, range1.find("-"));
  range1_upperbound = range1.substr(range1.find("-")+1, range1.size());
  range2_lowerbound = range2.substr(0, range2.find("-"));
  range2_upperbound = range2.substr(range2.find("-")+1, range2.size());

  range1_size = stoi(range1_upperbound)-stoi(range1_lowerbound)+1;
  range2_size = stoi(range2_upperbound)-stoi(range2_lowerbound)+1;
}
