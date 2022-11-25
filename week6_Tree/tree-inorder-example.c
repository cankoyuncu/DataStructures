#include <stdio.h>
#include <conio.h>

    struct node{
        int data;
        struct node *left;
        struct node *right;
    };

    typedef struct node CANTREE; //yukardaki struct yapısını CANTREE diyerek kullanacagim.

    CANTREE *yeni_dugum(int data){
        CANTREE *p=(CANTREE*)malloc(sizeof(CANTREE));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        return p;
    }

    CANTREE *ekle(CANTREE *root, int data){
        if(root==NULL) 
            root = yeni_dugum(data);
        else{
            if(data<root->data)
                root->left=ekle(root->left,data);
            else   
                root->right=ekle(root->right,data);
        }
        return root;
    }

    void inorder(CANTREE *root){
        if (root!=NULL){
            inorder(root->left);
            printf("%2d", root->data);
            inorder(root->right);
            // printf("%d", root->data);
        }2
    }

    main(){
        CANTREE *canroot=NULL;
        int i; //i=giris yaptigimiz veriler(datalar)
        do {
            printf("Agaca eklemek istediginiz veriyi giriniz[Cikis yapmak icin -1 tuslayiniz.]: ");
            scanf("%d", &i);
            if (i!=-1);
                canroot = ekle(canroot,i);
            } while (i!=-1);
            inorder(canroot);
            printf("\n");
            getch();
            return 0;          
    }
