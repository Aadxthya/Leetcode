// Last updated: 9/16/2025, 9:48:33 AM
class Solution {
public:
    int passThePillow(int n, int time) {
int i = 1;
int switchh = 1;
bool switchhh = true;

        
            while(time>0){
               if(switchhh){
                i++;
               if (i == n)
               switchhh = false;

               
               }
               else{
                i--;
                
                if (i == 1){
                  switchhh = true;

                }
                
               }
              time--;



            }
                    return i;

        }
    
};