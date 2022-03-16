#include <iostream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;


//FEN
//   k - black K - white
//   rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1


void convert_FEN(string FEN);
uint64_t set_bit(int n, uint64_t bit);

int main()
{
	uint64_t a = 0b0;
	convert_FEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	//           
	return 0;
}

//convert to bitboards
void convert_FEN(string FEN)
{
	uint64_t rBB = 0b0, RBB = 0b0, nBB = 0b0, NBB = 0b0, bBB = 0b0, BBB = 0b0, qBB = 0b0, QBB = 0b0, kBB = 0b0, KBB = 0b0, pBB = 0b0, PBB = 0b0;

	size_t length = FEN.size();
	int check;
	int checkmod = 0;

	for (check = 0; check < length; check++)
	{

		if (FEN[check] == '/')
		{
			checkmod -= 1;
		}

		if (isdigit(FEN[check]))
		{
			char num = FEN[check];
			int skip = num - '1';
			checkmod += skip;
		}

		if (FEN[check] == 'r')
		{
			rBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), rBB);
		}
		if (FEN[check] == 'R')
		{
			RBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), RBB);
		}




		cout << bitset<64>(rBB) << endl;



	}
	return;
}

uint64_t set_bit(int n, uint64_t bit)
{
	return bit | (static_cast<unsigned long long>(1) << n);
}

int writeboard(int board)
{
	int boardstate = 0;

	return boardstate;
}