#include "SequenceNode.h"

namespace behavior_tree {

SequenceNode::SequenceNode() : CompositeNode("Sequence Node") {
    runningChild = -1;
}

void SequenceNode::enter() {
    runningChild = -1;
}

ExecutionStatus SequenceNode::execute() {
    if (this->runningChild == -1) {
        runningChild = 0;
        children[runningChild]->enter();
    }

    while (true) {
        ExecutionStatus executionStatus = children[runningChild]->execute();

        if (executionStatus == ExecutionStatus::SUCCESS) {
            if (runningChild + 1 < children.size()) {
                runningChild++;
                children[runningChild]->enter();
            } else {
                runningChild = -1;
                return ExecutionStatus::SUCCESS;
            }
        } else if (executionStatus == ExecutionStatus::RUNNING) {
            return ExecutionStatus::RUNNING;
        } else if (executionStatus == ExecutionStatus::FAILURE) {
            runningChild = -1;
            return ExecutionStatus::FAILURE;
        }
    }
}

}