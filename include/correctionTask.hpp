#ifndef CORRECTIONTASK_HPP
#define CORRECTIONTASK_HPP
//#include "robot.hpp"
#include "task.hpp"
#include "enums/robotPoseToWaypoint.hpp"
#include "map.hpp"

//class Robot;

class CorrectionTask : public Task
{
public:
    CorrectionTask(){}

    // Task subtasks

    virtual void notStarted(Map* map, Navigator* navigator, RobotState& robotState) override;

    virtual void inProgress(Map* map, Navigator* navigator, RobotState& robotState) override;

    virtual void suspended() override;

    virtual void complete() override;

private:
    RobotState robotState; // ex. MOVE_BACKWARD
    double angleToDestTolerance = 10.0;
    bool correcting_position = false;        

};

#endif