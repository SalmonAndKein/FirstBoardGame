//
//  MyChessBoard.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 2. 16..
//
//

#include "MyChessBoard.h"
MyChessBoard::MyChessBoard(cocos2d::Vec2 size, cocos2d::Vec2 index) : Board(size,index) {
    
}
MyChessBoard::~MyChessBoard() {
}
MyChessBoard* MyChessBoard::createChessBoard() {
    MyChessBoard * _board = new MyChessBoard(cocos2d::Vec2(82,82), cocos2d::Vec2(8,8));
    if(_board && _board->initWithFile("board11.png"))
    {
        _board->autorelease();
        return _board;
    }
    CC_SAFE_DELETE(_board);
    return NULL;
}
void MyChessBoard::ResetBoard() {
    char initBoard[8][9] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "........",
        "........",
        "........",
        "........",
        "pppppppp",
        "rnbqkbnr"
    };
    
    RemoveAllPiecesOnBoard();

    char filename[16];
    char playerChar;
    int player, type;
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
            char targetPiece = initBoard[x][y];
            if(targetPiece != '.') {
                player = isCapitalLetter(targetPiece) ? 2 : 1;
                if(player == 1) {
                    playerChar = 'B';
                } else {
                    playerChar = 'W';
                }
                switch (targetPiece) {
                    case 'P': case'p': {
                        type = 1;
                        break;
                    }
                    case 'R': case 'r': {
                        type = 2;
                        break;
                    }
                    case 'N': case 'n': {
                        type = 3;
                        break;
                    }
                    case 'B': case 'b': {
                        type = 4;
                        break;
                    }
                    case 'Q': case 'q': {
                        type = 5;
                        break;
                    }
                    case 'K': case 'k': {
                        type = 6;
                        break;
                    }
                    default:
                        break;
                }
                std::sprintf(filename, "%c%d.png",playerChar,type);
                auto piece = BoardPiece::createWithImageName(filename, player, type);
                InsertPieceByIndex(piece, cocos2d::Vec2(x,y));
            }
        }
    }
}