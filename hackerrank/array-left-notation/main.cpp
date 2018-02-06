vector <int> leftRotation(vector <int> a, int d) {
    // Complete this function
    int temp;
    int k = 0;
    vector <int> b (a.size());
    //Failed because O(n^2)
    /*while(k < d) {
        for(int i = 0; i < a.size()-1; i++) {
            temp = a[i+1];
            a[i+1] = a[i];
            a[i] = temp;        
        }
        k++;
    }
    */
    
    //Passed because O(n)
    for(int i = 0; i <= a.size() - 1; ++i) {
        if(d >= a.size()) {
            d = 0;
        }
        b[i] = a[d];
        d++;
    }
    
    return b;
}