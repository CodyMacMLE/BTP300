//
//  ProteinDataBase.h
//  BTP300-W2
//
//  Created by Cody MacDonald on 2024-09-12.
//

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <stdio.h>
#include <string>

namespace seneca {
    class ProteinDatabase {
        std::string* m_uid;
        std::string* m_aminoSequence;
        int m_numSequences;
    public:
        /// <summary>
        ///     Default Constructor
        /// </summary>
        ProteinDatabase();
        
        /// <summary>
        ///     File Constructor
        /// </summary>
        /// <param name='file'>
        ///    A string containing the name of a file from which this member function populates the
        ///    current object
        /// </param>
        ProteinDatabase(const std::string file);
        
        // Rule-of-5 Start

        /// <summary>
        ///     Copy Constructor
        /// </summary>
        ProteinDatabase(const ProteinDatabase& src);
        
        /// <summary>
        ///     Move Constructor
        /// </summary>
        ProteinDatabase(ProteinDatabase&& src);
        
        /// <summary>
        ///     Copy Assignment
        /// </summary>
        ProteinDatabase& operator=(const ProteinDatabase& src);
        
        /// <summary>
        ///     Move Assignment
        /// </summary>
        ProteinDatabase& operator=(ProteinDatabase&& src);
        
        /// <summary>
        ///     Destructor
        /// </summary>
        ~ProteinDatabase();
        
        // Rule-of-5 End
        
        /// <summary>
        ///     A query that returns the number of protein sequences stored in the current object
        /// </summary>
        size_t size() const;
        
        /// <summary>
        ///     A query that returns a copy of the protein sequence at the index received as the function
        ///     parameter. If the index is invalid, this function should return an empty string.
        /// </summary>
        std::string operator[](const size_t index) const;
        
        /// <summary>
        ///     A query that returns a copy of the protein ID at the index received as the function parameter.
        ///     If the index is invalid, this function should return "None"
        /// </summary>
        std::string getUID(const size_t index) const;
        
    };
}
#endif /* SENECA_PROTEINDATABASE_H */
