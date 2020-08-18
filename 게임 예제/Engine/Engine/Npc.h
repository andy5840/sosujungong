#pragma once
#include "Object.h"
#include "Sprite.h"

class Npc : public Object
{
private:
	Sprite* npc;
public:
	Npc();
	~Npc();
	void Update(float dTime);
	void Render();
};