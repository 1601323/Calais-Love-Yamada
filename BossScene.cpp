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
	pl1frame.hp = 9;		//HP
	pl1frame.mana = 6;		//MP
	pl1frame.atk = 7;		//ATK
	pl1frame.def = 3;		//DEF
	pl1frame.matk = 4;		//MATK
	pl1frame.mdef = 5;		//MDEF
	//�L�����g2�i�q�[���[�ȏꍇ�j
	pl2frame.hp = 8;		//HP
	pl2frame.mana = 8;		//MP
	pl2frame.atk = 5;		//ATK
	pl2frame.def = 5;		//DEF
	pl2frame.matk = 5;		//MATK
	pl2frame.mdef = 5;		//MDEF
	//�L�����g3�i�}�W�b�N�̏ꍇ�j
	pl3frame.hp = 7;		//HP
	pl3frame.mana = 8;		//MP
	pl3frame.atk = 4;		//ATK
	pl3frame.def = 5;		//DEF
	pl3frame.matk = 7;		//MATK
	pl3frame.mdef = 5;		//MDEF
	//���@���L���[
	valkyrie.hp = 25;		//HP
	valkyrie.mana = 9;		//MP
	valkyrie.atk = 5;		//ATK
	valkyrie.def = 5;		//DEF
	valkyrie.matk = 4;		//MATK
	valkyrie.mdef = 5;		//MDEF

	//�����ݒ�
	continuity = 6;			//�h�炷��
	ten = 10;				//�ړ�������l
	hpcut = 3;				//���炷HP
	depth = 1;				//���s��
	rnd = random();			//�ő�l�܂ł̗������擾
	rndmin = 0;				//�����_���̍ŏ��l
	rndmax = 100;			//�����_���̍ő�l
	movecnt = 0.05f;		//1�񓮂�������
	actcnt = 0;				//�{�X�̓�����
	gametime = 0;			//����
	timemax = 350;			//���Ԃ̍ő�l
	choicetime = 0;			//�A���I���ł��Ȃ��悤�ɂ��邽�߂̂��
	fontsize = 50;			//�����̑傫��
	Shader = 0;				//���邳
	Color = 150;			//�Â�
	Colormax = 255;			//�J���[�̍ő�l
	HPGaugecnt = 0;			//HP�Q�[�W�̃J�E���g
	gaugecnt = 100;
	turn = PLAYER;			//�N�̃^�[���H
	battle = START;			//�o�g��
	choices = CHAR1;		//�R�}���h��I�ԍŏ��̃L����
	bsact = PICK;			//�{�X�̓���
	job = NON;				//�L�����I��
	state = false;			//�v���C���[�̏��
	flag = false;			//�{�X�̏��

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
	this->addChild(menu, depth);

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
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//�擾
	auto Atouchget = EventListenerTouchOneByOne::create();	//�A�^�b�N�{�^��
	auto Stouchget = EventListenerTouchOneByOne::create();	//�X�L���{�^��

	if (turn == PLAYER) {
		switch (battle){
			battle = START;
		case BossScene::START: {
			state = false;

			//�U���R�}���h�{�^��
			AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	//�摜�w��
			AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
			this->addChild(AttackButton1, 2, 41);					

			//�U���R�}���h�{�^��(�����Ă���Ƃ�)
			AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	//�摜�w��
			AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
			this->addChild(AttackButton2, depth, 42);

			//�X�L���R�}���h�{�^��
			SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//�摜�w��
			SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
			this->addChild(SkillButton1, 2, 43);									//�ǉ�

			//�X�L���R�}���h�{�^��(�����Ă���Ƃ�)
			SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//�摜�w��
			SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
			this->addChild(SkillButton2, depth, 44);								//�ǉ�

			//PLTURN(�E��)															
			plturn = CCSprite::create("Description/PL.png");						//�z�u����
			plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//�ꏊ�z�u
			this->addChild(plturn, depth, 1);										

			battle = WAIT;
			break;
		}
		case BossScene::WAIT: {
			battle = CHOICE;
			break;
		}
		case BossScene::CHOICE: {
			choicetime++;									//�{�^�����A���ŉ�����Ȃ��悤�ɂ��邽�߂̏���
			//�^�b�`����
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;
			//�A�^�b�N�{�^��
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();			//�^�b�`�����|�C���g�B
				Rect rectButton1 = Abutton->getBoundingBox();//�{�^���摜�͈̔́B
				switch (choices) {
				//�L����1
				case BossScene::CHAR1: {
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point1)) {	
							AttackButton1->setVisible(false);	//��̃{�^��������
							pl1 = PL1ATTACK;					//�A�^�b�N�ɂ���
							choicetime = 0;
							choices = CHAR2;					//���̃L������
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
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point1)) {	
							AttackButton1->setVisible(false);	//��̃{�^��������
							pl2 = PL2ATTACK;					//�A�^�b�N�ɂ���
							choicetime = 0;
							choices = CHAR3;					//���̃L������
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
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ
						if (rectButton1.containsPoint(point1)) {
							pick_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
							act_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
							decide_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓���)
							skill_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�X�L��)
							state = true;							//�������Ԃɂ���
							Abutton->removeFromParentAndCleanup(true);//�R�}���h�{�^��(attack)������
							this->removeChildByTag(42);
							this->removeChildByTag(43);
							this->removeChildByTag(44);
							pl3 = PL3ATTACK;						//�A�^�b�N�ɂ���
							choicetime = 0;
							battle = ACTION;
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
				Vec2 point2 = touch->getLocation();					//�^�b�`�����|�C���g�B
				Rect rectButton1 = Sbutton->getBoundingBox();		//�{�^���摜�͈̔́B

				switch (choices) {
				//�L����1
				case BossScene::CHAR1: {
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {	
							SkillButton1->setVisible(false);//��̃{�^��������
							pl1 = PL1SKILL;					//�X�L���ɂ���
							choicetime = 0;
							choices = CHAR2;				//���̃L������
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
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {	
							SkillButton1->setVisible(false);//��̃{�^��������
							pl2 = PL2SKILL;					//�X�L���ɂ���
							choicetime = 0;
							choices = CHAR3;				//���̃L������
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
					if (choicetime > 20) {
						//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
						if (rectButton1.containsPoint(point2)) {	
							pick_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
							act_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
							decide_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓���)
							skill_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�X�L��)
							state = true;							//�������Ԃɂ���
							Sbutton->removeFromParentAndCleanup(true);//�R�}���h�{�^��(attack)������
							this->removeChildByTag(41);
							this->removeChildByTag(42);
							this->removeChildByTag(44);
							pl3 = PL3SKILL;						//�X�L���ɂ���
							choicetime = 0;
							battle = ACTION;
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

			//�I���L�����𖾊m�ɂ���(�I������ĂȂ��L�����͏����Â�����)
			if (choices == CHAR1) {
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Color, Color, Color));
				PL3p->setColor(ccc3(Color, Color, Color));
			}
			else if (choices == CHAR2) {
				PL1p->setColor(ccc3(Color, Color, Color));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Color, Color, Color));
			}
			else if (choices == CHAR3) {
				PL1p->setColor(ccc3(Color, Color, Color));
				PL2p->setColor(ccc3(Color, Color, Color));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
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
			//�v���C���[�����̉摜�̐F��߂�
			PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			if (state == true) {
				gametime++;								//�J�E���g�J�n
				PLturn();								//��ȏ���
			}
			if (gametime > 250) {
				//����������
				this->removeChildByTag(1);				//PLTURN
				this->removeChildByTag(17);				//���邮�邵�Ă���
				this->removeChildByTag(23);				//�_���[�W�\�L������

				//BSTURN����
				emturn = CCSprite::create("Description/BS.png");							// �z�u����
				emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// �z�u�ꏊ
				this->addChild(emturn, depth, 2);											// �ǉ�

				gametime = 0;							//�J�E���g��0��
				bsact = PICK;							//�{�X�̓�����������
				turn = BOSS;							//�{�X�̃^�[����
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
		flag = false;									//�t���O��false��
		gaugecnt--;
		gametime++;										//�J�E���g�J�n
		BSturn();										//��ȏ���
		
		if (gametime == 170) {
			//����������
			this->removeChildByTag(5);					//�ʏ�U��
			this->removeChildByTag(54);					//�X�L��1			
			this->removeChildByTag(56);					//�X�L��2
			this->removeChildByTag(58);					//�X�L��3
			this->removeChildByTag(60);					//�X�L��4
		}

		if (gametime > timemax) {
			if (act_rnd < 20) {
				//����������
				this->removeChildByTag(2);				//BSTURN
				this->removeChildByTag(6);				//���ʕ\�L(�ʏ�U��)
				this->removeChildByTag(13);				//�p�[�e�B�N��
				this->removeChildByTag(55);				//���ʕ\�L(�X�L��1)
				this->removeChildByTag(57);				//���ʕ\�L(�X�L��2)
				this->removeChildByTag(59);				//���ʕ\�L(�X�L��3)
				this->removeChildByTag(61);				//���ʕ\�L(�X�L��4)

				gametime = 0;							//���Ԃ�0��
				actcnt = 0;								//�J�E���g��0��
				job = NON;								//�I�񂾃L�����������̏�Ԃɖ߂�
				battle = START;							//�o�g���������̏�Ԃɖ߂�
				choices = CHAR1;						//�I���L�������ŏ���
				turn = PLAYER;							//�v���C���[�̃^�[����
			}
			if (act_rnd >= 20 && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//����������
					this->removeChildByTag(6);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(13);			//�p�[�e�B�N��
					this->removeChildByTag(55);			//���ʕ\�L(�X�L��1)
					this->removeChildByTag(57);			//���ʕ\�L(�X�L��2)
					this->removeChildByTag(59);			//���ʕ\�L(�X�L��3)
					this->removeChildByTag(61);			//���ʕ\�L(�X�L��4)

					pick_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
					act_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓�����)
					decide_rnd = random(rndmin, rndmax);//�w�肵���͈͓��̗������擾(�{�X�̓���)
					skill_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�X�L��)

					actcnt += 1;						//�U���J�E���g�𑝂₵��2��ȏ�U�����Ȃ��悤�ɂ���
					gametime = 0;						//���Ԃ�0��
					bsact = PICK;						//�{�X�̓����������ɖ߂�
					turn = BOSS;						//�������{�X�̍s����
				}
				else {
					//����������
					this->removeChildByTag(2);			//BSTURN
					this->removeChildByTag(6);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(13);			//�p�[�e�B�N��
					this->removeChildByTag(55);			//���ʕ\�L(�X�L��1)
					this->removeChildByTag(57);			//���ʕ\�L(�X�L��2)
					this->removeChildByTag(59);			//���ʕ\�L(�X�L��3)
					this->removeChildByTag(61);			//���ʕ\�L(�X�L��4)

					gametime = 0;						//���Ԃ�0��
					actcnt = 0;							//�J�E���g��0��
					job = NON;							//�I�񂾃L�����������̏�Ԃɖ߂�
					battle = START;						//�o�g���������̏�Ԃɖ߂�
					choices = CHAR1;					//�I���L�������ŏ���
					turn = PLAYER;						//�v���C���[�̃^�[����
				}
			}
		}

		HPpl1->setTextureRect(Rect(HPbar.x, HPbar.y,
			HPGaugeWidth * pl1frame.hp / 9,
			HPpl1->getContentSize().height));
	}
	CCLOG("%i�b", gametime);
 }

