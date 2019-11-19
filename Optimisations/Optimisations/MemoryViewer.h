#pragma once
#ifndef _MEMORY_VIEWER_H_
#define _MEMORY_VIEWER_H_

// Includes.
#include <iomanip>
#include <iostream>
#include <Windows.h>

class MemoryViewer
{
private:
	unsigned int _stepSize;
	unsigned int _amountOfRows;
	unsigned int* _memoryAddress;

public:
	MemoryViewer();
	~MemoryViewer();

	void Initialize();
	void Run();
	void Restart();

private:
	void SetStepSize();
	void SetAmountOfRows();
	void SetMemoryLocation();

	void DisplayMemory();

	void Outline(unsigned char* pointer) const;
	void PrintPointerValue(unsigned char* pointer) const;
	void PrintPointerValueAsChar(unsigned char* pointer) const;

	int Filter(unsigned int code, struct _EXCEPTION_POINTERS* exceptionPointer) const;

	// Wrapper for a new line.
	void EndLine() { std::cout << std::endl; };
};

#endif