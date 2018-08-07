#pragma once
#ifndef __ScrollScene__
#define __ScrollScene__

#include "cocos2d.h"

USING_NS_CC;

enum class SelectName
{
	SELECT_ATTACK,		// 攻撃
	SELECT_SHIELD,		// 防御
	SELECT_ITEM,		// アイテム
	SELECT_SKILL,		// スキル
};

class ScrollScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(ScrollScene);
	std::vector<cocos2d::Node *> items;
	std::vector<cocos2d::Node *> selects;
	// 選択された選択情報格納
	static const std::vector<SelectName>& GetSelectData();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);

private:
	int nowSelect;					// 現在選ばれている番号
	unsigned int _clickCnt = 0;		// クリック回数を保存
	unsigned int _pushCnt = 0;		// 押した瞬間用カウント
	bool flag;						// 切り替え用のFlag
	Node* Top;						// 最前にあるものの情報
									// 行動パターン情報
	Sprite *_s_Attack;				// 攻撃
	Sprite *_s_Defence;				// 防御
	Sprite *_s_Item;				// アイテム
	Sprite *_s_Skill;				// スキル
	Sprite *_s_Top;					// 先頭

	// 当たり判定用
	Vec2 _touchPos;					// 現在座標
	Rect _r_swipeRect;				// スワイプ用の判定範囲
	Rect _r_clickButtunRect;		// ボタンのクリック判定
	Sprite *_s_swipe;				// スワイプ用スプライト
	Sprite *_s_clickButton;			// クリック用スプライト
	Sprite *_s_ChoiceSkill;			// 選択スキル
	Vec2 _pos;						// 座標

	void ActSelectDraw();						// 表示
	void SkillDraw();							// スキル表示
	void SkillAttacker();						// Attacker
	void SkillShield();							// シールダー
	void SkillHealer();							// Healer
	void SkillMagic();							// 魔法使い
	void Arrange(const Vec2 _pos);				// 角度調整
	void Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset);										// (配置座標,スプライト,上に表示する数,総表示数,通常拡大率,拡大率,通常透過,透過,X軸への広がり)
	void SwipeRotation();						// 回転
	void SwipeRotation(const float roleYDist);	// 回転
	void ObjHit();								// 当たり判定用
	void TouchArrange(Touch* _touch);			// タッチしたところエフェクト
	void SelectMove();							// 選択画面

	static std::vector<SelectName> SelectData;	// 保存する用のデータ


												// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	void FadeIn();							// フェードイン用
	void FadeOut(float cnt);				// フェードアウト
	Sprite *_fadeImage;						// フェードイン・アウト用のスプライト

	Rect _r_clickSkillRect;					// ボタンのクリック判定
	Sprite *_s_skill;						// スワイプ用スプライト

};

#endif 