void BossScene::PLturn()
{
	//�v���C���[1�̍s��
	if (gametime == 50) {
		if (pl1 == PL1ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 3, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 3, rightSize.height / 4 + ten)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			PL1p->runAction(repeat);

			//�{�X��HP�����炷
			hpcut = (pl1frame.atk - valkyrie.def);
			valkyrie.hp -=hpcut;
			//HP��0�ɂȂ�����
			if (valkyrie.hp <= 0) {
				// �J�ڍ�̉�ʂ�ݽ�ݽ
				Scene *pScene = GameClear::createScene();
				// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// �J�ڎ��s �A�j���[�V����
				Director::getInstance()->replaceScene(transition);
			}

			//�_���[�W�\�L
			String *p1atk = String::createWithFormat("PL1��%i�_���[�W�^����", hpcut);
			string _p1atk = p1atk->getCString();
			auto p1alabel = Label::createWithSystemFont(_p1atk, "HGRSGU.TTC", fontsize);
			p1alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p1alabel, depth, 21);
		}
		else if (pl1 == PL1SKILL) {
			//�G�t�F�N�g�̕\��
			//�G�t�F�N�g�̗�����w��
			CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill1.plist");

			plparticle->setAutoRemoveOnFinish(true);

			//�p�[�e�B�N���J�n
			plparticle->resetSystem();

			//�p�[�e�B�N����\������ꏊ�̐ݒ�
			plparticle->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//�p�[�e�B�N����z�u
			this->addChild(plparticle, depth, 15);

			//�{�X��HP�����炷
			hpcut = (pl1frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			valkyrie.hp -= hpcut;
			//HP��0�ɂȂ�����
			if (valkyrie.hp <= 0) {
				// �J�ڍ�̉�ʂ�ݽ�ݽ
				Scene *pScene = GameClear::createScene();
				// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// �J�ڎ��s �A�j���[�V����
				Director::getInstance()->replaceScene(transition);
			}
			//�_���[�W�\�L
			String *p1skl = String::createWithFormat("PL1��%i�_���[�W�^����", hpcut);
			string _p1skl = p1skl->getCString();
			auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsize);
			p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p1slabel, depth, 21);
		}
	}
	//�v���C���[2�̍s��
	if (gametime == 70) {
		this->removeChildByTag(15);				//�G�t�F�N�g������
		this->removeChildByTag(21);				//�_���[�W�\�L������
		if (pl2 == PL2ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			PL2p->runAction(repeat);

			//�{�X��HP�����炷
			hpcut = (pl2frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			//HP��0�ɂȂ�����
			if (valkyrie.hp <= 0) {
				// �J�ڍ�̉�ʂ�ݽ�ݽ
				Scene *pScene = GameClear::createScene();
				// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// �J�ڎ��s �A�j���[�V����
				Director::getInstance()->replaceScene(transition);
			}

			//�_���[�W�\�L
			String *p2atk = String::createWithFormat("PL2��%i�_���[�W�^����", hpcut);
			string _p2atk = p2atk->getCString();
			auto p2alabel = Label::createWithSystemFont(_p2atk, "HGRSGU.TTC", fontsize);
			p2alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p2alabel, depth, 22);
		}
		else if (pl2 == PL2SKILL) {
			//�G�t�F�N�g�̕\��
			//�G�t�F�N�g�̗�����w��
			CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill2.plist");

			plparticle2->setAutoRemoveOnFinish(true);

			//�p�[�e�B�N���J�n
			plparticle2->resetSystem();

			//�p�[�e�B�N����\������ꏊ�̐ݒ�
			plparticle2->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//�p�[�e�B�N����z�u
			this->addChild(plparticle2, depth, 16);

			//�{�X��HP�����炷
			valkyrie.hp -=(pl2frame.matk - valkyrie.mdef);
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
	}
	//�v���C���[3�̍s��
	if (gametime == 100) {
		this->removeChildByTag(22);				//�_���[�W�\�L������
		this->removeChildByTag(16);				//�G�t�F�N�g������
		if (pl3 == PL3ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 1.5f, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 1.5f, rightSize.height / 4 + ten)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			PL3p->runAction(repeat);

			//�{�X��HP�����炷
			hpcut = (pl3frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			//HP��0�ɂȂ�����
			if (valkyrie.hp <= 0) {
				// �J�ڍ�̉�ʂ�ݽ�ݽ
				Scene *pScene = GameClear::createScene();
				// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// �J�ڎ��s �A�j���[�V����
				Director::getInstance()->replaceScene(transition);
			}

			//�_���[�W�\�L
			String *p3atk = String::createWithFormat("PL3��%i�_���[�W�^����", hpcut);
			string _p3atk = p3atk->getCString();
			auto p3alabel = Label::createWithSystemFont(_p3atk, "HGRSGU.TTC", fontsize);
			p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p3alabel, depth, 23);
		}
		else if (pl3 == PL3SKILL) {
			//�G�t�F�N�g�̕\��
			//�G�t�F�N�g�̗�����w��
			CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
			plparticle3->setAutoRemoveOnFinish(true);

			//�p�[�e�B�N���J�n
			plparticle3->resetSystem();

			//�p�[�e�B�N����\������ꏊ�̐ݒ�
			plparticle3->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//�p�[�e�B�N����z�u
			this->addChild(plparticle3, depth, 17);

			//�{�X��HP�����炷
			valkyrie.hp -=(pl3frame.matk - valkyrie.mdef);
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
	}
}

