#ifndef __P_SCENE_H__
#define __P_SCENE_H__
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
class Physics : public cocos2d::Layer
{


public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void addNewSpriteAtPosition(cocos2d::Vec2 p);

	// implement the "static create()" method manually
	CREATE_FUNC(Physics);
};

#endif // __P_SCENE_H__

