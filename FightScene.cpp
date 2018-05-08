#include "FightScene.h"
#include "BossScene.h"

#include "HpBar.h"


const int hpGageSizeWidth = 300;
const int hpGageSizeHeight = 10;

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

	// バックグ;ランド
	this->FightBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(FightScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(Point(winSize.width , 0));
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
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

	//敵-------------------------------------------------
	//敵のHPをセット
	enemyHpNow = 300;
	enemyHpMax = 300;

	enemySprite = Sprite::create("enemy/zombi/green.png");
	// 表示座標指定
	enemySprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(enemySprite, 0);
	//敵画像のRectを取得
	enemySpriteRect = Rect(	enemySprite->getPosition().x - enemySprite->getContentSize().width / 2,
							enemySprite->getPosition().y - enemySprite->getContentSize().width / 2,
							enemySprite->getContentSize().width,
							enemySprite->getContentSize().height);


	//敵HPゲージ-------------------------------------------
	auto backHpRect = Rect(0, 0, hpGageSizeWidth, hpGageSizeHeight);
	auto redSquare = Sprite::create();
	redSquare ->setAnchorPoint(Point(0.f, 1.f));	//アンカーポイントを左上へ
	redSquare->setTextureRect(backHpRect);
	redSquare->setPosition(winSize.width / 3, 900);
	redSquare->setColor(Color3B::RED);
	this->addChild(redSquare);
	
	enemyHpRect = Rect(0, 0, (enemyHpNow / enemyHpMax) * hpGageSizeWidth, 10);
	blueSquare = Sprite::create();
	blueSquare->setAnchorPoint(Point(0.f, 1.f));	//アンカーポイントを左上へ
	blueSquare->setTextureRect(enemyHpRect);
	blueSquare->setPosition(winSize.width / 3, 900);
	blueSquare->setColor(Color3B::BLUE);
	this->addChild(blueSquare);

	this->scheduleUpdate();	//updateが毎フレーム呼び出される

	//// オブジェクト作成
	//HpBar* bar = HpBar::create(300, 20, 300);	//HpBar::create(幅、高さ、最大値）
	//bar->setPosition(winSize.width / 2, 850);
	//this->addChild(bar);
	//// 値を変更
	//bar->changeValue(enemyHpNow);



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
	auto lbl_Select = Label::createWithSystemFont("Fight", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 1);
}



// タッチした瞬間
bool FightScene::TouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//タッチ座標を取得
	touchLocation = touch->getLocation();

	//enemySpriteRect内をクリックしていたら・・・
	if (enemySpriteRect.containsPoint(touchLocation)) {
		enemyHpNow -= 20;
		////hpSizeWidth = (enemyHp / enemyHpMax) * 300;
		log("enemySpriteClickCheck");
		log("enemyHp = %i", enemyHpNow);

		enemyHpRect = Rect(0, 0, enemyHpNow, hpGageSizeHeight);
		blueSquare->setTextureRect(enemyHpRect);
	}


	return true;
}

// スワイプ中
void FightScene::TouchMove(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

// 指を離した瞬間
void FightScene::TouchEnd(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (enemyHpNow <= 0) {
		this->pushStart(this);
	}

}


// 画面遷移
void FightScene::pushStart(Ref * pSender)
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

void FightScene::update(float delta) {
	//enemyHpNow--;
	//bar->changeValue(enemyHpNow);
\

}