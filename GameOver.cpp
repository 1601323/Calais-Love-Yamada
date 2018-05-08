#include "GameOver.h"
#include "TitleScene.h"

Scene *GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// �o�b�N�O�����h
	ClearBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameOver::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width / 2, winSize.height / 2));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);

	return true;
}

// �w�i
void GameOver::ClearBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �o�b�N�J���[
	auto groundCollar = LayerColor::create(Color4B::BLUE, winSize.width, winSize.height);

	// �o�b�N�O�����hCollar��2:�\����
	this->addChild(groundCollar, 0);

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("Over DAYO", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
}

// ��ʑJ��
void GameOver::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = TitleScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}