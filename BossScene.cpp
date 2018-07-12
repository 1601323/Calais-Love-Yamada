#include "BossScene.h"
#include "GameClear.h"
#include <ui/CocosGUI.h>
#pragma execution_character_set("utf-8")

using namespace ui;
using namespace std; // String*

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
	
	//�L�����g�P�i�A�^�b�J�[�̏ꍇ�j
	pl1frame.hp = 115;					//HP
	pl1frame.hpmax = pl1frame.hp;		//HPMAX
	pl1frame.mana = 38;					//MP
	pl1frame.manamax = pl1frame.mana;	//MPMAX
	pl1frame.atk = 90;					//ATK
	pl1frame.atkmax = pl1frame.atk;		//ATKMAX
	pl1frame.def = 78;					//DEF
	pl1frame.defmax = pl1frame.def;		//DEFMAX
	pl1frame.matk = 57;					//MATK
	pl1frame.matkmax = pl1frame.matk;	//MATKMAX
	pl1frame.mdef = 78;					//MDEF
	pl1frame.mdefmax = pl1frame.mdef;	//MDEFMAX
	pl1frame.choicejob = HEALER;			//���m
	//�L�����g2�i�q�[���[�ȏꍇ�j
	pl2frame.hp = 86;					//HP
	pl2frame.hpmax = pl2frame.hp;		//HPMAX
	pl2frame.mana = 75;					//MP
	pl2frame.manamax = pl2frame.mana;	//MPMAX
	pl2frame.atk = 61;					//ATK
	pl2frame.atkmax = pl2frame.atk;		//ATKMAX
	pl2frame.def = 74;					//DEF
	pl2frame.defmax = pl2frame.def;		//DEFMAX
	pl2frame.matk = 57;					//MATK
	pl2frame.matkmax = pl2frame.matk;	//MATKMAX
	pl2frame.mdef = 69;					//MDEF
	pl2frame.mdefmax = pl2frame.mdef;	//MDEFMAX
	pl2frame.choicejob = MAGIC;		//���E��
	//�L�����g3�i�}�W�b�N�̏ꍇ�j
	pl3frame.hp = 93;					//HP
	pl3frame.hpmax = pl3frame.hp;		//HPMAX
	pl3frame.mana = 69;					//MP
	pl3frame.manamax = pl3frame.mana;	//MPMAX
	pl3frame.atk = 61;					//ATK
	pl3frame.atkmax = pl3frame.atk;		//ATKMAX
	pl3frame.def = 69;					//DEF
	pl3frame.defmax = pl3frame.def;		//DEFMAX
	pl3frame.matk = 90;					//MATK
	pl3frame.matkmax = pl3frame.matk;	//MATKMAX
	pl3frame.mdef = 74;					//MDEF
	pl3frame.mdefmax = pl3frame.mdef;	//MDEFMAX
	pl3frame.choicejob = ATTACKER;			//���p�t

	//���m
	if (pl1frame.choicejob == ATTACKER) {
		attacker.hp = pl1frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl1frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl1frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl1frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl1frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl1frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == ATTACKER) {
		attacker.hp = pl2frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl2frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl2frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl2frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl2frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl2frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == ATTACKER) {
		attacker.hp = pl3frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl3frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl3frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl3frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl3frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl3frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	//�R�m
	if (pl1frame.choicejob == SHIELD) {
		shield.hp = pl1frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl1frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl1frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl1frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl1frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl1frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == SHIELD) {
		shield.hp = pl2frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl2frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl2frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl2frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl2frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl2frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == SHIELD) {
		shield.hp = pl3frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl3frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl3frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl3frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl3frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl3frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	//���p�t
	if (pl1frame.choicejob == MAGIC) {
		magic.hp = pl1frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl1frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl1frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl1frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl1frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl1frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == MAGIC) {
		magic.hp = pl2frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl2frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl2frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl2frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl2frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl2frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == MAGIC) {
		magic.hp = pl3frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl3frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl3frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl3frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl3frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl3frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	//���E��
	if (pl1frame.choicejob == HEALER) {
		healer.hp = pl1frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl1frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl1frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl1frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl1frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl1frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == HEALER) {
		healer.hp = pl2frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl2frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl2frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl2frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl2frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl2frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == HEALER) {
		healer.hp = pl3frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl3frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl3frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl3frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl3frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl3frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	//���@���L���[
	valkyrie.hp = 800;					//HP
	valkyrie.hpmax = valkyrie.hp;		//HPMAX
	valkyrie.mana = 10;					//MP
	valkyrie.manamax = valkyrie.mana;	//MPMAX
	valkyrie.atk = 64;					//ATK
	valkyrie.atkmax = valkyrie.atk;		//ATKMAX
	valkyrie.def = 128;					//DEF
	valkyrie.defmax = valkyrie.def;		//DEFMAX
	valkyrie.matk = 70;					//MATK
	valkyrie.matkmax = valkyrie.matk;	//MATKMAX
	valkyrie.mdef = 88;					//MDEF
	valkyrie.mdefmax = valkyrie.mdef;	//MDEFMAX

	//�����ݒ�
	turn = PLAYER;			//�N�̃^�[���H
	battle = START;			//�o�g��
	choices = CHAR1;		//�R�}���h��I�ԍŏ��̃L����
	bsact = PICK;			//�{�X�̓���
	job = NON;				//�L�����I��
	
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
	this->addChild(menu, backdepth);

	//�^�b�`���[�h�ݒ�
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// �o�b�N�O�����h
	BossBackGroudn();

	//�A�b�v�f�[�g�X�V
	this->scheduleUpdate();

	return true;
}

void BossScene::update(float flame)
{
	if (turn == PLAYER) {
		switch (battle){
			battle = START;
		case BossScene::START: {
			state = false;
			//�U���R�}���h�{�^��
			AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	 //�摜�w��
			AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
			this->addChild(AttackButton1, middledepth, attackbuttonaI);				//�ǉ�		

			//�U���R�}���h�{�^��(������Ă���Ƃ�)
			AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	 //�摜�w��
			AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
			this->addChild(AttackButton2, backdepth, attackbuttonbI);				//�ǉ�

			//�X�L���R�}���h�{�^��
			SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//�摜�w��
			SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
			this->addChild(SkillButton1, middledepth, skillbuttonaI);				//�ǉ�

			//�X�L���R�}���h�{�^��(������Ă���Ƃ�)
			SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//�摜�w��
			SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
			this->addChild(SkillButton2, backdepth, skillbuttonbI);						//�ǉ�

			//PLTURN(�E��)															
			plturn = CCSprite::create("Description/PL.png");						//�z�u����
			plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//�ꏊ�z�u
			this->addChild(plturn, backdepth, playertrunI);							//�ǉ�

			battle = WAIT;
			break;
		}
		case BossScene::WAIT: {
			
			battle = CHOICE;
			break;
		}
		case BossScene::CHOICE: {
			// ��ʃT�C�Y�擾�B
			Size visibleSize = Director::getInstance()->getVisibleSize();
			//�擾
			auto Atouchget = EventListenerTouchOneByOne::create();	//�A�^�b�N�{�^��
			auto Stouchget = EventListenerTouchOneByOne::create();	//�X�L���{�^��

			choicetime++;											//�{�^�����A���ŉ�����Ȃ��悤�ɂ��邽�߂̏���
			//�^�b�`����
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;
			//�A�^�b�N�{�^��
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();					//�^�b�`�����|�C���g�B
				Rect rectButton1 = Abutton->getBoundingBox();		//�{�^���摜�͈̔́B
				switch (choices) {
				//�L����1
				case BossScene::CHAR1: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point1)) {
							AttackButton1->setVisible(false);		//��̃{�^��������
							pl1 = PL1ATTACK;						//�A�^�b�N�ɂ���
							this->removeChildByTag(choiceS);
							choicetime = 0;
							choices = CHAR2;						//���̃L������
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//�L����2
				case BossScene::CHAR2: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point1)) {
							this->removeChildByTag(choiceS);
							AttackButton1->setVisible(false);		//��̃{�^��������
							pl2 = PL2ATTACK;						//�A�^�b�N�ɂ���
							choicetime = 0;
							choices = CHAR3;						//���̃L������
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//�L����3
				case BossScene::CHAR3: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ
						if (rectButton1.containsPoint(point1)) {
							pick_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
							act_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
							decide_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓���)
							skill_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�X�L��)
							state = true;							//�������Ԃɂ���
							Abutton->removeFromParentAndCleanup(true);//�R�}���h�{�^��(attack)������
							this->removeChildByTag(attackbuttonbI);
							this->removeChildByTag(skillbuttonaI);
							this->removeChildByTag(skillbuttonbI);
							this->removeChildByTag(choiceS);
							pl3 = PL3ATTACK;						//�A�^�b�N�ɂ���
							choicetime = 0;
							battle = ACTION;						//�G�t�F�N�g�Ȃ�
							choices = CHAR1;
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				default: {
					break;
				}
				}
				return true;
			};
			//�X�L���{�^��
			Stouchget->onTouchBegan = [this, visibleSize, Sbutton](Touch* touch, Event* event) {
				Vec2 point2 = touch->getLocation();						//�^�b�`�����|�C���g�B
				Rect rectButton1 = Sbutton->getBoundingBox();			//�{�^���摜�͈̔́B
				switch (choices) {
				//�L����1
				case BossScene::CHAR1: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {
							SkillButton1->setVisible(false);			//��̃{�^��������
							pl1 = PL1SKILL;								//�X�L�����g��
							askill = ASKILL1;							//�c�C���t���[��
							sskill = SSKILL1;							//�A�C���X�]�C��
							mskill = MSKILL1;							//�}�W�b�N�~�T�C��
							hskill = HSKILL2;							//���҂̌o�T
							if(pl1frame.choicejob)
							choicetime = 0;
							this->removeChildByTag(choiceS);
							choices = CHAR2;							//���̃L������
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//�L����2
				case BossScene::CHAR2: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {
							SkillButton1->setVisible(false);			//��̃{�^��������
							pl2 = PL2SKILL;								//�X�L���g��
							askill = ASKILL2;							//�A�[�}�[�u���C�N
							sskill = SSKILL2;							//�J�E���^�[
							mskill = MSKILL2;							//�A�[�}�[�V���b�g
							hskill = HSKILL3;							//���҂̌o�T
							choicetime = 0;
							this->removeChildByTag(choiceS);
							choices = CHAR3;							//���̃L������
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//�L����3
				case BossScene::CHAR3: {
					if (choicetime > flame15) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {
							pick_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
							act_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�{�X�̓�����)
							decide_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓���)
							skill_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�X�L��)
							state = true;								//�������Ԃɂ���
							Sbutton->removeFromParentAndCleanup(true);	//�R�}���h�{�^��(attack)������
							this->removeChildByTag(attackbuttonaI);
							this->removeChildByTag(attackbuttonbI);
							this->removeChildByTag(skillbuttonbI);
							this->removeChildByTag(choiceS);
							pl3 = PL3SKILL;								//�X�L���ɂ���
							askill = ASKILL3;							//���C�t�\�[�h
							sskill = SSKILL3;							//�őO��
							mskill = MSKILL3;							//�}�W�b�N�o�[�X�g
							hskill = HSKILL7;							//�Z�C���g�I�[�_�[
							choicetime = 0;								//�^�C����0
							battle = ACTION;							//�G�t�F�N�g�Ȃǂ�S��
							choices = CHAR1;
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				default: {
					break;
				}
				}
				return true;
			};
			//�I������Ƃ��ɏo�镶��
			if (choicetime == flame15) {
				if (choices == CHAR1) {
					if (pl1frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("���m�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl1frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("���E�҂͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl1frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("���p�t�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
				else if (choices == CHAR2) {
					if (pl2frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("���m�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("���E�҂͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("���p�t�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
				else if (choices == CHAR3) {
					if (pl3frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("���m�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("���E�҂͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("���p�t�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
			}
			//�I���L�����𖾊m�ɂ���(�I������ĂȂ��L�����͏����Â�����)
			if (choices == CHAR1) {
				//pl1frame�̎�
				if (pl1frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl1frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl1frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR2) {
				//pl2frame�̎�
				if (pl2frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl2frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl2frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR3) {
				//pl3frame�̎�
				if (pl3frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl3frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl3frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
			}

			// touchget, button���C�x���g�o�^����B
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Atouchget, Abutton);
			auto director2 = Director::getInstance();
			director2->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Stouchget, Sbutton);
			break;
		}
		//�v���C���[�̃A�N�V����(�G�t�F�N�g�Ȃ�)
		case BossScene::ACTION: {
			this->removeChildByTag(choiceS);
			//�v���C���[�����̉摜�̐F��߂�
			PL1p->setColor(ccc3(colormax, colormax, colormax));
			PL2p->setColor(ccc3(colormax, colormax, colormax));
			PL3p->setColor(ccc3(colormax, colormax, colormax));
			if (state == true) {
				gameflame++;							//�J�E���g�J�n
				skillflame++;							//�X�L���J�E���g�J�n
				PLturn();								//��ȏ���
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	else if (turn == BOSS) {
		//������
		//���m�̃_���[�W�����̏�����
		if(pl1frame.choicejob == ATTACKER){
			//���m�_���[�W�\��
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout1 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == ATTACKER) {
			//���m�_���[�W�\��
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout1 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == ATTACKER) {
			//���m�_���[�W�\��
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout1 = CCFadeOut::create(2.0f);												//���b�ŏ�����H
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		//���E�҂̃_���[�W�����̏�����
		if (pl1frame.choicejob == HEALER) {
			//���E�҃_���[�W�\��
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout2 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov2= CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if(pl2frame.choicejob == HEALER){
			//���E�҃_���[�W�\��
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout2 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov2 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == HEALER) {
			//���E�҃_���[�W�\��
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout2 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov2 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		//���p�t�̃_���[�W�����̏�����
		if (pl1frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout3 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout3 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			fadeout3 = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		flag = false;									//�t���O��false��
		gameflame++;									//�J�E���g�J�n
		BSturn();										//��ȏ���
		
		if (gameflame == flame170) {
			//����������
			this->removeChildByTag(normalattackS);		//�ʏ�U��
			this->removeChildByTag(bossskill1S);		//�X�L��1			
			this->removeChildByTag(bossskill2S);		//�X�L��2
			this->removeChildByTag(bossskill3S);		//�X�L��3
			this->removeChildByTag(bossskill4S);		//�X�L��4
		}
		if (gameflame > flamemax) {
			if (act_rnd < 20) {
				//����������
				this->removeChildByTag(bossturnI);				//BSTURN
				this->removeChildByTag(damageS);				//���ʕ\�L(�ʏ�U��)
				this->removeChildByTag(bossskill1E);			//�p�[�e�B�N��
				this->removeChildByTag(bossskill1damageS);		//���ʕ\�L(�X�L��1)
				this->removeChildByTag(bossskill2damageS);		//���ʕ\�L(�X�L��2)
				this->removeChildByTag(bossskill3damageS);		//���ʕ\�L(�X�L��3)
				this->removeChildByTag(bossskill4damageS);		//���ʕ\�L(�X�L��4)

				gameflame = 0;									//���Ԃ�0��
				actcnt = 0;										//�J�E���g��0��
				fntflag = false;								//�_���[�W�\���t���O��false��
				job = NON;										//�I�񂾃L�����������̏�Ԃɖ߂�
				battle = START;									//�o�g���������̏�Ԃɖ߂�
				choices = CHAR1;								//�I���L�������ŏ���
				turn = PLAYER;									//�v���C���[�̃^�[����
			}
			if (act_rnd >= 20 && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//����������
					this->removeChildByTag(damageS);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(bossskill1E);		//�p�[�e�B�N��
					this->removeChildByTag(bossskill1damageS);	//���ʕ\�L(�X�L��1)
					this->removeChildByTag(bossskill2damageS);	//���ʕ\�L(�X�L��2)
					this->removeChildByTag(bossskill3damageS);	//���ʕ\�L(�X�L��3)
					this->removeChildByTag(bossskill4damageS);	//���ʕ\�L(�X�L��4)

					pick_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
					act_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�{�X�̓�����)
					decide_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓���)
					skill_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�X�L��)

					actcnt += 1;								//�U���J�E���g�𑝂₵��2��ȏ�U�����Ȃ��悤�ɂ���
					gameflame = 0;								//���Ԃ�0��
					fntflag = false;							//�_���[�W�\���t���O��false��
					bsact = PICK;								//�{�X�̓����������ɖ߂�
					turn = BOSS;								//�������{�X�̍s����
				}
				else {
					//����������
					this->removeChildByTag(bossturnI);			//BSTURN
					this->removeChildByTag(damageS);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(bossskill1E);		//�p�[�e�B�N��
					this->removeChildByTag(bossskill1damageS);	//���ʕ\�L(�X�L��1)
					this->removeChildByTag(bossskill2damageS);	//���ʕ\�L(�X�L��2)
					this->removeChildByTag(bossskill3damageS);	//���ʕ\�L(�X�L��3)
					this->removeChildByTag(bossskill4damageS);	//���ʕ\�L(�X�L��4)

					gameflame = 0;								//���Ԃ�0��
					actcnt = 0;									//�J�E���g��0��
					fntflag = false;							//�_���[�W�\���t���O��false��
					job = NON;									//�I�񂾃L�����������̏�Ԃɖ߂�
					battle = START;								//�o�g���������̏�Ԃɖ߂�
					choices = CHAR1;							//�I���L�������ŏ���
					turn = PLAYER;								//�v���C���[�̃^�[����
				}
			}
		}
	}
	//���m��HP�Q�[�W�����炷
	HPpl1->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl1hpgaugewidth * attacker.hp / attacker.hpmax,
		HPpl1->getContentSize().height));
	//���m��MANA�Q�[�W�ɕω�������
	MNpl1->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl1mngaugewidth * attacker.mana / attacker.manamax,
		MNpl1->getContentSize().height));
	//���E�҂�HP�Q�[�W�����炷
	HPpl2->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl2hpgaugewidth * healer.hp / healer.hpmax,
		HPpl2->getContentSize().height));
	//���E�҂�MANA�Q�[�W�ɕω�������
	MNpl2->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl2mngaugewidth * healer.mana / healer.manamax,
		MNpl2->getContentSize().height));
	//���p�t��HP�Q�[�W�����炷
	HPpl3->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl3hpgaugewidth * magic.hp / magic.hpmax,
		HPpl3->getContentSize().height));
	//���p�t��MANA�Q�[�W�ɕω�������
	MNpl3->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl3mngaugewidth * magic.mana / magic.manamax,
		MNpl3->getContentSize().height));
	//�{�X��HP�Q�[�W�ɕω�������
	HPboss->setTextureRect(Rect(HPbar.x, HPbar.y,
		bosshpgaugewidth * valkyrie.hp / valkyrie.hpmax,
		HPboss->getContentSize().height));
	//���ꂼ��̃v���C���[��HP�AMANA��MAX�ȏ�̎�MAX�ɂ���
	if (attacker.hp >= attacker.hpmax) {
		p1hpal->setString(std::to_string(attacker.hpmax));
		attacker.hp = attacker.hpmax;
	}
	if (attacker.mana >= attacker.manamax) {
		p1mnal->setString(std::to_string(attacker.manamax));
		attacker.mana = attacker.manamax;
	}
	if (healer.hp >= healer.hpmax) {
		p2hpal->setString(std::to_string(healer.hpmax));
		healer.hp = healer.hpmax;
	}
	if (healer.mana >= healer.manamax) {
		p2mnal->setString(std::to_string(healer.manamax));
		healer.mana = healer.manamax;
	}
	if (magic.hp >= magic.hpmax) {
		p3hpal->setString(std::to_string(magic.hpmax));
		magic.hp = magic.hpmax;
	}
	if (magic.mana >= magic.manamax) {
		p3mnal->setString(std::to_string(magic.manamax));
		magic.mana = magic.manamax;
	}
	//���ꂼ��̃v���C���[��HP�AMANA��0�ȉ��̎�0�ɂ���
	//���m
	if (attacker.hp <= hpmin) {
		p1hpal->setString(std::to_string(hpmin));
		attacker.hp = hpmin;
	}
	if (attacker.mana <= hpmin) {
		p1mnal->setString(std::to_string(hpmin));
		attacker.mana = hpmin;
	}
	//���E��
	if (healer.hp <= hpmin) {
		p2hpal->setString(std::to_string(hpmin));
		healer.hp = hpmin;
	}
	if (healer.mana <= hpmin) {
		p2mnal->setString(std::to_string(hpmin));
		healer.mana = hpmin;
	}
	//���p�t
	if (magic.hp <= hpmin) {
		p3hpal->setString(std::to_string(hpmin));
		magic.hp = hpmin;
	}
	if (magic.mana <= hpmin) {
		p3mnal->setString(std::to_string(hpmin));
		magic.mana = hpmin;
	}
 }

void BossScene::PLturn()
{
	switch (choices)
	{
	case BossScene::CHAR1: {
		//�v���C���[1�̍s��

		if (pl1frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl1frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl1frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl1frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl1 == PL1ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl1 == PL1SKILL) {
			Plskills();
		}
		//�U���E�X�L�����I�������
		if (attackendflag == true || skillendflag == true) {
			choices = CHAR2;								//���̃L������
			pl1 = PL1NON;									//pl1�͉������Ȃ��悤�ɂ���
			gameflame = 0;									//���Ԃ������l�ɖ߂�
			skillflame = 0;									//�X�L���̎��Ԃ������l��
			skillendflag = false;							//�t���O�����l�ɖ߂�
			attackendflag = false;							//�t���O��߂�
		}
		break;
	}
	case BossScene::CHAR2: {
		//�v���C���[2�̍s��
		if (pl2frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl2frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl2frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl2frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl2 == PL2SKILL) {
			Plskills();
		}
		if (attackendflag == true || skillendflag == true) {
			choices = CHAR3;
			gameflame = 0;									//���Ԃ������l�ɖ߂�
			skillflame = 0;									//�X�L���̎��Ԃ������l��
			skillendflag = false;							//�t���O�����l�ɖ߂�
			attackendflag = false;							//�t���O��߂�
		}
		break;
	}
	case BossScene::CHAR3: {
		//�v���C���[3�̍s��
		if (pl3frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl3frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl3frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl3frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl3 == PL3SKILL) {
			Plskills();
		}
		if (attackendflag == true || skillendflag == true) {
			bsact = PICK;								//�{�X�̓�����������
			turn = BOSS;								//�{�X�̃^�[����
			choices = CHAR1;							//�I�����ŏ�����ɖ߂�
			this->removeChildByTag(playertrunI);		//PLTURN������
			gameflame = 0;								//���Ԃ������l�ɖ߂�
			skillflame = 0;								//�X�L���̎��Ԃ������l��
			skillendflag = false;						//�t���O�����l�ɖ߂�
			attackendflag = false;						//�t���O��߂�
			//BSTURN�����\��
			emturn = CCSprite::create("Description/BS.png");							// �z�u����
			emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// �z�u�ꏊ
			this->addChild(emturn, backdepth, bossturnI);								// �ǉ�
		}
		break;
	}
	default: {
		break;
	}
	}
	//HP��0�ɂȂ�����
	if (valkyrie.hp <= 0) {
		// �J�ڍ�̉�ʂ�ݽ�ݽ
		Scene *pScene = GameClear::createScene();
		// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
		TransitionFade *transition = TransitionFade::create(1.0, pScene);
		// �J�ڎ��s �A�j���[�V����
		Director::getInstance()->replaceScene(transition);
	}
}

void BossScene::Plattacks()
{
	//���m
	if (job == ATTACKER) {
		if (gameflame == flame50) {
			//�ʏ�U��
			if (pl1 == PL1ATTACK) {
				//�{�X��HP�����炷
				Damage();
				Boss->runAction(bossrepeat);
				hpcut = (attacker.atk - valkyrie.def);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p1atk = String::createWithFormat("PL1��%i�_���[�W�^����", hpcut);
				string _p1atk = p1atk->getCString();
				auto p1alabel = Label::createWithSystemFont(_p1atk, "HGRSGU.TTC", fontsizeL);
				p1alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1alabel, backdepth, attackerdamageS);
			}
		}
		//�U���I���
		if (pl1 == PL1ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
	//���E��
	if (job == HEALER) {
		if (gameflame == flame50) {
			//�ʏ�U��
			if (pl2 == PL2ATTACK) {
				//�{�X��HP�����炷
				hpcut = (healer.atk - valkyrie.def);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p2atk = String::createWithFormat("PL2��%i�_���[�W�^����", hpcut);
				string _p2atk = p2atk->getCString();
				auto p2alabel = Label::createWithSystemFont(_p2atk, "HGRSGU.TTC", fontsizeL);
				p2alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p2alabel, backdepth, healerdamageS);
			}
		}
		//�U���I���
		if (pl2 == PL2ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
	//���p�t
	if (job == MAGIC) {
		if (gameflame == flame50) {
			//�ʏ�U��
			if (pl3 == PL3ATTACK) {
				//�{�X��HP�����炷
				hpcut = (magic.atk - valkyrie.def);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p3atk = String::createWithFormat("PL3��%i�_���[�W�^����", hpcut);
				string _p3atk = p3atk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p3atk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, magicdamageS);
			}
		}
		//�U���I���
		if (pl3 == PL3ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
}

void BossScene::Plskills()
{
	//���m
	if (job == ATTACKER) {
		if (askill == ASKILL1) {
			//�c�C���t���[��
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W2��U��
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill1.plist");
				plparticle->setAutoRemoveOnFinish(true);
				//�G�t�F�N�g����
				plparticle->resetSystem();								//�p�[�e�B�N���J�n
				plparticle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
				this->addChild(plparticle, backdepth, askill1E);		//�p�[�e�B�N����z�u

				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 3;
				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
			}
			//2��ڂ̃_���[�W��^����
			if (skillflame == flame150) {
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�A�[�}�[�u���C�N
		if (askill == ASKILL2) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W+�h��̓_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�G�̃X�e�[�^�X(�h���)��������l�����߂�
				//���̖h��͂�2�����炷
				buffdown = valkyrie.def * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				valkyrie.def -= buffdown;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//���C�t�\�[�h
		if (askill == ASKILL3) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W�{���g��HP������
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�񕜂���l�����߂�
				//����HP��2����
				recovery = attacker.hp * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				attacker.hp += recovery;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�C���p�N�g�X���b�V��
		if (askill == ASKILL4) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W+�U���̓_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�G�̃X�e�[�^�X(�U����)��������l�����߂�
				//���̍U���͂�2�����炷
				buffdown = valkyrie.atk * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�\�[�h�X���[
		if (askill == ASKILL5) {
			if (skillflame == flame50) {
				//�G�P�̂ɖh��͖����̒��_���[�W
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 4;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				//�h�䖳���Ȃ̂œG�̖h��͂������Ȃ�
				hpcut = attacker.atk * skillupmedium;
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�g�@��
		if (askill == ASKILL6) {
			if (skillflame == flame50) {
				//�G�P�̂ɑ�_���[�W
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 5;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				//���̍U���͂̔{�̃_���[�W��^����
				hpcut = (attacker.atk * skilluplarge) - valkyrie.def;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p1skl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�R���f�B�N�V����
		if (askill == ASKILL7) {
			if (skillflame == flame50) {
				//3�^�[���̊ԁA���g�̍U���͂����A�b�v
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 3;

				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�A�^�b�J�[�̌��̍U���͂�2���قǍU���͂��グ��
				buffup = attacker.atkmax * buffdownlittle;
				//���ʏ���
				attacker.atk += buffup;
				//�_���[�W�\�L
				String *p1buf = String::createWithFormat("���m�͍U���͂������A�b�v����", buffup);
				string _p1buf = p1buf->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1buf, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�E�H���A�[�E�H�[�N���C
		if (askill == ASKILL8) {
			if (skillflame == flame50) {
				//3�^�[���̊ԁA���g�̍U���͂��A�b�v�E�h��͏��_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 7;
				//MANA�̐��l��ς���
				p1mnal->setString(std::to_string(attacker.mana));
				//�A�^�b�J�[�̍U���͂��グ��
				//�A�^�b�J�[�̌��̍U���͂Ԃ�U���͂��グ��
				buffup = attacker.atkmax;
				//�A�^�b�J�[�̖h��͂�������
				buffdown = attacker.def * buffdownlittle;
				//���ʏ���
				attacker.atk += buffup;
				attacker.def -= buffdown;

				//�_���[�W�\�L
				String *p1buf = String::createWithFormat("���m�͍U���͂��啝�ɃA�b�v����", buffup);
				string _p1buf = p1buf->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1buf, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			//�X�e�[�^�X�ω��\�L
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);
				auto pl1buffdown = CCLabelTTF::create("���m�̖h��͂�������������", "HGRSGU.TTC", fontsizeL);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(buffdownS);				//�X�e�[�^�X�ω��\�L������
				skillendflag = true;
			}
		}
	}
	//�R�m
	if (job == SHIELD) {
		//�A�C���X�]�C��
		if (sskill == SSKILL1) {
			//�G�P�̂ɏ��_���[�W�̂Q��U��
		}
		//�J�E���^�[
		if (sskill == SSKILL2) {
			//�U�����󂯂��Ƃ��A�G���U������
		}
		//�őO��
		if (sskill == SSKILL3) {
			//�G�̍U�������g�ɏW��������
		}
		//�g����̕X��
		if (sskill == SSKILL4) {
			//�����P�̂ւ̃_���[�W�����Ɏ󂯂�
		}
		//�Q���X��
		if (sskill == SSKILL5) {
			//�����S���ւ̃_���[�W�����Ɏ󂯂�
		}
		//�ە�����Y����
		if (sskill == SSKILL6) {
			//�퓬�s�\���P�x�������g��HP�P�ŕ�������
		}
		//�X�̌��
		if (sskill == SSKILL7) {
			//5�^�[���̊ԁA���g�̖h��͂����A�b�v
		}
		//�R�m������
		if (sskill == SSKILL8) {
			//3�^�[���̊ԁA���g�̖h��͂��A�b�v�E�U���͏��_�E��
		}
	}
	//���p�t
	if (job == MAGIC) {
		//�}�W�b�N�~�T�C��
		if (mskill == MSKILL1) {
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
				plparticle3->setAutoRemoveOnFinish(true);

				//�G�t�F�N�g����
				plparticle3->resetSystem();								//�p�[�e�B�N���J�n
				plparticle3->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
				this->addChild(plparticle3, backdepth, mskill1E);		//�p�[�e�B�N����z�u

				//�v���C���[3��MANA�����炷
				magic.mana -= 20;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�{�X��HP�����炷
				hpcut = (pl3frame.matk - valkyrie.mdef);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�A�[�}�[�V���b�g
		if(mskill == MSKILL2) {
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W+���g�̖h�䏬�A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�{�X��HP�����炷
				hpcut = (pl3frame.matk - valkyrie.mdef);
				buffup = pl3frame.def / skilluplarge;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				pl3frame.def += buffup;

				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("���p�t�̖h��͂������オ����", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//�}�W�b�N�o�[�X�g
		if (mskill == MSKILL3) {
			if (gameflame == flame50) {
				//�G�P�̂ɒ��_���[�W + �G�̍U���_�E��
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�{�X��HP�����炷
				hpcut = (pl3frame.matk * skillupmedium) - valkyrie.mdef;
				//���p�t�̍��̍U���͂̂T���̍U���͂�������
				buffdown = valkyrie.atk * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;

				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", buffdown);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("�G�̍U���͂���������", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//VFD
		if (mskill == MSKILL4) {
			if (gameflame == flame50) {
				//�G�P�̂ɓ���_���[�W
				//�v���C���[3��MANA�����炷
				magic.mana -= 7;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�{�X��HP�����炷
				hpcut = (pl3frame.matk * skilluplarge) - valkyrie.mdef;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�O�����c
		if (mskill == MSKILL5 || mskill == MSKILL5 || mskill == MSKILL5) {
			if (gameflame == flame50) {
				//3�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͏��A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�����S���̃X�e�[�^�X���グ��
				//PL1�̍U���Ɩh����グ��
				pl1frame.atk = pl1frame.atk * skillupmedium;
				pl1frame.def = pl1frame.def * skillupmedium;
				//PL2��ry
				pl2frame.atk = pl2frame.atk * skillupmedium;
				pl2frame.def = pl2frame.def * skillupmedium;
				//PL3��ry
				pl3frame.atk = pl3frame.atk * skillupmedium;
				pl3frame.def = pl3frame.def * skillupmedium;
				
				//�X�e�[�^�X�A�b�v�\�L
				auto pl3buffup = CCLabelTTF::create("�����̍U���͂Ɩh��͂������オ����", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�_�̌䌕
		if (mskill == MSKILL6) {
			if (gameflame == flame50) {
				//2�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͑�A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 5;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//�����S���̃X�e�[�^�X���グ��
				//PL1�̍U���Ɩh����グ��
				pl1frame.atk = pl1frame.atk * skilluplarge;
				pl1frame.def = pl1frame.def * skilluplarge;
				//PL2��ry
				pl2frame.atk = pl2frame.atk * skilluplarge;
				pl2frame.def = pl2frame.def * skilluplarge;
				//PL3��ry
				pl3frame.atk = pl3frame.atk * skilluplarge;
				pl3frame.def = pl3frame.def * skilluplarge;

				//�X�e�[�^�X�A�b�v�\�L
				auto pl3buffup = CCLabelTTF::create("�����̍U���͂Ɩh��͂��啝�ɏオ����", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//���͋z��
		if (mskill == MSKILL7) {
			//�����P�̂�MP��10%�z�������g��MP���񕜂���
		}
		//�S�ċz
		if (mskill == MSKILL8) {
			if (gameflame == flame50) {
				//3�^�[���̊ԁA���g��MP������
				//�v���C���[3��MANA�����炷
				magic.mana -= 4;
				//MANA�̐��l��ς���
				p3mnal->setString(std::to_string(pl3frame.mana));
				//���p�t��mana���񕜂�����
				recovery = pl3frame.manamax / skilluplittle;
		
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", recovery);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
	}
	//���E��
	if (job == HEALER) {
		//���͋���
		if (hskill == HSKILL1) {
			if (gameflame == flame50) {
				//�����P�̂Ɏ��g��MP�����^����
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill2.plist");

				plparticle2->setAutoRemoveOnFinish(true);

				//�G�t�F�N�g����
				plparticle2->resetSystem();								//�p�[�e�B�N���J�n
				plparticle2->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
				this->addChild(plparticle2, backdepth, hskill1E);		//�p�[�e�B�N����z�u

				//�v���C���[�P��MANA�����炷
				healer.mana -= 3;
				//MANA�̐��l��ς���
				p2mnal->setString(std::to_string(healer.mana));
				//�{�X��HP�����炷
				valkyrie.hp -= (healer.matk - valkyrie.mdef);
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//�G�t�F�N�g������
				this->removeChildByTag(healerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//���҂̌o�T
		if (hskill == HSKILL2) {
			if (gameflame == flame50) {
				//�G�P�̂̍U���͒��_�E��
				//�v���C���[�P��MANA�����炷
				healer.mana -= 5;
				//MANA�̐��l��ς���
				p2mnal->setString(std::to_string(healer.mana));
				//�{�X�̍U���͂𒆃_�E��
				buffdown = valkyrie.atk * buffdownmedium;
				valkyrie.atk = buffdown;

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("�G�̍U���͂�������", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);
				
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//���҂̌o�T
		if (hskill == HSKILL3) {
			if (gameflame == flame50) {
				//�G�P�̖̂h��͒��_�E��
				//�v���C���[�P��MANA�����炷
				healer.mana -= 5;
				//MANA�̐��l��ς���
				p2mnal->setString(std::to_string(healer.mana));
				//�{�X�̍U���͂𒆃_�E��
				buffdown = valkyrie.def * buffdownmedium;
				valkyrie.def = buffdown;

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("�G�̖h��͂�������", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�Z�C���g���[�O
		if (hskill == HSKILL4) {
			//�����P�̂�HP������
		}
		//�����m�؁[�p�[
		if (hskill == HSKILL5) {
			//�����P�̂�HP�𒆉�
		}
		//���҂̋F��
		if (hskill == HSKILL6) {
			if (gameflame == flame50) {
				//�����S�̂�HP������
				//�v���C���[�P��MANA�����炷
				healer.mana -= 4;
				//MANA�̐��l��ς���
				p2mnal->setString(std::to_string(healer.mana));
				//�v���C���[�S����HP������
				pl1frame.hp += pl1frame.hpmax * buffdownlittle;
				healer.hp += healer.hpmax * buffdownlittle;
				pl3frame.hp += pl3frame.hpmax * buffdownlittle;
				//�v���C���[��HP�̐��l��ς���
				p1hpal->setString(std::to_string(pl1frame.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(pl3frame.hp));

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("������HP�������񕜂���", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�Z�C���g�I�[�_�[
		if (hskill == HSKILL7) {
			if (gameflame == flame50) {
				//�����S�̂�HP����
				//�v���C���[�P��MANA�����炷
				healer.mana -= 7;
				//MANA�̐��l��ς���
				p2mnal->setString(std::to_string(healer.mana));
				//�v���C���[�S����HP����
				attacker.hp += attacker.hpmax * buffdownlarge;
				healer.hp += healer.hpmax * buffdownlarge;
				magic.hp += magic.hpmax * buffdownlarge;
				//�v���C���[��HP�̐��l��ς���
				p1hpal->setString(std::to_string(attacker.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(magic.hp));

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("������HP�������񕜂���", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�_�̌[��
		if (hskill == HSKILL8) {
			//�����P�̂�퓬�s�\��Ԃ��畜��������
		}
	}
}

void BossScene::BSturn()
{
	//�_���v���C���[�����߂�
	if (bsact == PICK) {
		if (pick_rnd < fortypercent) {
			job = ATTACKER;
		}
		if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
			job = HEALER;
		}
		if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
			job = MAGIC;
		}
		bsact = DECIDE;
	}
	//�ʏ�U�����X�L���������߂�
	if (bsact == DECIDE) {
		if (decide_rnd < sixtypercent) {
			bsact = BOSSATTACK;
		}
		if (decide_rnd >= sixtypercent && decide_rnd <= rndmax ) {
			bsact = BOSSSKILL;
		}
	}
	//�ǂ̃X�L���ōU�����邩�����߂�
	if (bsact == BOSSSKILL) {
		if (skill_rnd < fiftypercent) {
			bskill = BSKILL1;
		}
		if (skill_rnd >= fiftypercent && skill_rnd < eightypercent) {
			bskill = BSKILL2;
		}
		if (skill_rnd >= eightypercent && skill_rnd < ninetypercent) {
			bskill = BSKILL3;
		}
		if (skill_rnd >= ninetypercent && skill_rnd <= rndmax) {
			bskill = BSKILL4;
		}
	}
	//�I�񂾃L�������o�͂ɕ\��
	log("job %i", job);					
	//�J�E���g���o�͂ɕ\��
	log("actcnt %i", actcnt);			
	//�v���C���[1��HP��\��
	CCString *hpstr1 = CCString::createWithFormat("����PL1HP��%d�ł�", pl1frame.hp);
	log("%s", hpstr1->getCString());	
	//�v���C���[2��HP��\��
	CCString *hpstr2 = CCString::createWithFormat("����PL2HP��%d�ł�", pl2frame.hp);
	log("%s", hpstr2->getCString());	
	//�v���C���[3��HP��\��
	CCString *hpstr3 = CCString::createWithFormat("����PL3MP��%d�ł�", pl3frame.mana);
	log("%s", hpstr3->getCString());	
	//�{�X��HP��\��
	CCString *hpstrBS = CCString::createWithFormat("���݃��@���L���[HP��%d�ł�", valkyrie.hp);
	log("%s", hpstrBS->getCString());	

	//�U�����[�h�̎�
	if (bsact == BOSSATTACK) {
		if (gameflame == flame80) {
			//�t���[����80(��)�ɂȂ����當����\������
			auto atk = CCLabelTTF::create("�u�₠���I(�ʏ�U��)�v", "HGRSGU.TTC", fontsizeL);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, backdepth, normalattackS);
			//�{�X�̉摜��h�炷����
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + moverange)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);
			//HP���ւ炷
			//���m
			if (job == ATTACKER) {
				hpcut = (valkyrie.atk - attacker.def);					//���炷HP���v�Z
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				attacker.hp -= hpcut;									//HP�����炷
				PL1p->setColor(ccc3(colormax, colordown, colordown));	//�_���[�W���󂯂�v���C���[�͐Ԃ�����
				p1hpal->setString(std::to_string(attacker.hp));			//�_���[�W���󂯂�v���C���[��HP�����炷
				dmf1->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf1, onece);							//�_���[�W�������o��
				dmf1->runAction(fadeout1);								//�_���[�W�������t�F�[�h�A�E�g������
				dmf1->runAction(fdoutmov1);								//�_���[�W��������ɓ�����
				Damage();												//�h�炷�������ȉ�����
				PL1p->runAction(pl1repeat1b);							
				HPpl1->runAction(pl1repeat2b);
				MNpl1->runAction(pl1repeat3b);
				p1hpal->runAction(pl1repeat4b);
				p1hpmaxal->runAction(pl1repeat5b);
				p1mnal->runAction(pl1repeat6b);
				p1mnmaxal->runAction(pl1repeat7b);
			}
			//���E��
			else if(job == HEALER){
				hpcut = (valkyrie.atk - healer.def);
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				healer.hp -= hpcut;
				PL2p->setColor(ccc3(colormax, colordown, colordown));
				p2hpal->setString(std::to_string(healer.hp));
				dmf2->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf2, onece);							//�_���[�W�������o��
				dmf2->runAction(fadeout2);								//�_���[�W�������t�F�[�h�A�E�g������
				dmf2->runAction(fdoutmov2);								//�_���[�W��������ɓ�����
				Damage();												//�h�炷�������ȉ�����
				PL2p->runAction(pl2repeat1b);
				HPpl2->runAction(pl2repeat2b);
				MNpl2->runAction(pl2repeat3b);
				p2hpal->runAction(pl2repeat4b);
				p2hpmaxal->runAction(pl2repeat5b);
				p2mnal->runAction(pl2repeat6b);
				p2mnmaxal->runAction(pl2repeat7b);
			}
			//���p�t
			else if (job == MAGIC) {
				hpcut = (valkyrie.atk - magic.def);
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				magic.hp -= hpcut;
				PL3p->setColor(ccc3(colormax, colordown, colordown));
				p3hpal->setString(std::to_string(magic.hp));
				dmf3->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf3, onece);							//�_���[�W�������o��
				dmf3->runAction(fadeout3);								//�_���[�W�������t�F�[�h�A�E�g������
				dmf3->runAction(fdoutmov3);								//�_���[�W��������ɓ�����
				Damage();												//�h�炷�������ȉ�����
				PL3p->runAction(pl3repeat1b);
				HPpl3->runAction(pl3repeat2b);
				MNpl3->runAction(pl3repeat3b);
				p3hpal->runAction(pl3repeat4b);
				p3hpmaxal->runAction(pl3repeat5b);
				p3mnal->runAction(pl3repeat6b);
				p3mnmaxal->runAction(pl3repeat7b);
			}
			//�N����HP���[���ɂȂ�����
			if ((pl1frame.hp <= 0) && (pl2frame.hp <= 0) && (pl3frame.hp <= 0)) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0f, pScene);	// 1�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}
		}
		//�L�����摜�̐F��߂�
		if (gameflame == flame100) {
			PL1p->setColor(ccc3(colormax, colormax, colormax));
			PL2p->setColor(ccc3(colormax, colormax, colormax));
			PL3p->setColor(ccc3(colormax, colormax, colormax));
		}
		//���ʏ���
		//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
		if (gameflame == flame230) {
			if (job == ATTACKER) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�A�^�b�J�[��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p1bsalabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p1bsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1bsalabel, backdepth, damageS);
			}
			else if (job == HEALER) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�q�[���[��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, damageS);
			}
			else if (job == MAGIC) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�}�W�b�N��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, damageS);
			}
		}
	}
	//���@���L���[�X�L��
	if (bsact == BOSSSKILL) {
		//��̑���
		if (bskill == BSKILL1) {
			//�t���[����80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gameflame == flame80) {
				auto Gskill1 = CCLabelTTF::create("�u���炦�c�I�v", "JiyunoTsubasa.ttf", fontsizeL);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, backdepth, bossskill1S);
			}
			//�h�炷����
			if (gameflame == flame210) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + 30)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
					NULL
				);
				//�h�炷
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// ��ʃT�C�Y�擾
				Size winSize = Director::getInstance()->getVisibleSize();

				//�w�i��h�炷
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f + 30)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f)),
					NULL
				);
				//����h�炷��
				auto backrepeat = Repeat::create(backmove, continuity2);
				//�h�炷
				back->runAction(backrepeat);			

				//�h��鏈��
				Damage();												//�h�炷�������ȉ�����
				//PL1�_���[�W���󂯂����ɗh��鏈��
				PL1p->runAction(pl1repeat1a);
				HPpl1->runAction(pl1repeat2a);
				MNpl1->runAction(pl1repeat3a);
				p1hpal->runAction(pl1repeat4a);
				p1hpmaxal->runAction(pl1repeat5a);
				p1mnal->runAction(pl1repeat6a);
				p1mnmaxal->runAction(pl1repeat7a);
				//PL2�_���[�W���󂯂����ɗh��鏈��
				PL2p->runAction(pl2repeat1a);
				HPpl2->runAction(pl2repeat2a);
				MNpl2->runAction(pl2repeat3a);
				p2hpal->runAction(pl2repeat4a);
				p2hpmaxal->runAction(pl2repeat5a);
				p2mnal->runAction(pl2repeat6a);
				p2mnmaxal->runAction(pl2repeat7a);
				//PL3�_���[�W���󂯂����ɗh��鏈��
				PL3p->runAction(pl3repeat1a);
				HPpl3->runAction(pl3repeat2a);
				MNpl3->runAction(pl3repeat3a);
				p3hpal->runAction(pl3repeat4a);
				p3hpmaxal->runAction(pl3repeat5a);
				p3mnal->runAction(pl3repeat6a);
				p3mnmaxal->runAction(pl3repeat7a);
				//�v���C���[�S����HP�����炷
				//�󂯂��_���[�W���Q�[�W��ɕ\��
				//���m
				hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				attacker.hp -= hpcut;									//HP�����炷
				dmf1->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf1, onece);							//�_���[�W�������o��
				dmf1->runAction(fadeout1);								//�t�F�[�h�A�E�g����
				dmf1->runAction(fdoutmov1);								//��ɏオ���Ă�������
				//���E��
				hpcut = (valkyrie.atk * skillupmedium) - healer.def;	//���炷�_���[�W���v�Z
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				healer.hp -= hpcut;									//HP�����炷
				dmf2->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf2, onece);							//�_���[�W�������o��
				dmf2->runAction(fadeout2);								//�_���[�W�������t�F�[�h�A�E�g������
				dmf2->runAction(fdoutmov2);								//�_���[�W��������ɓ�����
				//���p�t
				hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//���炷�_���[�W���v�Z
				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				magic.hp -= hpcut;									//HP�����炷
				dmf3->setString(std::to_string(hpcut));					//�_���[�W��ω�������
				this->addChild(dmf3, onece);							//�_���[�W�������o��
				dmf3->runAction(fadeout3);								//�_���[�W�������t�F�[�h�A�E�g������
				dmf3->runAction(fdoutmov3);								//�_���[�W��������ɓ�����
				//HP�̐��l��ς���
				p1hpal->setString(std::to_string(attacker.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(magic.hp));
				//�g�ɐ��߂Ă��̃L������
				PL1p->setColor(ccc3(colormax, colordown, colordown));
				PL2p->setColor(ccc3(colormax, colordown, colordown));
				PL3p->setColor(ccc3(colormax, colordown, colordown));
				//HP���[���ɂȂ�����
				if ((attacker.hp <= 0)&&(healer.hp <= 0)&&(magic.hp <= 0)) {
					// �J�ڍ�̉�ʂ�ݽ�ݽ
					Scene *pScene = GameClear::createScene();

					// 0.6�b�����Ď���ʂɑJ��
					// (����,�J�ڐ�,�F(�I�v�V����))
					TransitionFade *transition = TransitionFade::create(1.0, pScene);

					// �J�ڎ��s �A�j���[�V����
					Director::getInstance()->replaceScene(transition);
				}
			}
			//�_���[�W����
			//�t���[����230(��)�ɂȂ�ƃ_���[�W�\�L
			if (gameflame == flame230) {
				auto Gskill1dec = CCLabelTTF::create("�S���Ƀ_���[�W��^����", "HGRSGU.TTC", fontsizeL);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, backdepth, bossskill1damageS);

				//�L�����̐F��߂�
				PL1p->setColor(ccc3(colormax, colormax, colormax));
				PL2p->setColor(ccc3(colormax, colormax, colormax));
				PL3p->setColor(ccc3(colormax, colormax, colormax));
			}
		}
		//��̑���
		if (bskill == BSKILL2) {
			//�t���[����80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gameflame == flame80) {
				auto Gskill2 = CCLabelTTF::create("�u�₠�����I�v", "HGRSGU.TTC", fontsizeL);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, backdepth, bossskill2S);

				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//�_���[�W���v�Z
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;									//HP���ւ炷
					PL1p->setColor(ccc3(colormax, colordown, colordown));	//�󂯂���Ԃ�����
					dmf1->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf1, onece);							//�_���[�W�������o��
					dmf1->runAction(fadeout1);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf1->runAction(fdoutmov1);								//�_���[�W��������ɓ�����
					p1hpal->setString(std::to_string(attacker.hp));			//���l��ς��遫�ȉ�����
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - healer.def);
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					healer.hp -= hpcut;
					PL2p->setColor(ccc3(colormax, colordown, colordown));
					dmf2->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf2, onece);							//�_���[�W�������o��
					dmf2->runAction(fadeout2);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf2->runAction(fdoutmov2);								//�_���[�W��������ɓ�����
					p2hpal->setString(std::to_string(healer.hp));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - magic.def);
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					magic.hp -= hpcut;
					PL3p->setColor(ccc3(colormax, colordown, colordown));
					dmf3->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf3, onece);							//�_���[�W�������o��
					dmf3->runAction(fadeout3);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf3->runAction(fdoutmov3);								//�_���[�W��������ɓ�����
					p3hpal->setString(std::to_string(magic.hp));
				}

				//�G�t�F�N�g
				//�G�t�F�N�g�̕\��
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				particle->resetSystem();									//�G�t�F�N�g�J�n
				particle->setPosition(ccp(rightSize.width / 2,
										  rightSize.height / 3));			//�G�t�F�N�g��\������ꏊ�̐ݒ�
				this->addChild(particle, backdepth, bossskill1E);			//�G�t�F�N�g��z�u
			}
			//���ڂ̍U��
			if (gameflame == flame150) {
				//���ڂ�HP�����炷
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//�_���[�W�v�Z
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;									//HP�����炷
					PL1p->setColor(ccc3(colormax, colordown, colordown));	//�_���[�W���������(�v���C���[�̉摜��Ԃ�����)
					dmf1->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf1, onece);							//�_���[�W�������o��
					dmf1->runAction(fadeout1);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf1->runAction(fdoutmov1);								//�_���[�W��������ɓ�����
					p1hpal->setString(std::to_string(attacker.hp));			//HP���l�����炷
					Damage();												//�h�炷�������ȉ�����
					PL1p->runAction(pl1repeat1a);
					HPpl1->runAction(pl1repeat2a);
					MNpl1->runAction(pl1repeat3a);
					p1hpal->runAction(pl1repeat4a);
					p1hpmaxal->runAction(pl1repeat5a);
					p1mnal->runAction(pl1repeat6a);
					p1mnmaxal->runAction(pl1repeat7a);
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - healer.def);
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					healer.hp -= hpcut;
					PL2p->setColor(ccc3(colormax, colordown, colordown));
					p2hpal->setString(std::to_string(healer.hp));
					dmf2->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf2, onece);							//�_���[�W�������o��
					dmf2->runAction(fadeout2);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf2->runAction(fdoutmov2);								//�_���[�W��������ɓ�����
					Damage();												//�h�炷�������ȉ�����
					PL2p->runAction(pl2repeat1a);
					HPpl2->runAction(pl2repeat2a);
					MNpl2->runAction(pl2repeat3a);
					p2hpal->runAction(pl2repeat4a);
					p2hpmaxal->runAction(pl2repeat5a);
					p2mnal->runAction(pl2repeat6a);
					p2mnmaxal->runAction(pl2repeat7a);
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - magic.def);
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					magic.hp -= hpcut;
					PL3p->setColor(ccc3(colormax, colordown, colordown));
					p3hpal->setString(std::to_string(magic.hp));
					dmf3->setString(std::to_string(hpcut));					//�_���[�W��ω�������
					this->addChild(dmf3, onece);							//�_���[�W�������o��
					dmf3->runAction(fadeout3);								//�_���[�W�������t�F�[�h�A�E�g������
					dmf3->runAction(fdoutmov3);								//�_���[�W��������ɓ�����
					Damage();												//�h�炷�������ȉ�����
					PL3p->runAction(pl3repeat1a);
					HPpl3->runAction(pl3repeat2a);
					MNpl3->runAction(pl3repeat3a);
					p3hpal->runAction(pl3repeat4a);
					p3hpmaxal->runAction(pl3repeat5a);
					p3mnal->runAction(pl3repeat6a);
					p3mnmaxal->runAction(pl3repeat7a);
				}
				//HP���[���ɂȂ������ʑJ��
				if ((attacker.hp <= 0) && (healer.hp <= 0) && (magic.hp <= 0)) {
					Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
					TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
					Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
				}
				//�L�����̉摜�̐F��߂�
				PL1p->setColor(ccc3(colormax, colormax, colormax));
				PL2p->setColor(ccc3(colormax, colormax, colormax));
				PL3p->setColor(ccc3(colormax, colormax, colormax));
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				auto Gskill2dec = CCLabelTTF::create("�Q��_���[�W�Ƀ_���[�W", "HGRSGU.TTC", fontsizeL);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, backdepth, bossskill2damageS);
			}
		}
		//�Z��̐w
		if (bskill == BSKILL3) {
			if (gameflame == flame80) {
				auto Gskill3 = CCLabelTTF::create("�u����ł����@���L���[�Ȃ̂Łv", "HGRSGU.TTC", fontsizeL);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, backdepth, bossskill3S);

				//���@���L���[�̖h��͂𑝂₷
				valkyrie.def += 2;					
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				auto Gskill3dec = CCLabelTTF::create("���@���L���[�̖h��͂��啝�ɏオ����", "HGRSGU.TTC", fontsizeM);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, backdepth, bossskill3damageS);
			}
		}
		//�G�X�e
		if (bskill == BSKILL4) {
			if (gameflame == flame80) {
				auto Gskill4 = CCLabelTTF::create("�u�G�X�e�c����c�v", "HGRSGU.TTC", fontsizeL);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, backdepth, bossskill4S);

				//���@���L���[��HP�𑝂₷
				bsskillrecovery = valkyrie.hp / tenpercent;
				valkyrie.hp += bsskillrecovery;					
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				//�񕜕\�L
				String *Gskill4dec = String::createWithFormat("���@���L���[��%i�AHP���񕜂���", bsskillrecovery);
				string _Gskill4dec = Gskill4dec->getCString();
				auto bss4alabel = Label::createWithSystemFont(_Gskill4dec, "HGRSGU.TTC", fontsizeL);
				bss4alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(bss4alabel, backdepth, bossskill4damageS);
			}
		}
	}
}

//�摜��h�炷���߂̏���
void BossScene::Damage()
{
//���m
	//pl1frame.choisjob�����m�̏ꍇ
	if (pl1frame.choicejob == ATTACKER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//�h�炷�������m,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//�h�炷�������m,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//�h�炷�������m,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//�h�炷�������m,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//�h�炷�������m,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//�h�炷�������m,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������m,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//�h�炷�������m,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//�h�炷�������m,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//�h�炷�������m,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//�h�炷�������m,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//�h�炷�������m,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//�h�炷�������m,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
	//pl2frame.choisjob�����m�̏ꍇ
	if (pl2frame.choicejob == ATTACKER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//�h�炷�������m,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//�h�炷�������m,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//�h�炷�������m,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//�h�炷�������m,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//�h�炷�������m,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//�h�炷�������m,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������m,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//�h�炷�������m,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//�h�炷�������m,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//�h�炷�������m,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//�h�炷�������m,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//�h�炷�������m,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//�h�炷�������m,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
	//pl3frame.choisjob�����m�̏ꍇ
	if (pl3frame.choicejob == ATTACKER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//�h�炷�������m,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//�h�炷�������m,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//�h�炷�������m,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//�h�炷�������m,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//�h�炷�������m,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//�h�炷�������m,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������m,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//�h�炷�������m,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//�h�炷�������m,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//�h�炷�������m,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//�h�炷�������m,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//�h�炷�������m,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//�h�炷�������m,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
//���E��
	//pl1frame.choisjob�����E�҂̏ꍇ
	if (pl1frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//�h�炷�������E��,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//�h�炷�������E��,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//�h�炷�������E��,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//�h�炷�������E��,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//�h�炷�������E��,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//�h�炷�������E��,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������E��,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//�h�炷�������E��,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//�h�炷�������E��,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//�h�炷�������E��,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//�h�炷�������E��,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//�h�炷�������E��,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//�h�炷�������E��,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
	//pl2frame.choisjob�����E�҂̏ꍇ
	if (pl2frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//�h�炷�������E��,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//�h�炷�������E��,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//�h�炷�������E��,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//�h�炷�������E��,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//�h�炷�������E��,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//�h�炷�������E��,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������E��,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//�h�炷�������E��,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//�h�炷�������E��,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//�h�炷�������E��,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//�h�炷�������E��,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//�h�炷�������E��,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//�h�炷�������E��,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
	//pl3frame.choisjob�����E�҂̏ꍇ
	if (pl3frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//�h�炷�������E��,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//�h�炷�������E��,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//�h�炷�������E��,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//�h�炷�������E��,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//�h�炷�������E��,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//�h�炷�������E��,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������E��,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//�h�炷�������E��,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//�h�炷�������E��,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//�h�炷�������E��,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//�h�炷�������E��,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//�h�炷�������E��,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//�h�炷�������E��,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
//���p�t
	//pl1frame.choisjob�����p�t�̏ꍇ
	if (pl1frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//�h�炷�������p�t,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//�h�炷�������p�t,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//�h�炷�������p�t,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//�h�炷�������p�t,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//�h�炷�������p�t,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//�h�炷�������p�t,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������p�t,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//�h�炷�������p�t,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//�h�炷�������p�t,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//�h�炷�������p�t,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//�h�炷�������p�t,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//�h�炷�������p�t,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//�h�炷�������p�t,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
	//pl2frame.choisjob�����p�t�̏ꍇ
	if (pl2frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//�h�炷�������p�t,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//�h�炷�������p�t,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//�h�炷�������p�t,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//�h�炷�������p�t,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//�h�炷�������p�t,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//�h�炷�������p�t,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������p�t,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//�h�炷�������p�t,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//�h�炷�������p�t,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//�h�炷�������p�t,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//�h�炷�������p�t,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//�h�炷�������p�t,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//�h�炷�������p�t,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
	//pl3frame.choisjob�����p�t�̏ꍇ
	if (pl3frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//�h�炷�������p�t,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//�h�炷�������p�t,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//�h�炷�������p�t,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//�h�炷�������p�t,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//�h�炷�������p�t,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//�h�炷�������p�t,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������p�t,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//�h�炷�������p�t,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//�h�炷�������p�t,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//�h�炷�������p�t,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//�h�炷�������p�t,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//�h�炷�������p�t,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//�h�炷�������p�t,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
//�{�X
	auto bossmove = CCSequence::create(
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
		NULL
	);
	bossrepeat = Repeat::create(bossmove, continuity1);
}

// �����o�Ă���摜
void BossScene::BossBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	//rightSize = Director::getInstance()->getVisibleSize();
	rightSize = CCDirector::sharedDirector()->getWinSize();
	//�摜�̃|�C���g���Đݒ�
	CCPoint ancharpoint = ccp(0.0f, 0.0f);		//����
	CCPoint anancharpoint = ccp(1.0f, 0.0f);	//�E��
//�w�i
	back = CCSprite::create("BackImage/ST_Boss.png");							//�w�i�̉摜�w��
	back->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));			// �\�����W�w��
	this->addChild(back, backdepth);											//�ǉ�
//�e���b�v
	auto Telop = CCSprite::create("UI/UI_Terop.png");
	Telop->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
	Telop->setScaleX(1.5f);
	this->addChild(Telop, backdepth);
//�{�X
	// �{�X�̕\��
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");							// �摜�w��
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));		// �\�����W�w��
	this->addChild(Boss, backdepth);											// �ǉ�
	//BOSSHP�o�[
	HPboss = CCSprite::create("UI/Status/UI_Status_EMLife.png");
	HPboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPboss->setAnchorPoint(ancharpoint);
	HPbar = HPboss->getTextureRect().origin;
	bosshpgaugewidth = HPboss->getContentSize().width;
	this->addChild(HPboss, middledepth);
	//������̍����o�[
	auto HPLboss = CCSprite::create("UI/Status/UI_Status_EMLost.png");
	HPLboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPLboss->setAnchorPoint(ancharpoint);
	bosshpgaugewidth = HPLboss->getContentSize().width;
	this->addChild(HPLboss, backdepth);
//���m�̃X�e�[�^�X�o�[
	//�X�e�[�^�X�̃v���[�g(��Ԍ��̂��)
	PL1p= CCSprite::create("UI/Status/UI_Status_Attacker.png");
	if (pl1frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL1p->setScaleX(0.6f);
	PL1p->setScaleY(0.8f);
	this->addChild(PL1p, backdepth);
	//HP�o�[
	HPpl1 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl1->setAnchorPoint(ancharpoint);
	HPpl1->setScaleX(0.6f);
	HPpl1->setScaleY(0.8f);
	HPbar = HPpl1->getTextureRect().origin;
	pl1hpgaugewidth = HPpl1->getContentSize().width;
	this->addChild(HPpl1, prevdepth);
	//MANA�o�[
	MNpl1 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl1->setAnchorPoint(ancharpoint);
	MNpl1->setScaleX(0.6f);
	MNpl1->setScaleY(0.8f);
	MNbar = MNpl1->getTextureRect().origin;
	pl1mngaugewidth = MNpl1->getContentSize().width;
	this->addChild(MNpl1, prevdepth);
	//PL1HP�\�L
	//���l���ς�镔��
	p1hpal = LabelTTF::create(std::to_string(attacker.hp), "HGRSGU.TTC", fontsizeM);
	p1hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	if (pl1frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p1hpal->setColor(ccc3(150,255,255));			//���F
	p1hpal->setAnchorPoint(anancharpoint);
	this->addChild(p1hpal, prevdepth);
	//HP�̍ő�l
	p1hpmaxal = LabelTTF::create("/" + std::to_string(attacker.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p1hpmaxal, prevdepth);
	//PL1MANA�\�L
	//���l���ς�镔��
	p1mnal = LabelTTF::create(std::to_string(attacker.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p1mnal->setColor(ccc3(192, 136, 255));			//��
	p1mnal->setAnchorPoint(anancharpoint);
	this->addChild(p1mnal, prevdepth);
	//MP�̍ő�l
	p1mnmaxal = LabelTTF::create("/" + std::to_string(attacker.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p1mnmaxal, prevdepth);
//���E�҂̃X�e�[�^�X�o�[
	////�X�e�[�^�X�̃v���[�g(��Ԍ��̂��)
	PL2p = CCSprite::create("UI/Status/UI_Status_Healer.png");					//�摜�w��
	if (pl1frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL2p->setScaleX(0.6f);														//�傫���ύX
	PL2p->setScaleY(0.8f);
	this->addChild(PL2p, backdepth);											//�ǉ�
	//HP�o�[
	HPpl2 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl2->setAnchorPoint(ancharpoint);
	HPpl2->setScaleX(0.6f);
	HPpl2->setScaleY(0.8f);
	HPbar = HPpl2->getTextureRect().origin;
	pl2hpgaugewidth = HPpl2->getContentSize().width;
	this->addChild(HPpl2, prevdepth);
	//MANA�o�[
	MNpl2 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl2->setAnchorPoint(ancharpoint);
	MNpl2->setScaleX(0.6f);
	MNpl2->setScaleY(0.8f);
	MNbar = MNpl2->getTextureRect().origin;
	pl2mngaugewidth = MNpl2->getContentSize().width;
	this->addChild(MNpl2, prevdepth);
	//PL2HP�\�L
	//���l���ς�镔��
	p2hpal = LabelTTF::create(std::to_string(healer.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p2hpal->setColor(ccc3(150, 255, 255));
	p2hpal->setAnchorPoint(anancharpoint);
	this->addChild(p2hpal, prevdepth);
	//HP�̍ő�l
	p2hpmaxal = LabelTTF::create("/" + std::to_string(healer.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p2hpmaxal, prevdepth);
	//PL2MANA�\�L
	//���l���ς�镔��
	p2mnal = LabelTTF::create(std::to_string(healer.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p2mnal->setColor(ccc3(192, 136, 255));
	p2mnal->setAnchorPoint(anancharpoint);
	this->addChild(p2mnal, prevdepth);
	//MP�̍ő�l
	p2mnmaxal = LabelTTF::create("/" + std::to_string(healer.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p2mnmaxal, prevdepth);
//���p�t�̃X�e�[�^�X�o�[
	//�X�e�[�^�X�v���[�g(��Ԍ��̂��)
	PL3p = CCSprite::create("UI/Status/UI_Status_Magic.png");					//�摜�w��
	if (pl1frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL3p->setScaleX(0.6f);														//�傫���ύX
	PL3p->setScaleY(0.8f);
	this->addChild(PL3p, backdepth);											//�ǉ�
	//HP�o�[																	//HP�o�[
	HPpl3 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl3->setAnchorPoint(ancharpoint);
	HPpl3->setScaleX(0.6f);
	HPpl3->setScaleY(0.8f);
	HPbar = HPpl3->getTextureRect().origin;
	pl3hpgaugewidth = HPpl3->getContentSize().width;
	this->addChild(HPpl3, prevdepth);
	//MANA�o�[
	MNpl3 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl3->setAnchorPoint(ancharpoint);
	MNpl3->setScaleX(0.6f);
	MNpl3->setScaleY(0.8f);
	MNbar = MNpl3->getTextureRect().origin;
	pl3mngaugewidth = MNpl3->getContentSize().width;
	this->addChild(MNpl3, prevdepth);
	//PL3HP�\�L
	//���l���ς�镔��
	p3hpal = LabelTTF::create(std::to_string(magic.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p3hpal->setColor(ccc3(150, 255, 255));
	p3hpal->setAnchorPoint(anancharpoint);
	this->addChild(p3hpal, prevdepth);
	//HP�̍ő�l
	p3hpmaxal = LabelTTF::create("/" + std::to_string(magic.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p3hpmaxal, prevdepth);
	//PL3MANA�\�L
	//���l���ς�镔��
	p3mnal = LabelTTF::create(std::to_string(magic.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p3mnal->setColor(ccc3(192, 136, 255));
	p3mnal->setAnchorPoint(anancharpoint);
	this->addChild(p3mnal, prevdepth);
	//MP�̍ő�l
	p3mnmaxal = LabelTTF::create("/" + std::to_string(magic.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p3mnmaxal, prevdepth);
}

// ��ʑJ��
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = GameClear::createScene();							
	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6f, pScene);
	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

//�{�^�����������Ƃ�
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

//�{�^���������ė������Ƃ�
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	if (battle == CHOICE) {
		AttackButton1->setVisible(true);
		SkillButton1->setVisible(true);
	}
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}