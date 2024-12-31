//-----------------
// WorldViewProjection
//-----------------
float4x4 gWorldViewProj : WorldViewProjection;

//-----------------
// Texture
//-----------------
Texture2D gDiffuseMap : DiffuseMap;

SamplerState samPoint
{
    Filter = MIN_MAG_MIP_LINEAR; // options are: POINT, LINEAR, ANISOTROPIC
    AddressU = Wrap; // options are: WRAP, MIRROR, CLAMP, BORDER
    AddressV = Wrap;
};

//-----------------
// input/output structs
//-----------------
struct VS_INPUT
{
    float3 Position : POSITION;
    float3 Color : COLOR;
    float2 TexCoord : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 Position : SV_POSITION;
    float3 Color : COLOR;
    float2 TexCoord : TEXCOORD;
};

//-----------------
// Vertex Shader
//-----------------
VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    output.Position = mul(float4(input.Position, 1.f), gWorldViewProj);
    output.Color = input.Color;
    output.TexCoord = input.TexCoord;
    return output;
}

//-----------------
// Pixel Shader
//-----------------
float4 PS(VS_OUTPUT input) : SV_TARGET
{
    //return float4(input.Color, 1.f);
    //Output.RGBColor = g_MeshTexture.Sample(MeshTextureSampler, In.TextureUV) * In.Diffuse;
    //return float4(input.UV, 0.0, 1.0);
    return gDiffuseMap.Sample(samPoint, input.TexCoord);
}

//-----------------
// Technique
//-----------------
technique11 DefaultTechnique
{
    pass P0
    {
        SetVertexShader( CompileShader( vs_5_0, VS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_5_0, PS() ) );
    }
}