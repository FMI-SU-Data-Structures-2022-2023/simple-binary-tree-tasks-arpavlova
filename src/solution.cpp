#include "solution.h"

int countElements(Node* tree) 
{
    if (!tree) { return 0; }

    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) 
{
    if (!tree) { return 0; }
    if (!tree->left && !tree->right) return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) 
{
    if (!tree) { return 0; }
    return (1 + height(tree->left) >= 1 + height(tree->right)) ? 1 + height(tree->left) : 1 + height(tree->right);
}

int sumElements(Node* tree) 
{
    if (!tree) { return 0; }

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) 
{
    if (!tree) { return 0; }
    if (!level) { return tree->key; }
    return sumElementsAtLevel(tree->left, level-1) + sumElementsAtLevel(tree->right, level-1);

}

bool areSubtreesSymmetric(Node* left, Node* right)
{
    if (!left && !right) { return true; }

    if (!left || !right) { return false; }

    if (left->key == right->key)
    {
        return areSubtreesSymmetric(left->left, left->right) && areSubtreesSymmetric(left->right, left->left);
    }


    return false;
}

bool isSymmetric(Node* tree) 
{
    if (!tree) { return true; }
    return areSubtreesSymmetric(tree->left, tree->right);
}

bool areSubtreesBST(Node* root)
{
    if (!root) { return true; }
    if(root->left && root->right) 
    { 
        if(root->left->key < root->key&& root->key <= root->right->key)
        {
            return areSubtreesBST(root->left) && areSubtreesBST(root->right);
        }
        return false;
    }
    if (root->left)
    {
        if (root->left->key < root->key)
        {
            return areSubtreesBST(root->left);
        }
        return false;
    }
    if (root->right) 
    {
        if (root->key <= root->right->key)
        {
            return areSubtreesBST(root->right);
        }
        return false;
    }
}

bool isBST(Node* tree)
{
    if (!tree) { return true; }
    return areSubtreesBST(tree);
}
