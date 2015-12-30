//
//  ChessPiece.h
//  BoardGame
//
//  Created by Salmon on 2015. 2. 18..
//
//

#ifndef __BoardGame__ChessPiece__
#define __BoardGame__ChessPiece__

#include "ChessPieceNode.h"

class ChessPiece : public ChessPieceNode {
protected:
    ChessPiece();
    ~ChessPiece();
public:
    ChessPiece * createWithTypeIdentifier(char);
    virtual bool CanMoveTo(int,int,Board*);
    friend Board;
};
#endif /* defined(__BoardGame__ChessPiece__) */
