#include"MovingActor.h"
#include"Constant.h"

//�������������

MovingActor* MovingActor::create(const std::string& filename, HelloWorld* Scene)
{
	MovingActor* sprite = new MovingActor();
	if (sprite && sprite->init(filename, Scene))
	{
		sprite->autorelease();
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}


bool MovingActor::init(const std::string& filename, HelloWorld* Scene)
{
	if (!Sprite::initWithFile(filename))
	{
		return false;
	}

	initData(Scene);


}

void MovingActor::initData(HelloWorld* Scene)
{
	exploreScene = Scene;
	hitPoints = INIT_HITPOINTS;      //��ʼ����ֵ5
	identityRadius = INIT_ID_RADIUS;//��ʼ��֪�뾶500��boss���ܻ����
	moveSpeed = INIT_MOVESPEED; 
	attackSpeed = 0;           //���Ǻ�enemy�������Ʋ�ͬ����ʱ��Ϊ0
	alreadyDead = false;


}

void MovingActor::die()
{
	alreadyDead = true;
}

//buff������