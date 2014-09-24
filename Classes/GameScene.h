#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class GameScene : public cocos2d::Scene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void restart();
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameScene);
private:
	
};

#endif // __GAME_SCENE_H__
