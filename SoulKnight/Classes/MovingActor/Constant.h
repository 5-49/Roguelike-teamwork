#pragma once
#ifndef __CONSTANT_H_
#define __CONSTANT_H_

#include"cocos2d.h"

#define INIT_HITPOINTS 5			//��ʼ������ֵ
#define INIT_SHIELD 5				//��ʼ������ֵ
#define INIT_MANAPOINTS 180			//��ʼ������ֵ

#define SHIELD_RECOVER_TIME 1.0f     //���ǻ��ܻ��ƺ�ˢ��ʱ���ʼ��1.0f
#define INIT_ID_RADIUS 500        //�ƶ���ɫ�ĸ�Ӧ�뾶��֪̽��Χ���Ƿ��������ƶ�����  
#define MELEE_RADUIS 50    //�޽���ʱ�Ľ�ս�뾶
/* 
*û�о����������ʱ����500  
*/
#define INIT_MOVESPEED 1.0
#define INIT_EQUIP_NUMBER 2

enum EAttackMode	//	����ģʽ,�����������Ĺ���ģʽ��Ҳ���ǹ���Ĺ���ģʽ
{
	MELEE,			//	��ս
	REMOTE,			//	Զ��
	MIX				//  ���
};
enum DamageMode      //�˺�����	
{
	//˲ʱ�˺�
	//�����˺�
};

enum AllCamp        //��Ӫ
{
	FRIENDLY,
	ENEMY
};
//���ܻᶨ���
enum EEQUIPMENT
{
	POJIUDESHOUQIANG,
	AK47,
	GANCAOCHA,
	NOTHING
	//TBD
};

//���ܻᶨ��ķ���ö������
enum EDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
	NODIR
};

enum keyPress
{
	PRESS,
	RELEASE
};


//���ܻ�






#endif //!__CONSTANT_H_