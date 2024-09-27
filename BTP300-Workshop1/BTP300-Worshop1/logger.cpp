//
//  logger.cpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//
#include <iostream>
#include <utility>
#include "logger.h"

namespace seneca {
    /// <summary>
    /// Default constructor.
    /// </summary>
    Logger::Logger(){
        m_events = nullptr;
        m_arrSize = 0;
    }

    /// <summary>
    /// Move Constructor
    /// </summary>
    Logger::Logger(Logger&& src){
        *this = std::move(src);
    }
    
    /// <summary>
    /// Move Assignment
    /// </summary>
    Logger& Logger::operator=(Logger&& src){
        // 1) Self-Assign Guard
        if(this != &src) {
            // 2) Clean memory
            delete [] m_events;
            // 3) Shallow Copy Static(No static members)
            // 4) Shallow Copy Dynamic
            m_events = src.m_events;
            // 5) Delete old ptr
            delete [] src.m_events;
        }
        return *this;
    }
    
    /// <summary>
    /// Default destructor.
    /// </summary>
    Logger::~Logger(){
        delete [] m_events;
    }
    
    /// <summary>
    /// Add to the array a copy of the event received as a parameter (resizing the array if necessary).
    /// </summary>
    void Logger::addEvent(const Event& event){
        // Creating new array of events with new event
        Event* tmp = new Event[m_arrSize + 1];
        // Copying array content + new event to tmp array
        if (m_arrSize == 0)
            tmp[m_arrSize++] = event; // Incrementing array size after call
        else {
            tmp = m_events;
            tmp[m_arrSize++] = event;
        }
        // Clearing old array
        delete [] m_events;
        // Copy new array to object
        this->m_events = new Event[m_arrSize];
        for (auto i = 0; i < m_arrSize; ++i)
            this->m_events[i] = tmp[i];                                 // is copied into m_events, but when it goes out of scope both go null
    }
    
    /// <summary>
    /// Print to the screen all the events stored in the logger
    /// </summary>
    std::ostream& operator<<(std::ostream& out, Logger& logs){
        for (auto i = 0; i < logs.m_arrSize; ++i){
            out << logs.m_events[i] << std::endl;
        }
        return out;
    }
}
