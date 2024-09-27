//
//  ProteinDataBase.cpp
//  BTP300-W2
//
//  Created by Cody MacDonald on 2024-09-12.
//

#include <fstream>
#include <iostream>
#include "ProteinDatabase.h"

namespace seneca {
    /// <summary>
    ///     Default Constructor
    /// </summary>
    ProteinDatabase::ProteinDatabase() {
        m_uid = nullptr;
        m_aminoSequence = nullptr;
        m_numSequences = 0;
    }

    /// <summary>
    ///     File Constructor
    /// </summary>
    /// <param name='file'>
    ///    A string containing the name of a file from which this member function populates the
    ///    current object
    /// </param>
    ProteinDatabase::ProteinDatabase(const std::string file){
        std::ifstream proteinFile(file);
        if (proteinFile.good()) {
            // Counting Number of Protein Sequences
            std::string buffer;
            while (!proteinFile.eof()) {
                std::getline(proteinFile, buffer);
                if (buffer[0] == '>') {
                    ++m_numSequences;
                }
            }
            // Allocate memory for arrays
            m_uid = new std::string[m_numSequences];
            m_aminoSequence = new std::string[m_numSequences];
            
            // Reseting EOF flags
            proteinFile.clear();
            proteinFile.seekg(0);
            
            // Loading Protein Sequences to Object
            int index = 0;
            while (index < m_numSequences) {
                // Copying UID
                std::getline(proteinFile, buffer);
                std::string newUid = buffer.substr(4, 6);
                m_uid[index] = newUid;
                
                // Copying Amino Sequence
                std::string newSequence = "";
                while (proteinFile.peek() != '>') {
                    std::getline(proteinFile, buffer);
                    newSequence.append(buffer);
                }
                m_aminoSequence[index] = newSequence;
                std::cout << index++ << std::endl;;
            };
            proteinFile.close();
        } else {
            std::cerr << "Error: Could not open file" << std::endl;
        }
    }

    // Rule-of-5 Start

    /// <summary>
    ///     Copy Constructor
    /// </summary>
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
        m_uid = nullptr;
        m_aminoSequence = nullptr;
        *this = src;
    }

    /// <summary>
    ///     Move Constructor
    /// </summary>
    ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) {
        *this = std::move(src);
    }

    /// <summary>
    ///     Copy Assignment
    /// </summary>
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src) {
        // 1) Self-Assignment Guard
        if (this != &src) {
            // 2) Deallocate / clean memory
            delete [] m_uid;
            delete [] m_aminoSequence;
            
            // 3) Shallow Copy
            m_numSequences = src.m_numSequences;
            
            // 4) Deep Copy
            if (src.m_uid != nullptr) {
                // Copying UID
                m_uid = new std::string[src.m_uid->length()];
                for (int i = 0; i < m_uid->length(); ++i)
                {
                    this->m_uid[0] = src.m_uid[0];
                }
            } else {
                m_uid = nullptr;
            }
            
            if (src.m_aminoSequence != nullptr) {
                // Copying Amino Sequence
                m_aminoSequence = new std::string[src.m_aminoSequence->length()];
                for (int i = 0; i < m_aminoSequence->length(); ++i)
                {
                    this->m_aminoSequence[0] = src.m_aminoSequence[0];
                }
            } else {
                m_aminoSequence = nullptr;
            }
        }
        return *this;
    }

    /// <summary>
    ///     Move Assignment
    /// </summary>
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) {
        // 1) Self-Assignment Guard
        if (this != &src) {
            // 2) Clean Memory
            delete [] m_uid;
            delete [] m_aminoSequence;
            // 3) Shallow Copy All
            m_uid = src.m_uid;
            m_aminoSequence = src.m_aminoSequence;
            m_numSequences = src.m_numSequences;
            // 4) Detach pointers at src
            src.m_uid = nullptr;
            src.m_aminoSequence = nullptr;
        }
        return *this;
    }

    /// <summary>
    ///     Destructor
    /// </summary>
    ProteinDatabase::~ProteinDatabase() {
        delete [] m_uid;
        delete [] m_aminoSequence;
    }

    // Rule-of-5 End

    /// <summary>
    ///     A query that returns the number of protein sequences stored in the current object
    /// </summary>
    size_t ProteinDatabase::size() const {
        return m_numSequences; // could throw error: m_numSequences is an int not size_t
    }

    /// <summary>
    ///     A query that returns a copy of the protein sequence at the index received as the function
    ///     parameter. If the index is invalid, this function should return an empty string.
    /// </summary>
    std::string ProteinDatabase::operator[](const size_t index) const {
        return (m_aminoSequence == nullptr) ? "" : (m_aminoSequence[index] == "") ? "" : m_aminoSequence[index];
    }

    /// <summary>
    ///     A query that returns a copy of the protein ID at the index received as the function parameter.
    ///     If the index is invalid, this function should return "None"
    /// </summary>
    std::string ProteinDatabase::getUID(const size_t index) const {
        return (m_uid == nullptr) ? "none" : (m_uid[index] == "") ? "none" : m_uid[index];
    }
    
}
