#include "TreeNode.h"

namespace behavior_tree {

TreeNode::TreeNode(const std::string &name) : name(name) {
}

std::shared_ptr<TreeNode> TreeNode::getParent() {
    return this->parent;
}

void TreeNode::setParent(const std::shared_ptr<TreeNode> &newParent) {
    this->parent = newParent;
}

std::string TreeNode::getName() {
    return this->name;
}

void TreeNode::destroyNode() {
    this->parent = nullptr;
}

}
