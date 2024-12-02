

#include "Day1.h"
#include <vector>
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

  sum = 0;
  myfile.open ("input.txt");

  std::vector<int> set1;
  std::vector<int> set2;

  while (std::getline(myfile, line))
  {
    int i = 0;
    std::string aux1 ="";
    std::string aux2 ="";

    while(i<6)
    {
       aux1+=line[i];
       ++i;
    }
    i+=2;
    while(i<13)
    {
       aux2+=line[i];
       ++i;
    }

    set1.push_back(std::stoi(aux1));
    set2.push_back(std::stoi(aux2));

  }

  std::sort(set1.begin(), set1.end());
  std::sort(set2.begin(), set2.end());

  i = 0;

    for(i = 0; i<set1.size(); ++i)
    {
      sum+=abs(set1[i]-set2[i]);
    }

    std::cout<<sum<<std::endl;

  myfile.close();
}

void part2()
{
  std::ifstream myfile;

  sum = 0;
  myfile.open ("input.txt");

  std::vector<int> set1;
  std::map<int,int> frequency;

  while (std::getline(myfile, line))
  {
    int i = 0;
    std::string aux1 ="";
    std::string aux2 ="";

    while(i<6)
    {
       aux1+=line[i];
       ++i;
    }
    i+=2;
    while(i<13)
    {
       aux2+=line[i];
       ++i;
    }

    set1.push_back(std::stoi(aux1));

    if(frequency.find(std::stoi(aux2))!=frequency.end())
    {
      frequency[std::stoi(aux2)]++;
    }
    else
    {
      frequency.insert({std::stoi(aux2), 1});
    }
  }

  i = 0;

    for(i = 0; i<set1.size(); ++i)
    {
      if(frequency.find(set1[i])!=frequency.end())
      {
        sum+= set1[i]*frequency[set1[i]];
      }
    }

    std::cout<<sum<<std::endl;

  myfile.close();
}
