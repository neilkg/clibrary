#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <functional>
#include <utility>
#include <vector>
#include "algorithm.h"

// NEIL GOLLAPUDI

// HASHTABLE
// O(1) amortized lookup, insertion, deletion
// vector collision resolution method;
// for collision, O(log n) search, insertion, and deletion


template <typename K, typename V, typename Hash = std::hash<K>>
class unordered_map {
public:
    // depending on how big hashtable is needed (depending on data quantity)
    unordered_map(long table_size_in) : table_size(table_size_in), num_elements(0) {
        std::vector<std::vector<std::pair<K, V>>> temp;
        temp.resize(table_size);
        elts = std::move(temp);
    }
    
    bool empty() {
        return num_elements == 0;
    }
    
    int size() {
        return size;
    }
    
    // if doesnt exist, makes an entry with that key
    V &operator[](const K &key) {
        Hash hasher;
        int idx = int(hasher(key)) % table_size;
        for (int i = 0; i < elts[idx].size(); ++i) {
            if (key == elts[idx][i].first) {
                return elts[idx][i].second;
            }
        }
        elts[idx].push_back(std::make_pair(key, V()));
        ++num_elements;
        return elts[idx][elts[idx].size() - 1].second;
    }
    
    // insert returns if successfully inserted
    // (if key exists in the table, do nothing and return false).
    bool insert(const K &key, const V &val) {
        Hash hasher;
        int idx = int(hasher(key)) % table_size;
        for (int i = 0; i < elts[idx].size(); ++i) {
            if (key == elts[idx][i].first) {
                return false;
            }
        }
        elts[idx].push_back(std::make_pair(key, val));
        ++num_elements;
        return true;
    }
    
    // erase returns true if successfully deleted
    // (if key does not exist in table, do nothing and return false).
    bool erase(const K &key) {
        Hash hasher;
        int idx = int(hasher(key)) % table_size;
        for (int i = 0; i < elts[idx].size(); ++i) {
            if (key == elts[idx][i].first) {
                swap(elts[idx][i], elts[idx][elts[idx].size() - 1]);
                elts[idx].pop_back();
                --num_elements;
                return true;
            }
        }
        return false;
    }

    
private:
    long table_size;
    int num_elements;
    std::vector<std::vector<std::pair<K, V>>> elts;

};

#endif
