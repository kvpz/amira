#include "controlmandiblestask.hpp"

ControlMandiblesTask::ControlMandiblesTask(MandibleState desiredLeftState, 
                                           MandibleState desiredRightState,
                                           MandibleState currentLeftMandibleState,
                                           MandibleState currentRightMandibleState,
                                           XYPoint xy, double endpointOrientation)
    : Task(TaskType::CONTROLMANDIBLES, OBJECTSEARCHTASK_PRIORITY)
{
    desiredLeftMandibleState = desiredLeftState;
    desiredRightMandibleState = desiredRightState;
    actionPoint = xy;
    actionPointOrientation = endpointOrientation;
    inActionState = false;
}

void ControlMandiblesTask::notStarted(std::shared_ptr<Map> map, 
                        std::shared_ptr<Navigator> navigator, 
                        RobotState& nextRobotState)
{
    status = TaskStatus::INPROGRESS;
}

void ControlMandiblesTask::inProgress(std::shared_ptr<Map> map, 
                        std::shared_ptr<Navigator> navigator, 
                        RobotState& nextRobotState)
{
    // if robot is at the location this task requires it to be
    // and it is in the correct orientation, open mandible(s)
    // Proximity tolerance should be statically defined in settings.hpp

    bool isRobotNearActionPoint = 
        approximately(map->RobotX(), actionPoint.getX(), actionPointProximityTolerance) &&
        approximately(map->RobotY(), actionPoint.getY(), actionPointProximityTolerance);

    if(isRobotNearActionPoint || inActionState)
    {
        // start open/close of mandibles
        // set task state variable to indicate mandibles are being actuated
        inActionState = true;

        // open/close mandibles
        if(desiredLeftMandibleState == MandibleState::open &&
           desiredRightMandibleState == MandibleState::open) {
            // open right mandible on state machine tick
            // open left mandible on next state machine tick
        }
        else if(desiredLeftMandibleState == MandibleState::open &&
                desiredRightMandibleState == MandibleState::closed) {
            // open right mandible on state machine tick
            // open left mandible on state machine tick
            // close right mandible on state machine tick
        }
        else if(desiredLeftMandibleState == MandibleState::closed &&
                desiredRightMandibleState == MandibleState::open) {
            // open right mandible on state machine tick
        }
        else if(desiredLeftMandibleState == MandibleState::closed &&
                desiredRightMandibleState == MandibleState::closed) {
            // open right mandible on state machine tick
            // open left mandible on state machine tick
            // close right mandible on state machine tick
        }
    }
}

void ControlMandiblesTask::suspended(std::shared_ptr<Map> map, 
                        std::shared_ptr<Navigator> navigator, 
                        RobotState& nextRobotState, TaskType& nextTaskType)
{
    
}

void ControlMandiblesTask::complete(std::shared_ptr<Map> map, 
                        std::shared_ptr<Navigator> navigator, 
                        RobotState& nextRobotState, TaskType& nextTaskType)
{
    // mandibles should always be closed 
}