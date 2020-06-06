#include "MusicScene.h"
#include "SimpleAudioEngine.h" 

USING_NS_CC;

Scene* Music::createScene()
{
	return Music::create();
}

//Promble loading
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MusicScene.cpp\n");
}

bool Music::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�

	auto offMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/off.png", "off.png");
	auto onMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/on.png", "off.png");


	MenuItemToggle* musicMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Music::menuMusicCallBack, this),
		offMusic, onMusic, NULL
	);
	musicMenu->setPosition(Vec2(1221.0, visibleSize.height - 680.5));

	Menu* mu = Menu::create(offMusic,onMusic, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);//��һ���ӽڵ�/��һ������

	auto background = Sprite::create("ArtDesigning/SceneAndMap/SafeMap/StartGameBackground.png");
	if (background == nullptr)
	{
		problemLoading("'StartGameBackground.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	return true;
}

void Music::menuMusicCallBack(cocos2d::Ref* pSender)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()) {
		audio->pauseBackgroundMusic();
	}
	else {
		audio->resumeBackgroundMusic();
	}
}
/*
void StartGame::menuAudioCallBack(cocos2d::Ref* pSender)
{
	//ת����ȫ��ͼ
	auto nextScene = Music::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Start Menu Item %p", item);
}
*/

