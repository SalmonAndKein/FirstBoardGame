//
//  Board.h
//  BoardGame
//
//  Created by Salmon on 2015. 2. 13..
//
//

#ifndef __BoardGame__Board__
#define __BoardGame__Board__

#include "cocos2d.h"
#include "BoardTile.h"
#include "BoardPiece.h"

class Board : public cocos2d::Sprite {
protected:
    cocos2d::Vec2 itsSize;
    cocos2d::Vec2 itsIndex;
    BoardTile *** itsTiles;
protected:
    Board();
    Board(cocos2d::Vec2, cocos2d::Vec2);
    ~Board();
    bool CheckIndex(cocos2d::Vec2&);
    bool CheckPosition(cocos2d::Vec2&);
    int ConvertFloatToInt(float f) {
        return (int) std::floor(f+0.5);
    }
    cocos2d::Vec2 ConvertPositionToIndex(cocos2d::Vec2&);
    bool InsertPieceByIndex(BoardPiece*,cocos2d::Vec2);
    bool InsertPieceByPosition(BoardPiece*,cocos2d::Vec2);
    bool RemovePieceByIndex(BoardPiece*,cocos2d::Vec2);
    bool RemovePieceByPosition(BoardPiece*,cocos2d::Vec2);
    void RemoveAllPiecesOnBoard();
public:
    static Board* createBoardWithSizeAndIndex(cocos2d::Vec2, cocos2d::Vec2);
    cocos2d::Vec2 GetMaxSize();
    cocos2d::Vec2 GetMaxIndex();
    BoardPiece* GetPieceByIndex(cocos2d::Vec2);
    BoardPiece* GetPieceByPosition(cocos2d::Vec2);
    bool MovePieceByIndex(cocos2d::Vec2,cocos2d::Vec2);
    bool MovePieceByPosition(cocos2d::Vec2,cocos2d::Vec2);
    friend class MyChessBoard;
};

#endif /* defined(__BoardGame__Board__) */
