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

#include "dsw.h"
#include <math.h>
#include <stdlib.h>

static void TreeNodeLeftRotate(struct TreeNode **node);
static void TreeNodeRightRotate(struct TreeNode **node);
static struct TreeNode *BstToVine(struct TreeNode *root);
static void compress(struct TreeNode **root, int times);

void TreeNodeLeftRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->right != NULL)
        {
            struct TreeNode *rightson = parent->right;
            struct TreeNode *grandson = rightson->left;
            rightson->left = parent;
            parent->right = grandson;
            *node = rightson;
        }
    }
}

void TreeNodeRightRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->left != NULL)
        {
            struct TreeNode *leftson = parent->left;
            struct TreeNode *grandson = leftson->right;
            leftson->right = parent;
            parent->left = grandson;
            *node = leftson;
        }
    }
}

struct TreeNode *BstToVine(struct TreeNode *root)
{
    while (root->left != NULL)
    {
        TreeNodeRightRotate(&root);
    }
    struct TreeNode *current = root->right;
    struct TreeNode *previous = root;
    while (current != NULL)
    {
        while (current->left != NULL)
        {
            TreeNodeRightRotate(&current);
            previous->right = current;
        }
        previous = current;
        current = current->right;
    }
    return root;
}

void compress(struct TreeNode **root, int times)
{
    struct TreeNode *head = NULL, *prev = NULL;
    struct TreeNode *node = *root;
    for (int i = 0; i < times; i++)
    {
        TreeNodeLeftRotate(&node);
        if (prev != NULL)
            prev->right = node;
        else
            head = node;
        prev = node;
        node = node->right;
        if (node == NULL)
            break;
    }
    *root = head;
}

void DSWAlgorithm(struct TreeNode **_root, const int total_node)
{
    struct TreeNode *root = *_root;
    root = BstToVine(root);

    int level = (int)floor(log2f((float)total_node));
    int bottom = total_node - ((1 << level) - 1);

    compress(&root, bottom);

    for (int i = ((1 << level) - 1) / 2; i > 0; i /= 2)
    {
        compress(&root, i);
    }

    *_root = root;
}