#include "binary_trees.h"

/***/

int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    binary_tree_is_complete(tree->left);
    binary_tree_is_complete(tree->right);

    if ((tree->left && !tree->right) || (!tree->left && tree->right))
        return (0);
    else if ((tree->left && tree->right) || (!tree->left && !tree->right))
        return (1);
}
