#include"Knight.h"
#include "cocos2d.h"

Knight* Knight::createWithSpriteFrameName(const char* spriteFrameName)
{
	Knight* knight = new Knight();
	if (knight && knight->initWithFile(spriteFrameName))
	{
		knight->autorelease();

		//��������
		return knight;
	}
	CC_SAFE_DELETE(knight);
	return NULL;
	                                                       
}

Knight* Knight::create(const char* spriteFrameName)
{
	Knight* knight = new Knight();
	if (knight->init())
	{
		knight->autorelease();
		
		return knight;
	}
	CC_SAFE_DELETE(knight);
	return NULL;
}


void Knight::setPosition(const cocos2d::Vec2& newPosition)
{
	//�ܹ�Ȼ���������λ��
	Size screenSize = Director::getInstance()->getVisibleSize();

	float halfWidth = this->getContentSize().width / 2;
	float halfHeight = this->getContentSize().height / 2;
	float pos_x = newPosition.x;
	float pos_y = newPosition.y;

	if (pos_x < halfWidth) {
		pos_x = halfWidth;
	}
	else if (pos_x > (screenSize.width - halfWidth)){
		pos_x = screenSize.width - halfWidth;
	}

	if (pos_y < halfHeight) {
		pos_y = halfHeight;
	}
	else if(pos_y>(screenSize.height-halfHeight)){
		pos_y = halfHeight;
	}

	Sprite::setPosition(Vec2(pos_x, pos_y));
	Sprite::setAnchorPoint(Vec2(0.5f, 0.5f));
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

