//
//  Tree.cpp
//  Docker_Dependencies
//
//  Created by Wang Yi on 7/4/17.
//  Copyright © 2017 Wang Yiyiak.co. All rights reserved.
//

#include "Tree.hpp"
std::ostream& operator<<(std::ostream& o, const TreeNode& t)
{
    return t.dump(o);
}

vector<TreeNode*>
TreeNode::wfs()
{
    vector<TreeNode*> ret;
    queue<TreeNode*> q;
    q.push(this);
    vector<TreeNode*> children;
    int depth = 1;
    TreeNode* curr = nullptr;
    int curr_no = 1, next_no = 0;
    
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        
        // visit
        ret.push_back(curr);
        curr_no --;
        
        auto children = curr->children;
        next_no += (int)children.size();
        
        if (curr_no == 0){
            depth++;
            curr_no = next_no;
            next_no = 0;
        }
        
        for(auto child : children)
        {
            q.push(child);
        }
        
    }
    
    return ret;

}

// typedef _treenode TreeNode;

vector<TreeNode*>& build_children(TreeNode* parent, vector<string> imgs, unordered_map<string, TreeNode*> visited)
{
    int i=0;
    for(i=0; i<imgs.size(); i++)
    {
        TreeNode* nd = nullptr;
        // if the node is the root of another tree
        if (visited.find(imgs[i]) != visited.end()){
            nd = visited[imgs[i]];
        } else {
            nd = new TreeNode(imgs[i]);
        }
        nd->set_pos(i);
        nd->parent = parent;
        parent->children.push_back(nd);
        
    }
    return parent->children;
}

vector<TreeNode*> build_Tree_Merged(vector<pair<string, string>>& edges)
{
    unordered_map<string, vector<string>> g_edges;
    stack<TreeNode*> s;
    unordered_map<string, TreeNode*> visited;
    TreeNode* curr;
    TreeNode* p;
    vector<TreeNode*> forest;
    vector<TreeNode*> ret;
    TreeNode sentinel("Sentinel") ;
    
    for(auto edge : edges)
    {
        // base tree or directed graph egdes build
        string name = edge.second;
        if(g_edges.find(name) != g_edges.end())
        {
            g_edges[name].push_back(edge.first);
        } else {
            vector<string> children(1, edge.first);
            g_edges[name] = children;
            forest.push_back(new TreeNode(name));
        }
    }
    
    // merge trees
    for(auto tree: forest){
        s.push(tree);
        
        while(!s.empty()){
            curr = s.top(); s.pop();
            if (visited.find(curr->img) != visited.end())
            {
                // a circle find
                p = curr->parent;
                if (p != nullptr)
                    p->children.erase(p->children.begin() + curr->m_pos);
                else { curr->parent = &sentinel; curr->set_pos(sentinel.m_pos++); }
                continue;
            }
            visited[curr->img] = curr;
            vector<string> imgs = g_edges[curr->img];
            auto children = build_children(curr, imgs, visited);
            for (auto child : children){ s.push(child); }
            
        } // end while
        
    } // end for
    
    // be considered susptect for copy cost
    for(auto tree : forest){
        if (tree->parent == nullptr){
            TreeNodePrinter tnp(tree);
            std::cout << "------" << std::endl;
            std::cout << tnp._str();
            ret.push_back(tree);
        }
    }
    
    return ret;
}

shared_ptr<vector<string>> DockerBuildDependency(vector<pair<string, string>>& Relation)
{
    shared_ptr<vector<string>> ret(new vector<string>());
    vector<TreeNode*> forest = build_Tree_Merged(Relation);
    for (auto tree : forest)
    {
        vector<TreeNode*> nd_seq = tree->wfs();
        vector<string> imgs_seq;
        for(auto nd : nd_seq)
        {
            imgs_seq.push_back(nd->img);
        }
        ret->insert(ret->end(), imgs_seq.begin(), imgs_seq.end());
    }
    return ret;
}
