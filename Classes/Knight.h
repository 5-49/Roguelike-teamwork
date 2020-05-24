#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "cocos2d.h"


USING_NS_CC;

class Knight :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, hitPoints, HitPoints);    //����ֵ
	CC_SYNTHESIZE(INT32, manaPoints, ManaPoints);  //����ֵ
	CC_SYNTHESIZE(INT32, shield, Shield);		   //����ֵ	
	CC_SYNTHESIZE(float, critRate, CritRate);	   //������
	CC_SYNTHESIZE(float, lastSkillTime, LastSkillTime); //���ܳ���ʱ��

	//Crit rate
public:

	void setPosition(const cocos2d::Vec2& newPosition);//���ý�ɫ��ʼλ��
	static Knight* createWithSpriteFrameName(const char* spriteFrameName);
	virtual bool init();//������Ҫ��ӵ�Scene����
	virtual bool isAlreadyDead();  //��Ӹ����̳������ж��Ƿ�GG

	 //û��������ʱ��д
	//virtual bool attack();  

	//virtual void getEquip(Equipment* equip);                  //�ֳ���������������/������л�

	//virtual void changeEquip(Equipment* equip);

	//virtual void fighterMove();

	//virtual void stopMove();

	//virtual void playAttackAnimation();
};


#endif //!__KNIGHT_H__