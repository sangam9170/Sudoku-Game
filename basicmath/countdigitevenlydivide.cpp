
class solution{
public:
    int evenlyDivides(int n){
        //code here
        int count=0;
        int temp=n;
        while(n>0){
            int rem=n%10;
            if( rem!=0 && temp%rem==0){
                count++;
            }
            n=n/10;
        }
        return count;
    }
};