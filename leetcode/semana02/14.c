char* longestCommonPrefix(char** strs, int strsSize) {
    
    for(int i=0; strs[0][i] != '\0'; i++){
       char c= strs[0][i];
       
       for(int j=0; j < strsSize; j++)
            if(c != strs[j][i] || strs[j][i] == '\0'){
                strs[0][i] = '\0';
                return strs[0];
       }
    }
    
    return strs[0];
}