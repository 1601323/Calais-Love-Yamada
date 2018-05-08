#ifndef __Screen__FightScene__
#define __Screen__FightScene__

#include "cocos2d.h"

USING_NS_CC;

class HpBar;

class FightScene :public cocos2d::Layer
{
private:

	Sprite* enemySprite;	//敵の画像
	Vec2 touchLocation;		//タッチ座標
	Rect enemySpriteRect;	//敵の画像のRect
	Rect enemyHpRect;		//敵のHpバーのRect
	unsigned int enemyHpNow;			//敵の残りHp
	unsigned int enemyHpMax;			//敵のHpの上限

	Sprite* hpGageSprite_green;
	Sprite* hpGageSprite_red;
	HpBar* bar;
	Sprite* blueSquare;

	// タッチされた瞬間に呼び出される
	virtual bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// スワイプ中に呼び出される
	virtual void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);
	// 画面から指が離された瞬間に呼び出される
	virtual void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	
	//毎フレーム呼び出されるアップデート
	void update(float delta);


public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(FightScene);

	void FightBackGroudn();


	FightScene();
	~FightScene();


	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif //Select