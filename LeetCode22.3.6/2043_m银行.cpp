#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int n=balances.size();
        if(account1 > n || account2>n || balances[account1-1]<money)
            return false;
        balances[account1-1] -= money;
        balances[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int n=balances.size();
        if(account > n )
            return false;
        balances[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int n=balances.size();
        if(account > n || balances[account-1]<money)
            return false;
        balances[account-1] -= money;
        return true;
    }
private:
    vector<long long> balances;

};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */