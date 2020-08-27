#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define mktree() (bintree *)malloc(sizeof(bintree)) 

typedef struct Bintree {     
    int data;     
    Bintree *lchild; // left child of the node
    Bintree *rchild; // right child of the node 
} bintree; 


void array()
{
    int myvector [100];
    char mystring [80];
    float mymatrix [3] [2] = {2.0 , 10.0, 20.0, 123.0, 1.0, 1.0}; 
    int notfull [3][3] = {{1},{1,2,3},{4,5}};
    char lexicon [10000] [300];// 一万个300长度的数组
    int a[3][4];

    // define NDEBUG to remove assert
    assert(notfull[0][0]==1);
    assert(notfull[0][1]==0);
    assert(notfull[2][0]==4);
    assert(notfull[2][2]==0);

    printf("array\n");

    return;
}

int mem()
{
    int * buffer1, * buffer2, * buffer3;
    buffer1 = (int*) malloc (100*sizeof(int));
    buffer2 = (int*) calloc (100,sizeof(int));
    buffer3 = (int*) realloc (buffer2,500*sizeof(int));
    free (buffer1);
    free (buffer3);
    buffer1 = NULL;
    buffer3 = NULL;
    system("echo mem");

    return 0;
}

int main(void)
{
    bintree *tree; 
    tree = mktree(); 
    tree->data = 1; 
    tree->lchild = mktree();

    free(tree->lchild);
    free(tree);
    tree->lchild = NULL;
    tree = NULL;

    array();
    mem();

    printf("Hello, world!\n");

    return 0;
}

