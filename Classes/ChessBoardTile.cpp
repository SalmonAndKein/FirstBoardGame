//
//  ChessBoardTile.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 1. 20..
//
//
#include "cocos2d.h"
#include "ChessBoardTile.h"


ChessBoardTile::ChessBoardTile(int _type, int _player)
{
    itsType = _type;
    itsPlayer = _player;
    itsPiece = NULL;
    itsMarker = NULL;
}
ChessBoardTile::~ChessBoardTile()
{
}
ChessBoardTile* ChessBoardTile::createBoardTile(const char &pieceName, int _type, int _player)
{
    ChessBoardTile * tile = new ChessBoardTile(_type,_player);
    if(tile && tile->initWithPieceName(pieceName))
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
bool ChessBoardTile::initWithPieceName(const char &pieceName)
{
    itsPiece = cocos2d::Sprite::create(&pieceName);
    itsPiece->setAnchorPoint(cocos2d::Vec2(0,0));
    itsPiece->setPosition(cocos2d::Vec2(0,0));
    this->addChild(itsPiece);
    itsPiece->retain();
    itsMarker = cocos2d::Sprite::create("mark.png");
    itsMarker->setAnchorPoint(cocos2d::Vec2(0,0));
    itsMarker->setVisible(false);
    this->addChild(itsMarker);
    itsMarker->retain();
    return true;
}
bool ChessBoardTile::initWithEmptyTile()
{
    itsMarker = cocos2d::Sprite::create("mark.png");
    itsMarker->setAnchorPoint(cocos2d::Vec2(0,0));
    itsMarker->setVisible(false);
    this->addChild(itsMarker);
    itsMarker->retain();
    return true;
}
ChessBoardTile* ChessBoardTile::createEmptyTile()
{
    ChessBoardTile * tile = new ChessBoardTile(0,0);
    if(tile && tile->initWithEmptyTile())
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
void ChessBoardTile::ClearTile()
{
    if(itsPiece != NULL) {
        removeChild(itsPiece);
    }
    itsPiece = NULL;
    itsType = 0;
    itsPlayer = 0;
}
void ChessBoardTile::Mark()
{
    itsMarker->setVisible(true);
}
void ChessBoardTile::UnMark()
{
    itsMarker->setVisible(false);
}
bool ChessBoardTile::IsMarked()
{
    return itsMarker->isVisible();
}
int ChessBoardTile::GetType()
{
    return itsType;
}
int ChessBoardTile::GetPlayer()
{
    return itsPlayer;
}

