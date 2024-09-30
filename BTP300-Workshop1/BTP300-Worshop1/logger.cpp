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
            // 4) Shallow Copy
            m_arrSize = src.m_arrSize;
            m_events = src.m_events;
            // 5) Delete old ptr
            src.m_events = nullptr;
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
    /// resize array + 1
    /// </summary>
    void Logger::resizeArray() {
        // create tmp array and move
        Event* tmp = new Event[m_arrSize];
        for (auto i = 0; i < m_arrSize; i++)
            tmp[i] = m_events[i];
        // clean old array
        delete [] m_events;
        // resize array and copy old array
        m_events = new Event[m_arrSize + 1];
        for (auto i = 0; i < m_arrSize; i++)
            m_events[i] = tmp[i];
        // increment array size
        m_arrSize++;
        delete [] tmp;
    }
    
    /// <summary>
    /// Add to the array a copy of the event received as a parameter (resizing the array if necessary).
    /// </summary>
    void Logger::addEvent(const Event& event){
        this->resizeArray();
        m_events[m_arrSize - 1] = event;
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
