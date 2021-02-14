#include "BehaviorTree.h"

namespace behavior_tree {

BehaviorTree::BehaviorTree(const std::shared_ptr<TreeNode> &root) : root(root) {
}

ExecutionStatus BehaviorTree::update() {
    return root->execute();
}

BehaviorTree::~BehaviorTree() {
    root->destroyNode();
}

}
