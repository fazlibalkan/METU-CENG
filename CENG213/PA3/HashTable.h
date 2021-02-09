#ifndef __HASHTABLE__
#define __HASHTABLE__

#include "HashUtils.h"
#include "ItemNotFoundException.h"
/* Do not add new libraries or files */

#define BUCKET_SIZE 2

// Do not modify the public interface of this class.
// Otherwise, your code will note compile!
template <class K, class T>
class HashTable {
    struct Entry {
        K Key;             // the key of the entry
        T Value;   // the value of the entry
        bool Deleted;        // flag indicating whether this entry is deleted
        bool Active;         // flag indicating whether this item is currently used

        Entry() : Key(), Value(), Deleted(false), Active(false) {}
    };

    struct Bucket {
        Entry entries[BUCKET_SIZE];
    };

    int _capacity; // INDICATES THE TOTAL CAPACITY OF THE TABLE
    int _size; // INDICATES THE NUMBER OF ITEMS IN THE TABLE

    Bucket* _table; // THE HASH TABLE

    // == DEFINE HELPER METHODS & VARIABLES BELOW ==


public:
    // TODO: IMPLEMENT THESE FUNCTIONS.
    // CONSTRUCTORS, ASSIGNMENT OPERATOR, AND THE DESTRUCTOR
    HashTable();
    // COPY THE WHOLE CONTENT OF RHS INCLUDING THE KEYS THAT WERE SET AS DELETED
    HashTable(const HashTable<K, T>& rhs);
    HashTable<K, T>& operator=(const HashTable<K, T>& rhs);
    ~HashTable();

    // TODO: IMPLEMENT THIS FUNCTION.
    // INSERT THE ENTRY IN THE HASH TABLE WITH THE GIVEN KEY & VALUE
    // IF THE GIVEN KEY ALREADY EXISTS, THE NEW VALUE OVERWRITES
    // THE ALREADY EXISTING ONE. IF THE LOAD FACTOR OF THE TABLE IS GREATER THAN 0.6,
    // RESIZE THE TABLE WITH THE NEXT PRIME NUMBER.
    void Insert(const K& key, const T& value);

    // TODO: IMPLEMENT THIS FUNCTION.
    // DELETE THE ENTRY WITH THE GIVEN KEY FROM THE TABLE
    // IF THE GIVEN KEY DOES NOT EXIST IN THE TABLE, THROW ItemNotFoundException()
    void Delete(const K& key);

    // TODO: IMPLEMENT THIS FUNCTION.
    // IT SHOULD RETURN THE VALUE THAT CORRESPONDS TO THE GIVEN KEY.
    // IF THE KEY DOES NOT EXIST, THROW ItemNotFoundException()
    T& Get(const K& key) const;

    // TODO: IMPLEMENT THIS FUNCTION.
    // AFTER THIS FUNCTION IS EXECUTED THE TABLE CAPACITY MUST BE
    // EQUAL TO newCapacity AND ALL THE EXISTING ITEMS MUST BE REHASHED
    // ACCORDING TO THIS NEW CAPACITY.
    // WHEN CHANGING THE SIZE, YOU MUST REHASH ALL OF THE ENTRIES
    void Resize(int newCapacity);

    // THE IMPLEMENTATION OF THESE FUNCTIONS ARE GIVEN TO YOU
    // DO NOT MODIFY!
    int Capacity() const; // RETURN THE TOTAL CAPACITY OF THE TABLE
    int Size() const; // RETURN THE NUMBER OF ACTIVE ITEMS
    void getKeys(K* keys); // PUT THE ACTIVE KEYS TO THE GIVEN INPUT PARAMETER
};


template <class K, class T>
HashTable<K, T>::HashTable() {
    // TODO: IMPLEMENT THIS FUNCTION.
    _capacity = 7;
    _size = 0;
    _table = new Bucket[_capacity];

}

template <class K, class T>
HashTable<K, T>::HashTable(const HashTable<K, T>& rhs) {
    // TODO: IMPLEMENT THIS FUNCTION.
    _capacity = rhs._capacity;
    _size = 0;
    _table = new Bucket[_capacity];

    for (int i = 0; i < _capacity; i++) {
        Bucket& bucket = rhs._table[i];
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (bucket.entries[j].Active) {
                _table[i].entries[j].Key = bucket.entries[j].Key;
                _table[i].entries[j].Value = bucket.entries[j].Value;
                _table[i].entries[j].Active = bucket.entries[j].Active;
                _table[i].entries[j].Deleted = bucket.entries[j].Deleted;
                _size++;
            } else if (bucket.entries[j].Deleted) {
                _table[i].entries[j].Key = bucket.entries[j].Key;
                _table[i].entries[j].Value = bucket.entries[j].Value;
                _table[i].entries[j].Active = bucket.entries[j].Active;
                _table[i].entries[j].Deleted = bucket.entries[j].Deleted;
            }
        }
    }

}

