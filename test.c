#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"

struct proc_info {
    int pid;
    int memsize;           
};



int main(void){
    int first_child=fork();
    if (first_child<0)
    {
        printf(1,"first child failed");
    }

    
    else if(first_child==0)
    {
        // write a big loop to dont finish process 
        char* t = malloc(50000000* sizeof(char*));
        for(int i=0;i<50000000;i++)
        {
                        t[i]='t';
        }
    }

    else {
        
        int second_child =fork();
        if(second_child<0)
        {
            printf(1,"second_child failed");
        }
    else if (second_child==0)
        {
            char* b=malloc(7000000* sizeof(char*));
            for (int i = 0; i < 7000000; i++)
            {
                b[i]='b';
            }
            
        }
         else{
             struct proc_info *p=malloc(100*sizeof(struct proc_info));
             for (int i=0;i<10;i++)
             {
                 if(p[i].pid!=0)
                 {
                 printf(1,"%d\n %d\n", p[i].memsize, p[i].pid);
                 break;
                }
             }

        }

     }

  //  exit();
}