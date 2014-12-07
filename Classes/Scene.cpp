#include "Scene.h"
#include"GameScene.h"
#include"ModalLayer.h"
#include"menu.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

#define kModalLayerPriority kCCMenuHandlerPriority-1
#define kModalLayerMenuPriority kCCMenuHandlerPriority-2

#define CCRANDOM_0_1() ((float)rand()/RAND_MAX)
#define CCRANDOM_0_2() ((float)rand()/RAND_MAX)
#define CCRANDOM_ROTATE_0_1() ((float)rand()/RAND_MAX)


CCPoint touchStartPoint;

CCScene* Scene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Scene *layer = Scene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool Scene::isTapped(CCPoint point)
{
	CCRect rect = this->getRect();
	bool tapped = rect.containsPoint(point);
	if (tapped)
	{
		
	}
	else
	{
	
	}
	return tapped;
}

CCRect Scene::getRect()
{
	CCPoint point = this->getPosition();
	int w = this->getContentSize().width * this->getScaleX();
	int h = this->getContentSize().height * this->getScaleY();
	return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}


// on "init" you need to initialize your instance
bool Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	//����������
	srand(time(0));
	
	
	//�^�b�`���L��������
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);
	//

	//�L�[���g��������������
	this->setKeypadEnabled(true);
	//
	this->setTouchPriority(kModalLayerPriority);
	//
	//Menu.cpp����������������������-----------------------------
	CCUserDefault* user = CCUserDefault::sharedUserDefault();
	face_mode = user->getIntegerForKey("face",Menu::shareMenu()->face_mode );
	eye_mode = user->getIntegerForKey("eye", Menu::shareMenu()->eye_mode);
	eyebrow_mode = user->getIntegerForKey("eyebrow", Menu::shareMenu()->eyebrow_mode);
	nose_mode = user->getIntegerForKey("nose", Menu::shareMenu()->nose_mode);
	cheeks_mode = user->getIntegerForKey("cheeks", Menu::shareMenu()->cheeks_mode);
	mouth_mode = user->getIntegerForKey("mouth", Menu::shareMenu()->mouth_mode);
	//-----------------------------------------------------------

	able_to_touch_flag = false;
	flag = false;
	end_game_flag = false;
	game_flag = false;
	continu_flag = false;
	
	r_mode = 0;
	end_mode = 0;
    eye_counter = 0;
	eyebrow_counter = 0;
	cheeks_counter = 0;
	nose_mouth_counter = 0;
	mode = 0;
	mode_rotate = 0;
	time_r = 0;
	rotate_mode = 0;
	rotate_mode_p = 0;

	this->scheduleUpdate();


    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite* face1 = CCSprite::create("face.png");				   //背景
    	CCSprite* face2 = CCSprite::create("face_2.png");
    	CCSprite* face3 = CCSprite::create("face_3.png");
    	CCSprite* face4 = CCSprite::create("face4.png");

    	CCSprite* dark = CCSprite::create("dark.jpg");				   //暗転用画像

    	CCSprite* eye_r = CCSprite::create("eye_r.png");
    	CCSprite* eye_l = CCSprite::create("eye_l.png");

    	CCSprite* face2_eye_r = CCSprite::create("face_2_eye_r.png");
    	CCSprite* face2_eye_l = CCSprite::create("face_2_eye_l.png");

    	CCSprite* face3_eye_r = CCSprite::create("face3_eye_r.png");
    	CCSprite* face3_eye_l = CCSprite::create("face3_eye_l.png");

    	CCSprite* face4_eye_r = CCSprite::create("face4_eye_r.png");
    	CCSprite* face4_eye_l = CCSprite::create("face4_eye_l.png");

    	CCSprite* nose = CCSprite::create("nose.png");
    	CCSprite* face2_nose = CCSprite::create("face_2_nose.png");
    	CCSprite* face3_nose = CCSprite::create("face3_nose.png");
    	CCSprite* face4_nose = CCSprite::create("face_4_nose.png");

    	CCSprite* mouth = CCSprite::create("mouse.png");
    	CCSprite* face2_mouth = CCSprite::create("face_2_mouth.png");
    	CCSprite* face3_mouth = CCSprite::create("face3_mouth.png");
    	CCSprite* face4_mouth = CCSprite::create("face4_mouth.png");

    	CCSprite* cheeks_r = CCSprite::create("cheeks_r.png");
    	CCSprite* cheeks_l = CCSprite::create("cheeks_l.png");
    	CCSprite* face2_cheeks_r = CCSprite::create("face_2_cheeks_r.png");
    	CCSprite* face2_cheeks_l = CCSprite::create("face_2_cheeks_l.png");

    	CCSprite* eyebrow_r = CCSprite::create("eyebrow_r.png");
    	CCSprite* eyebrow_l = CCSprite::create("eyebrow_l.png");
    	CCSprite* face2_eyebrow_r = CCSprite::create("face_2_eyebrow_r.png");
    	CCSprite* face2_eyebrow_l = CCSprite::create("face_2_eyebrow_l.png");
    	CCSprite* face3_eyebrow_r = CCSprite::create("face3_eyebrow_r.png");
    	CCSprite* face3_eyebrow_l = CCSprite::create("face3_eyebrow_l.png");

    	CCSprite* face4_eyebrow_r = CCSprite::create("face4_eyebrow_r.png");
    	CCSprite* face4_eyebrow_l = CCSprite::create("face4_eyebrow_l.png");


    	CCSprite* point_eye_r = CCSprite::create("point.png"); //赤点
    	CCSprite* point_eye_l = CCSprite::create("point.png"); //赤点
    	CCSprite* point_nose = CCSprite::create("point.png"); //赤点
    	CCSprite* point_mouth = CCSprite::create("point.png"); //赤点
    	CCSprite* point_cheeks_r = CCSprite::create("point.png"); //赤点
    	CCSprite* point_cheeks_l = CCSprite::create("point.png"); //赤点
    	CCSprite* point_eyebrow_r = CCSprite::create("point.png"); //赤点
    	CCSprite* point_eyebrow_l = CCSprite::create("point.png"); //赤点


    	CCSprite* rotate_eye_r = CCSprite::create("rotate.png");
    	CCSprite* rotate_eye_l = CCSprite::create("rotate.png");
    	CCSprite* rotate_nose= CCSprite::create("rotate.png");
    	CCSprite* rotate_mouth = CCSprite::create("rotate.png");
    	CCSprite* rotate_cheeks_r = CCSprite::create("rotate.png");
    	CCSprite* rotate_cheeks_l = CCSprite::create("rotate.png");
    	CCSprite* rotate_eyebrow_r = CCSprite::create("rotate.png");
    	CCSprite* rotate_eyebrow_l = CCSprite::create("rotate.png");

    	CCSprite* scale_eye_r = CCSprite::create("scale.png");
    	CCSprite* scale_eye_l = CCSprite::create("scale.png");
    	CCSprite* scale_nose = CCSprite::create("scale.png");
    	CCSprite* scale_mouth= CCSprite::create("scale.png");
    	CCSprite* scale_cheeks_r = CCSprite::create("scale.png");
    	CCSprite* scale_cheeks_l = CCSprite::create("scale.png");
    	CCSprite* scale_eyebrow_r = CCSprite::create("scale.png");
    	CCSprite* scale_eyebrow_l = CCSprite::create("scale.png");

    	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("mokugyo.mp3");

    	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
    	SimpleAudioEngine::sharedEngine()->preloadEffect("nc42872.mp3");

    	face1->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    	face2->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    	face3->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    	face4->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

    	dark->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));


    	if (face_mode == 1)
    	{
    		nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 50));
    		face2_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 50));
    		face4_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 70));


    		mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 230));
    		face2_mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 230));
    		face4_mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 230));


    		face3_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 70));
    		face3_mouth->setPosition(ccp(visibleSize.width / 2 , visibleSize.height / 2 - 255));

    		eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		eye_l->setPosition(ccp(visibleSize.width = 430, visibleSize.height = 560));

    		cheeks_r->setScale(0.8);
    		cheeks_l->setScale(0.8);
    		cheeks_r->setPosition(ccp(visibleSize.width = 130, visibleSize.height = 330));
    		cheeks_l->setPosition(ccp(visibleSize.width = 500, visibleSize.height = 320));

    		face2_cheeks_r->setScale(0.8);
    		face2_cheeks_l->setScale(0.8);
    		face2_cheeks_r->setPosition(ccp(visibleSize.width = 130, visibleSize.height = 330));
    		face2_cheeks_l->setPosition(ccp(visibleSize.width = 500, visibleSize.height = 320));

    		eyebrow_r->setPosition(ccp(visibleSize.width = 240, visibleSize.height = 700));
    		eyebrow_l->setPosition(ccp(visibleSize.width = 390, visibleSize.height = 700));

    		face2_eyebrow_r->setScale(0.7);
    		face2_eyebrow_r->setRotation(20);
    		face2_eyebrow_l->setScale(0.8);
    		face2_eyebrow_l->setRotation(-20);
    		face2_eyebrow_r->setPosition(ccp(visibleSize.width = 220, visibleSize.height = 700));
    		face2_eyebrow_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 700));

    		face2_eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		face2_eye_l->setPosition(ccp(visibleSize.width = 430, visibleSize.height = 560));



    		face3_eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		face3_eye_l->setPosition(ccp(visibleSize.width = 430, visibleSize.height = 560));
    		face3_eyebrow_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 700));
    		face3_eyebrow_l->setPosition(ccp(visibleSize.width = 420, visibleSize.height = 700));


    		face3_nose->setScale(1.5);
    		face3_mouth->setScale(1.2);
    		face3_eye_r->setScale(1.2);
    		face3_eye_l->setScale(1.2);


    		face4_eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		face4_eye_l->setPosition(ccp(visibleSize.width = 430, visibleSize.height = 560));
    		face4_eyebrow_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 700));
    		face4_eyebrow_l->setPosition(ccp(visibleSize.width = 420, visibleSize.height = 700));

    		face4_nose->setScale(1.5);
    		face4_mouth->setScale(1.3);

    	}

    	/*if (face_mode == 2)
    	{
    		nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 50));
    		face2_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 50));

    		mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 230));
    		face2_mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 230));

    		face3_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 70));
    		face3_mouth->setPosition(ccp(visibleSize.width / 2 + 10, visibleSize.height / 2 - 255));

    		face2_eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		face2_eye_l->setPosition(ccp(visibleSize.width = 430, visibleSize.height = 560));

    		eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 560));
    		eye_l->setPosition(ccp(visibleSize.width = 450, visibleSize.height = 560));

    		cheeks_r->setScale(0.8);
    		cheeks_l->setScale(0.8);
    		cheeks_r->setPosition(ccp(visibleSize.width = 180, visibleSize.height = 350));
    		cheeks_l->setPosition(ccp(visibleSize.width = 470, visibleSize.height = 350));

    		face2_cheeks_r->setScale(0.8);
    		face2_cheeks_l->setScale(0.8);
    		face2_cheeks_r->setPosition(ccp(visibleSize.width = 180, visibleSize.height = 350));
    		face2_cheeks_l->setPosition(ccp(visibleSize.width = 470, visibleSize.height = 350));

    		eyebrow_r->setPosition(ccp(visibleSize.width = 240, visibleSize.height = 700));
    		eyebrow_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 700));

    		face2_eyebrow_r->setScale(0.9);
    		face2_eyebrow_l->setScale(0.9);
    		face2_eyebrow_r->setPosition(ccp(visibleSize.width = 220, visibleSize.height = 710));
    		face2_eyebrow_l->setPosition(ccp(visibleSize.width = 450, visibleSize.height = 710));



    		face3_eye_r->setPosition(ccp(visibleSize.width = 200, visibleSize.height = 570));
    		face3_eye_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 570));
    		face3_eyebrow_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 700));
    		face3_eyebrow_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 700));


    		face3_nose->setScale(1.5);
    		face3_eye_r->setScale(1.2);
    		face3_eye_l->setScale(1.2);
    	}*/

    	if (face_mode == 3)
    	{
    		nose->setPosition(ccp(visibleSize.width / 2 + 10, visibleSize.height / 2 - 150));
    		face2_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 150));
    		face4_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 150));

    		mouth->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 250));
    		face2_mouth->setPosition(ccp(visibleSize.width / 2 + 10, visibleSize.height / 2 - 240));
    		face4_mouth->setPosition(ccp(visibleSize.width / 2 + 10, visibleSize.height / 2 - 240));

    		face3_nose->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 - 150));
    		face3_mouth->setPosition(ccp(visibleSize.width / 2 + 10, visibleSize.height / 2 - 250));

    		face2_eye_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 400));
    		face2_eye_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 400));

    		eye_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 400));
    		eye_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 400));

    		cheeks_r->setScale(0.7);
    		cheeks_l->setScale(0.7);
    		cheeks_r->setPosition(ccp(visibleSize.width = 190, visibleSize.height = 310));
    		cheeks_l->setPosition(ccp(visibleSize.width = 460, visibleSize.height = 310));

    		face2_cheeks_r->setScale(0.7);
    		face2_cheeks_l->setScale(0.7);
    		face2_cheeks_r->setPosition(ccp(visibleSize.width = 190, visibleSize.height = 310));
    		face2_cheeks_l->setPosition(ccp(visibleSize.width = 460, visibleSize.height = 310));

    		eyebrow_r->setPosition(ccp(visibleSize.width = 230, visibleSize.height = 480));
    		eyebrow_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 480));

    		face2_eyebrow_r->setPosition(ccp(visibleSize.width = 230, visibleSize.height = 480));
    		face2_eyebrow_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 480));




    		face3_eye_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 400));
    		face3_eye_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 400));
    		face3_eyebrow_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 480));
    		face3_eyebrow_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 480));


    		face4_eye_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 400));
    		face4_eye_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 400));
    		face4_eyebrow_r->setPosition(ccp(visibleSize.width = 210, visibleSize.height = 480));
    		face4_eyebrow_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 480));



    		eye_r->setScale(0.75);
    		eye_l->setScale(0.75);
    		eyebrow_r->setScale(0.75);
    		eyebrow_l->setScale(0.75);
    		nose->setScale(0.75);
    		mouth->setScale(0.75);

    		face2_eye_r->setScale(0.75);
    		face2_eye_l->setScale(0.75);
    		face2_eyebrow_r->setScale(0.5);
    		face2_eyebrow_l->setScale(0.5);
    		face2_nose->setScale(0.75);
    		face2_mouth->setScale(0.6);

    		face2_eyebrow_r->setRotation(30);
    		face2_eyebrow_l->setRotation(-30);
    	}

    	if (face_mode == 4)
    	{
    		face4_eye_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 477));
    		face4_eye_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 478));
    		face4_eyebrow_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 551));
    		face4_eyebrow_l->setPosition(ccp(visibleSize.width = 387, visibleSize.height = 551));
    		face4_nose->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 408));
    		face4_mouth->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 325));

    		eye_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 477));
    		eye_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 477));

    		eye_r->setScale(0.7);
    		eye_l->setScale(0.7);

    		eyebrow_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 551));
    		eyebrow_l->setPosition(ccp(visibleSize.width = 387, visibleSize.height = 551));

    		eyebrow_r->setScale(0.7);
    		eyebrow_l->setScale(0.7);

    		nose->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 408));
    		nose->setScale(0.6);

    		mouth->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 325));
    		mouth->setScale(0.7);

    		face3_eye_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 477));
    		face3_eye_l->setPosition(ccp(visibleSize.width = 410, visibleSize.height = 478));
    		face3_eyebrow_r->setPosition(ccp(visibleSize.width = 250, visibleSize.height = 551));
    		face3_eyebrow_l->setPosition(ccp(visibleSize.width = 387, visibleSize.height = 551));
    		face3_nose->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 408));
    		face3_mouth->setPosition(ccp(visibleSize.width = 330, visibleSize.height = 325));

    		face3_eye_r->setScale(0.72);
    		face3_eye_l->setScale(0.72);
    		face3_eyebrow_r->setScale(0.72);
    		face3_eyebrow_l->setScale(0.72);
    		face3_nose->setScale(0.72);
    		face3_mouth->setScale(0.72);

    		cheeks_r->setScale(0.5);
    		cheeks_l->setScale(0.5);
    		cheeks_r->setPosition(ccp(visibleSize.width = 220, visibleSize.height = 395));
    		cheeks_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 395));

    		face2_cheeks_r->setScale(0.5);
    		face2_cheeks_l->setScale(0.5);
    		face2_cheeks_r->setPosition(ccp(visibleSize.width = 220, visibleSize.height = 395));
    		face2_cheeks_l->setPosition(ccp(visibleSize.width = 440, visibleSize.height = 395));


    	}


    	eye_r->setOpacity(0);
    	eye_l->setOpacity(0);

    	nose->setOpacity(0);
    	mouth->setOpacity(0);

    	cheeks_r->setOpacity(0);
    	cheeks_l->setOpacity(0);

    	eyebrow_r->setOpacity(0);
    	eyebrow_l->setOpacity(0);

    	face2_eye_r->setOpacity(0);
    	face2_eye_l->setOpacity(0);

    	face2_nose->setOpacity(0);
    	face2_mouth->setOpacity(0);

    	face2_cheeks_r->setOpacity(0);
    	face2_cheeks_l->setOpacity(0);

    	face2_eyebrow_r->setOpacity(0);
    	face2_eyebrow_l->setOpacity(0);

    	face3_eye_r->setOpacity(0);
    	face3_eye_l->setOpacity(0);

    	face3_nose->setOpacity(0);
    	face3_mouth->setOpacity(0);

    	face3_eyebrow_r->setOpacity(0);
    	face3_eyebrow_l->setOpacity(0);

    	face4_eye_r->setOpacity(0);
    	face4_eye_l->setOpacity(0);

    	face4_nose->setOpacity(0);
    	face4_mouth->setOpacity(0);

    	face4_eyebrow_r->setOpacity(0);
    	face4_eyebrow_l->setOpacity(0);

    	dark->setOpacity(0);
    	point_eye_r->setOpacity(0);
    	point_eye_l->setOpacity(0);

    	point_eyebrow_r->setOpacity(0);
    	point_eyebrow_l->setOpacity(0);

    	point_nose->setOpacity(0);
    	point_mouth->setOpacity(0);

    	point_cheeks_r->setOpacity(0);
    	point_cheeks_l->setOpacity(0);

    	rotate_eye_r->setVisible(false);
    	scale_eye_r->setVisible(false);

    	rotate_eye_l->setVisible(false);
    	scale_eye_l->setVisible(false);

    	rotate_nose->setVisible(false);
    	scale_nose->setVisible(false);

    	rotate_mouth->setVisible(false);
    	scale_mouth->setVisible(false);

    	rotate_cheeks_r->setVisible(false);
    	scale_cheeks_r->setVisible(false);


    	rotate_cheeks_l->setVisible(false);
    	scale_cheeks_l->setVisible(false);

    	rotate_eyebrow_r->setVisible(false);
    	scale_eyebrow_r->setVisible(false);

    	rotate_eyebrow_l->setVisible(false);
    	scale_eyebrow_l->setVisible(false);

    	//pCloseItem->setOpacity(0);
    	//end_button->setOpacity(0);
    	int parts1_x = (int)(CCRANDOM_0_1() * 620);
    	int parts1_y = (int)(CCRANDOM_0_2() * 930);

    	int parts2_x = (int)(CCRANDOM_0_1() * 620);
    	int parts2_y = (int)(CCRANDOM_0_2() * 930);

    	int parts3_x = (int)(CCRANDOM_0_1() * 620);
    	int parts3_y = (int)(CCRANDOM_0_2() * 930);

    	int parts4_x = (int)(CCRANDOM_0_1() * 620);
    	int parts4_y = (int)(CCRANDOM_0_2() * 930);

    	int parts5_x = (int)(CCRANDOM_0_1() * 620);
    	int parts5_y = (int)(CCRANDOM_0_2() * 930);

    	int parts6_x = (int)(CCRANDOM_0_1() * 620);
    	int parts6_y = (int)(CCRANDOM_0_2() * 930);

    	int parts7_x = (int)(CCRANDOM_0_1() * 620);
    	int parts7_y = (int)(CCRANDOM_0_2() * 930);

    	int parts8_x = (int)(CCRANDOM_0_1() * 620);
    	int parts8_y = (int)(CCRANDOM_0_2() * 930);

    	int parts1_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts2_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts3_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts4_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts5_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts6_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts7_r = (int)(CCRANDOM_ROTATE_0_1() * 360);
    	int parts8_r = (int)(CCRANDOM_ROTATE_0_1() * 360);

    	CCActionInterval* act = CCMoveTo::create(1.0, ccp(parts1_x,parts1_y));
    	CCActionInterval* easeact1 = CCEaseSineInOut::create(act);
    	CCActionInterval* act2 = CCMoveTo::create(1.0, ccp(parts2_x,parts2_y));
    	CCActionInterval* easeact2 = CCEaseSineInOut::create(act2);
    	CCCallFunc* pFunc = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_eye));

    	CCActionInterval* act3 = CCMoveTo::create(1.0, ccp(parts3_x,parts3_y));
    	CCActionInterval* easeact3 = CCEaseSineInOut::create(act3);
    	CCActionInterval* act4 = CCMoveTo::create(1.0, ccp(parts4_x,parts4_y));
    	CCActionInterval* easeact4 = CCEaseSineInOut::create(act4);
    	CCCallFunc* pFunc2 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_eyebrow));

    	CCActionInterval* act5 = CCMoveTo::create(1.0, ccp(parts5_x,parts5_y));
    	CCActionInterval* easeact5 = CCEaseSineInOut::create(act5);
    	CCActionInterval* act6 = CCMoveTo::create(1.0, ccp(parts6_x,parts6_y));
    	CCActionInterval* easeact6 = CCEaseSineInOut::create(act6);
    	CCCallFunc* pFunc3 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_cheeks));

    	CCActionInterval* act7 = CCMoveTo::create(1.0, ccp(parts7_x,parts7_y));
    	CCActionInterval* easeact7 = CCEaseSineInOut::create(act7);
    	CCActionInterval* act8 = CCMoveTo::create(1.0, ccp(parts8_x,parts8_y));
    	CCActionInterval* easeact8 = CCEaseSineInOut::create(act8);
    	CCCallFunc* pFunc4 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_nose_mouth));

    	//CCCallFunc* pFunc = CCCallFunc::create(this, callfunc_selector(parts1::nextAction));

    	//CCFadeIn* f_parts11 = (CCFadeIn*)this->getChildByTag(parts1::shareParts()->tagtest);
    	/*CCActionInterval* easeact1 = (CCActionInterval*)this->_parts1.getChildByTag(2);
    	CCCallFunc* pFunc = (CCCallFunc*)this->_parts1.getChildByTag(3);*/

    	if(flag == false)
    	{
    		//eye_r位置出現
    		eye_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//eye_r画面内を移動
    		eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact1, pFunc, NULL));
    		//eye_r回転移動
    		eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts1_r), NULL));
    		//--------------------------------------------------------------
    		//eye_l位置出現
    		eye_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//eye_l画面内を移動
    		eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact2, NULL));
    		//eye_l回転移動
    		eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts2_r), NULL));
    		//--------------------------------------------------------------
    		//eyebrow_l位置出現
    		eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//eyebrow_l画面内を移動
    		eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact3, pFunc2, NULL));
    		//eyebrow_l回転移動
    		eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts3_r), NULL));
    		//--------------------------------------------------------------
    		//eyebrow_r位置出現
    		eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//eyebrow_r画面内を移動
    		eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact4, NULL));
    		//eyebrow_r回転移動
    		eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts4_r), NULL));
    		//--------------------------------------------------------------
    		//cheeks_l位置出現
    		cheeks_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//cheeks_l画面内を移動
    		cheeks_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact5, pFunc3, NULL));
    		//cheeks_l回転移動
    		cheeks_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts5_r), NULL));
    		//--------------------------------------------------------------
    		//cheeks_r位置出現
    		cheeks_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//cheeks_r画面内を移動
    		cheeks_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact6, NULL));
    		//cheeks_r回転移動
    		cheeks_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts6_r), NULL));
    		//--------------------------------------------------------------
    		//nose位置出現
    		nose->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//nose画面内を移動
    		nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact7, pFunc4, NULL));
    		//nose回転移動
    		nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts7_r), NULL));
    		//--------------------------------------------------------------
    		//mouth位置出現
    		mouth->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//mouth画面内を移動
    		mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact8, NULL));
    		//mouth回転移動
    		mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts8_r), NULL));
    		//--------------------------------------------------------------




    		//face2_eye_r位置出現
    		face2_eye_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_eye_r画面内を移動
    		face2_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact1, pFunc, NULL));
    		//face2_eye_r回転移動
    		face2_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts1_r), NULL));
    		//--------------------------------------------------------------
    		//face2_eye_l位置出現
    		face2_eye_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_eye_l画面内を移動
    		face2_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact2, NULL));
    		//face2_eye_l回転移動
    		face2_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts2_r), NULL));
    		//--------------------------------------------------------------
    		//face2_eyebrow_l位置出現
    		face2_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_eyebrow_l画面内を移動
    		face2_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact3, pFunc2, NULL));
    		//face2_eyebrow_l回転移動
    		face2_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts3_r), NULL));
    		//--------------------------------------------------------------
    		//face2_eyebrow_r位置出現
    		face2_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_eyebrow_r画面内を移動
    		face2_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact4, NULL));
    		//face2_eyebrow_r回転移動
    		face2_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts4_r), NULL));
    		//--------------------------------------------------------------
    		//face2_cheeks_l位置出現
    		face2_cheeks_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_cheeks_l画面内を移動
    		face2_cheeks_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact5, pFunc3, NULL));
    		//face2_cheeks_l回転移動
    		face2_cheeks_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts5_r), NULL));
    		//--------------------------------------------------------------
    		//face2_cheeks_r位置出現
    		face2_cheeks_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_cheeks_r画面内を移動
    		face2_cheeks_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact6, NULL));
    		//face2_cheeks_r回転移動
    		face2_cheeks_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts6_r), NULL));
    		//--------------------------------------------------------------
    		//face2_nose位置出現
    		face2_nose->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_nose画面内を移動
    		face2_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact7, pFunc4, NULL));
    		//face2_nose回転移動
    		face2_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts7_r), NULL));
    		//--------------------------------------------------------------
    		//face2_mouth位置出現
    		face2_mouth->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face2_mouth画面内を移動
    		face2_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact8, NULL));
    		//face2_mouth回転移動
    		face2_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts8_r), NULL));




    		//face3_eye_r位置出現
    		face3_eye_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_eye_r画面内を移動
    		face3_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact1, pFunc, NULL));
    		//face3_eye_r回転移動
    		face3_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts1_r), NULL));
    		//--------------------------------------------------------------
    		//face3_eye_l位置出現
    		face3_eye_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_eye_l画面内を移動
    		face3_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact2, NULL));
    		//face3_eye_l回転移動
    		face3_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts2_r), NULL));
    		//--------------------------------------------------------------
    		//face3_eyebrow_l位置出現
    		face3_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_eyebrow_l画面内を移動
    		face3_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact3, pFunc2, NULL));
    		//face3_eyebrow_l回転移動
    		face3_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts3_r), NULL));
    		//--------------------------------------------------------------
    		//face3_eyebrow_r位置出現
    		face3_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_eyebrow_r画面内を移動
    		face3_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact4, NULL));
    		//face3_eyebrow_r回転移動
    		face3_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts4_r), NULL));


    		//face3_nose位置出現
    		face3_nose->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_nose画面内を移動
    		face3_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact7, pFunc4, NULL));
    		//face3_nose回転移動
    		face3_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts7_r), NULL));
    		//--------------------------------------------------------------
    		//face3_mouth位置出現
    		face3_mouth->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face3_mouth画面内を移動
    		face3_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact8, NULL));
    		//face3_mouth回転移動
    		face3_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts8_r), NULL));

    		//-------------------------------------------


    		//face4_eye_r位置出現
    		face4_eye_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_eye_r画面内を移動
    		face4_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact1, pFunc, NULL));
    		//face4_eye_r回転移動
    		face4_eye_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts1_r), NULL));
    		//--------------------------------------------------------------
    		//face4_eye_l位置出現
    		face4_eye_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_eye_l画面内を移動
    		face4_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact2, NULL));
    		//face4_eye_l回転移動
    		face4_eye_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts2_r), NULL));
    		//--------------------------------------------------------------
    		//face4_eyebrow_l位置出現
    		face4_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_eyebrow_l画面内を移動
    		face4_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact3, pFunc2, NULL));
    		//face4_eyebrow_l回転移動
    		face4_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts3_r), NULL));
    		//--------------------------------------------------------------
    		//face4_eyebrow_r位置出現
    		face4_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_eyebrow_r画面内を移動
    		face4_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact4, NULL));
    		//face4_eyebrow_r回転移動
    		face4_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts4_r), NULL));


    		//face4_nose位置出現
    		face4_nose->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_nose画面内を移動
    		face4_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact7, pFunc4, NULL));
    		//face4_nose回転移動
    		face4_nose->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts7_r), NULL));
    		//--------------------------------------------------------------
    		//face4_mouth位置出現
    		face4_mouth->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(5), CCDelayTime::create(2.0f), NULL));
    		//face4_mouth画面内を移動
    		face4_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			easeact8, NULL));
    		//face4_mouth回転移動
    		face4_mouth->runAction(CCSequence::create(CCDelayTime::create(11),
    			CCRotateBy::create(6.0f, 1800 + parts8_r), NULL));








    		//画面暗転
    		dark->runAction(CCSequence::create(CCDelayTime::create(13.0f),
    				CCFadeIn::create(4),NULL));
    		//赤点表示
    		point_eye_r->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    			CCDelayTime::create(3),NULL));
    		point_eye_l->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    			CCDelayTime::create(3),NULL));

    		point_eyebrow_r->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    			CCDelayTime::create(3),NULL));
    		point_eyebrow_l->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    			CCDelayTime::create(3),NULL));

    		if (cheeks_mode == 3)
    		{
    		}
    		else
    		{
    			point_cheeks_r->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    				CCDelayTime::create(3), NULL));
    			point_cheeks_l->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    				CCDelayTime::create(3), NULL));
    		}
    		point_nose->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0),
    			CCDelayTime::create(3),NULL));
    		point_mouth->runAction(CCSequence::create(CCDelayTime::create(18), CCFadeIn::create(0), CCCallFunc::create(this, callfunc_selector(Scene::gamestart)),
    			CCDelayTime::create(3),NULL));

    	}

    	if (face_mode == 1)
    	{
    		this->addChild(face1, 0, 1);
    	}
    	if (face_mode == 2)
    	{
    		this->addChild(face2, 0, 0);
    	}
    	if (face_mode == 3)
    	{
    		this->addChild(face3, 0, 0);
    	}
    	if (face_mode == 4)
    	{
    		this->addChild(face4, 0, 0);
    	}
    	this->addChild(dark, 5, 2);

    	if (eye_mode == 1)
    	{
    		this->addChild(eye_r, 4, 10);
    		this->addChild(eye_l, 4, 11);
    	}

    	if (nose_mode == 1)
    	{
    		this->addChild(nose, 4, 12);
    	}

    	if (mouth_mode == 1)
    	{
    		this->addChild(mouth, 4, 13);
    	}

    	if (cheeks_mode == 1)
    	{
    		this->addChild(cheeks_r, 4, 14);
    		this->addChild(cheeks_l, 4, 15);
    	}

    	if (eyebrow_mode == 1)
    	{
    		this->addChild(eyebrow_r, 4, 16);
    		this->addChild(eyebrow_l, 4, 17);
    	}

    	if (eye_mode == 2)
    	{
    		this->addChild(face2_eye_r, 4, 10);
    		this->addChild(face2_eye_l, 4, 11);
    	}

    	if (nose_mode == 2)
    	{
    		this->addChild(face2_nose, 4, 12);
    	}

    	if (mouth_mode == 2)
    	{
    		this->addChild(face2_mouth, 4, 13);
    	}

    	if (cheeks_mode == 2)
    	{
    		this->addChild(face2_cheeks_r, 4, 14);
    		this->addChild(face2_cheeks_l, 4, 15);
    	}

    	if (eyebrow_mode == 2)
    	{
    		this->addChild(face2_eyebrow_r, 4, 16);
    		this->addChild(face2_eyebrow_l, 4, 17);
    	}

    	if (eye_mode == 3)
    	{
    		this->addChild(face3_eye_r, 4, 10);
    		this->addChild(face3_eye_l, 4, 11);
    	}

    	if (nose_mode == 3)
    	{
    		this->addChild(face3_nose, 4, 12);
    	}

    	if (mouth_mode == 3)
    	{
    		this->addChild(face3_mouth, 4, 13);
    	}

    	if (eyebrow_mode == 3)
    	{
    		this->addChild(face3_eyebrow_r, 4, 16);
    		this->addChild(face3_eyebrow_l, 4, 17);
    	}

    	if (eye_mode == 4)
    	{
    		this->addChild(face4_eye_r, 4, 10);
    		this->addChild(face4_eye_l, 4, 11);
    	}

    	if (eyebrow_mode == 4)
    	{
    		this->addChild(face4_eyebrow_r, 4, 16);
    		this->addChild(face4_eyebrow_l, 4, 17);
    	}

    	if (nose_mode == 4)
    	{
    		this->addChild(face4_nose, 4, 12);
    	}

    	if (mouth_mode == 4)
    	{
    		this->addChild(face4_mouth, 4, 13);
    	}
    	this->addChild(point_eye_r,6,100);
    	this->addChild(point_eye_l,6,101);

    	this->addChild(point_nose,6,102);
    	this->addChild(point_mouth,6,103);

    	this->addChild(point_cheeks_r, 6, 104);
    	this->addChild(point_cheeks_l, 6, 105);


    	this->addChild(point_eyebrow_r,6,106);
    	this->addChild(point_eyebrow_l,6,107);

    	this->addChild(rotate_eye_r, 6, 200);
    	this->addChild(rotate_eye_l, 6, 201);
    	this->addChild(rotate_nose, 6, 202);
    	this->addChild(rotate_mouth, 6, 203);
    	this->addChild(rotate_cheeks_r, 6, 204);
    	this->addChild(rotate_cheeks_l, 6, 205);
    	this->addChild(rotate_eyebrow_r, 6, 206);
    	this->addChild(rotate_eyebrow_l, 6, 207);

    	this->addChild(scale_eye_r, 6, 300);
    	this->addChild(scale_eye_l, 6, 301);
    	this->addChild(scale_nose, 6, 302);
    	this->addChild(scale_mouth, 6, 303);
    	this->addChild(scale_cheeks_r, 6, 304);
    	this->addChild(scale_cheeks_l, 6, 305);
    	this->addChild(scale_eyebrow_r, 6, 306);
    	this->addChild(scale_eyebrow_l, 6, 307);


    	if (cheeks_mode == 3)
    	{
    		point_cheeks_r->setVisible(false);
    		point_cheeks_l->setVisible(false);

    	}
        return true;


    }

