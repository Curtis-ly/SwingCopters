#include "PicViewerScene.h"

Scene* PicViewerScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = PicViewerScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PicViewerScene::init()
{
    //////////////////////////////
    // 1. super init first
	if (!Layer::init())
    {
        return false;
    }

	_spriteFrames = AtlasLoader::getInstance()->getSpriteFrame();
	pos = 0;

	if (_spriteFrames.empty()) {
		return false;
	}
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	pic = Sprite::createWithSpriteFrame(getSpriteFrameByIndex(pos));
	pic->setPosition(Vec2(visibleSize / 2) + origin);
	pic->setTag(0x1234);
	this->addChild(pic);
    
	Sprite *left_arrow_nor = Sprite::create("left_arrow_btn.png");
	Sprite *left_arrow_sel = Sprite::create("left_arrow_btn.png");
	Sprite *right_arrow_nor = Sprite::create("right_arrow_btn.png");
	Sprite *right_arrow_sel = Sprite::create("right_arrow_btn.png");

	left_arrow_sel->setPositionY(-5);
	right_arrow_sel->setPositionY(-5);
	
	auto left_menuItem = MenuItemSprite::create(left_arrow_nor, left_arrow_sel, NULL, CC_CALLBACK_1(PicViewerScene::LeftMenuItemCallback, this));
	left_menuItem->setPosition(Vec2(origin.x + left_arrow_nor->getContentSize().width / 2, origin.y + visibleSize.height / 2));
	auto left_menu = Menu::create(left_menuItem, NULL);
	left_menu->setPosition(Vec2::ZERO);
	this->addChild(left_menu, 1);

	auto right_menuItem = MenuItemSprite::create(right_arrow_nor, right_arrow_sel, NULL, CC_CALLBACK_1(PicViewerScene::RightMenuItemCallback, this));
	right_menuItem->setPosition(Vec2(origin.x + visibleSize.width - left_arrow_nor->getContentSize().width / 2, origin.y + visibleSize.height / 2));
	auto right_menu = Menu::create(right_menuItem, NULL);
	right_menu->setPosition(Vec2::ZERO);
	this->addChild(right_menu, 1);

	label = LabelTTF::create("", "Arial", 46);
	label->setString(getSpriteNameByIndex(pos).c_str());

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

    return true;
}

SpriteFrame* PicViewerScene::getSpriteFrameByIndex(int index) {
	int i = 0;
	SpriteFrame* ret;

	if (index >= _spriteFrames.size()) {
		index = 0;
	}
	for(auto var : _spriteFrames)
	{
		if (index == i) {
			ret = var.second;
			break;
		}
		i++;
	}

	return ret;
}

string PicViewerScene::getSpriteNameByIndex(int index) {
	int i = 0;
	string ret;

	if (index >= _spriteFrames.size()) {
		index = 0;
	}

	for (auto var : _spriteFrames)
	{
		if (index == i) {
			ret = var.first;
			break;
		}
		i++;
	}

	return ret;
}

void PicViewerScene::LeftMenuItemCallback(Ref* sender)
{
	pos--;
	if (pos <= 0) {
		pos = _spriteFrames.size() - 1;
	}
	pic->setDisplayFrame(getSpriteFrameByIndex(pos));
	label->setString(getSpriteNameByIndex(pos).c_str());
}

void PicViewerScene::RightMenuItemCallback(Ref* sender)
{
	pos++;
	if (pos >= _spriteFrames.size()) {
		pos = 0;
	}
	pic->setDisplayFrame(getSpriteFrameByIndex(pos));
	label->setString(getSpriteNameByIndex(pos).c_str());
}
