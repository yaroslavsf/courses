#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#define MAX_THREADS 5
#define BUF_SIZE 255
#define MAX_SEM_COUNT 9

//определение результатов
#define ONE_PAIR 1
#define TWO_PAIRS 2
#define THREE_CARDS 3
#define FOUR_CARDS 4
#define FIVE_CARDS 5// in ascending order (5 cards)

CRITICAL_SECTION CriticalSection;
std::vector <int> player[5];
int results[5];
int counter = 0;                                                            //счетчик для создания(+ в создании каждому выдается по 1 карте)
int card;                                                                   //переменная для push_back в разных функциях
std::vector <int> cardsArr;   //карты(60)
void fillCardsArray()   //+swap
{
    
    for (int i = 0; i < 15; i++)
    {
        for (int z = 0; z < 4; z++)
        cardsArr.push_back(i);
    }
    
    for (int i = 0; i < 60; i++)
    {
        std::swap(cardsArr[i], cardsArr[0+rand()%(59-0+1)]);
    }

}


bool checkOnePair(int playerNumber)
{
    bool check = 0;

    for (int i = 1; i < 5; i++)
        if (*(player[playerNumber].begin()+i-1) == *(player[playerNumber].begin()+i)) // в отсортированном массиве одинаковые будут рядом
            check = 1;
    return check;
}