template <class K, class T>
HashTable<K, T>& HashTable<K, T>::operator=(const HashTable<K, T>& rhs) {
    // TODO: IMPLEMENT THIS FUNCTION.
    delete[]  _table;
    _capacity = rhs._capacity;
    _size = 0;
    _table = new Bucket[_capacity];

    for (int i = 0; i < _capacity; i++) {
        Bucket& bucket = rhs._table[i];
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (bucket.entries[j].Active) {
                _table[i].entries[j].Key = bucket.entries[j].Key;
                _table[i].entries[j].Value = bucket.entries[j].Value;
                _table[i].entries[j].Active = bucket.entries[j].Active;
                _table[i].entries[j].Deleted = bucket.entries[j].Deleted;
                _size++;
            } else if (bucket.entries[j].Deleted) {
                _table[i].entries[j].Key = bucket.entries[j].Key;
                _table[i].entries[j].Value = bucket.entries[j].Value;
                _table[i].entries[j].Active = bucket.entries[j].Active;
                _table[i].entries[j].Deleted = bucket.entries[j].Deleted;
            }
        }
    }
}

template <class K, class T>
HashTable<K, T>::~HashTable() {
    // TODO: IMPLEMENT THIS FUNCTION.
    delete[] _table;
    _capacity = 0;
    _size = 0;

}

template <class K, class T>
void HashTable<K, T>::Insert(const K& key, const T& value) {
    // TODO: IMPLEMENT THIS FUNCTION.
  /*
    if (_size > (_capacity * 2 * 0.6)) {
        int nc = NextCapacity(_capacity);
        Resize(nc);
    }

    int index = Hash(key)%_capacity, b = 0;
    if (!_table[index].entries[b].Active && !_table[index].entries[b].Deleted) {
        _table[index].entries[b].Active = true;
        _table[index].entries[b].Deleted = false;
        _table[index].entries[b].Key = key;
        _table[index].entries[b].Value = value;
        _size++;
    } else {
        if (_table[(index)%_capacity].entries[b].Key == key) {
            _table[(index)%_capacity].entries[b].Value = value;
            return;
        }
        b++;
        int i = 0, n = 0;
        while ((_table[(index + i)%_capacity].entries[b].Active && _table[(index + i)%_capacity].entries[b].Key != key) || _table[(index + i)%_capacity].entries[b].Deleted) {
            i = n*n;
            n++;
        }
        if (_table[(index + i)%_capacity].entries[b].Active) {
            _table[(index + i)%_capacity].entries[b].Value = value;
        }  else {
            _table[(index + i)%_capacity].entries[b].Key = key;
            _table[(index + i)%_capacity].entries[b].Value = value;
            _table[(index + i)%_capacity].entries[b].Active = true;
            _table[(index + i)%_capacity].entries[b].Deleted = false;
            _size++;
        }
    }

    int notexists = 0;

    if (_size > (_capacity * 2 * 0.6)) {
        int nc = NextCapacity(_capacity);
        Resize(nc);
    }

    try {
        Get(key);
    } catch (ItemNotFoundException a) {
        notexists = 1;
    }

    int index = Hash(key)%_capacity, b = 0;
    if (!notexists) {
        if (_table[index].entries[b].Key == key) {
            _table[index].entries[b].Value = value;
            return;
        }
        b++;
        int i = 0, n = 0;
        while (_table[(index + i)%_capacity].entries[b].Key != key) {
            i = n*n;
            n++;
        }
        _table[(index + i)%_capacity].entries[b].Value = value;
        return;
    } else {
        if (!_table[index].entries[b].Active) {
            _table[index].entries[b].Active = true;
            _table[index].entries[b].Deleted = false;
            _table[index].entries[b].Key = key;
            _table[index].entries[b].Value = value;
            _size++;
            return;
        }
        b++;
        int i = 0, n = 0;
        while (_table[(index + i)%_capacity].entries[b].Active) {
            i = n*n;
            n++;
        }
        _table[(index + i)%_capacity].entries[b].Key = key;
        _table[(index + i)%_capacity].entries[b].Value = value;
        _table[(index + i)%_capacity].entries[b].Active = true;
        _table[(index + i)%_capacity].entries[b].Deleted = false;
        _size++;

    }
        */
    if (_size > (_capacity * 2 * 0.6)) {
        int nc = NextCapacity(_capacity);
        Resize(nc);
    }

    try {
        Get(key) = value;
    } catch (ItemNotFoundException a) {
        int index = Hash(key)%_capacity, b = 0;
        if (!_table[index].entries[b].Active) {
            _table[index].entries[b].Active = true;
            _table[index].entries[b].Deleted = false;
            _table[index].entries[b].Key = key;
            _table[index].entries[b].Value = value;
            _size++;
            return;
        }
        b++;
        int i = 0, n = 0;
        while (_table[(index + i)%_capacity].entries[b].Active) {
            i = n*n;
            n++;
        }
        _table[(index + i)%_capacity].entries[b].Key = key;
        _table[(index + i)%_capacity].entries[b].Value = value;
        _table[(index + i)%_capacity].entries[b].Active = true;
        _table[(index + i)%_capacity].entries[b].Deleted = false;
        _size++;
    }
}

