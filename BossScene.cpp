#pragma execution_character_set("utf-8")
#include "BossScene.h"
#include "GameClear.h"

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

	//初期化
	Php = 3;				//プレイヤーHP
	Bhp = 5;				//ボスHP
	continuity = 5;			//揺らす回数ぅですかねぇ
	ten = 10;				//揺らす差
	hpcut = 1;				//減らすHP
	movecnt = 0.05f;		//1っ回動かす時間
	turn = PLAYER;			//誰のターン？
	gametime = 0;			//時間
	state = false;			//プレイヤーの状態
	flag = false;			//ボスの状態
	Bflag = false;			//ボスの動く状態

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
	this->addChild(menu, 1);

	//タッチモード設定
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// バックグランド
	BossBackGroudn();

	//タイマー開始
	this->schedule(schedule_selector(BossScene::Timer));

	//アップデート更新
	this->scheduleUpdate();

	//タイム
	Timer(1);


	return true;
}

void BossScene::update(float flame)
{
	// 画面サイズ取得。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//取得
	auto touchget = EventListenerTouchOneByOne::create();


	if (turn == PLAYER) {
		state = false;																//初期化
			// コマンド
			auto KyaraButton = CCSprite::create("attack1.png");						//画像指定
			KyaraButton->setPosition(rightSize.width / 2, rightSize.height / 3);	//配置場所
			this->addChild(KyaraButton, 1, 2);										//追加

			//PLTURN文字
			plturn = CCSprite::create("PL.png");									// 配置文字
			plturn->setPosition(rightSize.width / 2, rightSize.height / 1.15f);		// 配置場所
			this->addChild(plturn, 1, 1);											// 追加

			//タッチ処理
			touchget->onTouchBegan = [this, visibleSize, KyaraButton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();									// タッチしたポイント。
				Rect rectButton1 = KyaraButton->getBoundingBox();					// ボタン画像の範囲。
				if (rectButton1.containsPoint(point1)) {							// ボタン画像の範囲内をタッチした場合。
					state = true;													//動ける状態にする
					if (state == true) {
						KyaraButton->removeFromParentAndCleanup(true);				//文字を消す
						this->removeChildByTag(1);									//文字を消す
					}
					return true;
				}
				else {
					return false;
				}
			};
			// listener1, PlayButton1をイベント登録する。
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchget, KyaraButton);
	}
	else if (turn == BOSS) {
		flag = false;																	//初期化
		gametime++;
		BSturn();										//主な処理
		if (gametime > 300) {
			flag = true;
		}

		if (flag == true) {
			//消す
			this->removeChildByTag(3);					//BSTURN
			this->removeChildByTag(5);					//5000兆円ほしい
			this->removeChildByTag(13);					//パーティクル
			this->removeChildByTag(25);					//攻撃

			gametime = 0;
			turn = PLAYER;								//プレイヤーのターンへ
			log("touch!o_o");							//タッチィ
		}
	}
	log("flame is %f", flame);
}

void BossScene::Timer(float time) {
	CCLOG("%is %f", gametime, time);

	//画像移動
	Tsprite->setPosition(ccp(gametime, 600));

	//if (turn == BOSS) {
	//	//カウントアップ
	//	gametime++;
	//}

	//タイマー停止
	if (gametime > 300) {
		this->unschedule(schedule_selector(BossScene::Timer));
	}
}

void BossScene::PLturn()
{
	//攻撃文字
	auto attackfnt = Label::createWithTTF("攻撃", "fonts/HGRSGU.TTC", 36);		// 配置文字
	attackfnt->setAnchorPoint(Vec2(0, 0));
	attackfnt->setPosition(rightSize.width / 1.2f, rightSize.height / 1.15f);	// 配置場所
	this->addChild(attackfnt, 1, 25);											// 追加

																				//BSTURN文字
	emturn = CCSprite::create("BS.png");										// 配置文字
	emturn->setPosition(rightSize.width / 2, rightSize.height / 1.15f);			// 配置場所
	this->addChild(emturn, 1, 3);												// 追加

	//揺らす処理
	auto move = CCSequence::create(
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
		NULL
	);
	//揺らす
	auto repeat = Repeat::create(move, 1);
	Kyara->runAction(repeat);

	//ボスのHPを減らす
	Bhp = Bhp - hpcut;
	//HPが0になったら
	if (Bhp <= 0) {
		// 遷移策の画面をｲﾝｽﾀﾝｽ
		Scene *pScene = GameClear::createScene();

		// 0.6秒かけて次画面に遷移
		// (時間,遷移先,色(オプション))
		TransitionFade *transition = TransitionFade::create(1.0, pScene);

		// 遷移実行 アニメーション
		Director::getInstance()->replaceScene(transition);
	}

	//エフェクトの表示
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	//エフェクトの流れを指定
	CCParticleSystemQuad* particle = CCParticleSystemQuad::create("efect.plist");

	particle->setAutoRemoveOnFinish(true);

	//パーティクル開始
	particle->resetSystem();

	//パーティクルを表示する場所の設定
	particle->setPosition(ccp(rightSize.width / 2, rightSize.height / 3));

	//パーティクルを配置
	this->addChild(particle, 502, 13);
}

