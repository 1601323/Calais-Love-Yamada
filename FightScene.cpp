#include "FightScene.h"
#include "BossScene.h"

#include "HpBar.h"


const int hpGageSizeWidth = 300;
const int hpGageSizeHeight = 10;

Scene *FightScene::createScene()
{
	auto scene = Scene::create();
	auto layer = FightScene::create();
	scene->addChild(layer);
	return scene;
}

FightScene::FightScene() {

}
FightScene::~FightScene() {

}


// ������
bool FightScene::init()
{
	if (!Layer::init()){
		return false;
	}

	// �o�b�N�O;�����h
	this->FightBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(FightScene::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width , 0));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);


	//�^�b�`�C�x���g-------------------------------------
	// �擾
	auto touchGet = EventListenerTouchOneByOne::create();
	touchGet->onTouchBegan = CC_CALLBACK_2(FightScene::TouchBegan, this);
	touchGet->onTouchMoved = CC_CALLBACK_2(FightScene::TouchMove, this);
	touchGet->onTouchEnded = CC_CALLBACK_2(FightScene::TouchEnd, this);
	//�^�b�`�C�x���g���X�i�[�̓o�^
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchGet, this);

	//�G-------------------------------------------------
	//�G��HP���Z�b�g
	enemyHpNow = 300;
	enemyHpMax = 300;

	enemySprite = Sprite::create("enemy/zombi/green.png");
	// �\�����W�w��
	enemySprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(enemySprite, 0);
	//�G�摜��Rect���擾
	enemySpriteRect = Rect(	enemySprite->getPosition().x - enemySprite->getContentSize().width / 2,
							enemySprite->getPosition().y - enemySprite->getContentSize().width / 2,
							enemySprite->getContentSize().width,
							enemySprite->getContentSize().height);


	//�GHP�Q�[�W-------------------------------------------
	auto backHpRect = Rect(0, 0, hpGageSizeWidth, hpGageSizeHeight);
	auto redSquare = Sprite::create();
	redSquare ->setAnchorPoint(Point(0.f, 1.f));	//�A���J�[�|�C���g�������
	redSquare->setTextureRect(backHpRect);
	redSquare->setPosition(winSize.width / 3, 900);
	redSquare->setColor(Color3B::RED);
	this->addChild(redSquare);
	
	enemyHpRect = Rect(0, 0, (enemyHpNow / enemyHpMax) * hpGageSizeWidth, 10);
	blueSquare = Sprite::create();
	blueSquare->setAnchorPoint(Point(0.f, 1.f));	//�A���J�[�|�C���g�������
	blueSquare->setTextureRect(enemyHpRect);
	blueSquare->setPosition(winSize.width / 3, 900);
	blueSquare->setColor(Color3B::BLUE);
	this->addChild(blueSquare);

	this->scheduleUpdate();	//update�����t���[���Ăяo�����

	//// �I�u�W�F�N�g�쐬
	//HpBar* bar = HpBar::create(300, 20, 300);	//HpBar::create(���A�����A�ő�l�j
	//bar->setPosition(winSize.width / 2, 850);
	//this->addChild(bar);
	//// �l��ύX
	//bar->changeValue(enemyHpNow);



	return true;
}

// �w�i
void FightScene::FightBackGroudn()
{


	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �o�b�N�J���[
	auto groundCollar = LayerColor::create(Color4B::YELLOW, winSize.width, winSize.height);

	// �o�b�N�O�����hCollar��2:�\����
	this->addChild(groundCollar, 0);

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("Fight", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
}



// �^�b�`�����u��
bool FightScene::TouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//�^�b�`���W���擾
	touchLocation = touch->getLocation();

	//enemySpriteRect�����N���b�N���Ă�����E�E�E
	if (enemySpriteRect.containsPoint(touchLocation)) {
		enemyHpNow -= 20;
		////hpSizeWidth = (enemyHp / enemyHpMax) * 300;
		log("enemySpriteClickCheck");
		log("enemyHp = %i", enemyHpNow);

		enemyHpRect = Rect(0, 0, enemyHpNow, hpGageSizeHeight);
		blueSquare->setTextureRect(enemyHpRect);
	}


	return true;
}

// �X���C�v��
void FightScene::TouchMove(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

// �w�𗣂����u��
void FightScene::TouchEnd(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (enemyHpNow <= 0) {
		this->pushStart(this);
	}

}


// ��ʑJ��
void FightScene::pushStart(Ref * pSender)
{
	log("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = BossScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

void FightScene::update(float delta) {
	//enemyHpNow--;
	//bar->changeValue(enemyHpNow);
\

}