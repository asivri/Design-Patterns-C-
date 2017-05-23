#include <iostream>
#include <vector>
using namespace std;

//TODO: FIX IT

/*
 * Scenario: Many types of manufactured systems, such as
    computer systems and stereo systems, are composed of
    individual components and sub-systems that contain
    components. For example, a computer system can have
    various chassis that contain components (hard-drive
    chassis, power-supply chassis) and busses that contain
    cards. The entire system is composed of individual
    components (floppy drives, cd-rom drives), buses and
    chassis.
    This scenario is found online.

    This program ignored transparency and used safety which means child operation methods
    are implemented in the Composite Class.
 */

//Component class
class ComputerSystem{
public:
    void operation()
    {
        cout<<"Operation of ComputerSystem!"<<endl;
    }

    int getID()
    {
        return id;
    }

    virtual void Display(int location) = 0;

protected:
    ComputerSystem(int _id): id(_id){};
private:
    int id = 0;
};

//Following classes are leaf classes.
class HardDrive: public ComputerSystem{
public:
    HardDrive(int id): ComputerSystem(id){};
};

class GPU: public ComputerSystem{
public:
    GPU(int id): ComputerSystem(id){};
};

//Composite class.
class ComputerComposite: public ComputerSystem{
public:
    ComputerComposite(int id): ComputerSystem(id){};
    void Add(ComputerSystem* compositeObj)
    {
        compositeElements.push_back(compositeObj);
    }
    void Remove(ComputerSystem* compositeObj)
    {
        for(int i=0; i<compositeElements.size(); i++)
        {
            compositeElements.erase(compositeElements.begin()+1);
            return;
        }
    }

    void Display(int location)
    {
        for(int i=0; i<location; i++)
        {
            cout<<"Element with ID: "<<getID()<<endl;
        }

        for(int i=0; i<compositeElements.size(); i++)
        {
            compositeElements[i]->Display(location+2);
        }
    }
private:
    vector<ComputerSystem*> compositeElements;
};



int main() {
    ComputerComposite* root = new ComputerComposite(1);
    root->Add(new HardDrive(2));
    root->Add(new HardDrive(3));
    root->Add(new HardDrive(4));

    ComputerComposite* comp = new ComputerComposite(2);
    comp->Add(new GPU(1));
    comp->Add(new GPU(2));
    comp->Add(new GPU(3));
    root->Add(comp);
    root->Remove(comp);

    root->Display(1);


    return 0;
}