void BossScene::PLSKILLS()
{
	//���m
	if (job == ATTACKER) {
		//�c�C���t���[��
		if (askill == ASKILL1) {
			//�G�P�̂ɏ��_���[�W2��U��
		}
		//�A�[�}�[�u���C�N
		if (askill == ASKILL2) {
			//�G�P�̂ɏ��_���[�W+�h��̓_�E��
		}
		//���C�t�\�[�h
		if (askill == ASKILL3) {
			//�G�P�̂ɏ��_���[�W�{���g��HP������
		}
		//�C���p�N�g�X���b�V��
		if (askill == ASKILL4) {
			//�G�P�̂ɏ��_���[�W+�U���̓_�E��
		}
		//�\�[�h�X���[
		if (askill == ASKILL5) {
			//�G�P�̂ɖh��͖����̒��_���[�W
		}
		//�g�@��
		if (askill == ASKILL6) {
			//�G�P�̂ɑ�_���[�W
		}
		//�R���f�B�N�V����
		if (askill == ASKILL7) {
			//3�^�[���̊ԁA���g�̍U���͂����A�b�v
		}
		//�E�H���A�[�E�H�[�N���C
		if (askill == ASKILL8) {
			//3�^�[���̊ԁA���g�̍U���͂��A�b�v�E�h��͏��_�E��
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
			//�G�P�̂ɏ��_���[�W
		}
		//�A�[�}�[�V���b�g
		if (mskill == MSKILL2) {
			//�G�P�̂ɏ��_���[�W+���g�̖h�䏬�A�b�v
		}
		//�}�W�b�N�o�[�X�g
		if (mskill == MSKILL3) {
			//�G�P�̂ɒ��_���[�W + �G�̍U���_�E��
		}
		//VFD
		if (mskill == MSKILL4) {
			//�G�P�̂ɓ���_���[�W
		}
		//�O�����c
		if (mskill == MSKILL5) {
			//3�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͏��A�b�v
		}
		//�_�̌䌕
		if (mskill == MSKILL6) {
			//2�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͑�A�b�v
		}
		//���͋z��
		if (mskill == MSKILL7) {
			//�����P�̂�MP��10%�z�������g��MP���񕜂���
		}
		//�S�ċz
		if (mskill == MSKILL8) {
			//3�^�[���̊ԁA���g��MP������
		}
	}
	//���E��
	if (job == HEALER) {
		//���͋���
		if (hskill == HSKILL1) {
			//�����P�̂Ɏ��g��MP�����^����
		}
		//���҂̌o�T
		if (hskill == HSKILL2) {
			//�G�P�̂̍U���͒��_�E��
		}
		//���҂̌o�T
		if (hskill == HSKILL3) {
			//�G�P�̖̂h��͒��_�E��
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
			//�����S�̂�HP������
		}
		//�Z�C���g�I�[�_�[
		if (hskill == HSKILL7) {
			//�����S�̂�HP����
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
		if (pick_rnd < 30) {
			job = ATTACKER;
		}
		if (pick_rnd >= 30 && pick_rnd < 55) {
			job = HEALER;
		}
		if (pick_rnd >= 50 && pick_rnd < 80) {
			job = MAGIC;
		}
		if (pick_rnd >= 80 && pick_rnd <= rndmax) {
			job = SHIELD;
		}
		bsact = DECIDE;
	}
	//�ʏ�U�����X�L���������߂�
	if (bsact == DECIDE) {
		if (decide_rnd < 60) {
			bsact = ATTACK;
		}
		if (decide_rnd >= 60 && decide_rnd <= rndmax ) {
			bsact = SKILL;
		}
	}
	//�ǂ̃X�L���ōU�����邩�����߂�
	if (bsact == SKILL) {
		if (skill_rnd < 40) {
			bskill = BSKILL1;
		}
		if (skill_rnd >= 40 && skill_rnd < 65) {
			bskill = BSKILL2;
		}
		if (skill_rnd >= 65 && skill_rnd < 90) {
			bskill = BSKILL3;
		}
		if (skill_rnd >= 90 && skill_rnd <= rndmax) {
			bskill = BSKILL4;
		}
	}
	//log("pick_rnd %d", pick_rnd);		//�I�񂾃L�����̗������o�͂ɕ\��
	//log("act_rnd %d", act_rnd);		//�{�X�̓����񐔂̗������o�͂ɕ\��
	//log("decide_rnd %d", decide_rnd);	//�{�X�̓����̗������o�͂ɕ\��
	//log("skill_rnd %d", skill_rnd);	//�X�L���̗������o�͂ɕ\��
	log("job %i", job);					//�I�񂾃L�������o�͂ɕ\��
	//log("bsact %i", bsact);			//�{�X�̓������o�͂ɕ\��
	log("actcnt %i", actcnt);			//�J�E���g���o�͂ɕ\��
	//log("skill %i", skill);			//�X�L�����o�͂ɕ\��
	CCString *hpstr1 = CCString::createWithFormat("����PL1HP��%d�ł�", pl1frame.hp);
	log("%s", hpstr1->getCString());	//�v���C���[1��HP��\��
	CCString *hpstr2 = CCString::createWithFormat("����PL2HP��%d�ł�", pl2frame.hp);
	log("%s", hpstr2->getCString());	//�v���C���[2��HP��\��
	CCString *hpstr3 = CCString::createWithFormat("����PL3HP��%d�ł�", pl3frame.hp);
	log("%s", hpstr3->getCString());	//�v���C���[3��HP��\��
	CCString *hpstrBS = CCString::createWithFormat("���݃��@���L���[HP��%d�ł�", valkyrie.hp);
	log("%s", hpstrBS->getCString());	//���@���L���[��HP��\��

	//�U�����[�h�̎�
	if (bsact == ATTACK) {
		if (gametime == 80) {
			//�^�C�}�[��80(��)�ɂȂ����當����\������
			CCLabelTTF *atk = CCLabelTTF::create("�u�₠���I(�ʏ�U��)�v", "HGRSGU.TTC", fontsize);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, depth, 5);
			//�{�X�̉摜��h�炷����
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f - ten)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);
			//HP���ւ炷
			if (job == ATTACKER) {
				hpcut = (valkyrie.atk - pl1frame.def);
				pl1frame.hp -= hpcut;
				PL1p->setColor(ccc3(Colormax, Color, Color));
			}
			else if(job == HEALER){
				hpcut = (valkyrie.atk - pl1frame.def);
				pl2frame.hp -= hpcut;
				PL2p->setColor(ccc3(Colormax, Color, Color));
			}
			else if (job == MAGIC) {
				hpcut = (valkyrie.atk - pl3frame.def);
				pl3frame.hp -= hpcut;
				PL3p->setColor(ccc3(Colormax, Color, Color));
			}
			//�N����HP���[���ɂȂ�����
			if ((pl1frame.hp <= 0) || (pl2frame.hp <= 0) || (pl3frame.hp <= 0)) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0f, pScene);	// 1�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}
		}
		//�L�����摜�̐F��߂�
		if (gametime == 100) {
			PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
		}
		//���ʏ���
		//�^�C�}�[��230(��)�ɂȂ�ƌ��ʂ�\�L
		if (gametime == 230) {
			if (job == ATTACKER) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�A�^�b�J�[��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p1bsalabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p1bsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1bsalabel, depth, 6);
			}
			else if (job == HEALER) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�q�[���[��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, depth, 6);
			}
			else if (job == MAGIC) {
				//�_���[�W�\�L
				String *p1bsatk = String::createWithFormat("�}�W�b�N��%i�_���[�W�^����", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, depth, 6);
			}
		}
		//�ӂ������[���o�͂ɕ\��
		log("�ӂ������[");		
	}
	//���@���L���[�X�L��
	if (bsact == SKILL) {
		//��̑���
		if (bskill == BSKILL1) {
			//�^�C�}�[��80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gametime == 80) {
				CCLabelTTF *Gskill1 = CCLabelTTF::create("�u���炦�c�I�v", "HGRSGU.TTC", fontsize);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, depth, 54);
			}
			//�h�炷����
			if (gametime == 220) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + ten)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f - ten)),
					NULL
				);
				//�h�炷
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// ��ʃT�C�Y�擾
				Size winSize = Director::getInstance()->getVisibleSize();

				//�w�i��h�炷
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 2.02f + ten)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 2.02f - ten)),
					NULL
				);
				//����h�炷��
				auto backrepeat = Repeat::create(backmove, continuity);
				//�h�炷
				back->runAction(backrepeat);

				//�v���C���[�S����HP�����炷
				pl1frame.hp -= (valkyrie.atk - pl1frame.def);
				pl2frame.hp -= (valkyrie.atk - pl2frame.def);
				pl3frame.hp -= (valkyrie.atk - pl3frame.def);

				//�g�ɐ��߂Ă��̃L������
				PL1p->setColor(ccc3(Colormax, Color, Color));
				PL2p->setColor(ccc3(Colormax, Color, Color));
				PL3p->setColor(ccc3(Colormax, Color, Color));
				
				//HP���[���ɂȂ�����
				if ((pl1frame.hp <= 0)||(pl2frame.hp <= 0)||(pl3frame.hp <= 0)) {
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
			//�^�C�}�[��230(��)�ɂȂ�ƃ_���[�W�\�L
			if (gametime == 230) {
				CCLabelTTF *Gskill1dec = CCLabelTTF::create("�S���Ƀ_���[�W��^����", "HGRSGU.TTC", fontsize);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, depth, 55);

				//�L�����̐F��߂�
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			}
		}
		//��̑���
		if (bskill == BSKILL2) {
			//�^�C�}�[��80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gametime == 80) {
				CCLabelTTF *Gskill2 = CCLabelTTF::create("�u�₠�����I�v", "HGRSGU.TTC", fontsize);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, depth, 56);

				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - pl1frame.def);
					pl1frame.hp -= hpcut;	//HP���ւ炷
					PL1p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - pl2frame.def);
					pl2frame.hp -= hpcut;
					PL2p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - pl3frame.def);
					pl3frame.hp -= hpcut;
					PL3p->setColor(ccc3(Colormax, Color, Color));
				}

				//�G�t�F�N�g�̕\��
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				//�p�[�e�B�N���J�n
				particle->resetSystem();

				//�p�[�e�B�N����\������ꏊ�̐ݒ�
				particle->setPosition(ccp(rightSize.width / 2, rightSize.height / 3));

				//�p�[�e�B�N����z�u
				this->addChild(particle, depth, 13);
			}
			//���ڂ̍U��
			if (gametime == 150) {
				//���ڂ�HP�����炷
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - pl1frame.def);
					pl1frame.hp -= hpcut;	//HP���ւ炷
					PL1p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - pl2frame.def);
					pl2frame.hp -= hpcut;
					PL2p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - pl3frame.def);
					pl3frame.hp -= hpcut;
					PL3p->setColor(ccc3(Colormax, Color, Color));
				}
				//HP���[���ɂȂ������ʑJ��
				if ((pl1frame.hp <= 0) || (pl2frame.hp <= 0) || (pl3frame.hp <= 0)) {
					Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
					TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
					Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
				}
				//�L�����̐F��߂�
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			}
			//���ʏ���
			//�^�C�}�[��230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gametime == 230) {
				CCLabelTTF *Gskill2dec = CCLabelTTF::create("�Q��_���[�W�Ƀ_���[�W", "HGRSGU.TTC", fontsize);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, depth, 57);
			}
		}
		//�Z��̐w
		if (bskill == BSKILL3) {
			if (gametime == 80) {
				CCLabelTTF *Gskill3 = CCLabelTTF::create("�u����ł����@���L���[�Ȃ̂Łv", "HGRSGU.TTC", fontsize);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, depth, 58);

				//���@���L���[�̖h��͂𑝂₷
				valkyrie.def += 2;					
			}
			//���ʏ���
			//�^�C�}�[��230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gametime == 230) {
				CCLabelTTF *Gskill3dec = CCLabelTTF::create("���@���L���[�̖h��͂��啝�ɏオ����", "HGRSGU.TTC", 40);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, depth, 59);
			}
		}
		//�G�X�e
		if (bskill == BSKILL4) {
			if (gametime == 80) {
				CCLabelTTF *Gskill4 = CCLabelTTF::create("�u�G�X�e�c����c�v", "HGRSGU.TTC", fontsize);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, depth, 60);

				//���@���L���[��HP�𑝂₷
				valkyrie.hp += 3;					
			}
			//���ʏ���
			//�^�C�}�[��230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gametime == 230) {
				CCLabelTTF *Gskill4dec = CCLabelTTF::create("���@���L���[��HP�������񕜂���", "HGRSGU.TTC", fontsize);
				Gskill4dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4dec, depth, 61);
			}
		}
		log("�t�@�C�A�[");		//�t�@�C�A�[���o�͂ɕ\��
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
//�w�i
	//�w�i�̉摜�w��
	back = CCSprite::create("BackImage/ST_Boss.png"); 
	// �\�����W�w��
	back->setPosition(ccp(winSize.width / 2, winSize.height / 2.02f));
	//�ǉ�
	this->addChild(back, depth);
