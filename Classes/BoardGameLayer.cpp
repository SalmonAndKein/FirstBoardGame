
#include "cocos2d.h"
#include "BoardGameLayer.h"
#include "BoardPiece.h"
#include "BoardTile.h"
#include "Board.h"
#include "MyChessBoard.h"

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
    /*
    //board = ChessBoard::createWithBoardImage("board10.png");
    board = Game::createWithBackgroundImage("board10.png");
    board->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(board);
    board->ResetGame();
    board->setVisible(false);
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(BoardGameLayer::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    scheduleUpdate();
    */
    //auto board2 =  MyChessBoard::createChessBoard();
    //board2->ResetBoard();
    //this->addChild(board2);
    
    /*
    auto tile = BoardTile::createBoardTile();
    tile->setPosition(cocos2d::Vec2(300,300));
    this->addChild(tile);
    auto piece = BoardPiece::createWithImageName("W1.png");
    piece->setPosition(cocos2d::Vec2(0,0));
    tile->AddPiece(piece);
    char strline[50];
    std::sprintf(strline, "player:%d, type:%d", piece->GetPlayer(), piece->GetType());
    auto strLabel = Label::createWithTTF(strline, "fonts/Marker Felt.ttf", 50);
    strLabel->setPosition(cocos2d::Vec2(200,200));
    this->addChild(strLabel);
    */
    
    auto board = MyChessBoard::createChessBoard();
    board->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height/2));
    board->ResetBoard();
    this->addChild(board);
    
    return true;
}
/*
bool BoardGameLayer::onTouchBegan (cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    auto tapPosition = touch->getLocation();
    if( board->getBoundingBox().containsPoint(tapPosition)) {
        auto convertedTapPosition = board->convertToNodeSpace(tapPosition);
        board->selectTile(convertedTapPosition);
        return true;
    }
    return false;
}
*/