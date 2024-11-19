#include "piece_hijas.h"


#include "pieceTextures.h"
#include "chessGame.h"

//?KING
    
    // Override setTexture
    void PKing::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteKing : PieceTextures::blackKing);
        Piece::setTexture();

    }
   void PKing::calcPiecePossibleMoves() {
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    // Movimiento hacia arriba
    if ((piecePos / 8) != 0) {
        int newPos = piecePos - 8;
        if (eraseMovesA(newPos) != 1) { // Verifica que no sea una pieza del mismo color
            getPossibleMoves().push_back(newPos);
        }

        // Diagonal superior izquierda
        if ((piecePos % 8) != 0) {
            newPos = piecePos - 9;
            if (eraseMovesA(newPos) != 1) {
                getPossibleMoves().push_back(newPos);
            }
        }

        // Diagonal superior derecha
        if ((piecePos % 8) != 7) {
            newPos = piecePos - 7;
            if (eraseMovesA(newPos) != 1) {
                getPossibleMoves().push_back(newPos);
            }
        }
    }

    // Movimiento hacia abajo
    if ((piecePos / 8) != 7) {
        int newPos = piecePos + 8;
        if (eraseMovesA(newPos) != 1) {
            getPossibleMoves().push_back(newPos);
        }

        // Diagonal inferior izquierda
        if ((piecePos % 8) != 0) {
            newPos = piecePos + 7;
            if (eraseMovesA(newPos) != 1) {
                getPossibleMoves().push_back(newPos);
            }
        }

        // Diagonal inferior derecha
        if ((piecePos % 8) != 7) {
            newPos = piecePos + 9;
            if (eraseMovesA(newPos) != 1) {
                getPossibleMoves().push_back(newPos);
            }
        }
    }

    // Movimiento hacia los costados
    if ((piecePos % 8) != 0) {
        int newPos = piecePos - 1;
        if (eraseMovesA(newPos) != 1) {
            getPossibleMoves().push_back(newPos);
        }
    }

    if ((piecePos % 8) != 7) {
        int newPos = piecePos + 1;
        if (eraseMovesA(newPos) != 1) {
            getPossibleMoves().push_back(newPos);
        }
    }
}



//?QUEEN

    // Override setTexture
    void PQueen::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteQueen : PieceTextures::blackQueen);
        Piece::setTexture();
    }

    void PQueen::calcPiecePossibleMoves(){
        /**/
        int piecePos{getPosition()};
        getPossibleMoves().clear();
        
        

         // Calcula para caminos de arriba
        for (int i = 1; (piecePos / 8 - i) >= 0; ++i) {
            int newPos = piecePos - 8 * i;

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        
        // Calcula para caminos diagonales hacia arriba a la izquierda
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos - 9 * i;

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        
        }
        // Calcula para caminos diagonales hacia arriba a la derecha
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos - 7 * i;
            
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
            

           
        }

        // Calcula para caminos de abajo
        for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
            int newPos = piecePos + 8 * i;
            
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
            
        }
        // Calcula para caminos diagonales hacia abajo a la izquierda
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos + 7 * i;
            
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }

        
        }
        // Calcula para caminos diagonales hacia abajo a la derecha
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos + 9 * i;
           
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }

        
        }

        // Calcula para los costados
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
                int newPos = piecePos + dir * i;
                
                int eraseResult = eraseMovesA(newPos);

                if (eraseResult == 3 || eraseResult == 2) {
                    getPossibleMoves().push_back(newPos);

                    if (eraseResult == 2) {
                        break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                    }
                } else if (eraseResult == 1) {
                    break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
                }
            }
        }

    }
    

    

//?Rook
  

    // Override setTexture
    void PRook::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteRook : PieceTextures::blackRook);
        Piece::setTexture();
    }

    void PRook::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();
        // Calcula para caminos de arriba
        for (int i = 1;(piecePos / 8 - i) >= 0; ++i) {
            int newPos = piecePos - 8 * i;

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           
        }
        // Calcula para caminos de abajo
        for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
            int newPos = piecePos + 8 * i;
            
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        // Calcula para los costados
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
                int newPos = piecePos + dir * i;
                
                int eraseResult = eraseMovesA(newPos);

                if (eraseResult == 3 || eraseResult == 2) {
                    getPossibleMoves().push_back(newPos);

                    if (eraseResult == 2) {
                        break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                    }
                } else if (eraseResult == 1) {
                    break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
                }

            }
        }

    }

