#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:

	enum TURN{
		PLAYER,
		BOSS,
	};

	enum BSACT {
		ATTACK,
		SKILL,
		DEFENCE
	};

	int Php,Bhp;
	int continuity;
	int ten;
	int hpcut;
	float movecnt;
	bool state;
	bool flag;
	bool Bflag;
	long gametime;
	
	TURN turn;							//�^�[��
	FILE* file;							//�t�@�C��
	CCSprite* Boss;						//�{�X
	CCSprite* Tsprite;
	CCSprite* back;						//�w�i
	CCSprite* Kyara;					//�v���C���[(��)
	CCSprite* efect;					//�p�[�e�B�N��
	CCSprite* plturn;
	CCSprite* emturn;
	CCSprite* timerfnt;
	CCSize rightSize;
	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//������
	virtual void update(float flame);	//���C��
	virtual void BSturn();				//�{�X�̃^�[��
	virtual void PLturn();				//�v���C���[�̃^�[��
	virtual void Timer(float time);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	//�^�b�`�J�n
	virtual void onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	//�X���C�v
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);	//�^�b�`�I��
	virtual void onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);//�L�����Z��
	
	CREATE_FUNC(BossScene);

	void BossBackGroudn();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);

};

#endif //Select