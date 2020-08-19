#pragma once
#include "Object.h"
#include "Sprite.h"

class Npc : public Object
{
private :
	bool isSus;
public :
	Sprite* npc;
	Npc();
	Npc(bool isSus);
	~Npc();

	bool IsSus();
	void Update(float dTime);
	void Render();
};