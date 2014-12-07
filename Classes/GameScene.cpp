#include <string.h>
#include <unistd.h>
#include "GameScene.h"
#include"menu.h"

USING_NS_CC;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    this->setKeypadEnabled(true);

    // add "HelloWorld" splash screen"
    CCSprite* title = CCSprite::create("title.png");

    // position the sprite on the center of the screen
    title->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));

    // add the sprite as a child to this layer
    this->addChild(title, 0);
    
    //ボタン２（ゲーム開始）
    	CCSprite* btn2 = CCSprite::create("start_button.png");
    	CCSprite* btnPush2 = CCSprite::create("start_button.png");
    	CCMenuItemSprite* menu2 = CCMenuItemSprite::create(btn2, btnPush2,this, menu_selector(GameScene::nextPage));
    	menu2->setPosition(ccp(visibleSize.width = 150, visibleSize.height = -300));
    	menu2->setScale(0.8);
    	CCMenu* cmenu2 = CCMenu::create(menu2, NULL);
    	this->addChild(cmenu2, 10, 11);

    	CCSprite* btn3 = CCSprite::create("end_button.png");
    	CCSprite* btnPush3 = CCSprite::create("end_button.png");
    	CCMenuItemSprite* menu3 = CCMenuItemSprite::create(btn3, btnPush3,this, menu_selector(GameScene::MenuCallBack));
    	menu3->setPosition(ccp(visibleSize.width = -160, visibleSize.height = -300));
    	menu3->setScale(0.8);
    	CCMenu* cmenu3 = CCMenu::create(menu3, NULL);
    	this->addChild(cmenu3, 11, 12);

        return true;
    }

    //シーンの遷移
    void GameScene::nextPage(CCObject* pSelevter)
    {
    	CCScene* nextScene = Menu::scene();
    	CCScene* pScene = CCTransitionFade::create(3, nextScene);
    	if(pScene)
    		CCDirector::sharedDirector()->replaceScene(pScene);
    }

    void GameScene::keyBackClicked()
    {
    	// 戻るキーを押すとゲームを終了させる
    	   CCDirector::sharedDirector()->end();
    }

    void GameScene::MenuCallBack(CCObject *Sender)
    {
    	// 戻るキーを押すとゲームを終了させる
    	   CCDirector::sharedDirector()->end();
    }

