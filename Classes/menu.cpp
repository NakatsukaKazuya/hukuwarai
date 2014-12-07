#include"GameScene.h"
#include "menu.h"
#include"ModalLayer.h"
#include"Scene.h"


#define kModalLayerPriority kCCMenuHandlerPriority-1
#define kModalLayerMenuPriority kCCMenuHandlerPriority-2

static Menu* instsnceMenuScene;

USING_NS_CC;

CCScene* Menu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Menu *layer = Menu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

Menu *Menu::shareMenu()
{
	return instsnceMenuScene;
}

bool Menu::isTapped(CCPoint point)
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

CCRect Menu::getRect()
{
	CCPoint point = this->getPosition();
	int w = this->getContentSize().width * this->getScaleX();
	int h = this->getContentSize().height * this->getScaleY();
	return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}




//������
bool Menu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	//�^�b�`���[�h����
	this->setTouchMode(kCCTouchesOneByOne);
	//�^�b�`�L����
	this->setTouchEnabled(true);
	this->setTouchPriority(kModalLayerPriority);

	this->setKeypadEnabled(true);

	//�V���O���g��
	instsnceMenuScene = this;

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//
//
	face_mode = 0; //���p�^�[��
	eye_mode = 0; //���p�^�[��
	eyebrow_mode = 0; //���p�^�[��
	nose_mode = 0; //�@�p�^�[��
	cheeks_mode = 0; //�j�p�^�[��
	mouth_mode = 0; //���p�^�[��
//
	Touch_flag = false; //�^�b�`�t���O
	buttonPush_flag = false; //�X�^�[�g�{�^���t���O
//
//	//�X�v���C�g��������������
	CCRect rect = CCRectMake(0, 0, 100, 100);
//
//	//�����X�v���C�g����
	CCSprite *pSprite1 = CCSprite::create();
	pSprite1->setTextureRect(rect);
	pSprite1->setVisible(false);

//	//背景
	CCSprite* bg = CCSprite::create("sample_back.png");
//
//
	CCSprite* txt_face = CCSprite::create("txt_face.png");
	txt_face->setScale(0.25);
	txt_face->setPosition(ccp(575,840));

	CCSprite* txt_eye = CCSprite::create("txt_eye.png");
	txt_eye->setScale(0.7);
	txt_eye->setPosition(ccp(570,660));

	CCSprite* txt_nose = CCSprite::create("txt_nose.png");
	txt_nose->setScale(0.7);
	txt_nose->setPosition(ccp(575,560));

	CCSprite* txt_eyebrow = CCSprite::create("txt_eyebrow.png");
	txt_eyebrow->setScale(0.6);
	txt_eyebrow->setPosition(ccp(575,450));

	CCSprite* txt_cheek = CCSprite::create("txt_cheek.png");
	txt_cheek->setScale(0.8);
	txt_cheek->setPosition(ccp(570,340));

	CCSprite* txt_mouth = CCSprite::create("txt_mouth.png");
	txt_mouth->setScale(0.75);
	txt_mouth->setPosition(ccp(575,220));
//
	//顔
	CCSprite* face1 = CCSprite::create("face.png");
	//CCSprite* face2 = CCSprite::create("face_2.png");
	CCSprite* face3 = CCSprite::create("face_3.png");
	CCSprite* face4 = CCSprite::create("face4.png");
	face1->setScale(0.25);
	//face2->setScale(0.25);
	face3->setScale(0.25);
	face4->setScale(0.25);
	face1->setPosition(ccp(80, 840));
	//face2->setPosition(ccp(245,840));
	face3->setPosition(ccp(410, 840));
	face4->setPosition(ccp(245, 840));
