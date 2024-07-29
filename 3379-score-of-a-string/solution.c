int scoreOfString(char* s) {
    int su = 0;
    int size = strlen(s);
    for(int i=0; i < size- 1 ;i++){
        su += abs(s[i] - s[i+1]) ;
    }
    return su;
}
