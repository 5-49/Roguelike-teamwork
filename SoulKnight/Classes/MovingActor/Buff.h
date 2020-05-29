#pragma once
#ifndef __BUFF_H__
#define __BUFF_H__
#include "cocos2d.h"
USING_NS_CC;

enum BuffType
{
	VERTIGO,	//ѣ��
	FROZEN,     //����
	BURN,       //����
	POISON,     //�ж�
	SPEEDUP,    //����
	SPEEDDOWN   //����

};
//��ҩƿ�ɹ���buff����
class Buff :public cocos2d::Sprite
{
	//CC_SYNTHESIZE(int, hp, HP);                          
	//CC_SYNTHESIZE(float, buffMoveSpeed, BuffMoveSpeed);
	CC_SYNTHESIZE(int, hp, HP);                   //ѪƿЧ��,���ˣ��ж�
	CC_SYNTHESIZE(int, mp, MP);					 //ħƿЧ��       ����ҩƿЧ��
	CC_SYNTHESIZE(float, buffMoveSpeed, BuffMoveSpeed);   //�ƶ��ٶ�Ч��   ����/���� ,������ѣ��
	

	CC_SYNTHESIZE(float, duration, Duration);   //����ʱ��
	CC_SYNTHESIZE(float, beginTime, BeginTime); //��ʼʱ��
	CC_SYNTHESIZE(float, endTime, EndTime);		//����ʱ��

	

};




#endif // !__BUFF_H__
