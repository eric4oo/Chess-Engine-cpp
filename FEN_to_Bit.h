#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Boards {

	//piece bitboards
	uint64_t rBB = 0b0, RBB = 0b0, nBB = 0b0, NBB = 0b0, bBB = 0b0, BBB = 0b0, qBB = 0b0, QBB = 0b0, kBB = 0b0, KBB = 0b0, pBB = 0b0, PBB = 0b0;

	//all team pieces + occupied + empty
	uint64_t wB, bB, oB, eB;

	//all attacked spaces
	vector<list<int>> legal_moves;
	

};

void combine_boards(Boards& b);

Boards convert_FEN(string FEN);

uint64_t set_bit(int n, uint64_t bit);