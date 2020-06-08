#include"UnMovingActor.h"
//#include"GameScene"


//
//��������:
//1.վ��һ����Χ��
//2.click - �� / ��������� - ��
//3������ʾ����(���� / ���� / ������) / ���Ŷ���(����)
//4.��click - �� / ��������� - �α�ʾȷ��
//5.���Ŷ��� / ���ؾ���
//6.���bufFЧ�� / �۳���Ǯ������� / �۳���Ǯ����������


UnMovingActor* UnMovingActor::create(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius)
{
	UnMovingActor* unmovingactor = new UnMovingActor();
	if (unmovingactor && unmovingactor->init(filename, Scene,NPC,radius))
	{
		unmovingactor->autorelease();
		return unmovingactor;
	}

	CC_SAFE_DELETE(unmovingactor);
	return nullptr;

}

bool UnMovingActor::init(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius)
{
	if (!Sprite::init())
	{
		return false;
	}

	npcName = NPC;
	if (NPC == BloodBox|| NPC == ManaBox || NPC == CoinBox)
	{
		isExploreBox == true;
	}
	else { isExploreBox == false; }

	touchRadius = radius;


}

bool UnMovingActor::isInRadius(MovingActor* fighter)  //д����
{
	//if(){	//if(figher)




	//return true;
 //   }
	//else { return false; }
	return false;
}

String UnMovingActor::talkFirstBack()             //��֪�������ܲ���ʹ��
{
	switch (npcName)
	{
	case TOTALNPC::Businessman:
		return "��ˮǧɽ�����飬���װ���в���";
		
	case TOTALNPC::Statue:
		return "���ڷ�ǰ������˼�ǧ�꣬��Ϊ�˸���Ӹ�Buff";

	case TOTALNPC::Vending:
		return "��ŷ�ʾ�������";
	case TOTALNPC::BloodBox:
		return "(������)";
	case TOTALNPC::ManaBox:
		return "(������)";
	case TOTALNPC::CoinBox:
		return "(������)";
	}
	return "Unknown Wrong";
}

String UnMovingActor::talkSecondBack()        //���ζԻ�����ʾ��Ҫ���Ľ���Լ���������,ע��˴�����Ӧ��ֱ�����������øú���
{
	//������
	return "Unknown Wrong";
}



void UnMovingActor::StartAnimation()                  
{

	auto animation = Animation::create();
	//
}

Buff* UnMovingActor::buffBack()
{
	Buff* newbuff;
	switch (npcName)
	{
	case TOTALNPC::BloodBox:
		Buff* newbuff = Buff::create(SPEEDUP, 2, 0, 0.f, 0);
		return newbuff;
	case TOTALNPC::ManaBox:
		Buff* newbuff = Buff::create(SPEEDUP, 0, 60, 0.f, 0);
		return newbuff;
	case TOTALNPC::CoinBox:
		//Buff* newbuff = Buff::create(SPEEDUP, 2, 0, 0.f, 0);
		return newbuff;
	//buff�����ӵĶ������ܶ�

	}
}

Equipment* UnMovingActor::equipBack()
{
	return nullptr;
}





