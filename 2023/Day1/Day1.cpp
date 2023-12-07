
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
  std::ifstream myfile;

  myfile.open ("input.txt");

  ones = 0;
  tens = 0;

  int iTensString = 0;
  int iOnesString = 0;
   
  std::map<std::string, int> Nums = {};
  
  while (std::getline(myfile, line))
  {
    for(auto &element : Numbers)
    {
      std::size_t found = line.find(element);
      if (found!=std::string::npos)
        {
           Nums.insert ( std::pair<std::string ,int>(element,found) );
        }
    }
    

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
/*
    auto min = min_element(Nums.begin(), Nums.end(),
                      [](decltype(Nums)::value_type& l, decltype(Nums)::value_type& r) -> bool { return l.second < r.second; });

    auto max = max_element(Nums.begin(), Nums.end(),
                      [](decltype(Nums)::value_type& l, decltype(Nums)::value_type& r) -> bool { return l.second > r.second; });

    std::cout<<min.first<<" "<<min.second;
*/
    (tens>iTensString) ? (tens=tens) : (tens=iTensString);
    (tens>iTensString) ? (tens=tens) : (tens=iTensString);

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
eight
nine
*/
