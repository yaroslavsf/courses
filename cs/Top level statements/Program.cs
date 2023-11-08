using System;

namespace cs_practise
{

    
    class Program 
    {

        static void Main(string[] args)
        {
            Client atm = new Client();

            Console.WriteLine("\t\tTerminal\n");
            try
            {
                while (true)
                {
                    atm.ChooseBank();
                    switch (atm.EnteringSetUp())
                    {
                        case 1:
                            atm.OpenAccount();
                            break;
                        case 2:
                            atm.LoginToAccount();
                            break;
                        default:
                            Environment.Exit(0);
                            break;
                    }

                    if (atm.loggedIn == true)
                    {
                        atm.Menu();
                    }
                    

                }
                
            }
            catch(Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
