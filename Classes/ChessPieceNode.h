//
//  ChessPieceNode.h
//  BoardGame
//
//  Created by Salmon on 2015. 2. 18..
//
//

#ifndef __BoardGame__ChessPieceNode__
#define __BoardGame__ChessPieceNode__

#include "BoardPiece.h"

class ChessPieceNode : public BoardPiece {
protected:
    ChessPieceNode();
    ~ChessPieceNode();
public:
    virtual bool CanMoveTo(int,int,Board*) = 0;
};
#endif /* defined(__BoardGame__ChessPieceNode__) */
