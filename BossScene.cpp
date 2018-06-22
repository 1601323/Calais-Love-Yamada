#include "BossScene.h"
#include "GameClear.h"
#include <ui/CocosGUI.h>
#pragma execution_character_set("utf-8")

using namespace ui;
using namespace std; // String*

Scene *BossScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BossScene::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool BossScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	//キャラ枠１（アタッカーの場合）
	pl1frame.hp = 9;		//HP
	pl1frame.mana = 6;		//MP
	pl1frame.atk = 7;		//ATK
	pl1frame.def = 3;		//DEF
	pl1frame.matk = 4;		//MATK
	pl1frame.mdef = 5;		//MDEF
	//キャラ枠2（ヒーラーな場合）
	pl2frame.hp = 8;		//HP
	pl2frame.mana = 8;		//MP
	pl2frame.atk = 5;		//ATK
	pl2frame.def = 5;		//DEF
	pl2frame.matk = 5;		//MATK
	pl2frame.mdef = 5;		//MDEF
	//キャラ枠3（マジックの場合）
	pl3frame.hp = 7;		//HP
	pl3frame.mana = 8;		//MP
	pl3frame.atk = 4;		//ATK
	pl3frame.def = 5;		//DEF
	pl3frame.matk = 7;		//MATK
	pl3frame.mdef = 5;		//MDEF
	//ヴァルキリー
	valkyrie.hp = 25;		//HP
	valkyrie.mana = 9;		//MP
	valkyrie.atk = 5;		//ATK
	valkyrie.def = 5;		//DEF
	valkyrie.matk = 4;		//MATK
	valkyrie.mdef = 5;		//MDEF

	//初期設定
	continuity = 6;			//揺らす回数
	ten = 10;				//移動させる値
	hpcut = 3;				//減らすHP
	depth = 1;				//奥行き
	rnd = random();			//最大値までの乱数を取得
	rndmin = 0;				//ランダムの最小値
	rndmax = 100;			//ランダムの最大値
	movecnt = 0.05f;		//1回動かす時間
	actcnt = 0;				//ボスの動く回数
	gametime = 0;			//時間
	timemax = 350;			//時間の最大値
	choicetime = 0;			//連続選択できないようにするためのやつ
	fontsize = 50;			//文字の大きさ
	Shader = 0;				//明るさ
	Color = 150;			//暗さ
	Colormax = 255;			//カラーの最大値
	HPGaugecnt = 0;			//HPゲージのカウント
	gaugecnt = 100;
	turn = PLAYER;			//誰のターン？
	battle = START;			//バトル
	choices = CHAR1;		//コマンドを選ぶ最初のキャラ
	bsact = PICK;			//ボスの動き
	job = NON;				//キャラ選択
	state = false;			//プレイヤーの状態
	flag = false;			//ボスの状態

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BossScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(Point(winSize.width / 16, winSize.height / 2));
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, depth);

	//タッチモード設定
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// バックグランド
	BossBackGroudn();

	//アップデート更新
	this->scheduleUpdate();

	return true;
}

