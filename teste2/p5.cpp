// Answer Preload -->
#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.h"
 
using namespace std;
// <-- Answer Preload

class Regular:public Account{
    public:
        Regular(int n) : Account(n){
            amount_ = 0;
        }
        void increase_balance(float amount){
            amount_ += amount;
        }
        float get_balance() const override{
            return amount_;
        }
    private:
        float amount_;
};

class Deposits:public Account{
    public:
        Deposits(int n) : Account(n){

        }
        void add_deposit(float amount){
            deposits_.push_back(amount);
        }
        float get_deposit(int deposit_number) const{
            return deposits_[deposit_number-1];
        }
        float get_balance() const override{
            float sum = 0;
            for(float v: deposits_){
                sum += v;
            }
            return sum;
        }
    private:
        vector<float> deposits_;
};

int main(){
    return 0;
}