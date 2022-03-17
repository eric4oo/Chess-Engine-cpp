#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
#include "FEN_to_Bit.h"
#include "get_attacks.h"
#include <vector>

using namespace std;


//FEN
//   k - black K - white
//   rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1

int main()
{
	Boards all_bitboards = convert_FEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	combine_boards(all_bitboards);
	get_legal_moves(all_bitboards);






	//show occupied board
	bitset<64> occ = all_bitboards.oB;
	bitset<64> wh = all_bitboards.wB;
	bitset<64> bl = all_bitboards.bB;

	cout << endl;
	cout << "white spaces" << endl;
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			cout << endl;
		cout << wh.test(63 - i - 7 + 2 * (i%8));
	}
	cout << endl << endl;
	cout << "black spaces" << endl;
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			cout << endl;
		cout << bl.test(63 - i - 7 + 2 * (i % 8));
	}
	cout << endl << endl;
	cout << "occupied spaces" << endl;
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			cout << endl;
		cout << occ.test(63 - i - 7 + 2 * (i % 8));
	}
		cout << endl;

	return 0;
}

int writeboard(int board)
{
	int boardstate = 0;

	return boardstate;
}