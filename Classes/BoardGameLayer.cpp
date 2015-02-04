
#include "cocos2d.h"
#include "BoardGameLayer.h"
#include "Game.h"
//#include "Board.h"

USING_NS_CC;

#define TILECOUNTX 8
#define TILECOUNTY 8
#define LENGTH 82

Scene* BoardGameLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BoardGameLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BoardGameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    bFisrtPosTouched = false;
    firstPos = cocos2d::Vec2(0,0);
    secondPos = cocos2d::Vec2(0,0);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //board = ChessBoard::createWithBoardImage("board10.png");
    board = Game::createWithBackgroundImage("board10.png");
    board->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(board);
    board->ResetGame();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(BoardGameLayer::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    scheduleUpdate();
    
    return true;
}
bool BoardGameLayer::onTouchBegan (cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    auto tapPosition = touch->getLocation();
    if( board->getBoundingBox().containsPoint(tapPosition)) {
        auto convertedTapPosition = board->convertToNodeSpace(tapPosition);
        board->selectTile(convertedTapPosition);
        return true;
    }
    return false;
}