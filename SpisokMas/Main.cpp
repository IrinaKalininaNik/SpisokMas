#include "SpisokMas.h"
#include <iostream>

int main()
{
   Spisok<int> K(7);
   K.addStart(7);
   K.addStart(3);
   K.addEnd(3);
   K.addEnd(5);
   K.addEnd(4);
   K.addEnd(1);
   K.addStart(8);
   K.delEnd();

   for(int i=K.getStart();!K.isEnd(i);i=K.getNext(i))
   {std:: cout<<K.getDano(i);}
   std:: cin.get();
};