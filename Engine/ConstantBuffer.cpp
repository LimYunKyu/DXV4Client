#include "pch.h"
#include "ConstantBuffer.h"
#include "DXManager.h"

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::Init(CBV_REGISTER reg, uint32 size)
{
	_reg = reg;

 ////////////////////////////////////////////////
 //                                            //
 //        Create Dynamic Constant Buffer      //
 //                                            //
 ////////////////////////////////////////////////


	D3D11_BUFFER_DESC  cbDesc;
	cbDesc.ByteWidth = size;
	cbDesc.Usage = D3D11_USAGE_DYNAMIC;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cbDesc.MiscFlags = 0;
	cbDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA cbData;
	cbData.pSysMem = nullptr;
	cbData.SysMemPitch = 0;
	cbData.SysMemSlicePitch = 0;

	
	DEVICE->CreateBuffer(&cbDesc, &cbData, &_buffer);

	ZeroMemory(&_mappedResource, sizeof(D3D11_MAPPED_SUBRESOURCE));

	DEVICECONTEXT->Map(_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &_mappedResource);



}

void ConstantBuffer::PushData(void* buffer, uint32 size)
{

	memcpy(_mappedResource.pData, buffer, size);
	DEVICECONTEXT->VSSetConstantBuffers(0, 1, &_buffer);

}


