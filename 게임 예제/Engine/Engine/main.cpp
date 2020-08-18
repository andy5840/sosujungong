#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {
	srand(GetTickCount());

	Console console;
	Application app;

	if (CONSOLE_ON) {
		console.OpenConsole();
	}

	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));

	app.InitDeltaTime();
	app.InitManager();


	return app.DoMainLoop(new MainScene());
}
/*
as among us
kill npc when your are a imposter
//save npc when you are a player
npc and ccty has a sight to see imposter
there are a target you've to kill
some gold(platinum) target'll give you 3points


*/