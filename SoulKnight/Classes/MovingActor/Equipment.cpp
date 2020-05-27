#include "Equipment.h"



Equipment* Equipment::create(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
	float _attackSpeed, int _attackRadius,int _manaConsume)
{
	Equipment* equipment = new Equipment();
	if (equipment && equipment->init(_equipType, _equipname, _attack,
		_attackSpeed, _attackRadius, _manaConsume))
	{
		equipment->autorelease();
		
		return equipment;
	}
	CC_SAFE_DELETE(equipment);
	return nullptr;
}




bool Equipment::init(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
	float _attackSpeed, int _attackRadius,int _manaConsume)
{
	if (!Sprite::init())
	{
		return false;
	}
	
	equipType = _equipType;
	equipName = _equipname;

	attackNumber = _attack;
	attackSpeedNumber = _attackSpeed;
	attackRadius = _attackRadius;

	manaConsume = _manaConsume;
	return true;


}

bool Equipment::init(ValueVector& data, EAttackMode _equipType, EEQUIPMENT _equipname)
{
	if (!Sprite::init())
	{
		return false;
	}


	equipType = _equipType;
	equipName = _equipname;

	attackNumber = data.at(0).asInt();
	attackSpeedNumber = data.at(1).asFloat();
	attackRadius = data.at(2).asInt();
	manaConsume = data.at(3).asInt();
	
	return true;

}

