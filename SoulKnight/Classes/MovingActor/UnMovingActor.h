#pragma once
#ifndef __UNMOVINGACTOR_H__
#define __UNMOVINGACTOR_H__
#include<iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include "Constant.h"
#include"Buff.h"
#include"MovingActor.h"
#include"Equipment.h"
USING_NS_CC;

class GameScene;
enum TOTALNPC
{
	BloodBox,
	ManaBox,
	CoinBox,
	Businessman,
	Statue,
	Vending

};


class UnMovingActor :public cocos2d::Sprite
{

	CC_SYNTHESIZE(float, touchRadius, TouchRadius);    //�����뾶��С�趨 ���ڽ�ɫ�Ƿ��ڴ�����Χ��
	CC_SYNTHESIZE(bool, isExploreBox, IsExploreBox);    //�Ƿ�Ϊͨ�غ�ı���
	CC_SYNTHESIZE(TOTALNPC, npcName, NPCName);            //npc����


public:

	static UnMovingActor* create(const std::string& filename, GameScene* Scene, TOTALNPC NPC,float radius);

	virtual bool init(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius);

	virtual bool isInRadius(MovingActor* fighter);                 //�жϽ�ɫ�Ƿ��ڷ�Χ��

	virtual String talkFirstBack();				  //����NPC˵�Ļ�

	virtual String talkSecondBack();				  //����NPC˵�Ļ�

	void StartAnimation();                //���Ŷ���

	Buff* buffBack();                       //����buff����

	Equipment* equipBack();             //��������
};












#endif // !__UNMOVINGACTOR_H__
