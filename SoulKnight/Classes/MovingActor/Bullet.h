#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include"cocos2d.h"
#include<string>
#include"MovingActor/Constant.h"

USING_NS_CC;

class MovingActor; 

class Bullet :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, _damage, Damage);
	CC_SYNTHESIZE(float, _flySpeed, FlySpeed);
	CC_SYNTHESIZE(MovingActor*, _owner, Owner);
	CC_SYNTHESIZE(MovingActor*, _victim, Victim);
public:
	virtual bool init(const std::string& filename, INT32 damage, float flySpeed, MovingActor* owner, MovingActor* victim);
	virtual void giveOut();
	virtual void giveOut(EDirection Dir);
	virtual void fly();
	static Bullet* create(const std::string& filename, INT32 damage, float flySpeed, MovingActor* owner, MovingActor* victim);
};

#endif // !__BULLET_H__
