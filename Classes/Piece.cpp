//
//  Piece.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//

#include "Piece.h"

Piece::Piece(void) {
    init(0, 0, 0);
}
Piece::Piece(int _type) {
    init(_type, 0, 0);
}
Piece::~Piece() {
}

void Piece::init(int _type, int _player, int _location) {
    _typeId = _type;
    _playerId = _player;
    _locationId = _location;
}

Piece * Piece::CreateWithType(int _type) {
    Piece * piece = new Piece(_type);
    if(piece && piece->initWithFile("Blank_Piece.png")) {
        piece->autorelease();
        return piece;
    }
    CC_SAFE_DELETE(piece);
    return NULL;
}

int Piece::GetLocationId() {
    return _locationId;
}
int Piece::GetPlayerId() {
    return _playerId;
}
int Piece::GetTypeId() {
    return _typeId;
}
int Piece::SetLocationId(int _location) {
    _locationId = _location;
    return 0;
}
int Piece::SetPlayerId(int _player) {
    _playerId = _player;
    return 0;
}