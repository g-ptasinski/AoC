#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct Direction {
    int dx, dy;
};

const std::vector<Direction> _Directions{{0, -1},  {0, 1},  {-1, 0}, {1, 0},
                                         {-1, -1}, {1, -1}, {1, 1},  {-1, 1}};

void part1();
void part2();
std::vector<std::string> processInput();
int searchForWords(const Direction dir, const  std::vector<std::string> board, int letterPos, int i, int j);

const std::string _Word{"XMAS"};

int main ()
{

  part1();
  //part2();
  return 0;
}

void part1()
{
    std::vector<std::string> board = processInput();
    int sum = 0;

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            for(const auto direction : _Directions)
            {
                sum+= searchForWords(direction, board,0,i,j);
            }
        }
    }

    std::cout<<sum<<std::endl;
}

void part2()
{

}

int searchForWords(const Direction dir, const  std::vector<std::string> board, int letterPos, int i, int j)
{
    if(i<0 || i>= board.size() || j<0 || j>=board[0].size())
    {
        return 0;
    }

    if(board[i][j] != _Word[letterPos])
    {
        return 0;
    }
    else
    {
        if(letterPos == 3){return 1;}
        else
        {
            return searchForWords(dir,board, ++letterPos, i+dir.dx, j+dir.dy);
        }

    }

    return 0;
}

std::vector<std::string> processInput()
{
    std::ifstream myfile;
    std::string line;
    myfile.open ("input.txt");

    std::vector<std::string> contents;

    while(std::getline(myfile,line))
    {
        contents.push_back(line);
    }

    myfile.close();

    return contents;
}




