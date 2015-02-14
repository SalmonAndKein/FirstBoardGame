//
//  BoardTile.h
//  BoardGame
//
//  Created by Salmon on 2015. 2. 14..
//
//

#ifndef __BoardGame__BoardTile__
#define __BoardGame__BoardTile__

#include "BoardPiece.h"

class BoardTile : public cocos2d::Node {
protected:
    BoardPiece* itsPiece;
    BoardTile();
    ~BoardTile();
public:
    static BoardTile* createBoardTile();
    int AddPiece(BoardPiece*);
    int RemovePiece();
    BoardPiece* GetBoardPiece();
};


#endif /* defined(__BoardGame__BoardTile__) */
