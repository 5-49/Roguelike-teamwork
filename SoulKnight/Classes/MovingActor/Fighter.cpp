#include"MovingActor.h"
#include"Fighter.h"
#include"MovingActor/Constant.h"
#include<set>
#include "Fighter.h"
//

Fighter* Fighter::create(HelloWorld* Scene ,std::string fighterName)
{

	Fighter* fighter = new Fighter();
	if (fighter && fighter->init(Scene, fighterName))
	{

		fighter->autorelease();
		return fighter;					//	��������������ԭ��δ֪
	}

	CC_SAFE_DELETE(fighter);
	return nullptr;


}




bool Fighter::init(HelloWorld* Scene, std::string fighterName)
{
	if (!Sprite::init())
	{
		return false;
	}

	initHeroData( Scene, fighterName);
	//������ʼ���������

	return true;

}


bool Fighter::initHeroData(HelloWorld* Scene, std::string Name)
{
	ValueMap value = FileUtils::getInstance()->getValueMapFromFile("FightersData.plist");
	initFighterData = value.at(Name).asValueMap();

	exploreScene = Scene;

	fighterName = Name;

	hitPoints = initFighterData["hitPoints"].asInt();     //����plist�ļ�ֵ��
	moveSpeed = initFighterData["MovingSpeed"].asFloat();
	shield = initFighterData["shield"].asInt();
	acRcoverSpeed = initFighterData["ACRecoverRate"].asInt();
	manaPoints = initFighterData["manaPoints"].asInt();
	critRate = initFighterData["critRate"].asFloat();

	//�Ҹ���������ʱ���ⶫ��ʶ���ˣ�����ע�͵�
	//identityRadius = INIT_ID_RADIUS;//��ʼ��֪�뾶500��boss���ܻ����
	equipNumber = INIT_EQUIP_NUMBER;

	alreadyDead = false;
	attackSpeed = 0.f;
	attackMode = MIX;
	lastTimeInjured = 0.f;

	curHitPoints = hitPoints;         //��ʼ�趨Ϊ��ֵ
	curShield = shield;		
	curManaPoints = manaPoints;
			
	for (int i = 0; i < INIT_EQUIP_NUMBER; ++i)    //++i???���������ܴ���bug
	{
		equips[i] = nullptr;

	}
	return true;


}

bool Fighter::isFullEquipments()
{
	for (int i = 0; i < INIT_EQUIP_NUMBER; ++i)    //++i???���������ܴ���bug
	{
		if (equips[i] = nullptr)
		{
			return false;
		}

	}
	return true;
}

Equipment* Fighter::changeMainEquip()    //������л���������Ч
{
	if (isFullEquipments() == false)
	{
		return equips[0];
	}
	else
	{
		return equips[1];
	}
}

bool Fighter::attack()
{
	return false;
}




bool Fighter::isInMelee()           //�ж�enemyλ�ڷ�Χ�ڣ���ʱ����д
{
	return false;
}




void Fighter::fighterMove()      //
{
	Vec2 current = this->getPosition();
	switch (direction)
	{
	case EDirection::UP:
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::UPLEFT:
		current.x -= INIT_MOVESPEED;
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::UPRIGHT:
		current.x += INIT_MOVESPEED;
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::LEFT:
		current.x -= INIT_MOVESPEED;
		break;
	case EDirection::DOWN:
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::DOWNLEFT:
		current.x -= INIT_MOVESPEED;
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::DOWNRIGHT:
		current.x += INIT_MOVESPEED;
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::RIGHT:
		current.x += INIT_MOVESPEED;
		break;
	case EDirection::NODIR:
		break;
	default:
		break;
	}
	this->setPosition(current);
}



void Fighter::playAttackAnimation()
{
}


void Fighter::die()
{
	//���Ӣ������ʱ����Ч��ͼ��
	//if(this == _combatScene->getMyHero())
	//{
	//	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio/YouHaveBeenSlained.wav", false, 1, 0, 1.2);
	//}
	//ѧ���Ĳο�����

	//setVisible(false);������ʾӢ�۵��ر�ڲ���ս��


	alreadyDead = true;
	//�������ҳ��
}

void Fighter::releaseSkill()
{
//�̳���������Ӣ��д	
}