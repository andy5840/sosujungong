#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {//WINAPI에서 쓰는 메인인듯
	srand(GetTickCount());
	//srand(time(NULL));		//콘솔 뜨게 할 수 있음

	Console console;
	Application app;
	if (CONSOLE_ON) {
		console.OpenConsole();
	}

	std::cout << "hello" << std::endl;

	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));
	app.InitDeltaTime();
	app.InitManager();

	return app.DoMainLoop(new MainScene());
}
