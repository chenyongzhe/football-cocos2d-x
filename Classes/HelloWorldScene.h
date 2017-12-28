#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "physics.h"
using namespace cocos2d::ui;
class HelloWorld : public cocos2d::Layer
{

public :
	Layout *root1;
	ImageView *img1;
	ImageView *img2;
	Text  * name_text;
	Button * startbutton1;
	void StartGame1(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void SelectPenson(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
