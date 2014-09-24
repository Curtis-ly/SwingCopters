#ifndef __WELCOM_SCENE_H__
#define __WELCOM_SCENE_H__

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class WelcomeScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(WelcomeScene);
private:
	void StartMenuCallback(Ref* sender);
	void ScoreMenuCallback(Ref* sender);
	void RateMenuCallback(Ref* sender);
	void RemoveAdsMenuCallback(Ref* sender);

};

#endif // __WELCOM_SCENE_H__
