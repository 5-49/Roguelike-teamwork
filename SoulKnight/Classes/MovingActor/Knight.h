#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "cocos2d.h"
#include "Fighter.h"


USING_NS_CC;

class HelloWorld;

class Knight :public Fighter
{
	

	//Crit rate
public:

	void setPosition(const cocos2d::Vec2& newPosition);//���ý�ɫ��ʼλ��

	virtual bool isAlreadyDead();  //��Ӹ����̳������ж��Ƿ�GG

	virtual bool init(GameScene* Scene, std::string Name);

	static Knight* create(GameScene* Scene,std::string Name);

	virtual void releaseSkill();               //������


	 //û��������ʱ��д
	//virtual bool attack();  

	//virtual void getEquip(Equipment* equip);                  //�ֳ���������������/������л�

	//virtual void changeEquip(Equipment* equip);

	//virtual void fighterMove();

	//virtual void stopMove();

	//virtual void playAttackAnimation();
};


#endif //!__KNIGHT_H__