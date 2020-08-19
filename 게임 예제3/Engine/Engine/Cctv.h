#pragma once
#include "Object.h"
#include "Sprite.h"

class Cctv : public Object
{
private:
	Sprite* cctv;
public:
	Cctv();
	~Cctv();

	void Update(float dTime);
	void Render();
};