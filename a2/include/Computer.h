#include <iostream>

class ALU {
    public:
    ALU(int); // ALU constructor takes an integer to set the number of cores.

    int getNumPerCores() const; // this is the getter of the number of cores.

    private:
    int numPerCores; 

    public: // operations that will be done in CPU as mentioned in the assignment
    const int add(int, int) const;
    const int subtract(int, int) const;
    const int multiply(int, int) const;
};

class CUDA {
    public:
    CUDA(int); // CUDA constructor takes an integer to set the number of cores.

    int getNumCores() const; // this is the getter of the number of cores.

    private:
    int numCores;

    public: // operations that will be done in CPU as mentioned in the assignment
    const std::string render() const;
    const std::string trainModel() const;
};

class CPU{
    public:
    CPU(int); // constructor of the CPU takes the number of cores
    ~CPU();

    const ALU* getALU() const; // getter of the ALU object in the CPU

    private:
    const ALU* alu; // this is the ALU object in the CPU

    public:
    const int execute(std::string) const; // takes operation name as an argument and returns the result of the operation.
};

class GPU{
    public:
    GPU(int); // constructor of the GPU takes the number of cores
    ~GPU();

    const CUDA* getCUDA() const; // getter of the CUDA object in the GPU

    private:
    const CUDA* cuda; // this is the CUDA object in the GPU

    public:
    const std::string execute(std:: string) const; // takes operation name as an argument and returns the result of the operation.
};

class Computer
{
    public:
    Computer(); // initializes the CPU and GPU as null

    void operator+ (const CPU &); // overloading the + operator for adding CPU to the Computer
    void operator+ (const GPU &); // overloading the + operator for adding GPU to the Computer

    const CPU* getAttachedCPU() const; // getter of the attached CPU object in the Computer
    void setAttachedCPU(const CPU &); // setter of the attached CPU object in the Computer

    const GPU* getAttachedGPU() const; // getter of the attached GPU object in the Computer
    void setAttachedGPU(const GPU &); // getter of the attached GPU object in the Computer

    private:
    const CPU* attachedCPU; 
    const GPU* attachedGPU;

    public:
    void execute(std::string) const; // it calls the execute method of the CPU or GPU taking the operation into consideration.
};
