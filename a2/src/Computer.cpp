#include "../include/Computer.h"
#include <iostream>

using namespace std;

// Computer

Computer::Computer() // The constructor of the computer initializes the CPU and GPU as null pointers.
{
    this->attachedCPU = nullptr;
    this->attachedGPU = nullptr;
    cout << "Computer is ready" << endl;
}

const CPU *Computer::getAttachedCPU() const
{
    return this->attachedCPU;
}

void Computer::setAttachedCPU(const CPU &attachedCPU)
{
    this->attachedCPU = &attachedCPU;
}

const GPU *Computer::getAttachedGPU() const
{
    return this->attachedGPU;
}

void Computer::setAttachedGPU(const GPU &attachedGPU)
{
    this->attachedGPU = &attachedGPU;
}

void Computer::operator+(const CPU &attachedCPU)
{
    if (getAttachedCPU() == nullptr) // if there is no CPU attached the Computer, the attached CPU is null
    {
        setAttachedCPU(attachedCPU); // so the argument of the operator+ will be attached to the Computer
        cout << "CPU is attached" << endl;
    }
    else // Otherwise, there exists an attached CPU
        cout << "There is already a CPU" << endl; // It shouws an error message
}

void Computer::operator+(const GPU &attachedGPU)
{
    if (getAttachedGPU() == nullptr) // if there is no GPU attached the Computer, the attached GPU is null
    {
        setAttachedGPU(attachedGPU); // so the argument of the operator+ will be attached to the Computer
        cout << "GPU is attached" << endl;
    }
    else // Otherwise, there exists an attached GPU
        cout << "There is already a GPU" << endl; // It shouws an error message
}

void Computer::execute(string operation) const
{
    if (operation == "add" || operation == "subtract" || operation == "multiply") // if the operation is add, subtract or multiply, it should be executed in CPU
        cout << getAttachedCPU()->execute(operation) << endl; // so, the execute method of the attached CPU is called.
    else if (operation == "trainModel" || operation == "render") // if the operation is trainModel, or render, it should be executed in GPU
        cout << getAttachedGPU()->execute(operation) << endl; // so, the execute method of the attached GPU is called.
    else
        return;
}

// ALU

ALU::ALU(int numPerCores) // constructor of the ALU takes an integer to be sent to numPerCores attribute of the object.
{
    this->numPerCores = numPerCores;
    cout << "ALU is ready" << endl;
}

int ALU::getNumPerCores() const
{
    return this->numPerCores;
}

const int ALU::add(int firstNum, int secondNum) const // takes two integers and returns the sum of them
{
    return firstNum + secondNum;
}

const int ALU::subtract(int firstNum, int secondNum) const // takes two integers and returns the difference of them
{
    return firstNum - secondNum;
}

const int ALU::multiply(int firstNum, int secondNum) const // takes two integers and returns the product of them
{
    return firstNum * secondNum;
}

// CUDA

CUDA::CUDA(int numCores) // constructor of the CUDA takes an integer to be sent to numPerCores attribute of the object.
{
    this->numCores = numCores;
    cout << "CUDA is ready" << endl;
}

int CUDA::getNumCores() const
{
    return this->numCores;
}

const string CUDA::render() const
{
    return "Video is rendered";
}

const string CUDA::trainModel() const
{
    return "AI Model is trained";
}

// CPU

CPU::CPU(int numALUCores) // The constructor of the CPU creates an ALU object in the CPU with the number of cores in CPU.
{
    this->alu = new ALU(numALUCores);
    cout << "CPU is ready" << endl;
}

CPU::~CPU() // the ALU object should be deleted when the CPU object is destructed.
{
    delete this->alu;
}

const ALU *CPU::getALU() const
{
    return this->alu;
}

const int CPU::execute(string operation) const // CPU takes two integers and according to operation name, returns the result of the wanted operation (add, subtract, or multiply)
{
    int firstInt, secondInt;

    cout << "Enter two integers" << endl;
    cin >> firstInt;
    cin >> secondInt;

    if (operation == "add")
        return getALU()->add(firstInt, secondInt);
    else if (operation == "subtract")
        return getALU()->subtract(firstInt, secondInt);
    else if (operation == "multiply")
        return getALU()->multiply(firstInt, secondInt);
    return 0;
}

// GPU

GPU::GPU(int numCUDACores) // The constructor of the GPU creates an CUDA object in the GPU with the number of cores in GPU.
{
    this->cuda = new CUDA(numCUDACores);
    cout << "GPU is ready" << endl;
}

GPU::~GPU() // the CUDA object should be deleted when the GPU object is destructed.
{
    delete this->cuda;
}

const CUDA *GPU::getCUDA() const
{
    return this->cuda;
}

const string GPU::execute(string operation) const // calls the correct CUDA function according to the operation, and returns the value of that CUDA function
{
    if (operation == "render")
        return getCUDA()->render();
    else if (operation == "trainModel")
        return getCUDA()->trainModel();
    return "";
}