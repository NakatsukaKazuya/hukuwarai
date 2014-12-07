#ifndef __ModalLayer_SCENE_H__
#define __ModalLayer_SCENE_H__

#include "cocos2d.h"

class ModalLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void menuCloseCallback(CCObject* pSender);
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
   	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    // implement the "static node()" method manually
    CREATE_FUNC(ModalLayer);
};

#endif // __ModalLayer_SCENE_H__
