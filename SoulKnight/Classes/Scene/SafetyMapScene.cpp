#include "SafetyMapScene.h"
#include "StartGameScene.h"
#include "SimpleAudioEngine.h" 
#include "cocos2d.h"

USING_NS_CC;

Scene* SafetyMap::createScene()
{
	return SafetyMap::create();
}
//������ʾ
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SafetyMapScene.cpp\n");
}

bool SafetyMap::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying()) {
		audio->playBackgroundMusic("SafetyMap.mp3", true);
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�


	
}

