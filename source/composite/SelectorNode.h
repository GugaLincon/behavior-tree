#ifndef SELECTORNODE_H
#define SELECTORNODE_H

#include "CompositeNode.h"

namespace behavior_tree {

/**
 * Represents a selector node.
 * A selector ticks all its children as long as they return FAILURE. If any child returns SUCCESS,
 * the sequence is aborted, returning SUCCESS.
 */
class SelectorNode : public CompositeNode {
public:
    /**
     * Default constructor.
     */
    SelectorNode();

    /**
     * Sets the first child to run on the execution of the selector node.
     */
    void enter() override;

    /**
     * Tries to execute all of its children, stopping at the first non-FAILURE returned.
     * @return RUNNING, if a child returns RUNNING. SUCCESS, if a child returns SUCCESS. FAILURE, if all children
     * return FAILURE.
     */
    ExecutionStatus execute() override;

protected:
    int runningChild;
};

}

#endif //SELECTORNODE_H