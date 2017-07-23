#pragma once
#include <SFML/Graphics.hpp>

class GameObject
	: public sf::Drawable
{
public:
	void setClickable(bool _set){ clickable = _set; }
	bool isClickable(){ return clickable; }
	virtual void onClick() = 0;
	virtual sf::FloatRect getBox() = 0;
	GameObject(){ clickable = false; }
	virtual ~GameObject(){
	}
private:
	bool clickable;
};