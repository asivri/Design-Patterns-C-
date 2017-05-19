#include <iostream>
#include <vector>
using namespace std;

//TODO:FIX THE CODE LATER.
//GIVES ERROR CURRENTY

class Email;
class Observer;

//Subject Class
class List{
public:
    virtual ~List(){};
    List(){};
    List(string mailBody): _message(mailBody) {};
    virtual void Attach(Email* eObj);
    virtual void Detach(Email* eObj);
    virtual void Notify();
    string getMessage()
    {
        return _message;
    }
    void setMessage(string mailBody)
    {
        _message = mailBody;
    }
private:
    vector<Email*> emails;
    string _message;
public:
     string getChannel()  {
        return channel;
    }

    void setChannel( string _channel) {
        channel = _channel;
    }

private:
    string channel;
};


//ConcreteSubject class
class Programming :public List{
public:
    Programming(string mailBody,string _channel, string mail):
            List(mailBody), List(_channel), mail(mail){};
    string getMail()
    {
        return mail;
    }
    void setMail(string _mail)
    {
        mail = _mail;
    }
private:
    string mail; //Internal subject state.
};

//Concrete Observer class
class Email: public Observer{
public:
    Email(string _sender, double _date): sender(_sender), date(_date){};

    void Update(List& list)
    {
        emailList = list;
        message = list.getMessage();
        channel = list.getChannel();
        cout<<"New message "<<message<<" to "<<channel<<" channel"<<endl;

    }

    string getSender()  {
        return sender;
    }

    void setSender( string _sender) {
        sender = _sender;
    }

    double getDate()  {
        return date;
    }

    void setDate(int _date) {
        date = _date;
    }

private:
    List emailList;
    string sender;
    double date;
    string message; //Internal observer state.
    string channel; //Internal observer state.
};

class Observer{
public:
    virtual ~Observer(){};
    virtual void Update(List& list) = 0;
};

void List::Attach(Email* email)
{
    emails.push_back(email);
}

void List::Detach(Email *eObj) {
    for(int i = 0; i<emails.size(); i++)
    {
        if(emails[i]->getSender() == eObj->getSender())
        {
            emails.erase(emails.begin()+1);
            return;
        }
    }
}

void List::Notify() {
    for(int i = 0; i<emails.size(); i++)
    {
        emails[i]->Update(*this);
    }
}

int main() {
    Email *f = new Email("Ahmet", 11.25);
    Email *s = new Email("John", 08.25);

    Programming* pObj = new Programming("First Message!", "Programming", "asivri@fredonia.com");
    pObj->Attach(f);


//    Programming* pObj = new Programming("Second Message!", "Programming", "john@hello.com");
//    pObj->Attach(s);

    return 0;
}