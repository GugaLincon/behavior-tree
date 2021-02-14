#include "SelectorNode.h"

namespace behavior_tree {

SelectorNode::SelectorNode() : CompositeNode("Selector Node") {
    runningChild = -1;
}

void SelectorNode::enter() {
    // When this node is entered, no child should be running.
    runningChild = -1;
}

ExecutionStatus SelectorNode::execute() {
    if (this->runningChild == -1) {
        runningChild = 0;
        children[runningChild]->enter();
    }

    while (true) {
        ExecutionStatus executionStatus = children[runningChild]->execute();

        if (executionStatus == ExecutionStatus::SUCCESS) {
            runningChild = -1;
            return ExecutionStatus::SUCCESS;
        } else if (executionStatus == ExecutionStatus::RUNNING) {
            return ExecutionStatus::RUNNING;
        } else if (executionStatus == ExecutionStatus::FAILURE) {
            if (runningChild + 1 < children.size()) {
                runningChild++;
                children[runningChild]->enter();
            } else {
                runningChild = -1;
                return ExecutionStatus::FAILURE;
            }
        }
    }

}

}