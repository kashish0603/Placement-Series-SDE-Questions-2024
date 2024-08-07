# Deliveroo-SDE-Questions
<h2>Minimum Sum Spanning Tree</h2>

<h3>Problem Statement</h3>
<p>Minimum sum spanning tree: g_nodes value and g_edges value is given in integer along with 2 arrays, g_start[] and g_end[] specifying the start and end position of an edge and g_weights[] telling the weight of each edge. Find out the minimum sum spanning tree by removing any edge.

<h3>Approach:</h3>
<ul>
<li><b>Calculate the Minimum Spanning Tree (MST):</b> Use Kruskal's or Prim's algorithm to compute the MST for the given graph.</br></li>
<li><b>Calculate the MST with Each Edge Removed:</b> For each edge, temporarily remove it and recompute the MST for the remaining edges.</br></li>
<li><b>Track the Minimum Sum of the MST After Removing Each Edge:</b> Compare the sum of the MSTs for different scenarios to find the minimum.</br></li>
</ul>
<h3>Explanation</h3>
<ol>
  <li>Union-Find Class: Manages connected components to support the union and find operations efficiently.</li>
  <li>Kruskal's Algorithm: Finds the MST of the graph using the edges sorted by weight.</li>
  <li>Main Function: Computes the MST with all edges and then calculates the MST for each scenario where one edge is removed. It then finds the minimum MST weight among all these scenarios.</li>
</ol>
  
