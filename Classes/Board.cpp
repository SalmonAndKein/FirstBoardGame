//
//  Board.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 2. 13..
//
//

#include "Board.h"
Board::Board() {}
Board::Board(cocos2d::Vec2 inputSize, cocos2d::Vec2 inputIndex) {
    if(inputSize.x <= 0 || inputSize.y <= 0 || inputIndex.x <= 0|| inputIndex.y <= 0) {
        inputSize.x = inputSize.y = 10;
        inputIndex.x = inputIndex.y = 10;
    }
    itsSize.set(inputSize);
    itsIndex.set(inputIndex);
    itsTiles = new BoardTile**[ConvertFloatToInt(itsIndex.x)];
    for(int i=0; i<itsIndex.x; i++)
        itsTiles[i] = new BoardTile*[ConvertFloatToInt(itsIndex.y)];
    
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
Board* Board::createBoardWithSizeAndIndex(cocos2d::Vec2 inputSize, cocos2d::Vec2 inputIndex) {
    Board * _board = new Board(inputSize, inputIndex);
    if(_board && _board->init() )
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
cocos2d::Vec2 Board::ConvertPositionToIndex(cocos2d::Vec2 &position) {
    int x_div = ConvertFloatToInt(position.x / itsSize.x);
    int y_div = ConvertFloatToInt(position.y / itsSize.y);
    return cocos2d::Vec2(x_div,y_div);
}

BoardPiece* Board::GetPieceByIndex(cocos2d::Vec2 index) {
    if( CheckIndex(index) == false)
        return NULL;
    BoardTile * targetTile = itsTiles[ConvertFloatToInt(index.x)][ConvertFloatToInt(index.y)];
    return targetTile->GetPiece();
}
BoardPiece* Board::GetPieceByPosition(cocos2d::Vec2 position) {
    return GetPieceByIndex(ConvertPositionToIndex(position));
}
cocos2d::Vec2 Board::GetMaxSize() {
    return cocos2d::Vec2(itsIndex.x * itsSize.x, itsIndex.y * itsSize.y);
}
cocos2d::Vec2 Board::GetMaxIndex() {
    return cocos2d::Vec2(itsIndex.x, itsIndex.y);
}
void Board::RemoveAllPiecesOnBoard() {
    for(int x=0; x<itsIndex.x; x++) {
        for(int y=0; y<itsIndex.y; y++) {
            auto curPiece = itsTiles[x][y]->GetPiece();
            itsTiles[x][y]->RemovePiece(curPiece);
        }
    }
}
bool Board::InsertPieceByIndex(BoardPiece* piece, cocos2d::Vec2 index) {
    if(CheckIndex(index)) {
        return itsTiles[ConvertFloatToInt(index.x)][ConvertFloatToInt(index.y)]->AddPiece(piece);
    } else {
        return false;

    }
}
bool Board::InsertPieceByPosition(BoardPiece* piece, cocos2d::Vec2 position) {
    if(CheckPosition(position))
        return InsertPieceByIndex(piece, ConvertPositionToIndex(position));
    else
        return false;
}
bool Board::RemovePieceByIndex(BoardPiece* piece, cocos2d::Vec2 index) {
    if(CheckIndex(index)) {
        return false;
    } else {
        return itsTiles[ConvertFloatToInt(index.x)][ConvertFloatToInt(index.y)]->RemovePiece(piece);
    }
}
bool Board::RemovePieceByPosition(BoardPiece * piece, cocos2d::Vec2 position) {
    if(CheckPosition(position)) {
        return RemovePieceByPosition(piece, position);
    } else {
        return false;
    }
}
bool Board::MovePieceByIndex(cocos2d::Vec2 idxSrc, cocos2d::Vec2 idxDst) {
    if( CheckIndex(idxSrc) == false || CheckIndex(idxDst) == false) {
        return false;
    } else {
        auto srcPiece = GetPieceByIndex(idxSrc);
        auto dstPiece = GetPieceByIndex(idxDst);
        if(srcPiece == NULL) {
            return false;
        } else if(dstPiece != NULL) {
            RemovePieceByIndex(dstPiece, idxDst);
        }
        InsertPieceByIndex(srcPiece, idxDst);
        return true;
    }
}
bool Board::MovePieceByPosition(cocos2d::Vec2 pos1, cocos2d::Vec2 pos2) {
    if(CheckPosition(pos1) && CheckPosition(pos2))
        return MovePieceByIndex(ConvertPositionToIndex(pos1), ConvertPositionToIndex(pos2));
    else
        return 0;
}
