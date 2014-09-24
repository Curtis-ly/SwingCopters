#include "GameScene.h"

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Scene::initWithPhysics())
    {
        return false;
    }

	this->getPhysicsWorld()->setGravity(Vect(0, -900));
    
	// Add the background
	auto backgroundLayer = BackgroundLayer::create();
	if (backgroundLayer) {
		this->addChild(backgroundLayer);
	}

    return true;
}

void GameScene::restart() {
	this->removeAllChildrenWithCleanup(true);
	this->init();
}
