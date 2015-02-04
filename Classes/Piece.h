//
//  Piece.h
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//

#ifndef __BoardGame__Piece__
#define __BoardGame__Piece__

class Piece : public cocos2d::Sprite {
protected:
    int _typeId;
    int _playerId;
    int _locationId;
public:
    static Piece * CreateWithType(int _type);
    
    Piece(void);
    Piece(int _type);
    ~Piece();
    
    void init(int _type, int _player, int _location);
    
    int GetLocationId();
    int GetPlayerId();
    int GetTypeId();
    
    int SetLocationId(int _location);
    int SetPlayerId(int _player);
};
#endif /* defined(__BoardGame__Piece__) */
