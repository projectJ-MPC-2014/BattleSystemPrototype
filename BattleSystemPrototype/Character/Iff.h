#pragma once

/**
*敵味方識別の列挙体
*/
enum class Iff :int	//Identify friend or foe
{
	/**敵味方不明*/
	UNKNOWN,
	/**プレイヤの味方*/
	FRIEND,
	/**プレイヤの敵*/
	FOE
};