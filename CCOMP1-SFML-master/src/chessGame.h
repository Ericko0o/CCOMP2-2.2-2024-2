/*
    This header file contains th ChessGame class.
    contains the whole game.
*/

#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "Piece_hijas.h"
using namespace std;

class ChessGame: public sf::Drawable{
private:
    Board board;

    std::array<Piece*, 16> whitePieces;
    std::array<Piece*, 16> blackPieces;

    sf::RectangleShape selectionBorder;
    vector<sf::RectangleShape> possibleMovesSquares;
    
    Piece* selectedPiece; //seguira la pieza seleccionada y la usaremos en todo el codigo sin necesidad de copiar toda la info de la pieza
    /*
    vector<sf::RectangleShape> possibleMovesSquares;
    
    */
    sf::RectangleShape infoRestart;
    string lastMove;
    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;
    

    bool selected;
    bool playerTurn; // true = White , false = Black 
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createSelectSquare();
    void createMovesSquares();
    
    void calcPossibleMoves();
    
    /*
   
    void eraseMoves(Piece*);    
    void checkMate();
    */
    

    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    friend class Piece;
    ChessGame(sf::Color bordL_col, sf::Color bordD_col);
    ~ChessGame(){
        for (int i = 0; i < 16; i++) {
            delete blackPieces[i];
            delete whitePieces[i];
        }
    }

    bool getSelected(){
        return selected;
    }

    bool getMate(){
        return mate;
    }

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();
    //!PRUEBA ERASE

     std::array<int, 16> getPosicionesWhitePieces();
     std::array<int, 16> getPosicionesBlackPieces();

    //void vectorcoy(){
      //  std::array<Piece*, 16> copiaWhitePieces = whitePieces;
      //  std::array<Piece*, 16> copiaBlackPieces = blackPieces;
    //}
    //!


};


#endif