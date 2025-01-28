#include "../header/Cake.hpp"
#include "../dxlib_for_visual_studio/DxLib.h"


Cake::Cake() :
	Cake(GetRand(3),nullptr){
}

Cake::Cake(int strawberry) :
	Cake(strawberry, nullptr) {
}

Cake::Cake(Item* item) :
	Cake(GetRand(3), item) {
}

Cake::Cake(int strawberry, Item* item) :
	strawberry(strawberry),
	item(item),
	Graphics(0,0,1,1, LoadGraph("image/cake_zero.png")){
	
	SetCakeGraph();
}

void Cake::AddStrawberry(int i) {
	strawberry += i;
	if(strawberry > 5){
		strawberry = 5;
	}
	SetCakeGraph();
}

void Cake::SetCakeGraph() {
	switch (strawberry) {
	case 0:
		this->SetGraph(LoadGraph("image/cake_zero.png"));
		break;
	case 1:
		this->SetGraph(LoadGraph("image/cake_one.png"));
		break;
	case 2:
		this->SetGraph(LoadGraph("image/cake_two.png"));
		break;
	case 3:
		this->SetGraph(LoadGraph("image/cake_three.png"));
		break;
	case 4:
		this->SetGraph(LoadGraph("image/cake_four.png"));
		break;
	case 5:
		this->SetGraph(LoadGraph("image/cake_five.png"));
		break;
	}
	this->SetCnt(500, 500);
}