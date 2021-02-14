#include "RetryNode.h"


namespace behavior_tree {

RetryNode::RetryNode(const int &numRetrials) : DecoratorNode("Retry Node"), numRetrials(numRetrials) {
    counter = 0;
}

void RetryNode::enter() {
    counter = 0;
    child->enter();
}

ExecutionStatus RetryNode::execute() {
    ExecutionStatus result;

    while (counter < numRetrials) {
        result = child->execute();

        if (result != ExecutionStatus::FAILURE) {
            break;
        }

        if (counter + 1 < numRetrials) {
            child->enter();
        }
        counter++;
    }

    return result;
}

}