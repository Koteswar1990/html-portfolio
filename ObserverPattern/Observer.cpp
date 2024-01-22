#include <iostream>
#include <list>
#include <string>

using namespace std;

class Observer
{
    public:
    virtual void notify() const{};
    virtual ~Observer(){};
};
class Subject
{
  public:
    void registerObserver(Observer* observer)
    {
        observers.push_back(observer);
    }
    void unregisterObserver(Observer* observer){
        observers.remove(observer);
    }
    void notifyObservers(){
        for(auto observer: observers){
            observer->notify();
        }
    }
  private:
    std::list<Observer*> observers;
};

class ConcreateObserverA: public Observer{
    public:
      ConcreateObserverA(Subject& subject):subject_(subject){
        subject_.registerObserver(this);
      }
      void notify() const{
        cout<<"ConcreateObserverA::notify"<<endl;
      }
    private:
      Subject& subject_;
};

class ConcreateObserverB : public Observer{
    public:
      ConcreateObserverB(Subject& subject):subject_(subject){
        subject_.registerObserver(this);
      }
      void notify() const{
        cout<<"ConcreateObserverB::notify"<<endl;
      }
    private:
      Subject& subject_;
};

int main()
{
    Subject subject;

    ConcreateObserverA observerA(subject);
    ConcreateObserverB observerB(subject);

    subject.notifyObservers();
    cout<<"Subject----->unregister ObserverA"<<endl;
    subject.unregisterObserver(&observerA);
    subject.notifyObservers();

    return 0;
  
}
