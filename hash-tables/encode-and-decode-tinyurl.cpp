class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> map;
    string base = "http://tinyurl.com/";
    string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+`~-=/?<>[]{}";
    string encode(string longUrl) {
        string tiny;
        int n = longUrl.size()-1;
        while(map.find(tiny) == map.end()){
            for(int i=n;i<n-6;i--){
                tiny += code[((longUrl[i]-'a')+rand()%86)%86];
            }
            if(map.find(tiny)==map.end()){
                map[tiny] = longUrl;
            }
        }
        return base+tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int ind = shortUrl.find_last_of('/');
        return map[shortUrl.substr(ind+1)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