void BossScene::update(float flame)
{
	// 画面サイズ取得。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//取得
	auto Atouchget = EventListenerTouchOneByOne::create();	//アタックボタン
	auto Stouchget = EventListenerTouchOneByOne::create();	//スキルボタン

	if (turn == PLAYER) {
		switch (battle){
			battle = START;
		case BossScene::START: {
			state = false;

			//攻撃コマンドボタン
			AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	//画像指定
			AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
			this->addChild(AttackButton1, 2, 41);					

			//攻撃コマンドボタン(押しているとき)
			AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	//画像指定
			AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
			this->addChild(AttackButton2, depth, 42);

			//スキルコマンドボタン
			SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//画像指定
			SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
			this->addChild(SkillButton1, 2, 43);									//追加

			//スキルコマンドボタン(押しているとき)
			SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//画像指定
			SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
			this->addChild(SkillButton2, depth, 44);								//追加

			//PLTURN(右上)															
			plturn = CCSprite::create("Description/PL.png");						//配置文字
			plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//場所配置
			this->addChild(plturn, depth, 1);										

			battle = WAIT;
			break;
		}
		case BossScene::WAIT: {
			battle = CHOICE;
			break;
		}
		case BossScene::CHOICE: {
			choicetime++;									//ボタンが連続で押されないようにするための処理
			//タッチ処理
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;
			//アタックボタン
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();			//タッチしたポイント。
				Rect rectButton1 = Abutton->getBoundingBox();//ボタン画像の範囲。
				switch (choices) {
				//キャラ1
				case BossScene::CHAR1: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point1)) {	
							AttackButton1->setVisible(false);	//上のボタンを消す
							pl1 = PL1ATTACK;					//アタックにする
							choicetime = 0;
							choices = CHAR2;					//次のキャラへ
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//キャラ2
				case BossScene::CHAR2: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point1)) {	
							AttackButton1->setVisible(false);	//上のボタンを消す
							pl2 = PL2ATTACK;					//アタックにする
							choicetime = 0;
							choices = CHAR3;					//次のキャラへ
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//キャラ3
				case BossScene::CHAR3: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合
						if (rectButton1.containsPoint(point1)) {
							pick_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
							act_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動く回数)
							decide_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動き)
							skill_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(スキル)
							state = true;							//動ける状態にする
							Abutton->removeFromParentAndCleanup(true);//コマンドボタン(attack)を消す
							this->removeChildByTag(42);
							this->removeChildByTag(43);
							this->removeChildByTag(44);
							pl3 = PL3ATTACK;						//アタックにする
							choicetime = 0;
							battle = ACTION;
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				default: {
					break;
				}
				}
				return true;
			};

			//スキルボタン
			Stouchget->onTouchBegan = [this, visibleSize, Sbutton](Touch* touch, Event* event) {
				Vec2 point2 = touch->getLocation();					//タッチしたポイント。
				Rect rectButton1 = Sbutton->getBoundingBox();		//ボタン画像の範囲。

				switch (choices) {
				//キャラ1
				case BossScene::CHAR1: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {	
							SkillButton1->setVisible(false);//上のボタンを消す
							pl1 = PL1SKILL;					//スキルにする
							choicetime = 0;
							choices = CHAR2;				//次のキャラへ
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				 //キャラ2
				case BossScene::CHAR2: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {	
							SkillButton1->setVisible(false);//上のボタンを消す
							pl2 = PL2SKILL;					//スキルにする
							choicetime = 0;
							choices = CHAR3;				//次のキャラへ
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				//キャラ3
				case BossScene::CHAR3: {
					if (choicetime > 20) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {	
							pick_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
							act_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動く回数)
							decide_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動き)
							skill_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(スキル)
							state = true;							//動ける状態にする
							Sbutton->removeFromParentAndCleanup(true);//コマンドボタン(attack)を消す
							this->removeChildByTag(41);
							this->removeChildByTag(42);
							this->removeChildByTag(44);
							pl3 = PL3SKILL;						//スキルにする
							choicetime = 0;
							battle = ACTION;
							return true;
						}
						else {
							CCLOG("NO TOUCH");
							return false;
						}
					}
					break;
				}
				default: {
					break;
				}
				}
				return true;
			};

			//選択キャラを明確にする(選択されてないキャラは少し暗くする)
			if (choices == CHAR1) {
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Color, Color, Color));
				PL3p->setColor(ccc3(Color, Color, Color));
			}
			else if (choices == CHAR2) {
				PL1p->setColor(ccc3(Color, Color, Color));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Color, Color, Color));
			}
			else if (choices == CHAR3) {
				PL1p->setColor(ccc3(Color, Color, Color));
				PL2p->setColor(ccc3(Color, Color, Color));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			}
			// touchget, buttonをイベント登録する。
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Atouchget, Abutton);
			auto director2 = Director::getInstance();
			director2->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Stouchget, Sbutton);
			break;
		}
		//プレイヤーのアクション(エフェクトなど)
		case BossScene::ACTION: {
			//プレイヤーたちの画像の色を戻す
			PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			if (state == true) {
				gametime++;								//カウント開始
				PLturn();								//主な処理
			}
			if (gametime > 250) {
				//文字を消す
				this->removeChildByTag(1);				//PLTURN
				this->removeChildByTag(17);				//ぐるぐるしてるやつ
				this->removeChildByTag(23);				//ダメージ表記を消す

				//BSTURN文字
				emturn = CCSprite::create("Description/BS.png");							// 配置文字
				emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// 配置場所
				this->addChild(emturn, depth, 2);											// 追加

				gametime = 0;							//カウントを0へ
				bsact = PICK;							//ボスの動きを初期化
				turn = BOSS;							//ボスのターンへ
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	else if (turn == BOSS) {
		//初期化
		flag = false;									//フラグをfalseに
		gaugecnt--;
		gametime++;										//カウント開始
		BSturn();										//主な処理
		
		if (gametime == 170) {
			//文字を消す
			this->removeChildByTag(5);					//通常攻撃
			this->removeChildByTag(54);					//スキル1			
			this->removeChildByTag(56);					//スキル2
			this->removeChildByTag(58);					//スキル3
			this->removeChildByTag(60);					//スキル4
		}

		if (gametime > timemax) {
			if (act_rnd < 20) {
				//文字を消す
				this->removeChildByTag(2);				//BSTURN
				this->removeChildByTag(6);				//効果表記(通常攻撃)
				this->removeChildByTag(13);				//パーティクル
				this->removeChildByTag(55);				//効果表記(スキル1)
				this->removeChildByTag(57);				//効果表記(スキル2)
				this->removeChildByTag(59);				//効果表記(スキル3)
				this->removeChildByTag(61);				//効果表記(スキル4)

				gametime = 0;							//時間を0へ
				actcnt = 0;								//カウントを0へ
				job = NON;								//選んだキャラを初期の状態に戻す
				battle = START;							//バトルを初期の状態に戻す
				choices = CHAR1;						//選択キャラを最初に
				turn = PLAYER;							//プレイヤーのターンへ
			}
			if (act_rnd >= 20 && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//文字を消す
					this->removeChildByTag(6);			//効果表記(通常攻撃)
					this->removeChildByTag(13);			//パーティクル
					this->removeChildByTag(55);			//効果表記(スキル1)
					this->removeChildByTag(57);			//効果表記(スキル2)
					this->removeChildByTag(59);			//効果表記(スキル3)
					this->removeChildByTag(61);			//効果表記(スキル4)

					pick_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
					act_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動く回数)
					decide_rnd = random(rndmin, rndmax);//指定した範囲内の乱数を取得(ボスの動き)
					skill_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(スキル)

					actcnt += 1;						//攻撃カウントを増やして2回以上攻撃しないようにする
					gametime = 0;						//時間を0へ
					bsact = PICK;						//ボスの動きを初期に戻す
					turn = BOSS;						//もう一回ボスの行動へ
				}
				else {
					//文字を消す
					this->removeChildByTag(2);			//BSTURN
					this->removeChildByTag(6);			//効果表記(通常攻撃)
					this->removeChildByTag(13);			//パーティクル
					this->removeChildByTag(55);			//効果表記(スキル1)
					this->removeChildByTag(57);			//効果表記(スキル2)
					this->removeChildByTag(59);			//効果表記(スキル3)
					this->removeChildByTag(61);			//効果表記(スキル4)

					gametime = 0;						//時間を0へ
					actcnt = 0;							//カウントを0へ
					job = NON;							//選んだキャラを初期の状態に戻す
					battle = START;						//バトルを初期の状態に戻す
					choices = CHAR1;					//選択キャラを最初に
					turn = PLAYER;						//プレイヤーのターンへ
				}
			}
		}

		HPpl1->setTextureRect(Rect(HPbar.x, HPbar.y,
			HPGaugeWidth * pl1frame.hp / 9,
			HPpl1->getContentSize().height));
	}
	CCLOG("%i秒", gametime);
 }

