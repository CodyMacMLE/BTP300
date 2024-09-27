//
//  Settings.hpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

// Dependencies
#include <string>

namespace seneca {

/// <summary>
/// The settings will contain functionality regarding configuration of the application.
/// </summary>
struct Settings {
    /// <summary>
    /// When true, if a word has multiple definitions, all definitions should be printed on screen, otherwise
    /// only the first definition should be shown (default false)
    /// </summary>
    bool m_show_all;
    
    /// <summary>
    /// When true, print to screen the part-of-speech of a word if it exists (default false).
    /// </summary>
    bool m_verbose;
    
    /// <summary>
    /// Stores the time units to be used when printing duration of various operations. Possible values are
    /// seconds, milliseconds, microseconds, nanoseconds (default nanoseconds).
    /// </summary>
    std::string m_time_units;
};

extern Settings g_settings;

}
#endif /* SENECA_SETTINGS_H */
