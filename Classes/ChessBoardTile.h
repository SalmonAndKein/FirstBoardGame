//
//  ChessBoardTile.h
//  BoardGame
//
//  Created by Salmon on 2015. 1. 20..
//
//

#ifndef __BoardGame__ChessBoardTile__
#define __BoardGame__ChessBoardTile__

class ChessBoardTile : public cocos2d::Node {
protected:
    cocos2d::Sprite *itsPiece;
    cocos2d::Sprite *itsMarker;
    int itsType;
    int itsPlayer;
    bool initWithPieceName(const char &pieceName);
    bool initWithEmptyTile();
public:
    ChessBoardTile(int _type, int _player);
    ~ChessBoardTile();
    static ChessBoardTile* createBoardTile(const char &pieceName, int _type, int _player);
    static ChessBoardTile* createEmptyTile();
    void ClearTile();
    void Mark();
    void UnMark();
    bool IsMarked();
    int GetType();
    int GetPlayer();
};

#endif /* defined(__BoardGame__ChessBoardTile__) */
