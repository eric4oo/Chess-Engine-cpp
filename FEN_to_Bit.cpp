#include"FEN_to_Bit.h"
#include <iostream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;


Boards convert_FEN(string FEN)
{
	size_t length = FEN.size();
	int check;
	bool hasSeen = false;
	int built = 0;
	int checkmod = 0;
	Boards all_bitboards;

	for (check = 0; check < length; check++)
	{

		if (FEN[check] == '/')
		{
			checkmod -= 1;
			built += 1;
		}

		if (isdigit(FEN[check]))
		{
			char num = FEN[check];
			int skip = num - '1';
			checkmod += skip;
		}
		if (FEN[check] == ' ')
		{
			hasSeen = true;
		}

		if (!hasSeen)
		{
			if (FEN[check] == 'r')
				all_bitboards.rBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.rBB);

			if (FEN[check] == 'R')
				all_bitboards.RBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.RBB);

			if (FEN[check] == 'n')
				all_bitboards.nBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.nBB);

			if (FEN[check] == 'N')
				all_bitboards.NBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.NBB);

			if (FEN[check] == 'b')
				all_bitboards.bBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.bBB);

			if (FEN[check] == 'B')
				all_bitboards.BBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.BBB);

			if (FEN[check] == 'q')
				all_bitboards.qBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.qBB);

			if (FEN[check] == 'Q')
				all_bitboards.QBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.QBB);

			if (FEN[check] == 'k')
				all_bitboards.kBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.kBB);

			if (FEN[check] == 'K')
				all_bitboards.KBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.KBB);

			if (FEN[check] == 'p')
				all_bitboards.pBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.pBB);

			if (FEN[check] == 'P')
				all_bitboards.PBB = set_bit(64 - check - checkmod - 8 + 2 * ((check + checkmod) % 8), all_bitboards.PBB);
		}


	}
	cout << "FEN conversion completed" << endl;

	return all_bitboards;
}

void combine_boards(Boards& b)
{
	b.wB = b.RBB ^ b.NBB ^ b.BBB ^ b.QBB ^ b.KBB ^ b.PBB;
	cout << "White bitboard done" << endl;

	b.bB = b.rBB ^ b.nBB ^ b.bBB ^ b.qBB ^ b.kBB ^ b.pBB;
	cout << "Black bitboard done" << endl;

	b.oB = b.wB ^ b.bB;
	cout << "Occupied bitboard done" << endl;

	b.eB = ~b.oB;
	cout << "Empty bitboard done" << endl;
}


uint64_t set_bit(int n, uint64_t bit)
{
	uint64_t one = 1;
	return bit | (one << n);
}