#include <map>

void part1();
void part2();
int 	IdentifyPartNumber(char firstdigit, std::string line, std::size_t index);
bool   	IsAdjacent(std::string line, std::string bottomline );



std::string line;
std::string line_top;
std::string line_bottom;
std::string ch;

std::string strPartNumber =""; 

int sum = 0;
int tens= 0;
int ones= 0;
int i=0;

//
class PartNumber{

public:

	PartNumber(){};
	~PartNumber(){};

private: 

};