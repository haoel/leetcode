//
//  Tree.hpp
//  Docker_Dependencies
//
//  Created by Wang Yi on 7/4/17.
//  Copyright © 2017 Wang Yiyiak.co. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
using std::vector;
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using std::unordered_map;
using std::pair;
using std::stack;
using std::queue;
using std::set;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

class TreeNode {
public:
    TreeNode(string name):img(name), parent(nullptr), m_pos(0){};
    TreeNode(const TreeNode& nd)
    {
        if (this != &nd)
        {
            this->img = nd.img;
            this->children = nd.children;
            this->parent = nd.parent;
            this->m_pos = nd.m_pos;
        }
    }
    
    TreeNode& operator = (const TreeNode& nd){
        if (this != &nd)
        {
            this->img = nd.img;
            this->children = nd.children;
            this->parent = nd.parent;
            this->m_pos = nd.m_pos;
        }
        return *this;
    }
    
    virtual ~TreeNode(){
        for (auto child : children){
            delete child;
        }
    };
    
    void add(TreeNode* child){children.push_back(child);};
    void set_pos(int pos){this->m_pos = pos;};
    
    vector<TreeNode*> wfs();
    // please refer to this question: http://stackoverflow.com/questions/1549930/c-equivalent-of-java-tostring for more details
    string _str() const {return string(" Node: <") + this->img + string("> ");}
    virtual std::ostream& dump(std::ostream& o) const {
        return o << _str();
    }
    
    string img;
    vector<TreeNode*> children;
    TreeNode* parent;
    int m_pos;
    
};

std::ostream& operator<<(std::ostream& o, const TreeNode& t);

vector<TreeNode*>& build_children(TreeNode* parent, vector<string> imgs, unordered_map<string, TreeNode*> visited);
vector<TreeNode*> build_Tree_Merged(vector<pair<string, string>>& edges);
shared_ptr<vector<string>> DockerBuildDependency(vector<pair<string, string>>& Relation);

#define TAIL "└──"
#define NORMAL_NODE "├──"
#define INDENT_PREFIX          "|   "
#define INDENT_PREFIX_FOR_LAST "    "
#define ROOT_PREFIX            "───"
#define INDENT_STEP 3

template <class Tree> class _tree_node_printer {
public:
    _tree_node_printer(Tree* t=nullptr): m_tree(t){};
    _tree_node_printer(const _tree_node_printer& nd)
    {
        if (this != &nd)
        {
            m_tree = nd.m_tree;
            prefix = nd.prefix;
            isRoot = nd.isRoot;
            isTail = nd.isTail;
        }
    }
    
    _tree_node_printer& operator = (const _tree_node_printer& nd)
    {
        if (this != &nd)
        {
            m_tree = nd.m_tree;
            prefix = nd.prefix;
            isRoot = nd.isRoot;
            isTail = nd.isTail;
        }
        return *this;
    }
    
    virtual ~_tree_node_printer()
    {
        for (auto child : children){
            delete child;
        }
    }
    
    string _str();
    vector<_tree_node_printer*> build_children()
    {
        if (m_tree->children.size() != 0 && children.size() == 0)
        {
            int i=0;
            for (i=0; i < m_tree->children.size() - 1; i++)
            {
                Tree* child = m_tree->children[i];
                _tree_node_printer* nd = new _tree_node_printer(child);
                nd->prefix = string(NORMAL_NODE);
                children.push_back(nd);
            }
            
            if (m_tree->children.size() - 1 >= 0)
            {
                Tree* child = m_tree->children[m_tree->children.size() - 1];
                _tree_node_printer* nd = new _tree_node_printer(child);
                nd->prefix = string(TAIL);
                nd->isTail = true;
                children.push_back(nd);
            }
            
        }
        
        return children;
    }
    
    virtual std::ostream& dump(std::ostream& o) {
        return o << _str();
    }
    
private:
    Tree* m_tree;
    
    // fmt info
    string prefix = "";
    string indent = "";
    bool isRoot = false;
    bool isTail = false;
    
    vector<_tree_node_printer*> children;
};

typedef _tree_node_printer<TreeNode> TreeNodePrinter;

template <class Tree>
string
_tree_node_printer<Tree>::_str() {
    vector<string> temp;
    string ret;
    stack<_tree_node_printer<Tree>*> s;
    
    this->prefix = string("\n") + string(ROOT_PREFIX);
    this->isRoot = true;
    this->isTail = true;
    
    s.push(this);
    vector<_tree_node_printer*> children;
    _tree_node_printer* curr=nullptr;

    
    while(!s.empty())
    {
        curr = s.top(); s.pop();
        string indent = curr->indent;
        
        // visit func
        temp.push_back(indent + curr->prefix + curr->m_tree->_str() + string("\n"));
        
        auto children = curr->build_children();
        std::reverse(children.begin(), children.end());
        for(auto child : children)
        {
            string curr_indent = curr->isTail == true ? string(INDENT_PREFIX_FOR_LAST) : string(INDENT_PREFIX);
            child->indent = indent + curr_indent;
            s.push(child);
        }
        
    }
    
    // we can use boost::algorithm::join(vec, delim) here
    for (string el : temp)
    {
        ret += el;
    }
    return ret;
}

#endif /* Tree_hpp */
