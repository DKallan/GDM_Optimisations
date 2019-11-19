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

// Main execution for this Viewer. Will ask questions and respond accordingly.
void MemoryViewer::Run()
{
	DisplayMemory();

	std::cout << std::endl << "Would you like to display the next " << _amountOfRows << " rows? (y/n)" << std::endl;

	char answer;
	std::cin >> answer;

	if (answer == 'y')
		return Run(); // return as we don't want to execute below code multiple times (otherwise it gets executed each time 'Run()' is executed).
	else if (answer != 'n')
		std::cout << "I did not quite understand that answer... I will asume you did not want those extra rows.";

	std::cout << std::endl << "Would you like to re-configure the settings of this Viewer? (y/n where n will return to the main menu)" << std::endl;
	std::cin >> answer;
	std::cout << std::endl;

	if (answer == 'y')
		return Restart(); // return as we don't want to execute below code multiple times (otherwise it gets executed each time 'Run()' is executed).
	else if (answer != 'n')
		std::cout << "I did not quite understand that answer... I will assume you wanted to exit the program.";

	std::cout << std::endl;

	return;
}

// Wrapper for Initialize() and Run() in that order.
void MemoryViewer::Restart()
{
	Initialize();
	Run();
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
	unsigned char a = 'a';
	unsigned char* charPtr = std::addressof(a);

	for (size_t i = 0; i < _amountOfRows; i++)
	{
		std::cout << "0x" << (void*)charPtr << " ";
		
		for (size_t j = 0; j < _stepSize; j++)
		{
			__try
			{
				PrintPointerValue(charPtr + j);
			}
			__except (Filter(GetExceptionCode(), GetExceptionInformation()))
			{
				Outline(nullptr);
			}
		}

		// Increment the pointer by the step size we took.
		charPtr += _stepSize;

		EndLine();
	}
}

void MemoryViewer::Outline(unsigned char* pointer) const
{
	if (!pointer)
	{
		std::cout << std::setw(2) << std::setfill('?') << " ";
	}
	else
	{
		std::cout << std::setfill('0') << std::setw(2) << std::hex << (0xff & (unsigned int)*pointer) << " ";
	}
}

void MemoryViewer::PrintPointerValue(unsigned char* pointer) const
{
	Outline(pointer);
}

void MemoryViewer::PrintPointerValueAsChar(unsigned char* pointer) const
{
}

int MemoryViewer::Filter(unsigned int code, _EXCEPTION_POINTERS* exceptionPointer) const
{
	return 0;
}
