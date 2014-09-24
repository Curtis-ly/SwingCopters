#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"
#include "AtlasLoader.h"

using namespace cocos2d;

class BackgroundLayer :public Layer{
public:
	virtual bool init();

	CREATE_FUNC(BackgroundLayer);
private:
	Sprite *cloud1;
	Sprite *cloud2;
	Sprite *cloud3;
	Sprite *land;
	Sprite *tree;
	SEL_SCHEDULE  shiftBackground;

	void scrollBackground(float dt);
	void stopScrollBackground();
};

#endif //__BACKGROUND_LAYER_H__