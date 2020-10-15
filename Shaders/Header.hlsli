//VertexShaderBuffer
cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
    matrix invView;
}

cbuffer Projection : register(b2)
{
    matrix projection;
}

//PixelShaderBuffer
cbuffer Light : register(b0)
{
    float3 lightDirection;
}

cbuffer Material : register(b1)
{
    float3 mDiffuse;
    float padding1;
    
    float3 mSpeccular;
    float padding2;
    
    float3 mAmbient;
    float padding3;
    
    float shininess;
}

SamplerState samp : register(s0);

Texture2D diffuseMap : register(t0);
Texture2D specularMap : register(t1);


//Vertex Layouts
struct Vertex
{
    float4 pos : Position;
};

struct VertexUV
{
    float4 pos : Position;
    float2 uv : UV;
};

struct VertexUVNormal
{
    float4 pos : Position;
    float2 uv : UV;
    float3 normal : Normal;
};
