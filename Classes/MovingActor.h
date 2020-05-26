#pragma once
#ifndef __MOVINGACTOR_H__
#define __MOVINGACTOR_H__
#include<iostream>
#include <iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include"Constant.h"

USING_NS_CC;

class HelloWorld;

class MovingActor :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, hitPoints, Hitpoints);   //����ֵ
	CC_SYNTHESIZE(float, identityRadius, IdentityRadius); //ʶ��뾶���ڸ�֪��Χ
	CC_SYNTHESIZE(float, moveSpeed, MoveSpeed); //�ƶ��ٶ�
	CC_SYNTHESIZE(float, attackSpeed, AttackSpeed); //�����ٶ�/����Ƶ��
	CC_SYNTHESIZE(bool, alreadyDead, AlreadyDead); //�����ж�
	CC_SYNTHESIZE(HelloWorld*, exploreScene, ExploreScene);   //���볡��


protected:

	virtual void initData(HelloWorld* Scene);  //��ֹ�ն���

	//virtual void removeBuff(Buff* buff);
public:

	virtual bool init(const std::string& filename, HelloWorld* Scene);
	//
	static MovingActor* create(const std::string& filename, HelloWorld* Scene);

};





#endif // !__MOVINGACTOR_H__