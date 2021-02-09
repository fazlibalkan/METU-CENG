    #include "moviestore.h"


MovieStore::MovieStore( ) //implemented, do not change
{
}


// IMPLEMENT
void
MovieStore::insert(const Movie & movie)
{
    
    primaryIndex.insert(movie.getID(), movie);
    
    Movie::SecondaryKey key(movie);
    
    Movie * ptr = &((primaryIndex.find(movie.getID()))->data);
    
    secondaryIndex.insert(key, ptr);
    ternaryIndex.insert(key, ptr);

    //primaryIndex.find(movie.getID())
}


// IMPLEMENT
void
MovieStore::remove(const std::string & id)
{
    if (primaryIndex.find(id)) {
        Movie m = (primaryIndex.find(id))->data;
        Movie::SecondaryKey key(m);
        if (ternaryIndex.find(key)) {
            ternaryIndex.remove(key);
        }
        if (secondaryIndex.find(key)) {
            secondaryIndex.remove(key);
        }
        primaryIndex.remove(id);
    }
    

}


// IMPLEMENT
void
MovieStore::remove(const std::string & title,
                  const std::string & director)
{
    Movie::SecondaryKey key(title, director);
    if (ternaryIndex.find(key)) {
        Movie *m = (ternaryIndex.find(key))->data;
        ternaryIndex.remove(key);
        if (secondaryIndex.find(key)) {
            secondaryIndex.remove(key);
        }
        if (primaryIndex.find(m->getID())) {
            primaryIndex.remove(m->getID());
        }
    }
    
}


// IMPLEMENT
void
MovieStore::removeAllMoviesWithTitle(const std::string & title)
{
    Movie::SecondaryKey key1(title, "a");
    Movie::SecondaryKey key2(title, "{");

    auto ranges = ternaryIndex.find(key1, key2);
    int size = ranges.size();
    
    for (int i = 0; i < size; i++) {
        Movie *m = ((ranges.front())->data);
        Movie::SecondaryKey key(title, m->getDirector());
        if (m) {
            ternaryIndex.remove(key);
            if (secondaryIndex.find(key)) {
                secondaryIndex.remove(key);
            }
            if (primaryIndex.find(m->getID())) {
                primaryIndex.remove(m->getID());
            }
        }
        ranges.pop_front();
    }
}


// IMPLEMENT
void
MovieStore::makeAvailable(const std::string & id)
{
    Movie *m = &((primaryIndex.find(id))->data);
    if (m)
        m->setAvailable();

}


// IMPLEMENT
void
MovieStore::makeUnavailable(const std::string & title,
                           const std::string & director)
{
    Movie::SecondaryKey key(title, director);
    Movie *m = ((ternaryIndex.find(key))->data);
    if (m)
        m->setUnavailable();
    
}


// IMPLEMENT
void
MovieStore::updateCompany(const std::string & director, 
                           const std::string & Company)
{
    Movie::SecondaryKey key1("a", director);
    Movie::SecondaryKey key2("z", director);

    auto ranges = secondaryIndex.find(key1, key2);
    int size = ranges.size();
    
    
    
    for (int i = 0; i < size; i++) {
        const Movie *m = ((ranges.front())->data);
        if (m) {
            Movie *m_notconstant = &((primaryIndex.find(m->getID()))->data);
            if (m_notconstant){
                m_notconstant->setCompany(Company);
            }
        }
        ranges.pop_front();
    }

}


// IMPLEMENT
void
MovieStore::printMoviesWithID(const std::string & id1,
                              const std::string & id2,
                              unsigned short since) const
{
    auto ranges = primaryIndex.find(id1, id2);
    int size = ranges.size();

    for (int i = 0; i < size; i++) {
        if (((ranges.front())->data).getYear() >= since) {
              std::cout << (ranges.front())->data << std::endl;
        }
        ranges.pop_front();
    }
    
}


// IMPLEMENT
void
MovieStore::printMoviesOfDirector(const std::string & director,
                                  const std::string & first,
                                  const std::string & last) const
{
    Movie::SecondaryKey key1(first, director);
    Movie::SecondaryKey key2(last, director);

    auto ranges = secondaryIndex.find(key1, key2);
    int size = ranges.size();
    
    for (int i = 0; i < size; i++) {
        const Movie *m = ((ranges.front())->data);
        if (m) {
            std::cout << *m << std::endl;
        }
        ranges.pop_front();
    }
    
}



void  // implemented, do not change
MovieStore::printPrimarySorted( ) const
{
  printPrimarySorted(primaryIndex.getRoot());
}


void  // implemented, do not change
MovieStore::printPrimarySorted(MSTP::Node * t) const
{
  if (t == NULL)
  {
    return;
  }

  printPrimarySorted(t->left);
  std::cout << t->data << std::endl;
  printPrimarySorted(t->right);
}


void  // implemented, do not change
MovieStore::printSecondarySorted( ) const
{
  printSecondarySorted(secondaryIndex.getRoot());
}


void  // implemented, do not change
MovieStore::printSecondarySorted(MSTS::Node * t) const
{
  if (t == NULL)
  {
    return;
  }

  printSecondarySorted(t->left);
  std::cout << *(t->data) << std::endl;
  printSecondarySorted(t->right);
}


void  // implemented, do not change
MovieStore::printTernarySorted( ) const
{
  printTernarySorted(ternaryIndex.getRoot());
}


void  // implemented, do not change
MovieStore::printTernarySorted(MSTT::Node * t) const
{
  if (t == NULL)
  {
    return;
  }

  printTernarySorted(t->left);
  std::cout << *(t->data) << std::endl;
  printTernarySorted(t->right);
}

