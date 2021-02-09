#ifndef _director_h__
#define _director_h__

#include "movie.h"
#include <cstring>


class DirectorComparator
{
  public:
    // IMPLEMENT BELOW inline
    bool operator( ) (const Movie::SecondaryKey & key1, 
                      const Movie::SecondaryKey & key2) const
    {
        
        std::string director1 = key1.getDirector();
        std::string director2 = key2.getDirector();

        int size1 = director1.size();
        int size2 = director2.size();
        int sizewillbeused = size1 < size2 ? size1 : size2;
        
        for (int i = 0; i < sizewillbeused; i++) {
            char char1 = std::tolower(director1[i]);
            char char2 = std::tolower(director2[i]);
            if (char1 != char2) {
                if (char1 < char2) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        
        if (size1 < size2) {
            return true;
        }else  if (size1 > size2) {
            return false;
        }
        

        std::string title1 = key1.getTitle();
        std::string title2 = key2.getTitle();

        size1 = title1.size();
        size2 = title2.size();
        sizewillbeused = size1 < size2 ? size1 : size2;
        
        
        
        for (int i = 0; i < sizewillbeused; i++) {
            char char1 = std::tolower(title1[i]);
            char char2 = std::tolower(title2[i]);
            if (char1 != char2) {
                if (char1 < char2) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        
        if (size1 < size2) {
            return true;
        }else if (size1 > size2)  {
            return false;
        }

      return false;
    }

};

#endif
