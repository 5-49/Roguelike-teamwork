#pragma once
#ifndef __TESTMANSLECT_SCENE_H__
#define __TESTMANSLECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;
class testmanSelect :public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuAudioCallBack(cocos2d::Ref* pSender);
	void menuExitCallBack(cocos2d::Ref* pSender);//������һ����


	CREATE_FUNC(testmanSelect);
};


#endif
