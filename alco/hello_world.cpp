#include <iostream>
#include <vector>
#include <string>

using namespace std;

void show(int k)
{
    std::cout<<k<<std::endl;
}

void show(double s)
{
    std::cout<<s<<std::endl;
}

void increase(int &al)
{
    al++;
}

int main()
{
    int a[5]={1,2,3,4,5};
    double b[5]={2.1,3.1,4.1,5.1,1};
    int x=0,y=0;
    for(int i=0;i<5;i++)
    {
        show(a[i]);
        show(b[i]);
        increase(x);
        increase(y);
        show(x);
        show(y);
    }
    return 0;
}