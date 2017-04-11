#include <iostream>
#include <vector>
#include <numeric> //To use accumulate function.
#include <math.h> //To use sqrt

using namespace std;


//Subclasses are following 4 classes: Mean, Deviation, Variance, and StandardDeviation
class Mean{
public:
    double ComputeMean(vector<int> numVec)
    {
        double mean;
        mean = (std::accumulate(numVec.begin(), numVec.end(), 0.0)) / numVec.size();
        return mean;
    }
};

class Deviation{
public:
    double ComputeDeviation(double mean, vector<int> numVec)
    {
        double deviation = 0;
        for(int i=0; i<numVec.size(); i++)
        {
            deviation += (numVec[i] - mean) * (numVec[i] - mean);
        }
        return deviation;
    }
};

class Variance{
public:
    double ComputeVariance(double deviation, int size)
    {
        double variance = deviation / size;

        return variance;
    }
};

class StandardDeviation{
public:
    double ComputeStandard(double variance)
    {
        double standardDeviation;

        standardDeviation = sqrt(variance);

        return standardDeviation;
    }
};

//The following class is Facade class which implements the standard deviation only.
class CalculatorFacade{
public:
    CalculatorFacade(double d)
    {
        mObj = new Mean();
        dObj = new Deviation();
        vObj = new Variance();
        sObj = new StandardDeviation();
    }

    double StDevFacade(double variance)
    {
        double stDevF = sObj->ComputeStandard(variance);
        return stDevF;
    }
private:
    Mean *mObj;
    Deviation *dObj;
    Variance *vObj;
    StandardDeviation *sObj;
};

//TODO: Ask if it's client class or subclass?
class InputReceiver{
    
};


int main() {
    //Declaration of the subclass objects
    Mean *mObj = new Mean();
    Deviation *dObj = new Deviation();
    Variance *vObj = new Variance();
    StandardDeviation *sObj = new StandardDeviation();

    //Declaration of the facade class object;
    CalculatorFacade *fObj = new CalculatorFacade(0);

    //Declaration of the local variables
    double mean;
    double deviation;
    double variance;
    double standard;

    //Declaration of the vector will be used for computations.
    vector<int> mainVec;
    mainVec.push_back(1);
    mainVec.push_back(2);
    mainVec.push_back(3);
    mainVec.push_back(4);
    mainVec.push_back(5);
    mainVec.push_back(6);
    mainVec.push_back(7);
    mainVec.push_back(8);
    mainVec.push_back(9);
    mainVec.push_back(10);

    //Calling the functions from classes.
    mean = mObj->ComputeMean(mainVec);
    cout<<"The mean is: "<<mean<<endl;

    deviation = dObj->ComputeDeviation(mean, mainVec);
    cout<<"The deviation is: "<<deviation<<endl;

    variance = vObj->ComputeVariance(deviation, mainVec.size());
    cout<<"The variance is: "<<variance<<endl;

    standard = fObj->StDevFacade(variance);
    cout<<"The standard  deviation by facade class is: "<<standard<<endl;




    return 0;
}