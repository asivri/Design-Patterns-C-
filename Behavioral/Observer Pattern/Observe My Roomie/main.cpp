#include <iostream>
#include <vector>
using namespace std;

/*
 * Scenario: Suppose that you need to notify your housemates when you want to invite a guest.
 * Implemented by Ahmet Sivri&Burak Akkanat
 */

class Observer;

//Abstract Subject class
class Resident {
public:
    virtual ~Resident() { }

    Resident() { };

    virtual void Attach(Observer *obj) = 0;
    virtual void Detach(Observer *obj) = 0;
    virtual void Notify() =0;
    virtual bool isGuestComing() =0;

    virtual void setGuestComing(bool _guestComing) =0;

private:
    vector<Observer*> houseMates;
    bool guestComing;
};

//Concrete Subject class
class ME: public Resident{
public:

    ME() { }

    ~ME() { }
    void setGuestComing(bool _guestComing) {
        guestComing = _guestComing;
        Notify();
    }
    void Attach(Observer *obj)
    {
        houseMates.push_back(obj);
    }
    void Detach(Observer *obj)
    {
        for(int i=0; i<houseMates.size(); i++)
        {
            if(houseMates[i] == obj)
            {
                houseMates.erase(houseMates.begin()+1);
            }
        }
    }
    void Notify();

    bool isGuestComing()  {
        return guestComing;
    }

//    void setGuestComing(bool _guestComing) {
//        guestComing = _guestComing;
//    }

private:
    bool guestComing;
    vector<Observer*> houseMates;
};


//Abstract Observer Class
class Observer{
public:
    virtual ~Observer(){};
    virtual void Update(Resident& r) = 0;
};

// Observer Class
class HouseMate: public Observer{
public:
    void Update(Resident& s)
    {
        setComingHome(s.isGuestComing());
    }
    void setComingHome(bool _comingHome) {
        comingHome = _comingHome;
    }
    bool isComingHome()  {
        return comingHome;
    }

private:
    Resident* s;
    bool comingHome = false;
};


void ME::Notify() {
    for(unsigned int i=0; i<houseMates.size(); i++)
    {
        houseMates[i]->Update(*this);
    }
}

int main() {
    ME *Ahmet = new ME();
    ME *Burak = new ME();

    HouseMate *Umut = new HouseMate();
    HouseMate *Kenan = new HouseMate();
    HouseMate *Ayse = new HouseMate();

    Ahmet->Attach(Umut);
    Ahmet->Attach(Kenan);
    Ahmet->Attach(Ayse);
    Ahmet->setGuestComing(true);
    cout<<Kenan->isComingHome()<<endl;

    Burak->Attach(Umut);
    Burak->Attach(Kenan);
    Burak->setGuestComing(false);
    cout<<Kenan->isComingHome()<<endl;

    return 0;
}