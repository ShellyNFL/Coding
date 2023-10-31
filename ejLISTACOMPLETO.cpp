//Code by Shelly Naomi Flores López
#include <stdio.h>
#include<iostream>
using namespace std;

void insertend(struct nodo *lista, int x);
void insertOrder(struct nodo *lista,int numio);
void print(struct nodo *lista);
void erase(struct nodo *lista,int nume);
void jcircle(struct nodo *lista,int hn,int fs);
void printjc(struct nodo *inicio);

struct nodo {
   int inf;
   struct nodo *sig;
};

int main(){
	int op;
	int x;
	int num;
	//se crea apuntador que apunta a algo tipo struct
	struct nodo *lista;
	//apunta al primer nodo de la lista
	lista=new(nodo);
	lista->sig=NULL;
	
	
	do{
		
		printf("\nCHOOSE ONE OPTION:\n");
		printf("1.INSERT AT THE END\n");
		printf("2.INSERT IN ORDER\n");
		printf("3.PRINT\n");
		printf("4.DELETE ELEMENT\n");
		printf("5.JOSEPHUS'S CIRCLE\n");
		printf("6.EXIT\n");
		scanf("%d",&op);
		
		switch(op){
		
			case 1:
				cout<< "GIVE THE VALUE TO ADD: ";
				cin>>x;
				insertend(lista,x);									 
		        break;
		    case 2: 
				cout<< "GIVE THE VALUE TO ADD: ";
				cin>>x;
				insertOrder(lista,x);									 
		        break;
		    case 3://imprimir
		   			print(lista);
		    	break;
		    case 4: //eliminar 
		    	print(lista);
		    	cout<< "GIVE THE NUMBER TO DELETE FROM THE LIST ABOVE:\n";
				cin>> num;
				erase(lista,num);
				print(lista);
		    	break;

		    case 5: //CÍRCULO DE JOSEPHUS
		    	int hops_num, first_solder;
		    	cout<< "GIVE THE NUMBER OF THE SOLDIER WHOM WE'RE GONNA START COUNTING:\n";
				cin>> first_solder;
		    	cout<< "GIVE THE NUMBER OF HOPS:\n";
				cin>> hops_num;
		    	jcircle(lista,hops_num,first_solder);
				break;
				
			default:
		    	printf("Ciao");
		    	break;
		}

    }while(op<6);
		
    return 0;
}

void insertend(struct nodo *p, int x){	
		struct nodo *q;
		while (p->sig != NULL){
			q=p;
			p=p->sig;	
		}
		struct nodo *nuevo;
		nuevo=new (nodo);
		nuevo->inf=x;
		p->sig=nuevo;
		nuevo->sig=NULL;
		cout<<"INSERTION AT THE END SUCCESSFUL \n\n";	
}

void insertOrder(struct nodo *p,int numio){
	struct nodo *q;
	q=p;
	bool flag=false;
	//INSERT AT THE BEGINNING
	if(p->sig==NULL){
		struct nodo *nuevo;
		nuevo=new (nodo);
		nuevo->inf=numio;
		p->sig=nuevo;
		nuevo->sig=NULL;
		cout<<"INSERTION IN THE ORDER SUCCESSFUL  \n\n";
	}else{
		p=p->sig;
		//THIS LOOP WOORK FOR PUT P IN THE CORRECT
		//POSITION WHEN IS GONNA INSERT
		while(numio>p->inf && flag==false){
			if (p->sig==NULL){
				flag=true;	
			}else{
				q=p;
				p=p->sig;
			}
			//cout <<"Test\n";	
		}
		//ONLY THREE MORE OPTIONS:
		//1. THE NUMBER WE WANNA INSERT IS BIGGER THAN EVERYOTHER
		//SO IS GONNA ADD IT AT THE END	
		if (p->sig==NULL && numio>p->inf){
			struct nodo *nuevo;
			nuevo=new (nodo);
			nuevo->inf=numio;
			p->sig=nuevo;
			nuevo->sig=NULL;
			cout<<"INSERTION IN THE ORDER SUCCESSFUL  \n\n";
		//2. THE NUMBER WE WANNA ADD AI ALREADY IN THE LIST 					
		}else if (p->inf==numio){
			cout <<"THE NUMBER IS ALREADY IN THE LIST \nTRY AGAIN WITH A DIFFERENT ONE\n\n";
		}else{ //IN OTHER CASE
			struct nodo *nuevo;
			nuevo=new (nodo);
			nuevo->inf=numio;
			nuevo->sig=p;
			q->sig=nuevo;	
			cout<<"INSERTION IN THE ORDER SUCCESSFUL \n\n";	
		}			
	}	
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

void erase(struct nodo *p, int nume){
	if (p->sig==NULL){
		cout<< "COULDN'T DELETE BECAUSE THE LIST IS EMPY\nTRY AGAIN\n\n";
	}else{
		struct nodo *q;
		int ne=0;
		q=p;
		p=p->sig;
		while (ne!=1){
			if (p->inf==nume){
				ne=1;
				q->sig=p->sig;
				cout<<"SUCCESSFUL DELETE\n\n";
				//p->sig=q->sig;
			}else{ //THE NUMBER IS NOT IN THE LIST
				q=p;
				p=p->sig;
				if(p->sig==NULL && nume!=p->inf){
					cout<<"THAT NUMBER ISN'T IN THE LIST\n\n";
					break;
				}	
			}		
		}
	}
}
 
void printjc(struct nodo *lista){
	struct nodo *inicio;
	inicio=lista->sig;
	while(inicio->sig!=lista){
		cout<<inicio->inf<<" ";
		inicio=inicio->sig;
	}
	cout<<inicio->inf<<" ";
	cout<<"\n";	
}

void jcircle(struct nodo *lista, int hn,int fs){
	struct nodo *p;
	struct nodo *q;
	p=lista;
   	q=p;
	//fullfill the 8 nodes with the numbers	
	for (int i=0; i<8;i++){
		p=new(nodo);
		int soldier_num=i+1+(i+1)*10;
		p->inf=soldier_num;
		if(lista->sig==NULL)
		lista->sig=p;
		else
		q->sig=p;
		q=p;
		//This operation is to get the number of the soldier	
	}
	p->sig=lista;
	//p is jumping from the last node till one node after lista
	//this is like this bc lista is empty
	p=lista->sig;
	printjc(lista);
	//with this while we have p in the position where fs is indicating
	while(p->inf!=fs){
		q=p;
		p=p->sig;
	}
	for (int j=0; j<7;j++){
		for (int i=0;i<hn;i++){
			if (p->sig==lista){
				q=p;
				p=lista->sig;
			}else{
				q=p;
				p=p->sig;
			}	
		}
		//delete de soldier
		if (lista->sig==p){
			cout<<"NUMBER DELETED: "<<p->inf<<"\n";
			q=p;
			q=q->sig;
			lista->sig=q;
			
		}else{
			cout<<"NUMBER DELETED: "<<p->inf<<"\n";
			q->sig=p->sig;
			p=q;
		}
		printjc(lista);		
		if(p->sig==lista){
			p=lista->sig;
		}else{
			p=p->sig;
		}
		//cout<<"START COUNTING IN: "<<p->inf<<endl;
	}
}
