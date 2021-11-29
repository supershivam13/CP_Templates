class UndergroundSystem {
    unordered_map<int, pair<string, int> >checkIns;        // id : {stationName, time}
    unordered_map<string, pair<int, int> >routeTimings;    // startStation-endStation : {sumOfTime, count}
public:
    UndergroundSystem() {  }

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};           // store id checked in at stationName at time t
    }

    void checkOut(int id, string stationName, int t) {

        // person with given 'id' must have checked in at some station first before he check Out
        // which is stored in 'checkIns' map
        string startToEnd = checkIns[id].first + '-' + stationName;

        // update route's total time and count
        //
        routeTimings[startToEnd] = {routeTimings[startToEnd].first + (t - checkIns[id].second), routeTimings[startToEnd].second + 1};

        // Here, we are not storing a person's whole travel history.
        // As soon as we update the data in the 'routeTimings', we delete the person with 'id' from the 'checkIns' map
        checkIns.erase(id); // erase checkin data to free up memory
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = routeTimings[startStation + '-' + endStation];
        // divide   total time by total cound to get average route time
        return (double)p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