void BossScene::PLturn()
{
	//プレイヤー1の行動
	if (gametime == 50) {
		if (pl1 == PL1ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 3, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 3, rightSize.height / 4 + ten)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			PL1p->runAction(repeat);

			//ボスのHPを減らす
			hpcut = (pl1frame.atk - valkyrie.def);
			valkyrie.hp -=hpcut;
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}

			//ダメージ表記
			String *p1atk = String::createWithFormat("PL1は%iダメージ与えた", hpcut);
			string _p1atk = p1atk->getCString();
			auto p1alabel = Label::createWithSystemFont(_p1atk, "HGRSGU.TTC", fontsize);
			p1alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p1alabel, depth, 21);
		}
		else if (pl1 == PL1SKILL) {
			//エフェクトの表示
			//エフェクトの流れを指定
			CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill1.plist");

			plparticle->setAutoRemoveOnFinish(true);

			//パーティクル開始
			plparticle->resetSystem();

			//パーティクルを表示する場所の設定
			plparticle->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//パーティクルを配置
			this->addChild(plparticle, depth, 15);

			//ボスのHPを減らす
			hpcut = (pl1frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			valkyrie.hp -= hpcut;
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}
			//ダメージ表記
			String *p1skl = String::createWithFormat("PL1は%iダメージ与えた", hpcut);
			string _p1skl = p1skl->getCString();
			auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsize);
			p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p1slabel, depth, 21);
		}
	}
	//プレイヤー2の行動
	if (gametime == 70) {
		this->removeChildByTag(15);				//エフェクトを消す
		this->removeChildByTag(21);				//ダメージ表記を消す
		if (pl2 == PL2ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			PL2p->runAction(repeat);

			//ボスのHPを減らす
			hpcut = (pl2frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}

			//ダメージ表記
			String *p2atk = String::createWithFormat("PL2は%iダメージ与えた", hpcut);
			string _p2atk = p2atk->getCString();
			auto p2alabel = Label::createWithSystemFont(_p2atk, "HGRSGU.TTC", fontsize);
			p2alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p2alabel, depth, 22);
		}
		else if (pl2 == PL2SKILL) {
			//エフェクトの表示
			//エフェクトの流れを指定
			CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill2.plist");

			plparticle2->setAutoRemoveOnFinish(true);

			//パーティクル開始
			plparticle2->resetSystem();

			//パーティクルを表示する場所の設定
			plparticle2->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//パーティクルを配置
			this->addChild(plparticle2, depth, 16);

			//ボスのHPを減らす
			valkyrie.hp -=(pl2frame.matk - valkyrie.mdef);
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}
		}
	}
	//プレイヤー3の行動
	if (gametime == 100) {
		this->removeChildByTag(22);				//ダメージ表記を消す
		this->removeChildByTag(16);				//エフェクトを消す
		if (pl3 == PL3ATTACK) {
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 1.5f, rightSize.height / 4 - ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 1.5f, rightSize.height / 4 + ten)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			PL3p->runAction(repeat);

			//ボスのHPを減らす
			hpcut = (pl3frame.atk - valkyrie.def);
			valkyrie.hp -= hpcut;
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}

			//ダメージ表記
			String *p3atk = String::createWithFormat("PL3は%iダメージ与えた", hpcut);
			string _p3atk = p3atk->getCString();
			auto p3alabel = Label::createWithSystemFont(_p3atk, "HGRSGU.TTC", fontsize);
			p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(p3alabel, depth, 23);
		}
		else if (pl3 == PL3SKILL) {
			//エフェクトの表示
			//エフェクトの流れを指定
			CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
			plparticle3->setAutoRemoveOnFinish(true);

			//パーティクル開始
			plparticle3->resetSystem();

			//パーティクルを表示する場所の設定
			plparticle3->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));

			//パーティクルを配置
			this->addChild(plparticle3, depth, 17);

			//ボスのHPを減らす
			valkyrie.hp -=(pl3frame.matk - valkyrie.mdef);
			//HPが0になったら
			if (valkyrie.hp <= 0) {
				// 遷移策の画面をｲﾝｽﾀﾝｽ
				Scene *pScene = GameClear::createScene();
				// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				TransitionFade *transition = TransitionFade::create(1.0, pScene);
				// 遷移実行 アニメーション
				Director::getInstance()->replaceScene(transition);
			}
		}
	}
}

