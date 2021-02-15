#ifndef SEQUENCENODE_H
#define SEQUENCENODE_H

#include "CompositeNode.h"

namespace behavior_tree {

/**
 * Represents a sequence node.
 * A sequence ticks all its children as long as they return SUCCESS. If any child returns FAILURE,
 * the sequence is aborted, returning FAILURE.
 */
class SequenceNode : public CompositeNode {
public:
    /**
     * Default constructor.
     */
    SequenceNode();

    /**
     * Sets the first child to run on execution of the sequence node.
     */
    void enter() override;

    /**
     * Tries to execute all of its children, stopping at the first non-SUCCESS returned.
     * @return RUNNING, if a child returns RUNNING. FAILURE, if a child returns FAILURE. SUCCESS, if all children
     * return SUCCESS.
     */
    ExecutionStatus execute() override;

protected:
    int runningChild;
};

}

#endif //SEQUENCENODE_H