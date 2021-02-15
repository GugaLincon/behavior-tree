#ifndef DECORATORNODE_H
#define DECORATORNODE_H

#include "../TreeNode.h"


namespace behavior_tree {

/**
 * Represents a decorator node base class.
 */
class DecoratorNode : public TreeNode {
public:
    /**
     * DecoratorNode constructor.
     * @param name the name of the decorator node.
     */
    explicit DecoratorNode(const std::string &name);

    /**
     * Sets the child of the decorator node
     * @param decoratorChild the child of the decorator node.
     */
    void setChild(const std::shared_ptr<TreeNode> &decoratorChild);

    /**
     * Acts as an auxiliary function to the recursive destruction of the tree.
     */
    void destroyNode() override;

protected:
    std::shared_ptr<TreeNode> child;
};

}
#endif //DECORATORNODE_H