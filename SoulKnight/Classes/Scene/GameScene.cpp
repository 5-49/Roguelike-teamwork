#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Knight.h"
#include"HelloWorldScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameSceneScene.cpp\n");

}


bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;

	}

	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();
	loadingAnimation();
	initMapLayer();
	initKnight();
	scheduleUpdate();

	/*��������
	for (int i = 0; i < 4; i++)
	{
		auto soldier = Soldier::create(EAttackMode::REMOTE, ECamp::BLUE, ERoad::MIDWAY, this);
		_map->addChild(soldier);
		soldier->setPosition(200, 200 + rand() % 100 * 10);
		soldier->setScale(0.3);
		_soldiers.pushBack(soldier);
	}*/



	//�������̼�����
    listenerKeyBoard = EventListenerKeyboard::create();
    //�󶨼����¼�
    listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GameScene::onPressKey, this);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GameScene::onReleaseKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, this);
	listenerTouch->setSwallowTouches(false);


	return true;
}


//ˢ�µ��ˣ�
void GameScene::generateEnemies(float delta)
{
	
}



//��ʼ����ͼ!!!����ע�⣺���仹�ǵ�ͼ
void GameScene::initMapLayer()
{


}

//��ʼ������,Ŀǰ�ٽ�ɫ�ࣨ�ڶ��ɫ��ѡ��ǰ���£�
void GameScene::initKnight()
{

	auto visibleSize = Director::getInstance()->getVisibleSize();
	//_myKnight = HouYi::create(this, ECamp::BLUE, "HouYi", EAttackMode::MELEE);
	_myKnight->setPosition(visibleSize / 2);
	//_myHero->setTag(TAG_MYHERO);
	_myKnight->setScale(0.5);
	_map->addChild(_myKnight);
}


//���ض�����һ������״��
void GameScene::loadingAnimation()
{
	
}

//��������λ��
void updateKnightPosition()
{

}


//֡����
void GameScene::update(float delta)
{
	/*�ӵ������ж�
	for (auto it = _bullets.begin(); it != _bullets.end();)
	{
		if (!(*it)->getTarget()->getAlreadyDead())
		{
			if ((*it)->calculateDistance() < (*it)->getTarget()->getBoundingBox().size.height / 2)
			{
				auto target = (*it)->getTarget();
				target->takeDamage((*it)->getDamage(), (*it)->getFromActor());
				removeChild(*it);
				it = _bullets.erase(it);
			}
			else
			{
				(*it)->calculatePosition();
				++it;
			}
		}
		else
		{
			removeChild(*it);
			it = _bullets.erase(it);
		}
	}*/

	/*���������ж�
	for (auto it = _enemies.begin(); it != _enemies.end(); ++it)
	{
		if ((*it)->getAlreadyDead())
		{
			(*it)->setVisible(false);
		}
	}*/
}


void GameScene::updateEnemiesAttackTarget()
{



}



//������Χ
void GameScene::CircleDamage(Point point, float radius, float damage)
{

}


bool GameScene::onPressKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	keys[keyCode] = true;
	return true;
}



bool GameScene::onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	//keys[keyCode] = false;
	return true;
}


bool GameScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}