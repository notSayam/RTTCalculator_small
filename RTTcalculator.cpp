/*

Code written by 

Sayam Dhingra
N16451815
sd5292

For IAP end-term exam

*/

#include <iostream>

using namespace std;

int main()
{
    float alpha = 0.125, beta=0.25;
    float RTTm[4], RTTs[4], RTTd[4],RTO,max1;
    RTTm[0]=0;
    int i=0,j=0,k=0,g=4;

    cout<<"\nPlease enter the values of RTTs0 and RTTd0 : ";
    cin>>RTTs[0]>>RTTd[0];
    
    for(i=1;i<=3;i++)
    {
        cout<<"\n\nPlease enter the values of RTTm"<<i<<"\n";
        cin>>RTTm[i];
    }

    for(j=1;j<4;j++)
    {
        RTTs[j] = (1-alpha)*RTTs[j-1] + alpha*RTTm[j];
        
        if((RTTm[j]-RTTs[j-1]) < 0)
            k=-1;
        else 
            k=1;
        
        RTTd[j] = (1-beta)*RTTd[j-1] + beta*((RTTm[j]-RTTs[j-1])*k);

        cout<<"\nRTTs"<<j<<" = "<<RTTs[j];
        cout<<"\t\tRTTd"<<j<<" = "<<RTTd[j];
        // cout<<"\t\tRTO"<<j<<" = "<<RTO[j];

    }

    if(((RTTd[3])*4)>g)
            max1=RTTd[3]*4;
        else
            max1=g;

    RTO = RTTs[3] + max1;
    
    cout<<"\n\nRTO 1 = "<<RTO;    
    cout<<"\t\tRTO 2 = "<<RTO*2;
    cout<<"\n\n";

    return 0;

}
