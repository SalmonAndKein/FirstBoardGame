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
    itsMarker = cocos2d::Sprite::create("mark.png");
    this->addChild(itsMarker);
    itsMarker->setVisible(false);
    itsMarker->retain();
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
bool BoardTile::AddPiece(BoardPiece * _piece) {
    if(itsPiece == NULL) {
        itsPiece = _piece;
        itsPiece->setAnchorPoint(cocos2d::Vec2(0,0));
        itsPiece->setPosition(cocos2d::Vec2(0,0));
        this->addChild(itsPiece);
        return true;
    } else {
        return false;
    }
}
bool BoardTile::RemovePiece(BoardPiece* _removePiece) {
    if(itsPiece != NULL && itsPiece == _removePiece) {
        this->removeChild(itsPiece);
        itsPiece = NULL;
        return true;
    }
    return false;
}
BoardPiece* BoardTile::GetPiece() {
    return itsPiece;
}
void BoardTile::Mark() {
    itsMarker->setVisible(true);
}
void BoardTile::UnMark() {
    itsMarker->setVisible(false);
}
bool BoardTile::isMarked() {
    return itsMarker->isVisible();
}
