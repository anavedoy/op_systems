#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *arg) {
   long tid = (long)arg;
   printf("Alo da thread %ld\n", tid);
   pthread_exit(NULL);
}

void *QuadNum(void *arg){
    long tid = (long)arg;
    printf("Quadrado de %ld: %ld\n", tid, tid*tid);
    pthread_exit(NULL);
}


int main (int argc, char *argv[]) {
   
   pthread_t threads[NUM_THREADS];
   
   int rc, rc_2;
   long t;
   
   for (t=0; t<NUM_THREADS; t++){
      
        printf("main: criando thread %ld\n", t);
        
        rc = pthread_create(&threads[t], 
                            NULL, 
                            PrintHello, 
                            (void *)t);
        
        if (rc) {
            printf("ERRO - rc=%d\n", rc);
            exit(-1);
        }
   }
   

    for (t=0; t<(NUM_THREADS+3); t++){

        rc_2 = pthread_create(&threads[t], 
                            NULL, 
                            QuadNum, 
                            (void *)t);

        if (rc_2) {
         printf("ERRO - rc=%d\n", rc_2);
         exit(-1);
        }
    }

   /* Ultima coisa que main() deve fazer */
   pthread_exit(NULL); 
}
