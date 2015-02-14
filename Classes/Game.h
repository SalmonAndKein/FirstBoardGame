//
//  Game.h
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//

#ifndef __BoardGame__Game__
#define __BoardGame__Game__

#include "ChessBoard.h"
class Game : public ChessBoard
{
protected:
    int curTurnPlayer;
    bool bFisrtPosTouched;
    bool bGameOver;
    cocos2d::Vec2 firstPos;
    cocos2d::Vec2 secondPos;
    cocos2d::Label * statusBar;
    cocos2d::Sprite * resetButton; //구현 예정.... (2016.2.)
protected:
    void GameOver(int playerId);
    void ChangeStatusBar(std::string &str);
    int Search(cocos2d::Vec2 &pos);
    int EndTurn();
public:
    Game();
    static Game* createWithBackgroundImage(const std::string &filename);
    void ResetGame();
    bool selectTile(cocos2d::Vec2 &pos);
};

#endif /* defined(__BoardGame__Game__) */
