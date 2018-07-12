#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:


	//�L�����g�̃X�e�[�^�X
	struct FRAME{
		int hp;			//�̗�
		int hpmax;		//�����̗͍̑ő�l
		int mana;		//���_��
		int manamax;	//�����̐��_�͍ő�l
		int atk;		//�U����
		int atkmax;		//�����̍U���̍ő�l
		int def;		//�h���
		int defmax;		//�����̖h��͂̍ő�l
		int matk;		//���@��
		int matkmax;	//�����̖��@�͂̍ő�l
		int mdef;		//���h��
		int mdefmax;	//�����̖��h�͂̍ő�l
		int choicejob;	//�I�������E��
	};

	struct CHAR {
		int hp;			//�̗�
		int hpmax;		//�����̗͍̑ő�l
		int mana;		//���_��
		int manamax;	//�����̐��_�͍ő�l
		int atk;		//�U����
		int atkmax;		//�����̍U���̍ő�l
		int def;		//�h���
		int defmax;		//�����̖h��͂̍ő�l
		int matk;		//���@��
		int matkmax;	//�����̖��@�͂̍ő�l
		int mdef;		//���h��
		int mdefmax;	//�����̖��h�͂̍ő�l
		int choicejob;	//�I�������E��
	};



	//�^�[���̏���
	enum TURN{
		PLAYER,			//�v���C���[�̃^�[��
		BOSS,			//�G�̃^�[��
	};

	//�Ƃ肠�����v���C���[�𑝂₵�܂�
	enum JOB {
		NON,			//�����I������Ă��Ȃ�
		ATTACKER,		//���m
		SHIELD,			//�R�m
		MAGIC,			//���p�t
		HEALER,			//���E��
	};

	//�o�g�����̏���
	enum BATTLE {
		START,			//�퓬�J�n
		WAIT,			//�҂����
		CHOICE,			//�I��
		ACTION,			//���[�V������
	};

	//�I��
	enum CHOICES {
		CHAR1,			//�L�����g1
		CHAR2,			//�L�����g2
		CHAR3,			//�L�����g3
	};

	enum PL1 {
		PL1NON,			//�������Ȃ�
		PL1ATTACK,		//�U��
		PL1SKILL,		//�X�L��
		PL1DEATH,		//���S���
	};

	enum PL2 {
		PL2NON,			
		PL2ATTACK,
		PL2SKILL,
		PL2DEATH,
	};
	enum PL3 {
		PL3NON,			
		PL3ATTACK,
		PL3SKILL,
		PL3DEATH,
	};

	//�ǂ̃X�L�����g���������߂�Ƃ��Ɏg��
	enum SKILL {
		SKILL1,
		SKILL2,
		SKILL3,
		SKILL4,
		SKILL5,
		SKILL6,
		SKILL7,
		SKILL8,
	};

	//���m
	enum ATTAKERSKILL {
		ASKILL1,		//�c�C���t���[��
		ASKILL2,		//�A�[�}�[�u���C�N
		ASKILL3,		//���C�t�\�[�h
		ASKILL4,		//�C���p�N�g�X���b�V��
		ASKILL5,		//�\�[�h�X���[
		ASKILL6,		//�g�@��
		ASKILL7,		//�R���f�B�N�V����
		ASKILL8,		//�E�H���A�[�E�H�[�N���C
	};
	//�R�m
	enum SHIELDSKILL {
		SSKILL1,		//�A�C���X�]�C��
		SSKILL2,		//�J�E���^�[
		SSKILL3,		//�őO��
		SSKILL4,		//�g����̕X��
		SSKILL5,		//�Q���X��
		SSKILL6,		//�ە�����Y����
		SSKILL7,		//�X�̌��
		SSKILL8,		//�R�m������
	};
	//���p�t
	enum MAZICSKILL {
		MSKILL1,		//�}�W�b�N�~�T�C��
		MSKILL2,		//�A�[�}�[�V���b�g
		MSKILL3,		//�}�W�b�N�o�[�X�g
		MSKILL4,		//VFD
		MSKILL5,		//�O�����c
		MSKILL6,		//�_�̌䌕
		MSKILL7,		//���͋z��
		MSKILL8,		//�S�ċz
	};
	//���E��
	enum HEALERSKILL {
		HSKILL1,		//���͋���
		HSKILL2,		//���҂̌o�T
		HSKILL3,		//���҂̌o�T
		HSKILL4,		//�Z�C���g���[�O
		HSKILL5,		//�����m�؁[�p�[
		HSKILL6,		//���҂̋F��
		HSKILL7,		//�Z�C���g�I�[�_�[
		HSKILL8,		//�_�̌[��
	};

	//�{�X�̓���
	enum BSACT {
		PICK,			//�U������v���C���[��I��
		DECIDE,			//���������߂�
		BOSSATTACK,		//�U��
		BOSSSKILL			//�X�L��
	};

	//�{�X�̃X�L��
	enum BOSSSKILLS{
		BSKILL1,		//��̑���
		BSKILL2,		//��̑���
		BSKILL3,		//�Z��̐w
		BSKILL4,		//�G�X�e
	};

	//�^�O(�萔)
	const int normalattackS = 1;		//�ʏ�U��(����)
	const int damageS = 2;				//�`�_���[�W�^����(����)
	const int bossskill1S = 3;			//�{�X�̃X�L��1(����)
	const int bossskill1damageS = 4;	//�{�X�̃X�L��1�_���[�W(����)
	const int bossskill2S = 5;			//�{�X�̃X�L��2(����)
	const int bossskill2damageS = 6;	//�{�X�̃X�L��2�_���[�W(����)
	const int bossskill3S = 7;			//�{�X�̃X�L��3(����)
	const int bossskill3damageS = 8;	//�{�X�̃X�L��3����(����)
	const int bossskill4S = 9;			//�{�X�̃X�L��4(����)
	const int bossskill4damageS = 10;	//�{�X�̃X�L��4����(����)
	const int bossskill1E = 11;			//�{�X�X�L��1(�G�t�F�N�g)�^�O11�`14
	const int askill1E = 15;			//���m�X�L���P(�G�t�F�N�g)�^�O15�`22
	const int mskill1E= 23;				//���p�t�X�L���P(�G�t�F�N�g)�^�O23�`30
	const int hskill1E = 31;			//���E�҃X�L���P(�G�t�F�N�g)�^�O31�`38
	const int sskill1E = 39;			//�R�m�X�L��1(�G�t�F�N�g)�^�O39�`47
	const int attackerdamageS = 48;		//���m�́`�_���[�W�^����(����)
	const int healerdamageS = 49;		//���E�҂́`�_���[�W�^����(����)
	const int magicdamageS = 50;		//���p�t�́`�_���[�W�^����(����)
	const int attackbuttonaI = 51;		//�����O�̍U���R�}���h�{�^��(�摜)
	const int attackbuttonbI = 52;		//��������̍U���R�}���h�{�^��(�摜)
	const int skillbuttonaI = 53;		//�����O�̃X�L���R�}���h�{�^��(�摜)
	const int skillbuttonbI = 54;		//��������̃X�L���R�}���h�{�^��(�摜)
	const int choiceS = 80;				//�`�͂ǂ�����(����)
	const int damage1 = 81;				//�_���[�W��̗͂̏�ɕ\�L
	const int buffupS = 82;				//�X�e�[�^�X���オ�����Ƃ��ɕ\�L(����)
	const int buffdownS = 83;			//�X�e�[�^�X�����������Ƃ��ɕ\�L(����)
	const int playertrunI = 99;			//PLTURN(�摜)�������\��
	const int bossturnI = 100;			//BSTURN(�摜)�������\��

	//�p�[�Z���g�v�Z(�萔)
	const int tenpercent = 10;			//1��(10)
	const int twentypercent = 20;		//2��(20)
	const int thirtypercent = 30;		//3��(30)
	const int fortypercent = 40;		//4��(40)
	const int fiftypercent = 50;		//5��(50)
	const int sixtypercent = 60;		//6��(60)
	const int seventypercent = 70;		//7��(70)
	const int eightypercent = 80;		//8��(80)
	const int ninetypercent = 90;		//9��(90)
	const int hundredpercent = 100;		//10��(100)

	//�萔
	const int backdepth = 1;		//���s(���)
	const int middledepth = 2;		//���s(�^��)
	const int prevdepth = 3;		//���s(�O)
	const int onece = 4;			//��Ԏ�O
	const int continuity1 = 3;		//�h�炷��1
	const int continuity2 = 6;		//�h�炷��2
	const int moverange = 20;		//�ړ�������l
	const int fontsizeS = 20;		//�����̑傫��(S�T�C�Y)
	const int fontsizeM = 30;		//�����̑傫��(M�T�C�Y)
	const int fontsizeL = 40;		//�����̑傫��(L�T�C�Y)
	const int fontsizeXL = 50;		//�����̑傫��(XL�T�C�Y)
	const int flame15 = 15;			//�t���[����15
	const int flame50 = 50;			//�t���[����50
	const int flame70 = 70;			//�t���[����70
	const int flame80 = 80;			//�t���[����80
	const int flame100 = 100;		//�t���[����100
	const int flame110 = 110;		//�t���[����110
	const int flame130 = 130;		//�t���[����130
	const int flame150 = 150;		//�t���[����150
	const int flame170 = 170;		//�t���[����170
	const int flame200 = 200;		//�t���[����200
	const int flame210 = 210;		//�t���[����210
	const int flame220 = 220;		//�t���[����220
	const int flame230 = 230;		//�t���[����230
	const int flame250 = 250;		//�t���[����250
	const int flamemax = 350;		//�t���[���̍ő�l
	const int hpmin = 0;			//HP�̍ŏ��l
	const int rndmin = 0;			//�����_���̍ŏ��l
	const int rndmax = 100;			//�����_���̍ő�l
	const int colordown = 150;		//�Â�����
	const int colormin = 0;			//�F�ŏ��l
	const int colormax = 255;		//�F�ő�l
	const int opacitymin = 0;		//�����x�̍ŏ��l
	const int opacitymax = 255;		//�����x�̍ő�l
	const float skilluplittle = 0.75f;	//�X�L���{����(0.75�{)
	const float skillupmedium = 1.2f;	//�X�L���{����(1.2�{)
	const float skilluplarge = 1.5f;	//�X�L���{����(1.5�{)
	const float buffuplittle = 0.0f;	//�X�e�[�^�X�A�b�v�{����(0.0�{)
	const float buffupmedium = 0.0f;	//�X�e�[�^�X�A�b�v�{����(0.0�{)
	const float buffuplarge = 0.0f;		//�X�e�[�^�X�A�b�v�{����(0.0�{)
	const float buffdownlittle = 0.2f;	//�X�e�\�^�X�_�E���{����(0.2�{)
	const float buffdownmedium = 0.5f;	//�X�e�\�^�X�_�E���{����(0.5�{)
	const float buffdownlarge = 0.8f;	//�X�e�\�^�X�_�E���{����(0.8�{)


	//�ϐ�
	int actcnt = 0;				//�{�X�̓�����
	int bsskillrecovery = 0;	//�{�X�X�L��4�̉񕜂̗�
	int hpcut = 0;				//�v�Z������̃_���[�W
	int buffup = 0;				//�X�e�[�^�X�㏸
	int buffdown = 0;			//�X�e�[�^�X���~
	int	recovery = 0;			//�񕜗�
	int opacity = 255;			//�����x
	int rnd = random();			//�ő�l�܂ł̗������擾
	int act_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
	int pick_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
	int skill_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�X�L��)
	int decide_rnd = rndmin;	//�w�肵���͈͓��̗������擾(�{�X�̓���)
	float movecnt = 0.05f;		//�摜�𓮂�������
	float pl1hpgaugewidth = 0.0f;	//�v���C���[1HP�Q�[�W�̉��̃T�C�Y
	float pl1mngaugewidth = 0.0f;	//�v���C���[1MN�Q�[�W�̉��̃T�C�Y
	float pl2hpgaugewidth = 0.0f;	//�v���C���[2HP�Q�[�W�̉��̃T�C�Y
	float pl2mngaugewidth = 0.0f;	//�v���C���[2MN�Q�[�W�̉��̃T�C�Y
	float pl3hpgaugewidth = 0.0f;	//�v���C���[3HP�Q�[�W�̉��̃T�C�Y
	float pl3mngaugewidth = 0.0f;	//�v���C���[3MN�Q�[�W�̉��̃T�C�Y
	float bosshpgaugewidth = 0.0f;	//�{�XHP�Q�[�W�̉��̃T�C�Y
	bool flag = false;			//�{�X�̏��
	bool state = false;			//�v���C���[�̏��
	bool attackendflag = false;	//�U�����I��������ǂ���
	bool skillendflag = false;	//�X�L�����I��������ǂ���
	bool fntflag = false;		//�t�H���g�̏����鎞��
	long gameflame = 0;			//���ꂼ��̃^�[���̎���
	long skillflame = 0;		//���ꂼ��̃X�L���̎���
	long choicetime = 0;		//�{�^����A�����ĉ����Ȃ��悤�ɂ��鏈��

	//enum
	TURN turn;				//�^�[��
	JOB job;				//�L�����̐E��
	BATTLE battle;			//�o�g��
	BSACT bsact;			//�{�X�̓���
	CHOICES choices;		//�I��
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	SKILL pl1skill;			//�ǂ̃X�L�����g�����������߂�
	SKILL pl2skill;			//�ǂ̃X�L�����g�����������߂�
	SKILL pl3skill;			//�ǂ̃X�L�����g�����������߂�
	ATTAKERSKILL askill;	//�A�^�b�J�[�X�L��
	SHIELDSKILL sskill;		//�V�[���_�[�X�L��
	HEALERSKILL hskill;		//�q�[���[�X�L��
	MAZICSKILL mskill;		//�}�W�b�N�X�L��
	BOSSSKILLS bskill;		//�{�X�X�L��
	//struct
	FRAME pl1frame;			//�L�����g1
	FRAME pl2frame;			//�L�����g2
	FRAME pl3frame;			//�L�����g3
	CHAR attacker;			//���m
	CHAR shield;			//�R�m
	CHAR magic;				//���p�t
	CHAR healer;			//���E��
	CHAR valkyrie;			//���@���L���[
	//cocos2d-x
	cocos2d::Vec2 HPbar;	//HP�΁[�̒���
	cocos2d::Vec2 MNbar;	//MANA�΁[�̒���
	CCSize rightSize;		//�I�u�W�F�N�g��z�u����Ƃ��ɕK�v
	CCSprite *back;			//�w�i
	CCSprite *plturn;		//PLTURN����(�����\��)
	CCSprite *emturn;		//BSTURN����(�����\��)
	CCSprite *AttackButton1;//�U���R�}���h
	CCSprite *AttackButton2;//�U���R�}���h(�����Ă���Ƃ�)
	CCSprite *SkillButton1;	//�X�L���R�}���h
	CCSprite *SkillButton2;	//�X�L���R�}���h(�����Ă���Ƃ�)
	LabelTTF *lo;			//���m�͂ǂ�����
	LabelTTF *ll;			//���E�҂͂ǂ�����
	LabelTTF *lw;			//���p�t�͈ȉ���
	//���m��UI
	CCSprite *PL1p;			//���m�̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *HPpl1;		//���m��HP
	CCSprite *MNpl1;		//���m��MN
	LabelTTF *p1hpal;		//���m��HP�\�L
	LabelTTF *p1hpmaxal;	//HP�̍ő�l
	LabelTTF *p1mnal;		//���m��MN�\�L
	LabelTTF *p1mnmaxal;	//MANA�̍ő�l
	LabelTTF *dmf1;			//���m�_���[�W�\��
	CCFadeOut *fadeout1;	//���m�_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *fdoutmov1;	//���m�_���[�W�\���t�F�[�h�A�E�g���̓���
	//���E�҂�UI
	CCSprite *PL2p;			//���E�҂̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *HPpl2;		//���E�҂�HP
	CCSprite *MNpl2;		//���E�҂�MN
	LabelTTF *p2hpal;		//���E�҂�HP�\�L
	LabelTTF *p2hpmaxal;	//HP�̍ő�l
	LabelTTF *p2mnal;		//���E�҂�MN�\�L
	LabelTTF *p2mnmaxal;	//MANA�̍ő�l
	LabelTTF *dmf2;			//���E�҃_���[�W�\��
	CCFadeOut *fadeout2;	//���E�҃_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *fdoutmov2;	//���E�҃_���[�W�\���t�F�[�h�A�E�g���̓���
	//���p�t��UI
	CCSprite *PL3p;			//���p�t�̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *HPpl3;		//���p�t��HP
	CCSprite *MNpl3;		//���p�t��MN
	LabelTTF *p3hpal;		//���p�t��HP�\�L
	LabelTTF *p3hpmaxal;	//HP�̍ő�l
	LabelTTF *p3mnal;		//���p�t��MN�\�L
	LabelTTF *p3mnmaxal;	//MANA�̍ő�l
	LabelTTF *dmf3;			//���p�t�_���[�W�\��
	CCFadeOut *fadeout3;	//���p�t�_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *fdoutmov3;	//���p�t�_���[�W�\���t�F�[�h�A�E�g���̓���
	//�{�X��UI
	CCSprite *Boss;			//�{�X
	CCSprite *efect;		//�p�[�e�B�N��
	CCSprite *HPboss;		//�{�X��hp
	Repeat *bossrepeat;		//�{�X���_���[�W���󂯂����ɗh�炷����
	//PL1��UI��h�炷����(�h�炷�����傫��)	
	Repeat *pl1repeat1a, *pl1repeat2a, *pl1repeat3a, *pl1repeat4a, *pl1repeat5a, *pl1repeat6a, *pl1repeat7a;
	//PL1��UI��h�炷����(�h�炷����������)	
	Repeat *pl1repeat1b, *pl1repeat2b, *pl1repeat3b, *pl1repeat4b, *pl1repeat5b, *pl1repeat6b, *pl1repeat7b;
	//PL2��UI��h�炷����(�h�炷�����傫��)	
	Repeat *pl2repeat1a, *pl2repeat2a, *pl2repeat3a, *pl2repeat4a, *pl2repeat5a, *pl2repeat6a, *pl2repeat7a;
	//PL2��UI��h�炷����(�h�炷����������)	
	Repeat *pl2repeat1b, *pl2repeat2b, *pl2repeat3b, *pl2repeat4b, *pl2repeat5b, *pl2repeat6b, *pl2repeat7b;
	//PL3��UI��h�炷����(�h�炷�����傫��)	
	Repeat *pl3repeat1a, *pl3repeat2a, *pl3repeat3a, *pl3repeat4a, *pl3repeat5a, *pl3repeat6a, *pl3repeat7a;
	//PL3��UI��h�炷����(�h�炷����������)	
	Repeat *pl3repeat1b, *pl3repeat2b, *pl3repeat3b, *pl3repeat4b, *pl3repeat5b, *pl3repeat6b, *pl3repeat7b;


	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//������
	virtual void update(float flame);	//���C��
	virtual void PLturn();				//�v���C���[�̃^�[��
	virtual void Plattacks();			//�v���C���[�̒ʏ�U��
	virtual void Plskills();			//�v���C���[�̃X�L��
	virtual void BSturn();				//�{�X�̃^�[��
	virtual void Damage();				//�_���[�W���󂯂����̏���
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	//�^�b�`�J�n
	virtual void onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event);		//�X���C�v
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);	//�^�b�`�I��
	virtual void onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);	//�L�����Z��
	
	CREATE_FUNC(BossScene);

	void BossBackGroudn();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);

};

#endif //Select