void Scene::update(float delta)
{
	
	//���_�����������������p�[�c����������
	CCSprite* eye_r = (CCSprite*)this->getChildByTag(10);

	CCSprite* point_eye_r = (CCSprite*)this->getChildByTag(100);
	CCSprite* rotate_eye_r = (CCSprite*)this->getChildByTag(200);
	CCSprite* scale_eye_r = (CCSprite*)this->getChildByTag(300);
	float rotate_eye_r_ = rotate_eye_r->getRotation();
	float scale_eye_r_ = scale_eye_r->getScale();
	CCPoint pos1 = point_eye_r->getPosition();
	

	CCSprite* eye_l = (CCSprite*)this->getChildByTag(11);
	CCSprite* point_eye_l = (CCSprite*)this->getChildByTag(101);
	CCSprite* rotate_eye_l = (CCSprite*)this->getChildByTag(201);
	CCSprite* scale_eye_l = (CCSprite*)this->getChildByTag(301);
	float rotate_eye_l_ = rotate_eye_l->getRotation();
	float scale_eye_l_ = scale_eye_l->getScale();
	CCPoint pos2 = point_eye_l->getPosition();

	CCSprite* nose = (CCSprite*)this->getChildByTag(12);
	CCSprite* point_nose = (CCSprite*)this->getChildByTag(102);
	CCSprite* rotate_nose = (CCSprite*)this->getChildByTag(202);
	CCSprite* scale_nose = (CCSprite*)this->getChildByTag(302);
	float rotate_nose_ = rotate_nose->getRotation();
	float scale_nose_ = scale_nose->getScale();
	CCPoint pos3 = point_nose->getPosition();

	CCSprite* mouth = (CCSprite*)this->getChildByTag(13);
	CCSprite* point_mouth = (CCSprite*)this->getChildByTag(103);
	CCSprite* rotate_mouth = (CCSprite*)this->getChildByTag(203);
	CCSprite* scale_mouth = (CCSprite*)this->getChildByTag(303);
	float rotate_mouth_ = rotate_mouth->getRotation();
	float scale_mouth_ = scale_mouth->getScale();
	CCPoint pos4 = point_mouth->getPosition();

	CCSprite* cheek_r = (CCSprite*)this->getChildByTag(14);
	CCSprite* point_cheek_r = (CCSprite*)this->getChildByTag(104);
	CCSprite* rotate_cheeks_r = (CCSprite*)this->getChildByTag(204);
	CCSprite* scale_cheeks_r = (CCSprite*)this->getChildByTag(304);
	float rotate_cheeks_r_ = rotate_cheeks_r->getRotation();
	float scale_cheeks_r_ = scale_cheeks_r->getScale();
	CCPoint pos5 = point_cheek_r->getPosition();

	CCSprite* cheek_l = (CCSprite*)this->getChildByTag(15);
	CCSprite* point_cheek_l = (CCSprite*)this->getChildByTag(105);
	CCSprite* rotate_cheeks_l = (CCSprite*)this->getChildByTag(205);
	CCSprite* scale_cheeks_l = (CCSprite*)this->getChildByTag(305);
	float rotate_cheeks_l_ = rotate_cheeks_l->getRotation();
	float scale_cheeks_l_ = scale_cheeks_l->getScale();
	CCPoint pos6 = point_cheek_l->getPosition();
	
	CCSprite* eyebrow_r = (CCSprite*)this->getChildByTag(16);
	CCSprite* point_eyebrow_r = (CCSprite*)this->getChildByTag(106);
	CCSprite* rotate_eyebrow_r = (CCSprite*)this->getChildByTag(206);
	CCSprite* scale_eyebrow_r = (CCSprite*)this->getChildByTag(306);
	float rotate_eyebrow_r_ = rotate_eyebrow_r->getRotation();
	float scale_eyebrow_r_ = scale_eyebrow_r->getScale();
	CCPoint pos7 = point_eyebrow_r->getPosition();

	CCSprite* eyebrow_l = (CCSprite*)this->getChildByTag(17);
	CCSprite* point_eyebrow_l = (CCSprite*)this->getChildByTag(107);
	CCSprite* rotate_eyebrow_l = (CCSprite*)this->getChildByTag(207);
	CCSprite* scale_eyebrow_l = (CCSprite*)this->getChildByTag(307);
	float rotate_eyebrow_l_ = rotate_eyebrow_l->getRotation();
	float scale_eyebrow_l_ = scale_eyebrow_l->getScale();
	CCPoint pos8 = point_eyebrow_l->getPosition();	

	if(able_to_touch_flag)//�u�^�b�v�������v�t���O������������
	{
		//\\\\\\\\\\\\\\\\\\\(��������������������)
		/*pos1.x = dt.x;
		pos1.y = dt.y;
		p_parts1->setPosition(dt);
		pp_parts1->setPosition(pos1);*/
		//\\\\\\\\\\\\\\\\\\\

		//���������W�����������W������������������
		eye_r->setPosition(pos1);
		eye_r->setRotation(rotate_eye_r_);
		eye_r->setScale(scale_eye_r_);
		rotate_eye_r->setPosition(pos1);
		scale_eye_r->setPosition(pos1);

		eye_l->setPosition(pos2);
		eye_l->setRotation(rotate_eye_l_);
		eye_l->setScale(scale_eye_l_);
		rotate_eye_l->setPosition(pos2);
		scale_eye_l->setPosition(pos2);

		nose->setPosition(pos3);
		nose->setRotation(rotate_nose_);
		nose->setScale(scale_nose_);
		rotate_nose->setPosition(pos3);
		scale_nose->setPosition(pos3);

		mouth->setPosition(pos4);
		mouth->setRotation(rotate_mouth_);
		mouth->setScale(scale_mouth_);
		rotate_mouth->setPosition(pos4);
		scale_mouth->setPosition(pos4);
		if (cheeks_mode == 3)
		{
		}
		else
		{
			cheek_r->setPosition(pos5);
			cheek_r->setRotation(rotate_cheeks_r_);
			cheek_r->setScale(scale_cheeks_r_);
			rotate_cheeks_r->setPosition(pos5);
			scale_cheeks_r->setPosition(pos5);

			cheek_l->setPosition(pos6);
			cheek_l->setRotation(rotate_cheeks_l_);
			cheek_l->setScale(scale_cheeks_l_);
			rotate_cheeks_l->setPosition(pos6);
			scale_cheeks_l->setPosition(pos6);
		}
			
		
		eyebrow_r->setPosition(pos7);
		eyebrow_r->setRotation(rotate_eyebrow_r_);
		eyebrow_r->setScale(scale_eyebrow_r_);
		rotate_eyebrow_r->setPosition(pos7);
		scale_eyebrow_r->setPosition(pos7);

		eyebrow_l->setPosition(pos8);
		eyebrow_l->setRotation(rotate_eyebrow_l_);
		eyebrow_l->setScale(scale_eyebrow_l_);
		rotate_eyebrow_l->setPosition(pos8);
		scale_eyebrow_l->setPosition(pos8);

	}

	if (mode_rotate == 1)
	{
		time_r++;
		
		if (time_r > 20)
		{
			mode_rotate = 0;
			
			time_r = 0;
		}
	}

}

