#include <iostream>

/*
 * Scenario: This program implements ascending and descending orders
 * of bubble sort algorithm.
 * Coder: Ahmet Sivri
 * This program based on a lab work of Software Architecture class
 * in Izmir University of Economics.
 */

using namespace std;

int MAX = 0;

//This is the Abstract Class
class Sort{
public:
    void sort()
    {
        cout<<"Sorting the array: "<<endl;
        getInput();
//        checkInput();
        compare();
        display();
    }

protected:
    //Those are the Primitive Operation which will be overridden
    //by the subclasses.
    virtual void getInput() =0;
    //Terminates the getInput process with a negative number.
    virtual void checkInput(int input) = 0;
    virtual void display() = 0;
    virtual void compare() = 0;
private:
    int arr[];
};

//Following classes are Concrete Classes
class AscendingOrder: public Sort{
public:
    AscendingOrder() {};
protected:
    void getInput()
    {
        int nSize;
        cout<<"Please enter how many numbers that you will enter: ";
        cin>>nSize;
        cout<<endl;
        cout<<"Please enter your array: ";
        for(int i=0; i<nSize; i++)
        {
            cin>>arr[i];
            checkInput(arr[i]);
            length++;
        }
    }
    //Terminates the getInput process with a negative number.
    void checkInput(int input)
    {

        int checkArr[MAX];
        for(int i=0; i<MAX;  i++)
        {
            if(checkArr[input] < 0)
            {
                break;
            }
        }
    }
    void compare()
    {
        for(int i=0; i<length-1 ;i++)//Make loop till to reach lenght-1
        {
            int temp;
            bool isSorted = false;
            if(arr[i]> arr[i+1])//Swap two
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSorted = true;
            }
        }
    }
    //Print out sorted array
    void display()
    {
        for(int i = 0; i<length; i++)
        {
            cout<<arr[i]<<" ,";
        }
    }


private:
    int arr[];
    int length = 0;
};

class DescendingOrder: public Sort{
protected:
    void getInput()
    {

        int nSize;
        cout<<"Please enter how many numbers that you will enter: ";
        cin>>nSize;
        cout<<endl;
        cout<<"Please enter your array: ";
        for(int i=0; i<nSize; i++)
        {
            cin>>arr[i];
            checkInput(arr[i]);
            length++;
        }
    }
    //Terminates the getInput process with a negative number.
    void checkInput(int input)
    {

        int checkArr[MAX];
        for(int i=0; i<MAX;  i++)
        {
            if(checkArr[input] < 0)
            {
                break;
            }
        }
    }
    void compare()
    {
        for(int i=0; i<length-1 ;i++)//Make loop till to reach lenght-1
        {
            int temp;
            bool isSorted = false;
            if(arr[i]< arr[i+1])//Swap two
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSorted = true;
            }
        }
    }
    //Print out sorted array
    void display()
    {
        for(int i = 0; i<length; i++)
        {
            cout<<arr[i]<<" ,";
        }
    }


private:
    int arr[];
    int length = 0;
};

int main() {
    AscendingOrder aObj;
    aObj.sort();

    return 0;
}

