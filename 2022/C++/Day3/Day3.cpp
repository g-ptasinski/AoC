
#include <iostream>
#include <fstream>
#include <string>
#include "Day3.h"
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

    match_found = 0;

    for(int j=0; j<comp1.size(); j++)
    {
      if(!match_found)
      {for(int z=0; z<comp2.size(); z++)
        {
          if(comp1[j]==comp2[z])
          {
            if(static_cast<int>(comp1[j])>95)
            {total_value+=(static_cast<int>(comp1[j]) - 96);}
            else
            {total_value+=(static_cast<int>(comp1[j]) - 38);}
            match_found=1;
            break;
          }
        }
      }
      else
      break;
    }
  }
  cout<<total_value<<endl;
  myfile.close();
}

void part2()
{
  ifstream myfile;
  myfile.open ("input.txt");

  while (std::getline(myfile, line1))
  {
    std::getline(myfile, line2);
    std::getline(myfile, line3);
    i+=3;

    match_found_1 = 0;
    match_found_2 = 0;

    for(int j=0; j<line1.size(); j++)
    {
      if(!match_found_1)
      {for(int z=0; z<line2.size(); z++)
        {
          if(line1[j]==line2[z])
          {
            if(!match_found_2)
            {
              for(int x=0; x<line3.size(); x++)
              {if(line2[z]==line3[x])
                {
                if(static_cast<int>(line1[j])>95)
                {total_value+=(static_cast<int>(line1[j]) - 96);}
                else
                {total_value+=(static_cast<int>(line1[j]) - 38);}
                match_found_2=1;
                break;
                }
              }
            }
            else break;
          }
        }
      }
    }
    //cout<<line1<<endl<<line2<<endl<<line3<<endl<<i<<endl;
  }
  cout<<total_value<<endl;
  myfile.close();

}

void parse()
{
  comp1 = line.substr(0, line.size()/2);
  comp2 = line.substr(line.size()/2, line.size());
}
