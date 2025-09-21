class MovieRentingSystem {
public:
        map<pair<int,int>,int> pricepair;
        map<int,set<pair<int,int>>> available;
        set<tuple<int,int,int>> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto e : entries){
            int shop=e[0],movie=e[1],price=e[2];
            pricepair[{shop,movie}]=price;
            available[movie].insert({price,shop});
        }

    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if(available.find(movie)==available.end()) return result;
        int count=0;
        for(auto p : available[movie]){
            result.push_back(p.second); 
            if (++count == 5) break;
        }
        return result;
        
    }
    
    void rent(int shop, int movie) {
        int price =pricepair[{shop,movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
         int price = pricepair[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count=0;
        for(auto t:rented){
        int price,shop,movie;
        tie(price, shop, movie) = t;
        result.push_back({shop, movie});
        if (++count == 5) break;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */