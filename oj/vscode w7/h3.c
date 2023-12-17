#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main(){
    int n,k;
    int count=0;
    scanf("%d",&n);
    while(count<n){
        scanf("%d",&k);  
        count++;
        int X[k],Y[k];
        for(int i=0;i<k;i++)
        scanf("%d%d",&X[i],&Y[i]);
        for(int i=0;i<k-1;i++)
            for(int j=0;j<k-i-1;j++){
                if(X[j]>X[j+1]){
                    int temp=X[j];
                    X[j]=X[j+1];
                    X[j+1]=temp;

                    int temp_1=Y[j];
                    Y[j]=Y[j+1];
                    Y[j+1]=temp_1;
                }
            }

        bool decide_x[k],decide_y[k];
        int X_1[k],Y_1[k];
        //初始化
        for(int i=0;i<k;i++){
            decide_x[i]=false;
            decide_y[i]=false;
            X_1[i]=0;
            Y_1[i]=0;
        }
        //將可以被照到的設為true
        for(int i=0;i<k;i++){
            bool decide;
            decide=false;
            for(int j=i+1;j<k;j++){
                if(Y[i]>Y[j]){
                    decide=true;
                }else{
                    decide=false;
                    break;
                }
            }
            if(decide){
                decide_x[i]=true;
                decide_y[i]=true;
            }
        }
        int z=0;
        for(int i=0;i<k;i++){
            if(decide_x[i] && decide_y[i]){
                X_1[z]=X[i];
                Y_1[z]=Y[i];
                z++;
            }
        }
        //算照射長度
        int d=1;
        double m;
        double X_2[k];
        double length[k];
        for(int i=0;i<k;i++)
            length[i]=0;
        for(int i=0;i<k;i++){
            if(decide_x[i] && decide_y[i]){
                m=(double)(Y[i+1]-Y[i])/(X[i+1]-X[i]);
                X_2[i]=((Y_1[d]-Y[i])/m)+X[i];
                length[i]=sqrt((X[i]-X_2[i])*(X[i]-X_2[i])+(Y[i]-Y_1[d])*(Y[i]-Y_1[d]));
                d++;
            }
        }
        //長度加總

        double sum = 0.0;
        for(int i=0;i<k;i++){
            sum+=length[i];
        }
        //印出長度
        printf("%.2f\n",sum);
         
    }
    return 0;
}




