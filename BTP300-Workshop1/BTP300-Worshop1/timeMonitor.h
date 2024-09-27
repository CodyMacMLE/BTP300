//
//  timeMoniter.hpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <string>
#include "event.h"

namespace seneca {
    class TimeMonitor {
        /// <summary>
        /// Stores name of current event
        /// </summary>
        const char* m_name;
        
        /// <summary>
        /// Stores start time of the event
        /// </summary>
        std::chrono::steady_clock::time_point m_startTime;
        
        /// <summary>
        /// Stores endtime of the event
        /// </summary>
        std::chrono::steady_clock::time_point m_endTime;
        public:
        /// <summary>
        /// A new event with the name starts; records the time when the event started and the name of the
        /// event.
        /// </summary>
        void startEvent(const char* name);
        
        /// <summary>
        /// The current event started earlier by a call to startEvent has ended; take the time when it ended,
        /// calculate the duration of the event, create an instance of type Event and return it to the client.
        /// </summary>
        Event stopEvent();
        
    };
}
#endif /* SENECA_TIMEMONITOR_H */
