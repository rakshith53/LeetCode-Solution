class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int> > fol;
    unordered_map<int,vector<pair<int,int> > > tweet;
    int time = 0;
    #define ite vector<pair<int,int> >::iterator 
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet[userId].emplace(tweet[userId].begin(),make_pair(++time, tweetId));
        
        if (tweet[userId].size() > 10) {
            tweet[userId].pop_back();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // priority_queue<pair<int,int> > q;
        // for(auto it=tweet[userId].begin();it!=tweet[userId].end();it++)
        //     q.push(*it);
        // for(auto it=fol[userId].begin();it!=fol[userId].end();it++){
        //     for(auto i=tweet[*it].begin();i!=tweet[*it].end();i++)
        //         q.push(*i);
        // }
        // int n = q.size() < 10 ? q.size() : 10;
        // vector<int> res;
        // while(n--){
        //     res.push_back(q.top().second);
        //     q.pop();
        // }
        // return res;
        
        vector<pair<ite,ite> > feed;
        if(tweet[userId].size())
            feed.push_back({tweet[userId].begin(),tweet[userId].end()});
        for(auto it=fol[userId].begin();it!=fol[userId].end();it++)
           if(tweet[*it].size())
               feed.push_back({tweet[*it].begin(),tweet[*it].end()});
        vector<int> res;
        int ind,max,n=feed.size();
        while(res.size() < 10){
            ind = -1;
            max = -1;
            for(int i=0;i<n;i++){
                if(feed[i].first == feed[i].second) continue;
                if(ind==-1 || max < feed[i].first->first){
                    ind = i;
                    max = feed[i].first->first;
                }
            }
            if(ind==-1) break;
            res.push_back(feed[ind].first->second);
            ++feed[ind].first;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            fol[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(fol[followerId].find(followeeId)!=fol[followerId].end())
            fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
