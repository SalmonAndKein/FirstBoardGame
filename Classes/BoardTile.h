//
//  BoardTile.h
//  BoardGame
//
//  Created by Salmon on 2015. 1. 20..
//
//

#ifndef __BoardGame__BoardTile__
#define __BoardGame__BoardTile__

class BoardTile : public cocos2d::Node {
protected:
    cocos2d::Sprite *itsPiece;
    cocos2d::Sprite *itsMarker;
    int itsType;
    int itsPlayer;
    bool initWithPieceName(const char &pieceName);
    bool initWithEmptyTile();
public:
    BoardTile(int _type, int _player);
    ~BoardTile();
    static BoardTile* createBoardTile(const char &pieceName, int _type, int _player);
    static BoardTile* createEmptyTile();
    void ClearTile();
    void Mark();
    void UnMark();
    bool IsMarked();
    int GetType();
    int GetPlayer();
};

#endif /* defined(__BoardGame__BoardTile__) */
