#ifndef BEHAVIORTREEBUILDER_H
#define BEHAVIORTREEBUILDER_H

#include "BehaviorTree.h"

#include "decorator/ForceFailureNode.h"
#include "decorator/InverterNode.h"
#include "decorator/ForceSuccessNode.h"
#include "decorator/RepeaterNode.h"
#include "decorator/RetryNode.h"
#include "composite/SelectorNode.h"
#include "composite/SequenceNode.h"
#include "LeafNode.h"
#include <stack>

namespace behavior_tree {

/**
 * An enum to control the construction of the hierarchy of the behavior tree.
 */
enum ParentType {
        COMPOSITE,
        DECORATOR
};

/**
 * Represents a builder class of a behavior tree.
 */
class BehaviorTreeBuilder {
public:
    /**
     * Default constructor.
     */
    BehaviorTreeBuilder();

    /**
     * Adds a leaf node as a child of the current father.
     * @tparam leafType the leaf class type.
     * @tparam Types the types of the leaf's constructor.
     * @param arguments the arguments of the leaf's constructor.
     * @return the BehaviorTreeBuilder object, for recursive purposes of the builder.
     */
    template<typename leafType, typename ... Types>
    BehaviorTreeBuilder &leaf(Types... arguments) {
        std::shared_ptr<LeafNode> newLeaf = std::make_shared<leafType>(arguments...);
        newLeaf->setParent(currentParent);

        if (treeHierarchy.top() == COMPOSITE) {
            std::static_pointer_cast<CompositeNode>(currentParent)->addChild(newLeaf);
        } else if (treeHierarchy.top() == DECORATOR) {
            std::static_pointer_cast<DecoratorNode>(currentParent)->setChild(newLeaf);
        }

        return *this;
    };

    /**
     * Adds a composite node as a child of the current father, if a father exists.
     * Then, sets this composite node as the current father.
     * @tparam compositeType the composite class type.
     * @tparam Types the types of the composite's constructor.
     * @param arguments the arguments of the composite's constructor
     * @return the BehaviorTreeBuilder object, for recursive purposes of the builder.
     */
    template<class compositeType, typename ... Types>
    BehaviorTreeBuilder &composite(Types... arguments) {
        std::shared_ptr<CompositeNode> newComposite = std::make_shared<compositeType>(arguments...);
        newComposite->setParent(currentParent);

        if (!treeHierarchy.empty() && treeHierarchy.top() == COMPOSITE) {
            std::static_pointer_cast<CompositeNode>(currentParent)->addChild(newComposite);
        } else if (!treeHierarchy.empty() && treeHierarchy.top() == DECORATOR) {
            std::static_pointer_cast<DecoratorNode>(currentParent)->setChild(newComposite);
        }

        currentParent = newComposite;
        treeHierarchy.emplace(COMPOSITE);

        return *this;
    };

    /**
     * Adds a decorator node as a child of the current father, if a father exists.
     * Then, sets this decorator node as the current father.
     * @tparam decoratorType the decorator class type.
     * @tparam Types the types of the decorator's constructor.
     * @param arguments the arguments of the decorator's constructor
     * @return the BehaviorTreeBuilder object, for recursive purposes of the builder.
     */
    template<typename decoratorType, typename ... Types>
    BehaviorTreeBuilder &decorator(Types... arguments) {
        std::shared_ptr<DecoratorNode> newDecorator = std::make_shared<decoratorType>(arguments...);
        newDecorator->setParent(currentParent);

        if (!treeHierarchy.empty() && treeHierarchy.top() == COMPOSITE) {
            std::static_pointer_cast<CompositeNode>(currentParent)->addChild(newDecorator);
        } else if (!treeHierarchy.empty() && treeHierarchy.top() == DECORATOR) {
            std::static_pointer_cast<DecoratorNode>(currentParent)->setChild(newDecorator);
        }

        currentParent = newDecorator;
        treeHierarchy.emplace(DECORATOR);

        return *this;
    };

    /**
     * Sets the previous father as the current father.
     * @return the BehaviorTreeBuilder object, for recursive purposes of the builder.
     */
    BehaviorTreeBuilder &end();

    /**
     * Builds the behavior tree with root on the current father, returning a pointer to the created behavior tree.
     * @return a pointer to the behavior tree.
     */
    std::shared_ptr<BehaviorTree> build();

protected:
    std::stack<ParentType> treeHierarchy;
    std::shared_ptr<TreeNode> currentParent;
};

}

#endif //BEHAVIORTREEBUILDER_H
