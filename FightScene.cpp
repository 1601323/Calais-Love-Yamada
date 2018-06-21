#include "FightScene.h"
#include "BossScene.h"
#include "WalkScene.h"

#include "HpBar.h"


const int hpGageSizeWidth = 300;
const int hpGageSizeHeight = 10;

const int ENEMY_HP_MAX = 300;				//敵のHP
const int INIT_GIVE_DAMAGE = 50;			//敵へ与えるダメージの初期値
const int DAMAGE_DISPLAY_TIME = 100;		//与えたダメージの数値の表示時間
const int EXP = 10;					//獲得経験値
const int NEXT_BATTLE_TIMER = 180;	//すべての雑魚敵が死んで次のバトルが始まるまでのタイマー
const int BATTLE_MAX = 6;
const int BATTLE_LABEL_FONT_SIZE = 60;
const int BATTLE_COUNT_FONT_SIZE = 80;
const int GIVE_ENEMY_DAMAGE_FONT_SIZE = 40;

Scene *FightScene::createScene()
{
	auto scene = Scene::create();
	auto layer = FightScene::create();
	scene->addChild(layer);
	return scene;
}

FightScene::FightScene() {

}
FightScene::~FightScene() {
	 
}


// 初期化
bool FightScene::init()
{
	if (!Layer::init()){
		return false;
	}

	_damageDispTime = DAMAGE_DISPLAY_TIME;
	_damageDispFlag = false;
	_enemyDeathFlg = true;
	_enemyDispFlag = false;
	_exp = EXP;
	_moveFlag = false;
	_hitCount = 0;
	_battleCounter = 1;
	_nextBattleTimer = NEXT_BATTLE_TIMER;

	// バックグ;ランド
	FightScene::FightBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(FightScene::ChangeBossScene, this));

	// ボタンの配置
	startButton->setPosition(Point(winSize.width , 0));
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, nullptr);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 1);


	//タッチイベント-------------------------------------
	// 取得
	auto touchGet = EventListenerTouchOneByOne::create();
	touchGet->onTouchBegan = CC_CALLBACK_2(FightScene::TouchBegan, this);
	touchGet->onTouchMoved = CC_CALLBACK_2(FightScene::TouchMove, this);
	touchGet->onTouchEnded = CC_CALLBACK_2(FightScene::TouchEnd, this);
	//タッチイベントリスナーの登録
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchGet, this);

	//バトル数を初期化
	_battleCounter = 1;
	//敵-------------------------------------------------
	//敵のHPをセット
	_enemyHpNow = ENEMY_HP_MAX;

	_enemySprite = Sprite::create();
	FightScene::EnemySelector();

	_enemySprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_enemySprite, 0);
	//敵画像のRectを取得
	Rect rect;
	_enemySpriteRect = GetSpriteRect(_enemySprite,rect);
	//敵HPゲージ
	//FightScene::EnemyHpGage();

	this->scheduleUpdate();	//updateが毎フレーム呼び出される

	//敵へワンタップで与えるダメージ数をセット
	_giveDamage = INIT_GIVE_DAMAGE;

	//----------------------------------------------------

	////Labelクラスの初期化
	//label = Label::create("文字列だよ", "Arial", 40);
	////座標を指定
	//label->setPosition(Point(100,winSize.height-100));

	////文字列を作る
	//str = String::createWithFormat("Score : %d", giveDamage);
	////作ったもし列をLabelに設定
	//label->setString(str->getCString());

	////シーンに追加
	//this->addChild(label);
	

	//auto draw = DrawNode::create();
	////頂点座標設定
	//std::vector<Vec2>vecs;
	//vecs.push_back(Vec2(-300,  335));
	//vecs.push_back(Vec2(-300, -335));
	//vecs.push_back(Vec2(300,  -335));
	////drawPolygon( 頂点座標格納配列 , 頂点数 , 色 );
	//draw->drawPolygon(&vecs[0], 3, Color4F::WHITE, 1, Color4F::YELLOW);
	//draw->setPosition(Vec2(winSize.width / 2, winSize.height / 2));

	//auto clipping = ClippingNode::create();
	//clipping->setStencil(draw);
	//clipping->setInverted(false);
	//clipping->setAlphaThreshold(1.0);
	//addChild(clipping);

	//auto sprite = Sprite::create("HelloWorld.png");
	//sprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	//clipping->addChild(sprite);

	return true;
}



