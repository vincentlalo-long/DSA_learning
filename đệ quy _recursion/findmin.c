int findMin(int S[], int start, int end)
{
    if(start >= end) return S[end];
    int div = (end - start) / 2;
    int A, B;
    A = findMin(S, start, start + div);
    B = findMin(S, start + div + 1, end);
    return Min(A, B);
}
 // Ta sẽ xác định O lớn của thuật toán = định lí thợ : 
// T(n) là thời gian xử lí thuật toán findmin có độ dài end-start+1
// T(n)=2T(n/2)+O(1) vì ta chia đôi bài toán để xét
// Áp dụng định lí thợ : a=2,b=2 f(n)=1 , n^logb(a)=n , f(n)<< n nên T(n)=O(n)
//
