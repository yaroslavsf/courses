using System;
using System.Collections.Generic;
using System.Text;

namespace cs_practise
{
    class Account
    {
        private int _creditCard;
        public int creditCard
        {
            get { return _creditCard; }
            set { _creditCard = value; }
        }

        private string _name;
        public string name
        {
            get { return _name; }
            set { _name = value; }
        }
        private string _surname;
        public string surname
        {
            get { return _surname; }
            set { _surname = value; }
        }
        private string _password;
        public string password 
        {
            get { return _password; }
            set { _password = value; }
        }

        private decimal _savings;
        public decimal savings
        {
            get { return _savings; }
            set { _savings = value; }
        }


        public Account(string name, string surname,  string pass, int creditCard)
        {
            _name = name;
            _surname = surname;
            _password = pass;
            _creditCard = creditCard;
            _savings = (decimal)0;
        }
    }
}
