#pragma once
#ifndef __FIGHTER_H__
#define __FIGHTER_H__

#include"cocos2d.h"
#include"MovingActor.h"

USING_NS_CC;

class Fighter :public MovingActor
{
	CC_SYNTHESIZE(INT32, magicPoint, MagicPoint);//����
	CC_SYNTHESIZE(INT32, shield, Shield);//����
	CC_SYNTHESIZE(INT32, shieldFix, ShieldFix);//���ܵĻظ��ٶ�
	CC_SYNTHESIZE(String, fighterName, FighterName);//Ӣ������
	CC_SYNTHESIZE(float, calmTime, CalmTime);//������ȴʱ��
	CC_SYNTHESIZE(float, lastTime, LastTime);//���ܳ���ʱ��
public:
	//virtual void getEquipment(Equipment* Eq);  //��ȡ����
	//virtual void exchangeEquipment(Equipment* Eq) //��������
	virtual void takeDamage(DamageMode type, INT32 damage, MovingActor* enemy);
	virtual void skill();
	virtual void reborn();
	virtual void move();
	virtual void stopMove();
	virtual void movingAnimation();
	virtual void attackAnimation();
};



#endif // !__FIGHTER_H__
