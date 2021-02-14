#ifndef EXECUTIONSTATUS_H
#define EXECUTIONSTATUS_H

namespace behavior_tree {

/**
 * This enum class represents the execution status returned by a given node of a behavior tree. It is used to control
 * the execution flow of the behavior tree. All execute() methods of implemented nodes must return an
 * ExecutionStatus: SUCCESS, FAILURE ou RUNNING.
 */
enum class ExecutionStatus {
    SUCCESS = 0,
    FAILURE = 1,
    RUNNING = 2,
};

}

#endif //EXECUTIONSTATUS_H