void Scene::nextAction_eye()
{
	eye_counter++;
	//�p�[�c������������������
	if(eye_counter > 5) return;
	{
		CCSprite* eye_r = (CCSprite*)this->getChildByTag(10);
		CCSprite* pos_eye_r = (CCSprite*)this->getChildByTag(100);
		CCSprite* rot_eye_r = (CCSprite*)this->getChildByTag(200);
		
		CCSprite* eye_l = (CCSprite*)this->getChildByTag(11);
		CCSprite* pos_eye_l = (CCSprite*)this->getChildByTag(101);
		CCSprite* rot_eye_l = (CCSprite*)this->getChildByTag(201);
		
		int eye_r_pos_x = (int)(CCRANDOM_0_1() * 600);
		int eye_r_pos_y = (int)(CCRANDOM_0_2() * 910);
		
		int eye_l_pos_x = (int)(CCRANDOM_0_1() * 600);
		int eye_l_pos_y = (int)(CCRANDOM_0_2() * 910);
		

		CCActionInterval* act1 = CCMoveTo::create(1.0, ccp(eye_r_pos_x + 20, eye_r_pos_y + 20));
		CCActionInterval* easeact1 = CCEaseSineInOut::create(act1);
		CCCallFunc* pFunc = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_eye));
		
		CCActionInterval* act3 = CCMoveTo::create(1.0, ccp(eye_l_pos_x + 20,eye_l_pos_y + 20));
		CCActionInterval* easeact3 = CCEaseSineInOut::create(act3);

		eye_r->runAction(CCSequence::create(easeact1, pFunc, NULL));

		eye_l->runAction(CCSequence::create(easeact3, NULL));
		
		CCPoint pos_point_eye_r = eye_r->getPosition();
		pos_point_eye_r.x = eye_r_pos_x;
		pos_point_eye_r.y = eye_r_pos_y;
		pos_eye_r->setPosition(pos_point_eye_r);

		CCPoint pos_point_eye_l = eye_l->getPosition();
		pos_point_eye_l.x = eye_l_pos_x;
		pos_point_eye_l.y = eye_l_pos_y;
		pos_eye_l->setPosition(pos_point_eye_l);

		float eye_r_rotate = eye_r->getRotation();
		rot_eye_r->setRotation(eye_r_rotate);

		float eye_l_rotate = eye_l->getRotation();
		rot_eye_l->setRotation(eye_l_rotate);
	}
}

