// Siyuan Li z5190747
// Please read readme.txt
// Question 1 Install g tests and add to cmakes lists
#include "gtest/gtest.h"

#include <thread>
#include <math.h>
#include <map>
#include <mutex>

const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof values / sizeof (int);
void function(const char** ptr);
void fn(const int** pp);
template <typename T1, typename T2>

struct ptr_holder {
    static_assert(std::is_same<T1, T2>(), "error");
};

int total = 0;

class Wallet
{
    int mMoney;
    std::mutex _mutex;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
           _mutex.lock();
          mMoney++;
          _mutex.unlock();
       }
    }
};

// Fix any compilation error
class Foo {
public:
    Foo() {}
    Foo(int , Wallet* ) {}
};

struct person {
   int age;
   float weight;
} person;

void testerFunction()
{
   Wallet walletObject;
   std::vector<std::thread> threads;
   for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
   }
   for(unsigned int i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   ASSERT_EQ(walletObject.getMoney(), 5000);
}


int main()
{
    // Question 2
    int x = 10;
    int y = 15;
    std::cout << " "<< x << ',' << y << std::endl;
    
    // Question 3 Get the function to run
    const char* arr[] = { "ant", "bat", "cat", "dog", "egg", "fly" };
	function(arr);


    // Question 4 Insert in map
    typedef std::map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++)
        m.insert(std::make_pair(values[i], pow(values[i], .5)));

    valmap::iterator it = m.begin();              
    valmap::iterator it2 = m.end();              
    while(it != it2) {
        std::cout << it->first << ' ' << it->second << std::endl;
        ++it;
    }
    
    // Question 5
    int i = 1, j = 1;
    if ( (i != 3) && (j==1))
    {
        std::cout << "inside if statement\n";
    }

    // Question 6 Store a char * pointer in template
    ptr_holder<void*, std::remove_pointer<void**>::type> p;
    printf("%p", (void*)(&p));

    // Question 7 Fix the compiler errors and race conditions
    // Convert the testerFunction() into a google test
    //int val = 0;
    for(int k = 0; k < 1000; k++)
    {
        testerFunction();
        /*
        if((val = testerFunction()) != 50000)
        {
            std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
            return 1;
        }
        */
    }

    // Question 8
    int n = 1;
    const int *p2 = &n;
    fn(&p2);

    // Question 9
    struct person *ptr;
    ptr = (struct person*)malloc(sizeof(struct person));
    ptr->age = 10;
    ptr->weight = 55.5;

    // Question 10 Initialise foo
    Foo foo;

    // Question 11
    char c;
    while((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;                         

}

// Do not change anything besides the ptr variable
void function(const char** ptr)
{
	const char *ptr1;
	ptr1 = (ptr += sizeof(int))[-2];
	printf("%s\n", ptr1);
}

void fn(const int** pp)
{
    printf("%p : %p : %d", (void*)pp, (void*)(*pp), **pp);
}


