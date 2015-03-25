// dobrininam.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout<<"�������� ��������:"<<endl
		<<(" 1. ����� ������� ������.")<<endl
		<<(" 2. ������� ������.")<<endl
		<<(" 3. �������� ������ �� �������.")<<endl
		<<(" 4. ������ � ������ � �������� ������.")<<endl
		<<(" 5. ��������� ������ � �������� ������.")<<endl
		<<(" 6. �������� ������ � �������� ������.")<<endl
		<<(" 7. ����� ������ � �������� ������.")<<endl
		<<(" 8. ����� ��������� ������ �� �����.")<<endl
		<<(" 9. ����� ����� ������ �� ����� t->L->R.")<<endl
		<<("k. ����� k��� �� ������� ����� � ������ .")<<endl
		<<("I. ��������.")<<endl
		<<("T. ������������.")<<endl
		<<("X. �����.")<<endl;
	    cin>>ch;
		switch(ch)
		{
		case '1':
		//	system("cls");
			D1.Uzl_Setup();
			cout<<("������ ������: ")<<D1.size()<<endl;
			_getch();break;
		case '2':
		//	system("cls");
			D1.Uzl_Setup();
			D1.clear();
			cout<<("������.");
			_getch();break;
		case '3':
	//		system("cls");
			D1.Uzl_Setup();
			if(D1.empty()) {cout<<("������ ������.");}
			else {cout<<("������ �� ������.");}
			_getch();break;
		case '4':
			try
			{
	//			system("cls");
				D1.Uzl_Setup();
				cout<<("������� ����: "); cin>>dkey; data=D1[dkey];
				cout<<("������ �� �����:"); 
				cout<<data<<endl;
				cout<<("������� ����� ������: ");
				cin>>data;
				D1[dkey]=data;
			}
			catch(char *s) {cout<<(s);}
			_getch();break;
		case '5':
	//		system("cls");
			cout<<("������� ����: ");cin>>dkey;
			cout<<("������� ������: ");cin>>data;
			D1.Uzl_Setup();
			bl=D1.add(dkey,data);
			if(!bl) {cout<<("����� ���� ��� ���� � ������.");}
			_getch();break;
		case '6':
		//	system("cls");
			cout<<("������� ����: ");
			cin>>dkey;
			D1.Uzl_Setup();
			bl=D1.del(dkey);
			if(!bl) {cout<<("������ ����� ��� � ������.");}
			_getch();break;
		case '7':
			try
			{
	//			system("cls");
				D1.Uzl_Setup();
				cout<<("������� ����: ");
				cin>>dkey;
				data=D1[dkey];
				cout<<("������ �� �����:");
				cout<<data<<endl;
			}
			catch(char *s) {cout<<(s);}
			_getch();break;
		case '8':
	//		system("cls");
			D1.Uzl_Setup();
			bl=D1.view();
			if(!bl) {cout<<("������ ������.");}
			_getch();break;
		case '9':
	//		system("cls");
			cout<<D1.obxod()<<endl;
			_getch();break;
		case 'k' /*'10'*/: // !!! ������, ������ '10' - '' ��������� ������� ������������� ���� ������ !!!
				   // ����� ����������� case '1'
			{
				D1.Uzl_Setup();
				cout<<("������ ������: ")<<D1.size()<<endl;
				cout<<("������� ���������� ����� ������: ");
				cin>>dkey;
				/*D1.selectk(0,dkey);*/

		//if( (this->size() < key) || (key <= 0) ){ // ���� ������� ���� ����� ������� 
		//										  // ������ ��� ������ ���� ����� ���� - ������ ���������� 
		//	cout << "������������ ���� �����" << endl;
		//	return NULL;
		//}
				try{D1.printNode(D1.selectk(D1.getRoot(),dkey));} catch (int) {cout<< "���������� ����� ��� � ������" <<endl;}
				break;
			}
		case 'I':
	//		system("cls");
			exitI=1;
			while(exitI!=0)
			{		
	//			system("cls");
				cout<<("���� ���������:")<<endl
				<<("1. ���������� �� ���� � ����������� ������.")<<endl
				<<("2. ���������� �� ���� � ������������ ������")<<endl
				<<("3. ��������� ��������� ���������.")<<endl
				<<("4. �������� ������� ��������.")<<endl
				<<("5. �������� ������� ��������.")<<endl
				<<("6. ������� � ���������� �� �������� ����� ����.")<<endl
                <<("7. ������� � ������������ �� �������� ����� ����.")<<endl
				<<("X. �����.\n")<<endl
				<<("������� ����� ����: ");cin>>chI;
				switch(chI)
				{
				case '1':
	//				system("cls");
					D1.Uzl_Setup();
                    //��������� �� ���� � ����������� ������
                    if(!It.beg()) cout<<("�������� ������.");
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
                    //��������� �� ���� � ������������ ������
                    if(!It.end()) cout<<("�������� ������.");
					try
                    {
                    //cout<<*It<<endl;
					//cout<<"(key="<<It.key()<<")"<<endl;
                    }
					catch(char *s) {cout<<(s);}
					_getch();break;
				case '3':
					system("cls");
                    //�������� ���������
					D1.Uzl_Setup();
                    bl=It.is_off();
                    if(bl) cout<<("�� ����������.");
                    if(!bl) cout<<("����������.");
					_getch();break;
				case '4':
					system("cls");
					D1.Uzl_Setup();
                    //�������� ������� ��������
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
                    //�������� ������� ��������
                    cout<<("������� ����� ������");
                    cin>>data;
                    try
                    {
                    *It=data;
                    cout<<("������ ��������:");
                    cout<<*It<<endl;
                    }
                    catch(char *s) {cout<<(s);}
					_getch();break;
				case '6':
					system("cls");
					D1.Uzl_Setup();
                    //������� � ���������� �� �������� ����� ����
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
                    //������� � ������������ �� �������� ����� ����
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
			cout<<("������� ����� ���������: ");cin>>j;
			if(j<=0) break;
			srand( (unsigned)time( NULL ) );
			cout<<("���������� ������ ���������� �������: /n");			
			for(i=0;i<j;i++) 
            {
				r=rand()*rand()%j;
				D1.add(r,rand());
			}
		//	cout<<("������.");
		//	cout<<("������� ������������.");
            cout<<("������� ������:");
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
			cout<<("�����...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(5)/(double)kop<<endl;
            cout<<("\t�������:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(6)<<endl;
            cout<<("�������...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(1)/(double)kop<<endl;
            cout<<("\t�������:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(2)<<endl;
            cout<<("��������...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(3)/(double)kop<<endl;
            cout<<("\t�������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(4)<<endl;
//---------------------------------------------------      
            D1.clear();
            for(i=0;i<j;i++) 
            {	
				M[i]=100*i;
				D1.add(i*100,rand());
			}
			cout<<("\n\n\t������ ������.");
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
			cout<<("�����...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(5)/(double)kop<<endl;
            cout<<("\t�������:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(6)<<endl;
            cout<<("�������...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(1)/(double)kop<<endl;
            cout<<("\t�������:");
            cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(2)<<endl;
            cout<<("��������...");
            cout<<("\t������������:");
			cout.precision( 6 );
            cout<<"\tBST "<<D1.cntshow(3)/(double)kop<<endl;
            cout<<("\t�������:");
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

