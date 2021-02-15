#ifndef TREENODE_H
#define TREENODE_H

#include <memory>
#include <string>
#include "ExecutionStatus.h"

namespace behavior_tree {

/**
 * Represents a tree node.
 * Notice that this class is not for user implementation, but a base class to other nodes.
 */
class TreeNode {
public:
    /**
     * Tree node constructor.
     * @param name the name of the Node.
     */
    explicit TreeNode(const std::string &name);

    /**
     * This method is executed when the node is entered.
     * As a pure virtual method, all node classes must have this method implemented.
     */
    virtual void enter() = 0;

    /**
     * This method represents the standard execution of the node.
     * As a pure virtual method, all node classes must have this method implemented.
     * @return an execution status, based on the method implementation.
     */
    virtual ExecutionStatus execute() = 0;

    /**
     * Gets the parent of the node.
     * @return a pointer to the parent of the node.
     */
    std::shared_ptr<TreeNode> getParent();

    /**
     * Sets the parent of the node.
     * @param newParent the parent of the node.
     */
    void setParent(const std::shared_ptr<TreeNode> &newParent);

    /**
     * Gets the name of the node.
     * @return the name of the node.
     */
    std::string getName();

    /**
     * Acts as an auxiliary function to the recursive destruction of the tree.
     */
     virtual void destroyNode();

protected:
    std::string name;
    std::shared_ptr<TreeNode> parent = nullptr;
};

}

#endif //TREENODE_H