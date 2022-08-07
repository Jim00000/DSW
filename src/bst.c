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
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode *TreeNodeCreate(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

struct BinaryTreeHeader *BinaryTreeHeaderCreate()
{
    struct BinaryTreeHeader *header = malloc(sizeof(struct BinaryTreeHeader));
    header->root = NULL;
    header->size = 0;
    return header;
}

void BinarySearchTreeAppend(struct BinaryTreeHeader *header, int value)
{
    if (header->root == NULL)
    {
        header->root = TreeNodeCreate(value);
    }
    else
    {
        struct TreeNode *current = header->root;
        while (true)
        {
            if (current->value >= value)
            {
                if (current->left != NULL)
                {
                    current = current->left;
                }
                else
                {
                    current->left = TreeNodeCreate(value);
                    break;
                }
            }
            else
            {
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current->right = TreeNodeCreate(value);
                    break;
                }
            }
        }
    }
    header->size++;
}