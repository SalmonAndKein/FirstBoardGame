//
//  MyChessBoard.h
//  BoardGame
//
//  Created by Salmon on 2015. 2. 16..
//
//

#ifndef __BoardGame__MyChessBoard__
#define __BoardGame__MyChessBoard__

#include "Board.h"
#include "BoardPiece.h"

class MyChessBoard : public Board {
protected:
    MyChessBoard(cocos2d::Vec2, cocos2d::Vec2);
    ~MyChessBoard();
    bool isCapitalLetter(char c) {
        if(c >= 'A' && c<= 'Z')
            return true;
        else
            return false;
    }
public:
    static MyChessBoard* createChessBoard();
    void ResetBoard();
};

#endif /* defined(__BoardGame__MyChessBoard__) */
