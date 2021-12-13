/**
 * @author Yannick Brenning
 * @date 11.12.2021
 * @brief Implementation of binary search trees
 */

#ifndef BINARY_SEARCH_TREES_H
#define BINARY_SEARCH_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX(x,y) (((x) > (y)) ? (x) : (y))

typedef struct bst_node_t {
    int val;
    struct bst_node_t *left;
    struct bst_node_t *right;
} bst_node_t;

// Insert node into bst
bst_node_t *bst_insert(bst_node_t *root, const int val);
// Destroy bst
void bst_destroy(bst_node_t *root)
// Count number of nodes
unsigned int bst_node_count(bst_node_t *root);
// Print content of bst onto console
void bst_print(bst_node_t *root);
// Check if tree contains a value
bool bst_is_in_tree(bst_node_t *root, int val);
// Get height of bst (highest number edges from root to leaf)
int bst_get_height(bst_node_t *root);
// Get max value in bst
int bst_get_min(bst_node_t *root);
// Get max value in bst
int bst_get_max(bst_node_t *root);
// Checks if a binary tree is a bst
bool bst_is_valid(bst_node_t *root);
// Checks if all the nodes in a subtree are smaller than the current node
bool is_subtree_greater(bst_node_t *root, int val);
// Checks if all the nodesi n a subtree are greater than the current node
bool is_subtree_lesser(bst_node_t *root, int val);
// Deletes node with val from the bst
bst_node_t *bst_delete_val(bst_node_t *root, int val);

#endif //BINARY_SEARCH_TREES_H
