#include <stdio.h>
#include <limits.h>
#define datatype int
typedef struct tree
{
 datatype key;
 struct tree *left, *right, *parent;
} tree;
int t = 0;
datatype findMin(tree *root);
datatype findMax(tree *root);

int main(int argc, char ** argv)
{
 tree t[10]={0};
 t[0].left = t+1;
 t[0].right = t+2;
 t[0].key = 10;
 t[1].left = t+3;
 t[1].right = t+4;
 t[1].key = 5;
 t[1].parent = t+0;
 t[2].left = t+5;
 t[2].right = t+6;
 t[2].key = 15;
 t[2].parent = t+0;
 t[3].left = t+7;
 t[3].parent = t+1;
 t[3].key = 3;
 t[4].left = t+8;
 t[4].parent = t+1;
 t[4].key = 7;
 t[5].key = 13;
 t[5].parent = t+2;
 t[6].key = 18;
 t[6].parent = t+2;
 t[7].key = 1;
 t[7].parent = t+3;
 t[8].key = 6;
 t[8].parent = t+4;
	datatype minElement = findMin(t);
    datatype maxElement = findMax(t);

    // Находим разницу между минимальным и максимальным элементами
    int diff = maxElement - minElement;
    
    printf("Difference between min and max elements of tree: %d\n", diff);

    return 0;
}

datatype findMin(tree *root) {
    if (root == NULL) {
        return INT_MAX;
    }
    datatype leftMin = findMin(root->left);
    datatype rightMin = findMin(root->right);
    return (root->key < leftMin) ? ((root->key < rightMin) ? root->key : rightMin) : ((leftMin < rightMin) ? leftMin : rightMin);
}

// Функция для поиска максимального элемента в дереве
datatype findMax(tree *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    datatype leftMax = findMax(root->left);
    datatype rightMax = findMax(root->right);
    return (root->key > leftMax) ? ((root->key > rightMax) ? root->key : rightMax) : ((leftMax > rightMax) ? leftMax : rightMax);
}

