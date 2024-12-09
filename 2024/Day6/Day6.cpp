#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

std::vector<std::pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1} };

void walk(int directionnum, int &sum, std::vector<std::string> &board, int i, int j)
{
    if(directionnum > 3){directionnum = 0;}

    std::pair<int,int> dir = directions[directionnum];

    if(i>board.size()-1 || j>board[0].size()-1 || i < 0 || j < 0)
    {
        return;
    }

    if(board[i][j] != '#')
    {
        if(board[i][j] != 'X')
        {
            ++sum;
            board[i][j] = 'X';
        }
        walk(directionnum, sum, board, i+dir.first, j+dir.second);
    }
    else
    {
        walk(directionnum+1, sum, board, i-dir.first, j-dir.second);
    }
}

void walk2(int directionnum, int &sum, std::vector<std::string> &board, int i, int j, std::set<std::pair<int,int>> &hashset)
{
    if(directionnum > 3){directionnum = 0;}

    std::pair<int,int> dir = directions[directionnum];
    char symbol = 'X';

    switch(directionnum)
    {

        case 0:
            symbol = 'U';
        break;
        case 1:
            symbol = 'R';
        break;
        case 2:
            symbol = 'D';
        break;
        case 3:
            symbol = 'L';
        break;

        default:
        break;
    }

    if(i>board.size()-1 || j>board[0].size()-1 || i < 0 || j < 0)
    {
        return;
    }

    if(board[i][j] != '#')
    {
        if(board[i][j] == '.' || board[i][j] == '^' )
        {
            board[i][j] = symbol;
        }

        switch(directionnum)
        {
                int x;
                //UP
                case 0:

                    x = j+1;

                    while(x < board[0].size())
                    {
                        if(board[i][x]=='R')
                        {
                            hashset.insert({i+dir.first, j+dir.second});
                            break;
                        }
                        else if(board[i][x]=='#')
                        {
                            break;
                        }
                        ++x;
                    }

                break;
                //RIGHT
                case 1:

                    x = i+1;

                    while(x < board.size())
                    {
                        if(board[x][j]=='D')
                        {
                            hashset.insert({i+dir.first, j+dir.second});
                            break;
                        }
                        else if(board[x][j]=='#')
                        {
                            break;
                        }
                        ++x;
                    }

                break;
                //DOWN
                case 2:

                    x = j-1;

                    while(x >= 0)
                    {
                        if(board[i][x]=='L')
                        {
                            hashset.insert({i+dir.first, j+dir.second});
                            break;
                        }
                        else if(board[i][x]=='#')
                        {
                            break;
                        }
                        --x;
                    }

                break;
                //LEFT
                case 3:

                    x = i-1;

                    while(x >= 0)
                    {
                        if(board[x][j]=='U')
                        {
                            hashset.insert({i+dir.first, j+dir.second});
                            break;
                        }
                        else if(board[x][j]=='#')
                        {
                            break;
                        }
                        --x;
                    }

                break;

                default:
                break;
        }

        
        walk2(directionnum, sum, board, i+dir.first, j+dir.second, hashset);
    }
    else
    {
        walk2(directionnum+1, sum, board, i-dir.first, j-dir.second, hashset);
    }
}

std::vector<std::string> processInput( )
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

void part1()
{
    std::vector<std::string> board = processInput();
    int sum = 0;

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == '^')
            {
                walk(0, sum, board,i,j);    
            }
            
        }
    }

    std::cout<<sum<<std::endl;
}

void part2()
{
    std::vector<std::string> board = processInput();
    std::set<std::pair<int,int>> hashset;

    int sum = 0;

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == '^')
            {
                walk2(0 ,sum ,board ,i ,j , hashset);    
            }
            
        }
    }

    std::cout<<hashset.size()<<std::endl;
}

int main ()
{

  //part1();
  part2();
  return 0;
}






