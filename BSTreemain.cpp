#include <iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<string>
#include"BSTree.h"



using namespace std;
using namespace BSTreeNS;
int main()
{
   //MemoryLeakTest();
    BSTree tree;
    int arr[10]={5,4,2,6,0,3,8,1,9,10};
    for(int i=0;i<10;i++)
    {
        tree.Insert(arr[i],i);
    }
  tree.preorder();
   tree.WriteInFile();

    return 0;
}
