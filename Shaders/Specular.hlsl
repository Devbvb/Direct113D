#include "Header.hlsli"


struct PixelInput
{
    float4 pos : SV_Position;
    float2 uv : UV;
    float3 normal : Normal;
    float3 viewDir : ViewDir;
};

PixelInput VS(VertexUVNormal input)
{
    PixelInput output;
    
    output.pos = mul(input.pos, world);
    
    float3 camPos = invView._41_42_43;
    output.viewDir = normalize(output.pos.xyz - camPos);
    
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, projection);
    
    output.normal = normalize(mul(input.normal, (float3x3) world));
   
    output.uv = input.uv;
    
    return output;
}

float4 PS(PixelInput input) : SV_Target
{
    float4 albedo = diffuseMap.Sample(samp, input.uv);
    
    float3 light = normalize(lightDirection);
    float3 normal = normalize(input.normal);
    float3 viewDir = normalize(input.viewDir);
    
    float diffuseIntensity = saturate(dot(normal, -light));
    
    float3 specular = 0;
    if (diffuseIntensity > 0)
    {
        float3 reflection = normalize(reflect(light, normal));
        specular = saturate(dot(reflection, -viewDir));
        float3 specularIntensity = specularMap.Sample(samp, input.uv).rgb;
        
        specular = pow(specular, shininess) * specularIntensity;
    }
    
    float3 diffuse = albedo.rgb * diffuseIntensity * mDiffuse;
    specular *= mSpeccular;
    float3 ambient = albedo.rgb * mAmbient;
    
    return float4(diffuse + specular + ambient, 1.0f);
}