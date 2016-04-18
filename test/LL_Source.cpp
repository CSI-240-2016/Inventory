#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
   LinkedList<int> *list;
   int             i;

   list = new LinkedList<int>;

   cout << "Making sure the constructor is working:\n";
   cout << list->getCount() << ", and I am expecting 0\n";
   cout << list->isEmpty() << ", and I am expecting to the true\n";

   for (i = 0; i < 5; i++)
   {
      list->insert(i);
      list->display();
      cout << "\n*************\n\n";
   }

   cout << (list->doesExist(2) ? "True" : "False") << ", expecting true\n"; 
   cout << (list->doesExist(15) ? "True" : "False") << ", expecting false\n";


   cout << "\n\nAppending 15\n";
   list->append(15);
   list->display();

   delete list;

   system("pause");

   return 0;
}