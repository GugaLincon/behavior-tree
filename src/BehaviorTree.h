#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "TreeNode.h"

namespace behavior_tree {

/**
 * Represents a behavior tree.
 */
class BehaviorTree {
public:
    /**
     * Behavior Tree constructor.
     * @param root the root of the behavior tree.
     */
    explicit BehaviorTree(const std::shared_ptr<TreeNode> &root);

    /**
     * Executes the root node.
     */
    ExecutionStatus update();

    /**
     * This destructor is responsible for starting the recursive destruction of the behavior tree nodes.
     */
     ~BehaviorTree();

protected:
    std::shared_ptr<TreeNode> root;
};
}

#endif //BEHAVIORTREE_H
