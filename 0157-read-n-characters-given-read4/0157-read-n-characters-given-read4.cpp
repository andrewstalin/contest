/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bytes = 4;
        int res = 0;
        
        while (n > 0 && bytes == 4) {
            bytes = read4(buf);
            bytes = std::min(n, bytes);
            buf += bytes;
            res += bytes;
            n -= bytes;
        }
        
        
        return res;
    }
};