#pragma once

#define CONSOLE_OFF false //true
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BG_COLOR D3DCOLOR_ARGB(255, 255, 255, 255)
#define PROGRAM_NAME TEXT("Engine")
#define CONSOLE_NAME TEXT("Console")

//Program Setting
//프로그램 세팅
#include <d3dx9.h>

//윈도우 헤더
#include <Windows.h>
#include <XAudio2.h>

//다렉 헤더
#include <d3d9.h>
#include <d3dx9.h>

//디버그용 헤더
#include <iostream>

//게임 매니저 헤더
#include "SceneManager.h"
#include "InputManager.h"
#include "TextureManager.h"
//#include "SoundManager.h"


//상수
#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}
#define SAFE_DELETE(p) {if(p){delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete [](p); {p)=nullptr;}}}

//전역 변수
extern LPDIRECT3D9 pd3d;
extern D3DPRESENT_PARAMETERS d3dpp;
extern LPDIRECT3DDEVICE9 pd3dDevice;
extern LPD3DXSPRITE pd3dSprite;
extern HWND hWnd;
extern SceneManager* sceneManager;
extern TextureManager* textureManager;
extern InputManager* inputManager;


