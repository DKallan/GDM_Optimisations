#include "MemoryViewer.h"

MemoryViewer::MemoryViewer()
{
	Initialize();
}

MemoryViewer::~MemoryViewer()
{
}

void MemoryViewer::Initialize()
{
	SetStepSize();
	SetAmountOfRows();
	SetMemoryLocation();
}

void MemoryViewer::Run()
{
}

void MemoryViewer::Restart()
{
}

void MemoryViewer::SetStepSize()
{
	_stepSize = 8;
}

void MemoryViewer::SetAmountOfRows()
{
	_amountOfRows = 10;
}

void MemoryViewer::SetMemoryLocation()
{
	_memoryAddress = std::addressof(_stepSize);
}

void MemoryViewer::DisplayMemory()
{
}

void MemoryViewer::Outline(unsigned int* pointer) const
{
}

void MemoryViewer::PrintPointerValue(unsigned int* pointer) const
{
}

void MemoryViewer::PrintPointerValueAsChar(unsigned int* pointer) const
{
}

int MemoryViewer::Filter(unsigned int code, _EXCEPTION_POINTERS* exceptionPointer) const
{
	return 0;
}
