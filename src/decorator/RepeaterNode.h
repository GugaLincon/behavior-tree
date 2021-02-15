#ifndef REPEATERNODE_H
#define REPEATERNODE_H

#include "DecoratorNode.h"


namespace behavior_tree {

/**
 * Represents a repeater node, a type of decorator.
 * Executes its child a given number of times, until failure.
 */
class RepeaterNode : public DecoratorNode {
public:
    /**
     * Repeater node constructor.
     * @param numRepetitions the max number of times the child can be executed.
     */
    explicit RepeaterNode(const int &numRepetitions);

    /**
     * Executes the enter() method of its child.
     */
    void enter() override;

    /**
     * Executes the child up to a given number, stopping at the
     * first non-SUCCESS return.
     * @return RUNNING, if an execution returns RUNNING.
     * @return FAILURE, if an execution returns FAILURE.
     * @return SUCCESS, if all of the executions return SUCCESS.
     */
    ExecutionStatus execute() override;

protected:
    int numRepetitions, counter;
};

}

#endif //REPEATERNODE_H