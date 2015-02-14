//
//  Board.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 2. 13..
//
//

#include "Board.h"


Board::Board(cocos2d::Vec2 inputSize, cocos2d::Vec2 inputIndex) {
    if(inputSize.x <= 0 || inputSize.y <= 0 || inputIndex.x <= 0|| inputIndex.y <= 0) {
        inputSize.x = inputSize.y = 10;
        inputIndex.x = inputIndex.y = 10;
    }
    itsSize.set(inputSize);
    itsIndex.set(inputIndex);
    itsTiles = new BoardTile**[(int)itsIndex.x];
    for(int i=0; i<itsIndex.x; i++)
        itsTiles[i] = new BoardTile*[(int)itsIndex.y];
    
    for(int x=0; x<itsIndex.x; x++) {
        for(int y=0; y<itsIndex.y; y++) {
            auto _tile = BoardTile::createBoardTile();
            _tile->setAnchorPoint(cocos2d::Vec2(0,0));
            _tile->setPosition(cocos2d::Vec2( x * itsSize.x, y * itsSize.y));
            this->addChild(_tile);
            itsTiles[x][y] = _tile;
            _tile->retain();
        }
    }
}
Board::~Board() {}
Board* Board::createBoard() {
    Board * _board = new Board(cocos2d::Vec2(92,92), cocos2d::Vec2(8,8));
    if(_board && _board->init())
    {
        _board->autorelease();
        return _board;
    }
    CC_SAFE_DELETE(_board);
    return NULL;
}

bool Board::CheckIndex(cocos2d::Vec2& _index) {
    if(_index.x < 0 || _index.y < 0 || _index.x >= itsIndex.x || _index.y >= itsIndex.y)
        return false;
    else
        return true;
}
bool Board::CheckPosition(cocos2d::Vec2& _position) {
    if(_position.x < 0 || _position.y < 0 || _position.x >= itsIndex.x * itsSize.x || _position.y >= itsIndex.y * itsSize.y)
        return false;
    else
        return true;
}

BoardTile* Board::GetTileByIndex(cocos2d::Vec2 index) {
    if( CheckIndex(index) == false)
        return NULL;
    BoardTile * targetTile = itsTiles[(int)index.x][(int)index.y];
    return targetTile;
}
BoardTile* Board::GetTileByPosition(cocos2d::Vec2 position) {
    int x_div = (int) position.x / (int) itsSize.x;
    int y_div = (int) position.y / (int) itsSize.y;
    return GetTileByIndex(cocos2d::Vec2(x_div,y_div));
}
cocos2d::Vec2 Board::GetMaxSize() {
    return cocos2d::Vec2(itsIndex.x * itsSize.x, itsIndex.y * itsSize.y);
}
cocos2d::Vec2 Board::GetMaxIndex() {
    return cocos2d::Vec2(itsIndex.x, itsIndex.y);
}