void Scene::nextAction_eyebrow()
{
	eyebrow_counter++;
	//�p�[�c������������������
	if(eyebrow_counter > 5) return;
	{
		CCSprite* eyebrow_r = (CCSprite*)this->getChildByTag(16);
		CCSprite* pos_eyebrow_r = (CCSprite*)this->getChildByTag(106);
		CCSprite* rot_eyebrow_r = (CCSprite*)this->getChildByTag(206);


		CCSprite* eyebrow_l = (CCSprite*)this->getChildByTag(17);
		CCSprite* pos_eyebrow_l = (CCSprite*)this->getChildByTag(107);
		CCSprite* rot_eyebrow_l = (CCSprite*)this->getChildByTag(207);


		int eyebrow_r_pos_x = (int)(CCRANDOM_0_1() * 600);
		int eyebrow_r_pos_y = (int)(CCRANDOM_0_2() * 910);
		
		int eyebrow_l_pos_x = (int)(CCRANDOM_0_1() * 600);
		int eyebrow_l_pos_y = (int)(CCRANDOM_0_2() * 910);
		
		CCActionInterval* act3 = CCMoveTo::create(1.0, ccp(eyebrow_r_pos_x + 20,eyebrow_r_pos_y + 20));
		CCActionInterval* easeact3 = CCEaseSineInOut::create(act3);
		CCActionInterval* act4 = CCMoveTo::create(1.0, ccp(eyebrow_l_pos_x + 20,eyebrow_l_pos_y + 20));
		CCActionInterval* easeact4 = CCEaseSineInOut::create(act4);
		CCCallFunc* pFunc2 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_eyebrow));
		
		eyebrow_r->runAction(CCSequence::create(easeact3, pFunc2, NULL));

		eyebrow_l->runAction(CCSequence::create(easeact4, NULL));
		
		CCPoint pos_point_eyebrow_r = eyebrow_r->getPosition();
		pos_point_eyebrow_r.x = eyebrow_r_pos_x;
		pos_point_eyebrow_r.y = eyebrow_r_pos_y;
		pos_eyebrow_r->setPosition(pos_point_eyebrow_r);

		CCPoint pos_point_eyebrow_l = eyebrow_l->getPosition();
		pos_point_eyebrow_l.x = eyebrow_l_pos_x;
		pos_point_eyebrow_l.y = eyebrow_l_pos_y;
		pos_eyebrow_l->setPosition(pos_point_eyebrow_l);
	
		float eyebrow_r_rotate = eyebrow_r->getRotation();
		rot_eyebrow_r->setRotation(eyebrow_r_rotate);

		float eyebrow_l_rotate = eyebrow_l->getRotation();
		rot_eyebrow_l->setRotation(eyebrow_l_rotate);
	}
}

