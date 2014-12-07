#ifndef __GameScene_SCENE_H__
#define __GameScene_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    
	void nextPage(CCObject* pSelevter);

	void MenuCallBack(CCObject *Sender);

    // implement the "static node()" method manually

	void keyBackClicked();

    CREATE_FUNC(GameScene);
};

#endif // __GameScene_SCENE_H__
