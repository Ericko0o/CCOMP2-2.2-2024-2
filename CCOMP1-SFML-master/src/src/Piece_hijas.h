#ifndef _PIECE_HIJAS_H
#define _PIECE_HIJAS_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "piece.h"
#include "board.h"
#include "chessGame.h"

using namespace std;


class PKing : public Piece {
public:
    PKing(bool player, int pos) : Piece('K', player, pos) {
        setPiece('K', player, pos, false);
    }

    // Override setTexture
    void setTexture() override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  }

};


class PQueen : public Piece {
public:

   
    PQueen(bool player, int pos) : Piece('Q', player, pos) {
        setPiece('Q', player, pos, false);
    }

   // Override setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();
    int eraseMoves(int);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  }

};

class PRook : public Piece {
public:
    PRook(bool player, int pos) : Piece('R', player, pos) {
        setPiece('R', player, pos, false);
    }

    // Override setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }

};

class PBishop : public Piece {
public:

    PBishop(bool player, int pos) : Piece('B', player, pos) {
        setPiece('B', player, pos, false);
    }

    // Override setTexture
    void setTexture()override;
    int eraseMoves(int);
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  }

};

class PKnight : public Piece {
public:

    PKnight(bool player, int pos) : Piece('N', player, pos) {
        setPiece('N', player, pos, false);
    }

    // Override setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  }

};

class PPawn : public Piece {
private:
    bool firstMove;

public:
    PPawn(bool player, int pos) : Piece('P', player, pos), firstMove(true) {
        setPiece('P', player, pos, false);
    }   

    
    bool hasFirstMove()const  {return firstMove;}
    void setFirstMove(bool value) {firstMove=value;}

    void movePiece(Piece* piece, int targetPos) {
    piece->setPosition(targetPos);

    // Si la pieza es un peón, actualiza su estado de primer movimiento
    if (PPawn* pawn = dynamic_cast<PPawn*>(piece)) {
        pawn->setFirstMove(false);
    }
}


    // Override setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();
    


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprite);
    }
};

#endif
