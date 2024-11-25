#include <iostream>
#include "chessGame.h"
#include "chessRules.h"


using namespace std;



ChessGame::ChessGame(sf::Color bordL_col = sf::Color::Blue, sf::Color bordD_col = sf::Color::Black)
: board(bordL_col,bordD_col)
{   

    font.loadFromFile("Texturesa/arial.ttf");
    
    
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::White);
    infoRestart.setPosition(sf::Vector2f(512.f,0.f));
    infoRestart.setSize(sf::Vector2f(256.f, 50.f));

    textRestart.setFont(font);
    textRestart.setString("RESTART");
    textRestart.setCharacterSize(24);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setFillColor(sf::Color::Black);
    textRestart.setPosition(infoRestart.getPosition().x + 75.f, infoRestart.getPosition().y + 10.f);

    textTurn.setFont(font);
    textTurn.setCharacterSize(24);
    textTurn.setStyle(sf::Text::Bold);
    textTurn.setFillColor(sf::Color::White);
    textTurn.setPosition(530.f, 70.f);

    textSituation.setFont(font);
    textSituation.setCharacterSize(24);
    textSituation.setStyle(sf::Text::Bold);
    textSituation.setFillColor(sf::Color::White);
    textSituation.setPosition(530.f, 110.f);

    textLastMove.setFont(font);
    textLastMove.setCharacterSize(24);
    textLastMove.setStyle(sf::Text::Bold);
    textLastMove.setFillColor(sf::Color::White);
    textLastMove.setPosition(530.f, 200.f);
    restart();
}


void ChessGame::restart(){


    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false;
    turn = 0;

    blackPieces[0] = new PRook(false, 7);
    blackPieces[1] = new PKnight(false, 6);
    blackPieces[2] = new PBishop(false, 5);
    blackPieces[3] = new PKing(false, 4);
    blackPieces[4] = new PQueen(false, 3);
    blackPieces[5] = new PBishop(false, 2);
    blackPieces[6] = new PKnight(false, 1);
    blackPieces[7] = new PRook(false, 0);

    whitePieces[0] = new PRook(true, 56);
    whitePieces[1] = new PKnight(true, 57);
    whitePieces[2] = new PBishop(true, 58);
    whitePieces[3] = new PKing(true, 59);
    whitePieces[4] = new PQueen(true, 60);
    whitePieces[5] = new PBishop(true, 61);
    whitePieces[6] = new PKnight(true, 62);
    whitePieces[7] = new PRook(true, 63);
    
    
    for(int i=8;i<16;i++){
        whitePieces[i] = new PPawn(true, 48 + (i - 8));
        blackPieces[i] = new PPawn(false, 15 - (i - 8));
    }
    
    calcPossibleMoves();
    updateInfo();

}

/*
void ChessGame::restart() {
    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false; // Reiniciar estado de jaque mate
    turn = 0;

    blackPieces[0] = new PRook(false, 7);
    blackPieces[1] = new PKnight(false, 6);
    blackPieces[2] = new PBishop(false, 5);
    blackPieces[3] = new PKing(false, 4);
    blackPieces[4] = new PQueen(false, 3);
    blackPieces[5] = new PBishop(false, 2);
    blackPieces[6] = new PKnight(false, 1);
    blackPieces[7] = new PRook(false, 0);

    whitePieces[0] = new PRook(true, 56);
    whitePieces[1] = new PKnight(true, 57);
    whitePieces[2] = new PBishop(true, 58);
    whitePieces[3] = new PKing(true, 59);
    whitePieces[4] = new PQueen(true, 60);
    whitePieces[5] = new PBishop(true, 61);
    whitePieces[6] = new PKnight(true, 62);
    whitePieces[7] = new PRook(true, 63);

    for (int i = 8; i < 16; i++) {
        whitePieces[i] = new PPawn(true, 48 + (i - 8));
        blackPieces[i] = new PPawn(false, 15 - (i - 8));
    }

    calcPossibleMoves(); // Recalcular movimientos
    updateInfo();
}

*/

void ChessGame::updateInfo(){
    textTurn.setString("Turn: " + std::to_string(turn));
    textLastMove.setString(lastMove);

    if(!mate){
        if(playerTurn)
            textSituation.setString("White piece turn");
        else
            textSituation.setString("Black piece turn");
        
        if(playerTurnCheck)
            textSituation.setString(textSituation.getString() + "\nCheck");
    }
    else{
        if(playerTurnCheck){
            if(playerTurn)
                textSituation.setString("CHECKMATE\nBlack Wins");
            else
                textSituation.setString("CHECKMATE\nWhite Wins");
        }
        else{
            textSituation.setString("STALEMATE\nIts a DRAW");
        }

    }
}

