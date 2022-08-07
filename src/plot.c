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

#include "plot.h"
#include <stdlib.h>

static void plotSingleNodeVertex(struct TreeNode *node, FILE *fptr);

static void plotSingleNodeEdge(struct TreeNode *node, FILE *fptr);

void plotSingleNodeVertex(struct TreeNode *node, FILE *fptr)
{
    if (node != NULL)
    {
        fprintf(fptr, "    %d [shape=circle]\n", node->value);
        plotSingleNodeVertex(node->left, fptr);
        plotSingleNodeVertex(node->right, fptr);
    }
}

void plotSingleNodeEdge(struct TreeNode *node, FILE *fptr)
{
    if (node != NULL)
    {
        if (node->left != NULL)
        {
            fprintf(fptr, "    %d -> %d\n", node->value, node->left->value);
            plotSingleNodeEdge(node->left, fptr);
        }
        else
        {
            fprintf(fptr, "    null%d_left [shape=point]\n", node->value);
            fprintf(fptr, "    %d -> null%d_left\n", node->value, node->value);
        }

        if (node->right != NULL)
        {
            fprintf(fptr, "    %d -> %d\n", node->value, node->right->value);
            plotSingleNodeEdge(node->right, fptr);
        }
        else
        {
            fprintf(fptr, "    null%d_right [shape=point]\n", node->value);
            fprintf(fptr, "    %d -> null%d_right\n", node->value, node->value);
        }
    }
}

void plotGraph(struct TreeNode *root, const char *output_filename)
{
    char buffer[BUFSIZ];
    FILE *fptr;
    fopen_s(&fptr, "tree.dot", "w");
    fprintf(fptr, "digraph Tree {\n");
    fprintf(fptr, "    graph [ordering=\"out\"]\n");
    plotSingleNodeVertex(root, fptr);
    plotSingleNodeEdge(root, fptr);
    fprintf(fptr, "}\n");
    fclose(fptr);
    sprintf(buffer, "dot tree.dot -Tpng > %s.png", output_filename);
    system(buffer);
    sprintf(buffer, "start ./%s.png", output_filename);
    system(buffer);
}