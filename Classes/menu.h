

#ifndef __Menu_SCENE_H__
#define __Menu_SCENE_H__

#include "cocos2d.h"



class Menu : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
	static Menu * shareMenu();
	cocos2d::CCRect getRect();
    void Modallayer_1();

	void remove_sprite(CCObject *pSender);
	void start_button();
	void Game_Scene(CCObject *pSender);

	int mode;

	int face_mode;
	int eye_mode;
	int eyebrow_mode;
	int nose_mode;
	int cheeks_mode;
	int mouth_mode;

	bool Touch_flag;
	bool buttonPush_flag;
    
	bool isTapped(cocos2d::CCPoint);

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);


	// ñﬂÇÈÉLÅ[âüÇ≥ÇÍÇΩéû
	void keyBackClicked();

	

    // implement the "static node()" method manually
    CREATE_FUNC(Menu);
};

#endif // __Menu_SCENE_H__
