#ifndef RETRYNODE_H
#define RETRYNODE_H

#include "DecoratorNode.h"


namespace behavior_tree {

/**
 * Represents a retry node, a type of decorator.
 * Executes its child a given number of times, until success.
 */
class RetryNode : public DecoratorNode {
public:
    /**
     * Retry node constructor.
     * @param numRetrials the max number of times the child can be executed.
     */
    explicit RetryNode(const int &numRetrials);

    /**
     * Executes the enter() method of its child.
     */
    void enter() override;

    /**
     * Executes the child up to a given number, stopping at the
     * first non-FAILURE return.
     * @return RUNNING, if an execution returns RUNNING. SUCCESS, if an execution returns SUCCESS.
     * FAILURE, if all of the executions return FAILURE.
     */
    ExecutionStatus execute() override;

protected:
    int numRetrials, counter;
};

}

#endif //RETRYNODE_H