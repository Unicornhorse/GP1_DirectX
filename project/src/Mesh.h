#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "vector"

#include "Effect.h"


using namespace dae;

struct Vertex_PosCol
{
	Vector3 position{};
	ColorRGB color{ colors::White };
};

class Mesh
{
public:
	Mesh(ID3D11Device* pDevice);
	~Mesh();

	void Render(ID3D11DeviceContext* pDeviceContext) const;

private:
	void CreateLayoutAndBuffers(ID3D11Device* pDevice, const std::vector<Vertex_PosCol>& vertices, const std::vector<uint32_t>& indices);

	void CreateVertexLayout(ID3D11Device* pDevice);
	void CreateVertexBuffer(ID3D11Device* pDevice, const std::vector<Vertex_PosCol>& vertices, const std::vector<uint32_t>& indices);
    
    // DirectX resources
    ID3D11Buffer* m_pVertexBuffer{ nullptr };
    ID3D11Buffer* m_pIndexBuffer{ nullptr };
    ID3D11InputLayout* m_pInputLayout{ nullptr };

    // Effect and technique
    Effect* m_pEffect{ nullptr };
    ID3DX11EffectTechnique* m_pTechnique{ nullptr };

    // Buffer sizes
    uint32_t m_NumIndices{ 0 };

    std::vector<uint32_t> m_Indices{};
    std::vector<Vertex_PosCol> m_Vertices{};
};
