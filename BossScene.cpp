#pragma execution_character_set("utf-8")
#include "BossScene.h"
#include "GameClear.h"

Scene *BossScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BossScene::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool BossScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//������
	Php = 3;				//�v���C���[HP
	Bhp = 5;				//�{�XHP
	continuity = 5;			//�h�炷�񐔂��ł����˂�
	ten = 10;				//�h�炷��
	hpcut = 1;				//���炷HP
	movecnt = 0.05f;		//1���񓮂�������
	turn = PLAYER;			//�N�̃^�[���H
	gametime = 0;			//����
	state = false;			//�v���C���[�̏��
	flag = false;			//�{�X�̏��
	Bflag = false;			//�{�X�̓������

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BossScene::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width / 16, winSize.height / 2));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);

	//�^�b�`���[�h�ݒ�
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// �o�b�N�O�����h
	BossBackGroudn();

	//�^�C�}�[�J�n
	this->schedule(schedule_selector(BossScene::Timer));

	//�A�b�v�f�[�g�X�V
	this->scheduleUpdate();

	//�^�C��
	Timer(1);


	return true;
}

void BossScene::update(float flame)
{
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//�擾
	auto touchget = EventListenerTouchOneByOne::create();


	if (turn == PLAYER) {
		state = false;																//������
			// �R�}���h
			auto KyaraButton = CCSprite::create("attack1.png");						//�摜�w��
			KyaraButton->setPosition(rightSize.width / 2, rightSize.height / 3);	//�z�u�ꏊ
			this->addChild(KyaraButton, 1, 2);										//�ǉ�

			//PLTURN����
			plturn = CCSprite::create("PL.png");									// �z�u����
			plturn->setPosition(rightSize.width / 2, rightSize.height / 1.15f);		// �z�u�ꏊ
			this->addChild(plturn, 1, 1);											// �ǉ�

			//�^�b�`����
			touchget->onTouchBegan = [this, visibleSize, KyaraButton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();									// �^�b�`�����|�C���g�B
				Rect rectButton1 = KyaraButton->getBoundingBox();					// �{�^���摜�͈̔́B
				if (rectButton1.containsPoint(point1)) {							// �{�^���摜�͈͓̔����^�b�`�����ꍇ�B
					state = true;													//�������Ԃɂ���
					if (state == true) {
						KyaraButton->removeFromParentAndCleanup(true);				//����������
						this->removeChildByTag(1);									//����������
					}
					return true;
				}
				else {
					return false;
				}
			};
			// listener1, PlayButton1���C�x���g�o�^����B
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchget, KyaraButton);
	}
	else if (turn == BOSS) {
		flag = false;																	//������
		gametime++;
		BSturn();										//��ȏ���
		if (gametime > 300) {
			flag = true;
		}

		if (flag == true) {
			//����
			this->removeChildByTag(3);					//BSTURN
			this->removeChildByTag(5);					//5000���~�ق���
			this->removeChildByTag(13);					//�p�[�e�B�N��
			this->removeChildByTag(25);					//�U��

			gametime = 0;
			turn = PLAYER;								//�v���C���[�̃^�[����
			log("touch!o_o");							//�^�b�`�B
		}
	}
	log("flame is %f", flame);
}

void BossScene::Timer(float time) {
	CCLOG("%is %f", gametime, time);

	//�摜�ړ�
	Tsprite->setPosition(ccp(gametime, 600));

	//if (turn == BOSS) {
	//	//�J�E���g�A�b�v
	//	gametime++;
	//}

	//�^�C�}�[��~
	if (gametime > 300) {
		this->unschedule(schedule_selector(BossScene::Timer));
	}
}

void BossScene::PLturn()
{
	//�U������
	auto attackfnt = Label::createWithTTF("�U��", "fonts/HGRSGU.TTC", 36);		// �z�u����
	attackfnt->setAnchorPoint(Vec2(0, 0));
	attackfnt->setPosition(rightSize.width / 1.2f, rightSize.height / 1.15f);	// �z�u�ꏊ
	this->addChild(attackfnt, 1, 25);											// �ǉ�

																				//BSTURN����
	emturn = CCSprite::create("BS.png");										// �z�u����
	emturn->setPosition(rightSize.width / 2, rightSize.height / 1.15f);			// �z�u�ꏊ
	this->addChild(emturn, 1, 3);												// �ǉ�

	//�h�炷����
	auto move = CCSequence::create(
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
		NULL
	);
	//�h�炷
	auto repeat = Repeat::create(move, 1);
	Kyara->runAction(repeat);

	//�{�X��HP�����炷
	Bhp = Bhp - hpcut;
	//HP��0�ɂȂ�����
	if (Bhp <= 0) {
		// �J�ڍ�̉�ʂ�ݽ�ݽ
		Scene *pScene = GameClear::createScene();

		// 0.6�b�����Ď���ʂɑJ��
		// (����,�J�ڐ�,�F(�I�v�V����))
		TransitionFade *transition = TransitionFade::create(1.0, pScene);

		// �J�ڎ��s �A�j���[�V����
		Director::getInstance()->replaceScene(transition);
	}

	//�G�t�F�N�g�̕\��
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	//�G�t�F�N�g�̗�����w��
	CCParticleSystemQuad* particle = CCParticleSystemQuad::create("efect.plist");

	particle->setAutoRemoveOnFinish(true);

	//�p�[�e�B�N���J�n
	particle->resetSystem();

	//�p�[�e�B�N����\������ꏊ�̐ݒ�
	particle->setPosition(ccp(rightSize.width / 2, rightSize.height / 3));

	//�p�[�e�B�N����z�u
	this->addChild(particle, 502, 13);
}

