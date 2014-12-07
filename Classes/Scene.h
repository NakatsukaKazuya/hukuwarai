#ifndef __Scene_SCENE_H__
#define __Scene_SCENE_H__

#include "cocos2d.h"



class Scene : public cocos2d::CCLayer
{
private:
	
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
	cocos2d::CCRect getRect();
	virtual void update(float delta);
	virtual void gamestart();
	virtual void gameend();
	void nextAction_eye();
	void nextAction_eyebrow();
	void nextAction_cheeks();
	void nextAction_nose_mouth();

	void rotateAction();

	void gamecontinu();


	void return_game_(CCObject *pSender);
	void end_game_(CCObject *pSender);

	void continu_modal();

    bool flag;
    bool able_to_touch_flag;
	bool touch_mode;
	bool end_game_flag;
	bool game_flag;
	bool continu_flag;
	
	int face_mode;
	int eye_mode;
	int eyebrow_mode;
	int nose_mode;
	int cheeks_mode;
	int mouth_mode;

	int mode;
	int mode_rotate;
	int end_mode;

	float increment_x;
	float increment_y;

	float get_r_eye_r;
	float set_r_eye_r;
	float get_s_eye_r;
	float set_s_eye_r;

	float get_r_eye_l;
	float set_r_eye_l;
	float get_s_eye_l;
	float set_s_eye_l;

	float get_r_nose;
	float set_r_nose;
	float get_s_nose;
	float set_s_nose;

	float get_r_mouth;
	float set_r_mouth;
	float get_s_mouth;
	float set_s_mouth;

	float get_r_cheeks_r;
	float set_r_cheeks_r;
	float get_s_cheeks_r;
	float set_s_cheeks_r;


	float get_r_cheeks_l;
	float set_r_cheeks_l;
	float get_s_cheeks_l;
	float set_s_cheeks_l;

	float get_r_eyebrow_r;
	float set_r_eyebrow_r;
	float get_s_eyebrow_r;
	float set_s_eyebrow_r;


	float get_r_eyebrow_l;
	float set_r_eyebrow_l;
	float get_s_eyebrow_l;
	float set_s_eyebrow_l;

	
	int r_mode;
	int rotate_mode;
	int rotate_mode_p;

	int s_mode;
	int scale_mode;
	int scale_mode_p;
	
	int time_r;
	int eye_counter;
	int eyebrow_counter;
	int cheeks_counter;
	int nose_mouth_counter;
	
	
	
	bool isTapped(cocos2d::CCPoint);
	
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	

	// ���j���[�L�[
	void keyMenuClicked();

	// implement the "static node()" method manually
    CREATE_FUNC(Scene);
};

#endif // __Scene_SCENE_H__
