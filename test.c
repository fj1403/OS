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
        char* a = malloc(7000000* sizeof(char*));
        for(int i=0;i<7000000;i++)
        {
                        a[i]='a';
        }
        while(0<1){
        }
    }
    else if(pid>0) {
        int second_child =fork();
        if(second_child==0){
            //allocate different size of memory to test correctness of syscall
            char* b=malloc(1200000* sizeof(char(*)));
            for(int i=0;i<1200000;i++){
                // use variable to prevent compile error
                b[i]='b';
            }
            while(0<1){

            }
        }
        // parent process
        else if(second_child>0) {
            // need sleep to make delay
            sleep(20);
            // main proc_info that we pass it to syscall
            struct proc_info p [NPROC];
            // call syscall to start running it
            // p contains running and runnable processes after that
            info_proc(p);
            // there are some default process with pid=0, we dont want to print them, so break
            // NPROC is number of all processes that is defined in "param.h"
            for(int i=0;i<NPROC;i++){
                if(p[i].pid==0)
                    break;
                printf(1,"%d %d\n", p[i].memsize, p[i].pid);

            }
        }
    }

    exit();
}