void Scene::nextAction_cheeks()
{
	cheeks_counter++;
	//�p�[�c������������������
	if(cheeks_counter > 5) return;
	{
	

			CCSprite* cheeks_r = (CCSprite*)this->getChildByTag(14);
			CCSprite* pos_cheeks_r = (CCSprite*)this->getChildByTag(104);
			CCSprite* rot_cheeks_r = (CCSprite*)this->getChildByTag(204);


			CCSprite* cheeks_l = (CCSprite*)this->getChildByTag(15);
			CCSprite* pos_cheeks_l = (CCSprite*)this->getChildByTag(105);
			CCSprite* rot_cheeks_l = (CCSprite*)this->getChildByTag(205);


			int cheeks_r_pos_x = (int)(CCRANDOM_0_1() * 600);
			int cheeks_r_pos_y = (int)(CCRANDOM_0_2() * 910);

			int cheeks_l_pos_x = (int)(CCRANDOM_0_1() * 600);
			int cheeks_l_pos_y = (int)(CCRANDOM_0_2() * 910);

			CCActionInterval* act3 = CCMoveTo::create(1.0, ccp(cheeks_r_pos_x + 20, cheeks_r_pos_y + 20));
			CCActionInterval* easeact3 = CCEaseSineInOut::create(act3);
			CCActionInterval* act4 = CCMoveTo::create(1.0, ccp(cheeks_l_pos_x + 20, cheeks_l_pos_y + 20));
			CCActionInterval* easeact4 = CCEaseSineInOut::create(act4);
			CCCallFunc* pFunc2 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_cheeks));

			cheeks_r->runAction(CCSequence::create(easeact3, pFunc2, NULL));

			cheeks_l->runAction(CCSequence::create(easeact4, NULL));

			CCPoint pos_point_cheeks_r = cheeks_r->getPosition();
			pos_point_cheeks_r.x = cheeks_r_pos_x;
			pos_point_cheeks_r.y = cheeks_r_pos_y;
			pos_cheeks_r->setPosition(pos_point_cheeks_r);

			CCPoint pos_point_cheeks_l = cheeks_l->getPosition();
			pos_point_cheeks_l.x = cheeks_l_pos_x;
			pos_point_cheeks_l.y = cheeks_l_pos_y;
			pos_cheeks_l->setPosition(pos_point_cheeks_l);


			float cheeks_r_rotate = cheeks_r->getRotation();
			rot_cheeks_r->setRotation(cheeks_r_rotate);

			float cheeks_l_rotate = cheeks_l->getRotation();
			rot_cheeks_l->setRotation(cheeks_l_rotate);
		}
	
}

