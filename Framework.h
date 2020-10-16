#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X WIN_WIDTH * 0.5f
#define CENTER_Y WIN_HEIGHT * 0.5f

#define WIN_START_X 30
#define WIN_START_Y 30

#define PI 3.141592654f
#define LERP(s, e, t) (s + (e - s) * t)

#ifdef NDEBUG
	#define V(hr) hr
#else
	#define V(hr) assert(SUCCEEDED(hr))
#endif

#define DEVICE Device::Get()->GetDevice()
#define DC Device::Get()->GetDeviceContext()

#define KEY_DOWN(k) Control::Get()->Down(k)
#define KEY_UP(k) Control::Get()->Up(k)
#define KEY_PRESS(k) Control::Get()->Press(k)

#define MOUSEPOS Control::Get()->GetMouse()

#define DELTA Timer::Get()->GetElapsedTime()

#define CAMERA Environment::Get()->GetMainCamera()

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
#include <DirectXCollision.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

//DirectWrite
#include <d2d1_2.h>
#include <dwrite.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

//DirectXTex
#include "../DirectXTex/DirectXTex.h"

//ImGui
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx11.h"
#include "../ImGui/imgui_impl_win32.h"

using namespace DirectX;
using namespace std;
using namespace DirectX::TriangleTests;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMVECTOR Vector4;
typedef XMMATRIX Matrix;
typedef XMFLOAT4X4 Float4x4;

const XMVECTORF32 kRight = { 1, 0, 0 };
const XMVECTORF32 kUp = { 0, 1, 0 };
const XMVECTORF32 kForward = { 0, 0, 1 };

//Framework Header
#include "Framework/Utility/Utility.h"
#include "Framework/Utility/Singleton.h"
#include "Framework/Utility/BinaryReader.h"
#include "Framework/Utility/BinaryWriter.h"
#include "Framework/Utility/Control.h"
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/Xml.h"
#include "Framework/Utility/DirectWrite.h"

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
#include "Framework/Render/Texture.h"
#include "Framework/Render/Material.h"

#include "Framework/Math/Vector3.h"
#include "Framework/Math/Transform.h"

#include "Framework/State/RasterizerState.h"
#include "Framework/State/SamplerState.h"

#include "Environment/Camera.h"
#include "Environment/Environment.h"

//Object Header
#include "Objects/Basic/Cube.h"
#include "Objects/Basic/Sphere.h"

#include "Objects/Landscape/Terrain.h"

//Scene Header
#include "Scene/Scene.h"
#include "Program/Program.h"

extern HWND hWnd;
