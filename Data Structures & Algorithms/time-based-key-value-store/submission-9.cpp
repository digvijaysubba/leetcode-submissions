class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>>keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      keyStore[key].emplace_back(value,timestamp);  
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0;
        int r = values.size()-1;
        string res = "";

        while (l <=r){
            int m = (l+r)/2;
            if ( values[m].second <= timestamp){
                res = values[m].first;
                l = m +1;
            }
            else {
                r = m -1;
            }
        }
        return res;
        
    }
};
