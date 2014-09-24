#include "WelcomeScene.h"

Scene* WelcomeScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = WelcomeScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool WelcomeScene::init()
{
    //////////////////////////////
    // 1. super init first
	if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	Sprite *background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_0"));
	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(background);

	Sprite *land = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
	land->setPosition(origin.x + visibleSize.width / 2, origin.y + land->getContentSize().height / 2);
	this->addChild(land, 2);

	Sprite *tree = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("tree"));
	tree->setPosition(origin.x + visibleSize.width / 2, origin.y + tree->getContentSize().height / 2);
	this->addChild(tree, 1);

	Sprite *cloud = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_0"));
	cloud->setPosition(origin.x + visibleSize.width / 2, origin.y + tree->getContentSize().height + cloud->getContentSize().height * 2 / 5);
	this->addChild(cloud, 1);

	Sprite *cloud2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("cloud_0"));
	cloud2->setPosition(origin.x + visibleSize.width / 2, origin.y + tree->getContentSize().height + cloud->getContentSize().height * 9 / 10 + cloud2->getContentSize().height / 2);
	this->addChild(cloud2, 1);

	//创建copyright精灵
	Sprite *copyright = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("copyright"));
	copyright->setPosition(origin.x + visibleSize.width / 2, origin.y + land->getContentSize().height / 2);
	this->addChild(copyright, 3);


	//创建start和排行榜菜单
	Sprite *start_nor = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_start"));
	Sprite *start_sel = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_start"));
	start_sel->setPositionY(-3);
	auto start_menuItem = MenuItemSprite::create(start_nor, start_sel, NULL, CC_CALLBACK_1(WelcomeScene::StartMenuCallback, this));
	Sprite *score_nor = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_score"));
	Sprite *score_sel = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_score"));
	score_sel->setPositionY(-3);
	auto score_menuItem = MenuItemSprite::create(score_nor, score_sel, NULL, CC_CALLBACK_1(WelcomeScene::ScoreMenuCallback, this));
	float start_score_gap = (visibleSize.width - start_nor->getContentSize().width - score_nor->getContentSize().width) / 2.0;


	start_menuItem->setPosition(Vec2(origin.x + start_score_gap + start_nor->getContentSize().width * 3 / 8, origin.y + land->getContentSize().height - start_nor->getContentSize().width / 5));
	score_menuItem->setPosition(Vec2(origin.x + visibleSize.width - start_score_gap - score_nor->getContentSize().width * 3 / 8, origin.y + land->getContentSize().height - score_nor->getContentSize().width / 5));
	auto start_menu = Menu::create(start_menuItem, NULL);
	auto score_menu = Menu::create(score_menuItem, NULL);
	start_menu->setPosition(Vec2::ZERO);
	score_menu->setPosition(Vec2::ZERO);
	this->addChild(start_menu, 3);
	this->addChild(score_menu, 3);

	//创建RATE菜单
	Sprite *rate_nor = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_rate"));
	Sprite *rate_sel = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_rate"));
	rate_sel->setPositionY(-3);
	auto rate_menuItem = MenuItemSprite::create(rate_nor, rate_sel, NULL, CC_CALLBACK_1(WelcomeScene::RateMenuCallback, this));
	rate_menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + tree->getContentSize().height));
	auto rate_menu = Menu::create(rate_menuItem, NULL);
	rate_menu->setPosition(Vec2::ZERO);
	this->addChild(rate_menu, 4);

	//创建REMOVE ADS菜单
	Sprite *remove_ads_nor = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_ads"));
	Sprite *remove_ads_sel = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_ads"));
	remove_ads_sel->setPositionY(-3);
	auto remove_ads_menuItem = MenuItemSprite::create(remove_ads_nor, remove_ads_sel, NULL, CC_CALLBACK_1(WelcomeScene::RemoveAdsMenuCallback, this));
	remove_ads_menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + remove_ads_nor->getContentSize().height * 1 / 8));
	auto remove_ads_menu = Menu::create(remove_ads_menuItem, NULL);
	remove_ads_menu->setPosition(Vec2::ZERO);
	this->addChild(remove_ads_menu, 3);


	//create a title and set the position in the center of the screen
	Sprite* title = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title_00"));
	title->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.68 - 4));

	//create the title animation
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title_00"));
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title_01"));
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title_02"));
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title_03"));
	//bind the animate to the title
	Animate* animate = Animate::create(animation);
	auto *fly = MoveBy::create(0.65f, Vec2(0, 8));
	auto *flyBack = fly->reverse();
	Sequence *swing = Sequence::create(fly, flyBack, NULL);
	title->runAction(RepeatForever::create(animate));
	title->runAction(RepeatForever::create(swing));
	this->addChild(title, 4);


	//创建左边障碍物精灵
	Sprite *letf_crane = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("crane"));
	letf_crane->setPosition(origin.x - letf_crane->getContentSize().width * 5 / 18, origin.y + visibleSize.height * 0.68);

	Sprite *letf_hammer = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("hammer"));
	letf_hammer->setAnchorPoint(Vec2(0.5, 1));
	letf_hammer->setPosition(Vec2(origin.x + letf_crane->getContentSize().width * 3 / 19, origin.y + visibleSize.height * 0.68 + letf_crane->getContentSize().height / 3));
	letf_hammer->setRotation(20);
	this->addChild(letf_crane, 3);
	this->addChild(letf_hammer, 3);
	//创建左边锤子动画
	auto *left_hammer_swing = RotateBy::create(1.5f, -40);
	auto *left_hammer_swingBack = left_hammer_swing->reverse();
	Sequence *left_hammer_sequence = Sequence::create(left_hammer_swing, left_hammer_swingBack, NULL);
	

	//创建右边障碍物精灵
	Sprite *right_crane = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("crane"));
	right_crane->setPosition(origin.x + visibleSize.width + right_crane->getContentSize().width * 5 / 18, origin.y + visibleSize.height * 0.68);

	Sprite *right_hammer = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("hammer"));
	right_hammer->setAnchorPoint(Vec2(0.5, 1));
	right_hammer->setPosition(Vec2(origin.x + visibleSize.width - right_crane->getContentSize().width * 3 / 19, origin.y + visibleSize.height * 0.68 + right_crane->getContentSize().height / 3));
	right_hammer->setRotation(20);
	this->addChild(right_crane, 3);
	this->addChild(right_hammer, 3);
	//创建右边锤子动画
	auto *right_hammer_swing = RotateBy::create(1.5f, -40);
	auto *right_hammer_swingBack = right_hammer_swing->reverse();
	Sequence *right_hammer_sequence = Sequence::create(right_hammer_swing, right_hammer_swingBack, NULL);

	//让锤子运动起来
	letf_hammer->runAction(RepeatForever::create(left_hammer_sequence));
	right_hammer->runAction(RepeatForever::create(right_hammer_sequence));

	

    return true;
}

void WelcomeScene::StartMenuCallback(Ref* sender)
{
	auto scene = GameScene::create();
	//auto scene = PicViewerScene::createScene();
	auto transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);
}

void WelcomeScene::ScoreMenuCallback(Ref* sender)
{

}

void WelcomeScene::RateMenuCallback(Ref* sender)
{

}

void WelcomeScene::RemoveAdsMenuCallback(Ref* sender)
{

}
