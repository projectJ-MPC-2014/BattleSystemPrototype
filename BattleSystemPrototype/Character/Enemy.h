#pragma once

#include"Character.h"
#include"../Selector/RandomSelector.h"

/**
*敵キャラクタ
*/
class Enemy : public Character
{
public:
	/**コンストラクタ*/
	Enemy(CharaData data);
	/**デストラクタ*/
	~Enemy() = default;
public:
	/**
	*ランダムに行動選択するクラスを生成する
	*行動選択クラスへのポインタ
	*/
	std::unique_ptr<Selector> getSelector()override;
};