void BossScene::PLSKILLS()
{
	//剣士
	if (job == ATTACKER) {
		//ツインフルーレ
		if (askill == ASKILL1) {
			//敵単体に小ダメージ2回攻撃
		}
		//アーマーブレイク
		if (askill == ASKILL2) {
			//敵単体に小ダメージ+防御力ダウン
		}
		//ライフソード
		if (askill == ASKILL3) {
			//敵単体に小ダメージ＋自身のHPを小回復
		}
		//インパクトスラッシュ
		if (askill == ASKILL4) {
			//敵単体に小ダメージ+攻撃力ダウン
		}
		//ソードスルー
		if (askill == ASKILL5) {
			//敵単体に防御力無視の中ダメージ
		}
		//紅蓮剣
		if (askill == ASKILL6) {
			//敵単体に大ダメージ
		}
		//コンディクション
		if (askill == ASKILL7) {
			//3ターンの間、自身の攻撃力が小アップ
		}
		//ウォリアーウォークライ
		if (askill == ASKILL8) {
			//3ターンの間、自身の攻撃力を大アップ・防御力小ダウン
		}
	}
	//騎士
	if (job == SHIELD) {
		//アインスゾイレ
		if (sskill == SSKILL1) {
			//敵単体に小ダメージの２回攻撃
		}
		//カウンター
		if (sskill == SSKILL2) {
			//攻撃を受けたとき、敵を攻撃する
		}
		//最前線
		if (sskill == SSKILL3) {
			//敵の攻撃を自身に集中させる
		}
		//身代わりの氷像
		if (sskill == SSKILL4) {
			//味方単体へのダメージを代わりに受ける
		}
		//群れる氷像
		if (sskill == SSKILL5) {
			//味方全員へのダメージを代わりに受ける
		}
		//鼓舞する雄叫び
		if (sskill == SSKILL6) {
			//戦闘不能時１度だけ自身のHP１で復活する
		}
		//氷の御衣
		if (sskill == SSKILL7) {
			//5ターンの間、自身の防御力を小アップ
		}
		//騎士の矜持
		if (sskill == SSKILL8) {
			//3ターンの間、自身の防御力を大アップ・攻撃力小ダウン
		}
	}
	//魔術師
	if (job == MAGIC) {
		//マジックミサイル
		if (mskill == MSKILL1) {
			//敵単体に小ダメージ
		}
		//アーマーショット
		if (mskill == MSKILL2) {
			//敵単体に小ダメージ+自身の防御小アップ
		}
		//マジックバースト
		if (mskill == MSKILL3) {
			//敵単体に中ダメージ + 敵の攻撃ダウン
		}
		//VFD
		if (mskill == MSKILL4) {
			//敵単体に特大ダメージ
		}
		//グランツ
		if (mskill == MSKILL5) {
			//3ターンの間、味方全体の攻撃力と防御力小アップ
		}
		//神の御剣
		if (mskill == MSKILL6) {
			//2ターンの間、味方全体の攻撃力と防御力大アップ
		}
		//魔力吸収
		if (mskill == MSKILL7) {
			//味方単体のMPを10%吸収し自身のMPを回復する
		}
		//心呼吸
		if (mskill == MSKILL8) {
			//3ターンの間、自身のMPを小回復
		}
	}
	//聖職者
	if (job == HEALER) {
		//魔力供給
		if (hskill == HSKILL1) {
			//味方単体に自身のMPを小与える
		}
		//死者の経典
		if (hskill == HSKILL2) {
			//敵単体の攻撃力中ダウン
		}
		//聖者の経典
		if (hskill == HSKILL3) {
			//敵単体の防御力中ダウン
		}
		//セイントローグ
		if (hskill == HSKILL4) {
			//味方単体のHPを小回復
		}
		//聖闘士ぺーパー
		if (hskill == HSKILL5) {
			//味方単体のHPを中回復
		}
		//聖者の祈り
		if (hskill == HSKILL6) {
			//味方全体のHPを小回復
		}
		//セイントオーダー
		if (hskill == HSKILL7) {
			//味方全体のHPを大回復
		}
		//神の啓示
		if (hskill == HSKILL8) {
			//味方単体を戦闘不能状態から復活させる
		}
	}
}

