#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN          

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X WIN_WIDTH * 0.5f
#define CENTER_Y WIN_HEIGHT * 0.5f

#define WIN_START_X 30
#define WIN_START_Y 30

#define PI 3.141592f

#define LERP(s, e, t) (s + (e - s) * t)

#define KEY_DOWN(k) Keyboard::Get()->Down(k)
#define KEY_PRESS(k) Keyboard::Get()->Press(k)
#define KEY_UP(k) Keyboard::Get()->Up(k)

#ifdef NDEBUG
	#define V(hr) hr
#else 
	#define V(hr) assert(SUCCEEDED(hr))
#endif

#define DEVICE Device::Get()->GetDevice()
#define DC Device::Get()->GetDeviceContext()

#include <windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib") 

//DirectXTex
#include "../DirectXTex/DirectXTex.h"

using namespace DirectX;
using namespace std;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMVECTOR Vector4;
typedef XMMATRIX Matrix;

const XMVECTORF32 kRight = { 1, 0, 0 };
const XMVECTORF32 kUp = { 0, 1, 0 };
const XMVECTORF32 kForward = { 0, 0, 1 };

//Framework Header
#include "Framework/Utility/Utility.h"
#include "Framework/Utility/Singleton.h"
#include "Framework/Utility/Keyboard.h"

using namespace Utility;

#include "Framework/Device/Device.h"

#include "Framework/Shader/Shader.h"
#include "Framework/Shader/VertexShader.h"
#include "Framework/Shader/PixelShader.h"

#include "Framework/Buffer/VertexBuffer.h"
#include "Framework/Buffer/IndexBuffer.h"
#include "Framework/Buffer/ConstBuffer.h"
#include "Framework/Buffer/VertexLayouts.h"
#include "Framework/Buffer/GlobalBuffers.h"

#include "Framework/Render/Mesh.h"
#include "Framework/Render/Material.h"
#include "Framework/Render/Texture.h"

#include "Framework/Math/Vector3.h"
#include "Framework/Math/Transform.h"

#include "Framework/State/RasterizerState.h"

#include "Framework/Camera/Camera.h"

#include "Enviroment/Eviroment.h"	

//Object Header
#include "Objects/Basic/Cube.h"


//Scene Header
#include "Scene/Scene.h"
#include "Program/Program.h"

extern HWND hWnd; //전역변수 다른곳에 쓸 수 있음
extern Vector3 mousePos;
extern short mouseWheel;