using System;
using System.Collections.Generic;
using System.Text;
namespace cs_practise
{
    class Bank
    {
        //number of accounts is limited
        Account[] accounts;
        //makes easier to count and add users
        private int counter;
        
        public Bank()
        {
            accounts = new Account[1000];
            counter = 0;
        }
        public decimal ShowSavingsAccount(int creditCard, string password)
        {
            for (int i = 0; i < counter; i++)
            {
                if (creditCard == accounts[i].creditCard && password == accounts[i].password)
                    return(accounts[i]._savings); 

            }
            throw new Exception("account was not found");
        }
        public void ReplenishBankAccount(int creditCard, string password, decimal money)
        {
            for (int i = 0; i < counter; i++)
            {
                if (creditCard == accounts[i].creditCard && password == accounts[i].password)
                    accounts[i]._savings += money;
             
            }
        }
        public bool Login(int creditCard, string password)
        {
            for (int i = 0; i < counter; i++)
            {
                if (creditCard == accounts[i].creditCard && password == accounts[i].password)
                return true;
            }
            return false;
        }

        public void CreateAccount(string name, string surname, string password, int creditCard)
        {
            if (counter == 999)
                throw new Exception("bank is full with accounts");
            Account acc = new Account(name, surname, password, creditCard);
            accounts[counter++] = acc;

        }

        public decimal WithDrawMoney(int creditCard, string password, decimal money)
        {
            for (int i = 0; i < counter; i++)
            {
                if (creditCard == accounts[i].creditCard && password == accounts[i].password)
                    if (money < accounts[i]._savings)
                        accounts[i]._savings -= money;
                        return accounts[i]._savings;

            }
            return -1;            
        }
    }
}
