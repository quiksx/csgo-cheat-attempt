#pragma once
#include <Windows.h>

// Extra Config
#define MENU_KB VK_INSERT
#define UNINJECT_KB VK_DELETE

// DirectX
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

// Imgui
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

#include "Vec3.h"

// Settings
#include "Settings.h"
ASettings Settings;

// Functions
#include "WTS.h"

// Hook/Drawing
#include "DirectX.h"
#include "Hook.h"
#include "Drawing.h"

// Offsets
#include "csgo.hpp"
using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

// GVariables
LPDIRECT3DDEVICE9 DirectXDevice;
DWORD Global_GameModule;
DWORD Global_EngineModule;

//Classes
#include "Engine.h"
#include "Localplayer.h"
#include "Entity.h"

// Mods
#include "JRESP.h"
#include "JRADAR.h"