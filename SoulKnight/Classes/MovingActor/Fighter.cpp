#include"MovingActor.h"
#include"Fighter.h"
#include"Constant.h"
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
	lastSkillTime = initFighterData["skillLastTime"].asFloat();
	skillCDTime = initFighterData["skillCD"].asFloat();

	identityRadius = INIT_ID_RADIUS;//��ʼ��֪�뾶500��boss���ܻ����
	equipNumber = INIT_EQUIP_NUMBER;

	alreadyDead = false;
	attackSpeed = 0.f;
	attackMode = MIX;
	lastTimeInjured = 0.f;
	//lastSkillTime = 0.f;

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
}



void Fighter::playAttackAnimation()
{
}


bool Fighter::isZeroSheild()
{
	if (curShield == 0 && curHitPoints != 0)
	{
		return true;
	}
	return false;
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