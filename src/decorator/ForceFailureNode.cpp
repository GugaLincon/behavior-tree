#include "ForceFailureNode.h"


namespace behavior_tree {

ForceFailureNode::ForceFailureNode() : DecoratorNode("Force Failure Node") {
}

void ForceFailureNode::enter() {
    child->enter();
}

ExecutionStatus ForceFailureNode::execute() {
    if (child->execute() == ExecutionStatus::RUNNING) {
        return ExecutionStatus::RUNNING;
    } else {
        return ExecutionStatus::FAILURE;
    }
}

}