#include "BehaviorTreeBuilder.h"

namespace behavior_tree {

BehaviorTreeBuilder::BehaviorTreeBuilder() {
    currentParent = nullptr;
}

BehaviorTreeBuilder &BehaviorTreeBuilder::end() {
    if (currentParent->getParent() != nullptr) {
        currentParent = currentParent->getParent();
        treeHierarchy.pop();
    }

    return *this;
}

std::shared_ptr<BehaviorTree> BehaviorTreeBuilder::build() {
    return std::make_shared<BehaviorTree>(currentParent);
}

}
