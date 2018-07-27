#include "cocos2d.h"


//�G�g�Z�g��-----------------------------------------------------------------------------------------------------
const unsigned int INIT_GIVE_DAMAGE = 50;			//�G�֗^����_���[�W�̏����l
const unsigned int DAMAGE_DISPLAY_DURATION = 100;	//�^�����_���[�W�̐��l�̕\������
const unsigned int EXP = 10;						//�l���o���l
const unsigned int NEXT_BATTLE_TIMER = 180;			//���ׂĂ̎G���G������Ŏ��̃o�g�����n�܂�܂ł̃^�C�}�[
const unsigned int BATTLE_MAX = 6;					//�ő�o�g����
const unsigned int GIVE_ENEMY_DAMAGE_FONT_SIZE = 40;//�G�ւ̃_���[�W�\�L�p���x���̃t�H���g�T�C�Y
const unsigned int EXP_LABEL_FONT_SIZE = 70;		//EXP���x���̃t�H���g�T�C�Y
const float CHANGE_FIGHT_SCENE_TO_BOSS_SCENE_DURATION = 0.6f;	//���b������FightScene����BossScene�֑J�ڂ��邩

const float TOUCH_SPRITE_HITBOX_OFFSET = 50.f;

//�G-------------------------------------------------------------------------------------------------------------
const unsigned int ENEMY_HP_MAX = 300;				//�G��HP�̏���l
const float ENEMY_DISPLAY_UNTIL_TIME = 1.5f;		//���̃o�g���ɑJ�ڂ��ēG���o������܂ł̎���
const float ENEMY_FADEIN_DURATION = 0.5f;			//�G�����b�����ăt�F�[�h�C�����Č���邩

//�G��Hp�Q�[�W---------------------------------------------------------------------------------------------------
const float BACK_GAGE_DISPLAY_INTERVAL_TIME = ENEMY_DISPLAY_UNTIL_TIME + 0.2f;	//�o�b�N�Q�[�W���\�������܂ł̑ҋ@����
const float BLUE_GAGE_DISPLAY_INTERVAL_TIME = ENEMY_DISPLAY_UNTIL_TIME;	//�Q�[�W���\�������܂ł̑ҋ@����

const float BACK_GAGE_FADE_IN_DURATION = 0.3f;		//���b�����ăo�b�N�Q�[�W�̃t�F�[�h�C�����s����
const float BACK_GAGE_FADE_OUT_DURATION = 0.3f;		//���b�����ăo�b�N�Q�[�W�̃t�F�[�h�A�E�g���s����

const float BLUE_GAGE__FADE_IN_DURATION = 0.5f;		//���b������Hp�Q�[�W�̃t�F�[�h�C�����s����
const float BULE_GAGE_FADE_OUT_DURATION = 0.3f;		//���b������Hp�Q�[�W�̃t�F�[�h�A�E�g���s����
/* ���ԃQ�[�W�Ɠ������Ԃɐݒ肵�Ă��܂��ƁA�t�F�[�h�C�����̃Q�[�W�̐F�������ςȊ����ɂȂ�̂ŁA
     �Q�[�W�̕����\�������܂ł̑ҋ@���Ԃ��Z���ݒ肵�Ă���*/

//HP�֌W---------------------------------------------------------------------------------------------------------
const unsigned int HP_GAGE_SIZE_WIDTH = 300;		//HP�Q�[�W�̉��T�C�Y
const unsigned int HP_GAGE_SIZE_HEIGHT = 10;		//HP�Q�[�W�̏c�T�C�Y

//�o�g�����x��(BL)�֌W-------------------------------------------------------------------------------------------
const unsigned int BATTLE_LABEL_FONT_SIZE = 60;		//�t�H���g�T�C�Y
const float BL_FADE_IN_DURATION = 0.3f;				//���b�����ăo�g�����x���̃t�F�[�h�C�����s����
const float BL_FADE_OUT_DURATION = 0.3f;			//���b�����ăo�g�����x���̃t�F�[�h�A�E�g���s����
///const Vec2 OTHER_BL_POS(400.f, 820.f);�@�����̓z��Vec2�ł܂Ƃ߂����������ǁA�������ē�����炸����XY���ꂼ��ɕ������B��ł�邩��	
const float OTHER_BL_POS_X = 400.f;					//�o�g���P�`�T�̃��x���̈ʒu
const float OTHER_BL_POS_Y = 820.f;
///const Vec2 FINAL_BL_POS(290.f, 820.f);			
const float FINAL_BL_POS_X = 290.f;					//�ŏI�o�g�����x���̈ʒu
const float FINAL_BL_POS_Y = 820.f;

