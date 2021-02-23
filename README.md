# Algorithm_2_Dijkstra

# Problem Description
Joseph and Lucy are best friends and they have arranged a travel together two months ago and reserved their flying tickets. However unfortunately, in this two months, they have fought over a small issue and they are not in good terms, so do not want to face each other in any case. Even so, they did not cancel the travel since everything was planned before. They decided to do check-in separately and stay at different hotels during the travel. Also, when going around the city, they do not want to run against each other. That is why we must arrange their routes from their hotels to the their destinations and from destinations to the hotels for one day. The rules are listed below:
 
    The city map is represented as a directed and weighted graph where nodes are places and edges are roads. Edge weights are the lengths of roads.
    
    Two of the nodes are Joseph’s hotel (JH) and Lucy’s hotel (LH). The other two of the nodes are the destination for Joseph (JD) and destination for Lucy (LD).
    
    If there is a path from node A to B with length of n, then it takes n minutes to get to B from A. Assume that the speed of the Lucy and Joseph are the same.
    
    Joseph and Lucy leave their hotels at the same time and they must not be in the same node at the same time.
    
    They spend 30 minutes at the destination before returning their hotels.
You are supposed to find the shortest paths from hotels to destinations and destinations to the hotels that are not intersecting considering the instant locations of Joseph and Lucy.

# PART 1 – Constructing the Graph

There is an example graph given below where the node 0 is JH, node 5 is JD, node 2 is LH and node 4 is LD. At the right of the graph, the format of the input files is given as the first line gives the number of nodes in the city (N) and the following line contains the hotels and destinations in following order: JH JD LH LD
The lines below gives the edge information as: source node, target node, weight respectively.
You must use the adjacency matrix representation for the graph construction. The txt file for graph input must be given as a command line argument.

<div align="center">
  <a href="https://www.youtube.com/watch?v=-fKUyT14G-8"
     target="_blank">
    <img src="http://img.youtube.com/vi/-fKUyT14G-8/0.jpg"
         alt="DeepMind open source PySC2 toolset for Starcraft II"
         width="240" height="180" border="10" />
  </a>
  <a href="https://www.youtube.com/watch?v=6L448yg0Sm0"
     target="_blank">
    <img src="http://img.youtube.com/vi/6L448yg0Sm0/0.jpg"
         alt="StarCraft II 'mini games' for AI research"
         width="240" height="180" border="10" />
  </a>
  <a href="https://www.youtube.com/watch?v=WEOzide5XFc"
     target="_blank">
    <img src="http://img.youtube.com/vi/WEOzide5XFc/0.jpg"
         alt="Trained and untrained agents play StarCraft II 'mini-game'"
         width="240" height="180" border="10" />
  </a>
</div>

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
  
