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
	std::cout << "-- Configuring the MemoryViewer --" << std::endl << std::endl;

	SetStepSize();
	SetAmountOfRows();
	SetMemoryLocation();

	EndLine();
}

void MemoryViewer::Run()
{
}

void MemoryViewer::Restart()
{
}


// Ask a question and set the step size with which we will work.
void MemoryViewer::SetStepSize()
{
	std::cout << "Please enter the step size with which the rows will be visualized: ";
	std::cin >> _stepSize;

	// if the given step size is invalid for some reason, notify the user and take a default value;
	if (!_stepSize)
	{
		std::cin.clear();
		std::cout << std::endl << "Something went wrong with setting the step size... The default step size of 8 will be used." << std::endl;
		_stepSize = 8;
	}
}

// Ask a question and set the amount of rows we will display per batch.
void MemoryViewer::SetAmountOfRows()
{
	std::cout << std::endl << "Please enter the desired amount of rows you would like to see: ";
	std::cin >> _amountOfRows;

	if (!_amountOfRows)
	{
		std::cin.clear();
		std::cout << std::endl << "Something went wrong with setting the amount of rows... The default iteration size of 10 will be used." << std::endl;
		_amountOfRows = 10;
	}
}

// Ask a question and set the memory location at which we will start reading.
void MemoryViewer::SetMemoryLocation()
{
	std::cout << std::endl << "Please enter a Memory adress (hex) where the Viewer will start looking" << std::endl
		<< "Should you fail to find any 'readable' memory, enter 0x00000000 and I will use a pre-set location." << std::endl
		<< "Address: 0x";

	unsigned int userAddress;
	std::cin >> std::hex >> userAddress;

	// If the user did not enter a custom location, simply use the location of _stepSize.
	if (!userAddress)
		_memoryAddress = std::addressof(_stepSize);
	else
		_memoryAddress = (unsigned int*)userAddress;
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