template <class K, class T>
void HashTable<K, T>::Delete(const K& key) {
    // TODO: IMPLEMENT THIS FUNCTION.

    int i = 0, n = 0, b = 0;
    int index = Hash(key)%_capacity;
    if (!_table[index].entries[b].Active) {
        throw ItemNotFoundException();
    } else {
        if (_table[(index + i)%_capacity].entries[b].Key == key) {
            _table[(index + i)%_capacity].entries[b].Active = false;
            _table[(index + i)%_capacity].entries[b].Deleted = true;
            _size--;
            return;
        }
        b++;
        while ((_table[(index + i)%_capacity].entries[b].Active && _table[(index + i)%_capacity].entries[b].Key != key) || _table[(index + i)%_capacity].entries[b].Deleted) {
            i = n*n;
            n++;
        }
        if (!_table[(index + i)%_capacity].entries[b].Active) {
            throw ItemNotFoundException();
        } else if (_table[(index + i)%_capacity].entries[b].Active) {
            _table[(index + i)%_capacity].entries[b].Active = false;
            _table[(index + i)%_capacity].entries[b].Deleted = true;
            _size--;
        }
    }

}

template <class K, class T>
T& HashTable<K, T>::Get(const K& key) const {
    // TODO: IMPLEMENT THIS FUNCTION.

    int i = 0, n = 0, b = 0;
    int index = Hash(key)%_capacity;
    if (!_table[index].entries[b].Active && !_table[index].entries[b].Deleted) {
        throw ItemNotFoundException();
    } else {
        if (_table[(index + i)%_capacity].entries[b].Active && _table[(index + i)%_capacity].entries[b].Key == key) {
            return (_table[(index + i)%_capacity].entries[b].Value);
        }
        b++;
        while ((_table[(index + i)%_capacity].entries[b].Active && _table[(index + i)%_capacity].entries[b].Key != key) || _table[(index + i)%_capacity].entries[b].Deleted) {
            i = n*n;
            n++;
        }
        if (_table[(index + i)%_capacity].entries[b].Active) {
            return (_table[(index + i)%_capacity].entries[b].Value);
        } else {
            throw ItemNotFoundException();
        }
    }

}


template <class K, class T>
void HashTable<K, T>::Resize(int newCapacity) {
    // TODO: IMPLEMENT THIS FUNCTION.
    Bucket * oldtable = _table;
    int oldcap = _capacity;
    _table = new Bucket[newCapacity];
    _capacity = newCapacity;
    _size=0;

    int index = 0, a = 0, n = 0, b = 0;
    for (int i = 0; i < oldcap; i++) {
        Bucket& bucket = oldtable[i];
        for (int j = 0; j < BUCKET_SIZE; j++) {
            b = 0; a = 0; n = 0;
            index = Hash(oldtable[i].entries[j].Key);
            if (bucket.entries[j].Active) {
                if (!_table[(index+a)%_capacity].entries[b].Active) {
                    _table[(index+a)%_capacity].entries[b].Active = true;
                    _table[(index+a)%_capacity].entries[b].Key = bucket.entries[j].Key;
                    _table[(index+a)%_capacity].entries[b].Value = bucket.entries[j].Value;
                    _size++;
                    continue;
                }
                b++;
                while (_table[(index+a)%_capacity].entries[b].Active) {
                    a = n*n;
                    n++;
                }
                _table[(index+a)%_capacity].entries[b].Active = true;
                _table[(index+a)%_capacity].entries[b].Key = bucket.entries[j].Key;
                _table[(index+a)%_capacity].entries[b].Value = bucket.entries[j].Value;
                _size++;
            }
        }

    }

    delete[] oldtable;
}


template <class K, class T>
int HashTable<K, T>::Capacity() const {
    return _capacity;
}

template <class K, class T>
int HashTable<K, T>::Size() const {
    return _size;
}


template <class K, class T>
void HashTable<K, T>::getKeys(K* keys) {
    int index = 0;

    for (int i = 0; i < _capacity; i++) {
        Bucket& bucket = _table[i];
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (bucket.entries[j].Active && !bucket.entries[j].Deleted) {
                keys[index++] = bucket.entries[j].Key;
            }
        }
    }
}

#endif
