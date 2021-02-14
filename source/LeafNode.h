#ifndef LEAFNODE_H
#define LEAFNODE_H

#include "TreeNode.h"

namespace behavior_tree {

/**
 * Represents a leaf node.
 * This is the base class for behavior implementation.
 */
class LeafNode : public TreeNode {
public:
    /**
     * LeafNode constructor.
     * @param name the name of the leaf node.
     */
    explicit LeafNode(const std::string &name);
};

}

#endif //LEAFNODE_H