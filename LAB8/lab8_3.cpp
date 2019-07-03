#include <iostream>
using namespace std;

class Train{
protected:
    int mPeople; //number of people
    
public:
    Train(){}
    Train(int people):
        mPeople(people){}
    ~Train(){}
    
    virtual int station(int takeOff, int takeOn){
        return mPeople;
    }
    
};

class Ktx: public Train{
public:
    Ktx(): Train(0){}
    Ktx(int people): Train(people){}
    ~Ktx(){}
    
    int station(int takeOff, int takeOn) override{
        mPeople = takeOn - takeOff;
        return mPeople;
    }
    
    int getPeople(){
        return mPeople;
    }
    
    void print(){
        cout<<mPeople<<endl;
    }
};


int main(){
    int takeOff = 0;;
    int takeOn = 0;
    int sum = 0;
    int cus[5];
    int max = 0;
    
    Ktx k;
    
    for(int i = 0; i < 5; i++){
        cout<<i+1<<" Station:";
        cin>>takeOff>>takeOn;
        cus[i] = k.station(takeOff, takeOn);
        sum += cus[i];

        if(sum > 300){
            cout<<">> The regular number is exceeded!!"<<endl;
            break;
        }
        else if(sum < 0){
            cout<<">> The regular number is not reach!!"<<endl;
            break;
        }
        
    }
    
    if(sum < 300 and sum >= 0){

        for(int j = 0; j < 5; j++){
            sum += cus[j];
            if(sum > max){
                max = sum;
            }
        }
    cout<<"Number of people when most people boarded = "<<max<<endl;
    }
    
    
    return 0;
}
