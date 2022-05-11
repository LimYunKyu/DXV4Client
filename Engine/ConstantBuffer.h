#pragma once

enum class CONSTANT_BUFFER_TYPE : uint8
{
	GLOBAL,
	TRANSFORM,
	MATERIAL,
	END
};

enum
{
	CONSTANT_BUFFER_COUNT = static_cast<uint8>(CONSTANT_BUFFER_TYPE::END)
};


class ConstantBuffer
{
	ConstantBuffer();
	~ConstantBuffer();

public:
	void Init(CBV_REGISTER reg, uint32 size);
	void PushData(void* buffer, uint32 size);
	

private:

	CBV_REGISTER  _reg = {};

	ID3D11Buffer* _buffer;
	D3D11_MAPPED_SUBRESOURCE _mappedResource;
};