void Scene::nextAction_nose_mouth()
{
	nose_mouth_counter++;
	//�p�[�c������������������
	if(nose_mouth_counter > 5) return;
	{
		CCSprite* nose = (CCSprite*)this->getChildByTag(12);
		CCSprite* pos_nose = (CCSprite*)this->getChildByTag(102);
		CCSprite* rot_nose = (CCSprite*)this->getChildByTag(202);


		CCSprite* mouth = (CCSprite*)this->getChildByTag(13);
		CCSprite* pos_mouth = (CCSprite*)this->getChildByTag(103);
		CCSprite* rot_mouth = (CCSprite*)this->getChildByTag(203);


		int nose_pos_x = (int)(CCRANDOM_0_1() * 600);
		int nose_pos_y = (int)(CCRANDOM_0_2() * 910);
		
		int mouth_pos_x = (int)(CCRANDOM_0_1() * 600);
		int mouth_pos_y = (int)(CCRANDOM_0_2() * 910);
		
		CCActionInterval* act3 = CCMoveTo::create(1.0, ccp(nose_pos_x + 20,nose_pos_y + 20));
		CCActionInterval* easeact3 = CCEaseSineInOut::create(act3);
		CCActionInterval* act4 = CCMoveTo::create(1.0, ccp(mouth_pos_x + 20,mouth_pos_y + 20));
		CCActionInterval* easeact4 = CCEaseSineInOut::create(act4);
		CCCallFunc* pFunc2 = CCCallFunc::create(this, callfunc_selector(Scene::nextAction_nose_mouth));
		
		nose->runAction(CCSequence::create(easeact3, pFunc2, NULL));

		mouth->runAction(CCSequence::create(easeact4, NULL));
		
		CCPoint pos_point_nose = nose->getPosition();
		pos_point_nose.x = nose_pos_x;
		pos_point_nose.y = nose_pos_y;
		pos_nose->setPosition(pos_point_nose);

		CCPoint pos_point_mouth = mouth->getPosition();
		pos_point_mouth.x = mouth_pos_x;
		pos_point_mouth.y = mouth_pos_y;
		pos_mouth->setPosition(pos_point_mouth);
	
		float nose_rotate = nose->getRotation();
		rot_nose->setRotation(nose_rotate);

		float mouth_rotate = mouth->getRotation();
		rot_mouth->setRotation(mouth_rotate);
	}
}

