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

class Board : public cocos2d::Sprite {
protected:
    cocos2d::Vec2 itsSize;
    cocos2d::Vec2 itsIndex;
    //int size_x, size_y, count_x, count_y;
    BoardTile *** itsTiles;
protected:
    Board(cocos2d::Vec2, cocos2d::Vec2);
    ~Board();
    bool CheckIndex(cocos2d::Vec2&);
    bool CheckPosition(cocos2d::Vec2&);
public:
    static Board* createBoard();
    BoardTile* GetTileByIndex(cocos2d::Vec2);
    BoardTile* GetTileByPosition(cocos2d::Vec2);
    cocos2d::Vec2 GetMaxSize();
    cocos2d::Vec2 GetMaxIndex();
};

#endif /* defined(__BoardGame__Board__) */
