#pragma once

#include "ConstantBuffer.h"
class BufferManager
{
	DECLARE_SINGLE(BufferManager)
public:
	void CreateConstantBuffer(CBV_REGISTER reg, uint32 bufferSize);

private:
	vector<shared_ptr<ConstantBuffer>> _constantBuffers;
};

