// 이진트리 구현하기
#include <stdio.h>
#include <stdlib.h>



typedef char item;
typedef struct binary_tree* t_pointer;
typedef struct binary_tree{
    item node;
    t_pointer left;
    t_pointer right;
}b_tree;


typedef enum {FALSE,TRUE} bool;

t_pointer Create();
t_pointer MakeBT(t_pointer bt1,item data,t_pointer bt2);
bool IsEmpty(t_pointer bt);
t_pointer Lchild(t_pointer bt);
t_pointer Rchild(t_pointer bt);
item* Data(t_pointer bt);
void inorder(t_pointer bt);
int main(){//아 힘들다.
    t_pointer p1=NULL;
    t_pointer p2=NULL;
    t_pointer p3=NULL;
    t_pointer p4=NULL;
    t_pointer p5=NULL;
    t_pointer p6=NULL;
    t_pointer p7=NULL;
    t_pointer p8=NULL;
    t_pointer p9=NULL;


    p1=Create();
    p2=Create();
    p3=Create();
    p4=Create();
    p5=Create();
    p6=Create();
    p7=Create();
    p8=Create();
    p9=Create();

    p1->node='A';
    p2->node='B';
    p3->node='C';
    p4->node='D';
    p5->node='E';
    p6->node='F';
    p7->node='G';
    p8->node='H';
    p9->node='I';

    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;
    p4->left=p8;
    p4->right=p9;

    inorder(p1);
    return 0;
}

t_pointer Create(){
    t_pointer p1;
    b_tree tree1;

    p1=malloc(sizeof(tree1));
    p1=&tree1;
    p1->left=NULL;
    p1->right=NULL;
    return p1;
}
t_pointer MakeBT(t_pointer bt1,item data,t_pointer bt2){
    t_pointer p1;
    b_tree tree1;

    p1=malloc(sizeof(tree1));
    p1=&tree1;

    p1->left=bt1;
    p1->right=bt2;
    p1->node=data;

    return p1;
}
bool IsEmpty(t_pointer bt){
    if(bt)
        return FALSE;
    else
        return TRUE;
}
t_pointer Lchild(t_pointer bt){//왼쪽 자식트리 반환 if(없으면)->NULL
    if(!IsEmpty(bt->left))
        return bt->left;
    else
        return NULL;            //왼쪽 자식노드가 없으면 NULL반환.
}
t_pointer Rchild(t_pointer bt){//오른쪽 자식트리 반환 if(없으면)->NULL
    if(!IsEmpty(bt->right))
        return bt->right;
    else
        return NULL;            //오른쪽 자식노드가 없으면 NULL반환.
}
item* Data(t_pointer bt){   //error 를 null로 주기위해서 자료형을 포인터로 바꿨음 받을때도 역참조로 받아야함.
    if(!IsEmpty(bt)){
        return NULL;
    }
    else{
        return &bt->node;
    }
}
void inorder(t_pointer bt){
    if(bt){
        inorder(bt->left);
        printf("%d ",bt->node);
        inorder(bt->right);
    }
}