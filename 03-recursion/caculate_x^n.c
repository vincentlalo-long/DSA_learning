double fastPower1(double x, int n)
{
 if (n == 0) return 1;
 if (n % 2 == 0) return fastPower(x, n / 2)*fastPower(x, n / 2);
 return fastPower(x, n / 2)*fastPower(x, n / 2)*x;
} 
// T(n)=2T(n/2)+1 
// Áp dụng định lí thợ : O(n)

// Cách 2 : nhanh hơn
double fastPower2(doublex, intn){
 if (n == 0) return 1;
 double y = fastPower(x, n / 2); 
 if (n % 2 == 0) return y*y;
 return y*y*x;
}
 //T(n)=T(n/2)+1 -> O(logn) 
