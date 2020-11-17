#include<iostream>
#include<unordered_map>
using namespace std;

int fib(int index, std::unordered_map<int, int>& lookup)
{
    if(index <= 1)
        return index;

    if(lookup.find(index) == lookup.end())
        lookup[index] = fib(index - 1, lookup) + fib(index - 2, lookup);
    
    return lookup[index];
} 

int main()
{
    unordered_map<int, int> lookup;
    cout << fib(10, lookup) << endl;
    return 0;
}
