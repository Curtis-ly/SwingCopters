#ifndef __PIC_VIEWER_SCENE_H__
#define __PIC_VIEWER_SCENE_H__

#include "cocos2d.h"
#include "AtlasLoader.h"

using namespace cocos2d;

class PicViewerScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(PicViewerScene);

	void LeftMenuItemCallback(Ref* sender);
	void RightMenuItemCallback(Ref* sender);
private:
	Map<std::string, SpriteFrame*> _spriteFrames;
	Sprite *pic;
	LabelTTF* label;
	int pos;
	SpriteFrame* getSpriteFrameByIndex(int index);
	string getSpriteNameByIndex(int index);
};

#endif // __PIC_VIEWER_SCENE_H__
