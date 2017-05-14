#include <iostream>
using namespace std;
/*
 *Scenario: A customer  calls our software company call center representative(Facade) to get help.
 * If the customer is not worked with us, representative delegates the to Advertisement department.
 * If the project isn't done yet, delegates to the Development department.
 * If the project is done, delegates to the Support department.
 */

//Client class
class Customer{
public:
    Customer(string name): name(name){};
    string getName()
    {
        return name;
    }
private:
    string name;
};




//Subsystem class 1
class Advertisment{
public:
    void advertise(Customer *c)
    {
        cout<<"New campaign are listed for "<<c->getName()<<endl;

    }
};

//Subsystem class 2
class Development{
public:
    void processInfo()
    {
        cout<<"78% of your project is done"<<endl;
    }
};

//Subsystem class 3
class Support{
public:
    void maintain(Customer *c)
    {
        cout<<"Customer "<<c->getName()<<" . Maintaining the project for future release."<<endl;
    }
};


//Facade class
class CallCenter{
private:
    Advertisment *ad;
    Development *dev;
    Support *sp;
public:
    CallCenter()
    {
        ad = new Advertisment();
        dev = new Development();
        sp = new Support();
    }
//Checks if the caller already work with our company. If not so,
//delegate to advertisement
    bool IsCustomer(Customer *cObj)
    {
        cout<< cObj->getName() <<"called us"<<endl;

        if(cObj->getName() == "Chuck Norris" || cObj->getName() == "Gregory House")
        {
            IsDone(cObj);
            return true;
        }
        else
        {
            ad->advertise(cObj);
            return false;
        }

    }

    bool IsDone(Customer *cObj)
    {
        if(cObj->getName() == "Chuck Norris")
        {
            sp->maintain(cObj);
            return true;
        }
        else
            dev->processInfo();
        return false;

    }

};

int main() {
    //Facade
    CallCenter* fObj = new CallCenter();

    //Call the call center
    Customer *cObj = new Customer("Chuck Norris");

    //Connect to facade by the customer
    fObj->IsCustomer(cObj);

    return 0;
}