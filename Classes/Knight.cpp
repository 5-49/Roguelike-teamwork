#include"Knight.h"
#include "cocos2d.h"

Knight* Knight::createWithSpriteFrameName(const char* spriteFrameName)
{
	Knight* knight = new Knight();
	if (knight && knight->initWithSpriteFrameName(spriteFrameName))
	{
		knight->autorelease();




		//��������
		return knight;
	}
	CC_SAFE_DELETE(knight);
	return NULL;

}


void Knight::setPosition(const cocos2d::Vec2& newPosition)
{
	//�ܹ�Ȼ���������λ��


}

bool Knight::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	hitPoints = 5;
	shield = 5;
	manaPoints = 180; //��ʼ��Ѫ�������ס�����ֵ������Ҳ��ѡ�񴫲ν��и�ֵ.
	//lastSkillTime = 5.0f 
	return true;
}

bool Knight::isAlreadyDead()//�����ж������Ƿ�����������ӻص�����
{
	if (hitPoints <= 0)
	{
		return true;
	}
	return false;
}

