#include "chessRules.h"

bool ChessRules::isCheck(const std::vector<Piece*>& playerPieces, const std::vector<Piece*>& opponentPieces, int kingPosition) {
    for (const auto& opponentPiece : opponentPieces) {
        if (opponentPiece->getPosition() == -1) continue; // Pieza capturada
        const auto& moves = opponentPiece->getPossibleMoves();
        if (std::find(moves.begin(), moves.end(), kingPosition) != moves.end()) {
            return true; // El rey está amenazado
        }
    }
    return false;
}

bool ChessRules::isCheckmate(const std::vector<Piece*>& playerPieces, const std::vector<Piece*>& opponentPieces) {
    // Buscar la posición del rey del jugador
    int kingPosition = -1;
    for (const auto& piece : playerPieces) {
        if (piece->getType() == 'K') {
            kingPosition = piece->getPosition();
            break;
        }
    }

    // Si el rey no está en jaque, no puede haber jaque mate
    if (!isCheck(playerPieces, opponentPieces, kingPosition)) {
        return false;
    }

    // Verificar si existe algún movimiento legal para el jugador
    for (auto& piece : playerPieces) {
        if (piece->getPosition() == -1) continue; // Pieza capturada

        // Filtrar movimientos legales para esta pieza
        filterIllegalMoves(piece, playerPieces, opponentPieces);
        if (!piece->getPossibleMoves().empty()) {
            return false; // Hay al menos un movimiento legal
        }
    }

    // No hay movimientos legales y el rey está en jaque: jaque mate
    return true;
}

void ChessRules::filterIllegalMoves(Piece* piece, const std::vector<Piece*>& playerPieces, const std::vector<Piece*>& opponentPieces) {
    std::vector<int> legalMoves;
    int originalPosition = piece->getPosition();

    for (int move : piece->getPossibleMoves()) {
        piece->setPosition(move); // Simular movimiento

        // Buscar el rey del jugador
        int kingPosition = -1;
        for (const auto& p : playerPieces) {
            if (p->getType() == 'K') {
                kingPosition = p->getPosition();
                break;
            }
        }

        // Verificar si el rey sigue seguro
        if (!isCheck(playerPieces, opponentPieces, kingPosition)) {
            legalMoves.push_back(move);
        }
    }

    piece->setPosition(originalPosition); // Restaurar posición original
    piece->getPossibleMoves() = legalMoves; // Actualizar movimientos legales
}
