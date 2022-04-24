class UndergroundSystem {
public:
    map<pair<string, string>, pair<int, int>> m;
    map<int, pair<string, int> > checkin;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, string> p = {checkin[id].first, stationName};
        if(m.count(p))
            m[p] = {m[p].first + t - checkin[id].second, m[p].second + 1};
        else 
            m[p] = {t - checkin[id].second, 1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return m[{startStation, endStation}].first * 1.0 / m[{startStation, endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
