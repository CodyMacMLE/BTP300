//
//  TimedTask.cpp
//  BTP300-W2
//
//  Created by Cody MacDonald on 2024-09-12.
//

#include <iomanip>
#include "TimedTask.h"

namespace seneca {

    ///  <summary>
    ///     Default Constructor
    ///  </summary>
    TimedTask::TimedTask() {
        m_currentNumTasks = 0;
    };
    
    ///  <summary>
    ///     A modifier that starts the timer for an event
    ///  </summary>
    void TimedTask::startClock() {
        m_startTime = std::chrono::steady_clock::now();
    };

    ///  <summary>
    ///     A modifier that stops the timer for an event
    ///  </summary>
    void TimedTask::stopClock() {
        m_endTime = std::chrono::steady_clock::now();
    };

    ///  <summary>
    ///     - Stores into the name attribute the C-style string received as parameter
    ///     - Stores "nanoseconds" as the units of time
    ///     - Calculates and stores the duration of the event
    ///     (use std::chrono::duration_cast<std::chrono::nanoseconds>()
    ///  </summary>
    ///  <param name='taskName'>
    ///     An address of a C-style null-terminated string that holds the name of the task
    ///  </param>
    void TimedTask::addTask(const std::string& taskName) {
        if (m_currentNumTasks < 10) {
            m_tasks[m_currentNumTasks].m_taskName = taskName;
            m_tasks[m_currentNumTasks].m_unitTime = "nanoseconds";
            m_tasks[m_currentNumTasks].m_durationOfTask = std::chrono::duration_cast<std::chrono::nanoseconds>(m_startTime - m_endTime);
        }
    };
        
    ///  <summary>
    ///     This operator should insert in the std::ostream object the records from the array in the
    ///     following format:
    ///         Execution Times:
    ///         --------------------------
    ///         TASK_NAME DURATION UNITS
    ///         T ASK_NAME DURATION UNITS
    ///         ...
    ///         --------------------------
    ///     The name of the task should be in a field of size 21, aligned on the left; the duration should be
    ///     in a field of size 13, aligned on the right.
    ///  </summary>
    ///  <param name='out'>
    ///     a reference to a ostream object
    ///  </param>
    ///  <param name='task'>
    ///     A timed task object
    ///  </param>
    std::ostream& operator<<(std::ostream& out, const TimedTask task) {
        out << "Execution Times:\n--------------------------" << std::endl;
        for (int i = 0; i < task.m_currentNumTasks; ++i) {
            out << std::setw(21) << std::left << task.m_tasks[i].m_taskName
            << std::setw(13) << std::right << task.m_tasks[i].m_durationOfTask << " " << task.m_tasks[i].m_unitTime << std::endl;
        }
        out << "--------------------------" << std::endl;
        return out;
    };
}
