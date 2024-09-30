//
//  logger.hpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include <iostream>
#include <chrono>
#include "event.h"

namespace seneca {
    class Logger {
        /// <summary>
        /// Dynamically allocated collection of events in the form of an array.
        /// </summary>
        Event* m_events;
        
        /// <summary>
        ///  Stores current size of the array (Int)
        ///  </summary>
        int m_arrSize;
    public:
        /// <summary>
        /// Default constructor.
        /// </summary>
        Logger();
        
        /// <summary>
        /// Disabling Copy Constructor
        /// </summary>
        Logger(Logger&) = delete;
        
        /// <summary>
        /// Disabling Copy Assignment
        /// </summary>
        Logger& operator=(Logger&) = delete;
        
        /// <summary>
        /// Move Constructor
        /// </summary>
        Logger(Logger&& src);
        
        /// <summary>
        /// Move Assignment
        /// </summary>
        Logger& operator=(Logger&& src);
        
        
        /// <summary>
        /// Default destructor.
        /// </summary>
        ~Logger();
        
        /// <summary>
        /// resize array + 1
        /// </summary>
        void resizeArray();
        
        /// <summary>
        /// Add to the array a copy of the event received as a parameter (resizing the array if necessary).
        /// </summary>
        void addEvent(const Event& event);
        
        /// <summary>
        /// Print to the screen all the events stored in the logger
        /// </summary>
        friend std::ostream& operator<<(std::ostream& out, Logger& logs);
    };
}
#endif /* SENECA_LOGGER_H */
