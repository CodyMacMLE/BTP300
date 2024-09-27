//
//  dictionary.cpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "dictionary.h"

namespace seneca {
    
    /// <summary>
    ///  Returns a string of the type of word
    /// </summary>
    std::string Word::getPos() {
        std::string pos;
        if (m_pos == PartOfSpeech::Noun) {
            pos = " (noun)";
        }
        else if (m_pos == PartOfSpeech::Pronoun) {
            pos = " (pronoun)";
        }
        else if (m_pos == PartOfSpeech::Adjective) {
            pos = " (adjective)";
        }
        else if (m_pos == PartOfSpeech::Adverb) {
            pos = " (adverb)";
        }
        else if (m_pos == PartOfSpeech::Preposition) {
            pos = " (preposition)";
        }
        else if (m_pos == PartOfSpeech::Conjunction) {
            pos = " (conjunction)";
        }
        else if (m_pos == PartOfSpeech::Interjection) {
            pos = " (interjection)";
        }
        else {
            pos = "";
        }
        return pos;
    }

    /// <summary>
    /// Default Constructor
    /// </summary>
    Dictionary::Dictionary(){
        m_words = nullptr;
        m_arrLength = 0;
    }
    
/*
    /// <summary>
    /// Loads from the file specified as parameter the collection of words, allocate enough memory (but
    /// no more) for the array to store the data, and then load all the words into the array. If the file
    /// cannot be open, this function puts the current instance in an empty state.
    /// </summary>
    Dictionary::Dictionary(const char* filename){
        m_arrLength = 0;
        std::ifstream file;
        std::string buffer;
        if (filename != nullptr) {
            file.open(filename);
            if (file.good()){
                // Counting data lines
                while (!file.eof()){
                    std::getline(file, buffer);
                    m_arrLength++;
                }
                // Reset file position and flags
                file.clear();
                file.seekg(0);
                // Create new m_words array for file length
                m_words = new Word[m_arrLength];
                // Read from csv format = word,pos,definition
                for (auto i = 0; i < m_arrLength; ++i){
                    // Grabbing Word
                    buffer.clear();
                    std::getline(file, buffer,',');
                    m_words[i].m_word = buffer;
                    // Grabbing Part of Speech
                    buffer.clear();
                    std::getline(file, buffer,',');
                    if (buffer == "n.")
                        m_words[i].m_pos = PartOfSpeech::Noun;
                    else if (buffer == "n. pl.")
                        m_words[i].m_pos = PartOfSpeech::Noun;
                    else if (buffer == "adv.")
                        m_words[i].m_pos = PartOfSpeech::Adverb;
                    else if (buffer == "a.")
                        m_words[i].m_pos = PartOfSpeech::Adjective;
                    else if (buffer == "v.")
                        m_words[i].m_pos = PartOfSpeech::Verb;
                    else if (buffer == "v. i.")
                        m_words[i].m_pos = PartOfSpeech::Verb;
                    else if (buffer == "v. t.")
                        m_words[i].m_pos = PartOfSpeech::Verb;
                    else if (buffer == "v. t. & i.")
                        m_words[i].m_pos = PartOfSpeech::Verb;
                    else if (buffer == "prep.")
                        m_words[i].m_pos = PartOfSpeech::Preposition;
                    else if (buffer == "pron.")
                        m_words[i].m_pos = PartOfSpeech::Pronoun;
                    else if (buffer == "conj.")
                        m_words[i].m_pos = PartOfSpeech::Conjunction;
                    else if (buffer == "interj.")
                        m_words[i].m_pos = PartOfSpeech::Interjection;
                    else
                        m_words[i].m_pos = PartOfSpeech::Unknown;
                    // Grabbing definition
                    buffer.clear();
                    std::getline(file, buffer);
                    m_words[i].m_definition = buffer;
                }
            }
            else
                m_words = nullptr;
            file.close();
        }
        else
            m_words = nullptr;
    }
    
    /// <summary>
    /// Copy Constructor
    /// </summary>
    Dictionary::Dictionary(const Dictionary& src) {
        *this = src;
    }
    
    /// <summary>
    /// Copy Assignment
    /// </summary>
    Dictionary& Dictionary::operator=(const Dictionary& src) {
        // Self-assign guard
        if(this != &src) {
            // Clean mem
            delete [] m_words;
            // shallow copy
            m_arrLength = src.m_arrLength;
            // deep copy
            if (m_arrLength > 0) {
                for (auto i = 0; i < m_arrLength; ++i)
                    m_words[i] = src.m_words[i];
            } else {
                m_words = nullptr;
            }
        }
        return *this;
    }
    
    /// <summary>
    /// Move Constructor
    /// </summary>
    Dictionary::Dictionary(Dictionary&& src) {
        *this = std::move(src);
    }
    
    /// <summary>
    /// Move Assignment
    /// </summary>
    Dictionary& Dictionary::operator=(Dictionary&& src){
        // Self-assign guard
        if(this != &src) {
            // Clean mem
            delete [] m_words;
            // shallow copy (static)
            m_arrLength = src.m_arrLength;
            // shallow copy (dynamic)
            m_words = src.m_words;
            // delete old pointers
            delete [] src.m_words;
        }
        return *this;
    }
*/
    /// <summary>
    /// Default Destructor
    /// </summary>
    Dictionary::~Dictionary() {
        delete [] m_words;
    }
    
