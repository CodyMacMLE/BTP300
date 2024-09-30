//
//  Event.cpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//

#include <iostream>
#include <iomanip>
#include <utility>
#include <chrono>
#include "event.h"
#include "settings.h"

namespace seneca {
    
    /// <summary>
    /// Default Constructor {m_name = ""}
    /// </summary>
    Event::Event(){
        m_name = "";
    }
        
    /// <summary>
    /// Name of the event
    /// </summary>
    Event::Event(const char* name, const std::chrono::nanoseconds& duration){
        Event();
        if (name != nullptr) {
            m_name = name;
        }
        if (duration.count() != 0) {
            m_duration = duration;
        }
    }
    
    /// <summary>
    /// Move Constructor
    /// </summary>

    /// <summary>
    /// Print an event with the following format:
    /// COUNTER: EVENT_NAME -> DURATION TIME_UNITS
    /// </summary>
    std::ostream& operator<<(std::ostream& out, Event& event){
        static int counter = 1;
        out << std::setw(2) << std::right << counter << ": "
            << std::setw(40) << event.m_name << " -> ";
        
        if (g_settings.m_time_units == "seconds") {
            std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(event.m_duration);
            out << std::setw(2) << time.count() << " seconds";
        } else if (g_settings.m_time_units == "milliseconds") {
            std::chrono::milliseconds time = std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration);
            out << std::setw(5) << time.count() << " milliseconds";
        } else if (g_settings.m_time_units == "microseconds") {
            std::chrono::microseconds time = std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration);
            out << std::setw(8) << time.count() << " microseconds";
        } else if (g_settings.m_time_units == "nanoseconds") {
            std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(event.m_duration);
            out << std::setw(11) << time.count() << " nanoseconds";
        }
        
        counter++;
        return out;
    }
}
