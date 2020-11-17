#Shortest Path in a maze | Lee Algorithm
Given a maze in the form of the binary rectangular matrix, find length of the shortest path in a maze from given source to given destination.

Steps for Lee Algorithm
- Create an empty queue and enqueue source cell having distance 0 from src and mark it as valid
- loop until the queue is empty
    + pop front node from the queue
    + if the popped node is dest node, then return the distance
    + else, for each of the 4 adjacent cells of curr cell, we enqueue each valid cell into the queue with +1 distance and mark them as visted.
- If all the nodes in the queues is processed and dest is not reached, then return false