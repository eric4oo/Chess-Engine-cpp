#pragma once
#include <iostream>
#include <string>
#include "FEN_to_Bit.h"

using namespace std;

void get_legal_moves(Boards& bitboard);

uint64_t rookSlider(Boards& bitboard, int rank, int file);

uint64_t bishopSlider(Boards& bitboard, int rank, int file);

uint64_t pawnAttack(Boards& bitboard);

bool move_is_pinned(Boards& bitboard);

bool move_checks(Boards& bitboard);

//Files, Ranks, Diagonals


//Sliders