//
	//目
	CCSprite* face1_eye = CCSprite::create("eye_r.png");
	//CCSprite* face2_eye = CCSprite::create("face_2_eye_r.png");
	CCSprite* face3_eye = CCSprite::create("face3_eye_r.png");
	CCSprite* face4_eye = CCSprite::create("face4_eye_r.png");
	face1_eye->setPosition(ccp(80,660));
	//face2_eye->setPosition(ccp(245, 660));
	face3_eye->setPosition(ccp(410, 660));
	face4_eye->setPosition(ccp(245, 660));
	face1_eye->setScale(0.8);
	//face2_eye->setScale(0.7);
	//face3_eye->setScale(0.7);
	face1_eye->setOpacity(150);
	//face2_eye->setOpacity(150);
	face3_eye->setOpacity(150);
	face4_eye->setOpacity(150);
	//鼻
	CCSprite* face1_nose = CCSprite::create("nose.png");
	//CCSprite* face2_nose = CCSprite::create("face_2_nose.png");
	CCSprite* face3_nose = CCSprite::create("face3_nose.png");
	CCSprite* face4_nose = CCSprite::create("face_4_nose.png");
	face1_nose->setPosition(ccp(80, 560));
	//face2_nose->setPosition(ccp(245, 560));
	face3_nose->setPosition(ccp(410, 560));
	face4_nose->setPosition(ccp(245, 560));
	face1_nose->setScale(0.8);
	//face2_nose->setScale(0.7);
	face3_nose->setScale(0.8);
	face4_nose->setScale(1.3);
	face1_nose->setOpacity(150);
	//face2_nose->setOpacity(150);
	face3_nose->setOpacity(150);
	face4_nose->setOpacity(150);

	//眉
	CCSprite* face1_eyebrow = CCSprite::create("eyebrow_r.png");
	//CCSprite* face2_eyebrow = CCSprite::create("face_2_eyebrow_r.png");
	CCSprite* face3_eyebrow = CCSprite::create("face3_eyebrow_r.png");
	CCSprite* face4_eyebrow = CCSprite::create("face4_eyebrow_r.png");
	face1_eyebrow->setPosition(ccp(80, 450));
	//face2_eyebrow->setPosition(ccp(245, 445));
	face3_eyebrow->setPosition(ccp(410, 450));
	face4_eyebrow->setPosition(ccp(245, 445));

	face1_eyebrow->setScale(0.8);
	//face2_eyebrow->setScale(0.55);
	//face3_eyebrow->setScale(0.55);
	//face2_eyebrow->setRotation(25);
	face4_eyebrow->setScale(2.3);
	face1_eyebrow->setOpacity(150);
	//face2_eyebrow->setOpacity(150);
	face3_eyebrow->setOpacity(150);
	face4_eyebrow->setOpacity(150);

	//頬
	CCSprite* face1_cheek = CCSprite::create("cheeks_r.png");
	CCSprite* face2_cheek = CCSprite::create("face_2_cheeks_r.png");
	CCSprite* not_cheek = CCSprite::create("not_cheek.png");

	face1_cheek->setPosition(ccp(80, 340));
	face2_cheek->setPosition(ccp(245, 340));
	not_cheek->setPosition(ccp(405, 340));
	face1_cheek->setScale(0.8);
	face2_cheek->setScale(0.8);
	not_cheek->setScale(0.8);
	face1_cheek->setOpacity(150);
	face2_cheek->setOpacity(150);
	not_cheek->setOpacity(150);

	//口
	CCSprite* face1_mouth = CCSprite::create("mouse.png");
	//CCSprite* face2_mouth = CCSprite::create("face_2_mouth.png");
	CCSprite* face3_mouth = CCSprite::create("face3_mouth.png");
	CCSprite* face4_mouth = CCSprite::create("face4_mouth.png");
	face1_mouth->setPosition(ccp(80, 220));
	//face2_mouth->setPosition(ccp(245, 220));
	face3_mouth->setPosition(ccp(410, 220));
	face4_mouth->setPosition(ccp(245, 220));
	face1_mouth->setScale(0.8);
	//face2_mouth->setScale(0.75);
	face3_mouth->setScale(0.75);
	face1_mouth->setOpacity(150);
	//face2_mouth->setOpacity(150);
	face3_mouth->setOpacity(150);
	face4_mouth->setOpacity(150);
//
//	//黒画像
	CCSprite* dark = CCSprite::create("dark.jpg");
	dark->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	dark->setOpacity(200);
