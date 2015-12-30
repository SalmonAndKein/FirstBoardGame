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
    cocos2d::Sprite * itsMarker;
    BoardTile();
    ~BoardTile();
public:
    static BoardTile* createBoardTile();
    bool AddPiece(BoardPiece*);
    bool RemovePiece(BoardPiece*);
    BoardPiece* GetPiece();
    void Mark();
    void UnMark();
    bool isMarked();
};


#endif /* defined(__BoardGame__BoardTile__) */
