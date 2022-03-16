#pragma once
#include <iostream>
#include <string>
#include "FEN_to_Bit.h"

using namespace std;

void get_legal_moves(Boards& bitboard);

bool move_is_pinned(Boards& bitboard);

bool move_checks(Boards& bitboard);

//Files, Ranks, Diagonals

uint64_t A_file = 0x0101010101010101ULL;
uint64_t B_file = A_file << 1;
uint64_t C_file = A_file << 2;
uint64_t D_file = A_file << 3;
uint64_t E_file = A_file << 4;
uint64_t F_file = A_file << 5;
uint64_t G_file = A_file << 6;
uint64_t H_file = A_file << 7;

uint64_t Rank_1 = 0xFF;
uint64_t Rank_2 = Rank_1 << (8 * 1);
uint64_t Rank_3 = Rank_1 << (8 * 2);
uint64_t Rank_4 = Rank_1 << (8 * 3);
uint64_t Rank_5 = Rank_1 << (8 * 4);
uint64_t Rank_6 = Rank_1 << (8 * 5);
uint64_t Rank_7 = Rank_1 << (8 * 6);
uint64_t Rank_8 = Rank_1 << (8 * 7);



