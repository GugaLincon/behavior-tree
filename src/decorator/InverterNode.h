#ifndef INVERTERNODE_H
#define INVERTERNODE_H

#include "DecoratorNode.h"


namespace behavior_tree {

/**
 * Represents a inverts node, a type of decorator.
 * Inverts the result of its child execution.
 */
class InverterNode : public DecoratorNode {
public:
    /**
     * Default constructor.
     */
    InverterNode();

    /**
     * Executes the enter() method of its child.
     */
    void enter() override;

    /**
     * Executes the child, inverting the result.
     * @return RUNNING, if the child returns RUNNING.
     * SUCCESS, if the child returns FAILURE.
     * FAILURE, if the child returns SUCCESS.
     */
    ExecutionStatus execute() override;
};

}

#endif //INVERTERNODE_H