In Ubuntu 18,

use this: g++ main.cpp  -lpthread -lgtest, and ./to test my code.
Or in the "build" folder, run ./nmp to test my code.

Question 1:
Simply install CMake and GTest

Question 2:
(x, y) is wrong, it only output y.
changed it to std::cout << " "<< x << ',' << y << std::endl;
then it can output both x and y.

Question 3:
change it from char to const char*
ptr1 = (ptr + sizeof(int))[-2];
sizeof(int) = 4. 
4-2 = 2; which is the third one "cat".

Question 4:
for iterator, it should be valmap::iterator it = m.begin()

Question 5:
i != 3 means not equal

Question 6:
remove_pointer
use this website for reference.
https://en.cppreference.com/w/cpp/types/remove_pointer
line 102 printf only for solve the warnning. 

Question 7:
use mutex to solve the multithreading problem. Lock and unlock.
GTest is implemented inside the testerfunction()
which is ASSERT_EQ(walletObject.getMoney(), 5000);
change 5000 to 5001 will see the error.

Question 8:
pointer name problem
line 153 for solving the warnning.

Question 9:
struct person

Question 10:
Move class Foo{} infront of the main()

Question 11:
read and print the user input, stop when ctrl+D.

my output is

    10,15
    cat
    1 1
    2 1.41421
    3 1.73205
    4 2
    5 2.23607
    inside if statement
    0x7ffd4045a8b90x7ffd4045a8f0 : 0x7ffd4045a8bc : 1

    asd
    asd
    asdd
    asdd

