#include "HelloWorldScene.h"
#include "role.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    



    auto rootNode = CSLoader::createNode("MainScene.csb");
	root1 = (Layout*)rootNode->getChildByName("root1");
	name_text = (Text *)Helper::seekWidgetByName(root1, "name_text");
	img1 = (ImageView *)Helper::seekWidgetByName(root1, "man");
	img2 = (ImageView *)Helper::seekWidgetByName(root1, "woman");
	img1->setTouchEnabled(true);
	img2->setTouchEnabled(true);
	img1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::SelectPenson, this));
	img2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::SelectPenson, this));
	img1->setTag(1);
	img2->setTag(2);
	Role *role1 = new Role(1, "jeek");
    Role *role2 = new Role(2, "rose");

	img1->setUserObject(role1);
	img2->setUserObject(role2);


	startbutton1 = (Button *)Helper::seekWidgetByName(root1, "Button1");
	startbutton1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::StartGame1, this));

    addChild(rootNode);







    return true;
}


void HelloWorld::SelectPenson(Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
	switch (type)
	{
	
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		int i=((ImageView *)pSender)->getTag();
		Role *role = (Role *)((ImageView *)pSender)->getUserObject();
		name_text->setString(role->role_name);
		break;
	
	}









}



void HelloWorld::StartGame1(Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {

	switch (type)
	{
	case Widget::TouchEventType::BEGAN: {
		break;
	}
	case   Widget::TouchEventType::MOVED: {
		break;
	}
	case Widget::TouchEventType::ENDED: {
		//auto scene1 = HelloWorld::createScene();
		auto director = Director::getInstance();
		auto scen = Physics::createScene();
		director->replaceScene(scen);
		break;
	}
	case cocos2d::ui::Widget::TouchEventType::CANCELED: {
		break; }
	default:
		break;
	}






}

