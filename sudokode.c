#include <stdio.h>
#include <unistd.h>

//Name: Ian Lewis
//Course: COP 3502C

int main() {

    int i, j, x, y, z, k, count;
    int counter[10]={0};
    int puzzle[9][9];
    int success = 1;

    //Read in number of cases
    scanf("%d", &count);

    //For each case run a check
    for(i=0;i<count;i++){

        //Initialize success at start of check
        success=1;

        //Build array for current puzzle
        for(x=0;x<9;x++){
            for(y=0;y<9;y++){
                scanf("%d", &puzzle[x][y]);
            }
        }

        //Row check
        for(x=0;x<9;x++){
            for(y=0;y<9;y++){
                counter[puzzle[x][y]]++;
            }
            //Check to see if numbers appear more than once in a row
            for(z=1;z<10;z++){
                if(counter[z]==1)
                    counter[z]=0;
                else if(counter[z]!=1){
                    counter[z]=0;
                    success=0;
                }
            }
        }
        //End Row Check


        //Col check
        for(x=0;x<9;x++){
            for(y=0;y<9;y++){
                counter[puzzle[y][x]]++;
            }
            //Check to see if numbers appear more than once in each column
            for(z=1;z<10;z++){
                if(counter[z]==1)
                    counter[z]=0;
                else if(counter[z]!=1){
                    counter[z]=0;
                    success=0;
                }
            }
        }
        //End Col Check

        //3x3 Block Check
        for(x=0;x<3;x++){
            for(y=0;y<3;y++){
                for(j=0;j<3;j++){
                    for(z=0;z<3;z++){
                        //Add frequency count to counter for 3x3 block
                        counter[puzzle[j+(x*3)][z+(y*3)]]++;
                    }
                }
                    //Check to see if numbers appear more than once in each 3x3 square
                    for(k=1;k<10;k++){
                    if(counter[k]==1)
                        counter[k]=0;
                    else if(counter[k]!=1){
                        counter[k]=0;
                        success=0;
                    }
                }
            }
        }
        //End 3x3 Block check

        //Success/Fail Statements
        if(success==0)
            printf("NO\n");

        else if(success==1)
            printf("YES\n");

    }
}
