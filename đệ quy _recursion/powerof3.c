bool isPowerOfThree(int n) {
    if(n<=0) return false;
    if(n==1) return true;
    if(n%3!=0 && n!=1) return false;
    else return isPowerOfThree(n/3);
} // Bài kiểm tra xem có phải dạng 3^x không
