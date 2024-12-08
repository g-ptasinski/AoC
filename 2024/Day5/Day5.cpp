#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void part1();
void part2();

int midElement(std::vector<int> update)
{
    return update[update.size()/2];
}

bool isValid(std::vector<int> update, std::unordered_map<int,std::unordered_set<int>> rules)
{
    auto it = update.begin();

    for(auto const item : update)
    {
        auto j = it;

        while(j < update.end())
        {
            if(rules[*j].find(item) != rules[*j].end())
            {
                return false;
            }
            ++j;
        }

        ++it;
    }
    return true;
}

std::vector<int> stringToVector(std::string update)
{
    std::vector<int> ans;
    

    while(update.size() > 0)
    {
        std::string tmp = update.substr(0, update.find(','));
        ans.push_back(std::stoi(tmp));

        if(update.find(',')==std::string::npos)
        {
            break;
        }

        update = update.substr(update.find(',')+1);
    }

    return ans;
}

std::pair<std::unordered_map<int,std::unordered_set<int>>, std::vector<std::string>> getInstructions( )
{
    std::ifstream myfile;
    std::string line;
    myfile.open ("input.txt");

    std::unordered_map<int,std::unordered_set<int>> instructions;
    std::vector<std::string> update_list;

    while(std::getline(myfile,line) && line.length() != 0)
    {
        std::string key_substr = line.substr(0, line.find('|'));
        std::string value_substr = line.substr(line.find('|')+1);

        int key = std::stoi(key_substr);
        int value = std::stoi(value_substr);

        if(instructions.find(key)!=instructions.end())
        {
            instructions[std::stoi(line)].insert(value);
        }
        else
        {
            instructions.insert({key,{value}});
        }
    }

    while(std::getline(myfile,line))
    {
        update_list.push_back(line);
    }


    myfile.close();

    return {instructions, update_list};
}

int main ()
{

  //part1();
  part2();
  return 0;
}

void part1()
{
    std::unordered_map<int,std::unordered_set<int>> instructionsMap; 
    std::vector<std::string> updates;
    std::vector<int> tmp;

    instructionsMap = getInstructions().first;
    updates = getInstructions().second;

    int sum = 0;

    for(auto const item : updates)
    {
        tmp = stringToVector(item);

        if(isValid(tmp, instructionsMap))
        {
            sum+=midElement(tmp);
        }
    }

    std::cout<<sum<<std::endl;
}

void part2()
{
    std::unordered_map<int,std::unordered_set<int>> instructionsMap; 
    std::vector<std::string> updates;
    std::vector<int> tmp;

    instructionsMap = getInstructions().first;
    updates = getInstructions().second;

    int sum = 0;

    for(auto const item : updates)
    {
        tmp = stringToVector(item);

        if(!isValid(tmp, instructionsMap))
        {
            std::sort(tmp.begin(), tmp.end(), [&]
                (const int & firstElement, const int & secondElement)
            {
                return(instructionsMap[firstElement].find(secondElement)!=instructionsMap[firstElement].end());
            });

            sum+=midElement(tmp);
        }
    }

    std::cout<<sum<<std::endl;
}





