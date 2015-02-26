#pragma once

#include<string>
#include"Character.h"
#include"../Selector/CUISelector.h"

/**
*プレイヤキャラクタ
*/
class Player : public Character
{
public:
	/**コンストラクタ*/
	Player(CharaData data);
	/**デストラクタ*/
	~Player() = default;
public:
	/**
	*CUIで行動選択するクラスを生成する
	*/
	std::unique_ptr<Selector> getSelector();
};

