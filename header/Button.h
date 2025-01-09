#pragma once
#include "Graphics.h"
#include <functional>

typedef enum _eButtonStatus {
	NONE,
	CHARGING,
	CHARGED,
	PRESSED,
	INVALID
}eButtonStatus;

class Button : public Graphics
{
protected:
	// ƒNƒŠƒbƒN‚Ìó‘Ô‚Ì•Û‘¶
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	// ƒNƒŠƒbƒNŠ®—¹‚É•K—v‚ÈƒtƒŒ[ƒ€”
	int checkRightCharge;
	int checkLeftCharge;

	// ƒNƒŠƒbƒN‚Ìó‘Ô‚ğXV‚·‚éB¶‰E—¼—pB
	virtual eButtonStatus CheckClick(int time, int charge, eButtonStatus stutas,bool cheat);

public:
	Button();
	Button(int checkLeftCharge, int checkRightCharge, float x, float xx, float y, float yy, int graph);
	~Button() {};

	// ƒNƒŠƒbƒNƒCƒxƒ“ƒg‚ğ•Û‘¶‚·‚éB
	std::function<void(void)> Click{ []() {} };

	// ƒ}ƒEƒX‚ÌƒNƒŠƒbƒN‚ğŠm”F‚·‚é
	// virtual eButtonStatus CheckLeft();
	// virtual eButtonStatus CheckRight();

	// ƒL[ƒ{[ƒh‚©‚ç‚Ì“ü—Í‚ğŠm”F‚·‚éB
	virtual eButtonStatus CheckLeft(int inputKeyCharge);
	virtual eButtonStatus CheckRight(int inputKeyCharge);
	bool CheckLocation();


	eButtonStatus GetStatusLeft() { return statusLeft; }
	eButtonStatus GetStatusRight() { return statusRight; }

	void Initialize() override;        //åˆæœŸåŒ–å‡¦ç†ã¯å®Ÿè£…ã—ã¦ã‚‚ã—ãªãã¦ã‚‚ã„ã„
	void Finalize() override;        //çµ‚äº†å‡¦ç†ã¯å®Ÿè£…ã—ã¦ã‚‚ã—ãªãã¦ã‚‚ã„ã„
	void Update();    //æ›´æ–°å‡¦ç†ã¯å¿…ãšç¶™æ‰¿å…ˆã§å®Ÿè£…ã™ã‚‹
	// void Draw() ;    //æç”»å‡¦ç†ã¯å¿…ãšç¶™æ‰¿å…ˆã§å®Ÿè£…ã™ã‚‹
};