void BossScene::BSturn()
{
	//狙うプレイヤーを決める
	if (bsact == PICK) {
		if (pick_rnd < 30) {
			job = ATTACKER;
		}
		if (pick_rnd >= 30 && pick_rnd < 55) {
			job = HEALER;
		}
		if (pick_rnd >= 50 && pick_rnd < 80) {
			job = MAGIC;
		}
		if (pick_rnd >= 80 && pick_rnd <= rndmax) {
			job = SHIELD;
		}
		bsact = DECIDE;
	}
	//通常攻撃かスキルかを決める
	if (bsact == DECIDE) {
		if (decide_rnd < 60) {
			bsact = ATTACK;
		}
		if (decide_rnd >= 60 && decide_rnd <= rndmax ) {
			bsact = SKILL;
		}
	}
	//どのスキルで攻撃するかを決める
	if (bsact == SKILL) {
		if (skill_rnd < 40) {
			bskill = BSKILL1;
		}
		if (skill_rnd >= 40 && skill_rnd < 65) {
			bskill = BSKILL2;
		}
		if (skill_rnd >= 65 && skill_rnd < 90) {
			bskill = BSKILL3;
		}
		if (skill_rnd >= 90 && skill_rnd <= rndmax) {
			bskill = BSKILL4;
		}
	}
	//log("pick_rnd %d", pick_rnd);		//選んだキャラの乱数を出力に表示
	//log("act_rnd %d", act_rnd);		//ボスの動く回数の乱数を出力に表示
	//log("decide_rnd %d", decide_rnd);	//ボスの動きの乱数を出力に表示
	//log("skill_rnd %d", skill_rnd);	//スキルの乱数を出力に表示
	log("job %i", job);					//選んだキャラを出力に表示
	//log("bsact %i", bsact);			//ボスの動きを出力に表示
	log("actcnt %i", actcnt);			//カウントを出力に表示
	//log("skill %i", skill);			//スキルを出力に表示
	CCString *hpstr1 = CCString::createWithFormat("現在PL1HPは%dです", pl1frame.hp);
	log("%s", hpstr1->getCString());	//プレイヤー1のHPを表示
	CCString *hpstr2 = CCString::createWithFormat("現在PL2HPは%dです", pl2frame.hp);
	log("%s", hpstr2->getCString());	//プレイヤー2のHPを表示
	CCString *hpstr3 = CCString::createWithFormat("現在PL3HPは%dです", pl3frame.hp);
	log("%s", hpstr3->getCString());	//プレイヤー3のHPを表示
	CCString *hpstrBS = CCString::createWithFormat("現在ヴァルキリーHPは%dです", valkyrie.hp);
	log("%s", hpstrBS->getCString());	//ヴァルキリーのHPを表示

	//攻撃モードの時
	if (bsact == ATTACK) {
		if (gametime == 80) {
			//タイマーが80(仮)になったら文字を表示する
			CCLabelTTF *atk = CCLabelTTF::create("「やあっ！(通常攻撃)」", "HGRSGU.TTC", fontsize);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, depth, 5);
			//ボスの画像を揺らす処理
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + ten)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f - ten)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);
			//HPをへらす
			if (job == ATTACKER) {
				hpcut = (valkyrie.atk - pl1frame.def);
				pl1frame.hp -= hpcut;
				PL1p->setColor(ccc3(Colormax, Color, Color));
			}
			else if(job == HEALER){
				hpcut = (valkyrie.atk - pl1frame.def);
				pl2frame.hp -= hpcut;
				PL2p->setColor(ccc3(Colormax, Color, Color));
			}
			else if (job == MAGIC) {
				hpcut = (valkyrie.atk - pl3frame.def);
				pl3frame.hp -= hpcut;
				PL3p->setColor(ccc3(Colormax, Color, Color));
			}
			//誰かのHPがゼロになったら
			if ((pl1frame.hp <= 0) || (pl2frame.hp <= 0) || (pl3frame.hp <= 0)) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0f, pScene);	// 1秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}
		}
		//キャラ画像の色を戻す
		if (gametime == 100) {
			PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
			PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
		}
		//効果処理
		//タイマーが230(仮)になると効果を表記
		if (gametime == 230) {
			if (job == ATTACKER) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("アタッカーに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p1bsalabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p1bsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1bsalabel, depth, 6);
			}
			else if (job == HEALER) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("ヒーラーに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, depth, 6);
			}
			else if (job == MAGIC) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("マジックに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsize);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, depth, 6);
			}
		}
		//ふぉいあーを出力に表示
		log("ふぉいあー");		
	}
	//ヴァルキリースキル
	if (bsact == SKILL) {
		//一の太刀
		if (bskill == BSKILL1) {
			//タイマーが80(仮)になるとスキルの名前表示
			if (gametime == 80) {
				CCLabelTTF *Gskill1 = CCLabelTTF::create("「くらえ…！」", "HGRSGU.TTC", fontsize);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, depth, 54);
			}
			//揺らす処理
			if (gametime == 220) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + ten)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f - ten)),
					NULL
				);
				//揺らす
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// 画面サイズ取得
				Size winSize = Director::getInstance()->getVisibleSize();

				//背景を揺らす
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 2.02f + ten)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 2.02f - ten)),
					NULL
				);
				//何回揺らすか
				auto backrepeat = Repeat::create(backmove, continuity);
				//揺らす
				back->runAction(backrepeat);

				//プレイヤー全員のHPを減らす
				pl1frame.hp -= (valkyrie.atk - pl1frame.def);
				pl2frame.hp -= (valkyrie.atk - pl2frame.def);
				pl3frame.hp -= (valkyrie.atk - pl3frame.def);

				//紅に染めてこのキャラを
				PL1p->setColor(ccc3(Colormax, Color, Color));
				PL2p->setColor(ccc3(Colormax, Color, Color));
				PL3p->setColor(ccc3(Colormax, Color, Color));
				
				//HPがゼロになったら
				if ((pl1frame.hp <= 0)||(pl2frame.hp <= 0)||(pl3frame.hp <= 0)) {
					// 遷移策の画面をｲﾝｽﾀﾝｽ
					Scene *pScene = GameClear::createScene();

					// 0.6秒かけて次画面に遷移
					// (時間,遷移先,色(オプション))
					TransitionFade *transition = TransitionFade::create(1.0, pScene);

					// 遷移実行 アニメーション
					Director::getInstance()->replaceScene(transition);
				}
			}
			//ダメージ処理
			//タイマーが230(仮)になるとダメージ表記
			if (gametime == 230) {
				CCLabelTTF *Gskill1dec = CCLabelTTF::create("全員にダメージを与える", "HGRSGU.TTC", fontsize);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, depth, 55);

				//キャラの色を戻す
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			}
		}
		//二の太刀
		if (bskill == BSKILL2) {
			//タイマーが80(仮)になるとスキルの名前表示
			if (gametime == 80) {
				CCLabelTTF *Gskill2 = CCLabelTTF::create("「やあああ！」", "HGRSGU.TTC", fontsize);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, depth, 56);

				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - pl1frame.def);
					pl1frame.hp -= hpcut;	//HPをへらす
					PL1p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - pl2frame.def);
					pl2frame.hp -= hpcut;
					PL2p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - pl3frame.def);
					pl3frame.hp -= hpcut;
					PL3p->setColor(ccc3(Colormax, Color, Color));
				}

				//エフェクトの表示
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//エフェクトの流れを指定
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				//パーティクル開始
				particle->resetSystem();

				//パーティクルを表示する場所の設定
				particle->setPosition(ccp(rightSize.width / 2, rightSize.height / 3));

				//パーティクルを配置
				this->addChild(particle, depth, 13);
			}
			//二回目の攻撃
			if (gametime == 150) {
				//二回目のHPを減らす
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - pl1frame.def);
					pl1frame.hp -= hpcut;	//HPをへらす
					PL1p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - pl2frame.def);
					pl2frame.hp -= hpcut;
					PL2p->setColor(ccc3(Colormax, Color, Color));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - pl3frame.def);
					pl3frame.hp -= hpcut;
					PL3p->setColor(ccc3(Colormax, Color, Color));
				}
				//HPがゼロになったら画面遷移
				if ((pl1frame.hp <= 0) || (pl2frame.hp <= 0) || (pl3frame.hp <= 0)) {
					Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
					TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
					Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
				}
				//キャラの色を戻す
				PL1p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL2p->setColor(ccc3(Colormax, Colormax, Colormax));
				PL3p->setColor(ccc3(Colormax, Colormax, Colormax));
			}
			//効果処理
			//タイマーが230(仮)になると効果を表記
			if (gametime == 230) {
				CCLabelTTF *Gskill2dec = CCLabelTTF::create("２回ダメージにダメージ", "HGRSGU.TTC", fontsize);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, depth, 57);
			}
		}
		//六帝の陣
		if (bskill == BSKILL3) {
			if (gametime == 80) {
				CCLabelTTF *Gskill3 = CCLabelTTF::create("「これでもヴァルキリーなので」", "HGRSGU.TTC", fontsize);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, depth, 58);

				//ヴァルキリーの防御力を増やす
				valkyrie.def += 2;					
			}
			//効果処理
			//タイマーが230(仮)になると効果を表記
			if (gametime == 230) {
				CCLabelTTF *Gskill3dec = CCLabelTTF::create("ヴァルキリーの防御力が大幅に上がった", "HGRSGU.TTC", 40);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, depth, 59);
			}
		}
		//エステ
		if (bskill == BSKILL4) {
			if (gametime == 80) {
				CCLabelTTF *Gskill4 = CCLabelTTF::create("「エステ…ｽｷｨ…」", "HGRSGU.TTC", fontsize);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, depth, 60);

				//ヴァルキリーのHPを増やす
				valkyrie.hp += 3;					
			}
			//効果処理
			//タイマーが230(仮)になると効果を表記
			if (gametime == 230) {
				CCLabelTTF *Gskill4dec = CCLabelTTF::create("ヴァルキリーのHPが少し回復した", "HGRSGU.TTC", fontsize);
				Gskill4dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4dec, depth, 61);
			}
		}
		log("ファイアー");		//ファイアーを出力に表示
	}
}


