#ifndef CHESS_RULES_H
#define CHESS_RULES_H

#include "piece.h"
#include <vector>

class ChessRules {
public:
    static bool isCheck(const std::vector<Piece*>& playerPieces, const std::vector<Piece*>& opponentPieces, int kingPosition);
    static void filterIllegalMoves(Piece* piece, const std::vector<Piece*>& playerPieces, const std::vector<Piece*>& opponentPieces);
};

#endif // CHESS_RULES_H
