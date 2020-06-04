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
    int pid=fork();
    if(pid==0){
        // write a big loop to dont finish process 
        char* t = malloc(7000000* sizeof(char*));
        for(int i=0;i<7000000;i++)
        {
                        t[i]='t';
        }
        while(0<1){
        }
    }
    else if(pid>0) {
        int second_child =fork();
        if(second_child==0){
            char* s=malloc(1200000* sizeof(char(*)));
            for(int i=0;i<1200000;i++){
                s[i]='s';
            }
            while(0<1){

            }
        }
        else if(second_child>0) {
            sleep(20);
            struct proc_info p [NPROC];
            info_proc(p);
            for(int i=0;i<NPROC;i++){
                if(p[i].pid==0)
                    break;
                printf(1,"%d %d\n", p[i].memsize, p[i].pid);

            }
        }
    }

    exit();
}
