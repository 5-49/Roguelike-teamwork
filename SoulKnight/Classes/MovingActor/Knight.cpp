#include"Knight.h"
#include"Scene/GameScene.h"
//#include "HelloWorldScene.h"



Knight* Knight::create(GameScene* Scene, std::string Name)
{
	Knight* knight = new Knight();
	if (knight && knight->init(Scene, Name))
	{
		knight->autorelease();
		return knight;
	}

	CC_SAFE_DELETE(knight);
	return nullptr;
}



bool Knight::init(GameScene* Scene, std::string Name)
{
	if (!Fighter::init(Scene, Name))
	{
		return false;
	}
	//����ʼ������

	//TBD

	return true;
}



bool Knight::isAlreadyDead()
{
	if (curHitPoints == 0)
	{
		return true;
	}

	return false;
}



void Knight::setPosition(const cocos2d::Vec2& newPosition)
{


};




void Knight::releaseSkill()
{
	
	//˫ǹĿǰ����֪��ôд
	//���ټӳ�buff������buff������buff��֮�����

	
	
}


