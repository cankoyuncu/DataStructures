#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n *sol;
	n *sag;
};
typedef n node;

node *ekle(node *agac, int x){
	if(agac==NULL){
		node *root=(node *)malloc(sizeof(node));
		root -> sol = NULL;
		root -> sag = NULL;
		root -> data = NULL;
		return root;
	}
	
	if(agac->data < x){
		agac->sag = ekle(agac->sag,x);
	return agac;
	agac->sol=ekle(agac->sol,x);
	return agac;
	
//		if(iter->sag!=NULL)
//			return ekle(agac->sag,x);
//		if(iter->sol!=NULL)	
//			ekle(agac->sol,x);		
	}
	void dolas(node *agac){
		if(agac==NULL)
			return;
		dolas(agac->sol);
		printf("%d", agac->data);
		dolas(agac->sag);
	}

}

int main(){
	node *agac=NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,32);
	agac=ekle(agac,133);
	agac=ekle(agac,16);
	agac=ekle(agac,44);
	agac=ekle(agac,32);
	dolas(agac);
}
