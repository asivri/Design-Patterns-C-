#include <iostream>
#include <vector>
using namespace std;

class AbstractAggregate;
class ConcreteAggregate;
class Iterator;
class ConcreteIterator;

//TODO: Add Description and create a header file.
//Not working in this way.

class Channel{
public:
    Channel(string name): _name(name){};

    string get_name() {
        return _name;
    }

private:
    string _name;
};

class AbstractAggregate{
public:
    virtual ~AbstractAggregate(){};
    virtual Iterator* CreateIterator() = 0;
    virtual void add(Channel*) = 0;
    virtual int getCount() const = 0;
    virtual Channel* get(int) const = 0;

protected:
    AbstractAggregate(){};
};

class ConcreteAggregate: public AbstractAggregate{
public:
    ConcreteIterator* CreateIterator()
    {
        return new ConcreteIterator(this);
    }
    int getCount() const
    {
        int size = _channels.size();
        return size;
    }
    void add(Channel* channel)
    {
        _channels.push_back(channel);
    }
    Channel *get(int index) const {
        return _channels[index];
    }
private:
    vector<Channel*> _channels;
};

class Iterator{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Channel* CurrentItem() const = 0;

protected:
    Iterator(){};
};

class ConcreteIterator: public Iterator{
public:
    ConcreteIterator(const ConcreteAggregate *cAggregate)
            :_cAggregate(cAggregate), _current(0){};
    void First()
    {
        _current = 0;
    }
    void Next()
    {
        _current++;
    }
    Channel* CurrentItem() const
    {
        Channel *temp = nullptr;
        if(!IsDone())
             temp = _cAggregate->get(_current);
        return temp;
    }

    bool IsDone() const
    {
        return _current>= _cAggregate->getCount();
    }

private:
    const ConcreteAggregate* _cAggregate;
    int _current;
};

//Here is the client code
void printAggregate(Iterator& i)
{
    cout<<"Iterating over channels: "<<endl;
    for(i.First(); !i.IsDone(); i.Next())
    {
        cout<<i.CurrentItem()->get_name()<<endl;
    }
}



int main() {
    AbstractAggregate *aggregate = new ConcreteAggregate();
    aggregate->add(new Channel("FOX"));
    aggregate->add(new Channel("HBO"));
    aggregate->add(new Channel("CNN"));
    aggregate->add(new Channel("NBA TV"));
    aggregate->add(new Channel("NASA TV"));

    //Iterator Creation
    Iterator* iterator = aggregate->CreateIterator();

    printAggregate(*iterator);
    return 0;
}