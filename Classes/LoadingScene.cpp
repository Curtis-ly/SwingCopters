#include "LoadingScene.h"

Scene* LoadingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LoadingScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	Sprite *background = Sprite::create("splash.png");
	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(background);

	// start ansyc method load the atlas.png
	Director::getInstance()->getTextureCache()->addImageAsync("atlas.png", CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
    return true;
}

void LoadingScene::loadingCallBack(Texture2D *texture){
	AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);

	// After loading the texture , preload all the sound
	SimpleAudioEngine::getInstance()->preloadEffect("coin.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("crash.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("fan.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("fcoin.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("flip.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("fun.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("point.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("steer.ogg");

	// After load all the things, change the scene to new one
	auto scene = WelcomeScene::createScene();
	//auto scene = PicViewerScene::createScene();
	auto transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);
}