//
	//ボタン（押不可）
	CCSprite* btnPush = CCSprite::create("buttonPush_menu.png");
	btnPush->setPosition(ccp(visibleSize.width / 2,  100));
	btnPush->setScale(1.2);


//
	bg->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	pSprite1->runAction(CCSequence::create(CCDelayTime::create(3.0f),CCCallFunc::create(this, callfunc_selector(Menu::Modallayer_1)), NULL));
//
	face1->setOpacity(150);
	//face2->setOpacity(150);
	face3->setOpacity(150);
	face4->setOpacity(150);
//
//	//画像の表示-----------------------------
	this->addChild(bg,0,1);
//
	this->addChild(face1, 15, 20);
	//this->addChild(face2, 15, 30);
	this->addChild(face3, 15, 40);
	this->addChild(face4, 15, 50);
//
	this->addChild(face1_eye, 15, 21);
	//this->addChild(face2_eye, 15, 31);
	this->addChild(face3_eye, 15, 41);
	this->addChild(face4_eye, 15, 51);

	this->addChild(face1_nose, 15, 22);
	//this->addChild(face2_nose, 15, 32);
	this->addChild(face3_nose, 15, 42);
	this->addChild(face4_nose, 15, 52);

	this->addChild(face1_eyebrow, 15, 23);
	//this->addChild(face2_eyebrow, 15, 33);
	this->addChild(face3_eyebrow, 15, 43);
	this->addChild(face4_eyebrow, 15, 53);

	this->addChild(face1_cheek, 15, 24);
	this->addChild(face2_cheek, 15, 34);
	this->addChild(not_cheek, 15, 44);

	this->addChild(face1_mouth, 15, 25);
	//this->addChild(face2_mouth, 15, 35);
	this->addChild(face3_mouth, 15, 45);
	this->addChild(face4_mouth, 15, 55);
//
	this->addChild(pSprite1, 0, 0);
//
	this->addChild(dark, 102, 13);
//
	this->addChild(btnPush, 30, 5);

	this->addChild(txt_face,100,100);
	this->addChild(txt_eye,100,100);
	this->addChild(txt_nose,100,100);
	this->addChild(txt_eyebrow,100,100);
	this->addChild(txt_cheek,100,100);
	this->addChild(txt_mouth,100,100);
//	//---------------------------------------
//

    
    return true;
}


