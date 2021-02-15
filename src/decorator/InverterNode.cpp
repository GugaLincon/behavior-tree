#include "InverterNode.h"


namespace behavior_tree {

InverterNode::InverterNode() : DecoratorNode("Inverter Node") {
}

void InverterNode::enter() {
    child->enter();
}

ExecutionStatus InverterNode::execute() {
    ExecutionStatus result = child->execute();

    if (result == ExecutionStatus::SUCCESS) {
        return ExecutionStatus::FAILURE;
    } else if (result == ExecutionStatus::FAILURE) {
        return ExecutionStatus::SUCCESS;
    } else {
        return ExecutionStatus::RUNNING;
    }
}

}