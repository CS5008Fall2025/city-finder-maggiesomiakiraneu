# Report
Fill out these report questions. 


1. What is the difference between a directed and undirected graph?
The directed graph's edges has direction, go from one vertice to the other in a specific direction.
The undirected graph's edges have no direction. It is a two way connection. If there's an edge between A and B, it can travel in both directions.
2. What is the Big O of Dijkstra's algorithm.... 
   * Assuming you used an array (or list) to store the vertices.
     * If I use an array or list to store the vertices, the algorithm ends up taking about $O(V^2)$ time, where V is the number of vertices. This is because I have a loop that goes through each vertex once, and inside that loop, I need to look at all the vertices to find the one with the smallest distance. That alone takes V steps for each vertex. Then, I also update the distances for all the neighbors, and in the worst case, I might have to check every vertex again. So for every vertex, I’m doing roughly V steps, and I do this for all V vertices, which is why the total time is $O(V^2)$.
   * Assuming you used a heap / priority queue to store the vertices.
     * the algorithm takes about O((V + E) log V) time, where V is the number of vertices and E is the number of edges. The reason is that I have to insert each vertex into the heap and then remove it once, which takes roughly log V time for each vertex, giving me O(V log V). Then, for every edge, I might need to update the heap to reflect a shorter distance, and each of these updates also takes about log V time, adding O(E log V). When I combine these, the total work comes out to O((V + E) log V).

3. Explain in your own words what that means for larger graphs when trying to find the shortest distance.

   The difference between $O(V^2)$ and O((V + E) log V) really shows up when the graph gets huge, like in something as big as Google Maps. With $O(V^2)$, if there were a million cities, I’d be doing roughly a trillion operations, which is painfully slow. But with O((V + E) log V), for a million cities and, say, five million roads, I’d only be doing around a hundred million operations—about ten thousand times faster.
   For a small assignment with just 36 cities, both methods work fine. $36^2$ is only 1,296 operations, and using a heap might take even fewer. But in the real world, with millions of locations, a heap or priority queue becomes essential. The log V factor grows much slower than the $V^2$ factor, so the algorithm stays practical even for massive route planning problems.


## Deeper Thinking
4. For this assignment, you didn't need the most "efficient" set of data structures (for example, a heap wasn't required). However, think on the scale of google/apple maps - they have to deal with millions of vertices and edges. What data structures would you use to store the graph? Why? Somethings to consider - would you be able to store the entire graph at a time? Could you break it up into smaller pieces? How would you do that? Would there be advantages to caching/memoization of paths? You are free to explore your thoughts on this subject/reflect on various ideas. Other than a realization of some scalability of problems, there isn't a wrong answer. 

At the scale of Google Maps, with millions of cities and roads, a lot of strategies are needed to make routing fast and practical. First, I have to be smart about how I store the data. Using an adjacency matrix would be crazy because it would have trillions of cells, most of them empty. Instead, I use an adjacency list, which only stores actual connections between locations. I also implement Dijkstra’s algorithm with a binary heap or Fibonacci heap, which brings the running time down to O((V + E) log V) instead of $O(V^2)$. On top of that, spatial indexing like quadtrees or R-trees helps organize locations geographically so I don’t have to search the entire world when I only need a local route.

I can’t store the entire world graph in memory at once, so I break it up. I divide the map into regions, from neighborhoods to cities, states, and countries, and I use major roads to connect them. I load only the parts of the graph I actually need. If I’m routing from Boston to Miami, I don’t need Seattle’s data. I also pre-compute shortcuts on highways; if the fastest route between two cities always uses the same highway exits, I store that as a direct edge.

Caching and memoization give huge advantages. Popular routes like airports to downtown can be cached, partial paths can be reused if I already computed part of a route, and routes can be cached depending on the time of day to account for rush hours. When traffic changes, I only need to recompute the affected portions, not the whole route.

Other optimizations make searches even faster. I can search from both the start and end points at the same time, meeting in the middle. Using the A algorithm, I guide the search toward the destination with geographic distance as a heuristic. Landmark based routing also helps by pre-computing distances to key locations so I can make smarter choices during the search. All these strategies together make global-scale route planning possible in real time.


## Future Understanding
5. Related to shortest distance, is a problem called the "messenger" or "traveling sales person" problem commonly abbreviated to TSP. This problem is to find the shortest path that visits **every** vertex in a graph. Another way to look at it, is you are an delivery driver, and you have a series of packages to deliver. Can you find an optimal path for your deliveries that minimizes the total distance traveled? Imagine if you had 5 stops. How many different paths are there?  There are 120 possible paths to look at! (assuming fully connected routes). 
      
      If 5 stops have 120 paths, which means 120 = 5!
   * How many possible paths are there if you have 6 stops?
     * 6!=720
   * How many possible paths are there if you have 10 stops?
     * 10! = 3628800
6. What type of growth is this problem? 
   1. Factorial growth O(n!).
7. Take some time to research TSP problems. It falls under a certain classification of problems? What is it?
   
The TSP, Traveling Salesman Problem, is called NP-Complete. Being in NP means that if someone gives me a solution, I can quickly check if it’s correct. For TSP, this means if someone shows me a route and its total distance, I can easily make sure the route is valid and add up the distance in a reasonable amount of time.

Being NP-Complete means TSP is one of the hardest problems in that group. If there were a way to solve any NP-Complete problem quickly, then all problems in NP could be solved quickly too. This is the famous P versus NP question, one of the biggest unsolved problems in computer science. TSP is also NP-Hard, which means it’s at least as hard as NP-Complete problems and maybe even harder.

In practice, this means there is no known method that can always solve TSP perfectly in a short time. Instead, I use approximate methods or smart guesses, like genetic algorithms, simulated annealing, or branch-and-bound techniques, to find solutions that are good enough without taking forever.

1. Provide some examples of fields / problems that use TSP.
   1. package delivery services like UPS, Fedex.
   2. food delivery like Ubereats, Doordash
   3. X-Ray crystallographyAnalysis (https://stackoverflow.com/questions/10371317/what-are-real-world-industry-applications-of-tsp)



> [!TIP]
> We are having you explore TSP, so you can see the terms used for problem classification that are often the foundation of computer science theory. You will not be asked to know about TSP outside of this assignment or even problem classification. Computer Science is often about dealing with problems considered "too hard" or "impossible", and finding ways to make them possible! As such, knowing topics such as N, NP, NP-Complete, etc. is important to understand the limits (to break).


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.


Interview question: What is a header (.h) file and how does it differ from a source file? Why do we use header files?

A header file (.h) includes declarations such as function prototypes, structures, and constants. It tells the compiler what functions and types exist, but not how they work. A source file contains the actual code that implements those functions. So the header describes the interface, and the source file provides the working code.



2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

Link to the question: https://leetcode.com/problems/power-of-two/description/?envType=list&envId=ofbudylr

I saved the code in the 'leecode.c' file. 