//タップ始め
bool Menu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	Menu* face1 = (Menu*)this->getChildByTag(20);
	//Menu* face2 = (Menu*)this->getChildByTag(30);
	Menu* face3 = (Menu*)this->getChildByTag(40);
	Menu* face4 = (Menu*)this->getChildByTag(50);
	CCSprite* face_1 = (CCSprite*)this->getChildByTag(20);
	//CCSprite* face_2 = (CCSprite*)this->getChildByTag(30);
	CCSprite* face_3 = (CCSprite*)this->getChildByTag(40);
	CCSprite* face_4 = (CCSprite*)this->getChildByTag(50);

	Menu* face1_eye = (Menu*)this->getChildByTag(21);
	//Menu* face2_eye = (Menu*)this->getChildByTag(31);
	Menu* face3_eye = (Menu*)this->getChildByTag(41);
	Menu* face4_eye = (Menu*)this->getChildByTag(51);
	CCSprite* face_1_eye = (CCSprite*)this->getChildByTag(21);
	//CCSprite* face_2_eye = (CCSprite*)this->getChildByTag(31);
	CCSprite* face_3_eye = (CCSprite*)this->getChildByTag(41);
	CCSprite* face_4_eye = (CCSprite*)this->getChildByTag(51);

	Menu* face1_nose = (Menu*)this->getChildByTag(22);
	//Menu* face2_nose = (Menu*)this->getChildByTag(32);
	Menu* face3_nose = (Menu*)this->getChildByTag(42);
	Menu* face4_nose = (Menu*)this->getChildByTag(52);
	CCSprite* face_1_nose = (CCSprite*)this->getChildByTag(22);
	//CCSprite* face_2_nose = (CCSprite*)this->getChildByTag(32);
	CCSprite* face_3_nose = (CCSprite*)this->getChildByTag(42);
	CCSprite* face_4_nose = (CCSprite*)this->getChildByTag(52);

	Menu* face1_eyebrow = (Menu*)this->getChildByTag(23);
	//Menu* face2_eyebrow = (Menu*)this->getChildByTag(33);
	Menu* face3_eyebrow = (Menu*)this->getChildByTag(43);
	Menu* face4_eyebrow = (Menu*)this->getChildByTag(53);
	CCSprite* face_1_eyebrow = (CCSprite*)this->getChildByTag(23);
	//CCSprite* face_2_eyebrow = (CCSprite*)this->getChildByTag(33);
	CCSprite* face_3_eyebrow = (CCSprite*)this->getChildByTag(43);
	CCSprite* face_4_eyebrow = (CCSprite*)this->getChildByTag(53);

	Menu* face1_cheek = (Menu*)this->getChildByTag(24);
	Menu* face2_cheek = (Menu*)this->getChildByTag(34);
	Menu* not_cheek = (Menu*)this->getChildByTag(44);
	CCSprite* face_1_cheek = (CCSprite*)this->getChildByTag(24);
	CCSprite* face_2_cheek = (CCSprite*)this->getChildByTag(34);
	CCSprite* not_0_cheek = (CCSprite*)this->getChildByTag(44);


	Menu* face1_mouth = (Menu*)this->getChildByTag(25);
	//Menu* face2_mouth = (Menu*)this->getChildByTag(35);
	Menu* face3_mouth = (Menu*)this->getChildByTag(45);
	Menu* face4_mouth = (Menu*)this->getChildByTag(55);
	CCSprite* face_1_mouth = (CCSprite*)this->getChildByTag(25);
	//CCSprite* face_2_mouth = (CCSprite*)this->getChildByTag(35);
	CCSprite* face_3_mouth = (CCSprite*)this->getChildByTag(45);
	CCSprite* face_4_mouth = (CCSprite*)this->getChildByTag(55);

	if(Touch_flag == true)
	{
		if (face1->isTapped(pTouch->getLocation()))
		{
			face_mode = 1;

			face_1->setOpacity(255);
			//face_2->setOpacity(150);
			face_3->setOpacity(150);
			face_4->setOpacity(150);

		}

		/*if (face2->isTapped(pTouch->getLocation()))
		{
			face_mode = 2;

			face_1->setOpacity(150);
			face_2->setOpacity(255);
			face_3->setOpacity(150);
		}*/

		if (face3->isTapped(pTouch->getLocation()))
		{
			face_mode = 3;

			face_1->setOpacity(150);
			//face_2->setOpacity(150);
			face_3->setOpacity(255);
			face_4->setOpacity(150);
		}

		if (face4->isTapped(pTouch->getLocation()))
		{
			face_mode = 4;

			face_1->setOpacity(150);
			face_4->setOpacity(255);
			face_3->setOpacity(150);
		}

		if (face1_eye->isTapped(pTouch->getLocation()))
		{
			eye_mode = 1;
			face_1_eye->setOpacity(255);
			//face_2_eye->setOpacity(150);
			face_3_eye->setOpacity(150);
			face_4_eye->setOpacity(150);
		}

		/*if (face2_eye->isTapped(pTouch->getLocation()))
		{
			eye_mode = 2;
			face_1_eye->setOpacity(150);
			face_2_eye->setOpacity(255);
			face_3_eye->setOpacity(150);
		}*/

		if (face3_eye->isTapped(pTouch->getLocation()))
		{
			eye_mode = 3;
			face_1_eye->setOpacity(150);
			//face_2_eye->setOpacity(150);
			face_3_eye->setOpacity(255);
			face_4_eye->setOpacity(150);
		}

		if (face4_eye->isTapped(pTouch->getLocation()))
		{
			eye_mode = 4;
			face_1_eye->setOpacity(150);
			face_4_eye->setOpacity(255);
			face_3_eye->setOpacity(150);
		}

		if (face1_nose->isTapped(pTouch->getLocation()))
		{
			nose_mode = 1;
			face_1_nose->setOpacity(255);
			//face_2_nose->setOpacity(150);
			face_3_nose->setOpacity(150);
			face_4_nose->setOpacity(150);
		}

		/*if (face2_nose->isTapped(pTouch->getLocation()))
		{
			nose_mode = 2;
			face_1_nose->setOpacity(150);
			face_2_nose->setOpacity(255);
			face_3_nose->setOpacity(150);
		}*/

		if (face3_nose->isTapped(pTouch->getLocation()))
		{
			nose_mode = 3;
			face_1_nose->setOpacity(150);
			//face_2_nose->setOpacity(150);
			face_3_nose->setOpacity(255);
			face_4_nose->setOpacity(150);

		}

		if (face4_nose->isTapped(pTouch->getLocation()))
		{
			nose_mode = 4;
			face_1_nose->setOpacity(150);
			face_4_nose->setOpacity(255);
			face_3_nose->setOpacity(150);
		}

		if (face1_eyebrow->isTapped(pTouch->getLocation()))
		{
			eyebrow_mode = 1;
			face_1_eyebrow->setOpacity(255);
			//face_2_eyebrow->setOpacity(150);
			face_3_eyebrow->setOpacity(150);
			face_4_eyebrow->setOpacity(150);
		}

		/*if (face2_eyebrow->isTapped(pTouch->getLocation()))
		{
			eyebrow_mode = 2;
			face_1_eyebrow->setOpacity(150);
			face_2_eyebrow->setOpacity(255);
			face_3_eyebrow->setOpacity(150);
		}*/

		if (face3_eyebrow->isTapped(pTouch->getLocation()))
		{
			eyebrow_mode = 3;
			face_1_eyebrow->setOpacity(150);
			//face_2_eyebrow->setOpacity(150);
			face_3_eyebrow->setOpacity(255);
			face_4_eyebrow->setOpacity(150);
		}

		if (face4_eyebrow->isTapped(pTouch->getLocation()))
		{
			eyebrow_mode = 4;
			face_1_eyebrow->setOpacity(150);
			face_4_eyebrow->setOpacity(255);
			face_3_eyebrow->setOpacity(150);
		}

		if (face1_cheek->isTapped(pTouch->getLocation()))
		{
			cheeks_mode = 1;
			face_1_cheek->setOpacity(255);
			face_2_cheek->setOpacity(150);
			not_0_cheek->setOpacity(150);
		}

		if (face2_cheek->isTapped(pTouch->getLocation()))
		{
			cheeks_mode = 2;
			face_1_cheek->setOpacity(150);
			face_2_cheek->setOpacity(255);
			not_0_cheek->setOpacity(150);
		}

		if (not_cheek->isTapped(pTouch->getLocation()))
		{
			cheeks_mode = 3;
			not_0_cheek->setOpacity(255);
			face_1_cheek->setOpacity(150);
			face_2_cheek->setOpacity(150);
		}

		if (face1_mouth->isTapped(pTouch->getLocation()))
		{
			mouth_mode = 1;
			face_1_mouth->setOpacity(255);
			//face_2_mouth->setOpacity(150);
			face_3_mouth->setOpacity(150);
			face_4_mouth->setOpacity(150);
		}

		/*if (face2_mouth->isTapped(pTouch->getLocation()))
		{
			mouth_mode = 2;
			face_1_mouth->setOpacity(150);
			face_2_mouth->setOpacity(255);
			face_3_mouth->setOpacity(150);
		}*/

		if (face3_mouth->isTapped(pTouch->getLocation()))
		{
			mouth_mode = 3;
			face_1_mouth->setOpacity(150);
			//face_2_mouth->setOpacity(150);
			face_3_mouth->setOpacity(255);
			face_4_mouth->setOpacity(150);
		}

		if (face4_mouth->isTapped(pTouch->getLocation()))
		{
			mouth_mode = 4;
			face_1_mouth->setOpacity(150);
			face_4_mouth->setOpacity(255);
			face_3_mouth->setOpacity(150);
		}
	}
	CCSprite* box = (CCSprite*)this->getChildByTag(0);
	if (buttonPush_flag == false)
	{
		if (face_mode > 0 && eye_mode > 0 && eyebrow_mode > 0 && nose_mode > 0 && cheeks_mode > 0 && mouth_mode > 0)
		{
			CCCallFunc* pFunc = CCCallFunc::create(this, callfunc_selector(Menu::start_button));
			box->runAction(pFunc);
		}
	}
	return true;
}

