bool judgeSquareSum(int c) {
        for(long long i = 0; i * i <= c; i++){
            long long a = c - i * i, b = sqrt(a);
            
            if(b * b == a){
                return true;
            }
        }
        return false;
    }
