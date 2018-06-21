#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:


	//�v���C���[�̃X�e�[�^�X(��)
	struct CHARS{
		int hp;			//�̗�
		int mana;		//���_��
		int atk;		//�U����
		int def;		//�h���
		int matk;		//���@��
		int mdef;		//���h��
	};

	//�^�[���̏���
	enum TURN{
		PLAYER,			//�v���C���[�̃^�[��
		BOSS,			//�G�̃^�[��
	};

	//�Ƃ肠�����v���C���[�𑝂₵�܂�
	enum JOB {
		NON,			//�����I������Ă��Ȃ�
		ATTACKER,		//�A�^�b�J�[
		HEALER,			//�q�[���[
		MAGIC,			//�}�W�b�N
		SHIELD,			//�V�[���_�[
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
		CHAR1,			//�L�����g�P
		CHAR2,			//�L�����g�Q
		CHAR3,			//�L�����g3
	};

	enum PL1 {
		PL1ATTACK,		//�U��
		PL1SKILL,		//�X�L��
	};

	enum PL2 {
		PL2ATTACK,
		PL2SKILL,
	};
	enum PL3 {
		PL3ATTACK,
		PL3SKILL,
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
		ATTACK,			//�U��
		SKILL			//�X�L��
	};

	//�{�X�̃X�L��job
	enum BOSSSKILLS{
		BSKILL1,		//��̑���
		BSKILL2,		//��̑���
		BSKILL3,		//�Z��̐w
		BSKILL4,		//�G�X�e
	};

	int Bhp;			//�L������HP
	int continuity;		//�h�炷��
	int ten;			//10
	int hpcut;			//���炷HP
	int rnd;			//�����_���֐�
	int rndmin;			//�����_���̍ŏ��l
	int rndmax;			//�����_���̍ő�l
	int pick_rnd;		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
	int act_rnd;		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
	int decide_rnd;		//�w�肵���͈͓��̗������擾(�{�X�̓���)
	int skill_rnd;		//�w�肵���͈͓��̗������擾(�X�L��)
	int	depth;			//���s��
	int timemax;		//���Ԃ̍ő�l
	int actcnt;			//�{�X�̓�����
	int fontsize;		//�����̑傫��
	int Color;			//�F�܂��͈Â�
	int Colormax;		//�F�ő�l
	int Shader;			//�V�F�[�_�[
	int HPGaugecnt;		//hp�Q�[�W���J�E���g����
	int HPGaugeStopcnt;	//��
	float HPGaugeWidth;	//HP�Q�[�W�̉��̃T�C�Y
	float movecnt;		//����������
	bool state;			//�v���C���[�̏��
	bool flag;			//�{�X�̏��
	long choicetime;	//�{�^����A�����ĉ����Ȃ��悤�ɂ��鏈��
	long gametime;		//�^�C��
	long gaugecnt;

	
	//enum
	TURN turn;				//�^�[��
	JOB job;				//�L�����̐E��
	BATTLE battle;			//�o�g��
	BSACT bsact;			//�{�X�̓���
	CHOICES choices;		//�I��
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	BOSSSKILLS bskill;		//�{�X�X�L��
	ATTAKERSKILL askill;	//�A�^�b�J�[�X�L��
	SHIELDSKILL sskill;		//�V�[���_�[�X�L��
	HEALERSKILL hskill;		//�q�[���[�X�L��
	MAZICSKILL mskill;		//�}�W�b�N�X�L��
	//struct
	CHARS pl1frame;			//�L�����g1
	CHARS pl2frame;			//�L�����g2
	CHARS pl3frame;			//�L�����g3
	CHARS valkyrie;			//���@���L���[
	//cocos2d-x
	cocos2d::Vec2 HPbar;	//HP�΁[�̒���
	CCSize rightSize;		//�I�u�W�F�N�g��z�u����Ƃ��ɕK�v�H
	CCSprite* hp;			//�c��HP�̊m�F
	CCSprite* Boss;			//�{�X
	CCSprite* back;			//�w�i
	CCSprite* Kyara;		//�v���C���[(��)
	CCSprite* efect;		//�p�[�e�B�N��
	CCSprite* plturn;		//PLTURN����
	CCSprite* emturn;		//BSTURN����
	CCSprite* AttackButton1;//�U���R�}���h
	CCSprite* AttackButton2;//�U���R�}���h(�����Ă���Ƃ�)
	CCSprite* SkillButton1;	//�X�L���R�}���h
	CCSprite* SkillButton2;	//�X�L���R�}���h(�����Ă���Ƃ�)
	CCSprite* PL1p;			//�v���C���[1
	CCSprite* PL2p;			//�v���C���[2
	CCSprite* PL3p;			//�v���C���[3
	CCSprite* HPpl1;		//�v���C���[�P��HP
	CCSprite* HPBpl1;		//�v���C���[�P��HP���

	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//������
	virtual void update(float flame);	//���C��
	virtual void PLturn();				//�v���C���[�̃^�[��
	virtual void PLSKILLS();			//�v���C���[�̃X�L��
	virtual void BSturn();				//�{�X�̃^�[��
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