// いつも出ている画像
void BossScene::BossBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();
	// バックカラー
	auto groundCollar = LayerColor::create(Color4B::RED, winSize.width, winSize.height);
	// バックグランドCollar第2:表示順
	this->addChild(groundCollar, 0);
//背景
	//背景の画像指定
	back = CCSprite::create("BackImage/ST_Boss.png"); 
	// 表示座標指定
	back->setPosition(ccp(winSize.width / 2, winSize.height / 2.02f));
	//追加
	this->addChild(back, depth);
// ボスの表示
	// サイズ取得
	rightSize = CCDirector::sharedDirector()->getWinSize();
	// 画像指定
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");
	// 表示座標指定
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));
	// 追加
	this->addChild(Boss, depth);
//PL1
	//画像指定
	PL1p = CCSprite::create("Player/PL_Attacker_face.png");
	//表示座標指定
	PL1p->setPosition(ccp(rightSize.width / 3, rightSize.height / 4));
	//追加
	this->addChild(PL1p, depth);
//PL2
	//画像指定
	PL2p = CCSprite::create("Player/PL_Healer_face.png");
	//表示座標指定
	PL2p->setPosition(ccp(rightSize.width / 2, rightSize.height / 4));
	//追加
	this->addChild(PL2p, depth);
//PL3
	//画像指定
	PL3p = CCSprite::create("Player/PL_Magic_face.png");
	//表示座標指定
	PL3p->setPosition(ccp(rightSize.width / 1.5f, rightSize.height / 4));
	//追加
	this->addChild(PL3p, depth);
//ステータス(HP)
	HPpl1 = CCSprite::create("UI/Status/UI_Status_Life.png");
	HPpl1->setPosition(ccp(rightSize.width / 3 - HPpl1->getContentSize().width / 2,
						   rightSize.height / 5 - HPpl1->getContentSize().height / 2));
	CCPoint ancharpoint = ccp(0.0f, 0.0f);
	HPpl1->setAnchorPoint(ancharpoint);
	HPbar = HPpl1->getTextureRect().origin;
	HPGaugeWidth = HPpl1->getContentSize().width;
	this->addChild(HPpl1, 2, 48);

	HPBpl1 = CCSprite::create("UI/Status/UI_Status_Lifeback.png");
	HPBpl1->setPosition(ccp(rightSize.width / 3 - HPBpl1->getContentSize().width / 2,
							rightSize.height / 5 - HPBpl1->getContentSize().height / 2));
	this->addChild(HPBpl1, depth, 49);

}

// 画面遷移
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = GameClear::createScene();							
	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6f, pScene);
	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

//ボタンを押したとき
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

//ボタンを押して離したとき
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	if (battle == CHOICE) {
		AttackButton1->setVisible(true);
		SkillButton1->setVisible(true);
	}
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}