bool checkTwoPairs(int playerNumber)
{
    int check = 0;

    for (int i = 1; i < 5; i++)
        if (*(player[playerNumber].begin() + i - 1) == *(player[playerNumber].begin() + i)) // в отсортированном массиве одинаковые будут рядом
            check++;

    if (check == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool checkStreet(int playerNumber)
{
    if ((*(player[playerNumber].begin() + 1) - *(player[playerNumber].begin())) == 1 &&          //0-1
        (*(player[playerNumber].begin() + 2) - *(player[playerNumber].begin() + 1)) == 1 &&      //1-2
       (*(player[playerNumber].begin() + 3) - *(player[playerNumber].begin() + 2)) == 1 &&      //2-3
        (*(player[playerNumber].begin() + 4) - *(player[playerNumber].begin() + 3)) == 1)         //3-4
        return 1;
    else
        return 0;
}

bool checkFourCards(int playerNumber)
{
    int check = 0;
    for (int i = 3; i < 5; i++)
        if (*((player[playerNumber].begin() + i - 1)) == *((player[playerNumber].begin() + i)) && 
            *((player[playerNumber].begin() + i - 2)) == *((player[playerNumber].begin() + i)) &&
            *((player[playerNumber].begin() + i - 3)) == *((player[playerNumber].begin() + i))) // в отсортированном массиве одинаковые будут рядом
            check++;
    if (check)
        return 1;
    else
        return 0;
}

bool checkThreeCards(int playerNumber)
{
    int check = 0;
    for (int i = 2; i < 5; i++)
        if (*(player[playerNumber].begin() + i - 1) == *(player[playerNumber].begin() + i) &&
            *(player[playerNumber].begin() + i - 2) == *(player[playerNumber].begin() + i)) // в отсортированном массиве одинаковые будут рядом
            check++;
    if (check)
        return 1;
    else
        return 0;
}


int checkResult(int playerNumber) //возвращает define 
{
    //for (int i = 0; i < 5; i++)//5 случаев (пара, две пары и т.д.)
    //{
        if (checkTwoPairs(playerNumber) == 1)
            return TWO_PAIRS;
        if (checkOnePair(playerNumber) == 1)
            return ONE_PAIR;
        if (checkStreet(playerNumber) == 1)
            return FIVE_CARDS;
        if (checkFourCards(playerNumber) == 1)
            return FOUR_CARDS;
        if (checkThreeCards(playerNumber) == 1)
            return THREE_CARDS;

       
    /*}*/
    return 0;
}

int isThereAnyWinner()
{
    //должно быть 3 случая
    //1. недостаточно карт для для сравнения        return -1
    //2. кто-то выиграл                             return [какой именно выиграл]
    //3. никто не выиграл                           return -2
    for (int i = 0; i < 5; i++)
    {
         printf("size%d\n", player[i].size());
        if (player[i].size() < 5)
        {
           
            return -1;
        }
    }


    for (int i = 0; i < 5; i++)
    {
        results[i] = checkResult(i);            //ошибка тут
    }

    int max = 0;
    int max_i = -5;
    for (int i = 0; i < 5; i++)
    {
        if (results[i] > max)
        {
            max_i = i;
            max = results[i];
        }
    }
    

    if (max == 0 || max_i == (-5))
    {
        return -2;
    }
    else
    {
        return max_i;
    }

}

void rollBackPlayers()
{
    for (int i = 0; i < 5; i++)
    {
        player[i].erase(player[i].begin(), player[i].end());
        //int size = player[i].size();
        //for (int j = 0; j < size; j++)
        //{
        //    player[i].pop_back();
        //    /*(*begin).pop_back();*/ //не работае
        //}
    }

   /* int size2 = cardsArr.size();*/
    /* for (int j = 0; j < size2; j++)
     {
         cardsArr.pop_back();*/
    cardsArr.erase(cardsArr.begin(), cardsArr.end());
    /*}*/

    fillCardsArray();
    printf("\nrolled back\n");
}

void printCards()
{

    for (int i = 0; i < 5; i++)
    {
        auto end = player[i].end();
        printf("player[%d]: ", i);
        for (auto begin = player[i].begin(); begin < end; begin++)
        {
            printf("%d ",*begin);
        }
        printf("\n");
    }
}

HANDLE ghMutex;

DWORD WINAPI dealCard(LPVOID lpParam);                                      //начальная функция при создании
DWORD WINAPI dealCard2(LPVOID lpParam);

using namespace std;
// Sample custom data structure for threads to use.
// This is passed by void pointer so it can be any data type
// that can be passed using a single void pointer (LPVOID).
typedef struct MyData
{
    char buf;
} MYDATA, * PMYDATA;


int _tmain()
{
    srand(time(NULL));
    fillCardsArray();                                                           //ЗАПОЛНЯЕМ МАССИВ КАРТ
    if (!InitializeCriticalSectionAndSpinCount(&CriticalSection,
        0x00000400))
        return 0;
    PMYDATA pDataArray[MAX_THREADS];
    DWORD   dwThreadIdArray[MAX_THREADS];
    HANDLE  hThreadArray[MAX_THREADS];

    ghMutex = CreateMutex(
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex

    if (ghMutex == NULL)
    {
        printf("CreateMutex error: %d\n", GetLastError());
        return 1;
    }
    // Create MAX_THREADS worker threads.

    for (int i = 0; i < MAX_THREADS+1; i++)
    {
        if (i == MAX_THREADS) // после окончания цикла мы схитрим и будем пользоваться локальными данными, которые были выделены в цикле создания
        {
           /* Sleep(5000);*/
           int numberOfPlayers = 0;                                 //счетчик
           for (int z = 0; z < 250; z++)                          //цикл, по истечении времени которго заканчивается игра
           {
                if (numberOfPlayers == 5)
                    numberOfPlayers = 0;  
                   
                
                if (z % 25 == 0 && z >= 25)
                {
                    
                    int temp = isThereAnyWinner();
                    if (temp == -1)                        //проверить все массивы и 
                    {

                    }
                    else if (temp == -2)
                    {
                        printCards();
                        rollBackPlayers();//rollback для всех
                        printCards();
                        numberOfPlayers = 0;
                        printf("\n still no winner, no luck in this \t\tround #%d\n", z/25);
                    }
                    else
                    {
                        printf("\nplayer[%d] has won in \t\tround#%d\n", temp,z/25);
                        printCards();
                        WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

                        // Close all thread handles and free memory allocations.

                        for (int i = 0; i < MAX_THREADS; i++)
                        {
                            CloseHandle(hThreadArray[i]);
                            if (pDataArray[i] != NULL)
                            {
                                HeapFree(GetProcessHeap(), 0, pDataArray[i]);
                                pDataArray[i] = NULL;    // Ensure address is not reused.
                            }
                        }
                        CloseHandle(ghMutex);
                        DeleteCriticalSection(&CriticalSection);
                        return 0;

                    }
                }
            dealCard(pDataArray[numberOfPlayers]);          //функция для раздачи карт
            std::sort(player[numberOfPlayers].begin(), player[numberOfPlayers].end());
           
                

                numberOfPlayers++;
           }
            printf("\nwhat a pitty, no winner after 10 matches =(\n");
        }
        // Allocate memory for thread data.

        pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
            sizeof(MYDATA));

        if (pDataArray[i] == NULL)
        {
            // If the array allocation fails, the system is out of memory
            // so there is no point in trying to print an error message.
            // Just terminate execution.
            ExitProcess(2);
        }

        // Generate unique data for each thread to work with.



        // Create the thread to begin execution on its own.

        hThreadArray[i] = CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size  
            dealCard2,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier 



        
        // Check the return value for success.
        // If CreateThread fails, terminate execution. 
        // This will automatically clean up threads and memory. 

        if (hThreadArray[i] == NULL)
        {
            /*ErrorHandler(TEXT("CreateThread"));*/
            ExitProcess(3);
        }
    } // End of main thread creation loop.

    // Wait until all threads have terminated.

    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

    // Close all thread handles and free memory allocations.

    for (int i = 0; i < MAX_THREADS; i++)
    {
        CloseHandle(hThreadArray[i]);
        if (pDataArray[i] != NULL)
        {
            HeapFree(GetProcessHeap(), 0, pDataArray[i]);
            pDataArray[i] = NULL;    // Ensure address is not reused.
        }
    }
    CloseHandle(ghMutex);
    DeleteCriticalSection(&CriticalSection);

   
    return 0;
}


DWORD WINAPI dealCard(LPVOID lpParam)
{

   
    HANDLE hStdout;
    PMYDATA pDataArray;

    TCHAR msgBuf[BUF_SIZE];
    size_t cchStringSize;
    DWORD dwChars;

    // Make sure there is a console to receive output results. 

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE)
        return 1;

    // Cast the parameter to the correct data type.
    // The pointer is known to be valid because 
    // it was checked for NULL before the thread was created.

    pDataArray = (PMYDATA)lpParam;

    // Print the parameter values using thread-safe functions.
    EnterCriticalSection(&CriticalSection);
    WaitForSingleObject(
        ghMutex,    // handle to mutex
        INFINITE);  // no time-out interval
    if (counter == 5)
    {
        counter = 0;
    }
    //code here
    card = cardsArr[cardsArr.size()-1];                                                 //ИГРОК БЕРЕТ 1 КАРТУ И ВЫВОДИТ
    cardsArr.pop_back();
    player[counter].push_back(card);
    printf("player[%d] took %d card\n", counter, card);
    //std::cout << "player[" << counter << "]" << "took " << card;
    counter++;

    ReleaseMutex(ghMutex);
    LeaveCriticalSection(&CriticalSection);

    //StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Parameters = %d, min = %i\n"),  //output in  thread
    //    1, 1);
   /* StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);

    WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);*/



    return 0;
}




DWORD WINAPI dealCard2(LPVOID lpParam)
{


    HANDLE hStdout;
    PMYDATA pDataArray;

    TCHAR msgBuf[BUF_SIZE];
    size_t cchStringSize;
    DWORD dwChars;

    // Make sure there is a console to receive output results. 

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE)
        return 1;

    // Cast the parameter to the correct data type.
    // The pointer is known to be valid because 
    // it was checked for NULL before the thread was created.

    pDataArray = (PMYDATA)lpParam;

    // Print the parameter values using thread-safe functions.
    EnterCriticalSection(&CriticalSection);
  WaitForSingleObject(
      ghMutex,    // handle to mutex
      INFINITE);  // no time-out interval
    ////code here
    //card = cardsArr[cardsArr.size() - 1];                                                 //ИГРОК БЕРЕТ 1 КАРТУ И ВЫВОДИТ
    //cardsArr.pop_back();
    //player[counter].push_back(card);
    //printf("\nplayer[%d] took %d card", counter, card);
    ////std::cout << "player[" << counter << "]" << "took " << card;
    //counter++;

    ReleaseMutex(ghMutex);
    LeaveCriticalSection(&CriticalSection);

    //StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Parameters = %d, min = %i\n"),  //output in  thread
    //    1, 1);
    StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);

    WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);



    return 0;
}

