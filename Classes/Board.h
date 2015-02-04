//
//  Board.h
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//

#ifndef __BoardGame__Board__
#define __BoardGame__Board__

#include "cocos2d.h"
#include "BoardTile.h"

#define TILECOUNTMAX_X 8
#define TILECOUNTMAX_Y 8
#define LENGTH 82

class ChessBoard : public cocos2d::Sprite {
protected:
    bool bReset;
    BoardTile * tiles[TILECOUNTMAX_Y][TILECOUNTMAX_X];
protected:
    bool initWithImageName(const std::string &filename);
    bool AddTileTo(BoardTile* tile, int _x, int _y);
    BoardTile* GetTile(int x, int y);
    BoardTile* GetTile(cocos2d::Vec2 &pos);
    bool SwapTile(cocos2d::Vec2 &pos1, cocos2d::Vec2 &pos2);
    bool SwapTile(int x1, int y1, int x2, int y2);
    bool RemoveTile(cocos2d::Vec2 &pos);
    bool RemoveTile(int x, int y);
    void ClearBoard();
    void ClearAllMarker();
protected:
    bool CheckIndex(int x, int y);
    float ConvertIndexToPosition_X(int index);
    float ConvertIndexToPosition_Y(int index);
    int ConvertPositionToIndex_X(float position);
    int ConvertPositionToIndex_Y(float position);
public:
    ChessBoard();
    ~ChessBoard();
    static ChessBoard* createWithBoardImage(const std::string &filename);
    void ResetBoard();
    bool MoveTile(cocos2d::Vec2 &pos1, cocos2d::Vec2 &pos2);
};


#endif /* defined(__BoardGame__Board__) */
