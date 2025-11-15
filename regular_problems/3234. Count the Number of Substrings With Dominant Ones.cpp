/*You are given a binary string s.
Return the number of substrings with dominant ones.
A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
Example 1:
Input: s = "00011"
Output: 5*/

// 3234. Count the Number of Substrings With Dominant Ones
// C++17 solution
class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = (int)s.size();
        // total substrings
        long long total = 1LL * n * (n + 1) / 2;
        // collect positions of zeros with sentinels
        vector<int> pos;
        pos.push_back(-1);
        for (int i = 0; i < n; ++i) if (s[i] == '0') pos.push_back(i);
        pos.push_back(n);
        int m = (int)pos.size() - 2; // number of zeros
        // compute maxK where k^2 + k <= n
        int maxK = (int)((-1.0 + sqrt(1.0 + 4.0 * n)) / 2.0);
        // 1) substrings with zero zeros (all-ones substrings)
        long long substr_k0 = 0;
        for (int i = 1; i + 1 < (int)pos.size(); ++i) {
            int gap = pos[i] - pos[i - 1] - 1; // ones between zeros (but easier compute with sentinels)
            // above formula is wrong for direct; simpler: ranges between zeros are:
            // For k=0 windows correspond to intervals between consecutive zeros:
        }
        // Better compute ones segments by scanning:
        long long onesOnly = 0;
        {
            long long cur = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') cur++;
                else {
                    onesOnly += cur * (cur + 1) / 2;
                    cur = 0;
                }
            }
            onesOnly += (long long)0; // ensure variable exists
            // add last segment
            long long lastSeg = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] == '1') lastSeg++;
                else break;
            }
            // The above double-counting approach was sloppy; recompute properly:
        }
        // Recompute onesOnly cleanly:
        onesOnly = 0;
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') cur++;
            else { onesOnly += cur * (cur + 1) / 2; cur = 0; }
        }
        onesOnly += cur * (cur + 1) / 2;

        // 2) compute substrings with exactly k zeros for k = 1..maxK (and sum them to get substrings_with_zeros_at_most_maxK)
        long long substr_with_zeros_at_most_maxK = onesOnly; // include k=0
        for (int k = 1; k <= maxK; ++k) {
            if (k > m) break;
            for (int i = 1; i + k - 1 <= m; ++i) {
                // window zeros at pos[i] ... pos[i+k-1]
                long long leftChoices = pos[i] - pos[i - 1];          // starts in [pos[i-1]+1 .. pos[i]]
                long long rightChoices = pos[i + k] - pos[i + k - 1]; // ends in [pos[i+k-1] .. pos[i+k]-1]
                substr_with_zeros_at_most_maxK += leftChoices * rightChoices;
            }
        }

        // substrings with zeros > maxK are all non-dominant
        long long invalid = 0;
        invalid += (total - substr_with_zeros_at_most_maxK); // all substrings with zeros >= maxK+1

        // Now for k = 1..maxK, count invalid substrings where length < k^2 + k (i.e., ones < k^2)
        for (int k = 1; k <= maxK; ++k) {
            if (k > m) break;
            long long Lmin = 1LL * k * k + k; // minimal required length for dominance; if length < Lmin => invalid
            for (int i = 1; i + k - 1 <= m; ++i) {
                long long Smin = pos[i - 1] + 1;
                long long Smax = pos[i];
                long long Emin = pos[i + k - 1];
                long long Emax = pos[i + k] - 1;
                long long S = Smax - Smin + 1;
                long long E = Emax - Emin + 1;
                if (S <= 0 || E <= 0) continue;

                // For a start s in [Smin, Smax], invalid ends are e in [Emin, min(Emax, s + Lmin - 2)]
                long long s_start = max(Smin, Emin - (Lmin - 2)); // first s that may have any invalid ends
                if (s_start > Smax) continue; // no invalid
                long long s_mid = min(Smax, Emax - (Lmin - 2)); // while s+Lmin-2 <= Emax

                long long total_invalid_here = 0;
                if (s_start <= s_mid) {
                    // for s in [s_start .. s_mid], invalid_count(s) = (s + Lmin - 2) - Emin + 1 = s - C
                    long long C = Emin - (Lmin - 1); // invalid_count = s - C
                    long long len = s_mid - s_start + 1;
                    long long sumS = (s_start + s_mid) * len / 2;
                    long long sumInvalid = sumS - C * len;
                    total_invalid_here += sumInvalid;
                }
                if (s_mid < Smax) {
                    // for s in [max(s_start, s_mid+1) .. Smax], all E ends are invalid
                    long long left = max(s_start, s_mid + 1);
                    if (left <= Smax) {
                        long long cntS = Smax - left + 1;
                        total_invalid_here += cntS * E;
                    }
                }
                invalid += total_invalid_here;
            }
        }

        long long ans = total - invalid;
        return ans;
    }
};
