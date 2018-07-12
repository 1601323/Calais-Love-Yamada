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
	pl1frame.hp = 115;					//HP
	pl1frame.hpmax = pl1frame.hp;		//HPMAX
	pl1frame.mana = 38;					//MP
	pl1frame.manamax = pl1frame.mana;	//MPMAX
	pl1frame.atk = 90;					//ATK
	pl1frame.atkmax = pl1frame.atk;		//ATKMAX
	pl1frame.def = 78;					//DEF
	pl1frame.defmax = pl1frame.def;		//DEFMAX
	pl1frame.matk = 57;					//MATK
	pl1frame.matkmax = pl1frame.matk;	//MATKMAX
	pl1frame.mdef = 78;					//MDEF
	pl1frame.mdefmax = pl1frame.mdef;	//MDEFMAX
	pl1frame.choicejob = HEALER;			//剣士
	//キャラ枠2（ヒーラーな場合）
	pl2frame.hp = 86;					//HP
	pl2frame.hpmax = pl2frame.hp;		//HPMAX
	pl2frame.mana = 75;					//MP
	pl2frame.manamax = pl2frame.mana;	//MPMAX
	pl2frame.atk = 61;					//ATK
	pl2frame.atkmax = pl2frame.atk;		//ATKMAX
	pl2frame.def = 74;					//DEF
	pl2frame.defmax = pl2frame.def;		//DEFMAX
	pl2frame.matk = 57;					//MATK
	pl2frame.matkmax = pl2frame.matk;	//MATKMAX
	pl2frame.mdef = 69;					//MDEF
	pl2frame.mdefmax = pl2frame.mdef;	//MDEFMAX
	pl2frame.choicejob = MAGIC;		//聖職者
	//キャラ枠3（マジックの場合）
	pl3frame.hp = 93;					//HP
	pl3frame.hpmax = pl3frame.hp;		//HPMAX
	pl3frame.mana = 69;					//MP
	pl3frame.manamax = pl3frame.mana;	//MPMAX
	pl3frame.atk = 61;					//ATK
	pl3frame.atkmax = pl3frame.atk;		//ATKMAX
	pl3frame.def = 69;					//DEF
	pl3frame.defmax = pl3frame.def;		//DEFMAX
	pl3frame.matk = 90;					//MATK
	pl3frame.matkmax = pl3frame.matk;	//MATKMAX
	pl3frame.mdef = 74;					//MDEF
	pl3frame.mdefmax = pl3frame.mdef;	//MDEFMAX
	pl3frame.choicejob = ATTACKER;			//魔術師

	//剣士
	if (pl1frame.choicejob == ATTACKER) {
		attacker.hp = pl1frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl1frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl1frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl1frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl1frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl1frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == ATTACKER) {
		attacker.hp = pl2frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl2frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl2frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl2frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl2frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl2frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == ATTACKER) {
		attacker.hp = pl3frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl3frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl3frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl3frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl3frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl3frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	//騎士
	if (pl1frame.choicejob == SHIELD) {
		shield.hp = pl1frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl1frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl1frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl1frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl1frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl1frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == SHIELD) {
		shield.hp = pl2frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl2frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl2frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl2frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl2frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl2frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == SHIELD) {
		shield.hp = pl3frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl3frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl3frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl3frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl3frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl3frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	//魔術師
	if (pl1frame.choicejob == MAGIC) {
		magic.hp = pl1frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl1frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl1frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl1frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl1frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl1frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == MAGIC) {
		magic.hp = pl2frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl2frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl2frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl2frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl2frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl2frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == MAGIC) {
		magic.hp = pl3frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl3frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl3frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl3frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl3frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl3frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	//聖職者
	if (pl1frame.choicejob == HEALER) {
		healer.hp = pl1frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl1frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl1frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl1frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl1frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl1frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == HEALER) {
		healer.hp = pl2frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl2frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl2frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl2frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl2frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl2frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == HEALER) {
		healer.hp = pl3frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl3frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl3frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl3frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl3frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl3frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	//ヴァルキリー
	valkyrie.hp = 800;					//HP
	valkyrie.hpmax = valkyrie.hp;		//HPMAX
	valkyrie.mana = 10;					//MP
	valkyrie.manamax = valkyrie.mana;	//MPMAX
	valkyrie.atk = 64;					//ATK
	valkyrie.atkmax = valkyrie.atk;		//ATKMAX
	valkyrie.def = 128;					//DEF
	valkyrie.defmax = valkyrie.def;		//DEFMAX
	valkyrie.matk = 70;					//MATK
	valkyrie.matkmax = valkyrie.matk;	//MATKMAX
	valkyrie.mdef = 88;					//MDEF
	valkyrie.mdefmax = valkyrie.mdef;	//MDEFMAX

	//初期設定
	turn = PLAYER;			//誰のターン？
	battle = START;			//バトル
	choices = CHAR1;		//コマンドを選ぶ最初のキャラ
	bsact = PICK;			//ボスの動き
	job = NON;				//キャラ選択
	
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
	this->addChild(menu, backdepth);

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
	if (turn == PLAYER) {
		switch (battle){
			battle = START;
		case BossScene::START: {
			state = false;
			//攻撃コマンドボタン
			AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	 //画像指定
			AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
			this->addChild(AttackButton1, middledepth, attackbuttonaI);				//追加		

			//攻撃コマンドボタン(押されているとき)
			AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	 //画像指定
			AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
			this->addChild(AttackButton2, backdepth, attackbuttonbI);				//追加

			//スキルコマンドボタン
			SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//画像指定
			SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
			this->addChild(SkillButton1, middledepth, skillbuttonaI);				//追加

			//スキルコマンドボタン(押されているとき)
			SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//画像指定
			SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
			this->addChild(SkillButton2, backdepth, skillbuttonbI);						//追加

			//PLTURN(右上)															
			plturn = CCSprite::create("Description/PL.png");						//配置文字
			plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//場所配置
			this->addChild(plturn, backdepth, playertrunI);							//追加

			battle = WAIT;
			break;
		}
		case BossScene::WAIT: {
			
			battle = CHOICE;
			break;
		}
		case BossScene::CHOICE: {
			// 画面サイズ取得。
			Size visibleSize = Director::getInstance()->getVisibleSize();
			//取得
			auto Atouchget = EventListenerTouchOneByOne::create();	//アタックボタン
			auto Stouchget = EventListenerTouchOneByOne::create();	//スキルボタン

			choicetime++;											//ボタンが連続で押されないようにするための処理
			//タッチ処理
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;
			//アタックボタン
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();					//タッチしたポイント。
				Rect rectButton1 = Abutton->getBoundingBox();		//ボタン画像の範囲。
				switch (choices) {
				//キャラ1
				case BossScene::CHAR1: {
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point1)) {
							AttackButton1->setVisible(false);		//上のボタンを消す
							pl1 = PL1ATTACK;						//アタックにする
							this->removeChildByTag(choiceS);
							choicetime = 0;
							choices = CHAR2;						//次のキャラへ
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
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point1)) {
							this->removeChildByTag(choiceS);
							AttackButton1->setVisible(false);		//上のボタンを消す
							pl2 = PL2ATTACK;						//アタックにする
							choicetime = 0;
							choices = CHAR3;						//次のキャラへ
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
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合
						if (rectButton1.containsPoint(point1)) {
							pick_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
							act_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動く回数)
							decide_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動き)
							skill_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(スキル)
							state = true;							//動ける状態にする
							Abutton->removeFromParentAndCleanup(true);//コマンドボタン(attack)を消す
							this->removeChildByTag(attackbuttonbI);
							this->removeChildByTag(skillbuttonaI);
							this->removeChildByTag(skillbuttonbI);
							this->removeChildByTag(choiceS);
							pl3 = PL3ATTACK;						//アタックにする
							choicetime = 0;
							battle = ACTION;						//エフェクトなど
							choices = CHAR1;
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
				Vec2 point2 = touch->getLocation();						//タッチしたポイント。
				Rect rectButton1 = Sbutton->getBoundingBox();			//ボタン画像の範囲。
				switch (choices) {
				//キャラ1
				case BossScene::CHAR1: {
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {
							SkillButton1->setVisible(false);			//上のボタンを消す
							pl1 = PL1SKILL;								//スキルを使う
							askill = ASKILL1;							//ツインフルーレ
							sskill = SSKILL1;							//アインスゾイレ
							mskill = MSKILL1;							//マジックミサイル
							hskill = HSKILL2;							//死者の経典
							if(pl1frame.choicejob)
							choicetime = 0;
							this->removeChildByTag(choiceS);
							choices = CHAR2;							//次のキャラへ
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
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {
							SkillButton1->setVisible(false);			//上のボタンを消す
							pl2 = PL2SKILL;								//スキル使う
							askill = ASKILL2;							//アーマーブレイク
							sskill = SSKILL2;							//カウンター
							mskill = MSKILL2;							//アーマーショット
							hskill = HSKILL3;							//聖者の経典
							choicetime = 0;
							this->removeChildByTag(choiceS);
							choices = CHAR3;							//次のキャラへ
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
					if (choicetime > flame15) {
						//ボタン画像の範囲内をタッチした場合。
						if (rectButton1.containsPoint(point2)) {
							pick_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
							act_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(ボスの動く回数)
							decide_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動き)
							skill_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(スキル)
							state = true;								//動ける状態にする
							Sbutton->removeFromParentAndCleanup(true);	//コマンドボタン(attack)を消す
							this->removeChildByTag(attackbuttonaI);
							this->removeChildByTag(attackbuttonbI);
							this->removeChildByTag(skillbuttonbI);
							this->removeChildByTag(choiceS);
							pl3 = PL3SKILL;								//スキルにする
							askill = ASKILL3;							//ライフソード
							sskill = SSKILL3;							//最前線
							mskill = MSKILL3;							//マジックバースト
							hskill = HSKILL7;							//セイントオーダー
							choicetime = 0;								//タイムを0
							battle = ACTION;							//エフェクトなどを担当
							choices = CHAR1;
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
			//選択するときに出る文字
			if (choicetime == flame15) {
				if (choices == CHAR1) {
					if (pl1frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("剣士はどうする", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl1frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("聖職者はどうする", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl1frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("魔術師はどうする", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
				else if (choices == CHAR2) {
					if (pl2frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("剣士はどうする", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("聖職者はどうする", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("魔術師はどうする", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
				else if (choices == CHAR3) {
					if (pl3frame.choicejob == ATTACKER) {
						lo = CCLabelTTF::create("剣士はどうする", "HGRSGU.TTC", fontsizeL);
						lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == HEALER) {
						ll = CCLabelTTF::create("聖職者はどうする", "HGRSGU.TTC", fontsizeL);
						ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(ll, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == MAGIC) {
						lw = CCLabelTTF::create("魔術師はどうする", "HGRSGU.TTC", fontsizeL);
						lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
						this->addChild(lw, backdepth, choiceS);
					}
				}
			}
			//選択キャラを明確にする(選択されてないキャラは少し暗くする)
			if (choices == CHAR1) {
				//pl1frameの時
				if (pl1frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl1frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl1frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR2) {
				//pl2frameの時
				if (pl2frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl2frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl2frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR3) {
				//pl3frameの時
				if (pl3frame.choicejob == ATTACKER) {
					PL1p->setColor(ccc3(colormax, colormax, colormax));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl3frame.choicejob == HEALER) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colormax, colormax, colormax));
					PL3p->setColor(ccc3(colordown, colordown, colordown));
				}
				else if (pl3frame.choicejob == MAGIC) {
					PL1p->setColor(ccc3(colordown, colordown, colordown));
					PL2p->setColor(ccc3(colordown, colordown, colordown));
					PL3p->setColor(ccc3(colormax, colormax, colormax));
				}
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
			this->removeChildByTag(choiceS);
			//プレイヤーたちの画像の色を戻す
			PL1p->setColor(ccc3(colormax, colormax, colormax));
			PL2p->setColor(ccc3(colormax, colormax, colormax));
			PL3p->setColor(ccc3(colormax, colormax, colormax));
			if (state == true) {
				gameflame++;							//カウント開始
				skillflame++;							//スキルカウント開始
				PLturn();								//主な処理
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
		//剣士のダメージ処理の初期化
		if(pl1frame.choicejob == ATTACKER){
			//剣士ダメージ表示
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			fadeout1 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == ATTACKER) {
			//剣士ダメージ表示
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			fadeout1 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == ATTACKER) {
			//剣士ダメージ表示
			dmf1 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf1->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf1->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			fadeout1 = CCFadeOut::create(2.0f);												//何秒で消える？
			fdoutmov1 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		//聖職者のダメージ処理の初期化
		if (pl1frame.choicejob == HEALER) {
			//聖職者ダメージ表示
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			fadeout2 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov2= CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if(pl2frame.choicejob == HEALER){
			//聖職者ダメージ表示
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			fadeout2 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov2 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == HEALER) {
			//聖職者ダメージ表示
			dmf2 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf2->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf2->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			fadeout2 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov2 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		//魔術師のダメージ処理の初期化
		if (pl1frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			fadeout3 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			fadeout3 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			dmf3 = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			dmf3->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			dmf3->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			fadeout3 = CCFadeOut::create(2.0f);											//何秒で消える？
			fdoutmov3 = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		flag = false;									//フラグをfalseに
		gameflame++;									//カウント開始
		BSturn();										//主な処理
		
		if (gameflame == flame170) {
			//文字を消す
			this->removeChildByTag(normalattackS);		//通常攻撃
			this->removeChildByTag(bossskill1S);		//スキル1			
			this->removeChildByTag(bossskill2S);		//スキル2
			this->removeChildByTag(bossskill3S);		//スキル3
			this->removeChildByTag(bossskill4S);		//スキル4
		}
		if (gameflame > flamemax) {
			if (act_rnd < 20) {
				//文字を消す
				this->removeChildByTag(bossturnI);				//BSTURN
				this->removeChildByTag(damageS);				//効果表記(通常攻撃)
				this->removeChildByTag(bossskill1E);			//パーティクル
				this->removeChildByTag(bossskill1damageS);		//効果表記(スキル1)
				this->removeChildByTag(bossskill2damageS);		//効果表記(スキル2)
				this->removeChildByTag(bossskill3damageS);		//効果表記(スキル3)
				this->removeChildByTag(bossskill4damageS);		//効果表記(スキル4)

				gameflame = 0;									//時間を0へ
				actcnt = 0;										//カウントを0へ
				fntflag = false;								//ダメージ表示フラグをfalseに
				job = NON;										//選んだキャラを初期の状態に戻す
				battle = START;									//バトルを初期の状態に戻す
				choices = CHAR1;								//選択キャラを最初に
				turn = PLAYER;									//プレイヤーのターンへ
			}
			if (act_rnd >= 20 && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//文字を消す
					this->removeChildByTag(damageS);			//効果表記(通常攻撃)
					this->removeChildByTag(bossskill1E);		//パーティクル
					this->removeChildByTag(bossskill1damageS);	//効果表記(スキル1)
					this->removeChildByTag(bossskill2damageS);	//効果表記(スキル2)
					this->removeChildByTag(bossskill3damageS);	//効果表記(スキル3)
					this->removeChildByTag(bossskill4damageS);	//効果表記(スキル4)

					pick_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
					act_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(ボスの動く回数)
					decide_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動き)
					skill_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(スキル)

					actcnt += 1;								//攻撃カウントを増やして2回以上攻撃しないようにする
					gameflame = 0;								//時間を0へ
					fntflag = false;							//ダメージ表示フラグをfalseに
					bsact = PICK;								//ボスの動きを初期に戻す
					turn = BOSS;								//もう一回ボスの行動へ
				}
				else {
					//文字を消す
					this->removeChildByTag(bossturnI);			//BSTURN
					this->removeChildByTag(damageS);			//効果表記(通常攻撃)
					this->removeChildByTag(bossskill1E);		//パーティクル
					this->removeChildByTag(bossskill1damageS);	//効果表記(スキル1)
					this->removeChildByTag(bossskill2damageS);	//効果表記(スキル2)
					this->removeChildByTag(bossskill3damageS);	//効果表記(スキル3)
					this->removeChildByTag(bossskill4damageS);	//効果表記(スキル4)

					gameflame = 0;								//時間を0へ
					actcnt = 0;									//カウントを0へ
					fntflag = false;							//ダメージ表示フラグをfalseに
					job = NON;									//選んだキャラを初期の状態に戻す
					battle = START;								//バトルを初期の状態に戻す
					choices = CHAR1;							//選択キャラを最初に
					turn = PLAYER;								//プレイヤーのターンへ
				}
			}
		}
	}
	//剣士のHPゲージを減らす
	HPpl1->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl1hpgaugewidth * attacker.hp / attacker.hpmax,
		HPpl1->getContentSize().height));
	//剣士のMANAゲージに変化をつける
	MNpl1->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl1mngaugewidth * attacker.mana / attacker.manamax,
		MNpl1->getContentSize().height));
	//聖職者のHPゲージを減らす
	HPpl2->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl2hpgaugewidth * healer.hp / healer.hpmax,
		HPpl2->getContentSize().height));
	//聖職者のMANAゲージに変化をつける
	MNpl2->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl2mngaugewidth * healer.mana / healer.manamax,
		MNpl2->getContentSize().height));
	//魔術師のHPゲージを減らす
	HPpl3->setTextureRect(Rect(HPbar.x, HPbar.y,
		pl3hpgaugewidth * magic.hp / magic.hpmax,
		HPpl3->getContentSize().height));
	//魔術師のMANAゲージに変化をつける
	MNpl3->setTextureRect(Rect(MNbar.x, MNbar.y,
		pl3mngaugewidth * magic.mana / magic.manamax,
		MNpl3->getContentSize().height));
	//ボスのHPゲージに変化をつける
	HPboss->setTextureRect(Rect(HPbar.x, HPbar.y,
		bosshpgaugewidth * valkyrie.hp / valkyrie.hpmax,
		HPboss->getContentSize().height));
	//それぞれのプレイヤーのHP、MANAがMAX以上の時MAXにする
	if (attacker.hp >= attacker.hpmax) {
		p1hpal->setString(std::to_string(attacker.hpmax));
		attacker.hp = attacker.hpmax;
	}
	if (attacker.mana >= attacker.manamax) {
		p1mnal->setString(std::to_string(attacker.manamax));
		attacker.mana = attacker.manamax;
	}
	if (healer.hp >= healer.hpmax) {
		p2hpal->setString(std::to_string(healer.hpmax));
		healer.hp = healer.hpmax;
	}
	if (healer.mana >= healer.manamax) {
		p2mnal->setString(std::to_string(healer.manamax));
		healer.mana = healer.manamax;
	}
	if (magic.hp >= magic.hpmax) {
		p3hpal->setString(std::to_string(magic.hpmax));
		magic.hp = magic.hpmax;
	}
	if (magic.mana >= magic.manamax) {
		p3mnal->setString(std::to_string(magic.manamax));
		magic.mana = magic.manamax;
	}
	//それぞれのプレイヤーのHP、MANAが0以下の時0にする
	//剣士
	if (attacker.hp <= hpmin) {
		p1hpal->setString(std::to_string(hpmin));
		attacker.hp = hpmin;
	}
	if (attacker.mana <= hpmin) {
		p1mnal->setString(std::to_string(hpmin));
		attacker.mana = hpmin;
	}
	//聖職者
	if (healer.hp <= hpmin) {
		p2hpal->setString(std::to_string(hpmin));
		healer.hp = hpmin;
	}
	if (healer.mana <= hpmin) {
		p2mnal->setString(std::to_string(hpmin));
		healer.mana = hpmin;
	}
	//魔術師
	if (magic.hp <= hpmin) {
		p3hpal->setString(std::to_string(hpmin));
		magic.hp = hpmin;
	}
	if (magic.mana <= hpmin) {
		p3mnal->setString(std::to_string(hpmin));
		magic.mana = hpmin;
	}
 }

void BossScene::PLturn()
{
	switch (choices)
	{
	case BossScene::CHAR1: {
		//プレイヤー1の行動

		if (pl1frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl1frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl1frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl1frame.choicejob == HEALER) {
			job = HEALER;
		}
		//通常攻撃関連
		if (pl1 == PL1ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl1 == PL1SKILL) {
			Plskills();
		}
		//攻撃・スキルが終わったら
		if (attackendflag == true || skillendflag == true) {
			choices = CHAR2;								//次のキャラへ
			pl1 = PL1NON;									//pl1は何もしないようにする
			gameflame = 0;									//時間を初期値に戻す
			skillflame = 0;									//スキルの時間を初期値に
			skillendflag = false;							//フラグ初期値に戻す
			attackendflag = false;							//フラグを戻す
		}
		break;
	}
	case BossScene::CHAR2: {
		//プレイヤー2の行動
		if (pl2frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl2frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl2frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl2frame.choicejob == HEALER) {
			job = HEALER;
		}
		//通常攻撃関連
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl2 == PL2SKILL) {
			Plskills();
		}
		if (attackendflag == true || skillendflag == true) {
			choices = CHAR3;
			gameflame = 0;									//時間を初期値に戻す
			skillflame = 0;									//スキルの時間を初期値に
			skillendflag = false;							//フラグ初期値に戻す
			attackendflag = false;							//フラグを戻す
		}
		break;
	}
	case BossScene::CHAR3: {
		//プレイヤー3の行動
		if (pl3frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl3frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl3frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl3frame.choicejob == HEALER) {
			job = HEALER;
		}
		//通常攻撃関連
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl3 == PL3SKILL) {
			Plskills();
		}
		if (attackendflag == true || skillendflag == true) {
			bsact = PICK;								//ボスの動きを初期化
			turn = BOSS;								//ボスのターンへ
			choices = CHAR1;							//選択を最初からに戻す
			this->removeChildByTag(playertrunI);		//PLTURNを消す
			gameflame = 0;								//時間を初期値に戻す
			skillflame = 0;								//スキルの時間を初期値に
			skillendflag = false;						//フラグ初期値に戻す
			attackendflag = false;						//フラグを戻す
			//BSTURN文字表示
			emturn = CCSprite::create("Description/BS.png");							// 配置文字
			emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// 配置場所
			this->addChild(emturn, backdepth, bossturnI);								// 追加
		}
		break;
	}
	default: {
		break;
	}
	}
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

void BossScene::Plattacks()
{
	//剣士
	if (job == ATTACKER) {
		if (gameflame == flame50) {
			//通常攻撃
			if (pl1 == PL1ATTACK) {
				//ボスのHPを減らす
				Damage();
				Boss->runAction(bossrepeat);
				hpcut = (attacker.atk - valkyrie.def);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p1atk = String::createWithFormat("PL1は%iダメージ与えた", hpcut);
				string _p1atk = p1atk->getCString();
				auto p1alabel = Label::createWithSystemFont(_p1atk, "HGRSGU.TTC", fontsizeL);
				p1alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1alabel, backdepth, attackerdamageS);
			}
		}
		//攻撃終わり
		if (pl1 == PL1ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
	//聖職者
	if (job == HEALER) {
		if (gameflame == flame50) {
			//通常攻撃
			if (pl2 == PL2ATTACK) {
				//ボスのHPを減らす
				hpcut = (healer.atk - valkyrie.def);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p2atk = String::createWithFormat("PL2は%iダメージ与えた", hpcut);
				string _p2atk = p2atk->getCString();
				auto p2alabel = Label::createWithSystemFont(_p2atk, "HGRSGU.TTC", fontsizeL);
				p2alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p2alabel, backdepth, healerdamageS);
			}
		}
		//攻撃終わり
		if (pl2 == PL2ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
	//魔術師
	if (job == MAGIC) {
		if (gameflame == flame50) {
			//通常攻撃
			if (pl3 == PL3ATTACK) {
				//ボスのHPを減らす
				hpcut = (magic.atk - valkyrie.def);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p3atk = String::createWithFormat("PL3は%iダメージ与えた", hpcut);
				string _p3atk = p3atk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p3atk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, magicdamageS);
			}
		}
		//攻撃終わり
		if (pl3 == PL3ATTACK && gameflame == flame80) {
			attackendflag = true;
		}
	}
}

void BossScene::Plskills()
{
	//剣士
	if (job == ATTACKER) {
		if (askill == ASKILL1) {
			//ツインフルーレ
			if (gameflame == flame50) {
				//敵単体に小ダメージ2回攻撃
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill1.plist");
				plparticle->setAutoRemoveOnFinish(true);
				//エフェクト処理
				plparticle->resetSystem();								//パーティクル開始
				plparticle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//パーティクルを表示する場所の設定
				this->addChild(plparticle, backdepth, askill1E);		//パーティクルを配置

				//プレイヤー１の減らすMANA
				attacker.mana -= 3;
				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
			}
			//2回目のダメージを与える
			if (skillflame == flame150) {
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			//スキル終わり
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//アーマーブレイク
		if (askill == ASKILL2) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ+防御力ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//敵のステータス(防御力)を下げる値を決める
				//今の防御力の2割減らす
				buffdown = valkyrie.def * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				valkyrie.def -= buffdown;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//ライフソード
		if (askill == ASKILL3) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ＋自身のHPを小回復
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//回復する値を決める
				//今のHPの2割回復
				recovery = attacker.hp * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				attacker.hp += recovery;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//インパクトスラッシュ
		if (askill == ASKILL4) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ+攻撃力ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//敵のステータス(攻撃力)を下げる値を決める
				//今の攻撃力の2割減らす
				buffdown = valkyrie.atk * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//ソードスルー
		if (askill == ASKILL5) {
			if (skillflame == flame50) {
				//敵単体に防御力無視の中ダメージ
				//プレイヤー１の減らすMANA
				attacker.mana -= 4;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				//防御無視なので敵の防御力を引かない
				hpcut = attacker.atk * skillupmedium;
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//紅蓮剣
		if (askill == ASKILL6) {
			if (skillflame == flame50) {
				//敵単体に大ダメージ
				//プレイヤー１の減らすMANA
				attacker.mana -= 5;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				//今の攻撃力の倍のダメージを与える
				hpcut = (attacker.atk * skilluplarge) - valkyrie.def;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p1skl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _p1skl = p1skl->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1skl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//コンディクション
		if (askill == ASKILL7) {
			if (skillflame == flame50) {
				//3ターンの間、自身の攻撃力が小アップ
				//プレイヤー１の減らすMANA
				attacker.mana -= 3;

				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//アタッカーの元の攻撃力の2割ほど攻撃力を上げる
				buffup = attacker.atkmax * buffdownlittle;
				//効果処理
				attacker.atk += buffup;
				//ダメージ表記
				String *p1buf = String::createWithFormat("剣士は攻撃力が少しアップした", buffup);
				string _p1buf = p1buf->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1buf, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//ウォリアーウォークライ
		if (askill == ASKILL8) {
			if (skillflame == flame50) {
				//3ターンの間、自身の攻撃力を大アップ・防御力小ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 7;
				//MANAの数値を変える
				p1mnal->setString(std::to_string(attacker.mana));
				//アタッカーの攻撃力を上げる
				//アタッカーの元の攻撃力ぶん攻撃力を上げる
				buffup = attacker.atkmax;
				//アタッカーの防御力を下げる
				buffdown = attacker.def * buffdownlittle;
				//効果処理
				attacker.atk += buffup;
				attacker.def -= buffdown;

				//ダメージ表記
				String *p1buf = String::createWithFormat("剣士は攻撃力が大幅にアップした", buffup);
				string _p1buf = p1buf->getCString();
				auto p1slabel = Label::createWithSystemFont(_p1buf, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			//ステータス変化表記
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);
				auto pl1buffdown = CCLabelTTF::create("剣士の防御力が少し下がった", "HGRSGU.TTC", fontsizeL);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(buffdownS);				//ステータス変化表記を消す
				skillendflag = true;
			}
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
			if (gameflame == flame50) {
				//敵単体に小ダメージ
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
				plparticle3->setAutoRemoveOnFinish(true);

				//エフェクト処理
				plparticle3->resetSystem();								//パーティクル開始
				plparticle3->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//パーティクルを表示する場所の設定
				this->addChild(plparticle3, backdepth, mskill1E);		//パーティクルを配置

				//プレイヤー3のMANAを減らす
				magic.mana -= 20;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//ボスのHPを減らす
				hpcut = (pl3frame.matk - valkyrie.mdef);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//アーマーショット
		if(mskill == MSKILL2) {
			if (gameflame == flame50) {
				//敵単体に小ダメージ+自身の防御小アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//ボスのHPを減らす
				hpcut = (pl3frame.matk - valkyrie.mdef);
				buffup = pl3frame.def / skilluplarge;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				pl3frame.def += buffup;

				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("魔術師の防御力が少し上がった", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//マジックバースト
		if (mskill == MSKILL3) {
			if (gameflame == flame50) {
				//敵単体に中ダメージ + 敵の攻撃ダウン
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//ボスのHPを減らす
				hpcut = (pl3frame.matk * skillupmedium) - valkyrie.mdef;
				//魔術師の今の攻撃力の５割の攻撃力を下げる
				buffdown = valkyrie.atk * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;

				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", buffdown);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("敵の攻撃力が下がった", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//VFD
		if (mskill == MSKILL4) {
			if (gameflame == flame50) {
				//敵単体に特大ダメージ
				//プレイヤー3のMANAを減らす
				magic.mana -= 7;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//ボスのHPを減らす
				hpcut = (pl3frame.matk * skilluplarge) - valkyrie.mdef;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//グランツ
		if (mskill == MSKILL5 || mskill == MSKILL5 || mskill == MSKILL5) {
			if (gameflame == flame50) {
				//3ターンの間、味方全体の攻撃力と防御力小アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//味方全員のステータスを上げる
				//PL1の攻撃と防御を上げる
				pl1frame.atk = pl1frame.atk * skillupmedium;
				pl1frame.def = pl1frame.def * skillupmedium;
				//PL2のry
				pl2frame.atk = pl2frame.atk * skillupmedium;
				pl2frame.def = pl2frame.def * skillupmedium;
				//PL3のry
				pl3frame.atk = pl3frame.atk * skillupmedium;
				pl3frame.def = pl3frame.def * skillupmedium;
				
				//ステータスアップ表記
				auto pl3buffup = CCLabelTTF::create("味方の攻撃力と防御力が少し上がった", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//神の御剣
		if (mskill == MSKILL6) {
			if (gameflame == flame50) {
				//2ターンの間、味方全体の攻撃力と防御力大アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 5;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//味方全員のステータスを上げる
				//PL1の攻撃と防御を上げる
				pl1frame.atk = pl1frame.atk * skilluplarge;
				pl1frame.def = pl1frame.def * skilluplarge;
				//PL2のry
				pl2frame.atk = pl2frame.atk * skilluplarge;
				pl2frame.def = pl2frame.def * skilluplarge;
				//PL3のry
				pl3frame.atk = pl3frame.atk * skilluplarge;
				pl3frame.def = pl3frame.def * skilluplarge;

				//ステータスアップ表記
				auto pl3buffup = CCLabelTTF::create("味方の攻撃力と防御力が大幅に上がった", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//魔力吸収
		if (mskill == MSKILL7) {
			//味方単体のMPを10%吸収し自身のMPを回復する
		}
		//心呼吸
		if (mskill == MSKILL8) {
			if (gameflame == flame50) {
				//3ターンの間、自身のMPを小回復
				//プレイヤー3のMANAを減らす
				magic.mana -= 4;
				//MANAの数値を変える
				p3mnal->setString(std::to_string(pl3frame.mana));
				//魔術師のmanaを回復させる
				recovery = pl3frame.manamax / skilluplittle;
		
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", recovery);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
	}
	//聖職者
	if (job == HEALER) {
		//魔力供給
		if (hskill == HSKILL1) {
			if (gameflame == flame50) {
				//味方単体に自身のMPを小与える
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill2.plist");

				plparticle2->setAutoRemoveOnFinish(true);

				//エフェクト処理
				plparticle2->resetSystem();								//パーティクル開始
				plparticle2->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//パーティクルを表示する場所の設定
				this->addChild(plparticle2, backdepth, hskill1E);		//パーティクルを配置

				//プレイヤー１のMANAを減らす
				healer.mana -= 3;
				//MANAの数値を変える
				p2mnal->setString(std::to_string(healer.mana));
				//ボスのHPを減らす
				valkyrie.hp -= (healer.matk - valkyrie.mdef);
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//エフェクトを消す
				this->removeChildByTag(healerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//死者の経典
		if (hskill == HSKILL2) {
			if (gameflame == flame50) {
				//敵単体の攻撃力中ダウン
				//プレイヤー１のMANAを減らす
				healer.mana -= 5;
				//MANAの数値を変える
				p2mnal->setString(std::to_string(healer.mana));
				//ボスの攻撃力を中ダウン
				buffdown = valkyrie.atk * buffdownmedium;
				valkyrie.atk = buffdown;

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("敵の攻撃力を下げた", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);
				
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//聖者の経典
		if (hskill == HSKILL3) {
			if (gameflame == flame50) {
				//敵単体の防御力中ダウン
				//プレイヤー１のMANAを減らす
				healer.mana -= 5;
				//MANAの数値を変える
				p2mnal->setString(std::to_string(healer.mana));
				//ボスの攻撃力を中ダウン
				buffdown = valkyrie.def * buffdownmedium;
				valkyrie.def = buffdown;

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("敵の防御力を下げた", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
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
			if (gameflame == flame50) {
				//味方全体のHPを小回復
				//プレイヤー１のMANAを減らす
				healer.mana -= 4;
				//MANAの数値を変える
				p2mnal->setString(std::to_string(healer.mana));
				//プレイヤー全員のHPを小回復
				pl1frame.hp += pl1frame.hpmax * buffdownlittle;
				healer.hp += healer.hpmax * buffdownlittle;
				pl3frame.hp += pl3frame.hpmax * buffdownlittle;
				//プレイヤーのHPの数値を変える
				p1hpal->setString(std::to_string(pl1frame.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(pl3frame.hp));

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("味方のHPが少し回復した", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//セイントオーダー
		if (hskill == HSKILL7) {
			if (gameflame == flame50) {
				//味方全体のHPを大回復
				//プレイヤー１のMANAを減らす
				healer.mana -= 7;
				//MANAの数値を変える
				p2mnal->setString(std::to_string(healer.mana));
				//プレイヤー全員のHPを大回復
				attacker.hp += attacker.hpmax * buffdownlarge;
				healer.hp += healer.hpmax * buffdownlarge;
				magic.hp += magic.hpmax * buffdownlarge;
				//プレイヤーのHPの数値を変える
				p1hpal->setString(std::to_string(attacker.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(magic.hp));

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("味方のHPが少し回復した", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
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
		if (pick_rnd < fortypercent) {
			job = ATTACKER;
		}
		if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
			job = HEALER;
		}
		if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
			job = MAGIC;
		}
		bsact = DECIDE;
	}
	//通常攻撃かスキルかを決める
	if (bsact == DECIDE) {
		if (decide_rnd < sixtypercent) {
			bsact = BOSSATTACK;
		}
		if (decide_rnd >= sixtypercent && decide_rnd <= rndmax ) {
			bsact = BOSSSKILL;
		}
	}
	//どのスキルで攻撃するかを決める
	if (bsact == BOSSSKILL) {
		if (skill_rnd < fiftypercent) {
			bskill = BSKILL1;
		}
		if (skill_rnd >= fiftypercent && skill_rnd < eightypercent) {
			bskill = BSKILL2;
		}
		if (skill_rnd >= eightypercent && skill_rnd < ninetypercent) {
			bskill = BSKILL3;
		}
		if (skill_rnd >= ninetypercent && skill_rnd <= rndmax) {
			bskill = BSKILL4;
		}
	}
	//選んだキャラを出力に表示
	log("job %i", job);					
	//カウントを出力に表示
	log("actcnt %i", actcnt);			
	//プレイヤー1のHPを表示
	CCString *hpstr1 = CCString::createWithFormat("現在PL1HPは%dです", pl1frame.hp);
	log("%s", hpstr1->getCString());	
	//プレイヤー2のHPを表示
	CCString *hpstr2 = CCString::createWithFormat("現在PL2HPは%dです", pl2frame.hp);
	log("%s", hpstr2->getCString());	
	//プレイヤー3のHPを表示
	CCString *hpstr3 = CCString::createWithFormat("現在PL3MPは%dです", pl3frame.mana);
	log("%s", hpstr3->getCString());	
	//ボスのHPを表示
	CCString *hpstrBS = CCString::createWithFormat("現在ヴァルキリーHPは%dです", valkyrie.hp);
	log("%s", hpstrBS->getCString());	

	//攻撃モードの時
	if (bsact == BOSSATTACK) {
		if (gameflame == flame80) {
			//フレームが80(仮)になったら文字を表示する
			auto atk = CCLabelTTF::create("「やあっ！(通常攻撃)」", "HGRSGU.TTC", fontsizeL);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, backdepth, normalattackS);
			//ボスの画像を揺らす処理
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + moverange)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);
			//HPをへらす
			//剣士
			if (job == ATTACKER) {
				hpcut = (valkyrie.atk - attacker.def);					//減らすHPを計算
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				attacker.hp -= hpcut;									//HPを減らす
				PL1p->setColor(ccc3(colormax, colordown, colordown));	//ダメージを受けるプレイヤーは赤くする
				p1hpal->setString(std::to_string(attacker.hp));			//ダメージを受けるプレイヤーのHPを減らす
				dmf1->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf1, onece);							//ダメージ文字を出す
				dmf1->runAction(fadeout1);								//ダメージ文字をフェードアウトさせる
				dmf1->runAction(fdoutmov1);								//ダメージ文字を上に動かす
				Damage();												//揺らす処理↓以下同文
				PL1p->runAction(pl1repeat1b);							
				HPpl1->runAction(pl1repeat2b);
				MNpl1->runAction(pl1repeat3b);
				p1hpal->runAction(pl1repeat4b);
				p1hpmaxal->runAction(pl1repeat5b);
				p1mnal->runAction(pl1repeat6b);
				p1mnmaxal->runAction(pl1repeat7b);
			}
			//聖職者
			else if(job == HEALER){
				hpcut = (valkyrie.atk - healer.def);
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				healer.hp -= hpcut;
				PL2p->setColor(ccc3(colormax, colordown, colordown));
				p2hpal->setString(std::to_string(healer.hp));
				dmf2->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf2, onece);							//ダメージ文字を出す
				dmf2->runAction(fadeout2);								//ダメージ文字をフェードアウトさせる
				dmf2->runAction(fdoutmov2);								//ダメージ文字を上に動かす
				Damage();												//揺らす処理↓以下同文
				PL2p->runAction(pl2repeat1b);
				HPpl2->runAction(pl2repeat2b);
				MNpl2->runAction(pl2repeat3b);
				p2hpal->runAction(pl2repeat4b);
				p2hpmaxal->runAction(pl2repeat5b);
				p2mnal->runAction(pl2repeat6b);
				p2mnmaxal->runAction(pl2repeat7b);
			}
			//魔術師
			else if (job == MAGIC) {
				hpcut = (valkyrie.atk - magic.def);
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				magic.hp -= hpcut;
				PL3p->setColor(ccc3(colormax, colordown, colordown));
				p3hpal->setString(std::to_string(magic.hp));
				dmf3->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf3, onece);							//ダメージ文字を出す
				dmf3->runAction(fadeout3);								//ダメージ文字をフェードアウトさせる
				dmf3->runAction(fdoutmov3);								//ダメージ文字を上に動かす
				Damage();												//揺らす処理↓以下同文
				PL3p->runAction(pl3repeat1b);
				HPpl3->runAction(pl3repeat2b);
				MNpl3->runAction(pl3repeat3b);
				p3hpal->runAction(pl3repeat4b);
				p3hpmaxal->runAction(pl3repeat5b);
				p3mnal->runAction(pl3repeat6b);
				p3mnmaxal->runAction(pl3repeat7b);
			}
			//誰かのHPがゼロになったら
			if ((pl1frame.hp <= 0) && (pl2frame.hp <= 0) && (pl3frame.hp <= 0)) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0f, pScene);	// 1秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}
		}
		//キャラ画像の色を戻す
		if (gameflame == flame100) {
			PL1p->setColor(ccc3(colormax, colormax, colormax));
			PL2p->setColor(ccc3(colormax, colormax, colormax));
			PL3p->setColor(ccc3(colormax, colormax, colormax));
		}
		//効果処理
		//フレームが230(仮)になると効果を表記
		if (gameflame == flame230) {
			if (job == ATTACKER) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("アタッカーに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p1bsalabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p1bsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1bsalabel, backdepth, damageS);
			}
			else if (job == HEALER) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("ヒーラーに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, damageS);
			}
			else if (job == MAGIC) {
				//ダメージ表記
				String *p1bsatk = String::createWithFormat("マジックに%iダメージ与えた", hpcut);
				string _p1bsatk = p1bsatk->getCString();
				auto p3alabel = Label::createWithSystemFont(_p1bsatk, "HGRSGU.TTC", fontsizeL);
				p3alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3alabel, backdepth, damageS);
			}
		}
	}
	//ヴァルキリースキル
	if (bsact == BOSSSKILL) {
		//一の太刀
		if (bskill == BSKILL1) {
			//フレームが80(仮)になるとスキルの名前表示
			if (gameflame == flame80) {
				auto Gskill1 = CCLabelTTF::create("「くらえ…！」", "JiyunoTsubasa.ttf", fontsizeL);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, backdepth, bossskill1S);
			}
			//揺らす処理
			if (gameflame == flame210) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + 30)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
					NULL
				);
				//揺らす
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// 画面サイズ取得
				Size winSize = Director::getInstance()->getVisibleSize();

				//背景を揺らす
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f + 30)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f)),
					NULL
				);
				//何回揺らすか
				auto backrepeat = Repeat::create(backmove, continuity2);
				//揺らす
				back->runAction(backrepeat);			

				//揺れる処理
				Damage();												//揺らす処理↓以下同文
				//PL1ダメージを受けた時に揺れる処理
				PL1p->runAction(pl1repeat1a);
				HPpl1->runAction(pl1repeat2a);
				MNpl1->runAction(pl1repeat3a);
				p1hpal->runAction(pl1repeat4a);
				p1hpmaxal->runAction(pl1repeat5a);
				p1mnal->runAction(pl1repeat6a);
				p1mnmaxal->runAction(pl1repeat7a);
				//PL2ダメージを受けた時に揺れる処理
				PL2p->runAction(pl2repeat1a);
				HPpl2->runAction(pl2repeat2a);
				MNpl2->runAction(pl2repeat3a);
				p2hpal->runAction(pl2repeat4a);
				p2hpmaxal->runAction(pl2repeat5a);
				p2mnal->runAction(pl2repeat6a);
				p2mnmaxal->runAction(pl2repeat7a);
				//PL3ダメージを受けた時に揺れる処理
				PL3p->runAction(pl3repeat1a);
				HPpl3->runAction(pl3repeat2a);
				MNpl3->runAction(pl3repeat3a);
				p3hpal->runAction(pl3repeat4a);
				p3hpmaxal->runAction(pl3repeat5a);
				p3mnal->runAction(pl3repeat6a);
				p3mnmaxal->runAction(pl3repeat7a);
				//プレイヤー全員のHPを減らす
				//受けたダメージをゲージ上に表示
				//剣士
				hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				attacker.hp -= hpcut;									//HPを減らす
				dmf1->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf1, onece);							//ダメージ文字を出す
				dmf1->runAction(fadeout1);								//フェードアウト処理
				dmf1->runAction(fdoutmov1);								//上に上がっていく処理
				//聖職者
				hpcut = (valkyrie.atk * skillupmedium) - healer.def;	//減らすダメージを計算
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				healer.hp -= hpcut;									//HPを減らす
				dmf2->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf2, onece);							//ダメージ文字を出す
				dmf2->runAction(fadeout2);								//ダメージ文字をフェードアウトさせる
				dmf2->runAction(fdoutmov2);								//ダメージ文字を上に動かす
				//魔術師
				hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//減らすダメージを計算
				//もし減らすHPが1以下の場合1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				magic.hp -= hpcut;									//HPを減らす
				dmf3->setString(std::to_string(hpcut));					//ダメージを変化させる
				this->addChild(dmf3, onece);							//ダメージ文字を出す
				dmf3->runAction(fadeout3);								//ダメージ文字をフェードアウトさせる
				dmf3->runAction(fdoutmov3);								//ダメージ文字を上に動かす
				//HPの数値を変える
				p1hpal->setString(std::to_string(attacker.hp));
				p2hpal->setString(std::to_string(healer.hp));
				p3hpal->setString(std::to_string(magic.hp));
				//紅に染めてこのキャラを
				PL1p->setColor(ccc3(colormax, colordown, colordown));
				PL2p->setColor(ccc3(colormax, colordown, colordown));
				PL3p->setColor(ccc3(colormax, colordown, colordown));
				//HPがゼロになったら
				if ((attacker.hp <= 0)&&(healer.hp <= 0)&&(magic.hp <= 0)) {
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
			//フレームが230(仮)になるとダメージ表記
			if (gameflame == flame230) {
				auto Gskill1dec = CCLabelTTF::create("全員にダメージを与える", "HGRSGU.TTC", fontsizeL);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, backdepth, bossskill1damageS);

				//キャラの色を戻す
				PL1p->setColor(ccc3(colormax, colormax, colormax));
				PL2p->setColor(ccc3(colormax, colormax, colormax));
				PL3p->setColor(ccc3(colormax, colormax, colormax));
			}
		}
		//二の太刀
		if (bskill == BSKILL2) {
			//フレームが80(仮)になるとスキルの名前表示
			if (gameflame == flame80) {
				auto Gskill2 = CCLabelTTF::create("「やあああ！」", "HGRSGU.TTC", fontsizeL);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, backdepth, bossskill2S);

				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//ダメージを計算
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;									//HPをへらす
					PL1p->setColor(ccc3(colormax, colordown, colordown));	//受けるやつを赤くする
					dmf1->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf1, onece);							//ダメージ文字を出す
					dmf1->runAction(fadeout1);								//ダメージ文字をフェードアウトさせる
					dmf1->runAction(fdoutmov1);								//ダメージ文字を上に動かす
					p1hpal->setString(std::to_string(attacker.hp));			//数値を変える↓以下同文
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - healer.def);
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					healer.hp -= hpcut;
					PL2p->setColor(ccc3(colormax, colordown, colordown));
					dmf2->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf2, onece);							//ダメージ文字を出す
					dmf2->runAction(fadeout2);								//ダメージ文字をフェードアウトさせる
					dmf2->runAction(fdoutmov2);								//ダメージ文字を上に動かす
					p2hpal->setString(std::to_string(healer.hp));
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - magic.def);
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					magic.hp -= hpcut;
					PL3p->setColor(ccc3(colormax, colordown, colordown));
					dmf3->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf3, onece);							//ダメージ文字を出す
					dmf3->runAction(fadeout3);								//ダメージ文字をフェードアウトさせる
					dmf3->runAction(fdoutmov3);								//ダメージ文字を上に動かす
					p3hpal->setString(std::to_string(magic.hp));
				}

				//エフェクト
				//エフェクトの表示
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//エフェクトの流れを指定
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				particle->resetSystem();									//エフェクト開始
				particle->setPosition(ccp(rightSize.width / 2,
										  rightSize.height / 3));			//エフェクトを表示する場所の設定
				this->addChild(particle, backdepth, bossskill1E);			//エフェクトを配置
			}
			//二回目の攻撃
			if (gameflame == flame150) {
				//二回目のHPを減らす
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//ダメージ計算
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;									//HPを減らす
					PL1p->setColor(ccc3(colormax, colordown, colordown));	//ダメージをくらった(プレイヤーの画像を赤くする)
					dmf1->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf1, onece);							//ダメージ文字を出す
					dmf1->runAction(fadeout1);								//ダメージ文字をフェードアウトさせる
					dmf1->runAction(fdoutmov1);								//ダメージ文字を上に動かす
					p1hpal->setString(std::to_string(attacker.hp));			//HP数値を減らす
					Damage();												//揺らす処理↓以下同文
					PL1p->runAction(pl1repeat1a);
					HPpl1->runAction(pl1repeat2a);
					MNpl1->runAction(pl1repeat3a);
					p1hpal->runAction(pl1repeat4a);
					p1hpmaxal->runAction(pl1repeat5a);
					p1mnal->runAction(pl1repeat6a);
					p1mnmaxal->runAction(pl1repeat7a);
				}
				else if (job == HEALER) {
					hpcut = (valkyrie.atk - healer.def);
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					healer.hp -= hpcut;
					PL2p->setColor(ccc3(colormax, colordown, colordown));
					p2hpal->setString(std::to_string(healer.hp));
					dmf2->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf2, onece);							//ダメージ文字を出す
					dmf2->runAction(fadeout2);								//ダメージ文字をフェードアウトさせる
					dmf2->runAction(fdoutmov2);								//ダメージ文字を上に動かす
					Damage();												//揺らす処理↓以下同文
					PL2p->runAction(pl2repeat1a);
					HPpl2->runAction(pl2repeat2a);
					MNpl2->runAction(pl2repeat3a);
					p2hpal->runAction(pl2repeat4a);
					p2hpmaxal->runAction(pl2repeat5a);
					p2mnal->runAction(pl2repeat6a);
					p2mnmaxal->runAction(pl2repeat7a);
				}
				else if (job == MAGIC) {
					hpcut = (valkyrie.atk - magic.def);
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					magic.hp -= hpcut;
					PL3p->setColor(ccc3(colormax, colordown, colordown));
					p3hpal->setString(std::to_string(magic.hp));
					dmf3->setString(std::to_string(hpcut));					//ダメージを変化させる
					this->addChild(dmf3, onece);							//ダメージ文字を出す
					dmf3->runAction(fadeout3);								//ダメージ文字をフェードアウトさせる
					dmf3->runAction(fdoutmov3);								//ダメージ文字を上に動かす
					Damage();												//揺らす処理↓以下同文
					PL3p->runAction(pl3repeat1a);
					HPpl3->runAction(pl3repeat2a);
					MNpl3->runAction(pl3repeat3a);
					p3hpal->runAction(pl3repeat4a);
					p3hpmaxal->runAction(pl3repeat5a);
					p3mnal->runAction(pl3repeat6a);
					p3mnmaxal->runAction(pl3repeat7a);
				}
				//HPがゼロになったら画面遷移
				if ((attacker.hp <= 0) && (healer.hp <= 0) && (magic.hp <= 0)) {
					Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
					TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
					Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
				}
				//キャラの画像の色を戻す
				PL1p->setColor(ccc3(colormax, colormax, colormax));
				PL2p->setColor(ccc3(colormax, colormax, colormax));
				PL3p->setColor(ccc3(colormax, colormax, colormax));
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				auto Gskill2dec = CCLabelTTF::create("２回ダメージにダメージ", "HGRSGU.TTC", fontsizeL);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, backdepth, bossskill2damageS);
			}
		}
		//六帝の陣
		if (bskill == BSKILL3) {
			if (gameflame == flame80) {
				auto Gskill3 = CCLabelTTF::create("「これでもヴァルキリーなので」", "HGRSGU.TTC", fontsizeL);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, backdepth, bossskill3S);

				//ヴァルキリーの防御力を増やす
				valkyrie.def += 2;					
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				auto Gskill3dec = CCLabelTTF::create("ヴァルキリーの防御力が大幅に上がった", "HGRSGU.TTC", fontsizeM);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, backdepth, bossskill3damageS);
			}
		}
		//エステ
		if (bskill == BSKILL4) {
			if (gameflame == flame80) {
				auto Gskill4 = CCLabelTTF::create("「エステ…ｽｷｨ…」", "HGRSGU.TTC", fontsizeL);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, backdepth, bossskill4S);

				//ヴァルキリーのHPを増やす
				bsskillrecovery = valkyrie.hp / tenpercent;
				valkyrie.hp += bsskillrecovery;					
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				//回復表記
				String *Gskill4dec = String::createWithFormat("ヴァルキリーは%i、HPが回復した", bsskillrecovery);
				string _Gskill4dec = Gskill4dec->getCString();
				auto bss4alabel = Label::createWithSystemFont(_Gskill4dec, "HGRSGU.TTC", fontsizeL);
				bss4alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(bss4alabel, backdepth, bossskill4damageS);
			}
		}
	}
}

//画像を揺らすための処理
void BossScene::Damage()
{
//剣士
	//pl1frame.choisjobが剣士の場合
	if (pl1frame.choicejob == ATTACKER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//揺らす処理剣士,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//揺らす処理剣士,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//揺らす処理剣士,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//揺らす処理剣士,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//揺らす処理剣士,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//揺らす処理剣士,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理剣士,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//揺らす処理剣士,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//揺らす処理剣士,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//揺らす処理剣士,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//揺らす処理剣士,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//揺らす処理剣士,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//揺らす処理剣士,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
	//pl2frame.choisjobが剣士の場合
	if (pl2frame.choicejob == ATTACKER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//揺らす処理剣士,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//揺らす処理剣士,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//揺らす処理剣士,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//揺らす処理剣士,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//揺らす処理剣士,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//揺らす処理剣士,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理剣士,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//揺らす処理剣士,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//揺らす処理剣士,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//揺らす処理剣士,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//揺らす処理剣士,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//揺らす処理剣士,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//揺らす処理剣士,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
	//pl3frame.choisjobが剣士の場合
	if (pl3frame.choicejob == ATTACKER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
		auto pl1move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1a = Repeat::create(pl1move1a, continuity1);
		//揺らす処理剣士,2a
		auto pl1move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2a = Repeat::create(pl1move2a, continuity1);
		//揺らす処理剣士,3a
		auto pl1move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3a = Repeat::create(pl1move3a, continuity1);
		//揺らす処理剣士,4a
		auto pl1move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4a = Repeat::create(pl1move4a, continuity1);
		//揺らす処理剣士,5a
		auto pl1move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5a = Repeat::create(pl1move5a, continuity1);
		//揺らす処理剣士,6a
		auto pl1move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6a = Repeat::create(pl1move6a, continuity1);
		//揺らす処理剣士,7a
		auto pl1move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7a = Repeat::create(pl1move7a, continuity1);
		//揺れが小さいやつ
		//揺らす処理剣士,1b
		auto pl1move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl1repeat1b = Repeat::create(pl1move1b, continuity1);
		//揺らす処理剣士,2b
		auto pl1move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat2b = Repeat::create(pl1move2b, continuity1);
		//揺らす処理剣士,3b
		auto pl1move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl1repeat3b = Repeat::create(pl1move3b, continuity1);
		//揺らす処理剣士,4b
		auto pl1move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat4b = Repeat::create(pl1move4b, continuity1);
		//揺らす処理剣士,5b
		auto pl1move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat5b = Repeat::create(pl1move5b, continuity1);
		//揺らす処理剣士,6b
		auto pl1move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl1repeat6b = Repeat::create(pl1move6b, continuity1);
		//揺らす処理剣士,7b
		auto pl1move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl1repeat7b = Repeat::create(pl1move7b, continuity1);
	}
//聖職者
	//pl1frame.choisjobが聖職者の場合
	if (pl1frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//揺らす処理聖職者,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//揺らす処理聖職者,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//揺らす処理聖職者,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//揺らす処理聖職者,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//揺らす処理聖職者,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//揺らす処理聖職者,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理聖職者,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//揺らす処理聖職者,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//揺らす処理聖職者,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//揺らす処理聖職者,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//揺らす処理聖職者,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//揺らす処理聖職者,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//揺らす処理聖職者,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
	//pl2frame.choisjobが聖職者の場合
	if (pl2frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//揺らす処理聖職者,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//揺らす処理聖職者,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//揺らす処理聖職者,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//揺らす処理聖職者,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//揺らす処理聖職者,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//揺らす処理聖職者,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理聖職者,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//揺らす処理聖職者,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//揺らす処理聖職者,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//揺らす処理聖職者,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//揺らす処理聖職者,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//揺らす処理聖職者,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//揺らす処理聖職者,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
	//pl3frame.choisjobが聖職者の場合
	if (pl3frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
		auto pl2move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1a = Repeat::create(pl2move1a, continuity1);
		//揺らす処理聖職者,2a
		auto pl2move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2a = Repeat::create(pl2move2a, continuity1);
		//揺らす処理聖職者,3a
		auto pl2move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3a = Repeat::create(pl2move3a, continuity1);
		//揺らす処理聖職者,4a
		auto pl2move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4a = Repeat::create(pl2move4a, continuity1);
		//揺らす処理聖職者,5a
		auto pl2move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5a = Repeat::create(pl2move5a, continuity1);
		//揺らす処理聖職者,6a
		auto pl2move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6a = Repeat::create(pl2move6a, continuity1);
		//揺らす処理聖職者,7a
		auto pl2move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7a = Repeat::create(pl2move7a, continuity1);
		//揺れが小さいやつ
		//揺らす処理聖職者,1b
		auto pl2move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl2repeat1b = Repeat::create(pl2move1b, continuity1);
		//揺らす処理聖職者,2b
		auto pl2move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat2b = Repeat::create(pl2move2b, continuity1);
		//揺らす処理聖職者,3b
		auto pl2move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl2repeat3b = Repeat::create(pl2move3b, continuity1);
		//揺らす処理聖職者,4b
		auto pl2move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat4b = Repeat::create(pl2move4b, continuity1);
		//揺らす処理聖職者,5b
		auto pl2move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat5b = Repeat::create(pl2move5b, continuity1);
		//揺らす処理聖職者,6b
		auto pl2move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl2repeat6b = Repeat::create(pl2move6b, continuity1);
		//揺らす処理聖職者,7b
		auto pl2move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl2repeat7b = Repeat::create(pl2move7b, continuity1);
	}
//魔術師
	//pl1frame.choisjobが魔術師の場合
	if (pl1frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//揺らす処理魔術師,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//揺らす処理魔術師,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//揺らす処理魔術師,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//揺らす処理魔術師,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//揺らす処理魔術師,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//揺らす処理魔術師,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理魔術師,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//揺らす処理魔術師,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//揺らす処理魔術師,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//揺らす処理魔術師,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//揺らす処理魔術師,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//揺らす処理魔術師,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//揺らす処理魔術師,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
	//pl2frame.choisjobが魔術師の場合
	if (pl2frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//揺らす処理魔術師,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//揺らす処理魔術師,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//揺らす処理魔術師,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//揺らす処理魔術師,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//揺らす処理魔術師,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//揺らす処理魔術師,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//揺れ幅が小さいやつ
		//揺らす処理魔術師,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//揺らす処理魔術師,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//揺らす処理魔術師,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//揺らす処理魔術師,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//揺らす処理魔術師,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//揺らす処理魔術師,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//揺らす処理魔術師,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
	//pl3frame.choisjobが魔術師の場合
	if (pl3frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
		auto pl3move1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1a = Repeat::create(pl3move1a, continuity1);
		//揺らす処理魔術師,2a
		auto pl3move2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2a = Repeat::create(pl3move2a, continuity1);
		//揺らす処理魔術師,3a
		auto pl3move3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3a = Repeat::create(pl3move3a, continuity1);
		//揺らす処理魔術師,4a
		auto pl3move4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4a = Repeat::create(pl3move4a, continuity1);
		//揺らす処理魔術師,5a
		auto pl3move5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5a = Repeat::create(pl3move5a, continuity1);
		//揺らす処理魔術師,6a
		auto pl3move6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6a = Repeat::create(pl3move6a, continuity1);
		//揺らす処理魔術師,7a
		auto pl3move7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7a = Repeat::create(pl3move7a, continuity1);
		//揺れが小さいやつ
		//揺らす処理魔術師,1b
		auto pl3move1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		pl3repeat1b = Repeat::create(pl3move1b, continuity1);
		//揺らす処理魔術師,2b
		auto pl3move2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat2b = Repeat::create(pl3move2b, continuity1);
		//揺らす処理魔術師,3b
		auto pl3move3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		pl3repeat3b = Repeat::create(pl3move3b, continuity1);
		//揺らす処理魔術師,4b
		auto pl3move4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat4b = Repeat::create(pl3move4b, continuity1);
		//揺らす処理魔術師,5b
		auto pl3move5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat5b = Repeat::create(pl3move5b, continuity1);
		//揺らす処理魔術師,6b
		auto pl3move6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		pl3repeat6b = Repeat::create(pl3move6b, continuity1);
		//揺らす処理魔術師,7b
		auto pl3move7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		pl3repeat7b = Repeat::create(pl3move7b, continuity1);
	}
//ボス
	auto bossmove = CCSequence::create(
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
		NULL
	);
	bossrepeat = Repeat::create(bossmove, continuity1);
}

// いつも出ている画像
void BossScene::BossBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	//rightSize = Director::getInstance()->getVisibleSize();
	rightSize = CCDirector::sharedDirector()->getWinSize();
	//画像のポイントを再設定
	CCPoint ancharpoint = ccp(0.0f, 0.0f);		//左寄せ
	CCPoint anancharpoint = ccp(1.0f, 0.0f);	//右寄せ
//背景
	back = CCSprite::create("BackImage/ST_Boss.png");							//背景の画像指定
	back->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));			// 表示座標指定
	this->addChild(back, backdepth);											//追加
//テロップ
	auto Telop = CCSprite::create("UI/UI_Terop.png");
	Telop->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
	Telop->setScaleX(1.5f);
	this->addChild(Telop, backdepth);
//ボス
	// ボスの表示
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");							// 画像指定
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));		// 表示座標指定
	this->addChild(Boss, backdepth);											// 追加
	//BOSSHPバー
	HPboss = CCSprite::create("UI/Status/UI_Status_EMLife.png");
	HPboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPboss->setAnchorPoint(ancharpoint);
	HPbar = HPboss->getTextureRect().origin;
	bosshpgaugewidth = HPboss->getContentSize().width;
	this->addChild(HPboss, middledepth);
	//うしろの黒いバー
	auto HPLboss = CCSprite::create("UI/Status/UI_Status_EMLost.png");
	HPLboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPLboss->setAnchorPoint(ancharpoint);
	bosshpgaugewidth = HPLboss->getContentSize().width;
	this->addChild(HPLboss, backdepth);
//剣士のステータスバー
	//ステータスのプレート(一番後ろのやつ)
	PL1p= CCSprite::create("UI/Status/UI_Status_Attacker.png");
	if (pl1frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == ATTACKER) {
		PL1p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL1p->setScaleX(0.6f);
	PL1p->setScaleY(0.8f);
	this->addChild(PL1p, backdepth);
	//HPバー
	HPpl1 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		HPpl1->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl1->setAnchorPoint(ancharpoint);
	HPpl1->setScaleX(0.6f);
	HPpl1->setScaleY(0.8f);
	HPbar = HPpl1->getTextureRect().origin;
	pl1hpgaugewidth = HPpl1->getContentSize().width;
	this->addChild(HPpl1, prevdepth);
	//MANAバー
	MNpl1 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		MNpl1->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl1->setAnchorPoint(ancharpoint);
	MNpl1->setScaleX(0.6f);
	MNpl1->setScaleY(0.8f);
	MNbar = MNpl1->getTextureRect().origin;
	pl1mngaugewidth = MNpl1->getContentSize().width;
	this->addChild(MNpl1, prevdepth);
	//PL1HP表記
	//数値が変わる部分
	p1hpal = LabelTTF::create(std::to_string(attacker.hp), "HGRSGU.TTC", fontsizeM);
	p1hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	if (pl1frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p1hpal->setColor(ccc3(150,255,255));			//水色
	p1hpal->setAnchorPoint(anancharpoint);
	this->addChild(p1hpal, prevdepth);
	//HPの最大値
	p1hpmaxal = LabelTTF::create("/" + std::to_string(attacker.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p1hpmaxal, prevdepth);
	//PL1MANA表記
	//数値が変わる部分
	p1mnal = LabelTTF::create(std::to_string(attacker.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p1mnal->setColor(ccc3(192, 136, 255));			//紫
	p1mnal->setAnchorPoint(anancharpoint);
	this->addChild(p1mnal, prevdepth);
	//MPの最大値
	p1mnmaxal = LabelTTF::create("/" + std::to_string(attacker.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		p1mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p1mnmaxal, prevdepth);
//聖職者のステータスバー
	////ステータスのプレート(一番後ろのやつ)
	PL2p = CCSprite::create("UI/Status/UI_Status_Healer.png");					//画像指定
	if (pl1frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == HEALER) {
		PL2p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL2p->setScaleX(0.6f);														//大きさ変更
	PL2p->setScaleY(0.8f);
	this->addChild(PL2p, backdepth);											//追加
	//HPバー
	HPpl2 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		HPpl2->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl2->setAnchorPoint(ancharpoint);
	HPpl2->setScaleX(0.6f);
	HPpl2->setScaleY(0.8f);
	HPbar = HPpl2->getTextureRect().origin;
	pl2hpgaugewidth = HPpl2->getContentSize().width;
	this->addChild(HPpl2, prevdepth);
	//MANAバー
	MNpl2 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		MNpl2->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl2->setAnchorPoint(ancharpoint);
	MNpl2->setScaleX(0.6f);
	MNpl2->setScaleY(0.8f);
	MNbar = MNpl2->getTextureRect().origin;
	pl2mngaugewidth = MNpl2->getContentSize().width;
	this->addChild(MNpl2, prevdepth);
	//PL2HP表記
	//数値が変わる部分
	p2hpal = LabelTTF::create(std::to_string(healer.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p2hpal->setColor(ccc3(150, 255, 255));
	p2hpal->setAnchorPoint(anancharpoint);
	this->addChild(p2hpal, prevdepth);
	//HPの最大値
	p2hpmaxal = LabelTTF::create("/" + std::to_string(healer.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p2hpmaxal, prevdepth);
	//PL2MANA表記
	//数値が変わる部分
	p2mnal = LabelTTF::create(std::to_string(healer.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p2mnal->setColor(ccc3(192, 136, 255));
	p2mnal->setAnchorPoint(anancharpoint);
	this->addChild(p2mnal, prevdepth);
	//MPの最大値
	p2mnmaxal = LabelTTF::create("/" + std::to_string(healer.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		p2mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p2mnmaxal, prevdepth);
//魔術師のステータスバー
	//ステータスプレート(一番後ろのやつ)
	PL3p = CCSprite::create("UI/Status/UI_Status_Magic.png");					//画像指定
	if (pl1frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == MAGIC) {
		PL3p->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PL3p->setScaleX(0.6f);														//大きさ変更
	PL3p->setScaleY(0.8f);
	this->addChild(PL3p, backdepth);											//追加
	//HPバー																	//HPバー
	HPpl3 = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		HPpl3->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	HPpl3->setAnchorPoint(ancharpoint);
	HPpl3->setScaleX(0.6f);
	HPpl3->setScaleY(0.8f);
	HPbar = HPpl3->getTextureRect().origin;
	pl3hpgaugewidth = HPpl3->getContentSize().width;
	this->addChild(HPpl3, prevdepth);
	//MANAバー
	MNpl3 = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		MNpl3->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	MNpl3->setAnchorPoint(ancharpoint);
	MNpl3->setScaleX(0.6f);
	MNpl3->setScaleY(0.8f);
	MNbar = MNpl3->getTextureRect().origin;
	pl3mngaugewidth = MNpl3->getContentSize().width;
	this->addChild(MNpl3, prevdepth);
	//PL3HP表記
	//数値が変わる部分
	p3hpal = LabelTTF::create(std::to_string(magic.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3hpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	p3hpal->setColor(ccc3(150, 255, 255));
	p3hpal->setAnchorPoint(anancharpoint);
	this->addChild(p3hpal, prevdepth);
	//HPの最大値
	p3hpmaxal = LabelTTF::create("/" + std::to_string(magic.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3hpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(p3hpmaxal, prevdepth);
	//PL3MANA表記
	//数値が変わる部分
	p3mnal = LabelTTF::create(std::to_string(magic.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3mnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	p3mnal->setColor(ccc3(192, 136, 255));
	p3mnal->setAnchorPoint(anancharpoint);
	this->addChild(p3mnal, prevdepth);
	//MPの最大値
	p3mnmaxal = LabelTTF::create("/" + std::to_string(magic.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		p3mnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(p3mnmaxal, prevdepth);
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