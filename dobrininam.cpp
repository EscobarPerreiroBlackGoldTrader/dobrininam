// dobrininam.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stack>
#include <time.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
#include "BST.h"
//#include "source.h"
//BST<int>::Node *BST<int>::Null;
//******************************************************************************************//




int _tmain(int argc, _TCHAR* argv[])
{
	BST<int> D1;
	BST<int>::Iterator It(&D1);
	
	int dkey,i,j,r,number,kop;
	unsigned long M[100000];
	int data;
	bool bl;
	char exit=1,ch;
	char exitI=1,chI;
	while(exit!=0)
	{
	//	system("cls");
	setlocale(LC_ALL, "Russian");
	cout<<"Выберите операцию:"<<endl
		<<(" 1. Опрос размера дерева.")<<endl
		<<(" 2. Очистка дерева.")<<endl
		<<(" 3. Проверка дерева на пустоту.")<<endl
		<<(" 4. Доступ к данным с заданным ключом.")<<endl
		<<(" 5. Включение данных с заданным ключом.")<<endl
		<<(" 6. Удаление данных с заданным ключом.")<<endl
		<<(" 7. Вывод данных с заданным ключом.")<<endl
		<<(" 8. Вывод структуры дерева на экран.")<<endl
		<<(" 9. Обход узлов дерева по схеме t->L->R.")<<endl
		<<("k. Поиск k–го по порядку ключа в дереве .")<<endl
		<<("I. Итератор.")<<endl
		<<("T. Тестирование.")<<endl
		<<("X. Выход.")<<endl;
	    cin>>ch;
		switch(ch)
		{
		case '1':
		//	system("cls");
			D1.Uzl_Setup();
			cout<<("Размер дерева: ")<<D1.size()<<endl;
			_getch();break;
		case '2':
		//	system("cls");
			D1.Uzl_Setup();
			D1.clear();
			cout<<("Готово.");
			_getch();break;
		case '3':
	//		system("cls");
			D1.Uzl_Setup();
			if(D1.empty()) {cout<<("Дерево пустое.");}
			else {cout<<("Дерево не пустое.");}
			_getch();break;
		case '4':
			try
			{
	//			system("cls");
				D1.Uzl_Setup();
				cout<<("Введите ключ: "); cin>>dkey; data=D1[dkey];
				cout<<("Данные по ключу:"); 
				cout<<data<<endl;
				cout<<("Введите новые данные: ");
				cin>>data;
				D1[dkey]=data;
			}
			catch(char *s) {cout<<(s);}
			_getch();break;
		case '5':
	//		system("cls");
			cout<<("Введите ключ: ");cin>>dkey;
			cout<<("Введите данные: ");cin>>data;
			D1.Uzl_Setup();
			bl=D1.add(dkey,data);
			if(!bl) {cout<<("Такой ключ уже есть в дереве.");}
			_getch();break;
		case '6':
		//	system("cls");
			cout<<("Введите ключ: ");
			cin>>dkey;
			D1.Uzl_Setup();
			bl=D1.del(dkey);
			if(!bl) {cout<<("Такого ключа нет в дереве.");}
			_getch();break;
		case '7':
			try
			{
	//			system("cls");
				D1.Uzl_Setup();
				cout<<("Введите ключ: ");
				cin>>dkey;
				data=D1[dkey];
				cout<<("Данные по ключу:");
				cout<<data<<endl;
			}
			catch(char *s) {cout<<(s);}
			_getch();break;
		case '8':
	//		system("cls");
			D1.Uzl_Setup();
			bl=D1.view();
			if(!bl) {cout<<("Дерево пустое.");}
			_getch();break;
		case '9':
	//		system("cls");
			cout<<D1.obxod()<<endl;
			_getch();break;
		case 'k' /*'10'*/: // !!! ошибка, нельзя '10' - '' одинарные кавычки подразумевают один символ !!!
				   // будет срабатывать case '1'
			{
				D1.Uzl_Setup();
				cout<<("Размер дерева: ")<<D1.size()<<endl;
				cout<<("Введите порядковый номер обхода: ");
				cin>>dkey;
				/*D1.selectk(0,dkey);*/

		//if( (this->size() < key) || (key <= 0) ){ // если искомый ключ менше размера 
		//										  // дерева или меньше либо равен нулю - искать невозможно 
		//	cout << "неправильный ввод ключа" << endl;
		//	return NULL;
		//}
				try{D1.printNode(D1.selectk(D1.getRoot(),dkey));} catch (int) {cout<< "Указанного ключа нет в дереве" <<endl;}
				break;
			}
		case 'I':
	//		system("cls");
			exitI=1;
			while(exitI!=0)
			{		
	//			system("cls");
				cout<<("Меню Итератора:")<<endl
				<<("1. Установить на узел с минимальным ключом.")<<endl
				<<("2. Установить на узел с максимальным ключом")<<endl
				<<("3. Проверить состояние итератора.")<<endl
				<<("4. Прочесть текущее значение.")<<endl
				<<("5. Изменить текущее значение.")<<endl
				<<("6. Переход к следующему по значению ключа узлу.")<<endl
                <<("7. Переход к предыдующему по значению ключа узлу.")<<endl
				<<("X. Выход.\n")<<endl
				<<("Введите пункт меню: ");cin>>chI;
				switch(chI)
				{
				case '1':
	//				system("cls");
					D1.Uzl_Setup();
                    //установка на узел с минимальным ключом
                    if(!It.beg()) cout<<("Возникла ошибка.");
					try
                    {
                    //cout<<*It<<endl;
					//cout<<"(key="<<It.key()<<")"<<endl;
                    }
					catch(char *s) {cout<<(s);}
					_getch();break;
				case '2':
					system("cls");
					D1.Uzl_Setup();
                    //установка на узел с максимальным ключом
                    if(!It.end()) cout<<("Возникла ошибка.");
					try
                    {
                    //cout<<*It<<endl;
					//cout<<"(key="<<It.key()<<")"<<endl;
                    }
					catch(char *s) {cout<<(s);}
					_getch();break;
				case '3':
					system("cls");
                    //проверка состояния
					D1.Uzl_Setup();
                    bl=It.is_off();
                    if(bl) cout<<("Не установлен.");
                    if(!bl) cout<<("Установлен.");
					_getch();break;
				case '4':
					system("cls");
					D1.Uzl_Setup();
                    //Прочесть текущее значение
                    try
                    {
                    cout<<*It<<endl;
					cout<<"(key="<<It.key()<<")"<<endl;
                    }
                    catch(char *s)
                    {
                        cout<<(s);
                    }
					_getch();break;
				case '5':
					system("cls");
					D1.Uzl_Setup();
                    //Изменить текущее значение
                    cout<<("Введите новые данные");
                    cin>>data;
                    try
                    {
                    *It=data;
                    cout<<("Данные изменены:");
                    cout<<*It<<endl;
                    }
                    catch(char *s) {cout<<(s);}
					_getch();break;
				case '6':
					system("cls");
					D1.Uzl_Setup();
                    //переход к следующему по значению ключа узлу
                    It++;
					try
                    {
                    cout<<*It<<endl;
					cout<<"(key="<<It.key()<<")"<<endl;
                    }
					catch(char *s) {cout<<(s);}
					_getch();break;
                case '7':
					system("cls");
					D1.Uzl_Setup();
                    //переход к предыдующему по значению ключа узлу
                    It--;
					try
                    {
                    cout<<*It<<endl;
					cout<<"(key="<<It.key()<<")"<<endl;
                    }
                    catch(char *s) {cout<<(s);}
					_getch();break;
				case 'X':
					exitI=0;
					break;
				default:break;
				}
			}
			break;
		case 'T':
			system("cls");
			srand( (unsigned)time( NULL ) );
			D1.clear();
			cout<<("Введите число элементов: ");cin>>j;
			if(j<=0) break;
			srand( (unsigned)time( NULL ) );
			cout<<("Заполнение списка случайными числами: /n");			
			for(i=0;i<j;i++) 
            {
				r=rand()*rand()%j;
				D1.add(r,rand());
			}
		//	cout<<("Готово.");
		//	cout<<("Начинаю тестирование.");
            cout<<("Средний случай:");
			D1.sbros();            
			kop=0;
			for(i=0;i<j/2;i++)
			{                
				kop++;
                D1.Uzl_Setup();
				r=rand()*rand()%(j+(long)j/10);
				D1.find(r);
                D1.Uzl_Setup();
				r=rand()*rand()%(j+(long)j/10);
                D1.add(r,rand());
                D1.Uzl_Setup();
				r=rand()*rand()%(j+(long)j/10);
				D1.del(r);
			}
			cout<<("Поиск...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(5)/(double)kop<<endl;
            cout<<("\tПромахи:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(6)<<endl;
            cout<<("Вставка...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(1)/(double)kop<<endl;
            cout<<("\tПромахи:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(2)<<endl;
            cout<<("Удаление...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(3)/(double)kop<<endl;
            cout<<("\tПромахи:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(4)<<endl;
//---------------------------------------------------      
            D1.clear();
            for(i=0;i<j;i++) 
            {	
				M[i]=100*i;
				D1.add(i*100,rand());
			}
			cout<<("\n\n\tХудший случай.");
			D1.sbros();            
			kop=0;
			for(i=0;i<j/2;i++)
			{
				kop++;				
				if(i%10==0)
				{
                //Add--------------------------------------------
                D1.Uzl_Setup();
				number=M[rand()%j];
                D1.add(number,rand());                    
                //Delete--------------------------------------------
                D1.Uzl_Setup();
				number=(rand()+rand())%(100*j);
				number=number+!(number%2);				
				D1.del(number);                    
				//Search--------------------------------------------
				D1.Uzl_Setup();				
				D1.find(number);
                }
				else
				{
				//Delete--------------------------------------------
                D1.Uzl_Setup();
				number=M[rand()%j];				
				D1.del(number);                    
				//Add--------------------------------------------
                D1.Uzl_Setup();										
                D1.add(number,rand());                    
				//Search--------------------------------------------
				D1.Uzl_Setup();	
				number=M[rand()%j];	
				D1.find(number);
				}

			}
			cout<<("Поиск...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(5)/(double)kop<<endl;
            cout<<("\tПромахи:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(6)<<endl;
            cout<<("Вставка...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(1)/(double)kop<<endl;
            cout<<("\tПромахи:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(2)<<endl;
            cout<<("Удаление...");
            cout<<("\tТрудоемкость:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(3)/(double)kop<<endl;
            cout<<("\tПромахи:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(4)<<endl;
			_getch();break;
		case 'X':
			exit=0;
			break;		
		default:break;
		}
	}




	return 0;
}

