#pragma once
#include "Object.h"
#include "Animation.h"

class Player:public Object
{
private:
	Animation* playerAnimation;

public:
	Player();
	~Player();
	
	void Render();
	void Update(float dTime);
	float gravity;
	bool doubleJump, isJump;

};

