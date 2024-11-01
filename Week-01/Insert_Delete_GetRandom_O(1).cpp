//Insert Delet GetRandom 0(1)
class RandomizedSet {
public:
    vector<int> randomset;
    unordered_map <int,int> val_to_key;
    RandomizedSet() {
        randomset.clear();
        val_to_key.clear();
    }
    
    bool insert(int val) {
        if( val_to_key.count(val)) 
            return false;
        randomset.push_back(val);
        val_to_key[val] = randomset.size() - 1;
        return true;
        
    }
    
    bool remove(int val) {
        if(!val_to_key.count(val)) return false;
        val_to_key[randomset[randomset.size()-1]] = val_to_key[val];
        swap(randomset[val_to_key[val]] , randomset[randomset.size()-1]);
        randomset.pop_back();
        val_to_key.erase(val);
        return true;
        
    }
    
    int getRandom() {
        int rd_idx = rand() % randomset.size();
        return randomset[rd_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