//スタートボタン表示
void Menu::start_button()
{
	buttonPush_flag = true;
	CCSprite* btn_delete = (CCSprite*)this->getChildByTag(5);
	btn_delete->removeFromParentAndCleanup(true);

	CCSprite* btn = CCSprite::create("button_menu.png");
	CCSprite* btnPush2 = CCSprite::create("buttonpush_menu.png");
	CCMenuItemSprite* menu = CCMenuItemSprite::create(btn, btnPush2, this, menu_selector(Menu::Game_Scene));
	menu->setPosition(ccp(0,-380));
	menu->setScale(1.2);
	CCMenu* cmenu = CCMenu::create(menu, NULL);

	cmenu->setTouchPriority(kModalLayerMenuPriority);
	this->addChild(cmenu, 30, 6);

}

void Menu::Modallayer_1()
{



	//モーダルレイヤー表示
	ModalLayer* layer = ModalLayer::create();
	CCSprite* btn2 = CCSprite::create("OK_button.png");
	CCSprite* btnPush2 = CCSprite::create("OKPush_button.png");
	CCMenuItemSprite* menu_btn = CCMenuItemSprite::create(btn2,btnPush2,this,menu_selector(Menu::remove_sprite));

	CCSprite* choose_parts = CCSprite::create("parts_chooes.png");
	choose_parts->setScale(0.5);
	menu_btn->setPosition(ccp(0,-30));
	choose_parts->setPosition(ccp(320,530));
	CCMenu* cmenu_btn = CCMenu::create(menu_btn,NULL);
	cmenu_btn->setTouchPriority(kModalLayerMenuPriority);




	this->addChild(cmenu_btn,104,10);
	this->addChild(choose_parts,104,12);
	this->addChild(layer,103,11);



}

