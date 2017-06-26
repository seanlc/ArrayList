#include <iostream>
#include <algorithm>
using namespace std;

class IndexOutOfBoundsException{};

template 
 < typename T>
class ArrayList 
{
private:
    int maxSize;
    int curSize;
    T * buf;
public:
    ArrayList()
    : maxSize (10), buf (new T [maxSize])
    {}
    ArrayList(int cap)
    : maxSize (cap), buf (new T[maxSize])
    {}
    ArrayList(const ArrayList & oth)
    : maxSize (oth.maxSize), buf (new T[maxSize])
    {
	for(int i = 0; i < oth.curSize; ++i)
	    buf[i] = oth.buf[i];
    }
    ~ArrayList()
    {
        delete [] buf;
        buf = nullptr;
    }     
    T & operator [] ( int i )
	throw( IndexOutOfBoundsException )
    {
	if( i < 0 || i >= curSize )
	    throw IndexOutOfBoundsException{};
	return buf[i];
    }
    void print ( ostream & out )
    {
	for(int i = 0; i < curSize; ++i)
	    out << buf[i] << " ";
    }
    friend ostream & operator << (ostream & out, ArrayList & a)
    {
	a.print( out );
	return out; 
    }
    friend ostream & operator << (ostream & out, ArrayList * ap)
    {
	ap->print( out );
	return out;
    }
    void resize(int n)
    {
	T * newBuf = new T[n];
        int lowerIndex = min(n, maxSize);
        for(int i = 0; i < lowerIndex; ++i)
	    newBuf[i] = buf[i];
	delete [] buf;
	buf = newBuf;
        maxSize = n;
    }
    int get_curSize()
    {
	return curSize;
    }
    int get_maxSize()
    {
	return maxSize;
    }
    void push_back(const T & val)
    {
	if (curSize == maxSize)
	    resize(maxSize * 2);
	buf[curSize++] = val;	
    }
    void pop_back()
    {
	--curSize;
    }
};
