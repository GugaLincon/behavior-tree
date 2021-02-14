#include "ForceSuccessNode.h"


namespace behavior_tree {

ForceSuccessNode::ForceSuccessNode() : DecoratorNode("Force Success Node") {
}

void ForceSuccessNode::enter() {
    child->enter();
}

ExecutionStatus ForceSuccessNode::execute() {
    if (child->execute() == ExecutionStatus::RUNNING) {
        return ExecutionStatus::RUNNING;
    } else {
        return ExecutionStatus::SUCCESS;
    }
}

}