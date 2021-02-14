#ifndef FORCEFAILURENODE_H
#define FORCEFAILURENODE_H

#include "DecoratorNode.h"


namespace behavior_tree {

/**
 * Represents a force failure node, a type of decorator.
 * Executes its child, always returning failure in execution completion.
 */
class ForceFailureNode : public DecoratorNode {
public:
    /**
     * Default constructor.
     */
    ForceFailureNode();

    /**
     * Executes the enter() method of its child.
     */
    void enter() override;

    /**
     * Executes the child, return SUCCESS in conclusive executions.
     * @return RUNNING, if the child returns RUNNING.
     * Otherwise, always returns FAILURE.
     */
    ExecutionStatus execute() override;
};

}

#endif //FORCEFAILURENODE_H