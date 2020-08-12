#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = false;
		currentKey[i] = false;
	}
}

InputManager::~InputManager() {

}

void InputManager::UpdateKeyState() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = currentKey[i];
		currentKey[i] = GetAsyncKeyState(i) & 0x8000;
	}
}

int InputManager::GetKeyState(int vk) {
	if (beforeKey[vk] && currentKey[vk]) {
		return KEY_ON; //여전히 누르고 있다						->누르고 있다
	}
	else if (!beforeKey[vk] && currentKey[vk]) {
		return KEY_DOWN;//전에는 아닌데 지금은 맞다		->눌려있다
	}
	else if (beforeKey[vk] && !currentKey[vk]) {
		return KEY_UP;//전에는 맞는데 지금은 아니다			->뗐다
	}
	else {
		return KEY_NONE;	//ㅈ까라									->ㅈ까
	}
}

D3DXVECTOR2 InputManager::GetMousePos() {
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hWnd, &p);

	return D3DXVECTOR2(p.x, p.y);
}