void BossScene::BSturn()
{
	//5000兆円
	if (gametime == 100) {
		timerfnt = CCSprite::create("5000.png");
		timerfnt->setPosition(rightSize.width / 2, rightSize.height / 1.2);		// 配置場所
		this->addChild(timerfnt, 1, 5);
	}
	if (gametime == 250) {
		//揺らす処理
		auto move = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height - 500 + ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height - 500 - ten)),
			NULL
		);
		//揺らす
		auto repeat = Repeat::create(move, 1);
		Boss->runAction(repeat);

		// 画面サイズ取得
		Size winSize = Director::getInstance()->getVisibleSize();

		//キャラを揺らす
		auto charmove = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 - ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 4 + ten)),
			NULL
		);
		//何回揺らすか
		auto charrepeat = Repeat::create(charmove, continuity);
		//揺らす
		Kyara->runAction(charrepeat);
		//背景を揺らす
		auto backmove = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 2 - ten)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 2 + ten)),
			NULL
		);
		//何回揺らすか
		auto backrepeat = Repeat::create(backmove, continuity);
		//揺らす
		back->runAction(backrepeat);

		//プレイヤーのHPを減らす
		Php = Php - hpcut;
		//HPがゼロになったら
		if (Php <= 0) {
			// 遷移策の画面をｲﾝｽﾀﾝｽ
			Scene *pScene = GameClear::createScene();

			// 0.6秒かけて次画面に遷移
			// (時間,遷移先,色(オプション))
			TransitionFade *transition = TransitionFade::create(1.0, pScene);

			// 遷移実行 アニメーション
			Director::getInstance()->replaceScene(transition);
		}
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

// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithSystemFont("Boss", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));
	// Select追加
	this->addChild(lbl_Select, 1);

//背景
	//背景の画像指定
	back = CCSprite::create("testhi.jpg"); 
	// 表示座標指定
	back->setPosition(ccp(winSize.width / 2, winSize.height / 1.5f));
	//追加
	this->addChild(back, 1);

// ボスの表示
	// サイズ取得
	rightSize = CCDirector::sharedDirector()->getWinSize();

	// 画像指定
	Boss = CCSprite::create("enemy/EM_Golem.png");
	// 表示座標指定
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height - 500));
	// 追加
	this->addChild(Boss, 1);
	
//キャラ枠
	// 画像指定
	Kyara = CCSprite::create("kyarawaku.png");
	// 表示座標指定
	Kyara->setPosition(ccp(rightSize.width / 2, rightSize.height / 4));
	// 追加
	this->addChild(Kyara, 1);

//タイマー(仮)
	Tsprite = CCSprite::create("Player/PL_Magic.png");
	Tsprite->setPosition(ccp(gametime, 10));
	this->addChild(Tsprite, 1);
}

// 画面遷移
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = GameClear::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

//ボタンを押したとき
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) 
{
	// 画面サイズ取得。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (turn == PLAYER) {
		if (state == true) {
			PLturn();					//主な処理
			turn = BOSS;				//ボスのターンへ
			log("touchPE!o_o");			//タッチィ
		}
	}
	return true;
}

//ボタンを押して離したとき
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}

//// ボスボタン(仮)
//auto BossButton = Boss;												//ゴーレム

////タッチ処理
//touchget->onTouchBegan = [this, visibleSize, BossButton](Touch* touch, Event* event) {
//	Vec2 point1 = touch->getLocation();									// タッチしたポイント。
//	Rect rectButton1 = BossButton->getBoundingBox();					// ボタン画像の範囲。
//	if (rectButton1.containsPoint(point1)) {							// ボタン画像の範囲内をタッチした場合。
//		return true;
//	} else {
//		return false;
//	}
//};

//// listener1, PlayButton1をイベント登録する。
//auto director = Director::getInstance();
//director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchget, BossButton);