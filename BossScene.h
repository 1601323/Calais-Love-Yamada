#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"
#include <random>

#define BUFFUP_RECORD_VALUE_NUMBER 2			//上昇した値を記録する数
#define BUFFDOWN_RECORD_VALUE_NUMBER 2			//下降した値を記録する数
#define SKILL_RECORD_TURN 6						//スキルのターンを記録する数
#define SKILL_RECORD_FLAG 6						//スキルのフラグ管理を記録する数
#define ALLSKILL_BUFF_NUMBER 4					//全体スキルのバフをかけたステータスの種類
#define ALLSKILL_RECORD_TURN 5					//全体スキルのターン数を記録する数
#define ALLSKILL_BUFF_VALUE_NUMBER 4			//全体スキルの上昇した値の種類
#define SIMPLESUBSTANCESKILL_BUFFUP_NUMBER 2	//単体スキルのバフをかけたステータスの種類
#define SIMPLESUBSTANCESKILL_BUFFDOWN_NUMBER 2	//単体スキルのバフをかけたステータスの種類
#define SIMPLESUBSTANCESKILL_RECORD_TURN 6		//単体スキルのターン数を記録する数


USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:
	//ターンの処理
	enum TURN{
		PLAYER,			//プレイヤーのターン
		BOSS,			//敵のターン
	};

	//職業
	enum JOB {
		NON,			//何も選択されていない
		ATTACKER,		//剣士
		SHIELD,			//騎士
		MAGIC,			//魔術師
		HEALER,			//聖職者
	};
	
	//選択系で職業を選ぶ
	enum SJOB {
		S_ATTACKER,		//剣士
		S_SHIELD,		//騎士
		S_MAGIC,		//魔術師
		S_HEALER,		//聖職者
	};

	//バトル中の処理
	enum BATTLE {
		START,			//戦闘開始
		WAIT,			//スキルなどの効果ターン終了などを表記するところ
		CHOICE,			//選択
		ACTION,			//モーション中
	};

	//選択中
	enum CHOICES {
		CHAR1,			//キャラ枠1
		CHAR2,			//キャラ枠2
		CHAR3,			//キャラ枠3
		CHOICETIME_SHIELD,//スキルによる選択(同じところでしたらif文を通り抜けてタッチをしてしまうから分けておく)
		CHOICETIME_MAGIC,
		CHOICETIME_HEALER,
	};

	//PL1の状態
	enum PL1 {
		PL1NON,			//何もしない
		PL1ATTACK,		//攻撃
		PL1SKILL,		//スキル
		PL1DEFENCE,		//防御
		PL1ITEM,		//アイテム
		PL1DEATH,		//死亡状態
	};
	//PL2の状態
	enum PL2 {
		PL2NON,			
		PL2ATTACK,
		PL2SKILL,
		PL2DEFENCE,	
		PL2ITEM,		
		PL2DEATH,
	};
	//PL3の状態
	enum PL3 {
		PL3NON,			
		PL3ATTACK,
		PL3SKILL,
		PL3DEFENCE,		
		PL3ITEM,		
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

	//スキルのバフ・デバフのターンに関するやつ
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

	//キャラ枠、職業のステータス
	struct FRAME {
		int level = 1;
		int hp = 0;			//体力
		int hpmax = 0;		//初期の体力最大値
		int mana = 0;		//精神力
		int manamax = 0;	//初期の精神力最大値
		int atk = 0;		//攻撃力
		int atkmax = 0;		//初期の攻撃の最大値
		int def = 0;		//防御力
		int defmax = 0;		//初期の防御力の最大値
		int matk = 0;		//魔法力
		int matkmax = 0;	//初期の魔法力の最大値
		int mdef = 0;		//魔防力
		int mdefmax = 0;	//初期の魔防力の最大値
		int choicejob = NON;//選択した職業
		bool deathflag = false;	//死亡したかどうか
	};

	//スキルの効果とターン
	struct BUFFTURN {
		//共通
		int buffturn[SKILL_RECORD_TURN];
		bool buffendflag[SKILL_RECORD_FLAG];
		//単体スキルのバフ
		int buffupefect[SIMPLESUBSTANCESKILL_BUFFUP_NUMBER][SIMPLESUBSTANCESKILL_RECORD_TURN];	//スキルの効果で上がったステータス(後で上がったステータスから引くためのもの)
		int buffdownefect[SIMPLESUBSTANCESKILL_BUFFDOWN_NUMBER][SIMPLESUBSTANCESKILL_RECORD_TURN];	//スキルの効果で下がったステータス(後で下がったステータスから足すためのもの)
		//全体スキルのバフ
		int attackerbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];	//スキルの効果で上がったステ(剣士)
		int shieldbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//スキルの効果で上がったステ(騎士)
		int magicbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//スキルの効果で上がったステ(魔術師)
		int healerbuff[ALLSKILL_BUFF_NUMBER][ALLSKILL_RECORD_TURN];		//スキルの効果で上がったステ(聖職者)
	};

	//タグ(定数)
	const int normalattackS = 1;		//通常攻撃(文章)
	const int damageS = 2;				//〜ダメージ与えた(文章)
	const int bossskill1S = 3;			//ボスのスキル1(文章)
	const int bossskill1damageS = 4;	//ボスのスキル1ダメージ(文章)
	const int bossskill2S = 5;			//ボスのスキル2(文章)
	const int bossskill2damageS = 6;	//ボスのスキル2ダメージ(文章)
	const int bossskill3S = 7;			//ボスのスキル3(文章)
	const int bossskill3damageS = 8;	//ボスのスキル3効果(文章)
	const int bossskill4S = 9;			//ボスのスキル4(文章)
	const int bossskill4damageS = 10;	//ボスのスキル4効果(文章)
	const int bossskill1E = 11;			//ボススキル1(エフェクト)タグ11〜14
	const int askill1E = 15;			//剣士スキル１(エフェクト)タグ15〜22
	const int mskill1E= 23;				//魔術師スキル１(エフェクト)タグ23〜30
	const int hskill1E = 31;			//聖職者スキル１(エフェクト)タグ31〜38
	const int sskill1E = 39;			//騎士スキル1(エフェクト)タグ39〜47
	const int attackerdamageS = 47;		//剣士は〜ダメージ与えた(文章)
	const int shielddamageS = 48;		//剣士は〜ダメージ与えた(文章)
	const int healerdamageS = 49;		//聖職者は〜ダメージ与えた(文章)
	const int magicdamageS = 50;		//魔術師は〜ダメージ与えた(文章)
	const int attackbuttonaI = 51;		//押す前の攻撃コマンドボタン(画像)
	const int attackbuttonbI = 52;		//押した後の攻撃コマンドボタン(画像)
	const int skillbuttonaI = 53;		//押す前のスキルコマンドボタン(画像)
	const int skillbuttonbI = 54;		//押した後のスキルコマンドボタン(画像)
	const int choiceS = 80;				//〜はどうする(文字)
	const int damage1 = 81;				//ダメージを体力の上に表記
	const int buffupS = 82;				//ステータスが上がったときに表記(文章)
	const int buffdownS = 83;			//ステータスが下がったときに表記(文章)
	const int choiceplS = 84;			//どのキャラを選択しますか(文字)
	const int buffendS = 85;			//バフの効果処理が修理宇したことを知らせる処理(文章)
	const int buffend2S = 86;			//バフの効果処理が修理宇したことを知らせる処理(文章)
	const int coverS = 87;				//タゲ集中を使った時に出る表記(文章)
	const int insteadS = 88;			//身代わりスキルを使った時に出る表記(文章)
	const int playertrunI = 99;			//PLTURN(画像)※消す予定
	const int bossturnI = 100;			//BSTURN(画像)※消す予定

	//パーセント計算(定数)
	const int tenpercent = 10;			//1割(10%)
	const int twentypercent = 20;		//2割(20%)
	const int thirtypercent = 30;		//3割(30%)
	const int fortypercent = 40;		//4割(40%)
	const int fiftypercent = 50;		//5割(50%)
	const int sixtypercent = 60;		//6割(60%)
	const int seventypercent = 70;		//7割(70%)
	const int eightypercent = 80;		//8割(80%)
	const int ninetypercent = 90;		//9割(90%)
	const int hundredpercent = 100;		//10割(100%)

	//定数
	const int backdepth = 1;		//奥行(後ろ)
	const int middledepth = 2;		//奥行(真ん中)
	const int prevdepth = 3;		//奥行(前)
	const int onece = 4;			//一番手前
	const int manarecovery = 5;		//聖職者スキル１のマナを渡す量
	const int continuity_few = 3;	//揺らすが少ないほう(揺れが少ない)
	const int continuity_many = 6;	//揺らすが多いほう(揺れが大きい)
	const int moverange = 20;		//移動させる値
	const int fontsizeS = 20;		//文字の大きさ(Sサイズ)
	const int fontsizeM = 30;		//文字の大きさ(Mサイズ)
	const int fontsizeL = 40;		//文字の大きさ(Lサイズ)
	const int fontsizeXL = 50;		//文字の大きさ(XLサイズ)
	const int flamemin = 0;			//フレームの最小値
	const int flame15 = 15;			//フレームが15
	const int flame30 = 30;			//フレームが15
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
	const int flame280 = 280;		//フレームが280
	const int flame310 = 310;		//フレームが310
	const int flame340 = 340;		//フレームが340
	const int flamemax = 500;		//フレームの最大値(500)
	const int hpmin = 0;			//HPの最小値
	const int rndmin = 0;			//ランダムの最小値
	const int rndmax = 100;			//ランダムの最大値
	const int colordown = 150;		//暗くする
	const int colormin = 0;			//色最小値
	const int colormax = 255;		//色最大値
	const int opacitymin = 0;		//透明度の最小値
	const int opacitymax = 255;		//透明度の最大値
	const int recoverylittlemin = 20;	//聖職者スキル4の回復の最小値
	const int recoverylittlemax = 35;	//聖職者スキル4の回復の最大値
	const int recoverylargemin = 75;	//聖職者スキル5の回復の最小値
	const int recoverylargemax = 90;	//聖職者スキル5の回復の最大値
	const int recoverymediummin = 35;	//聖職者スキル6の回復の最小値
	const int recoverymediummax = 50;	//聖職者スキル6の回復の最大値
	const int recoveryall = 255;		//聖職者スキル7の回復の値
	const float skilluplittle = 0.75f;	//スキル倍率小(0.75倍)
	const float skilluplittlemedium = 1.15f;//スキル倍率微妙(1.15倍)
	const float skillupmedium = 1.2f;	//スキル倍率中(1.2倍)
	const float skilluplarge = 1.5f;	//スキル倍率大(1.5倍)
	const float buffuplittle = 0.05f;	//ステータスアップ倍率小(0.05倍)
	const float buffdownlittle = 0.25f;	//ステ―タスダウン倍率小(0.25倍)
	const float buffdownlarge = 0.5f;	//ステ―タスダウン倍率大(0.5倍)
	const float recoveryattackerskill = 0.3f;//剣士のスキルの回復倍率小(0.3倍)
	const float recoverymedium = 0.4f;	//回復倍率中(0.4倍)
	
	//変数
	int buffup_value[BUFFUP_RECORD_VALUE_NUMBER];		//ステータス上昇(atkとmatkまたはdefとmdef)
	int buffdown_value[BUFFDOWN_RECORD_VALUE_NUMBER];	//ステータス下降(atkとmatkまたはdefとmdef)
	int attackerbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//バフの計算をした後に数値を入れるところ(剣士)
	int shieldbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//バフの計算をした後に数値を入れるところ(騎士)
	int magicbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//バフの計算をした後に数値を入れるところ(魔術師)
	int healerbuffup[ALLSKILL_BUFF_VALUE_NUMBER];		//バフの計算をした後に数値を入れるところ(聖職者)
	int battleturn = 0;			//ターン数
	int actcnt = 0;				//ボスの動く回数
	int bsskillrecovery = 0;	//ボススキル4の回復の量
	int hpcut = 0;				//計算した後のダメージ
	int	recovery = 0;			//回復量
	int opacity = 255;			//透明度
	int rnd = random();			//最大値までの乱数を取得
	int act_rnd = rndmin;		//指定した範囲内の乱数を取得(ボスの動く回数)
	int pick_rnd = rndmin;		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
	int skill_rnd = rndmin;		//指定した範囲内の乱数を取得(スキル)
	int decide_rnd = rndmin;	//指定した範囲内の乱数を取得(ボスの動き)
	int recovery_rnd = rndmin;	//指定した範囲内の乱数を取得(回復する値)
	float movecnt = 0.05f;		//画像を動かす時間
	float attacker_hpgauge_width = 0.0f;	//剣士HPゲージの横のサイズ
	float attacker_mngauge_width = 0.0f;	//剣士MNゲージの横のサイズ
	float shield_hpgauge_width = 0.0f;		//騎士HPゲージの横のサイズ
	float shield_mngauge_width = 0.0f;		//騎士MNゲージの横のサイズ
	float magic_hpgauge_width = 0.0f;		//魔術師HPゲージの横のサイズ
	float magic_mngauge_width = 0.0f;		//魔術師MNゲージの横のサイズ
	float healer_hpgauge_width = 0.0f;		//聖職者HPゲージの横のサイズ
	float healer_mngauge_width = 0.0f;		//聖職者MNゲージの横のサイズ
	float boss_hpgauge_width = 0.0f;		//ボスHPゲージの横のサイズ
	bool coverflag[2];						//ボスのたげ集中
	bool attacker_defenceflag = false;		//防御しているかどうか(剣士)
	bool shield_defenceflag = false;		//防御しているかどうか(騎士)
	bool magic_defenceflag = false;			//防御しているかどうか(魔術師)
	bool healer_defenceflag = false;		//防御しているかどうか(聖職者)
	bool flag = false;						//ボスの状態
	bool state = false;						//プレイヤーの状態
	bool push_buttonflag = false;			//ボタンが押せるかどうか
	bool insteadflag = false;				//騎士のスキルで身代わり状態かどうか
	bool allinsteadflag = false;			//騎士スキルで全員の身代わり状態かどうか
	bool resurrectionflag = false;			//騎士復活フラグ
	bool counter_attackflag = false;		//騎士カウンターフラグ
	bool attackendflag = false;				//攻撃が終わったかどうか
	bool skillendflag = false;				//スキルが終わったかどうか
	bool choiceendflag = false;				//選択し終わったかどうか
	bool fntflag = false;					//フォントの消える時間
	bool allworkendflag = false;			//すべての作業が終了したかどうか
	bool boss_allwork_endflag = false;		//ボスのすべちぇの作業が終了したら
	bool shield_choice_skillflag = false;	//選択系スキルの時ほかの職業の選択スキルと交わらない様にすためのもの(騎士)
	bool magic_choice_skillflag = false;	//選択系スキルの時ほかの職業の選択スキルと交わらない様にすためのもの(魔術師)
	bool healer_choice_skillflag = false;	//選択系スキルの時ほかの職業の選択スキルと交わらない様にすためのもの(聖職者)
	bool allchoice_endflag = false;			//すべての選択を終えたかどうかを
	long gameflame = 0;						//それぞれのターンの時間
	long skillflame = 0;					//それぞれのスキルの時間
	long choicetime = 0;					//ボタンを連続して押さないようにする処理

	//スキル関連
	bool askill2_allworkendflag = false;//剣士のスキル2の処理が全部終わったか調べる処理
	bool askill4_allworkendflag = false;//剣士のスキル4の処理が全部終わったか調べる処理
	bool askill7allworkendflag = false;//剣士のスキル7の処理が全部終わったか調べる処理
	bool askill8allworkendflag = false;//剣士のスキル8の処理が全部終わったか調べる処理
	bool sskill2allworkendflag = false;//騎士のスキル2の処理が全部終わったか調べる処理
	bool sskill3allworkendflag = false;//騎士のスキル3の処理が全部終わったか調べる処理
	bool sskill4allworkendflag = false;//騎士のスキル4の処理が全部終わったか調べる処理
	bool sskill5allworkendflag = false;//騎士のスキル5の処理が全部終わったか調べる処理
	bool sskill6allworkendflag = false;//騎士のスキル7の処理が全部終わったか調べる処理
	bool sskill7allworkendflag = false;//騎士のスキル7の処理が全部終わったか調べる処理
	bool sskill8allworkendflag = false;//騎士のスキル8の処理が全部終わったか調べる処理
	bool mskill2allworkendflag = false;//魔術師のスキル2の処理が全部終わったか調べる処理
	bool mskill3allworkendflag = false;//魔術師のスキル3の処理が全部終わったか調べる処理
	bool mskill5allworkendflag = false;//魔術師のスキル5の処理が全部終わったか調べる処理
	bool mskill6allworkendflag = false;//魔術師のスキル6の処理が全部終わったか調べる処理
	bool hskill2allworkendflag = false;//聖職者のスキル2の処理が全部終わったか調べる処理
	bool hskill3allworkendflag = false;//聖職者のスキル3の処理が全部終わったか調べる処理
	bool vskill3allworkendflag = false;//ヴァルキュリ−のスキル3の処理が全部終わったか調べる処理

	//enum
	TURN turn;				//ターン
	JOB job;				//キャラの職業
	JOB sskillchoice;		//騎士のスキルで選択したキャラ
	JOB mskillchoice;		//魔術師のスキルで選択したキャラ
	JOB hskillchoice;		//聖職者のスキルで選択したキャラ
	BATTLE battle;			//バトル
	BUFFT bufft;			//バフのターンに関するやつ
	BSACT bsact;			//ボスの動き
	CHOICES choices;		//選択中
	PL1 pl1;				//PL1
	PL2 pl2;				//PL2
	PL3 pl3;				//PL3
	ATTAKERSKILL askill;	//アタッカースキル
	SHIELDSKILL sskill;		//シールダースキル
	HEALERSKILL hskill;		//ヒーラースキル
	MAZICSKILL mskill;		//マジックスキル
	BOSSSKILLS bskill;		//ボススキル
	//struct
	//キャラのステータス
	FRAME pl1frame;			//キャラ枠1
	FRAME pl2frame;			//キャラ枠2
	FRAME pl3frame;			//キャラ枠3
	FRAME excludeframe;		//除外枠
	FRAME attacker;			//剣士
	FRAME shield;			//騎士
	FRAME magic;			//魔術師
	FRAME healer;			//聖職者
	FRAME valkyrie;			//ヴァルキリー
	//スキルの効果ターン
	BUFFTURN askill2;		//剣士のスキル2(アーマーブレイク)
	BUFFTURN askill4;		//剣士のスキル4(インパクトスラッシュ)
	BUFFTURN askill7;		//剣士のスキル7(コンディクション)
	BUFFTURN askill8;		//剣士のスキル8(ウォリアーウォークライ)
	BUFFTURN sskill2;		//騎士のスキル2(カウンター)
	BUFFTURN sskill3;		//騎士のスキル3(最前線)
	BUFFTURN sskill4;		//騎士のスキル4(身代わりの氷像)
	BUFFTURN sskill5;		//騎士のスキル5(群れる氷像)
	BUFFTURN sskill6;		//騎士のスキル6(鼓舞する雄叫び)
	BUFFTURN sskill7;		//騎士のスキル7(氷の御衣)
	BUFFTURN sskill8;		//騎士のスキル8(騎士の矜持)
	BUFFTURN mskill2;		//魔術師のスキル2(アーマーショット)
	BUFFTURN mskill3;		//魔術師のスキル3(マジックバースト)
	BUFFTURN mskill5;		//魔術師のスキル5(グランツ)
	BUFFTURN mskill6;		//魔術師のスキル6(神の御剣)
	BUFFTURN hskill2;		//聖職者のスキル2(死者の経典)
	BUFFTURN hskill3;		//聖職者のスキル3(聖者の経典)
	BUFFTURN vskill3;		//ヴァルキュリ−のスキル3(六帝の陣)
	//cocos2d-x
	cocos2d::Vec2 HPbar;					//HPばーの長さ
	cocos2d::Vec2 MNbar;					//MANAばーの長さ
	CCSize rightSize;						//オブジェクトを配置するときに必要
	CCSprite * BACK_GRAND_SPRITE_BOSS;		//背景
	CCSprite *UI_BOSSSCENE_TELOP;			//テロップ
	CCSprite *plturn;						//PLTURN文字(抹消予定)
	CCSprite *emturn;						//BSTURN文字(抹消予定)
	CCSprite *UI_PUSH_BEFORE_ATTACKBUTTON;	//攻撃コマンド
	CCSprite *UI_PUSH_AFTER_ATTACKBUTTON;	//攻撃コマンド(押しているとき)
	CCSprite *UI_PUSH_BEFORE_SKILLBUTTON;	//スキルコマンド
	CCSprite *UI_PUSH_AFTER_SKILLBUTTON;	//スキルコマンド(押しているとき)
	CCSprite *UI_PUSH_BEFORE_DEFENCEBUTTON;	//防御コマンド
	CCSprite *UI_PUSH_AFTER_DEFENCEBUTTON;	//防御コマンド(押しているとき)
	CCSprite *UI_PUSH_BEFORE_ITEMBUTTON;	//アイテムコマンド
	CCSprite *UI_PUSH_AFTER_ITEMBUTTON;		//アイテムコマンド(押されているとき)
	CCSprite *TARGET;						//ターゲット
	LabelTTF *lo;							//剣士はどうする
	LabelTTF *ls;							//騎士はどうする
	LabelTTF *lw;							//魔術師は以下略
	LabelTTF *ll;							//聖職者はどうする
	LabelTTF *cho;							//選択中の文章
	//剣士のUI
	CCSprite *UI_PL_ATTACKER_STATUSPLATE;	//剣士の大まかなステータスプレート
	CCSprite *UI_PL_ATTACKER_HPBAR;			//剣士のHP
	CCSprite *UI_PL_ATTACKER_MANABAR;		//剣士のMN
	LabelTTF *attackerhpal;					//剣士のHP表記
	LabelTTF *attackerhpmaxal;				//HPの最大値
	LabelTTF *attackermnal;					//剣士のMN表記
	LabelTTF *attackermnmaxal;				//MANAの最大値
	LabelTTF *attackerdmf;					//剣士ダメージ表示
	CCFadeOut *attackerfadeout;				//剣士ダメージ表示フェードアウトの時間
	CCSequence *attackerfdoutmov;			//剣士ダメージ表示フェードアウト時の動き
	 //騎士のUI
	CCSprite *UI_PL_SHIELD_STATUSPLATE;		//騎士の大まかなステータスプレート
	CCSprite *UI_PL_SHIELD_HPBAR;			//騎士のHP
	CCSprite *UI_PL_SHIELD_MANABAR;			//騎士のMN
	LabelTTF *shieldhpal;					//騎士のHP表記
	LabelTTF *shieldhpmaxal;				//HPの最大値
	LabelTTF *shieldmnal;					//騎士のMN表記
	LabelTTF *shieldmnmaxal;				//MANAの最大値
	LabelTTF *shielddmf;					//騎士ダメージ表示
	CCFadeOut *shieldfadeout;				//騎士ダメージ表示フェードアウトの時間
	CCSequence *shieldfdoutmov;				//騎士ダメージ表示フェードアウト時の動き
	//魔術師のUI
	CCSprite *UI_PL_MAGIC_STATUSPLATE;		//魔術師の大まかなステータスプレート
	CCSprite *UI_PL_MAGIC_HPBAR;			//魔術師のHP
	CCSprite *UI_PL_MAGIC_MANABAR;			//魔術師のMN
	LabelTTF *magichpal;					//魔術師のHP表記
	LabelTTF *magichpmaxal;					//HPの最大値
	LabelTTF *magicmnal;					//魔術師のMN表記
	LabelTTF *magicmnmaxal;					//MANAの最大値
	LabelTTF *magicdmf;						//魔術師ダメージ表示
	CCFadeOut *magicfadeout;				//魔術師ダメージ表示フェードアウトの時間
	CCSequence *magicfdoutmov;				//魔術師ダメージ表示フェードアウト時の動き
	//聖職者のUI
	CCSprite *UI_PL_HEALER_STATUSPLATE;		//聖職者の大まかなステータスプレート
	CCSprite *UI_PL_HEALER_HPBAR;			//聖職者のHP
	CCSprite *UI_PL_HEALER_MANABAR;			//聖職者のMN
	LabelTTF *healerhpal;					//聖職者のHP表記
	LabelTTF *healerhpmaxal;				//HPの最大値
	LabelTTF *healermnal;					//聖職者のMN表記
	LabelTTF *healermnmaxal;				//MANAの最大値
	LabelTTF *healerdmf;					//聖職者ダメージ表示
	CCFadeOut *healerfadeout;				//聖職者ダメージ表示フェードアウトの時間
	CCSequence *healerfdoutmov;				//聖職者ダメージ表示フェードアウト時の動き
	//ボスのUI
	CCSprite *BOSS_VALKYRIE;				//ヴァルキュリ−
	CCSprite *Efect;						//パーティクル
	CCSprite *UI_BOSS_HPBAR;				//ボスのhp
	CCSprite *UI_BOSS_BACK_HPBAR;			//ボスのhpの後ろ
	Repeat *bossrepeat;						//ボスがダメージを受けた時に揺らす処理
	//敵からダメージを受けた時の揺れの大きさ
	Repeat* attacker_repeat_bigquake[7];	//剣士のUIを揺らす処理(揺らす幅が大きい)	
	Repeat* attacker_repeat_smallquake[7];	//剣士のUIを揺らす処理(揺らす幅が小さい)	
	Repeat* shield_repeat_bigquake[7];		//騎士のUIを揺らす処理(揺らす幅が大きい)	
	Repeat* shield_repeat_smallquake[7];	//騎士のUIを揺らす処理(揺らす幅が小さい)	
	Repeat* magic_repeat_bigquake[7];		//魔術師のUIを揺らす処理(揺らす幅が大きい)	
	Repeat* magic_repeat_smallquake[7];		//魔術師のUIを揺らす処理(揺らす幅が小さい)	
	Repeat* healaer_repeat_smallquake[7];	//聖職者のUIを揺らす処理(揺らす幅が大きい)	
	Repeat* healaer_repeat_bigquake[7];		//聖職者のUIを揺らす処理(揺らす幅が小さい)	

	Size winSize = Director::getInstance()->getWinSize();

	static Scene *createScene();
	ValueVector BossScene::split(const std::string &str, const std::string &delim);
	virtual bool init();				//初期化
	virtual void update(float flame);	//メイン
	void PLturn();				//プレイヤーのターン
	void Plattacks();			//プレイヤーの通常攻撃
	void Plskills();			//プレイヤーのスキル
	void Pldefence();			//プレイヤーの防御
	void BSturn();				//ボスのターン
	void DamageSway();			//ダメージを受けた時に揺らす関数
	void Skillturn();			//スキルの効果が切れたかどうかを判断するための関数
	void Pick();				//狙うプレイヤーを決める関数
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