// 背景
void FightScene::FightBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// バックカラー
	auto groundCollar = LayerColor::create(Color4B::YELLOW, winSize.width, winSize.height);

	// バックグランドCollar第2:表示順
	this->addChild(groundCollar, 0);

	// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithTTF("%i"+ENEMY_HP_MAX, "fonts/arial.ttf", 70);
	
	//アンカーポイントを左上へ
	lbl_Select->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	// 配置場所
	lbl_Select->setPosition(Point(0, winSize.height));

	// Select追加
	this->addChild(lbl_Select, 1);
}


//敵へ与えたダメージ数値を表示
void FightScene::GiveDamageDisplay(unsigned int giveDamage) {
	TTFConfig ttfConfigEffect("fonts/SHOWG.TTF", GIVE_ENEMY_DAMAGE_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //文字エフェクトを使用する
	damageLabel = Label::createWithTTF(ttfConfigEffect, "-" + StringUtils::toString(giveDamage));

	damageLabel->setColor(Color3B::RED);
	damageLabel->enableGlow(Color4B::BLACK); //色を設定

	int num1 = random(0, 100) - 50;
	damageLabel->setPosition(Vec2(400 + num1, 850 + num1));
	damageLabel->enableShadow(Color4B::BLACK, Size(-2, -4), 2);
	this->addChild(damageLabel);

	int num2 = random(0, 60) - 30;
	auto *up = MoveBy::create(0.5f, Vec2(num2, 25));
	auto *fadeout = FadeOut::create(1.0f);
	auto seq = Sequence::create(up, fadeout, nullptr);
	damageLabel->runAction(seq);
}

//HIT数値を表示
void FightScene::HitDisplay() {

	TTFConfig ttfConfigEffect("fonts/SHOWG.TTF", 60, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //文字エフェクトを使用する
	
	int offset = 0;
	if (_hitCount < 8) {
		offset = _hitCount*60;
	}
	else if (_hitCount > 8) {
		offset = (int)(_hitCount % 8) * 60;
	}

	hitLabel = Label::createWithTTF(ttfConfigEffect, StringUtils::toString(_hitCount) + "HIT!");
	hitLabel->setColor(Color3B::RED);
	hitLabel->setPosition(Vec2(650 , 600 + offset));
	hitLabel->enableGlow(Color4B::WHITE); //色を設定
	this->addChild(hitLabel);

	FightScene::ScalingAndFadeout(hitLabel, 0.1f, 1.5f, 0.1f, 1.0f, 2.0f, 0.4f);
	//hitLabel->pause();
	//virtual
}

//void FightScene::DrawGlowLabel(const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B glowColor) {
//	TTFConfig ttfConfigEffect(fontFilePath, fontSize, GlyphCollection::DYNAMIC);
//	ttfConfigEffect.distanceFieldEnabled = true; //文字エフェクトを使用する
//
//	auto label = Label::createWithTTF(ttfConfigEffect, text);
//
//	label->setColor(textCololr);
//	label->setPosition(position);
//	label->enableGlow(glowColor); //色を設定
//	this->addChild(label);
//
//}


//文字が拡大縮小の後にフェードアウトするアニメーション
//ScalingAndFadeout(ラベル, 何秒かけて拡大するか, 何倍に拡大するか, 何秒かけて縮小するか, 何倍に縮小か, 何秒間表示させるか, フェードアウトは何秒かけて行うか)
void FightScene::ScalingAndFadeout(Label* label, float largeTime, float multiple, float backTime, float backMultiple, float delay, float fadeOutTime) {
	auto act1 = ScaleTo::create(largeTime, multiple);
	auto act2 = ScaleTo::create(backTime, backMultiple);
	auto act3 = DelayTime::create(delay);
	auto act4 = FadeOut::create(fadeOutTime);
	auto seq = Sequence::create(act1, act2, act3, act4, NULL);
	label->runAction(seq);
}



//今なにバトル目ですよー！っていう文字表記
void FightScene::BattleAnnounce() {
	Label* battleLabel;
	Label* battleCntLabel;
	Vec2 battleLabel_pos;
	Vec2 battleCntLabel_pos;
	unsigned int labelSize = (_battleCounter == BATTLE_MAX) ? BATTLE_LABEL_FONT_SIZE : BATTLE_COUNT_FONT_SIZE;

	TTFConfig ttfConfigEffect("fonts/COPRGTB.TTF", BATTLE_LABEL_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true;

	TTFConfig ttfConfigEffect2("fonts/COPRGTB.TTF", labelSize, GlyphCollection::DYNAMIC);
	ttfConfigEffect2.distanceFieldEnabled = true;

	//バトル５以下と最後のバトルではフォントサイズとポジションが異なる
	if (_battleCounter < BATTLE_MAX) {
		battleLabel = Label::createWithTTF(ttfConfigEffect, "Battle");
		battleCntLabel = Label::createWithTTF(ttfConfigEffect2, StringUtils::toString(_battleCounter));
		battleLabel_pos = Vec2(400, 820);
		battleCntLabel_pos = Vec2(570, 780);
	}else if (_battleCounter == BATTLE_MAX) {
		battleLabel = Label::createWithTTF(ttfConfigEffect, "Final");
		battleCntLabel = Label::createWithTTF(ttfConfigEffect2, "Battle");
		battleLabel_pos = Vec2(290, 820);
		battleCntLabel_pos = Vec2(510, 780);
	}
	battleLabel->setColor(Color3B::BLACK);
	battleLabel->enableGlow(Color4B::WHITE);
	battleLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleLabel->setPosition(battleLabel_pos);

	battleCntLabel->setColor(Color3B::BLACK);
	battleCntLabel->enableGlow(Color4B::WHITE);
	battleCntLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleCntLabel->setPosition(battleCntLabel_pos);

	this->addChild(battleLabel);
	this->addChild(battleCntLabel);

	//両方のラベルをいったん非表示に
	battleLabel->setOpacity(0.0f);
	battleCntLabel->setOpacity(0.0f);

	//@param bl battleLabel
	//@param bcl battleCntLabel

	//バトルラベル用フェードアウトとインの設定
	auto *bl_fadein = FadeIn::create(0.3f);
	auto *bl_fadeout = FadeOut::create(0.3f);
	//バトルナンバーラベル用フェードアウトとインの設定
	auto *bcl_fadein = FadeIn::create(0.3f);
	auto *bcl_fadeout = FadeOut::create(0.3f);
	//その他のmove達は共用する
	auto *down = MoveBy::create(0.4f, Vec2(0, -20));
	auto *up = MoveBy::create(0.4f, Vec2(0, 20));
	auto *delay = DelayTime::create(1.0f);
	//Spawnで複数のアクションを同時に実行する設定を行う
	auto bl_fastMoves = Spawn::createWithTwoActions(bl_fadein, down);
	auto bl_lastMoves = Spawn::createWithTwoActions(bl_fadeout, down);
	auto bcl_fastMoves = Spawn::createWithTwoActions(bcl_fadein, up);
	auto bcl_lastMoves = Spawn::createWithTwoActions(bcl_fadeout, up);
	//順番にアクションを実行するための設定を行う
	auto battleLabelMoves = Sequence::create(bl_fastMoves, delay, bl_lastMoves, nullptr);
	auto battleCntLabelMoves = Sequence::create(bcl_fastMoves, delay, bcl_lastMoves, nullptr);
	//アクションの実行
	battleLabel->runAction(battleLabelMoves);
	battleCntLabel->runAction(battleCntLabelMoves);
}

// タッチした瞬間
bool FightScene::TouchBegan(Touch * touch, Event * event)
{
	//タッチ座標を取得
	_touchLocation = touch->getLocation();

	//敵が表示されていてかつ、enemySpriteRect内をクリックされていれば・・・
	if (_enemyDispFlag) {
		if (_enemySpriteRect.containsPoint(_touchLocation)) {
			log("enemySpriteClickCheck");
			_enemyHpNow -= _giveDamage;

			FightScene::GiveDamageDisplay(_giveDamage);
			_damageDispFlag = true;
			_damageDispTime = DAMAGE_DISPLAY_TIME;
			_hitCount++;
			//FightScene::HitDisplay();		//ちょっと作業お休みzzz...
		}
	}

	return true;
}

// スワイプ中
void FightScene::TouchMove(Touch * touch, Event * event)
{

}

// 指を離した瞬間
void FightScene::TouchEnd(Touch * touch, Event * event)
{
	//敵のHpが0以下になったとき
	if (_enemyHpNow <= 0) {
		_enemyHpNow = ENEMY_HP_MAX;
		_enemyDeathFlg = true;
		_enemyDispFlag = false;
		_nextBattleTimer = NEXT_BATTLE_TIMER;
		FightScene::ExpGetAnnounce();
		//バトル数をインクリメントしてから敵の画像を切り替える
		if (++_battleCounter > BATTLE_MAX) {
			FightScene::ChangeBossScene(this);
		}
		FightScene::EnemySelector();
	}

	//Hp情報更新
	FightScene::ReloadEnemyHp();
	//enemySpriteRect内をクリックしていたら・・・
	if (_enemyDispFlag) {
		if (_enemySpriteRect.containsPoint(_touchLocation)) {
			FightScene::SpriteTremble(_enemySprite);
		}
	}
	//log("enemyHp = %i", _enemyHpNow);
	//log("roundCounter = %i", _battleCounter);

}


//画像を振動させる
void FightScene::SpriteTremble(Sprite* sprite) {
	auto *right = MoveBy::create(0.05f, Vec2(0, 5));
	auto *left = MoveBy::create(0.05f, Vec2(0, -5));
	auto *up = MoveBy::create(0.05f, Vec2(5, 0));
	auto *down = MoveBy::create(0.05f, Vec2(-5, 0));
	auto moves = Sequence::create(right, left, up, down, nullptr);
	sprite->runAction(moves);
}

//画像のRectを取得する
Rect FightScene::GetSpriteRect(Sprite* sprite, Rect rect) {
	 rect = Rect(sprite->getPosition().x - sprite->getContentSize().width / 2,
				 sprite->getPosition().y - sprite->getContentSize().width / 2,
				 sprite->getContentSize().width,
				 sprite->getContentSize().height);
	 return rect;
}

//敵のHpバー
void FightScene::EnemyHpGage() {
	Size winSize = Director::getInstance()->getWinSize();
	//赤ゲージ
	auto backHpRect = Rect(0, 0, hpGageSizeWidth, hpGageSizeHeight);
	auto redSquare = Sprite::create();
	redSquare->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//アンカーポイントを左上へ
	redSquare->setTextureRect(backHpRect);
	redSquare->setPosition(winSize.width / 3, 900);
	redSquare->setColor(Color3B::RED);
	this->addChild(redSquare);
	//青ゲージ
	_enemyHpRect = Rect(0, 0, (_enemyHpNow / ENEMY_HP_MAX) * hpGageSizeWidth, 10);
	_blueSquare = Sprite::create();
	_blueSquare->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//アンカーポイントを左上へ
	_blueSquare->setTextureRect(_enemyHpRect);
	_blueSquare->setPosition(winSize.width / 3, 900);
	_blueSquare->setColor(Color3B::BLUE);
	this->addChild(_blueSquare);

	redSquare->setOpacity(0.0f);	//いったん非表示に（255にすると表示する）
	auto *r_delay = DelayTime::create(3.0f);
	auto r_fadein = FadeIn::create(0.5f);
	auto r_acts = Sequence::create(r_delay, r_fadein, nullptr);
	redSquare->runAction(r_acts);

	_blueSquare->setOpacity(0.0f);	//いったん非表示に（255にすると表示する）
	auto *b_delay = DelayTime::create(2.0f);
	auto b_fadein = FadeIn::create(1.0f);
	auto b_acts = Sequence::create(b_delay, b_fadein, nullptr);
	_blueSquare->runAction(b_acts);

}

//敵のHpバー情報を更新
void FightScene::ReloadEnemyHp() {
	_enemyHpRect = Rect(0, 0, _enemyHpNow, hpGageSizeHeight);
	_blueSquare->setTextureRect(_enemyHpRect);
}

// Boss画面へ遷移
void FightScene::ChangeBossScene(Ref * pSender)
{
	log("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = BossScene::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

// Walk画面へ遷移
void FightScene::ChangeWalkScene(Ref * pSender)
{
	log("Pushボタン");
	Scene *pScene = WalkScene::createScene();
	TransitionFade *transition = TransitionFade::create(0.6, pScene);
	Director::getInstance()->replaceScene(transition);
}


//経験値獲得アナウンスの表示
void FightScene::ExpGetAnnounce() {
	Size winSize = Director::getInstance()->getWinSize();
	expLabel = Label::createWithSystemFont("+" + StringUtils::toString(_exp)+" EXP", "Stencil", 70);
	expLabel->setColor(Color3B::RED);

	expLabel->setPosition(Point(winSize.width/2, 1000));
	expLabel->enableShadow(Color4B::BLACK, Size(-2, -4), 2);
	this->addChild(expLabel);

	FightScene::ScalingAndFadeout(expLabel, 0.1f, 1.3f, 0.1f, 1.0f, 2.0f, 0.4f);
}

//
void FightScene::update(float delta) {

	//ダメージ表示は一定時間でオフに
	if (_damageDispFlag) {
		if (--_damageDispTime < 1) {
			damageLabel->setVisible(false);
			_damageDispFlag = false;
		}else{
			damageLabel->setVisible(true);
			_damageDispFlag = true;
		}
	}


	//log("dispCnt = %i", _damageDispTime);
	//log("dispflag = %i", _damageDispFlag);
	//log("EPointDispTimeCnt = %i", EPointDispTime);

	log("_enemyDeathFlg = %i", _enemyDeathFlg);
	log("_nextBattleTimer = %i", _nextBattleTimer);
	log("_enemyDispFlag = %i", _enemyDispFlag);

	//敵が死亡していたら次のバトルが始まるまでのカウントダウンがスタート
	//カウントが０になったら敵の死亡状態フラグを下げて、敵の表示フラグを立てる。
	if (_enemyDeathFlg) {
		if (--_nextBattleTimer < 1) {
			_enemyDispFlag = true;
			_enemyDeathFlg = false;
		}
	}
}

//敵の切り替え
void FightScene::EnemySelector() {
	switch ((BattleNumber)_battleCounter) {
	case BattleNumber::Battle1:
		_enemySprite->setTexture("enemy/zako/Sleipnir.png");
		break;
	case BattleNumber::Battle2:
		_enemySprite->setTexture("enemy/zako/BoxDevil.png");
		break;
	case BattleNumber::Battle3:
		_enemySprite->setTexture("enemy/zako/CakeDora.png");
		break;
	case BattleNumber::Battle4:
		_enemySprite->setTexture("enemy/zako/Oden.png");
		break;
	case BattleNumber::Battle5:
		_enemySprite->setTexture("enemy/zako/Moja.png");
		break;
	case BattleNumber::Battle6:
		_enemySprite->setTexture("enemy/zako/Tors.png");
		break;
	}

	_enemySprite->setOpacity(0.0f);	//いったん非表示に（255にすると表示する）
	auto *delay = DelayTime::create(2.0f);
	auto fadein = FadeIn::create(1.0f);
	auto acts = Sequence::create(delay, fadein, nullptr);
	_enemySprite->runAction(acts);

	if (_battleCounter <= BATTLE_MAX) {
		FightScene::BattleAnnounce();
	}
	FightScene::EnemyHpGage();


}
