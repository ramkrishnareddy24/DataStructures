/*
#include <iostream>
using namespace std;
int main()
{
   int x = -1;
   try {
      cout << "Inside try n\n";
      if (x < 0)
      {
         throw x;
         cout << "After throw n\n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught n\n";
   }
 
   cout << "After catch n";
   return 0;
}

#include <iostream>
using namespace std;
 
int main()
{
    try
    {
       throw 'a';
    }
    catch (int param)
    {
        cout << "int exceptionn";
    }
    catch (...)
    {
        cout << "default exceptionn";
    }
    cout << "After Exception";
    return 0;
}


#include <iostream>
using namespace std;
 
int main()
{
    try
    {
       throw 10;
    }
    
    catch (int param)
    {
        cout << "int exceptionn";
    }
    catch (...)
    {
        cout << "default exceptionn";
    }
 
    return 0;
}

#include <iostream>
using namespace std;
 
int main()
{
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            cout << "Inner Catchn";
            throw;
        }
    }
    catch (int x)
    {
        cout << "Outer Catchn";
    }
    return 0;
}


#include <iostream>
using namespace std;
 
class Test {
public:
   Test() { cout << "Constructing an object of Test " << endl; }
  ~Test() { cout << "Destructing an object of Test "  << endl; }
};
 
int main() {
  try {
    Test t1;
    throw 10;
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}

*/

#include <iostream>
using namespace std;
 
class Test {
  static int count;
  int id;
public:
  Test() {
    count++;
    id = count;
    cout << "Constructing object number " << id << endl;
    if(id == 4)
       throw 4;
  }
  ~Test() { cout << "Destructing object number " << id << endl; }
};
 
int Test::count = 0;
 
int main() {
  try {
    Test array[5];
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}