void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);

    target.draw(board); //funcion draw de board
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(textTurn);
    target.draw(textSituation);
    target.draw(textLastMove);


    
    if((selectedPiece != NULL) && (selected)){
        for(int i=0; i<possibleMovesSquares.size();i++){
            target.draw(possibleMovesSquares.at(i));
        }
    }
    

    for(int i=0;i<16;i++){
        target.draw(*whitePieces[i]);
        target.draw(*blackPieces[i]);
    }

    if (selectedPiece != NULL && selected) {
        target.draw(selectionBorder);
    }
}
void ChessGame::createSelectSquare(){
    sf::RectangleShape tmp;
   
        selectionBorder.setSize(sf::Vector2f(64, 64)); // tamaño del cuadro
        selectionBorder.setFillColor(sf::Color::Transparent); // Sin relleno
        selectionBorder.setOutlineColor(sf::Color::Red); // Contorno rojo
        selectionBorder.setOutlineThickness(-5.f); // Grosor del contorno
        int x = (selectedPiece->getPosition() % 8) * 64;
        int y = (selectedPiece->getPosition() / 8) * 64;
        selectionBorder.setPosition(x,y);
  
    

}
void ChessGame::createMovesSquares(){

    if(selectedPiece == NULL)
        return;

    possibleMovesSquares.clear();

    for(int i=0; i<selectedPiece->getPossibleMoves().size();i++){
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((selectedPiece->getPossibleMoves().at(i) % 8) * 64.f , (selectedPiece->getPossibleMoves().at(i) / 8) * 64.f));
        tmp.setSize(sf::Vector2f(64.f, 64.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        possibleMovesSquares.push_back(tmp);
    }
    createSelectSquare();

    return;

}


bool ChessGame::selectPiece(int pos){
    // Reiniciar selección anterior
    selectedPiece = NULL;
    selected = false;


    for (int i=0;i<16;i++){
        if(playerTurn){
            if (whitePieces[i]->getPosition()==pos){
            selectedPiece = whitePieces[i];
            selected = true;
            break;
            }
        }
        else{
            if (blackPieces[i]->getPosition()==pos){
            selectedPiece = blackPieces[i];
            selected=true;
            break;
            }
        }
             
        selected=false;
    }

    if (!selected){
        selectedPiece=NULL;
        possibleMovesSquares.clear();
        return selected;
    }

    createMovesSquares();
    return selected;
}




void ChessGame::moveSelected(int pos){
    
    bool validMove{false};

    if((selectedPiece == NULL) || !selected ) 
        return;
    
    // Check pos with the Piece's possibleMoves
    for(int i=0;i<selectedPiece->getPossibleMoves().size();i++){
        if(pos == selectedPiece->getPossibleMoves().at(i)){
            validMove = true;
            break;
        }
    }
    
    if(validMove){
        selectedPiece->setPosition(pos);

        for(int i=0; i<16; i++){
                if(selectedPiece->getPlayer()){ 
                    if(blackPieces[i]->getPosition() == pos){
                        blackPieces[i]->setPosition(-1);
                        break;
                    }
                
                    
                }
                else{ 
                    if(whitePieces[i]->getPosition() == pos){
                        whitePieces[i]->setPosition(-1);
                        break;
                    }
                }
        }

        playerTurn = !playerTurn; 
        calcPossibleMoves();
    }
    

    selectedPiece = NULL;
    selected = false;

}

/*
void ChessGame::moveSelected(int pos) {
    bool validMove{false};

    if ((selectedPiece == NULL) || !selected)
        return;

    // Verificar si el movimiento es válido
    for (int i = 0; i < selectedPiece->getPossibleMoves().size(); i++) {
        if (pos == selectedPiece->getPossibleMoves().at(i)) {
            validMove = true;
            break;
        }
    }

    if (validMove) {
        selectedPiece->setPosition(pos);

        // Capturar piezas del oponente
        for (int i = 0; i < 16; i++) {
            if (selectedPiece->getPlayer()) {
                if (blackPieces[i]->getPosition() == pos) {
                    blackPieces[i]->setPosition(-1); // Pieza capturada
                    break;
                }
            } else {
                if (whitePieces[i]->getPosition() == pos) {
                    whitePieces[i]->setPosition(-1); // Pieza capturada
                    break;
                }
            }
        }

        // Alternar turno después del movimiento
        playerTurn = !playerTurn;
        calcPossibleMoves();

        // Verificar jaque mate
        ChessRules rules;

        // Crear vectores temporales para las piezas
        std::vector<Piece*> currentPlayerPieces(whitePieces, whitePieces + 16);
        std::vector<Piece*> opponentPlayerPieces(blackPieces, blackPieces + 16);

        if (!playerTurn) {
            // Cambiar los roles de las piezas si es turno de las negras
            currentPlayerPieces.assign(blackPieces, blackPieces + 16);
            opponentPlayerPieces.assign(whitePieces, whitePieces + 16);
        }

        bool checkmate = rules.isCheckmate(currentPlayerPieces, opponentPlayerPieces);

        if (checkmate) {
            mate = true; // Detener el juego
            std::cout << "¡Jaque mate! "
                      << (playerTurn ? "Jugador Blanco Gana" : "Jugador Negro Gana")
                      << "." << std::endl;
        }
    }

    // Limpiar selección
    selectedPiece = NULL;
    selected = false;
}

*/

void ChessGame::calcPossibleMoves(){
    Piece* tmp;
   
    for (int i=0;i<32;i++){
        if (i<16)
            tmp = whitePieces[i];
        else
            tmp = blackPieces[i-16];

        tmp->getPossibleMoves().clear();

        if (tmp->getPosition() == -1){
            continue;
        }

        getPosicionesWhitePieces();
        getPosicionesBlackPieces();


        tmp->calcPiecePossibleMoves();

        
    }

    updateInfo();
    turn++;
}



std::array<int, 16> ChessGame::getPosicionesWhitePieces()  {
        
    std::array<int, 16> posiciones;

    for (std::size_t i = 0; i < 16; ++i) {
        posiciones[i] = whitePieces[i]->getPosition();
    }

    // Ahora, asignamos las posiciones a la clase Piece
    Piece::setPosiciones(posiciones);

    return posiciones;

}

std::array<int, 16> ChessGame::getPosicionesBlackPieces()  {
        
    std::array<int, 16> bposiciones;

    for (std::size_t i = 0; i < 16; ++i) {
        bposiciones[i] = blackPieces[i]->getPosition();
    }

    // Ahora, asignamos las posiciones a la clase Piece
    Piece::setPosicionesB(bposiciones);

    return bposiciones;

}
