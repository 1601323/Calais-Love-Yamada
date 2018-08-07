#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

#define BUFFUP_RECORD_VALUE_NUMBER 2			//�㏸�����l���L�^���鐔
#define BUFFDOWN_RECORD_VALUE_NUMBER 2			//���~�����l���L�^���鐔
#define SKILL_RECORD_TURN 6						//�X�L���̃^�[�����L�^���鐔
#define SKILL_RECORD_FLAG 6						//�X�L���̃t���O�Ǘ����L�^���鐔
#define ALLSKILL_BUFF_NUMBER 4					//�S�̃X�L���̃o�t���������X�e�[�^�X�̎��
#define ALLSKILL_RECORD_TURN 5					//�S�̃X�L���̃^�[�������L�^���鐔
#define ALLSKILL_BUFF_VALUE_NUMBER 4			//�S�̃X�L���̏㏸�����l�̎��
#define SIMPLESUBSTANCESKILL_BUFFUP_NUMBER 2	//�P�̃X�L���̃o�t���������X�e�[�^�X�̎��
#define SIMPLESUBSTANCESKILL_BUFFDOWN_NUMBER 2	//�P�̃X�L���̃o�t���������X�e�[�^�X�̎��
#define SIMPLESUBSTANCESKILL_RECORD_TURN 6		//�P�̃X�L���̃^�[�������L�^���鐔


USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:
	//�^�[���̏���
	enum TURN{
		PLAYER,			//�v���C���[�̃^�[��
		BOSS,			//�G�̃^�[��
	};

	//�E��
	enum JOB {
		NON,			//�����I������Ă��Ȃ�
		ATTACKER,		//���m
		SHIELD,			//�R�m
		MAGIC,			//���p�t
		HEALER,			//���E��
	};
	
	//�I���n�ŐE�Ƃ�I��
	enum SJOB {
		S_ATTACKER,		//���m
		S_SHIELD,		//�R�m
		S_MAGIC,		//���p�t
		S_HEALER,		//���E��
	};

	//�o�g�����̏���
	enum BATTLE {
		START,			//�퓬�J�n
		WAIT,			//�X�L���Ȃǂ̌��ʃ^�[���I���Ȃǂ�\�L����Ƃ���
		CHOICE,			//�I��
		ACTION,			//���[�V������
	};

	//�I��
	enum CHOICES {
		CHAR1,			//�L�����g1
		CHAR2,			//�L�����g2
		CHAR3,			//�L�����g3
		CHOICETIME_SHIELD,//�X�L���ɂ��I��(�����Ƃ���ł�����if����ʂ蔲���ă^�b�`�����Ă��܂����番���Ă���)
		CHOICETIME_MAGIC,
		CHOICETIME_HEALER,
	};

	//PL1�̏��
	enum PL1 {
		PL1NON,			//�������Ȃ�
		PL1ATTACK,		//�U��
		PL1SKILL,		//�X�L��
		PL1DEFENCE,		//�h��
		PL1ITEM,		//�A�C�e��
		PL1DEATH,		//���S���
	};
	//PL2�̏��
	enum PL2 {
		PL2NON,			
		PL2ATTACK,
		PL2SKILL,
		PL2DEFENCE,	
		PL2ITEM,		
		PL2DEATH,
	};
	//PL3�̏��
	enum PL3 {
		PL3NON,			
		PL3ATTACK,
		PL3SKILL,
		PL3DEFENCE,		
		PL3ITEM,		
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

	//�X�L���̃o�t�E�f�o�t�̃^�[���Ɋւ�����
	enum BUFFT {
		ASKILL2T,
		ASKILL4T,
		ASKILL7T,
		ASKILL8T,
		SSKILL2T,
		SSKILL3T,
		SSKILL4T,
		SSKILL5T,
		SSKILL6T,
		SSKILL7T,
		SSKILL8T,
		MSKILL2T,
		MSKILL3T,
		MSKILL5T,
		MSKILL6T,
		HSKILL2T,
		HSKILL3T,
		BVSKILL3T,
	};

	//�L�����g�A�E�Ƃ̃X�e�[�^�X
	struct FRAME {
		int level = 1;
		int hp = 0;			//�̗�
		int hpmax = 0;		//�����̗͍̑ő�l
		int mana = 0;		//���_��
		int manamax = 0;	//�����̐��_�͍ő�l
		int atk = 0;		//�U����
		int atkmax = 0;		//�����̍U���̍ő�l
		int def = 0;		//�h���
		int defmax = 0;		//�����̖h��͂̍ő�l
		int matk = 0;		//���@��
		int matkmax = 0;	//�����̖��@�͂̍ő�l
		int mdef = 0;		//���h��
		int mdefmax = 0;	//�����̖��h�͂̍ő�l
		int choicejob = NON;//�I�������E��
		bool deathflag = false;	//���S�������ǂ���
	};

	//�X�L���̌��ʂƃ^�[��
	struct BUFFTURN {
		//����
		int buffturn[SKILL_RECORD_TURN];
		bool buffendflag[SKILL_RECORD_FLAG];
		//�P�̃X�L���̃o�t
		int buffupefect[SIMPLESUBSTANCESKILL_BUFFUP_NUMBER][SIMPLESUBSTANCESKILL_RECORD_TURN];	//�X�L���̌��ʂŏオ�����X�e�[�^�X(��ŏオ�����X�e�[�^�X����������߂̂���)
		int buffdownefect[SIMPLESUBSTANCESKILL_BUFFDOWN_NUMBER][SIMPLESUBSTANCESKILL_RECORD_TURN];	//�X�L���̌��ʂŉ��������X�e�[�^�X(��ŉ��������X�e�[�^�X���瑫�����߂̂���)
		//�S�̃X�L���̃o�t
		int attackerbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];	//�X�L���̌��ʂŏオ�����X�e(���m)
		int shieldbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//�X�L���̌��ʂŏオ�����X�e(�R�m)
		int magicbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//�X�L���̌��ʂŏオ�����X�e(���p�t)
		int healerbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//�X�L���̌��ʂŏオ�����X�e(���E��)
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
	const int attackerdamageS = 47;		//���m�́`�_���[�W�^����(����)
	const int shielddamageS = 48;		//���m�́`�_���[�W�^����(����)
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
	const int choiceplS = 84;			//�ǂ̃L������I�����܂���(����)
	const int buffendS = 85;			//�o�t�̌��ʏ������C���F�������Ƃ�m�点�鏈��(����)
	const int buffend2S = 86;			//�o�t�̌��ʏ������C���F�������Ƃ�m�点�鏈��(����)
	const int coverS = 87;				//�^�Q�W�����g�������ɏo��\�L(����)
	const int insteadS = 88;			//�g����X�L�����g�������ɏo��\�L(����)
	const int playertrunI = 99;			//PLTURN(�摜)�������\��
	const int bossturnI = 100;			//BSTURN(�摜)�������\��

	//�p�[�Z���g�v�Z(�萔)
	const int tenpercent = 10;			//1��(10%)
	const int twentypercent = 20;		//2��(20%)
	const int thirtypercent = 30;		//3��(30%)
	const int fortypercent = 40;		//4��(40%)
	const int fiftypercent = 50;		//5��(50%)
	const int sixtypercent = 60;		//6��(60%)
	const int seventypercent = 70;		//7��(70%)
	const int eightypercent = 80;		//8��(80%)
	const int ninetypercent = 90;		//9��(90%)
	const int hundredpercent = 100;		//10��(100%)

	//�萔
	const int backdepth = 1;		//���s(���)
	const int middledepth = 2;		//���s(�^��)
	const int prevdepth = 3;		//���s(�O)
	const int onece = 4;			//��Ԏ�O
	const int manarecovery = 5;		//���E�҃X�L���P�̃}�i��n����
	const int continuity_few = 3;	//�h�炷�����Ȃ��ق�(�h�ꂪ���Ȃ�)
	const int continuity_many = 6;	//�h�炷�������ق�(�h�ꂪ�傫��)
	const int moverange = 20;		//�ړ�������l
	const int fontsizeS = 20;		//�����̑傫��(S�T�C�Y)
	const int fontsizeM = 30;		//�����̑傫��(M�T�C�Y)
	const int fontsizeL = 40;		//�����̑傫��(L�T�C�Y)
	const int fontsizeXL = 50;		//�����̑傫��(XL�T�C�Y)
	const int flamemin = 0;			//�t���[���̍ŏ��l
	const int flame15 = 15;			//�t���[����15
	const int flame30 = 30;			//�t���[����15
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
	const int flame280 = 280;		//�t���[����280
	const int flame310 = 310;		//�t���[����310
	const int flame340 = 340;		//�t���[����340
	const int flamemax = 500;		//�t���[���̍ő�l(500)
	const int hpmin = 0;			//HP�̍ŏ��l
	const int rndmin = 0;			//�����_���̍ŏ��l
	const int rndmax = 100;			//�����_���̍ő�l
	const int colordown = 150;		//�Â�����
	const int colormin = 0;			//�F�ŏ��l
	const int colormax = 255;		//�F�ő�l
	const int opacitymin = 0;		//�����x�̍ŏ��l
	const int opacitymax = 255;		//�����x�̍ő�l
	const int recoverylittlemin = 20;	//���E�҃X�L��4�̉񕜂̍ŏ��l
	const int recoverylittlemax = 35;	//���E�҃X�L��4�̉񕜂̍ő�l
	const int recoverylargemin = 75;	//���E�҃X�L��5�̉񕜂̍ŏ��l
	const int recoverylargemax = 90;	//���E�҃X�L��5�̉񕜂̍ő�l
	const int recoverymediummin = 35;	//���E�҃X�L��6�̉񕜂̍ŏ��l
	const int recoverymediummax = 50;	//���E�҃X�L��6�̉񕜂̍ő�l
	const int recoveryall = 255;		//���E�҃X�L��7�̉񕜂̒l
	const float skilluplittle = 0.75f;	//�X�L���{����(0.75�{)
	const float skilluplittlemedium = 1.15f;//�X�L���{������(1.15�{)
	const float skillupmedium = 1.2f;	//�X�L���{����(1.2�{)
	const float skilluplarge = 1.5f;	//�X�L���{����(1.5�{)
	const float buffuplittle = 0.05f;	//�X�e�[�^�X�A�b�v�{����(0.05�{)
	const float buffdownlittle = 0.25f;	//�X�e�\�^�X�_�E���{����(0.25�{)
	const float buffdownlarge = 0.5f;	//�X�e�\�^�X�_�E���{����(0.5�{)
	const float recoveryattackerskill = 0.3f;//���m�̃X�L���̉񕜔{����(0.3�{)
	const float recoverymedium = 0.4f;	//�񕜔{����(0.4�{)
	
	//�ϐ�
	int buffup_value[BUFFUP_RECORD_VALUE_NUMBER];		//�X�e�[�^�X�㏸(atk��matk�܂���def��mdef)
	int buffdown_value[BUFFDOWN_RECORD_VALUE_NUMBER];	//�X�e�[�^�X���~(atk��matk�܂���def��mdef)
	int attackerbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//�o�t�̌v�Z��������ɐ��l������Ƃ���(���m)
	int shieldbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//�o�t�̌v�Z��������ɐ��l������Ƃ���(�R�m)
	int magicbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//�o�t�̌v�Z��������ɐ��l������Ƃ���(���p�t)
	int healerbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//�o�t�̌v�Z��������ɐ��l������Ƃ���(���E��)
	int battleturn = 0;			//�^�[����
	int actcnt = 0;				//�{�X�̓�����
	int bsskillrecovery = 0;	//�{�X�X�L��4�̉񕜂̗�
	int hpcut = 0;				//�v�Z������̃_���[�W
	int	recovery = 0;			//�񕜗�
	int opacity = 255;			//�����x
	int rnd = random();			//�ő�l�܂ł̗������擾
	int act_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
	int pick_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
	int skill_rnd = rndmin;		//�w�肵���͈͓��̗������擾(�X�L��)
	int decide_rnd = rndmin;	//�w�肵���͈͓��̗������擾(�{�X�̓���)
	int recovery_rnd = rndmin;	//�w�肵���͈͓��̗������擾(�񕜂���l)
	float movecnt = 0.05f;		//�摜�𓮂�������
	float attacker_hpgauge_width = 0.0f;	//���mHP�Q�[�W�̉��̃T�C�Y
	float attacker_mngauge_width = 0.0f;	//���mMN�Q�[�W�̉��̃T�C�Y
	float shield_hpgauge_width = 0.0f;		//�R�mHP�Q�[�W�̉��̃T�C�Y
	float shield_mngauge_width = 0.0f;		//�R�mMN�Q�[�W�̉��̃T�C�Y
	float magic_hpgauge_width = 0.0f;		//���p�tHP�Q�[�W�̉��̃T�C�Y
	float magic_mngauge_width = 0.0f;		//���p�tMN�Q�[�W�̉��̃T�C�Y
	float healer_hpgauge_width = 0.0f;		//���E��HP�Q�[�W�̉��̃T�C�Y
	float healer_mngauge_width = 0.0f;		//���E��MN�Q�[�W�̉��̃T�C�Y
	float boss_hpgauge_width = 0.0f;		//�{�XHP�Q�[�W�̉��̃T�C�Y
	bool coverflag[2];						//�{�X�̂����W��
	bool attacker_defenceflag = false;		//�h�䂵�Ă��邩�ǂ���(���m)
	bool shield_defenceflag = false;		//�h�䂵�Ă��邩�ǂ���(�R�m)
	bool magic_defenceflag = false;			//�h�䂵�Ă��邩�ǂ���(���p�t)
	bool healer_defenceflag = false;		//�h�䂵�Ă��邩�ǂ���(���E��)
	bool flag = false;						//�{�X�̏��
	bool state = false;						//�v���C���[�̏��
	bool push_buttonflag = false;			//�{�^���������邩�ǂ���
	bool insteadflag = false;				//�R�m�̃X�L���Őg�����Ԃ��ǂ���
	bool allinsteadflag = false;			//�R�m�X�L���őS���̐g�����Ԃ��ǂ���
	bool resurrectionflag = false;			//�R�m�����t���O
	bool counter_attackflag = false;		//�R�m�J�E���^�[�t���O
	bool attackendflag = false;				//�U�����I��������ǂ���
	bool skillendflag = false;				//�X�L�����I��������ǂ���
	bool choiceendflag = false;				//�I�����I��������ǂ���
	bool fntflag = false;					//�t�H���g�̏����鎞��
	bool allworkendflag = false;			//���ׂĂ̍�Ƃ��I���������ǂ���
	bool boss_allwork_endflag = false;		//�{�X�̂��ׂ����̍�Ƃ��I��������
	bool shield_choice_skillflag = false;	//�I���n�X�L���̎��ق��̐E�Ƃ̑I���X�L���ƌ����Ȃ��l�ɂ����߂̂���(�R�m)
	bool magic_choice_skillflag = false;	//�I���n�X�L���̎��ق��̐E�Ƃ̑I���X�L���ƌ����Ȃ��l�ɂ����߂̂���(���p�t)
	bool healer_choice_skillflag = false;	//�I���n�X�L���̎��ق��̐E�Ƃ̑I���X�L���ƌ����Ȃ��l�ɂ����߂̂���(���E��)
	bool allchoice_endflag = false;			//���ׂĂ̑I�����I�������ǂ�����
	long gameflame = 0;						//���ꂼ��̃^�[���̎���
	long skillflame = 0;					//���ꂼ��̃X�L���̎���
	long choicetime = 0;					//�{�^����A�����ĉ����Ȃ��悤�ɂ��鏈��

	//�X�L���֘A
	bool askill2_allworkendflag = false;//���m�̃X�L��2�̏������S���I����������ׂ鏈��
	bool askill4_allworkendflag = false;//���m�̃X�L��4�̏������S���I����������ׂ鏈��
	bool askill7allworkendflag = false;//���m�̃X�L��7�̏������S���I����������ׂ鏈��
	bool askill8allworkendflag = false;//���m�̃X�L��8�̏������S���I����������ׂ鏈��
	bool sskill2allworkendflag = false;//�R�m�̃X�L��2�̏������S���I����������ׂ鏈��
	bool sskill3allworkendflag = false;//�R�m�̃X�L��3�̏������S���I����������ׂ鏈��
	bool sskill4allworkendflag = false;//�R�m�̃X�L��4�̏������S���I����������ׂ鏈��
	bool sskill5allworkendflag = false;//�R�m�̃X�L��5�̏������S���I����������ׂ鏈��
	bool sskill6allworkendflag = false;//�R�m�̃X�L��7�̏������S���I����������ׂ鏈��
	bool sskill7allworkendflag = false;//�R�m�̃X�L��7�̏������S���I����������ׂ鏈��
	bool sskill8allworkendflag = false;//�R�m�̃X�L��8�̏������S���I����������ׂ鏈��
	bool mskill2allworkendflag = false;//���p�t�̃X�L��2�̏������S���I����������ׂ鏈��
	bool mskill3allworkendflag = false;//���p�t�̃X�L��3�̏������S���I����������ׂ鏈��
	bool mskill5allworkendflag = false;//���p�t�̃X�L��5�̏������S���I����������ׂ鏈��
	bool mskill6allworkendflag = false;//���p�t�̃X�L��6�̏������S���I����������ׂ鏈��
	bool hskill2allworkendflag = false;//���E�҂̃X�L��2�̏������S���I����������ׂ鏈��
	bool hskill3allworkendflag = false;//���E�҂̃X�L��3�̏������S���I����������ׂ鏈��
	bool vskill3allworkendflag = false;//���@���L�����|�̃X�L��3�̏������S���I����������ׂ鏈��

	//enum
	TURN turn;				//�^�[��
	JOB job;				//�L�����̐E��
	JOB sskillchoice;		//�R�m�̃X�L���őI�������L����
	JOB mskillchoice;		//���p�t�̃X�L���őI�������L����
	JOB hskillchoice;		//���E�҂̃X�L���őI�������L����
	BATTLE battle;			//�o�g��
	BUFFT bufft;			//�o�t�̃^�[���Ɋւ�����
	BSACT bsact;			//�{�X�̓���
	CHOICES choices;		//�I��
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	ATTAKERSKILL askill;	//�A�^�b�J�[�X�L��
	SHIELDSKILL sskill;		//�V�[���_�[�X�L��
	HEALERSKILL hskill;		//�q�[���[�X�L��
	MAZICSKILL mskill;		//�}�W�b�N�X�L��
	BOSSSKILLS bskill;		//�{�X�X�L��
	//struct
	//�L�����̃X�e�[�^�X
	FRAME pl1frame;			//�L�����g1
	FRAME pl2frame;			//�L�����g2
	FRAME pl3frame;			//�L�����g3
	FRAME excludeframe;		//���O�g
	FRAME attacker;			//���m
	FRAME shield;			//�R�m
	FRAME magic;			//���p�t
	FRAME healer;			//���E��
	FRAME valkyrie;			//���@���L���[
	//�X�L���̌��ʃ^�[��
	BUFFTURN askill2;		//���m�̃X�L��2(�A�[�}�[�u���C�N)
	BUFFTURN askill4;		//���m�̃X�L��4(�C���p�N�g�X���b�V��)
	BUFFTURN askill7;		//���m�̃X�L��7(�R���f�B�N�V����)
	BUFFTURN askill8;		//���m�̃X�L��8(�E�H���A�[�E�H�[�N���C)
	BUFFTURN sskill2;		//�R�m�̃X�L��2(�J�E���^�[)
	BUFFTURN sskill3;		//�R�m�̃X�L��3(�őO��)
	BUFFTURN sskill4;		//�R�m�̃X�L��4(�g����̕X��)
	BUFFTURN sskill5;		//�R�m�̃X�L��5(�Q���X��)
	BUFFTURN sskill6;		//�R�m�̃X�L��6(�ە�����Y����)
	BUFFTURN sskill7;		//�R�m�̃X�L��7(�X�̌��)
	BUFFTURN sskill8;		//�R�m�̃X�L��8(�R�m������)
	BUFFTURN mskill2;		//���p�t�̃X�L��2(�A�[�}�[�V���b�g)
	BUFFTURN mskill3;		//���p�t�̃X�L��3(�}�W�b�N�o�[�X�g)
	BUFFTURN mskill5;		//���p�t�̃X�L��5(�O�����c)
	BUFFTURN mskill6;		//���p�t�̃X�L��6(�_�̌䌕)
	BUFFTURN hskill2;		//���E�҂̃X�L��2(���҂̌o�T)
	BUFFTURN hskill3;		//���E�҂̃X�L��3(���҂̌o�T)
	BUFFTURN vskill3;		//���@���L�����|�̃X�L��3(�Z��̐w)
	//cocos2d-x
	cocos2d::Vec2 HPbar;					//HP�΁[�̒���
	cocos2d::Vec2 MNbar;					//MANA�΁[�̒���
	CCSize rightSize;						//�I�u�W�F�N�g��z�u����Ƃ��ɕK�v
	CCSprite * BACK_GRAND_SPRITE_BOSS;		//�w�i
	CCSprite *UI_BOSSSCENE_TELOP;			//�e���b�v
	CCSprite *plturn;						//PLTURN����(�����\��)
	CCSprite *emturn;						//BSTURN����(�����\��)
	CCSprite *UI_PUSH_BEFORE_ATTACKBUTTON;	//�U���R�}���h
	CCSprite *UI_PUSH_AFTER_ATTACKBUTTON;	//�U���R�}���h(�����Ă���Ƃ�)
	CCSprite *UI_PUSH_BEFORE_SKILLBUTTON;	//�X�L���R�}���h
	CCSprite *UI_PUSH_AFTER_SKILLBUTTON;	//�X�L���R�}���h(�����Ă���Ƃ�)
	CCSprite *UI_PUSH_BEFORE_DEFENCEBUTTON;	//�h��R�}���h
	CCSprite *UI_PUSH_AFTER_DEFENCEBUTTON;	//�h��R�}���h(�����Ă���Ƃ�)
	CCSprite *UI_PUSH_BEFORE_ITEMBUTTON;	//�A�C�e���R�}���h
	CCSprite *UI_PUSH_AFTER_ITEMBUTTON;		//�A�C�e���R�}���h(������Ă���Ƃ�)
	CCSprite *TARGET;						//�^�[�Q�b�g
	LabelTTF *lo;							//���m�͂ǂ�����
	LabelTTF *ls;							//�R�m�͂ǂ�����
	LabelTTF *lw;							//���p�t�͈ȉ���
	LabelTTF *ll;							//���E�҂͂ǂ�����
	LabelTTF *cho;							//�I�𒆂̕���
	//���m��UI
	CCSprite *UI_PL_ATTACKER_STATUSPLATE;	//���m�̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *UI_PL_ATTACKER_HPBAR;			//���m��HP
	CCSprite *UI_PL_ATTACKER_MANABAR;		//���m��MN
	LabelTTF *attackerhpal;					//���m��HP�\�L
	LabelTTF *attackerhpmaxal;				//HP�̍ő�l
	LabelTTF *attackermnal;					//���m��MN�\�L
	LabelTTF *attackermnmaxal;				//MANA�̍ő�l
	LabelTTF *attackerdmf;					//���m�_���[�W�\��
	CCFadeOut *attackerfadeout;				//���m�_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *attackerfdoutmov;			//���m�_���[�W�\���t�F�[�h�A�E�g���̓���
	 //�R�m��UI
	CCSprite *UI_PL_SHIELD_STATUSPLATE;		//�R�m�̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *UI_PL_SHIELD_HPBAR;			//�R�m��HP
	CCSprite *UI_PL_SHIELD_MANABAR;			//�R�m��MN
	LabelTTF *shieldhpal;					//�R�m��HP�\�L
	LabelTTF *shieldhpmaxal;				//HP�̍ő�l
	LabelTTF *shieldmnal;					//�R�m��MN�\�L
	LabelTTF *shieldmnmaxal;				//MANA�̍ő�l
	LabelTTF *shielddmf;					//�R�m�_���[�W�\��
	CCFadeOut *shieldfadeout;				//�R�m�_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *shieldfdoutmov;				//�R�m�_���[�W�\���t�F�[�h�A�E�g���̓���
	//���p�t��UI
	CCSprite *UI_PL_MAGIC_STATUSPLATE;		//���p�t�̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *UI_PL_MAGIC_HPBAR;			//���p�t��HP
	CCSprite *UI_PL_MAGIC_MANABAR;			//���p�t��MN
	LabelTTF *magichpal;					//���p�t��HP�\�L
	LabelTTF *magichpmaxal;					//HP�̍ő�l
	LabelTTF *magicmnal;					//���p�t��MN�\�L
	LabelTTF *magicmnmaxal;					//MANA�̍ő�l
	LabelTTF *magicdmf;						//���p�t�_���[�W�\��
	CCFadeOut *magicfadeout;				//���p�t�_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *magicfdoutmov;				//���p�t�_���[�W�\���t�F�[�h�A�E�g���̓���
	//���E�҂�UI
	CCSprite *UI_PL_HEALER_STATUSPLATE;		//���E�҂̑�܂��ȃX�e�[�^�X�v���[�g
	CCSprite *UI_PL_HEALER_HPBAR;			//���E�҂�HP
	CCSprite *UI_PL_HEALER_MANABAR;			//���E�҂�MN
	LabelTTF *healerhpal;					//���E�҂�HP�\�L
	LabelTTF *healerhpmaxal;				//HP�̍ő�l
	LabelTTF *healermnal;					//���E�҂�MN�\�L
	LabelTTF *healermnmaxal;				//MANA�̍ő�l
	LabelTTF *healerdmf;					//���E�҃_���[�W�\��
	CCFadeOut *healerfadeout;				//���E�҃_���[�W�\���t�F�[�h�A�E�g�̎���
	CCSequence *healerfdoutmov;				//���E�҃_���[�W�\���t�F�[�h�A�E�g���̓���
	//�{�X��UI
	CCSprite *BOSS_VALKYRIE;				//���@���L�����|
	CCSprite *Efect;						//�p�[�e�B�N��
	CCSprite *UI_BOSS_HPBAR;				//�{�X��hp
	CCSprite *UI_BOSS_BACK_HPBAR;			//�{�X��hp�̌��
	Repeat *bossrepeat;						//�{�X���_���[�W���󂯂����ɗh�炷����
	//�G����_���[�W���󂯂����̗h��̑傫��
	Repeat* attacker_repeat_bigquake[7];	//���m��UI��h�炷����(�h�炷�����傫��)	
	Repeat* attacker_repeat_smallquake[7];	//���m��UI��h�炷����(�h�炷����������)	
	Repeat* shield_repeat_bigquake[7];		//�R�m��UI��h�炷����(�h�炷�����傫��)	
	Repeat* shield_repeat_smallquake[7];	//�R�m��UI��h�炷����(�h�炷����������)	
	Repeat* magic_repeat_bigquake[7];		//���p�t��UI��h�炷����(�h�炷�����傫��)	
	Repeat* magic_repeat_smallquake[7];		//���p�t��UI��h�炷����(�h�炷����������)	
	Repeat* healaer_repeat_smallquake[7];	//���E�҂�UI��h�炷����(�h�炷�����傫��)	
	Repeat* healaer_repeat_bigquake[7];		//���E�҂�UI��h�炷����(�h�炷����������)	

	Size winSize = Director::getInstance()->getWinSize();

	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//������
	virtual void update(float flame);	//���C��
	void PLturn();				//�v���C���[�̃^�[��
	void Plattacks();			//�v���C���[�̒ʏ�U��
	void Plskills();			//�v���C���[�̃X�L��
	void Pldefence();			//�v���C���[�̖h��
	void BSturn();				//�{�X�̃^�[��
	void DamageSway();			//�_���[�W���󂯂����ɗh�炷�֐�
	void Skillturn();			//�X�L���̌��ʂ��؂ꂽ���ǂ����𔻒f���邽�߂̊֐�
	void Pick();				//�_���v���C���[�����߂�֐�
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