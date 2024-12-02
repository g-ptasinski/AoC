#include "Day2.h"
#include <string>
#include <vector>

int main ()
{
  part1();
  //part2();
  return 0;
}

int checkSafe(std::vector<int> vec1)
{
  bool descending = ((vec1[1]-vec1[0]) < 0);

  for(int j = 1; j<vec1.size(); ++j)
  {
    if(descending && ((vec1[j]-vec1[j-1]) >= 0) || !descending && ((vec1[j]-vec1[j-1]) <= 0) )\
    {
      return 0;
    }
    if(abs(vec1[j]-vec1[j-1]) > 3)
    {
      return 0;
    }
  }

  return 1;
}

int checkSafe2(std::vector<int> vec1)
{
  bool descending = ((vec1[1]-vec1[0]) < 0);

  for(int j = 0; j<vec1.size(); ++j)
  {
    if(checkSafe(vec1) == 1){return 1;}
    else
    {
      std::vector<int> tempVec = vec1;
      tempVec.erase(tempVec.begin()+j);

      if(checkSafe(tempVec)==1){return 1;}
    }
  }

  return 0;
}

void part1()
{
  std::ifstream myfile;

  myfile.open ("input.txt");

  int i = 0;
  safe = 0;

  while (std::getline(myfile, line))
  {
    std::string num = "";
    std::vector<int> lineVec;

    for(i = 0; i<line.length(); ++i)
    {
      if(line[i]==' ')
      {
        lineVec.push_back(std::stoi(num));
        num = "";
      }
      else
      {
        num+=line[i];
      }
    }
    lineVec.push_back(std::stoi(num));

    safe += checkSafe2(lineVec);

  }

  std::cout<<safe<<std::endl;

  myfile.close();
}

