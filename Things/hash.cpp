// Hash Table Implementation Template
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include<typeinfo>

//-------------------- HASH FUNCTION HELPERS --------------------
// Helper function to hash strings using Horner's rule
int hashString(const std::string& str, int tableSize) {
    // TODO: Implement string hashing function using Horner's rule
    // Use a prime number as the base (e.g., 31)
    // Return hash value modulo tableSize
    int primeNumber = 19;
    int hashValue = 0;
    for (char i : str){
        hashValue = (hashValue * primeNumber + i) % tableSize;
    }
    return hashValue; // Placeholder, replace with correct implementation
}

// Helper function to hash integers
int hashInt(int key, int tableSize) {
    // TODO: Implement simple integer hash function
    // Consider using the division method: h(k) = k mod tableSize
    return key % tableSize; // Placeholder, replace with correct implementation
}

//-------------------- SEPARATE CHAINING HASH TABLE --------------------
// Generic hash table using separate chaining for collision resolution
template <typename K, typename V>
class SeparateChainingHashTable {
private:
    // Each bucket contains a list of key-value pairs
    struct KeyValuePair {
        K key;
        V value;
        KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
    };

    std::list<KeyValuePair>* buckets; // Array of linked lists
    int tableSize;                    // Number of buckets
    int itemCount;                    // Total number of items in the hash table


    int hash (const std::string& key) const{
        return hashString(key, tableSize);
    }

    int hash (const int key) const {
        return hashInt(key, tableSize);
    }

public:
    // Constructor: Initialize hash table with given size
    SeparateChainingHashTable(int size = 101) {
        // TODO: Implement constructor
        tableSize = size;
        buckets = new std::list<KeyValuePair>[tableSize];
        itemCount = 0;
    }

    // Destructor: Free dynamically allocated memory
    ~SeparateChainingHashTable() {
        delete[] buckets;
        tableSize = 0;
        itemCount = 0;
        // TODO: Implement destructor
    }

    // Insert a key-value pair into the hash table
    // If key already exists, update its value
    void insert(const K& key, const V& value) {
        int hashValue = hash(key);
        itemCount++;
        buckets[hashValue].emplace_back(KeyValuePair(key, value));
        // TODO: Implement insert function
    }

    // Remove a key-value pair from the hash table
    // Throw exception if key not found
    void remove(const K& key) {
        int hashValue = hash(key);
        auto& bucket = buckets[hashValue];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                itemCount--;
                return;
            }
        }
        throw std::runtime_error("Key not found");
        // TODO: Implement remove function
    }

    // Search for a value associated with the given key
    // Throw exception if key not found
    V search(const K& key) const {
        // TODO: Implement search function
        int hashValue = hash(key);
        for (KeyValuePair& kv : buckets[hashValue]){
            if (kv.key == key){
                return kv.value;
            }
        }
        throw std::runtime_error("Key not found");
    }

    // Check if the hash table contains the given key
    bool contains(const K& key) const {
        // TODO: Implement contains function
        try {
            search(key);
        }catch (const std::exception& e){
            return false;
        }
        return true;
    }

    // Return the current load factor
    float loadFactor() const {
        // TODO: Implement load factor calculation
        return float(itemCount) / float(tableSize); // Placeholder, replace with correct implementation
    }

    // Return number of items in the hash table
    int size() const {
        // TODO: Implement size function
        return itemCount; // Placeholder, replace with correct implementation
    }

    // Display the hash table (for debugging)
    void display() const {
        for (int i = 0; i < tableSize; ++i){
            if (buckets[i].empty()) continue;
            std::cout << "index: " << i << "\n";
            for (KeyValuePair kv : buckets[i]){
                std::cout << kv.key << " " << kv.value << "\n";
            }
            std::cout << "\n";
        }
        // TODO: Implement display function
    }
};

//-------------------- OPEN ADDRESSING HASH TABLE --------------------
// Generic hash table using open addressing for collision resolution
template <typename K, typename V>
class OpenAddressingHashTable {
private:
    enum EntryStatus { EMPTY, OCCUPIED, DELETED };

    struct Entry {
        K key;
        V value;
        EntryStatus status;

        Entry() : status(EMPTY) {}

        Entry(const K& key, const V& value) 
        : key(key), value(value), status(OCCUPIED) {}
    };

    Entry* table;      // Array of entries
    int tableSize;     // Size of the table
    int itemCount;     // Number of items in the table

    // Hash function
    int hash(const std::string& key) const {
        return hashString(key, tableSize); 
    }

    int hash(const int& key) const {
        return hashInt(key, tableSize); 
    }

    // Probe function for collision resolution (linear probing)
    int probe(int hash, int i) const {
        if ( (i + 1) % tableSize ==  hash) return 0;
        else if (table[i].status == EMPTY) return i;
        else return probe(hash, (i+1) % tableSize);
    }

    int findIndex(int hash, int i, const K& key) const {
        if (table[i].status == EMPTY) return -1;
        else if (table[i].key == key) return i;
        else return findIndex(hash, i + 1, key);
        
    }

public:
    // Constructor: Initialize hash table with given size
    OpenAddressingHashTable(int size = 101) {
        tableSize = size;
        table = new Entry[tableSize];
        itemCount = 0;
    }

