//
//  BoardTile.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 1. 20..
//
//
#include "cocos2d.h"
#include "BoardTile.h"


BoardTile::BoardTile(int _type, int _player)
{
    itsType = _type;
    itsPlayer = _player;
    itsPiece = NULL;
    itsMarker = NULL;
}
BoardTile::~BoardTile()
{
}
BoardTile* BoardTile::createBoardTile(const char &pieceName, int _type, int _player)
{
    BoardTile * tile = new BoardTile(_type,_player);
    if(tile && tile->initWithPieceName(pieceName))
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
bool BoardTile::initWithPieceName(const char &pieceName)
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
bool BoardTile::initWithEmptyTile()
{
    itsMarker = cocos2d::Sprite::create("mark.png");
    itsMarker->setAnchorPoint(cocos2d::Vec2(0,0));
    itsMarker->setVisible(false);
    this->addChild(itsMarker);
    itsMarker->retain();
    return true;
}
BoardTile* BoardTile::createEmptyTile()
{
    BoardTile * tile = new BoardTile(0,0);
    if(tile && tile->initWithEmptyTile())
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
void BoardTile::ClearTile()
{
    if(itsPiece != NULL) {
        removeChild(itsPiece);
    }
    itsPiece = NULL;
    itsType = 0;
    itsPlayer = 0;
}
void BoardTile::Mark()
{
    itsMarker->setVisible(true);
}
void BoardTile::UnMark()
{
    itsMarker->setVisible(false);
}
bool BoardTile::IsMarked()
{
    return itsMarker->isVisible();
}
int BoardTile::GetType()
{
    return itsType;
}
int BoardTile::GetPlayer()
{
    return itsPlayer;
}

