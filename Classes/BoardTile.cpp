//
//  BoardTile.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 2. 14..
//
//

#include "BoardTile.h"

BoardTile::BoardTile() {
    itsPiece = NULL;
}
BoardTile::~BoardTile() {}
BoardTile* BoardTile::createBoardTile() {
    BoardTile * tile = new BoardTile();
    if(tile && tile->init())
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
int BoardTile::AddPiece(BoardPiece * _piece) {
    if(_piece)
        RemovePiece(itsPiece);
    itsPiece = _piece;
    this->addChild(itsPiece);
    return 1;
}
int BoardTile::RemovePiece(BoardPiece* _removePiece) {
    if(itsPiece == _removePiece) {
        this->removeChild(itsPiece);
        itsPiece = NULL;
        return 1;
    }
    return 0;
}
BoardPiece* BoardTile::GetPiece() {
    return itsPiece;
}