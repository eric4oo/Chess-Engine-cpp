#include"FEN_to_Bit.h"
#include"get_attacks.h"
#include <iostream>
#include <string>
#include <bitset>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

void get_legal_moves(Boards& bitboard)
{
	bitset<64> occ = bitboard.oB;
	//                  0       1      2       3       4        5      6      7     8      9     10    11    
	enum PieceType { rook = 0, Rook, knight, Knight, bishop, Bishop, queen, Queen, king, King, pawn, Pawn };
	PieceType piece;
	int pRank = 0;
	int pFile = 0;

	for (int i = 0; i < 64; i++)
	{
		if (occ.test(i) == 1)
		{
			uint64_t empty_board = 0b0;
			empty_board = set_bit(i, empty_board);
			
			if (empty_board == (bitboard.rBB & empty_board))
				piece = PieceType::rook;
			if (empty_board == (bitboard.RBB & empty_board))
				piece = PieceType::Rook;
			if (empty_board == (bitboard.nBB & empty_board))
				piece = PieceType::knight;
			if (empty_board == (bitboard.NBB & empty_board))
				piece = PieceType::Knight; 
			if (empty_board == (bitboard.bBB & empty_board))
				piece = PieceType::bishop; 
			if (empty_board == (bitboard.BBB & empty_board))
				piece = PieceType::Bishop; 
			if (empty_board == (bitboard.qBB & empty_board))
				piece = PieceType::queen;  
			if (empty_board == (bitboard.QBB & empty_board))
				piece = PieceType::Queen;  
			if (empty_board == (bitboard.kBB & empty_board))
				piece = PieceType::king;   
			if (empty_board == (bitboard.KBB & empty_board))
				piece = PieceType::King;   
			if (empty_board == (bitboard.pBB & empty_board))
				piece = PieceType::pawn;   
			if (empty_board == (bitboard.PBB & empty_board))
				piece = PieceType::Pawn;

			pRank = i / 8;
			pFile = i % 8;
			if (piece == PieceType::Rook)
			{
				uint64_t rookattacks = rookSlider(bitboard, pRank, pFile);
				//cout << bitset<64>(rookattacks) << endl;
			}


		}

	}






	//bitboard.legal_moves.push_back({0,1});
}

//these functions return movable spaces including attacks per piece
uint64_t rookSlider(Boards& bitboard, int rank, int file)
{
	uint64_t empty_board = 0b0;
	//look at horz
	uint64_t horzboard = bitboard.oB >> rank * 8;
	uint64_t horzOccu = horzboard & 0xFF;
	uint64_t horzSlider = 0b0 | (1 << (7 - file));

	cout << bitset<8>(horzOccu) << endl;
	cout << bitset<8>(horzSlider) << endl;
	cout << bitset<8>(horzOccu ^ (horzOccu - 2 * horzSlider)) << endl;
	cout << bitset<8>(horzSlider).flip() << endl;
	//need to make reverse func


	empty_board = empty_board | ((horzOccu - 2 * horzSlider) ^ ~(~horzOccu - ~(2 * horzSlider)));


	return empty_board;
}

uint64_t bishopSlider(Boards& bitboard, int rank, int file)
{
	return 0;
}

uint64_t pawnAttack(Boards& bitboard)
{
	return 0;
}

bool move_is_pinned(Boards& bitboard)
{
	return false;
}

bool move_checks(Boards& bitboard)
{
	return false;
}
