#include <iostream>
using namespace std;

/*
 * Scenario: A country has only one president. If he/she quit, an election should be performed.
 */

//Singleton Class
class Country{
public:
    static Country* getPresident()
    {
        //Lock synchronization here.
        if(president == NULL)
        {
            president = new Country();
        }
        return president;
    }
private:
    Country() //The constructor must be private.
    {
        cout<<"An election performed in the country."<<endl;
    }
    static Country* president; //static uniqueInstance.
};

int main() {
    Country* obj = Country::getPresident();
    return 0;
}