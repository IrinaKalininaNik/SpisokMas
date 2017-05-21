#ifndef SPISOK_MAS_H
#define SPISOK_MAS_H
#include <iostream>

template <class T>
class Spisok
{  
   private:
	   int* Uno; //Массив указателей
	   T* Dano; //Массив данных
	   int size; //Рамер массива
	   int count; //Количество элементов
	   int start; //Начало массива
	   int end; //Конец массива
   public:
	Spisok(int a=1);
	Spisok(Spisok&a);
	~Spisok();
	void addStart(T a);
    void addEnd(T a); 
	void delStart();
	void delEnd();
	int getStart();
	int getNext(int a);
	bool isEnd(int a);
	T getDano(int end);
};
 
template <class T>
 Spisok<T>::Spisok<T>(int a)
{ 
	size=a;
	count=0;
	start=0;
	end=0;
	Uno= new int[size];
	Dano= new T[size];
	for(int i=0; i<size; i++)
	{ 
		Uno[i]=-1;
		Dano[i]=0;
	}
}

template <class T>
Spisok<T>::Spisok<T>(Spisok<T>&a)
{
	size=a.size;
	count=a.count;
	start=a.start;
	end=a.end;

}

template <class T>
Spisok<T>::~Spisok<T>()
{
}

template <class T>
void Spisok<T>:: addStart(T a)
{
	if(count==0)
	{ 
	   Uno[0]=-2;
	   start=0;
	   end=0;
	   Dano[start]=a;

	}
	else
	{ 
		for(int i=0;i<size;i++)
		{ 
			if(Uno[i]==-1)
			{
			  Uno[i]=start;
			  start=i;
			  Dano[i]=a; 
			  break; 
			}
		}
	}count++;
}

template <class T>
void Spisok<T>:: addEnd(T a)
{
	if(count==0)
	{ 
	   Uno[0]=-2;
	   start=0;
	   end=0;
	   Dano[end]=a;
	}
	else
	{ 
		for(int i=0;i<size;i++)
		{ 
			if(Uno[i]==-1)
			{
			  Uno[end]=i;
			  end=i;
			  Dano[i]=a; 
			  Uno[i]=-2;
			  break; 
			}
		}
	}count++;
}

template <class T>
void Spisok<T>:: delStart()
{
	int S=start;
	start=Uno[start];
	Uno[S]=-1;
	count--;
}

template <class T>
void Spisok<T>:: delEnd()
{
	for(int i=0; i<size; i++)
	{
	  if(Uno[i]==end)
	  {
	    Uno[end]=-1;
		Uno[i]=-2;
		end=i;
		count--;
		return;
	  }
	}
}
template <class T>
int Spisok<T>:: getStart()
{
	return start;
}

template <class T>
int Spisok<T>:: getNext(int a)
{
    return Uno[a];
}

template <class T>
bool Spisok<T>:: isEnd(int a)
{
	if(a==-1)
	{ return true; }
	if(a==-2)
	{ return true; }
	return false;
}

template <class T>
T Spisok<T>:: getDano(int end)
{
	return Dano[end];
}

#endif 
