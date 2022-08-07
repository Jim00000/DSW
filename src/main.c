/* MIT License

Copyright (c) 2022 Jim00000

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include "bst.h"
#include "dsw.h"
#include "plot.h"

void DSWAlgorithmDemo1()
{
    struct TreeNode *root = TreeNodeCreate(10);
    root->left = TreeNodeCreate(5);
    root->left->right = TreeNodeCreate(7);
    root->right = TreeNodeCreate(20);
    root->right->left = TreeNodeCreate(15);
    root->right->right = TreeNodeCreate(30);
    root->right->right->left = TreeNodeCreate(25);
    root->right->right->left->left = TreeNodeCreate(23);
    root->right->right->right = TreeNodeCreate(40);
    const int total_node = 9;
    plotGraph(root, "original1");
    DSWAlgorithm(&root, total_node);
    plotGraph(root, "output1");
}

void DSWAlgorithmDemo2()
{
    struct BinaryTreeHeader *header = BinaryTreeHeaderCreate();
    BinarySearchTreeAppend(header, 50);
    BinarySearchTreeAppend(header, 10);
    BinarySearchTreeAppend(header, 90);
    BinarySearchTreeAppend(header, 20);
    BinarySearchTreeAppend(header, 30);
    BinarySearchTreeAppend(header, 80);
    BinarySearchTreeAppend(header, 71);
    BinarySearchTreeAppend(header, 3);
    BinarySearchTreeAppend(header, 56);
    BinarySearchTreeAppend(header, 52);
    BinarySearchTreeAppend(header, 93);
    BinarySearchTreeAppend(header, 67);
    BinarySearchTreeAppend(header, 34);
    BinarySearchTreeAppend(header, 51);
    BinarySearchTreeAppend(header, 32);
    BinarySearchTreeAppend(header, 29);
    BinarySearchTreeAppend(header, 66);
    BinarySearchTreeAppend(header, 98);
    BinarySearchTreeAppend(header, 88);
    BinarySearchTreeAppend(header, 77);
    BinarySearchTreeAppend(header, 33);
    plotGraph(header->root, "original2");
    DSWAlgorithm(&header->root, header->size);
    plotGraph(header->root, "output2");
}

void DSWAlgorithmDemo3()
{
    struct BinaryTreeHeader *header = BinaryTreeHeaderCreate();
    BinarySearchTreeAppend(header, 50);
    BinarySearchTreeAppend(header, 40);
    BinarySearchTreeAppend(header, 30);
    plotGraph(header->root, "original3");
    DSWAlgorithm(&header->root, header->size);
    plotGraph(header->root, "output3");
}

int main(int argc, char* argv[])
{
    DSWAlgorithmDemo1();
    DSWAlgorithmDemo2();
    DSWAlgorithmDemo3();
}