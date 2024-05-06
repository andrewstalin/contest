

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {

        int N = words.size();
        
          std::vector<std::vector<int>> overlaps(N, std::vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)  {
                if (i == j) {
                    continue;
                }

                int min = std::min(words[i].size(), words[j].size());
                int sizei = words[i].size() - 1;

                for (int k = min; k >= 0; --k) {
                    bool end_with = true;

                    for (int r = sizei, l = k - 1; l >= 0; --l, --r) {
                        if (words[i][r] != words[j][l]) {
                            end_with = false;
                            break;
                        }
                    }

                    if (end_with) {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }

        std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(1<<N, std::vector<int>(N));
        std::vector<std::vector<int>> parent = std::vector<std::vector<int>>(1<<N, std::vector<int>(N));

        for (int mask = 0; mask < (1 << N); ++mask) {
            std::fill(parent[mask].begin(), parent[mask].end(), -1);

            for (int bit = 0; bit < N; ++bit) {
                if (((mask >> bit) & 1) > 0) {
                    int pmask = mask ^ (1 << bit);

                    if (pmask == 0) {
                        continue;
                    }

                    for (int i = 0; i < N; ++i) {
                        if (((pmask >> i) & 1) > 0) {
                            int val = dp[pmask][i] + overlaps[i][bit];

                            if (val > dp[mask][bit]) {
                                dp[mask][bit] = val;
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }


        std::vector<int> perm = std::vector<int>(N);
        std::vector<bool> seen = std::vector<bool>(N);
        int t = 0;
        int mask = (1 << N) - 1;

        int p = 0;
        for (int j = 0; j < N; ++j) {
            if (dp[(1<<N) - 1][j] > dp[(1<<N) - 1][p]){
                p = j;
            }
        }

        while (p != -1) {
            perm[t++] = p;
            seen[p] = true;
            int p2 = parent[mask][p];
            mask ^= 1 << p;
            p = p2;
        }

        for (int i = 0; i < t/2; ++i) {
            int v = perm[i];
            perm[i] = perm[t-1-i];
            perm[t-1-i] = v;
        }

        for (int i = 0; i < N; ++i) if (!seen[i]) {
            perm[t++] = i;
        }

        std::string res;
        res.append(words[perm[0]]);
        res.reserve(50);

        for (int i = 1; i < N; ++i) {
            int overlap = overlaps[perm[i-1]][perm[i]];
            res.append(words[perm[i]].substr(overlap));
        }
        
        return res;
  }
};



/*

["alex","loves","leetcode"]
["catg","ctaagt","gcta","ttca","atgcatc"]
["ebc","xchdh","hieb","bcu"]
["abcde","xyzab"]
["ab","ba"]
["lugeuklyt","thwokzob","rilsthwokz","onkrilsthw","kzobvtr","krilsthwo"]
["cmqitnqwahfl","ygeeoensdpuobhazkn","fxlqkqwemwhpeoblldcv","eoblldcvypdygeeoen","dpuobhazknowcmq","yfhctxzvfxlqkqwemwh","emwhpeoblldcvypdygee","dcvypdygeeoensdpuobh","zvfxlqkqwemwhpeobl"]
["acabcc","bbbab","ecb","aaa","ccac","beaeda"]
["bccbacbcbabb","wuyhrlvbvzfrop","baaaaaabbbaaabbab","kjhajgsbic","eccge","ccac","fdgfgccfcefedfeda","babcba","ghahcebhgceecgfia","baaabbabbac","beaddcdabeafbfc","rsaac"]

*/

