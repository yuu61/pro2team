#include "..\header\Container.hpp"

//template class Container<int>;

template <class T>
Container<T>::Container() :
	Graphics() {
}

template <class T>
Container<T>::Container(float x1, float y1, float cx, float cy, int graph) :
	Graphics(x1, y1, cx, cy, graph){
}

template <class T>
void Container<T>::SetMove(eMoveType moveType, float x, float y, int flame) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetMove(moveType, x, y, flame);
	}
}

template <class T>
void Container<T>::SetMoveTo(eMoveType moveType, float x, float y, int flame) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetMoveTo(moveType, x, y, flame);
	}
}

template <class T>
void Container<T>::SetExpand(eMoveType moveType,float time, int flame) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetExpand(moveType, time, flame);
	}
}

template <class T>
void Container<T>::SetExpandTo(eMoveType moveType, float time, int flame) {
	Graphics::SetExpandTo(moveType, time, flame);
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetExpandTo(moveType, time, flame);
	}
}

template <class T>
void Container<T>::SetRotate(eMoveType moveType, float rota, int flame) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetRotate(moveType, rota, flame);
	}
}

template <class T>
void Container<T>::SetRotateTo(eMoveType moveType, float rota, int flame) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->SetRotateTo(moveType, rota, flame);
	}
}



template <class T>
void Container<T>::Update() {
	Graphics::Update();
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->Update();
	}
}

template <class T>
void Container<T>::Draw() {
	Graphics::Draw();
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->Draw(this->GetX(), this->GetY());
	}
}