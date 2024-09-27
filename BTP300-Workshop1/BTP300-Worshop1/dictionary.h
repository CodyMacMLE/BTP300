//
//  dictionary.hpp
//  BTP300-Worshop1
//
//  Created by Cody MacDonald on 2024-09-15.
//

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include "settings.h"

namespace seneca {
    extern Settings g_settings;
    
    enum class PartOfSpeech
    {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection,
    };
    
    struct Word
    {
        /// <summary>
        /// Word
        /// </summary>
        std::string m_word;
        /// <summary>
        /// Word definition
        /// </summary>
        std::string m_definition;
        /// <summary>
        /// Type of word
        /// </summary>
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
        
        /// <summary>
        ///  Returns a string of the type of word
        /// </summary>
        std::string getPos();
    };
    
    class Dictionary {
        /// <summary>
        /// Manages a dynamically allocated collection of objects of type Word in the form of an array
        /// </summary>
        Word* m_words;
        
        /// <summary>
        /// Stores the number of words in the array
        /// </summary>
        int m_arrLength;
    public:
        /// <summary>
        /// Default Constructor
        /// </summary>
        Dictionary();
        
        /// <summary>
        /// Loads from the file specified as parameter the collection of words, allocate enough memory (but
        /// no more) for the array to store the data, and then load all the words into the array. If the file
        /// cannot be open, this function puts the current instance in an empty state.
        /// </summary>
        Dictionary(const char* filename);
        
        /// <summary>
        /// Copy Constructor
        /// </summary>
        Dictionary(const Dictionary& src);
        
        /// <summary>
        /// Copy Assignment
        /// </summary>
        Dictionary& operator=(const Dictionary& src);
        
        /// <summary>
        /// Move Constructor
        /// </summary>
        Dictionary(Dictionary&& src);
        
        /// <summary>
        /// Move Assignment
        /// </summary>
        Dictionary& operator=(Dictionary&& src);
        
        /// <summary>
        /// Default Destructor
        /// </summary>
        ~Dictionary();
        
        /// <summary>
        /// Searches in the collection of words the one specified as a parameter. If the word is found, it prints
        /// the definition
        /// </summary>
        void searchWord(const char* word) const;
    };
}
#endif /* SENECA_DICTIONARY_H */