    /// <summary>
    /// Searches in the collection of words the one specified as a parameter. If the word is found, it prints
    /// the definition
    /// </summary>
    void Dictionary::searchWord(const char* word) const{
        std::string wordString = word;
        bool wordExists = false;
        int wordFirstIndex = -1;
        
        // Finding if a match is found
        for (auto i = 0; i < m_arrLength && !wordExists; ++i) {
            if (wordString.compare(this->m_words[i].m_word) == 0) {
                wordFirstIndex = i;
                wordExists = true;
            }
        }
        
        // If Word Match Exists
        if(wordExists) {
            // Checking if all or one match is shown
            if (!g_settings.m_show_all) {
                // Checking if full description is shown
                if (!g_settings.m_verbose) {
                    std::cout << word << " - " << m_words[wordFirstIndex].m_definition << std::endl;
                } else {
                    std::cout << word << " -" << m_words[wordFirstIndex].getPos() << " "<< m_words[wordFirstIndex].m_definition << std::endl;
                }
            } else {
                int wordWidth = int(wordString.length());
                int matchCount = 1;
                for (auto i = wordFirstIndex + 1; i < m_arrLength && wordExists; i++) {
                    if (wordString.compare(this->m_words[i].m_word) != 0) {
                        wordExists = false;
                    } else {
                        matchCount++;
                    }
                }
                if (!g_settings.m_verbose) {
                    std::cout << word << " - " << m_words[wordFirstIndex].m_definition << std::endl;
                    if (matchCount > 1) {
                        for (auto i = wordFirstIndex + 1; i < (wordFirstIndex + matchCount); ++i) {
                            std::cout << std::setw(wordWidth) << "" << " - " << m_words[i].m_definition << std::endl;
                        }
                    }
                } else {
                    std::cout << word << " -" << m_words[wordFirstIndex].getPos() << " "<< m_words[wordFirstIndex].m_definition << std::endl;
                    if (matchCount > 1) {
                        for (auto i = wordFirstIndex + 1; i < (wordFirstIndex + matchCount); ++i) {
                            std::cout << std::setw(wordWidth)<< "" << " -" << m_words[i].getPos() << " "<< m_words[i].m_definition << std::endl;
                        }
                    }
                }
            }
        } else {
            std::cout << "Word '"<< word <<"' was not found in the dictionary." << std::endl;
        }
    }
}
