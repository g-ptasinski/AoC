void part1();
void part2();
void parse();

std::string line;
std::string delimiter = " ";
size_t pos  = 0;

std::string hand1;
std::string hand2;

int value_of_hand1;
int value_of_hand2;
int value_of_hand2_changed;

int value_of_outcome;
int total_value_of_the_round;
int total_score;
int hands_outcome;

int score   = 0;

int i=0;

/*
ASCII VALUES:

A - 65 | X - 88 ROCK      1
B - 66 | Y - 89 PAPER     2
C - 67 | Z - 90 SCISSORS  3
_________________________________
ROCK
HAND2 - HAND1 = 0 (DRAW) 3pts
HAND2 - HAND1 = -1 (LOSE) 0pts
HAND2 - HAND1 = -2 (WIN)  6pts
_________________________________
PAPER:
HAND2 - HAND1 = 0 (DRAW) 3pts
HAND2 - HAND1 = -1 (LOSE) 0pts
HAND2 - HAND1 = 1 (WIN)  6pts
_________________________________
SCISSORS:
HAND2 - HAND1 = 0 (DRAW) 3pts
HAND2 - HAND1 = 2 (LOSE) 0pts
HAND2 - HAND1 = 1 (WIN)  6pts
_________________________________

WIN -2; 1
LOSE 2;-1
DRAW 0


X - 0
Y - 3
Z - 6
*/
