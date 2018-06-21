#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:


	//プレイヤーのステータス(仮)
	struct CHARS{
		int hp;			//体力
		int mana;		//精神力
		int atk;		//攻撃力
		int def;		//防御力
		int matk;		//魔法力
		int mdef;		//魔防力
	};

	//ターンの処理
	enum TURN{
		PLAYER,			//プレイヤーのターン
		BOSS,			//敵のターン
	};

	//とりあえずプレイヤーを増やします
	enum JOB {
		NON,			//何も選択されていない
		ATTACKER,		//アタッカー
		HEALER,			//ヒーラー
		MAGIC,			//マジック
		SHIELD,			//シールダー
	};

	//バトル中の処理
	enum BATTLE {
		START,			//戦闘開始
		WAIT,			//待ち状態
		CHOICE,			//選択
		ACTION,			//モーション中
	};

	//選択中
	enum CHOICES {
		CHAR1,			//キャラ枠１
		CHAR2,			//キャラ枠２
		CHAR3,			//キャラ枠3
	};

	enum PL1 {
		PL1ATTACK,		//攻撃
		PL1SKILL,		//スキル
	};

	enum PL2 {
		PL2ATTACK,
		PL2SKILL,
	};
	enum PL3 {
		PL3ATTACK,
		PL3SKILL,
	};

	//剣士
	enum ATTAKERSKILL {
		ASKILL1,		//ツインフルーレ
		ASKILL2,		//アーマーブレイク
		ASKILL3,		//ライフソード
		ASKILL4,		//インパクトスラッシュ
		ASKILL5,		//ソードスルー
		ASKILL6,		//紅蓮剣
		ASKILL7,		//コンディクション
		ASKILL8,		//ウォリアーウォークライ
	};
	//騎士
	enum SHIELDSKILL {
		SSKILL1,		//アインスゾイレ
		SSKILL2,		//カウンター
		SSKILL3,		//最前線
		SSKILL4,		//身代わりの氷像
		SSKILL5,		//群れる氷像
		SSKILL6,		//鼓舞する雄叫び
		SSKILL7,		//氷の御衣
		SSKILL8,		//騎士の矜持
	};
	//魔術師
	enum MAZICSKILL {
		MSKILL1,		//マジックミサイル
		MSKILL2,		//アーマーショット
		MSKILL3,		//マジックバースト
		MSKILL4,		//VFD
		MSKILL5,		//グランツ
		MSKILL6,		//神の御剣
		MSKILL7,		//魔力吸収
		MSKILL8,		//心呼吸
	};
	//聖職者
	enum HEALERSKILL {
		HSKILL1,		//魔力供給
		HSKILL2,		//死者の経典
		HSKILL3,		//聖者の経典
		HSKILL4,		//セイントローグ
		HSKILL5,		//聖闘士ぺーパー
		HSKILL6,		//聖者の祈り
		HSKILL7,		//セイントオーダー
		HSKILL8,		//神の啓示
	};

	//ボスの動き
	enum BSACT {
		PICK,			//攻撃するプレイヤーを選ぶ
		DECIDE,			//動きをきめる
		ATTACK,			//攻撃
		SKILL			//スキル
	};

	//ボスのスキルjob
	enum BOSSSKILLS{
		BSKILL1,		//一の太刀
		BSKILL2,		//二の太刀
		BSKILL3,		//六帝の陣
		BSKILL4,		//エステ
	};

	int Bhp;			//キャラのHP
	int continuity;		//揺らす回数
	int ten;			//10
	int hpcut;			//減らすHP
	int rnd;			//ランダム関数
	int rndmin;			//ランダムの最小値
	int rndmax;			//ランダムの最大値
	int pick_rnd;		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
	int act_rnd;		//指定した範囲内の乱数を取得(ボスの動く回数)
	int decide_rnd;		//指定した範囲内の乱数を取得(ボスの動き)
	int skill_rnd;		//指定した範囲内の乱数を取得(スキル)
	int	depth;			//奥行き
	int timemax;		//時間の最大値
	int actcnt;			//ボスの動く回数
	int fontsize;		//文字の大きさ
	int Color;			//色または暗さ
	int Colormax;		//色最大値
	int Shader;			//シェーダー
	int HPGaugecnt;		//hpゲージをカウントする
	int HPGaugeStopcnt;	//仮
	float HPGaugeWidth;	//HPゲージの横のサイズ
	float movecnt;		//動かす時間
	bool state;			//プレイヤーの状態
	bool flag;			//ボスの状態
	long choicetime;	//ボタンを連続して押さないようにする処理
	long gametime;		//タイム
	long gaugecnt;

	
	//enum
	TURN turn;				//ターン
	JOB job;				//キャラの職業
	BATTLE battle;			//バトル
	BSACT bsact;			//ボスの動き
	CHOICES choices;		//選択中
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	BOSSSKILLS bskill;		//ボススキル
	ATTAKERSKILL askill;	//アタッカースキル
	SHIELDSKILL sskill;		//シールダースキル
	HEALERSKILL hskill;		//ヒーラースキル
	MAZICSKILL mskill;		//マジックスキル
	//struct
	CHARS pl1frame;			//キャラ枠1
	CHARS pl2frame;			//キャラ枠2
	CHARS pl3frame;			//キャラ枠3
	CHARS valkyrie;			//ヴァルキリー
	//cocos2d-x
	cocos2d::Vec2 HPbar;	//HPばーの長さ
	CCSize rightSize;		//オブジェクトを配置するときに必要？
	CCSprite* hp;			//残りHPの確認
	CCSprite* Boss;			//ボス
	CCSprite* back;			//背景
	CCSprite* Kyara;		//プレイヤー(仮)
	CCSprite* efect;		//パーティクル
	CCSprite* plturn;		//PLTURN文字
	CCSprite* emturn;		//BSTURN文字
	CCSprite* AttackButton1;//攻撃コマンド
	CCSprite* AttackButton2;//攻撃コマンド(押しているとき)
	CCSprite* SkillButton1;	//スキルコマンド
	CCSprite* SkillButton2;	//スキルコマンド(押しているとき)
	CCSprite* PL1p;			//プレイヤー1
	CCSprite* PL2p;			//プレイヤー2
	CCSprite* PL3p;			//プレイヤー3
	CCSprite* HPpl1;		//プレイヤー１のHP
	CCSprite* HPBpl1;		//プレイヤー１のHP後ろ

	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//初期化
	virtual void update(float flame);	//メイン
	virtual void PLturn();				//プレイヤーのターン
	virtual void PLSKILLS();			//プレイヤーのスキル
	virtual void BSturn();				//ボスのターン
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	//タッチ開始
	virtual void onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event);		//スワイプ
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);	//タッチ終了
	virtual void onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);	//キャンセル
	
	CREATE_FUNC(BossScene);

	void BossBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);

};

#endif //Select