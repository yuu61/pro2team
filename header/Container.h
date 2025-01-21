#pragma once
#include <vector>
#include "..\header\Graphics.h"
#include <algorithm>
#include "Button.h"
#include "Cake.h"


template <class T>
class Container : public Graphics 
{
protected:
	std::vector<T> vec{};

public:
	Container();
	Container(float x1, float y1, float cx, float cy, int graph);

	void insert(int i, T thing) {vec.insert(vec.begin() + i, thing);}
	void push_back(T thing) { vec.push_back(thing); }

	T at(int i) {return vec.at(i);}
	void erase(int i) { vec.erase(vec.begin() + i); }
	int size() { return vec.size(); }

	virtual void SetMove(eMoveType moveType, float x, float y, int flame);
	virtual void SetMoveTo(eMoveType moveType, float x, float y, int flame);

	virtual void SetExpand(eMoveType moveType, float time, int flame);
	virtual void SetExpandTo(eMoveType moveType, float time, int flame);

	virtual void SetRotate(eMoveType moveType, float rota, int flame);
	virtual void SetRotateTo(eMoveType moveType, float rota, int flame);

	virtual void Initialize() {}     
	virtual void Finalize() {} 
	virtual void Update();
	virtual void Draw();    
};

template class Container<Button*>;

template class Container<Cake*>;