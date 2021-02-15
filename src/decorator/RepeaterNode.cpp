#include "RepeaterNode.h"


namespace behavior_tree {

RepeaterNode::RepeaterNode(const int &numRepetitions) : DecoratorNode("Repeater Node"), numRepetitions(numRepetitions) {
    counter = 0;
}

void RepeaterNode::enter() {
    counter = 0;
    child->enter();
}

ExecutionStatus RepeaterNode::execute() {
    ExecutionStatus result;

    while (counter < numRepetitions) {
        result = child->execute();

        if (result != ExecutionStatus::SUCCESS) {
            break;
        }

        if (counter + 1 < numRepetitions) {
            child->enter();
        }
        counter++;
    }

    return result;
}

}