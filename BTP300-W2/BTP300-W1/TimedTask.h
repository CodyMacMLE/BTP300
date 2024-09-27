//
//  TimedTask.h
//  BTP300-W2
//
//  Created by Cody MacDonald on 2024-09-12.
//

#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <stdio.h>
#include <string>
#include <chrono>

namespace seneca {
    /// <summary>
    /// A struct that holds the info of a task
    /// </summary>
    struct Task {
        std::string m_taskName;
        std::string m_unitTime;
        std::chrono::steady_clock::duration m_durationOfTask;
    };

    /// <summary>
    ///  A class that handles a static array of Task objects
    /// </summary>
    class TimedTask {
        int m_currentNumTasks;
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
        Task m_tasks[10];
    public:
        // Default Constructor
        TimedTask();
        
        ///  <summary>
        ///  A modifier that starts the timer for an event
        ///  </summary>
        void startClock();
        
        ///  <summary>
        ///  A modifier that stops the timer for an event
        ///  </summary>
        void stopClock();
        
        ///  <summary>
        ///  - Stores into the name attribute the C-style string received as parameter
        ///  - Stores "nanoseconds" as the units of time
        ///  - Calculates and stores the duration of the event
        ///    (use std::chrono::duration_cast<std::chrono::nanoseconds>()
        ///  </summary>
        ///  <param name='taskName'>
        ///  An address of a C-style null-terminated string that holds the name of the task
        ///  </param>
        void addTask(const std::string& taskName);
        
        ///  <summary>
        ///  This operator should insert in the std::ostream object the records from the array in the following format:
        ///     Execution Times:
        ///     --------------------------
        ///     TASK_NAME DURATION UNITS
        ///     TASK_NAME DURATION UNITS
        ///     ...
        ///     --------------------------
        ///  The name of the task should be in a field of size 21, aligned on the left; the duration should be in a field of size 13, aligned on the right.
        ///  </summary>
        ///  <param name='out'>
        ///     a reference to a ostream object
        ///  </param>
        ///  <param name='task'>
        ///     A timed task object
        ///  </param>
        friend std::ostream& operator<<(std::ostream& out, const TimedTask task);
    };

    
}
#endif /* SENECA_TIMEDTASK_H */
