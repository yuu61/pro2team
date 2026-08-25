#pragma once
#include <vector>
#include "Graphics.hpp"
#include <algorithm>
#include <cstddef>
#include "Button.hpp"
#include "Cake.hpp"


template <class T>
class Container : public Graphics 
{
protected:
	std::vector<T> vec{};

public:
	Container();
	Container(float x1, float y1, float cx, float cy, int graph);
	Container(const Container&) = delete;
	Container(Container&&) = delete;
	Container& operator=(const Container&) = delete;
	Container& operator=(Container&&) = delete;

	void insert(std::size_t i, T thing) {vec.insert(vec.begin() + static_cast<std::ptrdiff_t>(i), thing);}
	void push_back(T thing) { vec.push_back(thing); }

	T at(std::size_t i) {return vec.at(i);}
	void erase(std::size_t i) { vec.erase(vec.begin() + static_cast<std::ptrdiff_t>(i)); }
	std::size_t size() const { return vec.size(); }

	using Graphics::Draw;

	void SetMove(eMoveType moveType, float x, float y, int flame) override;
	void SetMoveTo(eMoveType moveType, float x, float y, int flame) override;

	void SetExpand(eMoveType moveType, float time, int flame) override;
	void SetExpandTo(eMoveType moveType, float time, int flame) override;

	void SetRotate(eMoveType moveType, float rota, int flame) override;
	void SetRotateTo(eMoveType moveType, float rota, int flame) override;

	void Initialize() override {}
	void Finalize() override {}
	void Update() override;
	void Draw() override;
};

template <class T>
Container<T>::Container() :
	Graphics() {
}

template <class T>
Container<T>::Container(float x1, float y1, float cx, float cy, int graph) :
	Graphics(x1, y1, cx, cy, graph) {
}

template <class T>
void Container<T>::SetMove(eMoveType moveType, float x, float y, int flame) {
	for (const auto& element : vec) {
		element->SetMove(moveType, x, y, flame);
	}
}

template <class T>
void Container<T>::SetMoveTo(eMoveType moveType, float x, float y, int flame) {
	for (const auto& element : vec) {
		element->SetMoveTo(moveType, x, y, flame);
	}
}

template <class T>
void Container<T>::SetExpand(eMoveType moveType, float time, int flame) {
	for (const auto& element : vec) {
		element->SetExpand(moveType, time, flame);
	}
}

template <class T>
void Container<T>::SetExpandTo(eMoveType moveType, float time, int flame) {
	Graphics::SetExpandTo(moveType, time, flame);
	for (const auto& element : vec) {
		element->SetExpandTo(moveType, time, flame);
	}
}

template <class T>
void Container<T>::SetRotate(eMoveType moveType, float rota, int flame) {
	for (const auto& element : vec) {
		element->SetRotate(moveType, rota, flame);
	}
}

template <class T>
void Container<T>::SetRotateTo(eMoveType moveType, float rota, int flame) {
	for (const auto& element : vec) {
		element->SetRotateTo(moveType, rota, flame);
	}
}

template <class T>
void Container<T>::Update() {
	Graphics::Update();
	for (const auto& element : vec) {
		element->Update();
	}
}

template <class T>
void Container<T>::Draw() {
	Graphics::Draw();
	for (const auto& element : vec) {
		element->Draw(GetX(), GetY());
	}
}
