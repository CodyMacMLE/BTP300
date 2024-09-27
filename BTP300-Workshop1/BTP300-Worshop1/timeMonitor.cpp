//
//  timeMoniter.cpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//
#include <chrono>
#include <string>
#include "timeMonitor.h"
#include "event.h"

namespace seneca {
    /// <summary>
    /// A new event with the name starts; records the time when the event started and the name of the event.
    /// </summary>
    void TimeMonitor::startEvent(const char* name){
        if (name != nullptr) {
            m_name = name;
        } else {
            m_name = "Error: No Name";
        }
        m_startTime = std::chrono::steady_clock::now();
    }
    
    /// <summary>
    /// The current event started earlier by a call to startEvent has ended; take the time when it ended,
    /// calculate the duration of the event, create an instance of type Event and return it to the client.
    /// </summary>
    Event TimeMonitor::stopEvent(){
        // End clock time
        m_endTime = std::chrono::steady_clock::now();
        // Casting clock time difference into a duration object
        std::chrono::duration<double> timeSpan = duration_cast<std::chrono::duration<double>>(m_endTime - m_startTime);
        // Casting duration to nanoseconds duration type
        std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(timeSpan);
        return Event(m_name, nanoseconds);
    }
}