    // Destructor: Free dynamically allocated memory
    ~OpenAddressingHashTable() {
        delete[] table;
    }

    bool isEmpty(){
        return (itemCount == 0);
    }

    bool isFull(){
        return !(tableSize - itemCount);
    }

    // Insert a key-value pair into the hash table
    // If key already exists, update its value
    // If table is full, throw an exception
    void insert(const K& key, const V& value) {
        if (isFull()){
            throw std::overflow_error("Table overflow");
            return;
        }
        int hashValue = hash(key);
        hashValue = probe(hashValue, hashValue);
        table[hashValue] = Entry(key, value);
        itemCount++;
        return;
    }

    // Remove a key-value pair from the hash table
    // Throw exception if key not found
    void remove(const K& key) {
        int hashValue = hash(key);
        hashValue = findIndex(hashValue, hashValue, key);
        if (hashValue == -1){
            throw std::runtime_error("Key not found");
            return;
        }
        itemCount--;
        table[hashValue].status = EMPTY;
        return;
    }

    // Search for a value associated with the given key
    // Throw exception if key not found
    V search(const K& key) const {
        int hashValue = hash(key);
        hashValue = findIndex(hashValue, hashValue, key);
        if (hashValue == -1){
            throw std::runtime_error("Key not found");
        }
        return table[hashValue].value; 
    }

    // Check if the hash table contains the given key
    bool contains(const K& key) const {
        int hashValue = hash(key);
        hashValue = findIndex(hashValue, hashValue, key);
        if (hashValue == -1){
            return false;
        }
        return true; 
    }

    // Return the current load factor
    float loadFactor() const {
        return float(itemCount) / float(tableSize); 
    }

    // Return number of items in the hash table
    int size() const {
        return tableSize; 
    }
    // Display the hash table (for debugging)
    void display() const {
        for (int i = 0; i < tableSize; ++i){
            if (table[i].status != EMPTY){
                std::cout << i << " " << table[i].key << " " << table[i].value << "\n";
            }
        }
        std::cout<<"\n";
    }
};

//-------------------- TESTING FUNCTION --------------------
void testHashTables() {
    // Test separate chaining hash table with string keys
    std::cout << "Testing Separate Chaining Hash Table with string keys:\n";
    SeparateChainingHashTable<std::string, int> scHashTable(10);

    // Insert some key-value pairs
    scHashTable.insert("apple", 5);
    scHashTable.insert("banana", 8);
    scHashTable.insert("cherry", 12);
    scHashTable.insert("date", 15);
    scHashTable.insert("elderberry", 20);
    scHashTable.insert("fig", 25);

    // Display the table
    std::cout << "After insertions:\n";
    scHashTable.display();

    // Search for some keys
    try {
        std::cout << "Value for 'apple': " << scHashTable.search("apple") << std::endl;
        std::cout << "Value for 'banana': " << scHashTable.search("banana") << std::endl;
        std::cout << "Value for 'grape': " << scHashTable.search("grape") << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Remove a key
    std::cout << "Removing 'banana'..." << std::endl;
    scHashTable.remove("banana");

    // Display the table again
    std::cout << "After removal:\n";
    scHashTable.display();

    // Test contains method
    std::cout << "Contains 'apple': " << (scHashTable.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Contains 'banana': " << (scHashTable.contains("banana") ? "Yes" : "No") << std::endl;

    // Test load factor
    std::cout << "Load factor: " << scHashTable.loadFactor() << std::endl;
    std::cout << "Size: " << scHashTable.size() << std::endl;




    // Test open addressing hash table with integer keys
    std::cout << "\nTesting Open Addressing Hash Table with integer keys:\n";
    OpenAddressingHashTable<int, std::string> oaHashTable(10);

    // Insert some key-value pairs
    oaHashTable.insert(5, "five");
    oaHashTable.insert(15, "fifteen");
    oaHashTable.insert(25, "twenty-five");
    oaHashTable.insert(35, "thirty-five");
    oaHashTable.insert(45, "forty-five");

    // Display the table
    std::cout << "After insertions:\n";
    oaHashTable.display();

    // Search for some keys
    try {
        std::cout << "Value for 5: " << oaHashTable.search(5) << std::endl;
        std::cout << "Value for 15: " << oaHashTable.search(15) << std::endl;
        std::cout << "Value for 100: " << oaHashTable.search(100) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Remove a key
    std::cout << "Removing 15..." << std::endl;
    oaHashTable.remove(15);

    // Display the table again
    std::cout << "After removal:\n";
    oaHashTable.display();

    // Test contains method
    std::cout << "Contains 5: " << (oaHashTable.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 15: " << (oaHashTable.contains(15) ? "Yes" : "No") << std::endl;

    // Test load factor
    std::cout << "Load factor: " << oaHashTable.loadFactor() << std::endl;
    std::cout << "Size: " << oaHashTable.size() << std::endl;
}

int main() {
    testHashTables();
    return 0;
}