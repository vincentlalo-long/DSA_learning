At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

//Code C :
bool lemonadeChange(int* bills, int billsSize) { // Day la cach mat nao , chi xet cac TH cua else if
    int money_slot[billsSize];
    int visited[1000];
    int cnt[1000]={0};
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5){
            cnt[5]++;
        }
        else if(bills[i]==10){
            cnt[10]++;
            if(cnt[5]<=0) return false;
            cnt[5]--;
            
        }
        else{
            if(cnt[10]<=0 ){
                if(cnt[5]<=2) return false;
                else cnt[5]=cnt[5]-3;
            }
            else if(cnt[10]>=1 && cnt[5]<=0) return false;
            else {
                cnt[10]--;
                cnt[5]--;
            }
        }
    }
    return true;
} 

//Lời giải tham khảo : 
