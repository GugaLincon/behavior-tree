#ifndef FORCESUCCESSNODE_H
#define FORCESUCCESSNODE_H

#include "DecoratorNode.h"


namespace behavior_tree {

/**
 * Represents a force success node, a type of decorator.
 * Executes its child, always returning success in execution completion
 */
class ForceSuccessNode : public DecoratorNode {
public:
    /**
     * Default constructor.
     */
    ForceSuccessNode();

    /**
     * Executes the enter() method of its child.
     */
    void enter() override;

    /**
     * Executes the child, return SUCCESS in conclusive executions.
     * @return RUNNING, if the child returns RUNNING.
     * Otherwise, always returns SUCCESS.
     */
    ExecutionStatus execute() override;
};

}

#endif //FORCESUCCESSNODE_H