#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
    ArrayList<int> myList;
    int item = 0;
    for(int i = 0; i < 100; ++i)
        myList.push_back(item++);
    cout << myList << endl;
    cout << "Max size: " << myList.get_maxSize()
	 << " Cur size: " << myList.get_curSize() << endl;
    return 0;
}