void BossScene::BSturn()
{
	//5000���~
	if (gametime == 100) {
		timerfnt = CCSprite::create("5000.png");
		timerfnt->setPosition(rightSize.width / 2, rightSize.height / 1.2);		// �z�u�ꏊ
		this->addChild(timerfnt, 1, 5);
	}
	if (gametime == 250) {
		//�h�炷����
		auto move = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height - 500 + ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height - 500 - ten)),
			NULL
		);
		//�h�炷
		auto repeat = Repeat::create(move, 1);
		Boss->runAction(repeat);

		// ��ʃT�C�Y�擾
		Size winSize = Director::getInstance()->getVisibleSize();

		//�L������h�炷
		auto charmove = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
			NULL
		);
		//����h�炷��
		auto charrepeat = Repeat::create(charmove, continuity);
		//�h�炷
		Kyara->runAction(charrepeat);
		//�w�i��h�炷
		auto backmove = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 2 - ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 2 + ten)),
			NULL
		);
		//����h�炷��
		auto backrepeat = Repeat::create(backmove, continuity);
		//�h�炷
		back->runAction(backrepeat);

		//�v���C���[��HP�����炷
		Php = Php - hpcut;
		//HP���[���ɂȂ�����
		if (Php <= 0) {
			// �J�ڍ�̉�ʂ�ݽ�ݽ
			Scene *pScene = GameClear::createScene();

			// 0.6�b�����Ď���ʂɑJ��
			// (����,�J�ڐ�,�F(�I�v�V����))
			TransitionFade *transition = TransitionFade::create(1.0, pScene);

			// �J�ڎ��s �A�j���[�V����
			Director::getInstance()->replaceScene(transition);
		}
	}
}

// �����o�Ă���摜
void BossScene::BossBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �o�b�N�J���[
	auto groundCollar = LayerColor::create(Color4B::RED, winSize.width, winSize.height);

	// �o�b�N�O�����hCollar��2:�\����
	this->addChild(groundCollar, 0);

// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("Boss", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));
	// Select�ǉ�
	this->addChild(lbl_Select, 1);

//�w�i
	//�w�i�̉摜�w��
	back = CCSprite::create("testhi.jpg"); 
	// �\�����W�w��
	back->setPosition(ccp(winSize.width / 2, winSize.height / 1.5f));
	//�ǉ�
	this->addChild(back, 1);

// �{�X�̕\��
	// �T�C�Y�擾
	rightSize = CCDirector::sharedDirector()->getWinSize();

	// �摜�w��
	Boss = CCSprite::create("enemy/EM_Golem.png");
	// �\�����W�w��
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height - 500));
	// �ǉ�
	this->addChild(Boss, 1);
	
//�L�����g
	// �摜�w��
	Kyara = CCSprite::create("kyarawaku.png");
	// �\�����W�w��
	Kyara->setPosition(ccp(rightSize.width / 2, rightSize.height / 4));
	// �ǉ�
	this->addChild(Kyara, 1);

//�^�C�}�[(��)
	Tsprite = CCSprite::create("Player/PL_Magic.png");
	Tsprite->setPosition(ccp(gametime, 10));
	this->addChild(Tsprite, 1);
}

// ��ʑJ��
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = GameClear::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

//�{�^�����������Ƃ�
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) 
{
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (turn == PLAYER) {
		if (state == true) {
			PLturn();					//��ȏ���
			turn = BOSS;				//�{�X�̃^�[����
			log("touchPE!o_o");			//�^�b�`�B
		}
	}
	return true;
}

//�{�^���������ė������Ƃ�
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}

//// �{�X�{�^��(��)
//auto BossButton = Boss;												//�S�[����

////�^�b�`����
//touchget->onTouchBegan = [this, visibleSize, BossButton](Touch* touch, Event* event) {
//	Vec2 point1 = touch->getLocation();									// �^�b�`�����|�C���g�B
//	Rect rectButton1 = BossButton->getBoundingBox();					// �{�^���摜�͈̔́B
//	if (rectButton1.containsPoint(point1)) {							// �{�^���摜�͈͓̔����^�b�`�����ꍇ�B
//		return true;
//	} else {
//		return false;
//	}
//};

//// listener1, PlayButton1���C�x���g�o�^����B
//auto director = Director::getInstance();
//director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchget, BossButton);