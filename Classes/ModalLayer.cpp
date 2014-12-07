#include <string.h>
#include <unistd.h>
#include "ModalLayer.h"

#define kModalLayerPriority kCCMenuHandlerPriority-1
#define kModalLayerMenuPriority kCCMenuHandlerPriority-2

using namespace cocos2d;

// on "init" you need to initialize your instance
bool ModalLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	this->setTouchPriority(kModalLayerPriority);
	this->setTouchEnabled(true);
	this->setTouchMode(kCCTouchesOneByOne);

	//CloseNormal CloseSelected
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite* frame = CCSprite::create("frame.jpg");
	CCSize frameSize = frame->getContentSize();
	frame->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	frame->setScale(0.5);
	this->addChild(frame);

	////�{�^���Z�b�g
	//CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",this,menu_selector(ModalLayer::menuCloseCallback));
	////CCSize* btnSize = pCloseItem->getContentSize(); 

	//pCloseItem->setPosition(ccp(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100));

	//CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);
	//pMenu->setTouchPriority(kModalLayerMenuPriority);
	//pMenu->setPosition(CCPointZero);
	//this->addChild(pMenu);
	
	return true;
}

bool ModalLayer::ccTouchBegan(CCTouch *pTouch, CCEvent* pEvent)
{
	return true;
}

void ModalLayer::menuCloseCallback(CCObject* pSender)
{
	this->removeFromParentAndCleanup(true);
}