//�V���O���^�b�v�C�x���g
//�^�b�v���n��
bool Scene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{

	Scene* eye_r = (Scene*)this->getChildByTag(100);
	Scene* eye_l = (Scene*)this->getChildByTag(101);
	Scene* nose = (Scene*)this->getChildByTag(102);
	Scene* mouth = (Scene*)this->getChildByTag(103);
	Scene* cheek_r = (Scene*)this->getChildByTag(104);
	Scene* cheek_l = (Scene*)this->getChildByTag(105);
	Scene* eyebrow_r = (Scene*)this->getChildByTag(106);
	Scene* eyebrow_l = (Scene*)this->getChildByTag(107);

	touchStartPoint = pTouch->getLocation();

	if (flag == true)
	{

		if (eye_r->isTapped(pTouch->getLocation()))
		{
			mode = 1;
		}

		if (eye_l->isTapped(pTouch->getLocation()))
		{
			mode = 2;
		}

		if (nose->isTapped(pTouch->getLocation()))
		{
			mode = 3;
		}

		if (mouth->isTapped(pTouch->getLocation()))
		{
			mode = 4;
		}


			if (cheek_r->isTapped(pTouch->getLocation()))
			{
				mode = 5;
			}

			if (cheek_l->isTapped(pTouch->getLocation()))
			{
				mode = 6;
			}

		
		
		if (eyebrow_r->isTapped(pTouch->getLocation()))
		{
			mode = 7;
		}

		if (eyebrow_l->isTapped(pTouch->getLocation()))
		{
			mode = 8;
		}
		
	}


	if (rotate_mode == 1)
	{
		rotate_mode_p = 1;
	}
	if (scale_mode == 1)
	{
		scale_mode_p = 1;
	}

	if (rotate_mode == 2)
	{
		rotate_mode_p = 2;
	}
	if (scale_mode == 2)
	{
		scale_mode_p = 2;
	}

	if (rotate_mode == 3)
	{
		rotate_mode_p = 3;
	}
	if (scale_mode == 3)
	{
		scale_mode_p = 3;
	}
	if (rotate_mode == 4)
	{
		rotate_mode_p = 4;
	}
	if (scale_mode == 4)
	{
		scale_mode_p = 4;
	}
	if (rotate_mode == 5)
	{
		rotate_mode_p = 5;
	}
	if (scale_mode == 5)
	{
		scale_mode_p = 5;
	}
	if (rotate_mode == 6)
	{
		rotate_mode_p = 6;
	}
	if (scale_mode == 6)
	{
		scale_mode_p = 6;
	}
	if (rotate_mode == 7)
	{
		rotate_mode_p = 7;
	}
	if (scale_mode == 7)
	{
		scale_mode_p = 7;
	}
	if (rotate_mode == 8)
	{
		rotate_mode_p = 8;
	}
	if (scale_mode == 8)
	{
		scale_mode_p = 8;
	}

	return true;
}
//�^�b�v��
void Scene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	Scene* eye_r = (Scene*)this->getChildByTag(100);
	Scene* eye_l = (Scene*)this->getChildByTag(101);
	Scene* nose = (Scene*)this->getChildByTag(102);
	Scene* mouth = (Scene*)this->getChildByTag(103);
	Scene* cheek_r = (Scene*)this->getChildByTag(104);
	Scene* cheek_l = (Scene*)this->getChildByTag(105);
	Scene* eyebrow_r = (Scene*)this->getChildByTag(106);
	Scene* eyebrow_l = (Scene*)this->getChildByTag(107);
	
	Scene* rotate_eye_r= (Scene*)this->getChildByTag(200);
	Scene* scale_eye_r = (Scene*)this->getChildByTag(300);
	Scene* rotate_eye_l = (Scene*)this->getChildByTag(201);
	Scene* scale_eye_l = (Scene*)this->getChildByTag(301);
	Scene* rotate_nose = (Scene*)this->getChildByTag(202);
	Scene* scale_nose = (Scene*)this->getChildByTag(302);
	Scene* rotate_mouth = (Scene*)this->getChildByTag(203);
	Scene* scale_mouth = (Scene*)this->getChildByTag(303);
	Scene* rotate_cheeks_r = (Scene*)this->getChildByTag(204);
	Scene* scale_cheeks_r = (Scene*)this->getChildByTag(304);
	Scene* rotate_cheeks_l = (Scene*)this->getChildByTag(205);
	Scene* scale_cheeks_l = (Scene*)this->getChildByTag(305);
	Scene* rotate_eyebrow_r = (Scene*)this->getChildByTag(206);
	Scene* scale_eyebrow_r = (Scene*)this->getChildByTag(306);
	Scene* rotate_eyebrow_l = (Scene*)this->getChildByTag(207);
	Scene* scale_eyebrow_l = (Scene*)this->getChildByTag(307);
	
	CCPoint touchEndPoint = pTouch->getLocation();
	if (flag == true)
	{
		if(mode == 1)
		{
			if (eye_r->isTapped(pTouch->getLocation()))
			{
				eye_r->setPosition(pTouch->getLocation());
			}			
		}
		if(mode == 2)
		{
			if (eye_l->isTapped(pTouch->getLocation()))
			{
				eye_l->setPosition(pTouch->getLocation());
			}
		}
		if(mode == 3)
		{
			if (nose->isTapped(pTouch->getLocation()))
			{
				nose->setPosition(pTouch->getLocation());
			}
		}
		if(mode == 4)
		{
			if (mouth->isTapped(pTouch->getLocation()))
			{
				mouth->setPosition(pTouch->getLocation());
			}
		}if(mode == 5)
		{
			
			if (cheek_r->isTapped(pTouch->getLocation()))
			{
				cheek_r->setPosition(pTouch->getLocation());
			}
		}
		if(mode == 6)
		{
			if (cheek_l->isTapped(pTouch->getLocation()))
			{
				cheek_l->setPosition(pTouch->getLocation());
			}
		}
		if(mode == 7)
		{
			
			if (eyebrow_r->isTapped(pTouch->getLocation()))
			{
				eyebrow_r->setPosition(pTouch->getLocation());
			}
		}
		if(mode == 8)
		{
			if (eyebrow_l->isTapped(pTouch->getLocation()))
			{
				eyebrow_l->setPosition(pTouch->getLocation());
			}
		}
	
	}

	if (rotate_mode == 1)
	{
		get_r_eye_r = rotate_eye_r->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_eye_r = get_r_eye_r + increment_x / 50;
		rotate_eye_r->setRotation(set_r_eye_r);
	}

	if (scale_mode == 1)
	{
		get_s_eye_r = scale_eye_r->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_eye_r = get_s_eye_r + increment_y / 5000;
		scale_eye_r->setScale(set_s_eye_r);

		float get_confirmation_scale = scale_eye_r->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_eye_r->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_eye_r->setScale(0.5);
		}
	}

	if (rotate_mode == 2)
	{
		get_r_eye_l = rotate_eye_l->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_eye_l = get_r_eye_l + increment_x / 50;
		rotate_eye_l->setRotation(set_r_eye_l);
	}

	if (scale_mode == 2)
	{
		get_s_eye_l = scale_eye_l->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_eye_l = get_s_eye_l + increment_y / 5000;
		scale_eye_l->setScale(set_s_eye_l);

		float get_confirmation_scale = scale_eye_l->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_eye_l->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_eye_l->setScale(0.5);
		}
	}

	if (rotate_mode == 3)
	{
		get_r_nose = rotate_nose->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_nose = get_r_nose + increment_x / 50;
		rotate_nose->setRotation(set_r_nose);
	}

	if (scale_mode == 3)
	{
		get_s_nose = scale_nose->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_nose = get_s_nose + increment_y / 5000;
		scale_nose->setScale(set_s_nose);

		float get_confirmation_scale = scale_nose->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_nose->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_nose->setScale(0.5);
		}
	}

	

	if (rotate_mode == 4)
	{
		get_r_mouth = rotate_mouth->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_mouth = get_r_mouth + increment_x / 50;
		rotate_mouth->setRotation(set_r_mouth);
	}

	if (scale_mode == 4)
	{
		get_s_mouth = scale_mouth->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_mouth = get_s_mouth + increment_y / 5000;
		scale_mouth->setScale(set_s_mouth);

		float get_confirmation_scale = scale_mouth->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_mouth->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_mouth->setScale(0.5);
		}
	}

	if (rotate_mode == 5)
	{
		get_r_cheeks_r = rotate_cheeks_r->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_cheeks_r = get_r_cheeks_r + increment_x / 50;
		rotate_cheeks_r->setRotation(set_r_cheeks_r);
	}

	if (scale_mode == 5)
	{
		get_s_cheeks_r = scale_cheeks_r->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_cheeks_r = get_s_cheeks_r + increment_y / 5000;
		scale_cheeks_r->setScale(set_s_cheeks_r);

		float get_confirmation_scale = scale_cheeks_r->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_cheeks_r->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_cheeks_r->setScale(0.5);
		}
	}

	if (rotate_mode == 6)
	{
		get_r_cheeks_l = rotate_cheeks_l->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_cheeks_l = get_r_cheeks_l + increment_x / 50;
		rotate_cheeks_l->setRotation(set_r_cheeks_l);
	}

	if (scale_mode == 6)
	{
		get_s_cheeks_l = scale_cheeks_l->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_cheeks_l = get_s_cheeks_l + increment_y / 5000;
		scale_cheeks_l->setScale(set_s_cheeks_l);

		float get_confirmation_scale = scale_cheeks_l->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_cheeks_l->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_cheeks_l->setScale(0.5);
		}
	}

	if (rotate_mode == 7)
	{
		get_r_eyebrow_r = rotate_eyebrow_r->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_eyebrow_r = get_r_eyebrow_r + increment_x / 50;
		rotate_eyebrow_r->setRotation(set_r_eyebrow_r);
	}

	if (scale_mode == 7)
	{
		get_s_eyebrow_r = scale_eyebrow_r->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_eyebrow_r = get_s_eyebrow_r + increment_y / 5000;
		scale_eyebrow_r->setScale(set_s_eyebrow_r);

		float get_confirmation_scale = scale_eyebrow_r->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_eyebrow_r->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_eyebrow_r->setScale(0.5);
		}
	}

	if (rotate_mode == 8)
	{
		get_r_eyebrow_l = rotate_eyebrow_l->getRotation();
		increment_x = touchEndPoint.x - touchStartPoint.x;
		set_r_eyebrow_l = get_r_eyebrow_l + increment_x / 50;
		rotate_eyebrow_l->setRotation(set_r_eyebrow_l);
	}

	if (scale_mode == 8)
	{
		get_s_eyebrow_l = scale_eyebrow_l->getScale();
		increment_y = touchEndPoint.y - touchStartPoint.y;
		set_s_eyebrow_l = get_s_eyebrow_l + increment_y / 5000;
		scale_eyebrow_l->setScale(set_s_eyebrow_l);

		float get_confirmation_scale = scale_eyebrow_l->getScale();
		if (get_confirmation_scale >= 2)
		{
			scale_eyebrow_l->setScale(2);
		}

		if (get_confirmation_scale <= 0.5)
		{
			scale_eyebrow_l->setScale(0.5);
		}
	}

}
//�^�b�v�I��
void Scene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	Scene* eye_r = (Scene*)this->getChildByTag(100);
	Scene* eye_l = (Scene*)this->getChildByTag(101);
	Scene* nose = (Scene*)this->getChildByTag(102);
	Scene* mouth = (Scene*)this->getChildByTag(103);
	Scene* cheek_r = (Scene*)this->getChildByTag(104);
	Scene* cheek_l = (Scene*)this->getChildByTag(105);
	Scene* eyebrow_r = (Scene*)this->getChildByTag(106);
	Scene* eyebrow_l = (Scene*)this->getChildByTag(107);

	Scene* rotate_eye_r = (Scene*)this->getChildByTag(200);
	Scene* scale_eye_r = (Scene*)this->getChildByTag(300);
	Scene* rotate_eye_l = (Scene*)this->getChildByTag(201);
	Scene* scale_eye_l = (Scene*)this->getChildByTag(301);
	Scene* rotate_nose = (Scene*)this->getChildByTag(202);
	Scene* scale_nose = (Scene*)this->getChildByTag(302);
	Scene* rotate_mouth = (Scene*)this->getChildByTag(203);
	Scene* scale_mouth = (Scene*)this->getChildByTag(303);
	Scene* rotate_cheeks_r = (Scene*)this->getChildByTag(204);
	Scene* scale_cheeks_r = (Scene*)this->getChildByTag(304);
	Scene* rotate_cheeks_l = (Scene*)this->getChildByTag(205);
	Scene* scale_cheeks_l = (Scene*)this->getChildByTag(305);
	Scene* rotate_eyebrow_r = (Scene*)this->getChildByTag(206);
	Scene* scale_eyebrow_r = (Scene*)this->getChildByTag(306);
	Scene* rotate_eyebrow_l = (Scene*)this->getChildByTag(207);
	Scene* scale_eyebrow_l = (Scene*)this->getChildByTag(307);


	Scene* return_game = (Scene*)this->getChildByTag(500);
	Scene* end_game = (Scene*)this->getChildByTag(501);

	if (flag == true)
	{

		if (mode == 1)
		{
			if (eye_r->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					eye_r->setPositionY(point.y + 50);
				}
				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 1;
				}
				if (r_mode == 1)
				{
					rotate_mode = 1;
					eye_r->setVisible(false);
					rotate_eye_r->setVisible(true);
					flag = false;
				}
			}
		}
		if (mode == 2)
		{
			if (eye_l->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					eye_l->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 2;
				}
				if (r_mode == 2)
				{
					rotate_mode = 2;
					eye_l->setVisible(false);
					rotate_eye_l->setVisible(true);
					flag = false;
				}
			}
		}
		if(mode == 3)
		{
		
			if (nose->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					nose->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 3;
				}
				if (r_mode == 3)
				{
					rotate_mode = 3;
					nose->setVisible(false);
					rotate_nose->setVisible(true);
					flag = false;
				}
			}
		}
		if(mode == 4)
		{
			if (mouth->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					mouth->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 4;
				}
				if (r_mode == 4)
				{
					rotate_mode = 4;
					mouth->setVisible(false);
					rotate_mouth->setVisible(true);
					flag = false;
				}
			}
			
		}
		if(mode == 5)
		{
			
			if (cheek_r->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					cheek_r->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 5;
				}
				if (r_mode == 5)
				{
					rotate_mode = 5;
					cheek_r->setVisible(false);
					rotate_cheeks_r->setVisible(true);
					flag = false;
				}
			}
			
		}
		if(mode == 6)
		{
			if (cheek_l->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					cheek_l->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 6;
				}
				if (r_mode == 6)
				{
					rotate_mode = 6;
					cheek_l->setVisible(false);
					rotate_cheeks_l->setVisible(true);
					flag = false;
				}
			}
			
		}if(mode == 7)
		{
			
			if (eyebrow_r->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					eyebrow_r->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 7;
				}
				if (r_mode == 7)
				{
					rotate_mode = 7;
					eyebrow_r->setVisible(false);
					rotate_eyebrow_r->setVisible(true);
					flag = false;
				}
			}
		}
		if(mode == 8)
		{
			if (eyebrow_l->isTapped(pTouch->getLocation()))
			{
				CCPoint point = pTouch->getLocation();
				if(point.y <= 20)
				{
					eyebrow_l->setPositionY(point.y + 50);
				}

				mode_rotate += 1;
				if (mode_rotate == 2)
				{
					r_mode = 8;
				}
				if (r_mode == 8)
				{
					rotate_mode = 8;
					eyebrow_l->setVisible(false);
					rotate_eyebrow_l->setVisible(true);
					flag = false;
				}
			}
		}

	}

	if (rotate_mode_p == 1)
	{
		if (rotate_eye_r->isTapped(pTouch->getLocation()))
		{
			scale_eye_r->setVisible(true);
			rotate_eye_r->setVisible(false);
			scale_mode = 1;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 1)
	{
		if (scale_eye_r->isTapped(pTouch->getLocation()))
		{
			eye_r->setVisible(true);
			scale_eye_r->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 2)
	{
		if (rotate_eye_l->isTapped(pTouch->getLocation()))
		{
			scale_eye_l->setVisible(true);
			rotate_eye_l->setVisible(false);
			scale_mode = 2;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 2)
	{
		if (scale_eye_l->isTapped(pTouch->getLocation()))
		{
			eye_l->setVisible(true);
			scale_eye_l->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 3)
	{
		if (rotate_nose->isTapped(pTouch->getLocation()))
		{
			scale_nose->setVisible(true);
			rotate_nose->setVisible(false);
			scale_mode = 3;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 3)
	{
		if (scale_nose->isTapped(pTouch->getLocation()))
		{
			nose->setVisible(true);
			scale_nose->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 4)
	{
		if (rotate_mouth->isTapped(pTouch->getLocation()))
		{
			scale_mouth->setVisible(true);
			rotate_mouth->setVisible(false);
			scale_mode = 4;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 4)
	{
		if (scale_mouth->isTapped(pTouch->getLocation()))
		{
			mouth->setVisible(true);
			scale_mouth->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 5)
	{
		if (rotate_cheeks_r->isTapped(pTouch->getLocation()))
		{
			scale_cheeks_r->setVisible(true);
			rotate_cheeks_r->setVisible(false);
			scale_mode = 5;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 5)
	{
		if (scale_cheeks_r->isTapped(pTouch->getLocation()))
		{
			cheek_r->setVisible(true);
			scale_cheeks_r->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 6)
	{
		if (rotate_cheeks_l->isTapped(pTouch->getLocation()))
		{
			scale_cheeks_l->setVisible(true);
			rotate_cheeks_l->setVisible(false);
			scale_mode = 6;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 6)
	{
		if (scale_cheeks_l->isTapped(pTouch->getLocation()))
		{
			cheek_l->setVisible(true);
			scale_cheeks_l->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 7)
	{
		if (rotate_eyebrow_r->isTapped(pTouch->getLocation()))
		{
			scale_eyebrow_r->setVisible(true);
			rotate_eyebrow_r->setVisible(false);
			scale_mode = 7;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 7)
	{
		if (scale_eyebrow_r->isTapped(pTouch->getLocation()))
		{
			eyebrow_r->setVisible(true);
			scale_eyebrow_r->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	if (rotate_mode_p == 8)
	{
		if (rotate_eyebrow_l->isTapped(pTouch->getLocation()))
		{
			scale_eyebrow_l->setVisible(true);
			rotate_eyebrow_l->setVisible(false);
			scale_mode = 8;
			rotate_mode = 0;
			rotate_mode_p = 0;
			mode_rotate = 0;
		}
	}

	if (scale_mode_p == 8)
	{
		if (scale_eyebrow_l->isTapped(pTouch->getLocation()))
		{
			eyebrow_l->setVisible(true);
			scale_eyebrow_l->setVisible(false);
			scale_mode = 0;
			scale_mode_p = 0;
			flag = true;
			r_mode = 0;
			time_r = 0;
		}
	}

	
	mode = 0;
}

//�^�b�`���\�t���O����
void Scene::gamestart()
{
	flag = true;
	able_to_touch_flag = true; //�������^�b�v���������u�^�b�v�����������������v

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mokugyo.mp3",true);
}

void Scene::keyMenuClicked()
{

	if (flag == true)
	{

		flag = false;
		continu_flag = true;
		CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create("button_continu.png", "buttonPush_continu.png", this, menu_selector(Scene::gamecontinu));
		CCMenu* pMenu = CCMenu::create(pCloseItem1, NULL);
		pMenu->setTouchPriority(kModalLayerMenuPriority);
		pMenu->setPosition(ccp(310, 600));
		//pMenu->setVisible(true);
		this->addChild(pMenu, 1000, 600);

		CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create("end_gamebutton.png", "end_gamebuttonpush.png", this, menu_selector(Scene::gameend));
		CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
		pMenu2->setTouchPriority(kModalLayerMenuPriority);
		pMenu2->setPosition(ccp(310, 400));
		//pMenu2->setVisible(true);
		this->addChild(pMenu2, 1000, 601);

	}
}

void Scene::gamecontinu()
{
	if(continu_flag == true)
	{
		CCMenu* pMenu = (CCMenu*)this->getChildByTag(600);
		CCMenu* pMenu2 = (CCMenu*)this->getChildByTag(601);

		pMenu->removeFromParentAndCleanup(true);
		pMenu2->removeFromParentAndCleanup(true);
		//pMenu2->setVisible(false);
		//pMenu->setVisible(false);
		flag = true;
		continu_flag = false;
	}
}



void Scene::gameend()
{
	flag = false;
	end_game_flag = true;
	continu_flag = false;
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);

	int chin;
	chin = SimpleAudioEngine::sharedEngine()->playEffect("nc42872.mp3");

	CCSprite* dark = (CCSprite*)this->getChildByTag(2);



	Scene* eye_r = (Scene*)this->getChildByTag(100);
	Scene* eye_l = (Scene*)this->getChildByTag(101);
	Scene* nose = (Scene*)this->getChildByTag(102);
	Scene* mouth = (Scene*)this->getChildByTag(103);
	Scene* cheek_r = (Scene*)this->getChildByTag(104);
	Scene* cheek_l = (Scene*)this->getChildByTag(105);
	Scene* eyebrow_r = (Scene*)this->getChildByTag(106);
	Scene* eyebrow_l = (Scene*)this->getChildByTag(107);
	CCMenu* pMenu = (CCMenu*)this->getChildByTag(600);
	CCMenu* pMenu2 = (CCMenu*)this->getChildByTag(601);

	eye_r->setVisible(false);
	eye_l->setVisible(false);
	eyebrow_r->setVisible(false);
	eyebrow_l->setVisible(false);
	nose->setVisible(false);
	mouth->setVisible(false);
	cheek_r->setVisible(false);
	cheek_l->setVisible(false);

	pMenu->removeFromParentAndCleanup(true);
	pMenu2->removeFromParentAndCleanup(true);

	if (end_game_flag == true)
	{
		dark->runAction(CCSequence::create(CCDelayTime::create(3.0f),
			CCFadeOut::create(3), CCDelayTime::create(5.0f), CCCallFunc::create(this, callfunc_selector(Scene::continu_modal)), NULL));

	}
	
	
}

void Scene::continu_modal()
{


	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create("continu.png", "continu_push.png", this, menu_selector(Scene::return_game_));
	CCMenu* pMenu = CCMenu::create(pCloseItem1, NULL);
	pMenu->setTouchPriority(kModalLayerMenuPriority);
	pMenu->setPosition(ccp(200, 902));
	this->addChild(pMenu, 1000, 500);

	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create("button_end.png", "buttonPush_end.png", this, menu_selector(Scene::end_game_));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setTouchPriority(kModalLayerMenuPriority);
	pMenu2->setPosition(ccp(460, 903));
	this->addChild(pMenu2, 1000, 501);

}



void Scene::return_game_(CCObject *pSender)
{
	CCScene* nextScene = Scene::scene();
	CCScene* pScene = CCTransitionFade::create(3, nextScene);
	if (pScene)
		CCDirector::sharedDirector()->replaceScene(pScene);
}

void Scene::end_game_(CCObject *pSender)
{
	CCScene* nextScene = GameScene::scene();
	CCScene* pScene = CCTransitionFade::create(3, nextScene);
	if (pScene)
		CCDirector::sharedDirector()->replaceScene(pScene);
}
