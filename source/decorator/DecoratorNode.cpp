#include "DecoratorNode.h"


namespace behavior_tree {

DecoratorNode::DecoratorNode(const std::string &name) : TreeNode(name) {
}

void DecoratorNode::setChild(const std::shared_ptr<TreeNode> &decoratorChild) {
    this->child = decoratorChild;
}

void DecoratorNode::destroyNode() {
    this->parent = nullptr;
    child->destroyNode();
}

}