
//enum MenuPoints { // для пунктов меню используй в седующий раз :)
//	TREE_SIZE = 1,
//	TREE_CLEAR,
//	CHECK_EMPTY,
//	DATA_ON_KEY,
//	INSERT_DATA_ON_KEY,
//	DELETE_DATA_ON_KEY,
//	SHOW_DATA_ON_KEY,
//	SHOW_TREE_STRUCTURE,
//	TRAVERS_TREE_tLR,
//	FIND_k_KEY,
//	ITERATOR,
//	TESTING,
//	EXIT};





//---------------------------------------------------
//	BST-дерево
//---------------------------------------------------
template <class T> class BST
{
public:
	unsigned long pIns,pDel,pS;
	unsigned long uIns,uDel,uS;
	unsigned long kUzl;	
public:
	class Node
		{
		public:
			T item;				//данные
			unsigned long key;	//ключ
			Node *pL;			//левое поддерево
			Node *pR;			//правое поддерево
			Node *pP;			//предок
			Node(unsigned long dkey,T data,Node *pNull)
			{
				item=data;
				key=dkey;
				pL=pR=pP=pNull;
			}			
		};    
	Node *Null;
	class Iterator
		{
			BST *ptr;
			Node *cur;
		public:
			//конструктор
			Iterator(BST *p)
			{
				ptr=p;cur=p->pH;
			}
			//установка на узел с минимальным ключом
			bool beg()
			{
				if(ptr->sz==0)  return false;
                cur=ptr->pH;ptr->kUzl++;
                while(cur->pL!=ptr->Null) {cur=cur->pL;ptr->kUzl++;}
                return true;
			}
			//установка на узел с максимальным ключом
			bool end()			
			{
                if(ptr->sz==0)  return false;
				cur=ptr->pH;ptr->kUzl++;
				while(cur->pR!=ptr->Null) {cur=cur->pR;ptr->kUzl++;}
                return true;
			}
			//проверка состояния
			bool is_off()
			{
				if(cur==ptr->Null) return true;
				return false;
			}
			//доступ по чтению и записи к данным текущего узла
			T& operator*()
			{
                if(ptr->pH==ptr->Null) throw"Дерево пустое.";
                if(cur==ptr->Null) throw"Итератор не установлен.";
				return cur->item;
			}
			//доступ по чтению к ключу текущего узла
			unsigned long key()
			{
                if(ptr->sz==0) throw"Дерево пустое.";
                if(cur==ptr->Null) throw"Итератор не установлен.";
				return cur->key;
			}
			//переход к следующему по значению ключа узлу
			bool operator++(int)
			{
				if(ptr->sz==0) return false;
                if(cur==ptr->Null) return false;
				if(cur->pR!=ptr->Null) 
				{
					cur=cur->pR;ptr->kUzl++;
					while(cur->pL!=ptr->Null) {cur=cur->pL;ptr->kUzl++;}
					return true;
				}
				else
				{
					if(cur==ptr->pH) return false;
					if(cur==cur->pP->pL) 
					{
						cur=cur->pP;ptr->kUzl++;
						return true;
					}
					if(cur==cur->pP->pR) 
					{
						while(cur==cur->pP->pR) 
						{
							cur=cur->pP;ptr->kUzl++;
							if(cur==ptr->pH) {cur=ptr->Null;return false;}
						}
						cur=cur->pP;ptr->kUzl++;
						return true;
					}
					else return false;
				}
			}
			//переход к предыдующему по значению ключа узлу
			bool operator--(int)
			{
                if(ptr->pH==ptr->Null) return false;
                if(cur==ptr->Null) return false;
				if(cur->pL!=ptr->Null) 
				{
					cur=cur->pL;ptr->kUzl++;
					while(cur->pR!=ptr->Null) {cur=cur->pR;ptr->kUzl++;}
					return true;
				}
				else
				{
					if(cur==ptr->pH) return false;
					if(cur==cur->pP->pR) 
					{
						cur=cur->pP;ptr->kUzl++;
						return true;
					}
					if(cur==cur->pP->pL) 
					{
						while(cur==cur->pP->pL) 
						{
							cur=cur->pP;ptr->kUzl++;
							if(cur==ptr->pH) {cur=ptr->Null;return false;}
						}
						cur=cur->pP;ptr->kUzl++;
						return true;
					}
					else return false;
				}
			}
			//сравнение итераторов
			bool operator==(const Iterator& It)
			{
				if(ptr==It.ptr&&cur=It.cur) return true;
				return false;
			}
			//присваивание итераторов
			Iterator operator=(const Iterator& It)
			{
				ptr=It.ptr;
				cur=It.cur;				
			}
		};
friend class Iterator;
Node *pH;
unsigned long sz;			//размер дерева	
public:
//Методы класса BST
//конструктор
	BST()
	{
        BST<T>::Null=0;sz=0;pH=Null;
	}
//деструктор
	~BST()
	{
		this->clear();
	}
//опрос размера дерева
	unsigned long size()
	{
		return sz;
	}	
//очистка дерева
	void clear()
	{
		if(this->pH==Null) return;
		stack<BST<T>::Node *> ss;
		BST<T>::Node *t=this->pH;kUzl++;
		ss.push(t);
		while(!ss.empty())
		{
			t=ss.top();ss.pop();
			if(t->pR!=Null) ss.push(t->pR);
			if(t->pL!=Null) ss.push(t->pL);
			delete t;sz--;kUzl++;
		}	
		this->pH=Null;
	}
//проверка дерева на пустоту
	bool empty()
	{
		if(sz==0) return true;
		return false;
	}
//доступ к данным с заданным ключом
	virtual T&  operator[](unsigned long key)
	{
		if(sz==0) throw "Дерево пустое.";
		BST::Node *t=pH;kUzl++;
		if(key==t->key) return t->item;
		while(key!=t->key)
		{
			if(key<t->key)
			{
				if(t->pL!=Null) {t=t->pL;kUzl++;}
				else throw "Ключ не найден.";
			}
			if(key>t->key)
			{
				if(t->pR!=Null){t=t->pR;kUzl++;}
				else throw "Ключ не найден.";
			}		
		}
		return t->item;	
	}
//поиск наличия ключа в дереве
	virtual bool find(unsigned long key)
	{
		if(sz==0) {pS++;return false;}
		BST::Node *t=pH;kUzl++;
		if(key==t->key) {uS+=kUzl;return true;}
		while(key!=t->key)
		{
			if(key<t->key)
			{
				if(t->pL!=Null) {t=t->pL;kUzl++;}
				else {uS+=kUzl;pS++;return false;}
			}
			if(key>t->key)
			{
				if(t->pR!=Null){t=t->pR;kUzl++;}
				else {uS+=kUzl;pS++;return false;}
			}		
		}
		uS+=kUzl;return true;
	}
//включение данных с заданным ключом
	virtual bool add(unsigned long key, T data)
	{
		if(pH==Null) 
		{
			pH=new BST<T>::Node(key,data,Null);sz++;kUzl++;
			return true;
		}
		BST<T>::Node *t=pH;kUzl++;
		if(key==t->key) {uIns+=kUzl;pIns++;return false;}
		while(key!=t->key)
		{
			if(key<t->key)
			{
				if(t->pL!=Null) {t=t->pL;kUzl++;}
				else {t->pL=new BST<T>::Node(key,data,Null);t->pL->pP=t;sz++;kUzl++;uIns+=kUzl;return true;}
			}
			if(key>t->key)
			{
				if(t->pR!=Null){t=t->pR;kUzl++;}
				else {t->pR=new BST<T>::Node(key,data,Null);t->pR->pP=t;sz++;kUzl++;uIns+=kUzl;return true;}
			}		
		}
		uIns+=kUzl;pIns++;return false;
	}
//удаление данных с заданным ключом
	virtual bool del(unsigned long key)
	{
		if(sz==0) {uDel+=kUzl;pDel++;return false;}
		BST<T>::Node *t,*p=pH;
		BST<T>::Node *predt=p;
		while(key!=p->key)
		{
			if(key<p->key)
			{
				if(p->pL!=Null) {predt=p;p=p->pL;kUzl++;}
				else {uDel+=kUzl;pDel++;return false;}
			}
			if(key>p->key)
			{
				if(p->pR!=Null) {predt=p;p=p->pR;kUzl++;}
				else {uDel+=kUzl;pDel++;return false;}
			}		
		}	
		//найден ключ
		//
		if(p->pL==Null) 
		{
			//удаляем голову
			if(predt==p) 
			{
				//голова дерева - единственный элемент
				if(p->pR==Null)
				{
					delete p;
					pH=Null;kUzl++;
					sz--;uDel+=kUzl;
					return true;
				}
				else
				{
					pH=p->pR;kUzl++;
					pH->pP=Null;
					sz--;
					delete p;uDel+=kUzl;
					return true;
				}
			}
			if(p==predt->pL) 
			{
				predt->pL=p->pR;
				if(p->pR!=Null)p->pR->pP=predt;
				kUzl++;
			}
			else 
			{
				predt->pR=p->pR;
				if(p->pR!=Null)p->pR->pP=predt;
				kUzl++;
			}
			delete p;uDel+=kUzl;
			sz--;return true;
		}	
		t=p->pL;kUzl++;
		predt=p;
		while(t->pR!=Null)
		{
			predt=t;
			t=t->pR;kUzl++;
		}
		p->item=t->item;
		p->key=t->key;
		if(t==p->pL) 
		{
			p->pL=t->pL;
			if(t->pL!=Null)t->pL->pP=p;
			kUzl++;
		}
		else 
		{
			predt->pR=t->pL;
			if(t->pL!=Null)t->pL->pP=predt;
			kUzl++;
		}
		delete t;kUzl++;
		sz--;uDel+=kUzl;
		return true;
	}
//обход t->L->R
	virtual bool obxod()
	{
		if(pH==Null) return false;
		stack<BST<T>::Node *> ss;
		BST<T>::Node *t=pH;
		ss.push(t);
		while(!ss.empty())
		{
			t=ss.top();ss.pop();
			cout<<"["<<t->key<<","<<t->item<<"] ";
			kUzl++;
			if(t->pR!=Null) ss.push(t->pR);
			if(t->pL!=Null) ss.push(t->pL);
		}
		return true;
	}
//вывод структуры дерева на экран
	virtual bool view()
	{
		int lev,i;
		int check=1;
		if(sz==0) return false;
		stack<BST<T>::Node *> st,sR,sL;		//стеки указателей на элементы
		stack<int> ist,isR,isL;				//стеки их уровней вложенности
		BST<T>::Node *t=pH;
		st.push(t);		//Заносим вершину,
		sR.push(t->pR);	//			правого потомка
		sL.push(t->pL);	//				и левого потомка
		kUzl++;kUzl++;kUzl++;
		ist.push(0);	//А также 
		isR.push(1);	//		их уровни
		isL.push(1);	//			вложенности	
		while(check==1)
		{
			//анализ правого сына
			while(!sR.empty())
			{
				t=sR.top();sR.pop();kUzl++;
				lev=isR.top();isR.pop();
				if(t==Null) 
				{
					for(i=0;i<lev;i++) cout<<"\t";
					cout<<"\n";
				}
				else
				{
					if(t->pL==Null&&t->pR==Null) 
					{
						for(i=0;i<lev;i++) cout<<"\t";
						cout<<t->key<<"("<<t->item<<")"<<"\n";
					}
					else
					{
						st.push(t);ist.push(lev);kUzl++;
						sR.push(t->pR);isR.push(lev+1);kUzl++;
						sL.push(t->pL);isL.push(lev+1);kUzl++;
					}
				} 
			}
			//вернулись к родителю
			t=st.top();st.pop();kUzl++;
			lev=ist.top();ist.pop();
			for(i=0;i<lev;i++) cout<<"\t";
			cout<<t->key<<"("<<t->item<<")"<<"\n";
			//анализ левого сына
			t=sL.top();sL.pop();kUzl++;
			lev=isL.top();isL.pop();
			if(t==Null) 
			{
				for(i=0;i<lev;i++) cout<<"\t";
				cout<<"\n";
			}
			else
			{
				if(t->pL==Null&&t->pR==Null) 
				{
					for(i=0;i<lev;i++) cout<<"\t";
					cout<<t->key<<"("<<t->item<<")"<<"\n";
				}
				else
				{
					st.push(t);ist.push(lev);kUzl++;
					sR.push(t->pR);isR.push(lev+1);kUzl++;
					sL.push(t->pL);isL.push(lev+1);kUzl++;
				}
			}
			if((st.size()==0)&&(sR.size()==0)&&(sL.size()==0)) check=0;
		}
		return true;		
	}

//поиск к-ключа в дереве
	/*int*/ Node* selectk(Node *tree, unsigned long key)
	{
		int m;
		if( (this->size() < key) || (key < 0) ){throw 1;}
		else
		if(tree==NULL) return tree/*->item*/;  
		
		//stack<BST<T>::Node *> st,sR,sL;		//стеки указателей на элементы
		
		//BST<T>::Node *t=pH; //??? я так понял это корень дерева ???

		//st.push(t);		//Заносим вершину,
		//sR.push(t->pR);	//			правого потомка
		//sL.push(t->pL);	//				и левого потомка
		
		
		if(tree->pL == NULL){
			m=0;
		}else{
			m = travers_counter_onStackBased(tree->pL); // подсчитываем и запоминаем количество узлов
												       // в левом поддереве 
		};

		if (m>key) return selectk(tree->pL, key);
		if (m<key) return selectk(tree->pR, key-m-1);
		return tree;
		
/*		BST<T>::Node *t=this->pH;
		int m;
		if(sz==0) {return t->item;}
		if(t->pL==Null) {m=0;}
		else {m=t->pL;}
		if (m>k) then return selectk(t=t->pL, key);
		if (m<k) then return selectk(t=t->pR, key-m-1);
		return t->item;*/
	}

	//подсчитывает количество узлов в дереве/поддереве и возвращает результат
int travers_counter_onStackBased(Node* root){
	if(root == NULL)return 0;
	
	int node_counter = 0; // счётчик узлов
	Node* t = NULL;	// указатель на текущий обрабатываемый узел
	stack<BST<T>::Node *> st;
	st.push(root);

	while(!st.empty()){ // пока стек не пуст

		t = st.top(); st.pop();
		++node_counter;

		if(t->pR != NULL)st.push(t->pR);
		if(t->pL != NULL)st.push(t->pL);
	}
	return node_counter;
}

Node* getRoot(){
	return pH;
}

void printNode(Node* node){
	cout << "Key: " << node->key << " item: " << node->item << endl << endl; 
}

//опрос числа просмотренных последней операцией узлов дерева
	unsigned long Uzl(){return kUzl;}
	void Uzl_Setup(){kUzl=0;}
	void sbros() {pIns=pDel=pS=uIns=uDel=uS=0;}
	unsigned long cntshow(int num)
	{
		switch(num)
		{
		case 1: return uIns;
		case 2: return pIns;
		case 3: return uDel;
		case 4: return pDel;
		case 5: return uS;
		case 6: return pS;
		default: return -1;
		}
	}
};
