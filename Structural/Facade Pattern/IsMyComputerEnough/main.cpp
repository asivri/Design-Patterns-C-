#include <iostream>

using namespace std;
/*
 * Facade implementation of computer feature checking for a game
 * Implemented with Burak AKKANAT
 */

//Client Class
class Computer{

public:
    Computer(double _ram, double _ghz, double _gRam): ram(_ram), ghz(_ghz), gRam(_gRam){};
    double getRam()  {
        return ram;
    }

    void setRam(double ram) {
        ram = ram;
    }

    double getGhz()  {
        return ghz;
    }

    void setGhz(double ghz) {
        ghz = ghz;
    }

    double getGRam()  {
        return gRam;
    }

    void setGRam(double gRam) {
        gRam = gRam;
    }

private:
    double ram ;
    double ghz ;
    double gRam;
};

//Following classes are subclasses
class RAM{
public:
    void ramCheck(double ram)
    {
        if(ram >= requiredRam)
        {
            cout<<"RAM is good to play!"<<endl;
        }
        else
        {
            cout<<"RAM is not enough"<<endl;
        }
    }

private:
double requiredRam = 2048;
};

class Processor{
public:
    void processorCheck(double ghz)
    {
        if(ghz >= requiredGHZ)
        {
            cout<<"Processor is good to play!"<<endl;
        }
        else
        {
            cout<<"Processor is not enough"<<endl;
        }
    }

private:
    double requiredGHZ = 3.5;
};

class GPU{
public:
    void GPUCheck(double gRam)
    {
        if(gRam >= requiredgRam)
        {
            cout<<"GPU is good to play!"<<endl;
        }
        else
        {
            cout<<"GPU is not enough"<<endl;
        }
    }

private:
    double requiredgRam = 2;
};

//Facade class
class ReqCheck{
public:
    ReqCheck()
    {
        ram = new RAM();
        processor = new Processor();
        gpu = new GPU();
    }

    void CanYouRunIt(Computer* pc)
    {
        ram->ramCheck(pc->getRam());
        processor->processorCheck(pc->getGhz());
        gpu->GPUCheck(pc->getGRam());
    }
private:
    RAM *ram;
    GPU *gpu;
    Processor* processor;
};

int main() {

    Computer* pc = new Computer(4000, 3, 6);

    ReqCheck* fObj = new ReqCheck();
    fObj->CanYouRunIt(pc);

    return 0;
}