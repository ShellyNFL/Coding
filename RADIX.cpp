//Code by Shelly Naomi Flores Lopez
#include <stdio.h>
#include<iostream>
using namespace std;
int place_value(int number,int op);
void imprimir(int *pointer, int x);
void print(struct nodo *p);

struct nodo {
   int inf;
   struct nodo *sig;
};

int main (){
	int num,elements,value_element;
	int contador=0;
	int position;
	cout<<"GIVE ME THE NUMBER OF ELEMENTS IN YOUR ARRAY: \n";
	cin>>elements;
	int array[elements];
	int *q;
	q=array;
	for (int i=0;i<elements;i++){
		cout<<"GIVE ME THE ELEMENT "<<i+1<<": "<<endl;
		cin>>value_element;
		array[i]=value_element;		
	}
	//array of pointers which point to sth that is struct nodo
	//solo almacena los apuntadores que apuntan a algo struct nodo
	struct nodo *lista[10];
	for (int i=0;i<10;i++){
		//each pointer point to a node
		lista[i]= new(nodo);
		lista[i]->sig=NULL;	
	}
	for(int k=0;k<3;k++){
	struct nodo *p;
	//for all the elements in the array extract the ones,tens and hundreds
	for(int i=0;i<elements;i++){
		position=place_value(array[i],k);
		//do it 10 times to put them in the correct list
		for (int j=0;j<10;j++){	
			if (position==j){
				p=lista[position];
				while (p->sig != NULL){
					p=p->sig;	
				}
				struct nodo *nuevo;
				nuevo=new (nodo);
				nuevo->inf=array[i];
				p->sig=nuevo;
				nuevo->sig=NULL;
			}
		}		
	}
	//INSERT THE NUMBERS IN THE LIST IN THE ARRAY (using the pointer q)	
	for(int i=0;i<10;i++){
		p=lista[i];
		cout<<"\n LISTA "<<i<<endl;
		while (p->sig != NULL){
			p=p->sig;
			*q=p->inf;
			q++;	
		}print(lista[i]);	
	}
	cout<<"\n"<<k+1<<" SORT\n";
	q=array;
	imprimir(q, elements);
	for (int i=0;i<10;i++){
		//each pointer point to a node
		lista[i]->sig=NULL;	
	}
}
}
	
int place_value(int number,int op){
	switch (op){
		case 0: //ones
			return number%10;
		break;
		case 1://tens
			return (number%100)/10;
		 break;
		case 2://hundreds
			return number/100;
		break;
	}
}

void imprimir(int *pointer,int x){
               for (int i=0;i<x;i++){
                    cout <<" "<<*pointer++<<" ";
               }
               cout << "\n";

}

void print(struct nodo *p){
	if (p->sig==NULL){
		cout<<"LISTA VACIA\n\n";
	}else{
		p=p->sig;
		struct nodo *q;
		while(p->sig!=NULL){
			cout<<p->inf<<" ";
			q=p;
			p=p->sig;
		}
		if (p->sig==NULL){
			cout<<p->inf;
		}
		cout<<"\n";
	}
}
