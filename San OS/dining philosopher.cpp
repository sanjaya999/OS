#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // number of philosophers

sem_t forks[N];
sem_t mutex;

void *philosopher(void *arg) {
  int id = *(int*)arg;
  int left = id;
  int right = (id + 1) % N;

  while (1) {
    // think for a random amount of time
    printf("Philosopher %d is thinking...\n", id);
    sleep(rand() % 5);

    // wait for the mutex semaphore to become available
    sem_wait(&mutex);

    // pick up the left fork
    sem_wait(&forks[left]);
    printf("Philosopher %d picked up fork %d\n", id, left);

    // pick up the right fork
    sem_wait(&forks[right]);
    printf("Philosopher %d picked up fork %d\n", id, right);

    // eat for a random amount of time
    printf("Philosopher %d is eating...\n", id);
    sleep(rand() % 5);

    // put down the left fork
    sem_post(&forks[left]);
    printf("Philosopher %d put down fork %d\n", id, left);

    // put down the right fork
    sem_post(&forks[right]);
    printf("Philosopher %d put down fork %d\n", id, right);

    // release the mutex semaphore
    sem_post(&mutex);
  }
}

int main() {
  pthread_t threads[N];
  int ids[N];

  // initialize the semaphores
  for (int i = 0; i < N; i++) {
    sem_init(&forks[i], 0, 1);
  }
  sem_init(&mutex, 0, 1);

  // create the philosopher threads
  for (int i = 0; i < N; i++) {
    ids[i] = i;
    pthread_create(&threads[i], NULL, philosopher, &ids[i]);
  }

  // wait for the philosopher threads to finish
  for (int i = 0; i < N; i++) {
    pthread_join(threads[i], NULL);
  }

  // destroy the semaphores
  for (int i = 0; i < N; i++) {
    sem_destroy(&forks[i]);
  }
  sem_destroy(&mutex);

  return 0;
}