//?BISHOP

    // Override setTexture
    void PBishop::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteBishop : PieceTextures::blackBishop);
        Piece::setTexture();
    // Resto de la implementación...
    }
    void PBishop::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();

       
        
        
        // Calcula para caminos diagonales hacia arriba a la derecha
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos - 7 * i;
            
            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           
        }
        // Calcula para caminos diagonales hacia arriba a la izquierda
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos - 9 * i;

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        // Calcula para caminos diagonales hacia abajo a la izquierda
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos + 7 * i;
            //evalua si se debe añadir como movimiento valido

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           

        
        }
        // Calcula para caminos diagonales hacia abajo a la derecha
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos + 9 * i;

            int eraseResult = eraseMovesA(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        
        }

    }

//?KNIGHT
    // Override setTexture
    void PKnight::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteKnight : PieceTextures::blackKnight);
        Piece::setTexture();
    // Resto de la implementación...
    }

void PKnight::calcPiecePossibleMoves() {
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    // Posibles movimientos relativos del caballo
    std::vector<int> relativeMoves = {-17, -15, -10, -6, 6, 10, 15, 17};

    for (int move : relativeMoves) {
        int newPos = piecePos + move;

        // Verifica límites del tablero
        if (newPos >= 0 && newPos < 64) {
            // Verifica que el movimiento no rompa filas del tablero
            int rowDiff = abs((newPos % 8) - (piecePos % 8));
            if (rowDiff <= 2) {
                int eraseResult = eraseMovesA(newPos);

                if (eraseResult != 1) { // Movimiento válido si no hay una pieza del mismo color
                    getPossibleMoves().push_back(newPos);
                }
            }
        }
    }
}

//?PAWN

    // Implementación de setTexture
    void PPawn::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whitePawn : PieceTextures::blackPawn);
        Piece::setTexture();
        // Resto de la implementación...
    
    }

void PPawn::calcPiecePossibleMoves() {
    int piecePos = getPosition();
    getPossibleMoves().clear();

    // Movimiento hacia adelante depende del color del jugador
    int forwardStep = m_player ? -8 : 8;
    int startRow = m_player ? 6 : 1; // Fila inicial de los peones

    // Movimiento de 1 casilla hacia adelante
    int oneStepPos = piecePos + forwardStep;
    if (eraseMovesA(oneStepPos) == 3) { // Casilla vacía
        getPossibleMoves().push_back(oneStepPos);

        // Movimiento de 2 casillas hacia adelante (solo si es el primer movimiento)
        if (!getGame()->hasPawnMovedTwoSquares() && (piecePos / 8) == startRow) {
            int twoStepPos = piecePos + 2 * forwardStep;
            if (eraseMovesA(twoStepPos) == 3) { // Ambas casillas deben estar libres
                getPossibleMoves().push_back(twoStepPos);

                // Marca que ya se ha movido un peón dos casillas
                getGame()->setPawnMovedTwoSquares(true);
            }
        }
    }

    // Captura en diagonal
    for (int diagStep : {forwardStep - 1, forwardStep + 1}) {
        int diagonalPos = piecePos + diagStep;

        // Verifica que la posición diagonal sea válida y que haya una pieza enemiga
        if (diagonalPos >= 0 && diagonalPos < 64) {
            int rowDiff = abs((diagonalPos % 8) - (piecePos % 8));
            if (rowDiff == 1 && eraseMovesA(diagonalPos) == 2) {
                getPossibleMoves().push_back(diagonalPos);
            }
        }
    }

    // Captura hacia adelante (si hay una pieza enemiga directamente enfrente)
    if (eraseMovesA(oneStepPos) == 2) { // Casilla tiene pieza enemiga
        getPossibleMoves().push_back(oneStepPos);
    }
}

