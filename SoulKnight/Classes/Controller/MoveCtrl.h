#pragma once
#ifndef __MOVECTRL_H__
#define __MOVECTRL_H__

#include "cocos2d.h"
#include "MovingActor/Constant.h"
#include <functional>

USING_NS_CC;

class MoveController :public Layer
{
	CC_SYNTHESIZE(bool,isCanMove,IsCanMove);
	CC_SYNTHESIZE(EDirection, firstDirection,FirstDirection);
	CC_SYNTHESIZE(EDirection, lastDirection, LastDirection);
	CC_SYNTHESIZE(EDirection, direction, Direction);
public:
	static MoveController* createMoveController();
private:
	EventListenerKeyboard* listener;
	//����������״̬
	bool pressW, pressS, pressD, pressA;
	//EDirection direction;
	//��������ʼ��
	void ctrlInit();
	//�����¼���������
	virtual bool onKeyPress(EventKeyboard::KeyCode keycode,Event *event);
	virtual bool onKeyRelease(EventKeyboard::KeyCode keycode, Event* event);
	virtual bool update(EventKeyboard::KeyCode keycode,keyPress type);
	virtual bool updateDir();
	CREATE_FUNC(MoveController);
};





#endif // !__MOVECTRL_H__
