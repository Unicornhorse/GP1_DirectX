using namespace dae;

class Effect
{
public:
    // Constructor & Destructor
    Effect(ID3D11Device* pDevice, const std::wstring& assetFile);
    ~Effect();

    static ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);

    // Getters
    ID3DX11EffectTechnique* GetTechnique() const;
    ID3D11InputLayout* GetInputLayout() const;
private:
    ID3DX11Effect* m_pEffect{ nullptr };
    ID3DX11EffectTechnique* m_pTechnique{ nullptr };
    ID3D11InputLayout* m_pInputLayout{ nullptr };  
};