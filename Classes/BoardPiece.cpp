//
//  BoardPiece.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 2. 13..
//
//

#include "BoardPiece.h"

BoardPiece::BoardPiece() : BoardPiece(0,0) {
}
BoardPiece::BoardPiece(int _player, int _type) {
    itsPlayer = _player;
    itsType = _type;
}
BoardPiece::~BoardPiece(){
}
BoardPiece* BoardPiece::createWithImageName(const std::string &filename, int _player, int _type) {
    BoardPiece * piece = new BoardPiece(_player, _type);
    if(piece && piece->initWithFile(filename) )
    {
        piece->autorelease();
        return piece;
    }
    CC_SAFE_DELETE(piece);
    return NULL;
}
BoardPiece* BoardPiece::createWithImageName(const std::string &filename) {
    return createWithImageName(filename, 0, 0);
}
int BoardPiece::GetPlayer() {
    return itsPlayer;
}
int BoardPiece::GetType() {
    return itsType;
}