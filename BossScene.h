#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:


	//キャラ枠のステータス
	struct FRAME{
		int hp;			//体力
		int hpmax;		//初期の体力最大値
		int mana;		//精神力
		int manamax;	//初期の精神力最大値
		int atk;		//攻撃力
		int atkmax;		//初期の攻撃の最大値
		int def;		//防御力
		int defmax;		//初期の防御力の最大値
		int matk;		//魔法力
		int matkmax;	//初期の魔法力の最大値
		int mdef;		//魔防力
		int mdefmax;	//初期の魔防力の最大値
		int choicejob;	//選択した職業
	};

	struct CHAR {
		int hp;			//体力
		int hpmax;		//初期の体力最大値
		int mana;		//精神力
		int manamax;	//初期の精神力最大値
		int atk;		//攻撃力
		int atkmax;		//初期の攻撃の最大値
		int def;		//防御力
		int defmax;		//初期の防御力の最大値
		int matk;		//魔法力
		int matkmax;	//初期の魔法力の最大値
		int mdef;		//魔防力
		int mdefmax;	//初期の魔防力の最大値
		int choicejob;	//選択した職業
	};



	//ターンの処理
	enum TURN{
		PLAYER,			//プレイヤーのターン
		BOSS,			//敵のターン
	};

	//とりあえずプレイヤーを増やします
	enum JOB {
		NON,			//何も選択されていない
		ATTACKER,		//剣士
		SHIELD,			//騎士
		MAGIC,			//魔術師
		HEALER,			//聖職者
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
		CHAR1,			//キャラ枠1
		CHAR2,			//キャラ枠2
		CHAR3,			//キャラ枠3
	};

	enum PL1 {
		PL1NON,			//何もしない
		PL1ATTACK,		//攻撃
		PL1SKILL,		//スキル
		PL1DEATH,		//死亡状態
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

	//どのスキルを使うかを決めるときに使う
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
		BOSSATTACK,		//攻撃
		BOSSSKILL			//スキル
	};

	//ボスのスキル
	enum BOSSSKILLS{
		BSKILL1,		//一の太刀
		BSKILL2,		//二の太刀
		BSKILL3,		//六帝の陣
		BSKILL4,		//エステ
	};

	//タグ(定数)
	const int normalattackS = 1;		//通常攻撃(文章)
	const int damageS = 2;				//～ダメージ与えた(文章)
	const int bossskill1S = 3;			//ボスのスキル1(文章)
	const int bossskill1damageS = 4;	//ボスのスキル1ダメージ(文章)
	const int bossskill2S = 5;			//ボスのスキル2(文章)
	const int bossskill2damageS = 6;	//ボスのスキル2ダメージ(文章)
	const int bossskill3S = 7;			//ボスのスキル3(文章)
	const int bossskill3damageS = 8;	//ボスのスキル3効果(文章)
	const int bossskill4S = 9;			//ボスのスキル4(文章)
	const int bossskill4damageS = 10;	//ボスのスキル4効果(文章)
	const int bossskill1E = 11;			//ボススキル1(エフェクト)タグ11～14
	const int askill1E = 15;			//剣士スキル１(エフェクト)タグ15～22
	const int mskill1E= 23;				//魔術師スキル１(エフェクト)タグ23～30
	const int hskill1E = 31;			//聖職者スキル１(エフェクト)タグ31～38
	const int sskill1E = 39;			//騎士スキル1(エフェクト)タグ39～47
	const int attackerdamageS = 48;		//剣士は～ダメージ与えた(文章)
	const int healerdamageS = 49;		//聖職者は～ダメージ与えた(文章)
	const int magicdamageS = 50;		//魔術師は～ダメージ与えた(文章)
	const int attackbuttonaI = 51;		//押す前の攻撃コマンドボタン(画像)
	const int attackbuttonbI = 52;		//押した後の攻撃コマンドボタン(画像)
	const int skillbuttonaI = 53;		//押す前のスキルコマンドボタン(画像)
	const int skillbuttonbI = 54;		//押した後のスキルコマンドボタン(画像)
	const int choiceS = 80;				//～はどうする(文字)
	const int damage1 = 81;				//ダメージを体力の上に表記
	const int buffupS = 82;				//ステータスが上がったときに表記(文章)
	const int buffdownS = 83;			//ステータスが下がったときに表記(文章)
	const int playertrunI = 99;			//PLTURN(画像)※消す予定
	const int bossturnI = 100;			//BSTURN(画像)※消す予定

	//パーセント計算(定数)
	const int tenpercent = 10;			//1割(10)
	const int twentypercent = 20;		//2割(20)
	const int thirtypercent = 30;		//3割(30)
	const int fortypercent = 40;		//4割(40)
	const int fiftypercent = 50;		//5割(50)
	const int sixtypercent = 60;		//6割(60)
	const int seventypercent = 70;		//7割(70)
	const int eightypercent = 80;		//8割(80)
	const int ninetypercent = 90;		//9割(90)
	const int hundredpercent = 100;		//10割(100)

	//定数
	const int backdepth = 1;		//奥行(後ろ)
	const int middledepth = 2;		//奥行(真ん中)
	const int prevdepth = 3;		//奥行(前)
	const int onece = 4;			//一番手前
	const int continuity1 = 3;		//揺らす回数1
	const int continuity2 = 6;		//揺らす回数2
	const int moverange = 20;		//移動させる値
	const int fontsizeS = 20;		//文字の大きさ(Sサイズ)
	const int fontsizeM = 30;		//文字の大きさ(Mサイズ)
	const int fontsizeL = 40;		//文字の大きさ(Lサイズ)
	const int fontsizeXL = 50;		//文字の大きさ(XLサイズ)
	const int flame15 = 15;			//フレームが15
	const int flame50 = 50;			//フレームが50
	const int flame70 = 70;			//フレームが70
	const int flame80 = 80;			//フレームが80
	const int flame100 = 100;		//フレームが100
	const int flame110 = 110;		//フレームが110
	const int flame130 = 130;		//フレームが130
	const int flame150 = 150;		//フレームが150
	const int flame170 = 170;		//フレームが170
	const int flame200 = 200;		//フレームが200
	const int flame210 = 210;		//フレームが210
	const int flame220 = 220;		//フレームが220
	const int flame230 = 230;		//フレームが230
	const int flame250 = 250;		//フレームが250
	const int flamemax = 350;		//フレームの最大値
	const int hpmin = 0;			//HPの最小値
	const int rndmin = 0;			//ランダムの最小値
	const int rndmax = 100;			//ランダムの最大値
	const int colordown = 150;		//暗くする
	const int colormin = 0;			//色最小値
	const int colormax = 255;		//色最大値
	const int opacitymin = 0;		//透明度の最小値
	const int opacitymax = 255;		//透明度の最大値
	const float skilluplittle = 0.75f;	//スキル倍率小(0.75倍)
	const float skillupmedium = 1.2f;	//スキル倍率中(1.2倍)
	const float skilluplarge = 1.5f;	//スキル倍率大(1.5倍)
	const float buffuplittle = 0.0f;	//ステータスアップ倍率小(0.0倍)
	const float buffupmedium = 0.0f;	//ステータスアップ倍率中(0.0倍)
	const float buffuplarge = 0.0f;		//ステータスアップ倍率大(0.0倍)
	const float buffdownlittle = 0.2f;	//ステ―タスダウン倍率小(0.2倍)
	const float buffdownmedium = 0.5f;	//ステ―タスダウン倍率中(0.5倍)
	const float buffdownlarge = 0.8f;	//ステ―タスダウン倍率大(0.8倍)


	//変数
	int actcnt = 0;				//ボスの動く回数
	int bsskillrecovery = 0;	//ボススキル4の回復の量
	int hpcut = 0;				//計算した後のダメージ
	int buffup = 0;				//ステータス上昇
	int buffdown = 0;			//ステータス下降
	int	recovery = 0;			//回復量
	int opacity = 255;			//透明度
	int rnd = random();			//最大値までの乱数を取得
	int act_rnd = rndmin;		//指定した範囲内の乱数を取得(ボスの動く回数)
	int pick_rnd = rndmin;		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
	int skill_rnd = rndmin;		//指定した範囲内の乱数を取得(スキル)
	int decide_rnd = rndmin;	//指定した範囲内の乱数を取得(ボスの動き)
	float movecnt = 0.05f;		//画像を動かす時間
	float pl1hpgaugewidth = 0.0f;	//プレイヤー1HPゲージの横のサイズ
	float pl1mngaugewidth = 0.0f;	//プレイヤー1MNゲージの横のサイズ
	float pl2hpgaugewidth = 0.0f;	//プレイヤー2HPゲージの横のサイズ
	float pl2mngaugewidth = 0.0f;	//プレイヤー2MNゲージの横のサイズ
	float pl3hpgaugewidth = 0.0f;	//プレイヤー3HPゲージの横のサイズ
	float pl3mngaugewidth = 0.0f;	//プレイヤー3MNゲージの横のサイズ
	float bosshpgaugewidth = 0.0f;	//ボスHPゲージの横のサイズ
	bool flag = false;			//ボスの状態
	bool state = false;			//プレイヤーの状態
	bool attackendflag = false;	//攻撃が終わったかどうか
	bool skillendflag = false;	//スキルが終わったかどうか
	bool fntflag = false;		//フォントの消える時間
	long gameflame = 0;			//それぞれのターンの時間
	long skillflame = 0;		//それぞれのスキルの時間
	long choicetime = 0;		//ボタンを連続して押さないようにする処理

	//enum
	TURN turn;				//ターン
	JOB job;				//キャラの職業
	BATTLE battle;			//バトル
	BSACT bsact;			//ボスの動き
	CHOICES choices;		//選択中
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	SKILL pl1skill;			//どのスキルを使ったかを決める
	SKILL pl2skill;			//どのスキルを使ったかを決める
	SKILL pl3skill;			//どのスキルを使ったかを決める
	ATTAKERSKILL askill;	//アタッカースキル
	SHIELDSKILL sskill;		//シールダースキル
	HEALERSKILL hskill;		//ヒーラースキル
	MAZICSKILL mskill;		//マジックスキル
	BOSSSKILLS bskill;		//ボススキル
	//struct
	FRAME pl1frame;			//キャラ枠1
	FRAME pl2frame;			//キャラ枠2
	FRAME pl3frame;			//キャラ枠3
	CHAR attacker;			//剣士
	CHAR shield;			//騎士
	CHAR magic;				//魔術師
	CHAR healer;			//聖職者
	CHAR valkyrie;			//ヴァルキリー
	//cocos2d-x
	cocos2d::Vec2 HPbar;	//HPばーの長さ
	cocos2d::Vec2 MNbar;	//MANAばーの長さ
	CCSize rightSize;		//オブジェクトを配置するときに必要
	CCSprite *back;			//背景
	CCSprite *plturn;		//PLTURN文字(抹消予定)
	CCSprite *emturn;		//BSTURN文字(抹消予定)
	CCSprite *AttackButton1;//攻撃コマンド
	CCSprite *AttackButton2;//攻撃コマンド(押しているとき)
	CCSprite *SkillButton1;	//スキルコマンド
	CCSprite *SkillButton2;	//スキルコマンド(押しているとき)
	LabelTTF *lo;			//剣士はどうする
	LabelTTF *ll;			//聖職者はどうする
	LabelTTF *lw;			//魔術師は以下略
	//剣士のUI
	CCSprite *PL1p;			//剣士の大まかなステータスプレート
	CCSprite *HPpl1;		//剣士のHP
	CCSprite *MNpl1;		//剣士のMN
	LabelTTF *p1hpal;		//剣士のHP表記
	LabelTTF *p1hpmaxal;	//HPの最大値
	LabelTTF *p1mnal;		//剣士のMN表記
	LabelTTF *p1mnmaxal;	//MANAの最大値
	LabelTTF *dmf1;			//剣士ダメージ表示
	CCFadeOut *fadeout1;	//剣士ダメージ表示フェードアウトの時間
	CCSequence *fdoutmov1;	//剣士ダメージ表示フェードアウト時の動き
	//聖職者のUI
	CCSprite *PL2p;			//聖職者の大まかなステータスプレート
	CCSprite *HPpl2;		//聖職者のHP
	CCSprite *MNpl2;		//聖職者のMN
	LabelTTF *p2hpal;		//聖職者のHP表記
	LabelTTF *p2hpmaxal;	//HPの最大値
	LabelTTF *p2mnal;		//聖職者のMN表記
	LabelTTF *p2mnmaxal;	//MANAの最大値
	LabelTTF *dmf2;			//聖職者ダメージ表示
	CCFadeOut *fadeout2;	//聖職者ダメージ表示フェードアウトの時間
	CCSequence *fdoutmov2;	//聖職者ダメージ表示フェードアウト時の動き
	//魔術師のUI
	CCSprite *PL3p;			//魔術師の大まかなステータスプレート
	CCSprite *HPpl3;		//魔術師のHP
	CCSprite *MNpl3;		//魔術師のMN
	LabelTTF *p3hpal;		//魔術師のHP表記
	LabelTTF *p3hpmaxal;	//HPの最大値
	LabelTTF *p3mnal;		//魔術師のMN表記
	LabelTTF *p3mnmaxal;	//MANAの最大値
	LabelTTF *dmf3;			//魔術師ダメージ表示
	CCFadeOut *fadeout3;	//魔術師ダメージ表示フェードアウトの時間
	CCSequence *fdoutmov3;	//魔術師ダメージ表示フェードアウト時の動き
	//ボスのUI
	CCSprite *Boss;			//ボス
	CCSprite *efect;		//パーティクル
	CCSprite *HPboss;		//ボスのhp
	Repeat *bossrepeat;		//ボスがダメージを受けた時に揺らす処理
	//PL1のUIを揺らす処理(揺らす幅が大きい)	
	Repeat *pl1repeat1a, *pl1repeat2a, *pl1repeat3a, *pl1repeat4a, *pl1repeat5a, *pl1repeat6a, *pl1repeat7a;
	//PL1のUIを揺らす処理(揺らす幅が小さい)	
	Repeat *pl1repeat1b, *pl1repeat2b, *pl1repeat3b, *pl1repeat4b, *pl1repeat5b, *pl1repeat6b, *pl1repeat7b;
	//PL2のUIを揺らす処理(揺らす幅が大きい)	
	Repeat *pl2repeat1a, *pl2repeat2a, *pl2repeat3a, *pl2repeat4a, *pl2repeat5a, *pl2repeat6a, *pl2repeat7a;
	//PL2のUIを揺らす処理(揺らす幅が小さい)	
	Repeat *pl2repeat1b, *pl2repeat2b, *pl2repeat3b, *pl2repeat4b, *pl2repeat5b, *pl2repeat6b, *pl2repeat7b;
	//PL3のUIを揺らす処理(揺らす幅が大きい)	
	Repeat *pl3repeat1a, *pl3repeat2a, *pl3repeat3a, *pl3repeat4a, *pl3repeat5a, *pl3repeat6a, *pl3repeat7a;
	//PL3のUIを揺らす処理(揺らす幅が小さい)	
	Repeat *pl3repeat1b, *pl3repeat2b, *pl3repeat3b, *pl3repeat4b, *pl3repeat5b, *pl3repeat6b, *pl3repeat7b;


	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//初期化
	virtual void update(float flame);	//メイン
	virtual void PLturn();				//プレイヤーのターン
	virtual void Plattacks();			//プレイヤーの通常攻撃
	virtual void Plskills();			//プレイヤーのスキル
	virtual void BSturn();				//ボスのターン
	virtual void Damage();				//ダメージを受けた時の処理
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