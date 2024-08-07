# Deliveroo-SDE-Questions
<h2>Task Scheduling</h2>

<h3>Problem Statement</h3>
<p>Given N process timings, with their start time and end time, the task is to find the minimum number of machines required to run all the processes such that a single machine can be used for only one process at a given time.

 <b> Examples: 
 
  Input: </b>
  
  int start[] = {96, 29, 76, 63, 51, 26, 39, 48, 66, 63};<br>
  int end[] = {97, 45, 85, 65, 61, 98, 99, 59, 95, 86};

  
  <b>Output:<br><br> </b> 5 

<h3>Approach: </h3>

Assuming that time T starts with 0. The task is to find the maximum number of processes that are ongoing at a particular instance of time. This will give the minimum number of machines required to schedule all the lprocesses.
To find the number of processes ongoing at any instance of time. Maintain a prefix_sum[] which will store the number of processes ongoing at any instance of time t. For any process with timings between [s, t], do prefix_sum[s]++ and prefix_sum[t + 1]–.
Afterward, the cumulative sum of this prefix array will give the count of processes going on at any instance of time.
The maximum value for any time instant t in the array is the minimum number of machines required.

<h3>Another Approach:</h3>

<b>The above approach works when MAX is limited to 105. When the limits of MAX are extended up to 109, we cannot use above approach due to Memory Limit and Time Limit Constraints.</b>

So, we think in a different dimension, towards sorting and cumulative sum. Store the process time (start time and end time) in chronological order, +1 denoting the start time of a process and -1 denoting the end time of a process. Then apply the concept of cumulative sum, this gives the maximum number of processes being conducted at a time. This gives the bare minimum number of machines that are required.

<br>
<b>Algorithm:</b>
<ol>
<li>Initialize a vector of pair, Time, the first value of which indicates the entry or exit time of process and the second value denotes whether the process starts or ends. </li>
<li>Traverse the processes vector and store the values in the vector Time.</li>
<li>Sort the vector Time.</li>
<li>Maintain two variables answer = 0, and sum = 0. answer denotes the final answer to be returned and sum denotes the number of processes going on at a particular time.</li>
<li>Traverse the Time vector, add the second value of the pair into sum and update the answer variable.</li>
<li>Return answer.</li>
</ol>
  
