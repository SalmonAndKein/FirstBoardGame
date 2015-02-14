//
//  ChessBoard.cpp
//  BoardGame
//
//  Created by Salmon on 2015. 1. 13..
//
//
#include "ChessBoard.h"

USING_NS_CC;

ChessBoard::ChessBoard()
{
    ClearBoard();
}
ChessBoard::~ChessBoard()
{
}
void ChessBoard::ClearBoard()
{
    for(int y=0; y<TILECOUNTMAX_Y; y++)
    {
        for(int x=0; x<TILECOUNTMAX_X; x++)
        {
            tiles[y][x] = 0;
        }
    }
    this->removeAllChildren();
}
bool ChessBoard::CheckIndex(int x, int y)
{
    if(x<0 || x>= TILECOUNTMAX_X || y<0 || y>=TILECOUNTMAX_Y)
        return false;
    else
        return true;
}
bool ChessBoard::initWithImageName(const std::string &filename)
{
    if(this->initWithFile(filename))
    {
        bReset = false;
        return true;
    }
    return false;
}
ChessBoard* ChessBoard::createWithBoardImage(const std::string &filename)
{
    ChessBoard * board = new ChessBoard();
    if(board && board->initWithImageName(filename))
    {
        board->autorelease();
        return board;
    }
    CC_SAFE_DELETE(board);
    return NULL;
}
float ChessBoard::ConvertIndexToPosition_X(int index)
{
    int index_position_zero = this->boundingBox().size.width/2-LENGTH*4;
    int position = index_position_zero + LENGTH * index;
    return position;
}
int ChessBoard::ConvertPositionToIndex_X(float position)
{
    int index = 0;
    int position_zero = this->boundingBox().size.width/2-LENGTH*4;
    int position_max = this->boundingBox().size.width/2+LENGTH*4 + 1;
    
    if( position<= position_zero)
    {
        return 0;
    }
    else if(position >= position_max)
    {
        return TILECOUNTMAX_X-1;
    }
    else
    {
        int position_offset = position - position_zero;
        int positionDividedBy = position_offset / LENGTH;
        index = positionDividedBy;
        return index;
    }
}
float ChessBoard::ConvertIndexToPosition_Y(int index)
{
    int index_position_zero = this->boundingBox().size.height/2-LENGTH*4;
    int position = index_position_zero + LENGTH * index;
    return position;
}
int ChessBoard::ConvertPositionToIndex_Y(float position)
{
    int index = 0;
    int position_zero = this->boundingBox().size.height/2-LENGTH*4;
    int position_max = this->boundingBox().size.height/2+LENGTH*4 + 1;
    
    if( position<= position_zero)
    {
        return 0;
    }
    else if(position >= position_max)
    {
        return TILECOUNTMAX_Y-1;
    }
    else
    {
        int position_offset = position - position_zero;
        int positionDividedBy = position_offset / LENGTH;
        index = positionDividedBy;
        return index;
    }

}
bool ChessBoard::SwapTile(int x1, int y1, int x2, int y2)
{
    if( CheckIndex(x1, y1) && CheckIndex(x2, y2))
    {
        ChessBoardTile * tempTiles = NULL;
        tempTiles = tiles[y1][x1];
        tiles[y1][x1] = tiles[y2][x2];
        tiles[y2][x2] = tempTiles;
        
        tiles[y1][x1]->setPosition(cocos2d::Vec2(ConvertIndexToPosition_X(x1), ConvertIndexToPosition_Y(y1)));
        tiles[y2][x2]->setPosition(cocos2d::Vec2(ConvertIndexToPosition_X(x2), ConvertIndexToPosition_Y(y2)));
        return true;
    }
    else
    {
        return false;
    }
}
bool ChessBoard::RemoveTile(int x, int y)
{
    if( CheckIndex(x, y) && GetTile(x, y)->GetType() != 0)
    {
        GetTile(x, y)->ClearTile();
        return true;
    }
    return false;
}

bool ChessBoard::RemoveTile(cocos2d::Vec2 &pos)
{
    return RemoveTile(ConvertPositionToIndex_X(pos.x),ConvertPositionToIndex_Y(pos.y));
}
bool ChessBoard::SwapTile(cocos2d::Vec2 &pos1, cocos2d::Vec2 &pos2)
{
    return SwapTile(ConvertPositionToIndex_X(pos1.x), ConvertPositionToIndex_Y(pos1.y),
                             ConvertPositionToIndex_X(pos2.x), ConvertPositionToIndex_Y(pos2.y));
}
bool ChessBoard::AddTileTo(ChessBoardTile* _tile,int _x, int _y)
{
    if(tiles[_y][_x] == NULL)
    {
        _tile->setPosition( cocos2d::Vec2(ConvertIndexToPosition_X(_x), ConvertIndexToPosition_Y(_y)) );
        this->addChild(_tile);
        tiles[_y][_x] = _tile;
        tiles[_y][_x]->retain();
        return true;
    }
    return false;
}void ChessBoard::ResetBoard()
{
    if(bReset==true)
    {
        ClearBoard();
    }
    bReset = true;

    std::string str = "rnbkqbnrpppppppp7PPPPPPPPRNBKQBNR";
    int num=0;
    
    for(int y=0; y<8; y++)
    {
        for(int x=0; x<8; x++)
        {
            if(str[num]>='A' && str[num]<='Z')
            {
                switch (str[num])
                {
                    case 'P':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W1.png", 'P', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'R':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W2.png", 'R', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'N':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W3.png", 'N', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'B':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W4.png", 'B', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'Q':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W5.png", 'Q', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'K':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"W6.png", 'K', 2);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    default:
                        break;
                }
            }
            if(str[num]>='a' && str[num]<='z')
            {
                switch (str[num])
                {
                    case 'p':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B1.png", 'p', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'r':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B2.png", 'r', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'n':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B3.png", 'n', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'b':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B4.png", 'b', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'q':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B5.png", 'q', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    case 'k':
                    {
                        auto _tile = ChessBoardTile::createBoardTile(*"B6.png", 'k', 1);
                        AddTileTo(_tile, x, y);
                        break;
                    }
                    default:
                        break;
                }
                
            }
            if(str[num]=='7')
            {
                y = y+3;
                x=8;
            }
            num++;
        }
        for (int y=2; y<6; y++)
        {
            for(int x=0; x<8; x++)
            {
                auto _tile = ChessBoardTile::createEmptyTile();
                AddTileTo(_tile, x, y);
            }
        }
    }
}
void ChessBoard::ClearAllMarker()
{
    for(int y=0; y<8; y++)
    {
        for(int x=0; x<8; x++)
        {
            tiles[y][x]->UnMark();
        }
    }
}
ChessBoardTile* ChessBoard::GetTile(int x, int y)
{
    if( CheckIndex(x, y) )
    {
        return tiles[y][x];
    }
    else
    {
        return NULL;
    }
}
ChessBoardTile* ChessBoard::GetTile(cocos2d::Vec2 &pos)
{
    return GetTile(ConvertPositionToIndex_X(pos.x), ConvertPositionToIndex_Y(pos.y));
}

bool ChessBoard::MoveTile(cocos2d::Vec2 &pos1, cocos2d::Vec2 &pos2)
{
    auto srcTile = GetTile(pos1);
    auto dstTile = GetTile(pos2);
    if(srcTile == NULL && dstTile == NULL)
    {
        return false;
    }
    if(dstTile && dstTile->GetType() != 0)
    {
        dstTile->ClearTile();
    }
    return SwapTile(pos1, pos2);
}