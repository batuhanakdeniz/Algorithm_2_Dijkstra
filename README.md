# Problem Description


Joseph and Lucy are best friends and they have arranged a travel together two months
ago and reserved their flying tickets. However unfortunately, in this two months, they
have fought over a small issue and they are not in good terms, so do not want to face
each other in any case. Even so, they did not cancel the travel since everything was
planned before. They decided to do check-in separately and stay at different hotels
during the travel. Also, when going around the city, they do not want to run against each
other. That is why we must arrange their routes from their hotels to the their
destinations and from destinations to the hotels for one day. The rules are listed below:


```
The city map is represented as a directed and weighted graph where nodes
are places and edges are roads. Edge weights are the lengths of roads.

Two of the nodes are Joseph’s hotel (JH) and Lucy’s hotel (LH). The other two
of the nodes are the destination for Joseph (JD) and destination for Lucy (LD).

If there is a path from node A to B with length of n, then it takes n minutes to
get to B from A. Assume that the speed of the Lucy and Joseph are the same.

Joseph and Lucy leave their hotels at the same time and they must not be in
the same node at the same time.

They spend 30 minutes at the destination before returning their hotels.

```

# PART 1 – Constructing the Graph


You are supposed to find the shortest paths from hotels to destinations and
destinations to the hotels that are not intersecting considering the instant locations of
Joseph and Lucy.

There is an example graph given below where the node 0 is JH, node 5 is JD, node 2 is LH
and node 4 is LD. At the right of the graph, the format of the input files is given as the
first line gives the number of nodes in the city (N) and the following line contains the
hotels and destinations in following order: JH JD LH LD

The lines below gives the edge information as: source node, target node, weight
respectively.

You must use the adjacency matrix representation for the graph construction. The txt
file for graph input must be given as a command line argument.

# PART 2 – Implementing the algorithm


You are supposed to implement a shortest path algorithm (i.e. Dijkstra). You need to
find 4 shortest paths for each input as:

- JH to JD and JD to JH
- LH to LD and LD to LH

Remember that edge weights represent how many minutes it takes to get from one
node to another and Lucy and Joseph cannot be at the same node at the same time.

So what to do step by step is like this:

- Find the shortest paths from hotels to destinations.
- Check if there are any case that Joseph and Lucy are at the same node
    considering the durations.
- If there is an intersection, find an alternative path which is valid and shortest. You
    should try to change either Joseph’s or Lucy’s path and choose the better one. If
    there is no alternative paths for both of them, then print “No solution!” on the
    screen and terminate the program.
- Then, find the shortest paths from destinations to hotels in the same manner.
    Note that they have waited at the destination for 30 minutes.


For the example graph given above we can find the shortest paths to destinations as
follows:

JH (0) to JD (5) :

LH (2) to LD (4):

There is no intersection where Joseph and Lucy are at the same node as you can see in
the tables. After waiting for 30 minutes at destinations they go back to the hotels using
shortest paths again.

JD (5) to JH (0):

LD (4) to LH (2):

As you can observe in highlighted rows, they met at node 6 at minute 56. So we need to
find an alternative second shortest path for Lucy which is 4-3-1-0-2. Because we have no
choices for Joseph other than 5-6.

LD (4) to LH (2):

## Sample output:

```
Hint: When comparing the alternative paths for Joseph and
Lucy, please consider
(1) if there is an alternative path
(2) whether if this new path has any intersections
(3) if there are two alternative solutions without
intersection, choose the shortest one overall ( J + L ).
```
```
Note: The test cases will be relatively simple where it is
enough to find one alternative path for each person in case
of intersection. This will give the result so you do not have
to check further. (i.e there will be no cases where there are
also intersections for all of the alternative paths, requiring a
second iteration for alternative path search.)
```
```
Node 0 1 4 5

Time 0 4 7 20

Node 2 3 1 4

Time 0 10 15 18

Node 5 6 2 3 1 0

Time 50 56 58 68 73 79

Node 4 3 6 2

Time 48 49 56 58

Node 4 3 1 0 2

Time 48 49 54 60 68

```


    Two of the nodes are Joseph’s hotel (JH) and Lucy’s hotel (LH). The other two of the nodes are the destination for Joseph (JD) and destination for Lucy (LD).
    
    If there is a path from node A to B with length of n, then it takes n minutes to get to B from A. Assume that the speed of the Lucy and Joseph are the same.
    
    Joseph and Lucy leave their hotels at the same time and they must not be in the same node at the same time.
    
    They spend 30 minutes at the destination before returning their hotels.
You are supposed to find the shortest paths from hotels to destinations and destinations to the hotels that are not intersecting considering the instant locations of Joseph and Lucy.

# PART 1 – Constructing the Graph

There is an example graph given below where the node 0 is JH, node 5 is JD, node 2 is LH and node 4 is LD. At the right of the graph, the format of the input files is given as the first line gives the number of nodes in the city (N) and the following line contains the hotels and destinations in following order: JH JD LH LD
The lines below gives the edge information as: source node, target node, weight respectively.
You must use the adjacency matrix representation for the graph construction. The txt file for graph input must be given as a command line argument.

# PART 2 – Implementing the algorithm

You are supposed to implement a shortest path algorithm (i.e. Dijkstra). You need to find 4 shortest paths for each input as:
- JH to JD and JD to JH
- LH to LD and LD to LH
Remember that edge weights represent how many minutes it takes to get from one node to another and Lucy and Joseph cannot be at the same node at the same time.
So what to do step by step is like this:
- Find the shortest paths from hotels to destinations.
- Check if there are any case that Joseph and Lucy are at the same node
considering the durations.
- If there is an intersection, find an alternative path which is valid and shortest. You
should try to change either Joseph’s or Lucy’s path and choose the better one. If there is no alternative paths for both of them, then print “No solution!” on the screen and terminate the program.
- Then, find the shortest paths from destinations to hotels in the same manner. Note that they have waited at the destination for 30 minutes.
  
