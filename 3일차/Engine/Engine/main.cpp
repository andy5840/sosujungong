#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "Scene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {//WINAPI���� ���� �����ε�
	srand(GetTickCount());
	//srand(time(NULL));

	Console console;
	Application app;
	if (CONSOLE_OFF) {
		console.CloseConsole();
	}
	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));

	return app.DoMainLoop(new Scene());


}
