#include "BackgroundLayer.h"

bool BackgroundLayer::init(){
	if (!Layer::init()){
		return false;
	}

	srand(time(NULL));
	int background_num = rand() %3;

	Sprite *background;

	if (background_num == 0) {
		//À¶É«
		background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_0"));
		this->cloud1 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_0"));
		this->cloud2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_0"));
		this->cloud3 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_0"));
	} else if (background_num == 1) {
		//¿§·ÈÉ«
		background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_1"));
		this->cloud1 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_1"));
		this->cloud2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_1"));
		this->cloud3 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_1"));
	} else{
		//×ÏÉ«
		background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_2"));
		this->cloud1 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_2"));
		this->cloud2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_2"));
		this->cloud3 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_2"));
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(background);

	this->land = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
	this->land->setAnchorPoint(Vec2(0.5, 1));
	this->land->setPosition(origin.x + visibleSize.width / 2, origin.y + this->land->getContentSize().height);
	this->addChild(this->land, 3);

	this->tree = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("tree"));
	this->tree->setAnchorPoint(Vec2(0.5, 1));
	this->tree->setPosition(origin.x + visibleSize.width / 2, origin.y + tree->getContentSize().height);
	this->addChild(this->tree, 2);

	this->cloud1->setAnchorPoint(Vec2(0.5, 1));
	this->cloud1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + this->tree->getContentSize().height + this->cloud1->getContentSize().height - this->cloud1->getContentSize().height / 10));
	this->addChild(this->cloud1, 1);

	this->cloud2->setAnchorPoint(Vec2(0.5, 1));
	this->cloud2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + this->cloud1->getPositionY() + this->cloud2->getContentSize().height));
	this->addChild(this->cloud2, 1);

	this->cloud3->setAnchorPoint(Vec2(0.5, 1));
	this->cloud3->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + this->cloud2->getPositionY() + this->cloud3->getContentSize().height));
	this->addChild(this->cloud3, 1);

	shiftBackground = schedule_selector(BackgroundLayer::scrollBackground);
	this->schedule(shiftBackground, 0.01f);

	return true;
}

void BackgroundLayer::scrollBackground(float dt){
	if (this->tree->getPositionY() > 0) {
		this->tree->setPositionY(this->tree->getPositionY() - 2.0f);
	}

	if (this->land->getPositionY() > 0) {
		this->land->setPositionY(this->land->getPositionY() - 2.0f);
	}
	this->cloud1->setPositionY(this->cloud1->getPositionY() - 2.0f);
	this->cloud2->setPositionY(this->cloud2->getPositionY() - 2.0f);
	this->cloud3->setPositionY(this->cloud3->getPositionY() - 2.0f);

	if (this->cloud1->getPositionY() <= 0) {
		this->cloud1->setPositionY(cloud3->getPositionY() + this->cloud3->getContentSize().height);
	}

	if (this->cloud2->getPositionY() <= 0) {
		this->cloud2->setPositionY(cloud1->getPositionY() + this->cloud1->getContentSize().height);
	}

	if (this->cloud3->getPositionY() <= 0) {
		this->cloud3->setPositionY(cloud2->getPositionY() + this->cloud2->getContentSize().height);
	}
}

void BackgroundLayer::stopScrollBackground(){
	this->unschedule(shiftBackground);
}