// �{�X�̕\��
	// �T�C�Y�擾
	rightSize = CCDirector::sharedDirector()->getWinSize();
	// �摜�w��
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");
	// �\�����W�w��
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));
	// �ǉ�
	this->addChild(Boss, depth);
//PL1
	//�摜�w��
	PL1p = CCSprite::create("Player/PL_Attacker_face.png");
	//�\�����W�w��
	PL1p->setPosition(ccp(rightSize.width / 3, rightSize.height / 4));
	//�ǉ�
	this->addChild(PL1p, depth);
//PL2
	//�摜�w��
	PL2p = CCSprite::create("Player/PL_Healer_face.png");
	//�\�����W�w��
	PL2p->setPosition(ccp(rightSize.width / 2, rightSize.height / 4));
	//�ǉ�
	this->addChild(PL2p, depth);
//PL3
	//�摜�w��
	PL3p = CCSprite::create("Player/PL_Magic_face.png");
	//�\�����W�w��
	PL3p->setPosition(ccp(rightSize.width / 1.5f, rightSize.height / 4));
	//�ǉ�
	this->addChild(PL3p, depth);
//�X�e�[�^�X(HP)
	HPpl1 = CCSprite::create("UI/Status/UI_Status_Life.png");
	HPpl1->setPosition(ccp(rightSize.width / 3 - HPpl1->getContentSize().width / 2,
						   rightSize.height / 5 - HPpl1->getContentSize().height / 2));
	CCPoint ancharpoint = ccp(0.0f, 0.0f);
	HPpl1->setAnchorPoint(ancharpoint);
	HPbar = HPpl1->getTextureRect().origin;
	HPGaugeWidth = HPpl1->getContentSize().width;
	this->addChild(HPpl1, 2, 48);

	HPBpl1 = CCSprite::create("UI/Status/UI_Status_Lifeback.png");
	HPBpl1->setPosition(ccp(rightSize.width / 3 - HPBpl1->getContentSize().width / 2,
							rightSize.height / 5 - HPBpl1->getContentSize().height / 2));
	this->addChild(HPBpl1, depth, 49);

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