/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Knight.h"



USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//���´��������Ĵ���ο��ԣ�https://blog.csdn.net/congcongjoy/article/details/8753452
	//�иĶ�
	Vector<SpriteFrame*> framesUp;
	Vector<SpriteFrame*> framesDown;
	Vector<SpriteFrame*> framesRight;
	Vector<SpriteFrame*> framesLeft;

	CCSpriteFrame* frame = NULL;
	CCSpriteFrame* frameOriginal = NULL;

	CCTexture2D* playerRight = CCTextureCache::sharedTextureCache()->addImage("rightDir.png");
	frame = CCSpriteFrame::createWithTexture(playerRight, CCRectMake(0, 0, 30, 60));
	framesRight.pushBack(frame);

	CCTexture2D* playerLeft = CCTextureCache::sharedTextureCache()->addImage("leftDir.png");
	frame = CCSpriteFrame::createWithTexture(playerLeft, CCRectMake(0, 0, 30, 60));
	framesLeft.pushBack(frame);

	CCTexture2D* playerDown = CCTextureCache::sharedTextureCache()->addImage("downDir.png");
	frame = CCSpriteFrame::createWithTexture(playerDown, CCRectMake(0, 0, 30, 60));
	framesDown.pushBack(frame);
	frameOriginal = frame;

	CCTexture2D* playerUp = CCTextureCache::sharedTextureCache()->addImage("upDir.png");
	frame = CCSpriteFrame::createWithTexture(playerUp, CCRectMake(0, 0, 30, 60));
	framesUp.pushBack(frame);

	//ͨ�����鴴��֡����
	CCAnimation* animitionUp = CCAnimation::createWithSpriteFrames(framesUp, 0.1f);
	CCAnimation* animitionDown = CCAnimation::createWithSpriteFrames(framesDown, 0.1f);
	CCAnimation* animitionLeft = CCAnimation::createWithSpriteFrames(framesLeft, 0.1f);
	CCAnimation* animitionRight = CCAnimation::createWithSpriteFrames(framesRight, 0.1f);

	//ͨ��֡���ж������ƶ������������������ƶ�����
	auto actionUp = CCSpawn::createWithTwoActions(CCAnimate::create(animitionUp), CCMoveBy::create(0.4f, ccp(0, 32)));
	auto actionDown = CCSpawn::createWithTwoActions(CCAnimate::create(animitionDown), CCMoveBy::create(0.4f, ccp(0, -32)));
	auto actionLeft = CCSpawn::createWithTwoActions(CCAnimate::create(animitionLeft), CCMoveBy::create(0.4f, ccp(-32, 0)));
	auto actionRight = CCSpawn::createWithTwoActions(CCAnimate::create(animitionRight), CCMoveBy::create(0.4f, ccp(32, 0)));

	actionUp->retain();
	actionDown->retain();
	actionLeft->retain();
	actionRight->retain();


	//������Ҫ�ı�λ��

	//��������
	auto bg = Sprite::create("securityMap.png"); 
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(bg, 0);

	//������ɫ
	auto hero = Sprite::createWithSpriteFrame(frameOriginal);
	hero->setPosition(Vec2(visibleSize.width / 2, 240));
	this->addChild(hero);


	//�����¼��ļ���������ʲô�뷨���Ըĸģ�ĿǰHelloWorldˮƽ����ʹ��lambda���ʽ��������¼�
	auto Listener = EventListenerKeyboard::create();
	Listener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_W:
		{
			auto actionUp = Spawn::createWithTwoActions(CCAnimate::create(animitionUp), MoveBy::create(0.4f, Vec2(0, 50)));
			actionUp->retain();
			hero->runAction(actionUp);
		}
		break;
		case EventKeyboard::KeyCode::KEY_D:
		{
			auto actionRight = Spawn::createWithTwoActions(CCAnimate::create(animitionRight), MoveBy::create(0.4f, Vec2(50, 0)));
			actionRight->retain();
			hero->runAction(actionRight);
		}
		break;
		case EventKeyboard::KeyCode::KEY_A:
		{
			auto actionLeft = Spawn::createWithTwoActions(CCAnimate::create(animitionLeft), MoveBy::create(0.4f, Vec2(-50, 0)));
			actionLeft->retain();
			hero->runAction(actionLeft);
		}
		break;
		case EventKeyboard::KeyCode::KEY_S:
		{
			auto actionDown = Spawn::createWithTwoActions(CCAnimate::create(animitionDown), MoveBy::create(0.4f, Vec2(0, -50)));
			actionDown->retain();
			hero->runAction(actionDown);
		}
		break;
		default:
			break;
		}
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listener, this);


	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
