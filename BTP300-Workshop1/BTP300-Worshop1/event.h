//
//  Event.hpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

// Dependencies
#include <utility>

namespace seneca {
    /// <summary>
    /// Stores information about a single event that happened during the execution of the program.
    /// </summary>
    class Event {
        /// <summary>
        /// Name of the event
        /// </summary>
        const char* m_name;
        
        /// <summary>
        /// Duration of the event in nanoseconds
        /// </summary>
        std::chrono::nanoseconds m_duration;
    public:
        /// <summary>
        /// Default Constructor
        /// </summary>
        Event();
        
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name='name'>C-style array for the name of the event</param>
        /// <param name='duration'>Duration of event in nanoseconds</param>
        Event(const char* name, const std::chrono::nanoseconds& duration);
        
        /// <summary>
        /// Friendly operator to print an event to the ostream
        /// </summary>
        friend std::ostream& operator<<(std::ostream& out, Event& event);
    };
}
#endif /* SENECA_EVENT_H */
