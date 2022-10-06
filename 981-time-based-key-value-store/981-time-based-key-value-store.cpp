class TimeMap {
public:
    map<int,map<string,string>>m;
    TimeMap() {
        m[0][""]="";
    }
    
    void set(string key, string value, int timestamp) {
        m[timestamp][key]=value;
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp;i>0;i--)
        {
            if(m[i].find(key)!=m[i].end())
                return m[i][key];
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */