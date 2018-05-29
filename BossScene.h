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
	
	TURN turn;							//ターン
	FILE* file;							//ファイル
	CCSprite* Boss;						//ボス
	CCSprite* Tsprite;
	CCSprite* back;						//背景
	CCSprite* Kyara;					//プレイヤー(仮)
	CCSprite* efect;					//パーティクル
	CCSprite* plturn;
	CCSprite* emturn;
	CCSprite* timerfnt;
	CCSize rightSize;
	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//初期化
	virtual void update(float flame);	//メイン
	virtual void BSturn();				//ボスのターン
	virtual void PLturn();				//プレイヤーのターン
	virtual void Timer(float time);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	//タッチ開始
	virtual void onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	//スワイプ
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);	//タッチ終了
	virtual void onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);//キャンセル
	
	CREATE_FUNC(BossScene);

	void BossBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);

};

#endif //Select