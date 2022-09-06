#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS    5

void *PrintHello(void *arg) {
    long tid = (long)arg;
    printf("Alo da thread %ld\n", tid);
    printf("Retornando %ld\n", tid*tid);
    printf("\n");
    return (long int *) (long int)2;
    pthread_exit(NULL);
}

int main (int argc, char *argv[]) {

    pthread_t threads[NUM_THREADS];
    
    int rc;
    long t;

    long int *teste;
    
    for (t=0; t<NUM_THREADS; t++){
        
        printf("main: criando thread %li\n", (long int)teste);
        
        rc = pthread_create(&threads[t], 
                            NULL, 
                            PrintHello, 
                            (void *)t);

        
        if (rc) {
            printf("ERRO - rc=%d\n", rc);
            exit(-1);
        }

    }
    
    /* Ultima coisa que main() deve fazer */
    pthread_exit(NULL); 
}