//始めのモーダルレイヤーやボタン、テキストの削除
void Menu::remove_sprite(CCObject *pSender)
{
	CCSprite* dark = (CCSprite*)this->getChildByTag(13);
	dark->removeFromParentAndCleanup(true);
	CCMenu* menu2 = (CCMenu*)this->getChildByTag(10);
	menu2->removeFromParentAndCleanup(true);
	ModalLayer *layer = (ModalLayer*)this->getChildByTag(11);
	layer->removeFromParentAndCleanup(true);
	CCSprite* choose_parts = (CCSprite*)this->getChildByTag(12);
	choose_parts->removeFromParentAndCleanup(true);

	Touch_flag = true;
}



//Sceneへ移動　変数の保存
void Menu::Game_Scene(CCObject *pSender)
{
	//変数の保存--------------------------------------
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();

	userDefault->setIntegerForKey("face", face_mode);
	userDefault->setIntegerForKey("eye", eye_mode);
	userDefault->setIntegerForKey("eyebrow", eyebrow_mode);
	userDefault->setIntegerForKey("nose", nose_mode);
	userDefault->setIntegerForKey("cheeks", cheeks_mode);
	userDefault->setIntegerForKey("mouth", mouth_mode);
	userDefault->flush();
	//-------------------------------------------------
	CCScene* menuScene = Scene::scene();
	CCScene* pScene = CCTransitionFade::create(3, menuScene);
	if (pScene)
		CCDirector::sharedDirector()->replaceScene(pScene);
}

void Menu::keyBackClicked()
{
	CCScene* titleScene = GameScene::scene();
	CCScene* pScene = CCTransitionFade::create(3, titleScene);
		if (pScene)
			CCDirector::sharedDirector()->replaceScene(pScene);
}
