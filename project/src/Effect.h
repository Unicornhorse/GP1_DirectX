using namespace dae;

class Effect
{
public:
    // Constructor & Destructor
    Effect(ID3D11Device* pDevice, const std::wstring& assetFile);
    ~Effect();
    
    // Getters
    ID3DX11EffectTechnique* GetTechnique() const;
	void SetWorldMatrix(const Matrix& world) const;
    //ID3D11InputLayout* GetInputLayout() const;
private:
    ID3DX11Effect* m_pEffect;
    ID3DX11EffectTechnique* m_pTechnique{};
    ID3D11InputLayout* m_pInputLayout{}; 

    ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);
    ID3DX11EffectMatrixVariable* m_pWorldMatrixVariable{};
};