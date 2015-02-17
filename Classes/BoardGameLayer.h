#ifndef __BOARDGAMELAYER_SCENE_H__
#define __BOARDGAMELAYER_SCENE_H__

#include "cocos2d.h"

class BoardGameLayer : public cocos2d::Layer
{
protected:
    //ChessBoard *board;
    //Game *board;
    bool bFisrtPosTouched;
    cocos2d::Vec2 firstPos;
    cocos2d::Vec2 secondPos;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(BoardGameLayer);
    
    //virtual bool onTouchBegan (cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif // __BOARDGAMELAYER_SCENE_H__
