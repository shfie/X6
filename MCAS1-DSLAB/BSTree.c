#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* insert(struct node* root,int value){
    if(root==NULL){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->left=temp->right=NULL;
        return temp;
    }
    if (value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
struct node* search(struct node* root, int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key>root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }

}
struct node* delete(struct node* root,int value){
    if(root==NULL){
        return NULL;

    }
    else if (root->data==value){
        free(root);
    }
}
int main(){
    int choice, value;
    struct node* root = NULL;
    struct node* result;
    while(1){
    printf("BINARY SERACH TREE \n");
    printf("1.INSERTION \n");
    printf("2.SEARCHING \n");
    printf("3.DELETION\n");
    printf("4.PREORDER TRAVERSAL \n");
    printf("5.POSTORDER TRAVERSAL \n");
    printf("6.EXIT \n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    
    switch (choice){
        case 1:
            printf("ENTER VALUE TO INSERT: ");
            scanf("%d", &value);
            root=insert(root, value);
            printf("%d INSERTED SUCCESSFULLY! \n", value);
            break;
        case 2:
            printf("ENTER THE VALUE TO SEARCH:");
            scanf("%d",&value);
           result= search(root,value);    
           if (result!=NULL){
            printf(" found");
           }
           else {
            printf("not founded");
           }
        case 3:
           printf("ENTER THE VALUE TO DELETE:");
           scanf("%d",&value);   
           result=search(root,value);
           if(result==NULL){
            printf("its not in the tree");
           }
else{
    root=delete(root,value);
}
    }
}
}


    