#pragma once
#ifndef __MOVINGACTOR_H__
#define __MOVINGACTOR_H__
#include<iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include"Constant.h"

USING_NS_CC;

class HelloWorld;

class MovingActor :public cocos2d::Sprite
{

	CC_SYNTHESIZE(int, maxHitPoints, MaxHitpoints);   //����ֵ����
	CC_SYNTHESIZE(int,curHitPoints,CurHitPoints) //��ǰ����ֵ

	CC_SYNTHESIZE(AllCamp, camp, Camp);//��Ӫ
	CC_SYNTHESIZE(INT32, hitPoints, Hitpoints);   //����ֵ

	CC_SYNTHESIZE(float, identityRadius, IdentityRadius); //ʶ��뾶���ڸ�֪��Χ
	CC_SYNTHESIZE(float, moveSpeed, MoveSpeed); //�ƶ��ٶ�
	CC_SYNTHESIZE(float, attackSpeed, AttackSpeed); //�����ٶ�/����Ƶ��
	CC_SYNTHESIZE(bool, alreadyDead, AlreadyDead); //�����ж�
	CC_SYNTHESIZE(HelloWorld*, exploreScene, ExploreScene);   //���볡��
	CC_SYNTHESIZE(MovingActor*,attackFrom, AttackFrom);//�˺���Դ
	CC_SYNTHESIZE(MovingActor*, attackTarget, AttackTarget);//����Ŀ��

protected:

	virtual void initData(HelloWorld* Scene);  //��ֹ�ն���

	//virtual void removeBuff(Buff* buff);
public:

	virtual bool init(const std::string& filename, HelloWorld* Scene);
	virtual void updateTarget();
	virtual void die();
	virtual void takeDamage(DamageMode type, INT32 damage, MovingActor* enemy);
	static MovingActor* create(const std::string& filename, HelloWorld* Scene);
};





#endif // !__MOVINGACTOR_H__
