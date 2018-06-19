#include "FightScene.h"
#include "BossScene.h"
#include "WalkScene.h"

#include "HpBar.h"


const int hpGageSizeWidth = 300;
const int hpGageSizeHeight = 10;

const int ENEMY_HP_MAX = 300;				//�G��HP
const int INIT_GIVE_DAMAGE = 50;			//�G�֗^����_���[�W�̏����l
const int DAMAGE_DISPLAY_TIME = 100;		//�^�����_���[�W�̐��l�̕\������
const int EXP = 10;					//�l���o���l
const int NEXT_BATTLE_TIMER = 180;	//���ׂĂ̎G���G������Ŏ��̃o�g�����n�܂�܂ł̃^�C�}�[
const int BATTLE_MAX = 6;
const int BATTLE_LABEL_FONT_SIZE = 60;
const int BATTLE_COUNT_FONT_SIZE = 80;
const int GIVE_ENEMY_DAMAGE_FONT_SIZE = 40;

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

	_damageDispTime = DAMAGE_DISPLAY_TIME;
	_damageDispFlag = false;
	_enemyDeathFlg = true;
	_enemyDispFlag = false;
	_exp = EXP;
	_moveFlag = false;
	_hitCount = 0;
	_battleCounter = 1;
	_nextBattleTimer = NEXT_BATTLE_TIMER;

	// �o�b�N�O;�����h
	FightScene::FightBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(FightScene::ChangeBossScene, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width , 0));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, nullptr);
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

	//�o�g������������
	_battleCounter = 1;
	//�G-------------------------------------------------
	//�G��HP���Z�b�g
	_enemyHpNow = ENEMY_HP_MAX;

	_enemySprite = Sprite::create();
	FightScene::EnemySelector();

	_enemySprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_enemySprite, 0);
	//�G�摜��Rect���擾
	Rect rect;
	_enemySpriteRect = GetSpriteRect(_enemySprite,rect);
	//�GHP�Q�[�W
	//FightScene::EnemyHpGage();

	this->scheduleUpdate();	//update�����t���[���Ăяo�����

	//�G�փ����^�b�v�ŗ^����_���[�W�����Z�b�g
	_giveDamage = INIT_GIVE_DAMAGE;

	//----------------------------------------------------

	////Label�N���X�̏�����
	//label = Label::create("�����񂾂�", "Arial", 40);
	////���W���w��
	//label->setPosition(Point(100,winSize.height-100));

	////����������
	//str = String::createWithFormat("Score : %d", giveDamage);
	////������������Label�ɐݒ�
	//label->setString(str->getCString());

	////�V�[���ɒǉ�
	//this->addChild(label);
	

	//auto draw = DrawNode::create();
	////���_���W�ݒ�
	//std::vector<Vec2>vecs;
	//vecs.push_back(Vec2(-300,  335));
	//vecs.push_back(Vec2(-300, -335));
	//vecs.push_back(Vec2(300,  -335));
	////drawPolygon( ���_���W�i�[�z�� , ���_�� , �F );
	//draw->drawPolygon(&vecs[0], 3, Color4F::WHITE, 1, Color4F::YELLOW);
	//draw->setPosition(Vec2(winSize.width / 2, winSize.height / 2));

	//auto clipping = ClippingNode::create();
	//clipping->setStencil(draw);
	//clipping->setInverted(false);
	//clipping->setAlphaThreshold(1.0);
	//addChild(clipping);

	//auto sprite = Sprite::create("HelloWorld.png");
	//sprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	//clipping->addChild(sprite);

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
	auto lbl_Select = Label::createWithTTF("%i"+ENEMY_HP_MAX, "fonts/arial.ttf", 70);
	
	//�A���J�[�|�C���g�������
	lbl_Select->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	// �z�u�ꏊ
	lbl_Select->setPosition(Point(0, winSize.height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
}


//�G�֗^�����_���[�W���l��\��
void FightScene::GiveDamageDisplay(unsigned int giveDamage) {
	TTFConfig ttfConfigEffect("fonts/SHOWG.TTF", GIVE_ENEMY_DAMAGE_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	damageLabel = Label::createWithTTF(ttfConfigEffect, "-" + StringUtils::toString(giveDamage));

	damageLabel->setColor(Color3B::RED);
	damageLabel->enableGlow(Color4B::BLACK); //�F��ݒ�

	int num1 = random(0, 100) - 50;
	damageLabel->setPosition(Vec2(400 + num1, 850 + num1));
	damageLabel->enableShadow(Color4B::BLACK, Size(-2, -4), 2);
	this->addChild(damageLabel);

	int num2 = random(0, 60) - 30;
	auto *up = MoveBy::create(0.5f, Vec2(num2, 25));
	auto *fadeout = FadeOut::create(1.0f);
	auto seq = Sequence::create(up, fadeout, nullptr);
	damageLabel->runAction(seq);
}

//HIT���l��\��
void FightScene::HitDisplay() {

	TTFConfig ttfConfigEffect("fonts/SHOWG.TTF", 60, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	
	int offset = 0;
	if (_hitCount < 8) {
		offset = _hitCount*60;
	}
	else if (_hitCount > 8) {
		offset = (int)(_hitCount % 8) * 60;
	}

	hitLabel = Label::createWithTTF(ttfConfigEffect, StringUtils::toString(_hitCount) + "HIT!");
	hitLabel->setColor(Color3B::RED);
	hitLabel->setPosition(Vec2(650 , 600 + offset));
	hitLabel->enableGlow(Color4B::WHITE); //�F��ݒ�
	this->addChild(hitLabel);

	FightScene::ScalingAndFadeout(hitLabel, 0.1f, 1.5f, 0.1f, 1.0f, 2.0f, 0.4f);
	//hitLabel->pause();
	//virtual
}

//void FightScene::DrawGlowLabel(const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B glowColor) {
//	TTFConfig ttfConfigEffect(fontFilePath, fontSize, GlyphCollection::DYNAMIC);
//	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
//
//	auto label = Label::createWithTTF(ttfConfigEffect, text);
//
//	label->setColor(textCololr);
//	label->setPosition(position);
//	label->enableGlow(glowColor); //�F��ݒ�
//	this->addChild(label);
//
//}


//�������g��k���̌�Ƀt�F�[�h�A�E�g����A�j���[�V����
//ScalingAndFadeout(���x��, ���b�����Ċg�傷�邩, ���{�Ɋg�傷�邩, ���b�����ďk�����邩, ���{�ɏk����, ���b�ԕ\�������邩, �t�F�[�h�A�E�g�͉��b�����čs����)
void FightScene::ScalingAndFadeout(Label* label, float largeTime, float multiple, float backTime, float backMultiple, float delay, float fadeOutTime) {
	auto act1 = ScaleTo::create(largeTime, multiple);
	auto act2 = ScaleTo::create(backTime, backMultiple);
	auto act3 = DelayTime::create(delay);
	auto act4 = FadeOut::create(fadeOutTime);
	auto seq = Sequence::create(act1, act2, act3, act4, NULL);
	label->runAction(seq);
}



//���ȂɃo�g���ڂł���[�I���Ă��������\�L
void FightScene::BattleAnnounce() {
	Label* battleLabel;
	Label* battleCntLabel;
	Vec2 battleLabel_pos;
	Vec2 battleCntLabel_pos;
	unsigned int labelSize = (_battleCounter == BATTLE_MAX) ? BATTLE_LABEL_FONT_SIZE : BATTLE_COUNT_FONT_SIZE;

	TTFConfig ttfConfigEffect("fonts/COPRGTB.TTF", BATTLE_LABEL_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true;

	TTFConfig ttfConfigEffect2("fonts/COPRGTB.TTF", labelSize, GlyphCollection::DYNAMIC);
	ttfConfigEffect2.distanceFieldEnabled = true;

	//�o�g���T�ȉ��ƍŌ�̃o�g���ł̓t�H���g�T�C�Y�ƃ|�W�V�������قȂ�
	if (_battleCounter < BATTLE_MAX) {
		battleLabel = Label::createWithTTF(ttfConfigEffect, "Battle");
		battleCntLabel = Label::createWithTTF(ttfConfigEffect2, StringUtils::toString(_battleCounter));
		battleLabel_pos = Vec2(400, 820);
		battleCntLabel_pos = Vec2(570, 780);
	}else if (_battleCounter == BATTLE_MAX) {
		battleLabel = Label::createWithTTF(ttfConfigEffect, "Final");
		battleCntLabel = Label::createWithTTF(ttfConfigEffect2, "Battle");
		battleLabel_pos = Vec2(290, 820);
		battleCntLabel_pos = Vec2(510, 780);
	}
	battleLabel->setColor(Color3B::BLACK);
	battleLabel->enableGlow(Color4B::WHITE);
	battleLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleLabel->setPosition(battleLabel_pos);

	battleCntLabel->setColor(Color3B::BLACK);
	battleCntLabel->enableGlow(Color4B::WHITE);
	battleCntLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleCntLabel->setPosition(battleCntLabel_pos);

	this->addChild(battleLabel);
	this->addChild(battleCntLabel);

	//�����̃��x�������������\����
	battleLabel->setOpacity(0.0f);
	battleCntLabel->setOpacity(0.0f);

	//@param bl battleLabel
	//@param bcl battleCntLabel

	//�o�g�����x���p�t�F�[�h�A�E�g�ƃC���̐ݒ�
	auto *bl_fadein = FadeIn::create(0.3f);
	auto *bl_fadeout = FadeOut::create(0.3f);
	//�o�g���i���o�[���x���p�t�F�[�h�A�E�g�ƃC���̐ݒ�
	auto *bcl_fadein = FadeIn::create(0.3f);
	auto *bcl_fadeout = FadeOut::create(0.3f);
	//���̑���move�B�͋��p����
	auto *down = MoveBy::create(0.4f, Vec2(0, -20));
	auto *up = MoveBy::create(0.4f, Vec2(0, 20));
	auto *delay = DelayTime::create(1.0f);
	//Spawn�ŕ����̃A�N�V�����𓯎��Ɏ��s����ݒ���s��
	auto bl_fastMoves = Spawn::createWithTwoActions(bl_fadein, down);
	auto bl_lastMoves = Spawn::createWithTwoActions(bl_fadeout, down);
	auto bcl_fastMoves = Spawn::createWithTwoActions(bcl_fadein, up);
	auto bcl_lastMoves = Spawn::createWithTwoActions(bcl_fadeout, up);
	//���ԂɃA�N�V���������s���邽�߂̐ݒ���s��
	auto battleLabelMoves = Sequence::create(bl_fastMoves, delay, bl_lastMoves, nullptr);
	auto battleCntLabelMoves = Sequence::create(bcl_fastMoves, delay, bcl_lastMoves, nullptr);
	//�A�N�V�����̎��s
	battleLabel->runAction(battleLabelMoves);
	battleCntLabel->runAction(battleCntLabelMoves);
}

// �^�b�`�����u��
bool FightScene::TouchBegan(Touch * touch, Event * event)
{
	//�^�b�`���W���擾
	_touchLocation = touch->getLocation();

	//�G���\������Ă��Ă��AenemySpriteRect�����N���b�N����Ă���΁E�E�E
	if (_enemyDispFlag) {
		if (_enemySpriteRect.containsPoint(_touchLocation)) {
			log("enemySpriteClickCheck");
			_enemyHpNow -= _giveDamage;

			FightScene::GiveDamageDisplay(_giveDamage);
			_damageDispFlag = true;
			_damageDispTime = DAMAGE_DISPLAY_TIME;
			_hitCount++;
			//FightScene::HitDisplay();		//������ƍ�Ƃ��x��zzz...
		}
	}

	return true;
}

// �X���C�v��
void FightScene::TouchMove(Touch * touch, Event * event)
{

}

// �w�𗣂����u��
void FightScene::TouchEnd(Touch * touch, Event * event)
{
	//�G��Hp��0�ȉ��ɂȂ����Ƃ�
	if (_enemyHpNow <= 0) {
		_enemyHpNow = ENEMY_HP_MAX;
		_enemyDeathFlg = true;
		_enemyDispFlag = false;
		_nextBattleTimer = NEXT_BATTLE_TIMER;
		FightScene::ExpGetAnnounce();
		//�o�g�������C���N�������g���Ă���G�̉摜��؂�ւ���
		if (++_battleCounter > BATTLE_MAX) {
			FightScene::ChangeBossScene(this);
		}
		FightScene::EnemySelector();
	}

	//Hp���X�V
	FightScene::ReloadEnemyHp();
	//enemySpriteRect�����N���b�N���Ă�����E�E�E
	if (_enemyDispFlag) {
		if (_enemySpriteRect.containsPoint(_touchLocation)) {
			FightScene::SpriteTremble(_enemySprite);
		}
	}
	//log("enemyHp = %i", _enemyHpNow);
	//log("roundCounter = %i", _battleCounter);

}


//�摜��U��������
void FightScene::SpriteTremble(Sprite* sprite) {
	auto *right = MoveBy::create(0.05f, Vec2(0, 5));
	auto *left = MoveBy::create(0.05f, Vec2(0, -5));
	auto *up = MoveBy::create(0.05f, Vec2(5, 0));
	auto *down = MoveBy::create(0.05f, Vec2(-5, 0));
	auto moves = Sequence::create(right, left, up, down, nullptr);
	sprite->runAction(moves);
}

//�摜��Rect���擾����
Rect FightScene::GetSpriteRect(Sprite* sprite, Rect rect) {
	 rect = Rect(sprite->getPosition().x - sprite->getContentSize().width / 2,
				 sprite->getPosition().y - sprite->getContentSize().width / 2,
				 sprite->getContentSize().width,
				 sprite->getContentSize().height);
	 return rect;
}

//�G��Hp�o�[
void FightScene::EnemyHpGage() {
	Size winSize = Director::getInstance()->getWinSize();
	//�ԃQ�[�W
	auto backHpRect = Rect(0, 0, hpGageSizeWidth, hpGageSizeHeight);
	auto redSquare = Sprite::create();
	redSquare->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	redSquare->setTextureRect(backHpRect);
	redSquare->setPosition(winSize.width / 3, 900);
	redSquare->setColor(Color3B::RED);
	this->addChild(redSquare);
	//�Q�[�W
	_enemyHpRect = Rect(0, 0, (_enemyHpNow / ENEMY_HP_MAX) * hpGageSizeWidth, 10);
	_blueSquare = Sprite::create();
	_blueSquare->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	_blueSquare->setTextureRect(_enemyHpRect);
	_blueSquare->setPosition(winSize.width / 3, 900);
	_blueSquare->setColor(Color3B::BLUE);
	this->addChild(_blueSquare);

	redSquare->setOpacity(0.0f);	//���������\���Ɂi255�ɂ���ƕ\������j
	auto *r_delay = DelayTime::create(3.0f);
	auto r_fadein = FadeIn::create(0.5f);
	auto r_acts = Sequence::create(r_delay, r_fadein, nullptr);
	redSquare->runAction(r_acts);

	_blueSquare->setOpacity(0.0f);	//���������\���Ɂi255�ɂ���ƕ\������j
	auto *b_delay = DelayTime::create(2.0f);
	auto b_fadein = FadeIn::create(1.0f);
	auto b_acts = Sequence::create(b_delay, b_fadein, nullptr);
	_blueSquare->runAction(b_acts);

}

//�G��Hp�o�[�����X�V
void FightScene::ReloadEnemyHp() {
	_enemyHpRect = Rect(0, 0, _enemyHpNow, hpGageSizeHeight);
	_blueSquare->setTextureRect(_enemyHpRect);
}

// Boss��ʂ֑J��
void FightScene::ChangeBossScene(Ref * pSender)
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

// Walk��ʂ֑J��
void FightScene::ChangeWalkScene(Ref * pSender)
{
	log("Push�{�^��");
	Scene *pScene = WalkScene::createScene();
	TransitionFade *transition = TransitionFade::create(0.6, pScene);
	Director::getInstance()->replaceScene(transition);
}


//�o���l�l���A�i�E���X�̕\��
void FightScene::ExpGetAnnounce() {
	Size winSize = Director::getInstance()->getWinSize();
	expLabel = Label::createWithSystemFont("+" + StringUtils::toString(_exp)+" EXP", "Stencil", 70);
	expLabel->setColor(Color3B::RED);

	expLabel->setPosition(Point(winSize.width/2, 1000));
	expLabel->enableShadow(Color4B::BLACK, Size(-2, -4), 2);
	this->addChild(expLabel);

	FightScene::ScalingAndFadeout(expLabel, 0.1f, 1.3f, 0.1f, 1.0f, 2.0f, 0.4f);
}

//
void FightScene::update(float delta) {

	//�_���[�W�\���͈�莞�ԂŃI�t��
	if (_damageDispFlag) {
		if (--_damageDispTime < 1) {
			damageLabel->setVisible(false);
			_damageDispFlag = false;
		}else{
			damageLabel->setVisible(true);
			_damageDispFlag = true;
		}
	}


	//log("dispCnt = %i", _damageDispTime);
	//log("dispflag = %i", _damageDispFlag);
	//log("EPointDispTimeCnt = %i", EPointDispTime);

	log("_enemyDeathFlg = %i", _enemyDeathFlg);
	log("_nextBattleTimer = %i", _nextBattleTimer);
	log("_enemyDispFlag = %i", _enemyDispFlag);

	//�G�����S���Ă����玟�̃o�g�����n�܂�܂ł̃J�E���g�_�E�����X�^�[�g
	//�J�E���g���O�ɂȂ�����G�̎��S��ԃt���O�������āA�G�̕\���t���O�𗧂Ă�B
	if (_enemyDeathFlg) {
		if (--_nextBattleTimer < 1) {
			_enemyDispFlag = true;
			_enemyDeathFlg = false;
		}
	}
}

//�G�̐؂�ւ�
void FightScene::EnemySelector() {
	switch ((BattleNumber)_battleCounter) {
	case BattleNumber::Battle1:
		_enemySprite->setTexture("enemy/zako/Sleipnir.png");
		break;
	case BattleNumber::Battle2:
		_enemySprite->setTexture("enemy/zako/BoxDevil.png");
		break;
	case BattleNumber::Battle3:
		_enemySprite->setTexture("enemy/zako/CakeDora.png");
		break;
	case BattleNumber::Battle4:
		_enemySprite->setTexture("enemy/zako/Oden.png");
		break;
	case BattleNumber::Battle5:
		_enemySprite->setTexture("enemy/zako/Moja.png");
		break;
	case BattleNumber::Battle6:
		_enemySprite->setTexture("enemy/zako/Tors.png");
		break;
	}

	_enemySprite->setOpacity(0.0f);	//���������\���Ɂi255�ɂ���ƕ\������j
	auto *delay = DelayTime::create(2.0f);
	auto fadein = FadeIn::create(1.0f);
	auto acts = Sequence::create(delay, fadein, nullptr);
	_enemySprite->runAction(acts);

	if (_battleCounter <= BATTLE_MAX) {
		FightScene::BattleAnnounce();
	}
	FightScene::EnemyHpGage();


}
