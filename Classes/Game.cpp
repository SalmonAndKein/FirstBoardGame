//
//  Game.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//

#include "Game.h"
/*
bool Game::MoveTile(cocos2d::Vec2 &pos1, cocos2d::Vec2 &pos2)
{
    auto srcTile = GetTile(pos1);
    auto dstTile = GetTile(pos2);
    if(srcTile == NULL && dstTile == NULL)
    {
        return false;
    }
    if(dstTile && dstTile->GetType() != 0)
    {
        if(dstTile->GetType() == 'K' || dstTile->GetType() == 'k') {
            GameOver(dstTile->GetPlayer());
        }
        dstTile->ClearTile();
    }
    return SwapTile(pos1, pos2);
}
 */
int Game::Search(cocos2d::Vec2 &pos)
{
    int player = GetTile(pos)->GetPlayer();
    int enemy;
    if(player == 1)enemy = 2;
    else enemy = 1;
    int up;
    if(player == 1)up=1;
    else up=-1;
    int type = GetTile(pos)->GetType();
    int x = ConvertPositionToIndex_X(pos.x);
    int y = ConvertPositionToIndex_Y(pos.y);
    switch (type) {
        case 'P': case 'p':
        {
            if(CheckIndex(x, y+up) && tiles[y+up][x]->GetPlayer()==0)
            {
                tiles[y+up][x]->Mark();
                if((up==1 && y==1) || (up==-1 && y==6))
                    if(CheckIndex(x, y+up*2) && tiles[y+up*2][x]->GetPlayer()==0)
                        tiles[y+up*2][x]->Mark();
            }
            if(CheckIndex(x-1, y+up) && tiles[y+up][x-1]->GetPlayer()==enemy)
                tiles[y+up][x-1]->Mark();
            if(CheckIndex(x+1, y+up) && tiles[y+up][x+1]->GetPlayer()==enemy)
                tiles[y+up][x+1]->Mark();
            break;
        }
        case 'R': case 'r':
        {
            for (int i=x+1; i<TILECOUNTMAX_X && tiles[y][i]->GetPlayer()!=player; i++) {
                if(tiles[y][i]->GetPlayer()!=0 && tiles[y][i]->GetPlayer()!=player)
                {
                    tiles[y][i]->Mark();
                    break;
                }
                tiles[y][i]->Mark();
            }
            for (int i=x-1; i>=0 && tiles[y][i]->GetPlayer()!=player; i--) {
                if(tiles[y][i]->GetPlayer()!=0 && tiles[y][i]->GetPlayer()!=player)
                {
                    tiles[y][i]->Mark();
                    break;
                }
                tiles[y][i]->Mark();
            }
            for (int i=y+1; i<TILECOUNTMAX_Y && tiles[i][x]->GetPlayer()!=player; i++) {
                if(tiles[i][x]->GetPlayer()!=0 && tiles[i][x]->GetPlayer()!=player)
                {
                    tiles[i][x]->Mark();
                    break;
                }
                tiles[i][x]->Mark();
            }
            for (int i=y-1; i>=0 && tiles[i][x]->GetPlayer()!=player; i--) {
                if(tiles[i][x]->GetPlayer()!=0 && tiles[i][x]->GetPlayer()!=player)
                {
                    tiles[i][x]->Mark();
                    break;
                }
                tiles[i][x]->Mark();
            }
            break;
        }
        case 'N': case 'n':
        {
            if(CheckIndex(x+1, y+2) && tiles[y+2][x+1]->GetPlayer()!=player)
                tiles[y+2][x+1]->Mark();
            if(CheckIndex(x-1, y+2) && tiles[y+2][x-1]->GetPlayer()!=player)
                tiles[y+2][x-1]->Mark();
            if(CheckIndex(x+1, y-2) && tiles[y-2][x+1]->GetPlayer()!=player)
                tiles[y-2][x+1]->Mark();
            if(CheckIndex(x-1, y-2) && tiles[y-2][x-1]->GetPlayer()!=player)
                tiles[y-2][x-1]->Mark();
            if(CheckIndex(x+2, y+1) && tiles[y+1][x+2]->GetPlayer()!=player)
                tiles[y+1][x+2]->Mark();
            if(CheckIndex(x+2, y-1) && tiles[y-1][x+2]->GetPlayer()!=player)
                tiles[y-1][x+2]->Mark();
            if(CheckIndex(x-2, y+1) && tiles[y+1][x-2]->GetPlayer()!=player)
                tiles[y+1][x-2]->Mark();
            if(CheckIndex(x-2, y-1) && tiles[y-1][x-2]->GetPlayer()!=player)
                tiles[y-1][x-2]->Mark();
            break;
        }
        case 'B': case 'b':
        {
            for (int i=x+1, j=y+1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i++,j++) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x-1, j=y+1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i--,j++) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x+1, j=y-1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i++,j--) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x-1, j=y-1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i--,j--) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            break;
        }
        case 'Q': case 'q':
        {
            for (int i=x+1; i<TILECOUNTMAX_X && tiles[y][i]->GetPlayer()!=player; i++) {
                if(tiles[y][i]->GetPlayer()!=0 && tiles[y][i]->GetPlayer()!=player)
                {
                    tiles[y][i]->Mark();
                    break;
                }
                tiles[y][i]->Mark();
            }
            for (int i=x-1; i>=0 && tiles[y][i]->GetPlayer()!=player; i--) {
                if(tiles[y][i]->GetPlayer()!=0 && tiles[y][i]->GetPlayer()!=player)
                {
                    tiles[y][i]->Mark();
                    break;
                }
                tiles[y][i]->Mark();
            }
            for (int i=y+1; i<TILECOUNTMAX_Y && tiles[i][x]->GetPlayer()!=player; i++) {
                if(tiles[i][x]->GetPlayer()!=0 && tiles[i][x]->GetPlayer()!=player)
                {
                    tiles[i][x]->Mark();
                    break;
                }
                tiles[i][x]->Mark();
            }
            for (int i=y-1; i>=0 && tiles[i][x]->GetPlayer()!=player; i--) {
                if(tiles[i][x]->GetPlayer()!=0 && tiles[i][x]->GetPlayer()!=player)
                {
                    tiles[i][x]->Mark();
                    break;
                }
                tiles[i][x]->Mark();
            }
            for (int i=x+1, j=y+1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i++,j++) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x-1, j=y+1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i--,j++) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x+1, j=y-1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i++,j--) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            for (int i=x-1, j=y-1; CheckIndex(i,j) && tiles[j][i]->GetPlayer()!=player; i--,j--) {
                if(tiles[j][i]->GetPlayer()!=0 && tiles[j][i]->GetPlayer()!=player)
                {
                    tiles[j][i]->Mark();
                    break;
                }
                tiles[j][i]->Mark();
            }
            break;
        }
        case 'K': case 'k':
        {
            if(CheckIndex(x+1, y) && tiles[y][x+1]->GetPlayer()!=player)
                tiles[y][x+1]->Mark();
            if(CheckIndex(x+1, y+1) && tiles[y+1][x+1]->GetPlayer()!=player)
                tiles[y+1][x+1]->Mark();
            if(CheckIndex(x, y+1) && tiles[y+1][x]->GetPlayer()!=player)
                tiles[y+1][x]->Mark();
            if(CheckIndex(x-1, y+1) && tiles[y+1][x-1]->GetPlayer()!=player)
                tiles[y+1][x-1]->Mark();
            if(CheckIndex(x-1, y) && tiles[y][x-1]->GetPlayer()!=player)
                tiles[y][x-1]->Mark();
            if(CheckIndex(x-1, y-1) && tiles[y-1][x-1]->GetPlayer()!=player)
                tiles[y-1][x-1]->Mark();
            if(CheckIndex(x, y-1) && tiles[y-1][x]->GetPlayer()!=player)
                tiles[y-1][x]->Mark();
            if(CheckIndex(x+1, y-1) && tiles[y-1][x+1]->GetPlayer()!=player)
                tiles[y-1][x+1]->Mark();
            break;
        }
        default:
            break;
    }
    GetTile(pos)->UnMark();
    return 0;
}
Game::Game()
{
    curTurnPlayer = 1;
    bFisrtPosTouched = false;
    statusBar = cocos2d::Label::createWithSystemFont("", "Arial Black.ttf", 100);
    statusBar->setAnchorPoint(cocos2d::Vec2(0,0));
    statusBar->setPosition(cocos2d::Vec2(0,0));
    this->addChild(statusBar, 1);
    this->retain();
}
Game* Game::createWithBackgroundImage(const std::string &filename)
{
    Game * game = new Game();
    if(game && game->initWithImageName(filename))
    {
        game->autorelease();
        return game;
    }
    CC_SAFE_DELETE(game);
    return NULL;
}
void Game::ChangeStatusBar(std::string &str) {
    statusBar->setString(str);
}
void Game::GameOver(int playerId) {
    bGameOver = true;
    std::string str = "";
    if(playerId == 1) {
        str = "White Wins";
    } else if (playerId == 2) {
        str = "Black Wins";
    }
    statusBar->setString(str);
    statusBar->setVisible(true);
}
void Game::ResetGame()
{
    curTurnPlayer = 1;
    bGameOver = false;
    bFisrtPosTouched = false;
    statusBar->setVisible(false);
    ResetBoard();
}
int Game::EndTurn()
{
    const int MaxPlayer = 2;
    ++curTurnPlayer;
    if(curTurnPlayer>MaxPlayer)
        curTurnPlayer = 1;
    return curTurnPlayer;
}
bool Game::selectTile(cocos2d::Vec2 &pos)
{
    auto selectedTile = GetTile(pos);
    if( selectedTile == NULL)
        return false;
    if( bGameOver == false) {
        if(bFisrtPosTouched)
        {
            if( selectedTile->IsMarked() )
            {
                secondPos.set(pos);
                auto dstTile =  GetTile(secondPos);
                if( dstTile->GetType() == 'k' || dstTile->GetType() == 'K' )
                    GameOver(dstTile->GetPlayer());
                MoveTile(firstPos, secondPos);
                EndTurn();
            }
            ClearAllMarker();
            bFisrtPosTouched = false;
            return true;
        }
        else
        {
            if( selectedTile->GetType() != 0 && selectedTile->GetPlayer() == curTurnPlayer)
            {
                bFisrtPosTouched = true;
                firstPos.set(pos);
                Search(pos);
                return true;
            }
        }
    }
    return false;
}