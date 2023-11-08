using System;
using System.Collections.Generic;
using System.Text;

namespace cs_practise
{
    class Client//assumed to be ATM
    {
        //there are list of banks in terminal that supposed to be used
        Bank centralBank, commercialBank;
        private string? choosedBank;
        /*private bool sessionState;*/
        private bool _loggedIn;
        public bool loggedIn
        {
            get { return _loggedIn; }
            set { _loggedIn = value; }
        }
        public string? _password;
        public int _creditCard;
        public Client()
        {
            centralBank = new Bank();
            commercialBank = new Bank();
            _loggedIn = false;
        }

        public void LoginToAccount()
        {
            Bank tempBank;
            tempBank = choosedBank == "central" ? centralBank : commercialBank;
            string?  password = "";
            int creditCard = 0;

           
            
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("Enter your card");
                creditCard = int.Parse(Console.ReadLine());

                Console.WriteLine("Enter your password");
                password = Console.ReadLine();

                loggedIn = tempBank.Login(creditCard, password);
                if (loggedIn == false)
                    Console.WriteLine("Try again, password is incorrect\n");
                else
                    break;
            }
            if (loggedIn == false)
                throw new Exception("Password is incorrect, 3 tries run ");

            _password = password;
            _creditCard = creditCard;

        }
        public void OpenAccount()
        {
            
            Bank tempBank;
            tempBank = choosedBank == "central" ?  centralBank : commercialBank;
            string? name, surname, password;
            int creditCard;

            Console.WriteLine("Enter your name");
            name = Console.ReadLine();
            Console.WriteLine("Enter your surname");
            surname = Console.ReadLine();
            Console.WriteLine("Enter your password");
            password = Console.ReadLine();
            Console.WriteLine("Enter your card");
            creditCard = int.Parse(Console.ReadLine());

            tempBank.CreateAccount(name, surname, password, creditCard);
            Console.WriteLine("you have succesfuly opened an account");
        }

        public int EnteringSetUp()
        {
            Console.WriteLine("Choose the one option\n1 - Open an account\n2 - Loggin to account\n3 - exit");
            //assumed that this is one session here
            string consoleInput = Console.ReadLine();
            return consoleInput != "" ? int.Parse(consoleInput) : 0; //returns 0 just to exit the program

        }

        public void ChooseBank()
        {
            Console.WriteLine("Choose the bank to work with\n1 - \"Central Bank\"\n2 - \"Commercial Bank\"");
            int? choice = 0;
            choice = int.Parse(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    choosedBank = "central";
                    break;
                case 2:
                    choosedBank = "commercial";
                    break;
                default:
                    throw new Exception("There is no such bank");

            }
        }

        public void Replenish(Bank tempBank)
        {
            decimal money;
            Console.WriteLine("Enter amount of money to replenish");
            money = Convert.ToDecimal(Console.ReadLine());
            tempBank.ReplenishBankAccount(_creditCard, _password, money);

        }
        public void ShowSavings(Bank tempBank)
        {
            decimal savs = tempBank.ShowSavingsAccount(_creditCard, _password);
            if (savs == 0)
            {
                Console.WriteLine("You have no money on your balance");
            }
            else
            {
                Console.WriteLine($"money: {savs}");
            }
        }

        public void Withdraw(Bank tempBank)
        {
            decimal money, result;
            Console.WriteLine("Enter amount of money to withdraw");
            money = Convert.ToDecimal(Console.ReadLine());
            result = tempBank.WithDrawMoney(_creditCard, _password, money);
            if (result != -1)
            {
                Console.WriteLine($"You have succesfuly withdrawed the money: {result}");

            }
            else 
            {
                Console.WriteLine("Not enough money");

            }
        }
        public void Menu()
        {
            Bank tempBank;
            tempBank = choosedBank == "central" ? centralBank : commercialBank;
            int? choice = 0;
            
            while (choice != 3)
            {
                Console.WriteLine("Options:\n1 - show the savings\n2 - replenish the account\n3 - withdraw money\n4 - exit");
                choice = int.Parse(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        ShowSavings(tempBank);
                        break;
                    case 2:
                        Replenish(tempBank);
                        break;
                    case 3:
                        Withdraw(tempBank);
                        break;
                    default:
                        break;
                }
            }
            

        }
    }
}