//�o�g���i���o�[���x��(BNL)�֌W--------------------------------------------------------------------------------
const unsigned int BNL_FONT_SIZE = 80;				//�t�H���g�T�C�Y
const float BNL_FADE_IN_DURATION = 0.3f;			//���b�����ă��x���̃t�F�[�h�C�����s����
const float BNL_FADE_OUT_DURATION = 0.3f;			//���b�����ă��x���̃t�F�[�h�C�����s����
///const Vec2 OTHER_BNL_POS(570.f, 780.f);	
const float OTHER_BNL_POS_X = 570.f;				//�o�g���P�`�T�̃��x���̈ʒu
const float OTHER_BNL_POS_Y = 780.f;
///const Vec2 FINAL_BNL_POS(510.f, 780.f);			
const float FINAL_BNL_POS_X = 510.f;				//�ŏI�o�g���̃��x���̈ʒu
const float FINAL_BNL_POS_Y = 780.f;

//�o�g���A�i�E���X���x���S�́iBAL�j----------------------------------------------------------------------------
const float BAL_SLIDE_UP_DURATION = 0.3f;			//���b�����ă��x������ֈړ����邩
const float BAL_SLIDE_DOWN_DURATION = 0.3f;			//���b�����ă��x�������ֈړ����邩
const float BAL_DISPLAY_TIME = 0.7f;				//�\�����ԁi�X���C�h����鎞�Ԃ������j
///const Vec2 BAL_SLIDE_UP_VOLUME(0.f, 20.f);			
const float BAL_SLIDE_UP_VOLUME = 20.f;				//���x������փX���C�h�ۂ̈ړ���
///const Vec2 BAL_SLIDE_DOWN_VOLUME(0.f, -20.f);		
const float BAL_SLIDE_DOWN_VOLUME = -20.f;			//���x�������փX���C�h�ۂ̈ړ���

//��ʏ㕔�̃A�i�E���X�e���b�v�֌W-----------------------------------------------------------------------------
const int ANNOUNCE_TELOP_FONT_SIZE = 30;			//�t�H���g�T�C�Y
const int TEXT_BOX_OPACITY = 180;					//�w�i�̃e�L�X�g�{�b�N�X�̕s�����x

//�摜�U���֌W-------------------------------------------------------------------------------------------------
const float SPRITE_TREMBLE_SPEED = 0.05f;			//�摜���U������ۂ̈�񓖂���̈ړ�����
const float SPRITE_DEFLECTION_WIDTH = 30;			//�U�ꕝ

//�摜�������h���z---------------------------------------------------------------------------------------
const float SPRITE_SWAY_SPEED = 3.f;				//�h���X�s�[�h
const float SPRITE_SWAY_DEFLECTION_WIDTH = 20.f;	//�U�ꕝ

//�\���e���b�v�̓��e--------------------------------------------------------------------------------------------


//���\�[�X�p�X-------------------------------------------------------------------------------------------------
const std::string BACK_GRAND_SPRITE_PATH = "ST_Colosseum.png";	//�����w�i
const std::string DAMAGE_LABEL_FONT_PATH = "fonts/SHOWG.TTF";	//�_���[�W���x���t�H���g
const std::string HIT_LABEL_FONT_PATH = "fonts/SHOWG.TTF";		//�q�b�g���x���t�H���g
const std::string BAL_FONT_PATH = "fonts/COPRGTB.TTF";			//�o�g���A�i�E���X���x���t�H���g
const std::string EXP_LABEL_FONT_PATH = "fonts/SHOWG.TTF";		//EXP���x���t�H���g
const std::string ANNOUNCE_TELOP_LABEL_FONT_PATH = "fonts/HGRSGU.TTC";


const std::string FIELD_ENEMY_FOLDER_PATH = "enemy/FieldEnemy/"; 

const std::string BOSS_BUTTON_PATH = "UI/boss.png";
const std::string PUSH_BOSS_BUTTON_PATH = "UI/boss_push.png";
const std::string YES_BUTTON_PATH = "UI/yes.png";
const std::string PUSH_YES_BUTTON_PATH = "UI/yes_push.png";
const std::string NO_BUTTON_PATH = "UI/no.png";
const std::string PUSH_NO_BUTTON_PATH = "UI/no_push.png";
