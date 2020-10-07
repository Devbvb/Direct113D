#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN          

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X WIN_WIDTH * 0.5f
#define CENTER_Y WIN_HEIGHT * 0.5f

#define WIN_START_X 30
#define WIN_START_Y 30

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

using namespace DirectX;
using namespace std;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMVECTOR Vector4;
typedef XMMATRIX Matrix;


//Framework Header
#include "Framework/Utility/Utility.h"
#include "Framework/Utility/Singleton.h"

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



//Object Header
#include "Object/Cube.h"



//Scene Header
#include "Scene/Scene.h"
#include "Program/Program.h"

extern HWND hWnd; //전역변수 다른곳에 쓸 수 있음