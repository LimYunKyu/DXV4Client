#include "pch.h"
#include "BufferManager.h"

void BufferManager::CreateConstantBuffer(CBV_REGISTER reg, uint32 bufferSize)
{
	uint8 typeInt = static_cast<uint8>(reg);
	assert(_constantBuffers.size() == typeInt);

	shared_ptr<ConstantBuffer> buffer = make_shared<ConstantBuffer>();
	buffer->Init(reg, bufferSize);
	_constantBuffers.push_back(buffer);


}
