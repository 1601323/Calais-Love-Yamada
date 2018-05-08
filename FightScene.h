#ifndef __Screen__FightScene__
#define __Screen__FightScene__

#include "cocos2d.h"

USING_NS_CC;

class HpBar;

class FightScene :public cocos2d::Layer
{
private:

	Sprite* enemySprite;	//�G�̉摜
	Vec2 touchLocation;		//�^�b�`���W
	Rect enemySpriteRect;	//�G�̉摜��Rect
	Rect enemyHpRect;		//�G��Hp�o�[��Rect
	unsigned int enemyHpNow;			//�G�̎c��Hp
	unsigned int enemyHpMax;			//�G��Hp�̏��

	Sprite* hpGageSprite_green;
	Sprite* hpGageSprite_red;
	HpBar* bar;
	Sprite* blueSquare;

	// �^�b�`���ꂽ�u�ԂɌĂяo�����
	virtual bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// �X���C�v���ɌĂяo�����
	virtual void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);
	// ��ʂ���w�������ꂽ�u�ԂɌĂяo�����
	virtual void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	
	//���t���[���Ăяo�����A�b�v�f�[�g
	void update(float delta);


public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(FightScene);

	void FightBackGroudn();


	FightScene();
	~FightScene();


	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif //Select