#ifndef COMPOSITENODE_H
#define COMPOSITENODE_H

#include "../TreeNode.h"
#include <vector>

namespace behavior_tree {

/**
 * Represents a composite note base class.
 */
class CompositeNode : public TreeNode {
public:
    /**
     * CompositeNode constructor.
     * @param name the name of the composite node.
     */
    explicit CompositeNode(const std::string &name);

    /**
     * Adds a child to the composite node.
     * @param child the child to be added to the composite node.
     */
    void addChild(const std::shared_ptr<TreeNode> &child);

    /**
     * Acts as an auxiliary function to the recursive destruction of the tree.
     */
    void destroyNode() override;

protected:
    std::vector<std::shared_ptr<TreeNode>> children;

};

}

#endif //COMPOSITENODE_H