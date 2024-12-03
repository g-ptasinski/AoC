#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

void part1();
void part2();
std::string processInput();
std::string parsePart2(std::string contents);

int main ()
{

  part1();
  part2();
  return 0;
}

void part1()
{
    std::string contents = processInput();

    int score = 0;
    std::smatch match;
    std::string parsedMatch;
    std::regex e ("mul\\(\\d+,\\d+\\)");

    while (regex_search(contents, match, e))
    {
      std::string strMatch = match.str();
      strMatch = strMatch.substr(4);

      std::istringstream ss (strMatch);
      std::string number1_str;
      std::string number2_str;

      std::getline(ss, number1_str, ',');
      std::getline(ss, number2_str, ')');
      score += std::stol(number1_str)*std::stol(number2_str);

      contents = match.suffix();
    }

    std::cout<<score<<std::endl;
}

void part2()
{
    std::string contents = processInput();

    int score = 0;
    std::smatch match;
    std::regex e ("mul\\([0-9]*,[0-9]*\\)|do\\(\\)|don't\\(\\)");
    bool enable = true;

    while (regex_search(contents, match, e))
    {
      std::string strMatch = match.str();

      if(strMatch == "don't()"){enable = false;}
      else if(strMatch == "do()"){enable = true;}
      else
      {
       if(enable)
       {
          strMatch = strMatch.substr(4);

          std::istringstream ss (strMatch);
          std::string number1_str;
          std::string number2_str;

          std::getline(ss, number1_str, ',');
          std::getline(ss, number2_str, ')');

          score += std::stol(number1_str)*std::stol(number2_str);
       }
      }


      contents = match.suffix();
    }

    std::cout<<score<<std::endl;
}


std::string processInput()
{
  std::ifstream myfile;
  std::stringstream buffer;

  myfile.open ("input.txt");

  buffer << myfile.rdbuf();
  std::string contents = buffer.str();

  myfile.close();

  return contents;
}




