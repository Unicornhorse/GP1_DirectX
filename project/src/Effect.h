#include "pch.h"

class Effect
{
   

public:
    // Constructor & Destructor
    Effect(ID3D11Device* pDevice, const std::wstring& assetFile);
    ~Effect();

    // Getters
    ID3DX11EffectTechnique* GetTechnique() const { return m_pTechnique; }
    ID3DX11Effect* GetEffect() const { return m_pEffect; }
private:
    // Private Members
    ID3DX11Effect* m_pEffect{ nullptr };
    ID3DX11EffectTechnique* m_pTechnique{ nullptr };

    
};