/*can not pass all cases*/

char cnt[256];
int lengthOfLongestSubstring(char* s) {
    char* l = s;
    char* r = s;
    int maxlen = 0;
    while (*r) {
        if (cnt[*r]) {
            if (maxlen < r - l) maxlen = r - l;
            do {
                cnt[*l] = 0;
            } while(*l++ != *r);
        }
        cnt[*r++] = 1;
    }
    if (maxlen < r - l) maxlen = r - l;
    return maxlen;
}
