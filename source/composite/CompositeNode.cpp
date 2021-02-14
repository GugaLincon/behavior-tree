#include "CompositeNode.h"

namespace behavior_tree {

CompositeNode::CompositeNode(const std::string &name) : TreeNode(name) {
}

void CompositeNode::addChild(const std::shared_ptr<TreeNode> &child) {
    this->children.emplace_back(child);
}

void CompositeNode::destroyNode() {
    this->parent = nullptr;
    for(const std::shared_ptr<TreeNode>& child : children) {
        child->destroyNode();
    }
}

}