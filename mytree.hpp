#ifndef MY_TREE_HPP
#define MY_TREE_HPP


class mytree
{
public:
    mytree *left;
    mytree *right;
    int val;

public:
    mytree(int val, mytree *left, mytree *right)
    {
        this->val = val;
        this->right = right;
        this->left = left;

    }

public:
    void in_traversal(mytree *node)
    {
        if(nullptr == node)
            return;

        in_traversal(node->left);
        cout<<node->val<<"\t";
        in_traversal(node->right);
    }

    void pre_traversal(mytree *node)
    {
        if(nullptr == node)
            return;

        cout<<node->val<<"\t";
        pre_traversal(node->left);
        pre_traversal(node->right);
    }

    void post_traversal(mytree *node)
    {
        if(nullptr == node)
            return;

        post_traversal(node->left);
        post_traversal(node->right);
        cout<<node->val<<"\t";
    }

    void layer_traversal(mytree *root)
    {
        if(nullptr == root)
            return;

        queue<mytree*> q;
        q.push(root);
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            cout<<root->val<<"\t";
            if(root->left)
                q.push(root->left);

            if(root->right)
                q.push(root->right);
        }
    }
};


//带有父节点的树
class ptree
{
public:
    ptree *parent;
    ptree *left;
    ptree *right;
    int val;

public:
    ptree(int val, ptree *left, ptree *right, ptree *parent)
    {
        this->val = val;
        this->right = right;
        this->left = left;
        this->parent = parent;
    }

public:
    void in_traversal(ptree *node)
    {
        if(nullptr == node)
            return;

        in_traversal(node->left);
        cout<<node->val<<"\t";
        in_traversal(node->right);
    }

    void pre_traversal(ptree *node)
    {
        if(nullptr == node)
            return;

        cout<<node->val<<"\t";
        pre_traversal(node->left);
        pre_traversal(node->right);
    }

    void post_traversal(ptree *node)
    {
        if(nullptr == node)
            return;

        post_traversal(node->left);
        post_traversal(node->right);
        cout<<node->val<<"\t";
    }


};

#endif
