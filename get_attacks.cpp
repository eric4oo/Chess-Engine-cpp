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

		}

	}






	//bitboard.legal_moves.push_back({0,1});
}

bool move_is_pinned(Boards& bitboard)
{
	return false;
}

bool move_checks(Boards& bitboard)
{
	return false;
}
